============
Installation
============

This plugin is designed to provide Unreal Engine developers with advanced machine learning tools inspired by Unity's
ML-Agents Toolkit. You can install the plugin directly from FAB, Unreal Engine's marketplace, or by cloning the repository
for full control over the `ue-agents` and `ue-agents-envs` packages.

Installing the Plugin from FAB
------------------------------

1. Open your Unreal Engine project.
2. Navigate to the **FAB Marketplace** and search for `Unreal ML Agents`.
3. Click **Install** to add the plugin to your project.
4. Open Unreal Engine and go to **Edit** -> **Plugins**.
5. Find `UnrealMLAgents` in the **Installed Plugins** section and enable it.
6. Restart Unreal Engine to finalize the installation.

The plugin is now ready to enhance your Unreal Engine environments with advanced machine learning capabilities.

Installing Python Dependencies with `pip`
------------------------------------------

The plugin relies on two Python packages located in the same repository: `ue-agents` and `ue-agents-envs`. These are
adapted versions of Unity's `ml-agents` and `ml-agents-envs` with modifications specific to Unreal Engine.

1. Ensure Python 3.10 is installed on your system.
2. Navigate to the repository root.
3. Install the Python packages using:

   ```bash
   pip install ./MLearning/ue-agents-envs
   pip install ./MLearning/ue-agents
   ```

4. Verify the installation by running:

   ```bash
   ue-agents-learn --help
   ```

   This should display the available command-line parameters for training.

Advanced Installation: Cloning the Repository
---------------------------------------------

For developers who want to modify or extend the plugin and its Python packages, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/YourGitHub/UnrealMLAgents.git
   ```

2. Navigate to the `MLearning` directory within the repository.
3. Install the Python packages in editable mode using the `-e` flag:

   ```bash
   cd MLearning/ue-agents-envs
   pip install -e .

   cd ../ue-agents
   pip install -e .
   ```

4. Verify the installation as outlined in the previous section.

**Note:** Using `-e` ensures that changes to the Python files are immediately reflected without requiring reinstallation.

Testing the Installation
-------------------------

After completing the installation, ensure everything is working by running a quick test:

1. Open Unreal Engine and enable the `Unreal ML Agents` plugin as described above.
2. Run a Python script using the installed `ue-agents` package to confirm communication between Python and Unreal Engine.

Next Steps
----------

With the plugin and Python packages installed, you can start building and training intelligent agents in your Unreal
projects. Check out the :doc:`Getting Started <getting_started>` guide for detailed tutorials and examples.

