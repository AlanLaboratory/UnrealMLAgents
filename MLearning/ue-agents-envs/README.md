# Unreal ML-Agents Python Interface

The `ueagents_envs` Python package is part of the Unreal ML-Agents Toolkit.
`ueagents_envs` provides APIs that allow direct interaction with Unreal Engine.

## Notice

This package is inspired by Unity's ML-Agents Toolkit. The primary differences are:
- Protobuf import definitions were updated to align with Unreal conventions.
- References to Unity have been replaced with Unreal to avoid confusion.

All credit for the foundational work goes to Unity's ML-Agents Toolkit team.

## Installation

Install the `ueagents_envs` package with:

```sh
python -m pip install ueagents_envs
```

For more information on the Unreal ML-Agents Toolkit and how to instrument an Unreal scene with the Unreal ML-Agents SDK,
check out the main [Unreal ML-Agents Toolkit documentation](https://unrealmlagents.readthedocs.io/en/latest/).

## Limitations

- `ueagents_envs` uses localhost ports to exchange data between Unreal and Python. As such, multiple instances can have their ports collide,
leading to errors. Make sure to use a different port if you are using multiple instances of `UnrealEnvironment`.
- Communication between Unreal and the Python `UnrealEnvironment` is not secure.
- On Linux, ports are not released immediately after the communication closes. As such, you cannot reuse ports right after closing a `UnrealEnvironment`.

## Credit

[Unity ML Agents](https://github.com/Unity-Technologies/ml-agents)
