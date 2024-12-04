#!/bin/bash

# GRPC-TOOLS required. Install with `nuget install Grpc.Tools`.
# Then un-comment and replace [DIRECTORY] with location of files.
# For example, on macOS, you might have something like:
# COMPILER=Grpc.Tools.1.14.1/tools/macosx_x64
COMPILER=../Source/ThirdParty/protobuf/bin

SRC_DIR=proto/ueagents_envs/communicator_objects
DST_DIR_C=../Source/UnrealMLAgents/Grpc
DST_DIR_P=../MLearning/ue-agents-envs
PYTHON_PACKAGE=ueagents_envs/communicator_objects

# clean
rm -rf $DST_DIR_C
rm -rf $DST_DIR_P/$PYTHON_PACKAGE
mkdir -p $DST_DIR_C
mkdir -p $DST_DIR_P/$PYTHON_PACKAGE

# generate proto objects in python and C#

$COMPILER/protoc.exe --proto_path=proto --cpp_out $DST_DIR_C $SRC_DIR/*.proto
$COMPILER/protoc.exe --proto_path=proto --python_out=$DST_DIR_P $SRC_DIR/*.proto

# grpc

GRPC=unreal_to_external.proto

$COMPILER/protoc.exe --proto_path=proto --cpp_out=$DST_DIR_C --grpc_out=$DST_DIR_C $SRC_DIR/$GRPC --plugin=protoc-gen-grpc=$COMPILER/../../grpc/bin/grpc_cpp_plugin.exe
python -m grpc_tools.protoc --proto_path=proto --python_out=$DST_DIR_P --grpc_python_out=$DST_DIR_P $SRC_DIR/$GRPC


# Generate the init file for the python module
# rm -f $DST_DIR_P/$PYTHON_PACKAGE/__init__.py
for FILE in $DST_DIR_P/$PYTHON_PACKAGE/*.py
do
FILE=${FILE##*/}
# echo from .$(basename $FILE) import \* >> $DST_DIR_P/$PYTHON_PACKAGE/__init__.py
echo from .${FILE%.py} import \* >> $DST_DIR_P/$PYTHON_PACKAGE/__init__.py
done

# Remove the __init__.py file since it is not needed
rm $DST_DIR_P/$PYTHON_PACKAGE/__init__.py
touch $DST_DIR_P/$PYTHON_PACKAGE/__init__.py

# Add disable warning C4800 introduced by gRPC
sed -i '/^\s\+_impl_\.is_training_.*/i \ \ \ \ \ \ \ \ \ \ #pragma warning(disable: 4800)' $DST_DIR_C/$PYTHON_PACKAGE/brain_parameters.pb.cc
sed -i '/^\s\+_impl_\.done_.*/i \ \ \ \ \ \ \ \ \ \ #pragma warning(disable: 4800)' $DST_DIR_C/$PYTHON_PACKAGE/agent_info.pb.cc
sed -i '/^\s\+_impl_\.extrinsic_reward_enabled_.*/i \ \ \ \ \ \ \ \ \ \ #pragma warning(disable: 4800)' $DST_DIR_C/$PYTHON_PACKAGE/training_analytics.pb.cc
