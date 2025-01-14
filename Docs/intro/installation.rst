Installation
============

This plugin is designed to provide Unreal Engine developers with advanced machine learning tools inspired by Unity's
ML-Agents Toolkit. You can install the plugin directly from FAB, Unreal Engine's marketplace, or by cloning the repository
for full control over the entire plugin, including `ue-agents`, `ue-agents-envs`, and all other components. Cloning the
repository is also a great opportunity for developers to contribute to the project by adding new features or improving
existing ones.

Prerequisites
-------------

1. **Unreal Engine**:

   - Ensure you have Unreal Engine version 5.2 or later installed.
   - Download Unreal Engine from the official website: `Unreal Engine Download <https://www.unrealengine.com/en-US/download>`_.

2. **Python**:

   - Install Python >= 3.10.11 (64-bit) to avoid compatibility issues.
   - Download Python from the official website: `Python Download <https://www.python.org/downloads/>`_.

3. **PyTorch**:

   - On Windows, install the CUDA-enabled version of PyTorch before proceeding with the plugin installation.
     Activate your virtual environment and run the following command:

     .. code-block:: bash

        pip install torch~=2.2.1 --index-url https://download.pytorch.org/whl/cu121

   .. note::

      On Windows, you may also need Microsoft's Visual C++ Redistributable if you don't have it already. See the
      PyTorch installation guide for more installation options and versions.

Installing the Plugin from FAB
------------------------------

1. Open your Unreal Engine project.
2. Navigate to the **FAB Marketplace** and search for `Unreal ML Agents`.
3. Click **Install** to add the plugin to your project.
4. Open Unreal Engine and go to **Edit** -> **Plugins**.
5. Find `Unreal ML Agents` in the **Installed Plugins** section and enable it.
6. Restart Unreal Engine to finalize the installation.

The plugin is now ready to enhance your Unreal Engine environments with advanced machine learning capabilities.

Installing Python Dependencies with `pip`
------------------------------------------

If you are not modifying the plugin or its Python packages, you can install the required Python dependencies directly
from PyPI:

1. Ensure Python 3.10 is installed on your system.
2. Run the following command to install the package:

   .. code-block:: bash

      pip install ue-agents

   This will automatically install `ue-agents-envs` as a dependency.

.. note::

   Installing the `ue-agents` Python package involves installing other dependencies it relies on. To avoid issues
   with conflicting versions, consider using a virtual environment. For detailed steps, refer to the
   :doc:`Virtual Environment Guide </intro/python-environment>`.

Advanced Installation: Cloning the Repository
---------------------------------------------

For developers who want to modify or extend the plugin and its Python packages, follow these steps:

1. Clone the repository:

   .. code-block:: bash

      git clone https://github.com/YourGitHub/UnrealMLAgents.git

2. Navigate to the `MLearning` directory within the repository.
3. Install the Python packages in editable mode using the `-e` flag:

   .. code-block:: bash

      cd MLearning/ue-agents-envs
      pip install -e .

      cd ../ue-agents
      pip install -e .

.. note::

   Running pip with the `-e` flag will let you make changes to the Python files directly and have those reflected
   when you run `ue-agents-learn`. It is important to install these packages in this order as the `ue-agents` package
   depends on `ue-agents-envs`, and installing it in the other order will download `ue-agents-envs` from PyPI.

.. _next-steps-installation:

Next Steps
----------

With the plugin and Python packages installed, you can start building and training intelligent agents in your Unreal
projects. Check out the :doc:`Getting Started </intro/getting-started>` guide for detailed tutorials and examples.

Help
----

If you run into any problems regarding ML-Agents, refer to our `Discord Server <https://discord.gg/XNNJFfgw6M>`_.
If you can't find a solution, please submit an issue and include relevant information such as:

- Your operating system and version.
- The Python version you are using.
- Exact error messages (whenever possible).
