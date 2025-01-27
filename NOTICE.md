Copyright 2024 AlanLaboratory and individual contributors.

This product includes software developed by Unity Technologies under the Apache License, Version 2.0. You may obtain
a copy of the License at:

    http://www.apache.org/licenses/LICENSE-2.0

### Modifications:

- **Adaptation from C# to C++**: The original Unity ML-Agents C# code has been adapted to work in Unreal Engine with C++.
  The plugin integrates into Unreal Engine, enabling agent training similar to Unity.

- **Protobuf Definition**: We have created our own Protobuf definitions for Python and C++ for Unreal Engine. This
  implementation supports Linux, Windows, and macOS.

- **Python Package (ml-agents-envs)**: The `mlagents_envs` Python package has been mostly copied from Unity ML-Agents,
  with changes to the Protobuf module import and SideChannel functionality due to engine differences.

- **Raycast Sensor**: A **Raycast sensor** has been implemented for agent perception in Unreal Engine. The implementation
  is incomplete and differs from Unity's. Other sensor types have not yet been ported.

- **Blueprint Integration**: Many methods have been adapted for **Blueprint visual scripting**, enabling easier use of
  the plugin within Unreal without needing extensive C++ knowledge.

### Features Not Yet Implemented:

- **Inference Mode**: Inference mode, which allows trained agents to be deployed in real-time without training, has not
  yet been implemented.

- **Unity Insight Analytics**: Unity-specific **Insight Analytics** features have not been ported to Unreal. Significant
  adaptation is required due to reliance on Unity's infrastructure.

- **SideChannel Support**: Unity's **SideChannel** communication system has not been ported. Given the architectural
  differences in Unreal, implementing this may require a different approach.

- **Sensors**: Only the Raycast sensor has been implemented so far. **Image-based observations (visual observations)**
  and other sensor types are not yet supported, but visual observations are planned for future releases.

- **Unit Testing**: **Unit tests** are currently missing. The goal is to replicate Unity’s unit tests in Unreal Engine
  and create a wide range of example environments, similar to Unity’s ML-Agents examples.

### Future Goals:

- We plan to expand **sensor support**, improve **unit testing**, and develop more example environments for Unreal
  Engine to mirror Unity's completeness.

- **Visual Observations** support and more advanced features like inference mode and SideChannel communications are planned
  for future versions.

- Additional support for **Blueprint integration** is also planned to enhance usability for developers without C++ expertise.

For development updates, planned features, and future releases, please refer to the project’s roadmap in the documentation.
