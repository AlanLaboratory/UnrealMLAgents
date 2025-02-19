import numpy as np
import pytest
from ueagents.torch_utils import torch
from ueagents.trainers.buffer import BufferKey
from ueagents.trainers.torch_entities.components.reward_providers import (
    CuriosityRewardProvider,
    create_reward_provider,
)
from ueagents_envs.base_env import BehaviorSpec, ActionSpec
from ueagents.trainers.settings import CuriositySettings, RewardSignalType
from ueagents.trainers.tests.torch_entities.test_reward_providers.utils import (
    create_agent_buffer,
)
from ueagents.trainers.torch_entities.utils import ModelUtils
from ueagents.trainers.tests.dummy_config import create_observation_specs_with_shapes

SEED = [42]

ACTIONSPEC_CONTINUOUS = ActionSpec.create_continuous(5)
ACTIONSPEC_TWODISCRETE = ActionSpec.create_discrete((2, 3))
ACTIONSPEC_DISCRETE = ActionSpec.create_discrete((2,))


@pytest.mark.parametrize(
    "behavior_spec",
    [
        BehaviorSpec(
            create_observation_specs_with_shapes([(10,)]), ACTIONSPEC_CONTINUOUS
        ),
        BehaviorSpec(
            create_observation_specs_with_shapes([(10,)]), ACTIONSPEC_TWODISCRETE
        ),
    ],
)
def test_construction(behavior_spec: BehaviorSpec) -> None:
    curiosity_settings = CuriositySettings(32, 0.01)
    curiosity_settings.strength = 0.1
    curiosity_rp = CuriosityRewardProvider(behavior_spec, curiosity_settings)
    assert curiosity_rp.strength == 0.1
    assert curiosity_rp.name == "Curiosity"


@pytest.mark.parametrize(
    "behavior_spec",
    [
        BehaviorSpec(
            create_observation_specs_with_shapes([(10,)]), ACTIONSPEC_CONTINUOUS
        ),
        BehaviorSpec(
            create_observation_specs_with_shapes([(10,), (3, 64, 66), (1, 84, 86)]),
            ACTIONSPEC_CONTINUOUS,
        ),
        BehaviorSpec(
            create_observation_specs_with_shapes([(10,), (1, 64, 66)]),
            ACTIONSPEC_TWODISCRETE,
        ),
        BehaviorSpec(
            create_observation_specs_with_shapes([(10,)]), ACTIONSPEC_DISCRETE
        ),
    ],
)
def test_factory(behavior_spec: BehaviorSpec) -> None:
    curiosity_settings = CuriositySettings(32, 0.01)
    curiosity_rp = create_reward_provider(
        RewardSignalType.CURIOSITY, behavior_spec, curiosity_settings
    )
    assert curiosity_rp.name == "Curiosity"


@pytest.mark.parametrize("seed", SEED)
@pytest.mark.parametrize(
    "behavior_spec",
    [
        BehaviorSpec(
            create_observation_specs_with_shapes([(10,), (3, 64, 66), (1, 24, 26)]),
            ACTIONSPEC_CONTINUOUS,
        ),
        BehaviorSpec(
            create_observation_specs_with_shapes([(10,)]), ACTIONSPEC_TWODISCRETE
        ),
        BehaviorSpec(
            create_observation_specs_with_shapes([(10,)]), ACTIONSPEC_DISCRETE
        ),
    ],
)
def test_reward_decreases(behavior_spec: BehaviorSpec, seed: int) -> None:
    np.random.seed(seed)
    torch.manual_seed(seed)
    curiosity_settings = CuriositySettings(32, 0.01)
    curiosity_rp = CuriosityRewardProvider(behavior_spec, curiosity_settings)
    buffer = create_agent_buffer(behavior_spec, 5)
    curiosity_rp.update(buffer)
    reward_old = curiosity_rp.evaluate(buffer)[0]
    for _ in range(20):
        curiosity_rp.update(buffer)
        reward_new = curiosity_rp.evaluate(buffer)[0]
    assert reward_new < reward_old


@pytest.mark.parametrize("seed", SEED)
@pytest.mark.parametrize(
    "behavior_spec",
    [
        BehaviorSpec(
            create_observation_specs_with_shapes([(10,)]), ACTIONSPEC_CONTINUOUS
        )
    ],
)
def test_continuous_action_prediction(behavior_spec: BehaviorSpec, seed: int) -> None:
    np.random.seed(seed)
    torch.manual_seed(seed)
    curiosity_settings = CuriositySettings(32, 0.1)
    curiosity_rp = CuriosityRewardProvider(behavior_spec, curiosity_settings)
    buffer = create_agent_buffer(behavior_spec, 5)
    for _ in range(200):
        curiosity_rp.update(buffer)
    prediction = curiosity_rp._network.predict_action(buffer)[0]
    target = torch.tensor(buffer[BufferKey.CONTINUOUS_ACTION][0])
    error = torch.mean((prediction - target) ** 2).item()
    assert error < 0.001


@pytest.mark.parametrize("seed", SEED)
@pytest.mark.parametrize(
    "behavior_spec",
    [
        BehaviorSpec(
            create_observation_specs_with_shapes([(10,), (3, 64, 66), (1, 24, 26)]),
            ACTIONSPEC_CONTINUOUS,
        ),
        BehaviorSpec(
            create_observation_specs_with_shapes([(10,)]), ACTIONSPEC_TWODISCRETE
        ),
        BehaviorSpec(
            create_observation_specs_with_shapes([(10,)]), ACTIONSPEC_DISCRETE
        ),
    ],
)
def test_next_state_prediction(behavior_spec: BehaviorSpec, seed: int) -> None:
    np.random.seed(seed)
    torch.manual_seed(seed)
    curiosity_settings = CuriositySettings(32, 0.1)
    curiosity_rp = CuriosityRewardProvider(behavior_spec, curiosity_settings)
    buffer = create_agent_buffer(behavior_spec, 5)
    for _ in range(100):
        curiosity_rp.update(buffer)
    prediction = curiosity_rp._network.predict_next_state(buffer)[0]
    target = curiosity_rp._network.get_next_state(buffer)[0]
    error = float(ModelUtils.to_numpy(torch.mean((prediction - target) ** 2)))
    assert error < 0.001
