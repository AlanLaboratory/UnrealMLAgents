Virtual environment
===================

Python programs often use packages and modules that are not part of the standard
library. Sometimes these programs require a specific version of a library, because
a specific bug has been fixed or the program has been implemented using an
obsolete version.

This means it isn't always possible for a single installation of Python
to cover all the needs of all applications.

The solution is to create a virtual environment. A self-sufficient folder
that contains a Python installation for a particular version with
additional packages.

Installing pip
--------------

Pip is the package manager of python. It is used to install/update packages
in your environment. The first thing to do is to check if you have the
latest version of pip. Usually pip comes directly with python.

On MacOs, Linux or Linux emulator (git-bash, ...):

.. code-block:: console

    $ python3 -m pip install --upgrade pip

On windows:

.. code-block:: console

    $ py -3 -m pip install --upgrade pip

Installing virtualenv
---------------------

As `ue-agents` and `ue-agents-envs` are using python >= 3.10, the package ``venv`` should
be installed by default and should be the preferred way to create an environment.

Creating a virtual environment
------------------------------

``venv`` allows you to manage separate package installations for different projects.
This allows you to keep a separate directory of installed packages for each of
your projects so that they don't interfere with each other.

On MacOs, Linux or Linux emulator (git-bash, ...):

.. code-block:: console

    $ python3 -m venv .venv

On windows:

.. code-block:: console

    $ py -3 -m venv .venv

The second argument is the location to create the virtual environment.
Generally, you can just create this in your project and call it ``.venv``.

Activating a virtual environment
--------------------------------

Before installing a package and starting your development, you will have to
activate the environment. Activating a virtual environment will put the
virtual environment-specific python and pip executable into your shell's PATH.

On MacOs, Linux:

.. code-block:: console

    $ source venv/bin/activate

On windows:

.. code-block:: console

    $ .\venv\Scripts\activate

On Linux emulator (git-bash, ...):

.. code-block:: console

    $ source venv/Scripts/activate

Leaving the environment
-----------------------

If at any time you want to switch projects or otherwise leave your
virtual environment, simply run:

.. code-block:: console

    $ deactivate