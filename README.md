# Unreal ML Agents Plugin

The **Unreal ML Agents Plugin** is inspired by and built upon the [Unity ML-Agents Toolkit](https://github.com/Unity-Technologies/ml-agents).
The primary goal of this project is to bring Unity's powerful reinforcement learning framework to **Unreal Engine**, allowing developers
to train intelligent agents using state-of-the-art machine learning algorithms.

## Unreal Engine and Machine Learning

Unreal Engine also has its own plugin for machine learning, called [Unreal Learning Agents](https://dev.epicgames.com/community/learning/courses/GAR/unreal-engine-learning-agents-5-5/bZnJ/unreal-engine-learning-agents-5-5).

This project isn't here to compete with Unreal Learning Agents—it's meant to complement it.
For those who find Unreal Learning Agents more suited to their needs, I wholeheartedly encourage you to
explore its capabilities. Both plugins share the same vision: advancing AI in game engines and providing developer
with innovative tools to build smarter, more dynamic systems. This plugin aims to bridge that gap by providing
similar capabilities within Unreal Engine.

## Documentation

For full documentation, visit: [Unreal ML-Agents Documentation](https://unrealmlagents.readthedocs.io/en/latest/)

If you are just getting started, we recommend that you read the documentation in this order:

1. Read the **Getting Started** section.
2. Jump to the **Create New Environment** guide.
3. Check out the **Examples** to see implementations in action.

Check `Docs/README` for instructions on building an HTML version of the docs.

We are actively working on Unreal-specific documentation, but for additional reference, Unity's ML-Agents Toolkit documentation
remains a valuable resource.

## Overview

The **Unreal ML Agents Plugin** is a framework that allows Unreal Engine developers to train machine learning-based agents.
At this stage, inference is not yet implemented, and many sensors available in Unity ML-Agents have not been developed yet.
Currently, we support only **base vector observations** for the agent and a **RaySensorComponent**.

### ✅ **Current Features**
- **Reinforcement Learning (RL) support**
- **Basic vector observations**
- **Ray sensor component for spatial awareness**
- **Multi-Agent training**

### 🚧 **Work in Progress**
- **Inference is not implemented yet**
- **Most sensor types from Unity ML-Agents are not yet available**
- **Imitation learning is planned but not yet supported**

This project mirrors the structure of Unity ML-Agents, ensuring a familiar workflow while adapting features to **Unreal Engine’s C++ and Blueprint systems**.

## Differences from Unity ML-Agents

This plugin is based on **Unity ML-Agents**, but several adaptations were required for Unreal Engine:

### ✅ Core Modifications
- **Converted from C# to C++** to fit Unreal Engine’s architecture.
- **Integrated with Unreal Blueprints**, allowing developers to interact with the system without writing C++.
- **Reworked `mlagents_envs` into `ueagents_envs`**, adjusting Python-side communication for Unreal.
- **Reworked `mlagents` into `ueagents`**, adjusting Python-side for ueagents_envs.

For more details on what has been modified, refer to the [`NOTICE`](NOTICE.md) file.

## Contributing

We welcome contributions! The contributing guidelines are available in `CONTRIBUTING.rst` at the root of the repository.
You can also find them in the official documentation: [Contributing Guide](https://unrealmlagents.readthedocs.io/en/latest/).

Areas where help is most needed:
- Implementing additional **sensor types** (e.g., vision-based sensors).
- Expanding **unit tests** for Unreal-specific features.
- Developing more **example environments** and **training scenarios**.
- Improving **documentation and tutorials**.

If you’d like to contribute, feel free to **submit pull requests** or **open issues**.

## YouTube Showcase

To see what is possible with **Unreal ML Agents**, check out my YouTube channel:

📺 **[Alan Laboratory - Unreal ML Agents](https://www.youtube.com/@AlanLaboratory)**

There, you’ll find examples, demonstrations, and progress updates on what can be achieved using this plugin.
Don't forget to Subscribe!

## Support the Project

When I was younger, I spent a lot of time creating 3D environments, but I never had a clear purpose for them. When AI became popular,
it required an enormous amount of data to create something meaningful. However, seeing what people could do with Unity and my growing
experience with Unreal made me realize that I could combine both of my passions—without needing external datasets. In reinforcement learning,
we generate data as we interact with our own environments, which is an incredible concept.

If you would like to support this project and help with further development, funding auto-building servers, or simply buy me a coffee,
you can do so via **GitHub Sponsors**.

👉 Click the ❤️ **Sponsors** button on GitHub or visit: **[GitHub Sponsors](https://github.com/sponsors/AlanLaboratory)**
