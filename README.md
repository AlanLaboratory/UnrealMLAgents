# Unreal ML Agents Plugin

This project is inspired by and built upon the [Unity ML-Agents Toolkit](https://github.com/Unity-Technologies/ml-agents).
The primary goal is to bring all of the incredible work from Unity's ML-Agents to Unreal Engine. The Unity implementation
is known for its great documentation and solid design. I wanted to adapt this to Unreal Engine to give Unreal developers
access to these amazing features.

It's worth noting that Unreal Engine has its own plugin for machine learning called
[Unreal Learning Agents](https://dev.epicgames.com/community/learning/courses/kRm/unreal-engine-learning-agents-5-4/4JPj/unreal-engine-learning-agents-intro-5-4).
While the Unreal Learning Agents is a promising project, at this stage, I believe the Unity implementation is still
superior in terms of features and ease of use. However, Unreal Learning Agents could be a good alternative to this plugin,
and I encourage developers to explore it as well.

## Installation

To install the Plugin:

1. Clone this repository into your Unreal Engine project's `Plugins` folder.
2. Download the pre-built third-party binary libraries from [here](https://github.com/AlanLaboratory/UnrealMLAgents/releases/tag/0.1.0).
3. Extract the downloaded libraries to the `Source/ThirdParty` directory in your project.

## Overview

The **UnrealMLAgents Plugin** is inspired by the [Unity Machine Learning Agents Toolkit](https://github.com/Unity-Technologies/ml-agents),
which enables games and simulations to serve as environments for training intelligent agents. This plugin aims to bring
those same capabilities to Unreal Engine.

Like Unity ML-Agents, this plugin provides integrations for training intelligent agents in 3D, VR/AR, and other Unreal
Engine environments. The UnrealMLAgents Plugin allows game developers, hobbyists, and researchers to train agents
using state-of-the-art algorithms, including reinforcement learning and imitation learning.

You can use trained agents for various purposes, such as controlling NPC behavior, automating game testing, and evaluating
game design decisions.

## Acknowledgements

This project is based on the [Unity ML-Agents Toolkit](https://github.com/Unity-Technologies/ml-agents) and includes
significant modifications to integrate its functionality into **Unreal Engine**. The original Unity ML-Agents code is
licensed under the Apache License 2.0, and this plugin retains compatibility with that license.

We are grateful to **Unity Technologies** for providing the foundation upon which this Unreal ML Agents Plugin
is built. You can find the original Unity ML-Agents code and license information in the `LICENSE.unity` file.

### Modifications

- The original Unity ML-Agents code has been adapted from **C#** to **C++** for use within Unreal Engine.
- We have implemented custom **Protobuf definitions** to support integration with Python and Unreal, compatible with
  Linux, Windows, and macOS.
- Significant changes have been made to integrate Unreal's **Blueprint system**, making it easier for developers to
  interact with the plugin without requiring in-depth C++ knowledge.
- Other changes include modifications to the `mlagents_envs` Python package and adaptations for sensor systems.

For more details on modifications and what has not yet been implemented, please refer to the `NOTICE` file.

## Contributing

Contributions are highly appreciated! There is still much work to be done, and contributions in the following areas would
be especially valuable:

- Implementing additional sensors, such as visual and positional sensors.
- Expanding unit tests to better cover Unreal-specific features.
- Creating more example environments and training scenarios.
- Improving documentation and tutorial content.

Please feel free to submit pull requests or open issues if you would like to contribute or report bugs.

## Documentation

All code is well-documented, and much of the documentation was inspired by Unity ML-Agents. Most methods, classes, and
modules have equivalent names and functionality to Unity's implementation. We are working on adding more examples and
general documentation to make it easier for developers to get started.

For now, you can refer to Unity's excellent documentation here: [Unity ML-Agents Documentation](https://unity-technologies.github.io/ml-agents/ML-Agents-Overview/).

More detailed Unreal-specific documentation is in progress.
