# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: ueagents_envs/communicator_objects/brain_parameters.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
from google.protobuf.internal import builder as _builder
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n9ueagents_envs/communicator_objects/brain_parameters.proto\x12\x14\x63ommunicator_objects\"\x8b\x01\n\x0f\x41\x63tionSpecProto\x12\x1e\n\x16num_continuous_actions\x18\x01 \x01(\x05\x12\x1c\n\x14num_discrete_actions\x18\x02 \x01(\x05\x12\x1d\n\x15\x64iscrete_branch_sizes\x18\x03 \x03(\x05\x12\x1b\n\x13\x61\x63tion_descriptions\x18\x04 \x03(\t\"{\n\x14\x42rainParametersProto\x12\x12\n\nbrain_name\x18\x01 \x01(\t\x12\x13\n\x0bis_training\x18\x02 \x01(\x08\x12:\n\x0b\x61\x63tion_spec\x18\x03 \x01(\x0b\x32%.communicator_objects.ActionSpecProtob\x06proto3')

_globals = globals()
_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, _globals)
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'ueagents_envs.communicator_objects.brain_parameters_pb2', _globals)
if _descriptor._USE_C_DESCRIPTORS == False:

  DESCRIPTOR._options = None
  _globals['_ACTIONSPECPROTO']._serialized_start=84
  _globals['_ACTIONSPECPROTO']._serialized_end=223
  _globals['_BRAINPARAMETERSPROTO']._serialized_start=225
  _globals['_BRAINPARAMETERSPROTO']._serialized_end=348
# @@protoc_insertion_point(module_scope)
