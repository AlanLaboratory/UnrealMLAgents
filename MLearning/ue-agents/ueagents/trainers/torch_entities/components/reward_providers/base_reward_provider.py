import numpy as np
from ueagents.torch_utils import torch
from abc import ABC, abstractmethod
from typing import Dict

from ueagents.trainers.buffer import AgentBuffer
from ueagents.trainers.settings import RewardSignalSettings
from ueagents_envs.base_env import BehaviorSpec


class BaseRewardProvider(ABC):
    def __init__(self, specs: BehaviorSpec, settings: RewardSignalSettings) -> None:
        self._policy_specs = specs
        self._gamma = settings.gamma
        self._strength = settings.strength
        self._ignore_done = False

    @property
    def gamma(self) -> float:
        """
        The discount factor for the reward signal
        """
        return self._gamma

    @property
    def strength(self) -> float:
        """
        The strength multiplier of the reward provider
        """
        return self._strength

    @property
    def name(self) -> str:
        """
        The name of the reward provider. Is used for reporting and identification
        """
        class_name = self.__class__.__name__
        return class_name.replace("RewardProvider", "")

    @property
    def ignore_done(self) -> bool:
        """
        If true, when the agent is done, the rewards of the next episode must be
        used to calculate the return of the current episode.
        Is used to mitigate the positive bias in rewards with no natural end.
        """
        return self._ignore_done

    @abstractmethod
    def evaluate(self, mini_batch: AgentBuffer) -> np.ndarray:
        """
        Evaluates the reward for the data present in the Dict mini_batch. Use this when evaluating a reward
        function drawn straight from a Buffer.
        :param mini_batch: A Dict of numpy arrays (the format used by our Buffer)
            when drawing from the update buffer.
        :return: a np.ndarray of rewards generated by the reward provider
        """
        raise NotImplementedError(
            "The reward provider's evaluate method has not been implemented "
        )

    @abstractmethod
    def update(self, mini_batch: AgentBuffer) -> Dict[str, np.ndarray]:
        """
        Update the reward for the data present in the Dict mini_batch. Use this when updating a reward
        function drawn straight from a Buffer.
        :param mini_batch: A Dict of numpy arrays (the format used by our Buffer)
            when drawing from the update buffer.
        :return: A dictionary from string to stats values
        """
        raise NotImplementedError(
            "The reward provider's update method has not been implemented "
        )

    def get_modules(self) -> Dict[str, torch.nn.Module]:
        """
        Returns a dictionary of string identifiers to the torch.nn.Modules used by
        the reward providers. This method is used for loading and saving the weights
        of the reward providers.
        """
        return {}
