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
     Activate your :doc:`virtual environment </intro/python-environment>` and run the following command:

     .. code-block:: bash

        pip install torch~=2.4.1 --index-url https://download.pytorch.org/whl/cu124

   .. note::

      On Windows, you may also need Microsoft's Visual C++ Redistributable if you don't have it already. See the
      PyTorch installation guide for more installation options and versions.

For those who wants to develop in C++, please follow the very good documentation from Unreal Engine.
You need to install and configure one of the following IDEs:

   - `Setting Up Visual Studio <https://dev.epicgames.com/documentation/en-us/unreal-engine/setting-up-visual-studio-development-environment-for-cplusplus-projects-in-unreal-engine>`_
   - `Setting Up VS Code <https://dev.epicgames.com/documentation/en-us/unreal-engine/setting-up-visual-studio-code-for-unreal-engine>`_

.. note::

   In case you are interested by other aspects of Unreal Engine, you can find more information
   in the `Development Setup <https://dev.epicgames.com/documentation/en-us/unreal-engine/setting-up-your-development-environment-for-cplusplus-in-unreal-engine>`_

.. important::

   You can either install the plugin from the FAB Marketplace or clone the repository to access the full source code.
   If you choose the second option, you will need to build the plugin from source.
   Instructions are in the GitHub advanced installation section.

.. tab-set::

   .. tab-item:: FAB Marketplace (easy)

      1. Navigate to the `FAB Marketplace <https://www.fab.com/>`_ and search for `UnrealMLAgents`.
      2. Click **Add to My Library**.
      3. Open Epic Games Launcher and go to the **Unreal Engine -> Library** tab.
      4. Refresh the Fab Library and then **Install to Engine**.

      The plugin is now ready to enhance your Unreal Engine environments with advanced machine learning capabilities.

   .. tab-item:: GitHub (advanced)

      For developers who want to modify or extend the plugin and its Python packages, follow these steps:

      1. Clone the repository:

         .. code-block:: bash

            git clone git@github.com:AlanLaboratory/UnrealMLAgents.git

      2. Download the pre-built third-party binary libraries from `here <https://github.com/AlanLaboratory/UnrealMLAgents/releases/tag/0.1.0>`_.
      3. Extract the downloaded libraries to the `Source/ThirdParty` directory.

      To build the plugin from source, follow these steps:

         .. code-block:: console

            $ cd C:/Program Files/Epic Games/UE_5.X/Engine/Build/Batchfiles
            $ RunUAT.bat BuildPlugin -plugin="<path to this repo>\UnrealMLAgents.uplugin" -package="<somewhere/UnrealMLAgents>" -TargetPlatforms=Win64

      After building the plugin, you can copy the `UnrealMLAgents` folder to the Unreal Engine **Plugins/Marketplace** directory.

         .. code-block:: console

            $ cp -r UnrealMLAgents C:/Program Files/Epic Games/UE_5.X/Engine/Plugins/Marketplace

The plugin is now ready to use in your Unreal Engine projects.

Installing Python Dependencies with `pip`
------------------------------------------

Same for the Python packages, you can install them from PyPI or clone the repository to access the full source code.
If you are not familiar with Python, we recommend installing the packages from PyPI.
Last point, we recommand using a virtual environment to avoid conflicts with other Python packages. If you
are not familiar with virtual environments, you can find more information in the :doc:`Python Environment Guide </intro/python-environment>`.

.. note::

   If you have already installed pytorch at the beginning, you shoudld already have a virtual environment.

.. tab-set::

   .. tab-item:: PyPI (easy)

      If you are not modifying the plugin or its Python packages, you can install the required Python dependencies directly
      from PyPI:

      1. Ensure Python 3.10 is installed on your system.
      2. Run the following command to install the package:

         .. code-block:: bash

            pip install ueagents

         This will automatically install `ueagents_envs` as a dependency.

      .. note::

         Installing the `ueagents` Python package involves installing other dependencies it relies on. To avoid issues
         with conflicting versions, consider using a virtual environment. For detailed steps, refer to the
         :doc:`Virtual Environment Guide </intro/python-environment>`.

   .. tab-item:: GitHub (advanced)

      For this section, you first need to clone the repository to access the full source code.
      See above for more information on cloning the repository.

      1. Navigate into `MLearning` directory within the previously cloned repository.
      2. Install the Python packages in editable mode using the `-e` flag:

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
