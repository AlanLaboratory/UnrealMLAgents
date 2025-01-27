# Unreal ML-Agents Trainers

The `ueagents` Python package is part of the Unreal ML-Agents Toolkit. `ueagents`
provides a set of reinforcement and imitation learning algorithms designed to be
used with Unreal Engine environments. The algorithms interface with the Python API
provided by the `ueagents_envs` package.

## Notice

This package is inspired by Unity's ML-Agents Toolkit. The primary differences are:
- `ueagents` has been updated to import from `ueagents_envs` instead of `mlagents_envs`.
- Changes were made to support Unreal Engine, with references to Unity replaced with Unreal.
- SideChannels are not supported yet, and the code has been adjusted accordingly.

All credit for the foundational work goes to Unity's ML-Agents Toolkit team.

## Installation

Install the `ueagents` package with:

```sh
python -m pip install ueagents
```

## Usage & More Information

For more information on the Unreal ML-Agents Toolkit and how to instrument an Unreal
scene with the Unreal ML-Agents SDK, check out the main
[Unreal ML-Agents Toolkit documentation](https://unrealmlagents.readthedocs.io/en/latest/).

## Credit

[Unity ML Agents](https://github.com/Unity-Technologies/ml-agents)
