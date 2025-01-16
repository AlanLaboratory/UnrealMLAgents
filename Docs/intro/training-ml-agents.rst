Training ML Agents
==================

I want to acknowledge that training ML Agents is a crucial aspect of leveraging the Unreal ML Agents Toolkit. This section
will eventually guide you through the step-by-step process of setting up, running, and optimizing training sessions.

For now, I want to provide you with a reference to the excellent documentation available in Unity ML-Agents, as much of
my work is inspired by it: `Unity ML-Agents Training Documentation <https://github.com/Unity-Technologies/ml-agents/blob/develop/docs/Training-ML-Agents.md>`_.

Unfortunately, I haven't had the time to fully document this section yet.

.. note::

   Instead of using `mlagents-xxx` commands as referenced in the Unity documentation, you will need to use `ue-agents-xxx` commands. For example:

   .. code-block:: bash

      ue-agents-learn --help

   Additionally, the Python module `ue-agents` functions identically to Unity's `ml-agents`. The only significant differences are:

   - The import paths for Python protobuf files have been updated to align with Unreal ML Agents.
   - SideChannels are not supported in this toolkit, so the related code has been removed.

   All credit for the foundational work goes to Unity's ML-Agents team. This toolkit is heavily inspired by their implementation.

As I'm currently focusing on ensuring other core aspects of the plugin and documentation are complete,
I plan to revisit this topic in the future. Meanwhile, the Unity guide can serve as an invaluable resource for understanding concepts like:

- Setting up configurations for reinforcement learning.
- Understanding reward functions.
- Choosing hyperparameters for training.
- Monitoring training performance and debugging.

Thank you for your patience, and please feel free to explore the Unity ML-Agents documentation linked above to gain
insights that are closely related to how this toolkit functions in Unreal Engine.
