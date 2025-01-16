import os
import sys
from setuptools import setup, find_packages
from setuptools.command.install import install
import mlagents_envs
from pathlib import Path

VERSION = mlagents_envs.__version__
EXPECTED_TAG = mlagents_envs.__release_tag__

BASE_DIR = Path(__file__).resolve().parent


# Get the long description from the README file
with BASE_DIR.joinpath("README.md").open(encoding="utf-8") as f:
    long_description = f.read()

setup(
    name="mlagents_envs",
    version=VERSION,
    description="Unreal Machine Learning Agents Interface based on Unity ML Agents",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/AlanLaboratory/UnrealMLAgents",
    author="Stephane Capponi",
    classifiers=[
        "Intended Audience :: Developers",
        "Topic :: Scientific/Engineering :: Artificial Intelligence",
        "License :: OSI Approved :: Apache Software License",
        "Programming Language :: Python :: 3.10",
    ],
    packages=find_packages(
        exclude=["*.tests", "*.tests.*", "tests.*", "tests", "colabs", "*.ipynb"]
    ),
    zip_safe=False,
    install_requires=[
        "gymnasium==0.28.1",
        "numpy<1.24.0,>=1.23.5",
        "grpcio==1.66.2",
        "protobuf==3.20.3",
        "grpcio-tools==1.46",
    ],
    python_requires=">=3.10.1,<=3.10.12",
)