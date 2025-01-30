==============================
Contributing to UnrealMLAgents
==============================

Thank you for considering contributing to UnrealMLAgents! Whether you're fixing bugs,
writing documentation, or proposing new features, every contribution is valuable and helps improve the project.

We welcome contributors of all experience levels. Every little bit helps!

Writing Code
============

We use Clang with rules defined in `.clang-format`. A GitHub action with `Restyled` checks
these rules on each pull request. Restyled will suggest changes, but you must apply them manually.

.. note::

   To apply Restyled changes locally, refer to its logs and run the suggested commands.

Features
========

New Features
------------

We would love to hear your suggestions. Feel free to `submit them as issues <https://github.com/AlanLaboratory/UnrealMLAgents/issues>`_ and:

* Explain your suggestions and how they would work.
* Describe any impacts on the project and why they are necessary.
* Keep it simple and clear!

Implement Features
------------------

Look through the `GitHub issues for enhancements <https://github.com/AlanLaboratory/UnrealMLAgents/issues>`_
and use the `UnrealMLAgents GitHub discussion <https://github.com/AlanLaboratory/UnrealMLAgents/discussions>`_ to find guidance.

To claim a feature, comment on the specific enhancement issue and join
the `Discord server <https://discord.gg/XNNJFfgw6M>`_ for further discussion.

Bugs
====

Report Bugs
-----------

If you encounter a bug, confirm it by discussing it in the `UnrealMLAgents GitHub discussion <https://github.com/AlanLaboratory/UnrealMLAgents/discussions>`_
or the `Discord server <https://discord.gg/XNNJFfgw6M>`_ under the development channel.

Submit bug reports through the `issue tracker <https://github.com/AlanLaboratory/UnrealMLAgents/issues>`_, including:

* A detailed description of the bug or problem you are having.
* The operating system and version.
* Steps to reproduce the issue (minimum example if possible).
* The version of UnrealMLAgents in use.

Fix Bugs
--------

Explore `GitHub issues for bugs <https://github.com/AlanLaboratory/UnrealMLAgents/issues>`_
for existing reports. Use GitHub discussions or Discord for further clarification.

Indicate your intent to fix a bug by commenting on the issue.

Writing Documentation
=====================

UnrealMLAgents always needs better documentation. Whether clarifying unclear sections
or adding new examples, your help is invaluable. Here's how you can contribute:

* Add supplementary information to unclear sections.
* Improve function, class, and attribute docstrings following the `Sphinx docstring format <https://sphinx-rtd-tutorial.readthedocs.io/en/latest/docstrings.html>`_.
* Provide examples, tutorials, or how-to guides.

To build the documentation locally, install Sphinx:

.. code-block:: console

   $ python -m pip install -r Docs/requirements.txt

From the ``Docs`` directory, build the HTML documentation:

.. code-block:: console

   $ make html

The documentation will be available in ``Docs/_build/html``.

Contribute
==========

Contribution is done through pull request from your own UnrealMLAgents repository (fork).
As a quick reminder, a pull request informs UnrealMLAgents's core development team about
the changes that you have submitted. It will allow us to review the code and to make
comment to discuss its potential modification or not.

#. Fork the `UnrealMLAgents <https://github.com/AlanLaboratory/UnrealMLAgents>`_ repository.

#. Clone your fork locally:

   .. code-block:: console

      $ git clone git@github.com:YOUR_GITHUB_USERNAME/UnrealMLAgents.git
      $ cd UnrealMLAgents

#. Create a branch from `master`:

   .. code-block:: console

      $ git checkout -b your-branch master

#. Add the main UnrealMLAgents remote as ``upstream``:

   .. code-block:: console

      $ git remote add upstream https://github.com/AlanLaboratory/UnrealMLAgents

#. Install `pre-commit <https://pre-commit.com>`_:

   .. code-block:: console

      $ pip install pre-commit==4.1.0
      $ pre-commit install
      $ pre-commit install --hook-type commit-msg

   Afterwards ``pre-commit`` will run whenever you commit.

   https://pre-commit.com/ is a framework for managing and maintaining multi-language
   pre-commit hooks to ensure code-style and code formatting is consistent.

#. Build the plugin in case you made a change to the C++ code:

   .. code-block:: console

      $ cd C:\Program Files\Epic Games\UE_5.2\Engine\Build\Batchfiles
      $ RunUAT.bat BuildPlugin -plugin="<path to this repo>\UnrealMLAgents.uplugin" -package="<somewhere>" -TargetPlatforms=Win64

   You need to build successfully before you can push your changes.
   Full `Building Plugins <https://dev.epicgames.com/community/learning/tutorials/qz93/unreal-engine-building-plugins>`_ documentation.

#. Create a new changelog entry in `changelog` directory. The file should be named
   <issueid>.<type>.rst, where issueid is the number of the issue related to
   the change and type is one of feature, improvement, bugfix, doc, deprecation,
   breaking, or trivial. You may skip creating the changelog entry if the
   change doesn't affect the documented behaviour of UnrealMLAgents.

   .. code-block:: console

      $ echo "Your changelog content" > changelog/<issueid>.<type>.rst

#. Add yourself to the `AUTHORS` file in alphabetical order.

#. Commit and push your changes:

   .. code-block:: console

      $ git commit -m "[#ticket-id] <commit message>"
      $ git push -u

#. Submit your pull request through the GitHub website.

UnrealMLAgents will automatically test your pull request and notify you of any issues.
