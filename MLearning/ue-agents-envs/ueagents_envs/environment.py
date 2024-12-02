import atexit
import signal

import numpy as np
import subprocess
from typing import Dict, List, Optional, Tuple, Mapping as MappingType
from distutils.version import StrictVersion

from ueagents_envs.logging_util import get_logger
from ueagents_envs import utils
from ueagents_envs import __version__

from ueagents_envs.base_env import (
    BaseEnv,
    DecisionSteps,
    TerminalSteps,
    BehaviorSpec,
    ActionTuple,
    BehaviorName,
    AgentId,
    BehaviorMapping,
)
from ueagents_envs.exception import (
    UnrealEnvironmentException,
    UnrealActionException,
    UnrealTimeOutException,
    UnrealCommunicatorStoppedException,
)

from ueagents_envs.communicator_objects.command_pb2 import STEP, RESET
from ueagents_envs.rpc_utils import behavior_spec_from_proto, steps_from_proto

from ueagents_envs.communicator_objects.unreal_rl_input_pb2 import UnrealRLInputProto
from ueagents_envs.communicator_objects.unreal_rl_output_pb2 import UnrealRLOutputProto
from ueagents_envs.communicator_objects.agent_action_pb2 import AgentActionProto
from ueagents_envs.communicator_objects.unreal_output_pb2 import UnrealOutputProto
from ueagents_envs.communicator_objects.unreal_rl_initialization_input_pb2 import (
    UnrealRLInitializationInputProto,
)
from ueagents_envs.communicator_objects.unreal_input_pb2 import UnrealInputProto
from ueagents_envs.communicator import RpcCommunicator
from ueagents_envs.side_channel.side_channel import SideChannel
from ueagents_envs.side_channel import DefaultTrainingAnalyticsSideChannel
from ueagents_envs.side_channel.side_channel_manager import SideChannelManager

logger = get_logger(__name__)


class UnrealEnvironment(BaseEnv):
    # Communication protocol version.
    # When connecting to C++, this must be compatible with UnrealMLAgents.k_ApiVersion.
    # We follow semantic versioning on the communication version, so existing
    # functionality will work as long the major versions match.
    # This should be changed whenever a change is made to the communication protocol.
    # Revision history:
    #  * 0.1.0 - initial version
    API_VERSION = "0.1.0"

    # Default port that the editor listens on. If an environment executable
    # isn't specified, this port will be used.
    DEFAULT_EDITOR_PORT = 5004

    # Default base port for environments. Each environment will be offset from this
    # by it's worker_id.
    BASE_ENVIRONMENT_PORT = 5005

    # Command line argument used to pass the port to the executable environment.
    _PORT_COMMAND_LINE_ARG = "-mlAgentPort"

    def __init__(
        self,
        file_name: Optional[str] = None,
        worker_id: int = 0,
        base_port: Optional[int] = None,
        seed: int = 0,
        no_graphics: bool = False,
        no_graphics_monitor: bool = False,
        timeout_wait: int = 60,
        additional_args: Optional[List[str]] = None,
        side_channels: Optional[List[SideChannel]] = None,
        log_folder: Optional[str] = None,
        num_areas: int = 1,
    ):
        """
        Starts a new unity environment and establishes a connection with the environment.
        Notice: Currently communication between Unreal and Python takes place over an open socket without authentication.
        Ensure that the network where training takes place is secure.

        :string file_name: Name of Unreal environment binary. :int base_port: Baseline port number to connect to Unreal
        environment over. worker_id increments over this. If no environment is specified (i.e. file_name is None),
        the DEFAULT_EDITOR_PORT will be used. :int worker_id: Offset from base_port. Used for training multiple
        environments simultaneously. :bool no_graphics: Whether to run the Unreal simulator in no-graphics mode :bool
        no_graphics_monitor: Whether to run the main worker in graphics mode, with the remaining in no-graphics mode
        :int timeout_wait: Time (in seconds) to wait for connection from environment. :list args: Addition Unreal
        command line arguments :list side_channels: Additional side channel for no-rl communication with Unreal :str
        log_folder: Optional folder to write the Unreal Player log file into.  Requires absolute path.
        """
        atexit.register(self._close)
        self._additional_args = additional_args or []
        self._no_graphics = no_graphics or no_graphics_monitor and worker_id != 0
        # If base port is not specified, use BASE_ENVIRONMENT_PORT if we have
        # an environment, otherwise DEFAULT_EDITOR_PORT
        if base_port is None:
            base_port = (
                self.BASE_ENVIRONMENT_PORT if file_name else self.DEFAULT_EDITOR_PORT
            )
        self._port = base_port + worker_id
        self._buffer_size = 12000
        # If true, this means the environment was successfully loaded
        self._loaded = False
        # The process that is started. If None, no process was started
        self._process: Optional[subprocess.Popen] = None
        self._timeout_wait: int = timeout_wait
        self._communicator = self._get_communicator(worker_id, base_port, timeout_wait)
        self._worker_id = worker_id
        if side_channels is None:
            side_channels = []
        default_training_side_channel: Optional[
            DefaultTrainingAnalyticsSideChannel
        ] = None
        if DefaultTrainingAnalyticsSideChannel.CHANNEL_ID not in [
            _.channel_id for _ in side_channels
        ]:
            default_training_side_channel = DefaultTrainingAnalyticsSideChannel()
            side_channels.append(default_training_side_channel)
        self._side_channel_manager = SideChannelManager(side_channels)
        self._log_folder = log_folder

        # If the environment name is None, a new environment will not be launched
        # and the communicator will directly try to connect to an existing unity environment.
        # If the worker-id is not 0 and the environment name is None, an error is thrown
        if file_name is None and worker_id != 0:
            raise UnrealEnvironmentException(
                "If the environment name is None, "
                "the worker-id must be 0 in order to connect with the Editor."
            )
        if file_name is not None:
            try:
                self._process = utils.launch_executable(
                    file_name, self._executable_args()
                )
            except UnrealEnvironmentException:
                self._close(0)
                raise
        else:
            logger.info(
                f"Listening on port {self._port}. "
                f"Start training by pressing the Play button in the Unreal Editor."
            )
        self._loaded = True

        rl_init_parameters_in = UnrealRLInitializationInputProto(
            seed=seed,
            communication_version=self.API_VERSION,
            package_version=__version__,
            num_areas=num_areas,
        )
        try:
            aca_output = self._send_academy_parameters(rl_init_parameters_in)
            aca_params = aca_output.rl_initialization_output
        except UnrealTimeOutException:
            self._close(0)
            raise

        if not UnrealEnvironment._check_communication_compatibility(
            aca_params.communication_version,
            UnrealEnvironment.API_VERSION,
            aca_params.package_version,
        ):
            self._close(0)
            UnrealEnvironment._raise_version_exception(aca_params.communication_version)

        self._env_state: Dict[str, Tuple[DecisionSteps, TerminalSteps]] = {}
        self._env_specs: Dict[str, BehaviorSpec] = {}
        self._env_actions: Dict[str, ActionTuple] = {}
        self._is_first_message = True
        self._update_behavior_specs(aca_output)
        if default_training_side_channel is not None:
            default_training_side_channel.environment_initialized()

    @staticmethod
    def _raise_version_exception(unreal_com_ver: str) -> None:
        raise UnrealEnvironmentException(
            f"The communication API version is not compatible between Unreal and python. "
            f"Python API: {UnrealEnvironment.API_VERSION}, Unreal API: {unreal_com_ver}."
        )

    @staticmethod
    def _check_communication_compatibility(
        unreal_com_ver: str, python_api_version: str, unreal_package_version: str
    ) -> bool:
        unreal_communicator_version = StrictVersion(unreal_com_ver)
        api_version = StrictVersion(python_api_version)
        if unreal_communicator_version.version[0] == 0:
            if (
                unreal_communicator_version.version[0] != api_version.version[0]
                or unreal_communicator_version.version[1] != api_version.version[1]
            ):
                # Minor beta versions differ.
                return False
        elif unreal_communicator_version.version[0] != api_version.version[0]:
            # Major versions mismatch.
            return False
        else:
            # Major versions match, so either:
            # 1) The versions are identical, in which case there's no compatibility issues
            # 2) The Unity version is newer, in which case we'll warn or fail on the Unity side if trying to use
            #    unsupported features
            # 3) The trainer version is newer, in which case new trainer features might be available but unused by C#
            # In any of the cases, there's no reason to warn about mismatch here.
            logger.info(
                f"Connected to Unreal environment with package version {unreal_package_version} "
                f"and communication version {unreal_com_ver}"
            )
        return True

    @staticmethod
    def _get_communicator(worker_id, base_port, timeout_wait):
        return RpcCommunicator(worker_id, base_port, timeout_wait)

    def _executable_args(self) -> List[str]:
        args: List[str] = []
        if self._no_graphics:
            args += ["-nullrhi"]
        args += [UnrealEnvironment._PORT_COMMAND_LINE_ARG, str(self._port)]
        args += self._additional_args
        return args

    def _update_behavior_specs(self, output: UnrealOutputProto) -> None:
        init_output = output.rl_initialization_output
        for brain_param in init_output.brain_parameters:
            # Each BrainParameter in the rl_initialization_output should have at least one AgentInfo
            # Get that agent, because we need some of its observations.
            agent_infos = output.rl_output.agentInfos[brain_param.brain_name]
            if agent_infos.value:
                agent = agent_infos.value[0]
                new_spec = behavior_spec_from_proto(brain_param, agent)
                self._env_specs[brain_param.brain_name] = new_spec
                logger.info(f"Connected new brain: {brain_param.brain_name}")

    def _update_state(self, output: UnrealRLOutputProto) -> None:
        """
        Collects experience information from all external brains in environment at current step.
        """
        for brain_name in self._env_specs.keys():
            if brain_name in output.agentInfos:
                agent_info_list = output.agentInfos[brain_name].value
                self._env_state[brain_name] = steps_from_proto(
                    agent_info_list, self._env_specs[brain_name]
                )
            else:
                self._env_state[brain_name] = (
                    DecisionSteps.empty(self._env_specs[brain_name]),
                    TerminalSteps.empty(self._env_specs[brain_name]),
                )
        self._side_channel_manager.process_side_channel_message(output.side_channel)

    def reset(self) -> None:
        if self._loaded:
            outputs = self._communicator.exchange(
                self._generate_reset_input(), self._poll_process
            )
            if outputs is None:
                raise UnrealCommunicatorStoppedException("Communicator has exited.")
            self._update_behavior_specs(outputs)
            rl_output = outputs.rl_output
            self._update_state(rl_output)
            self._is_first_message = False
            self._env_actions.clear()
        else:
            raise UnrealEnvironmentException("No Unreal environment is loaded.")

    def step(self) -> None:
        if self._is_first_message:
            return self.reset()
        if not self._loaded:
            raise UnrealEnvironmentException("No Unreal environment is loaded.")
        # fill the blanks for missing actions
        for group_name in self._env_specs:
            if group_name not in self._env_actions:
                n_agents = 0
                if group_name in self._env_state:
                    n_agents = len(self._env_state[group_name][0])
                self._env_actions[group_name] = self._env_specs[
                    group_name
                ].action_spec.empty_action(n_agents)
        step_input = self._generate_step_input(self._env_actions)
        outputs = self._communicator.exchange(step_input, self._poll_process)
        if outputs is None:
            raise UnrealCommunicatorStoppedException("Communicator has exited.")
        self._update_behavior_specs(outputs)
        rl_output = outputs.rl_output
        self._update_state(rl_output)
        self._env_actions.clear()

    @property
    def behavior_specs(self) -> MappingType[str, BehaviorSpec]:
        return BehaviorMapping(self._env_specs)

    def _assert_behavior_exists(self, behavior_name: str) -> None:
        if behavior_name not in self._env_specs:
            raise UnrealActionException(
                f"The group {behavior_name} does not correspond to an existing "
                f"agent group in the environment"
            )

    def set_actions(self, behavior_name: BehaviorName, action: ActionTuple) -> None:
        self._assert_behavior_exists(behavior_name)
        if behavior_name not in self._env_state:
            return
        action_spec = self._env_specs[behavior_name].action_spec
        num_agents = len(self._env_state[behavior_name][0])
        action = action_spec._validate_action(action, num_agents, behavior_name)
        self._env_actions[behavior_name] = action

    def set_action_for_agent(
        self, behavior_name: BehaviorName, agent_id: AgentId, action: ActionTuple
    ) -> None:
        self._assert_behavior_exists(behavior_name)
        if behavior_name not in self._env_state:
            return
        action_spec = self._env_specs[behavior_name].action_spec
        action = action_spec._validate_action(action, 1, behavior_name)
        if behavior_name not in self._env_actions:
            num_agents = len(self._env_state[behavior_name][0])
            self._env_actions[behavior_name] = action_spec.empty_action(num_agents)
        try:
            index = np.where(self._env_state[behavior_name][0].agent_id == agent_id)[0][
                0
            ]
        except IndexError as ie:
            raise IndexError(
                "agent_id {} is did not request a decision at the previous step".format(
                    agent_id
                )
            ) from ie
        if action_spec.continuous_size > 0:
            self._env_actions[behavior_name].continuous[index] = action.continuous[0, :]
        if action_spec.discrete_size > 0:
            self._env_actions[behavior_name].discrete[index] = action.discrete[0, :]

    def get_steps(
        self, behavior_name: BehaviorName
    ) -> Tuple[DecisionSteps, TerminalSteps]:
        self._assert_behavior_exists(behavior_name)
        return self._env_state[behavior_name]

    def _poll_process(self) -> None:
        """
        Check the status of the subprocess. If it has exited, raise a UnrealEnvironmentException
        :return: None
        """
        if not self._process:
            return
        poll_res = self._process.poll()
        if poll_res is not None:
            exc_msg = self._returncode_to_env_message(self._process.returncode)
            raise UnrealEnvironmentException(exc_msg)

    def close(self):
        """
        Sends a shutdown signal to the unity environment, and closes the socket connection.
        """
        if self._loaded:
            self._close()
        else:
            raise UnrealEnvironmentException("No Unreal environment is loaded.")

    def _close(self, timeout: Optional[int] = None) -> None:
        """
        Close the communicator and environment subprocess (if necessary).

        :int timeout: [Optional] Number of seconds to wait for the environment to shut down before
            force-killing it.  Defaults to `self.timeout_wait`.
        """
        if timeout is None:
            timeout = self._timeout_wait
        self._loaded = False
        self._communicator.close()
        if self._process is not None:
            # Wait a bit for the process to shutdown, but kill it if it takes too long
            try:
                self._process.wait(timeout=timeout)
                logger.debug(self._returncode_to_env_message(self._process.returncode))
            except subprocess.TimeoutExpired:
                logger.warning("Environment timed out shutting down. Killing...")
                self._process.kill()
            # Set to None so we don't try to close multiple times.
            self._process = None

    def _generate_step_input(
        self, vector_action: Dict[str, ActionTuple]
    ) -> UnrealInputProto:
        rl_in = UnrealRLInputProto()
        for b in vector_action:
            n_agents = len(self._env_state[b][0])
            if n_agents == 0:
                continue
            for i in range(n_agents):
                action = AgentActionProto()
                if vector_action[b].continuous is not None:
                    action.continuous_actions.extend(vector_action[b].continuous[i])
                if vector_action[b].discrete is not None:
                    action.discrete_actions.extend(vector_action[b].discrete[i])
                rl_in.agent_actions[b].value.extend([action])
                rl_in.command = STEP
        rl_in.side_channel = bytes(
            self._side_channel_manager.generate_side_channel_messages()
        )
        return self._wrap_unreal_input(rl_in)

    def _generate_reset_input(self) -> UnrealInputProto:
        rl_in = UnrealRLInputProto()
        rl_in.command = RESET
        rl_in.side_channel = bytes(
            self._side_channel_manager.generate_side_channel_messages()
        )
        return self._wrap_unreal_input(rl_in)

    def _send_academy_parameters(
        self, init_parameters: UnrealRLInitializationInputProto
    ) -> UnrealOutputProto:
        inputs = UnrealInputProto()
        inputs.rl_initialization_input.CopyFrom(init_parameters)
        return self._communicator.initialize(inputs, self._poll_process)

    @staticmethod
    def _wrap_unreal_input(rl_input: UnrealRLInputProto) -> UnrealInputProto:
        result = UnrealInputProto()
        result.rl_input.CopyFrom(rl_input)
        return result

    @staticmethod
    def _returncode_to_signal_name(returncode: int) -> Optional[str]:
        """
        Try to convert return codes into their corresponding signal name.
        E.g. returncode_to_signal_name(-2) -> "SIGINT"
        """
        try:
            # A negative value -N indicates that the child was terminated by signal N (POSIX only).
            s = signal.Signals(-returncode)
            return s.name
        except Exception:
            # Should generally be a ValueError, but catch everything just in case.
            return None

    @staticmethod
    def _returncode_to_env_message(returncode: int) -> str:
        signal_name = UnrealEnvironment._returncode_to_signal_name(returncode)
        signal_name = f" ({signal_name})" if signal_name else ""
        return f"Environment shut down with return code {returncode}{signal_name}."
