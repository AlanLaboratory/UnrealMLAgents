# Unreal ML-Agents Protobuf Definitions

Contains relevant definitions needed to generate probobuf files used in [UnrealMLAgents Toolkit](https://github.com/AlanLaboratory/UnrealMLAgents).

## Set-up & Installation

First we will follow these steps once install protobuf and grpcio-tools via your terminal.
Assume the UnrealMLAgents repository is checked out to a folder named $UNREAL_ROOT.

`pip install -r Protobuf/requirements.txt`

## Running

Whenever you change the fields of a message, you must follow the steps below to create C++ and Python files corresponding to the new message.

1. Open a terminal. **Note:** If you're using Anaconda, don't forget to activate the ml-agents environment first.
2. Run the protobuf generation script from the terminal by navigating to `$UNREAL_ROOT/Protobuf` and entering `make.sh`
