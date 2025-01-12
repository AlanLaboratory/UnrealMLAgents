===============
Release process
===============

Versioning
==========

UnrealMLAgents follows the `standard Python versioning scheme`_. This means that the
canonical public version identifiers MUST comply with the following scheme::

    [N!]N(.N)*[{a|b|rc}N][.postN][.devN]

Following this scheme, UnrealMLAgents's release numbering will work as follow:

* Versions will be numbered in the form ``A.B`` or ``A.B.C``.
  We will ignore the [N!] part, the `version epoch`_, which is only used
  when project changes the way it handles version numbering in a way that
  means the normal version ordering rules will give the wrong answer.

* ``A.B``, is the *feature release* version number. This will increase
  every time we add a new feature (1.1 -> 1.2 -> ...). When we update the
  major version, it means that we have made major changes and that we might
  break backwards-compatibility. Minor version change should be compatible
  with previous release (Exception for early development that might break
  backwards-compatibility)

* ``C``. is only use for *bug fixes*. 100% backwards-compatibility

* ``[{a|b|rc}N][.postN][.devN]``. Before a new feature release, we'll make
  alpha, beta, and release candidate releases. These are of the form
  ``A.B alpha/beta/rc N`` (1.1a1, 1.1rc1)

Each time we will make a release we will put a tag to indicate the version
number and create a ``release/A.B.x`` branch where we will integrate bug
fixes and apply the final tag.

Release Cycle
-------------

Each release will consists of three parts:

#. *Feature proposal*: Discuss on what should be included
   for the next release.

#. *Development*: Develop the feature, make the docs. Try to respect
   the schedule and deliver all features.

#. *Bug Fixes*: When the deadline approaches and we have the features
   we want, we apply a ``alpha`` tag and create a ``release/A.B.x`` branch
   of the master branch. No new features will be accepted during this time.

.. _standard Python versioning scheme: https://peps.python.org/pep-0440/
.. _version epoch: https://peps.python.org/pep-0440/#version-epochs
