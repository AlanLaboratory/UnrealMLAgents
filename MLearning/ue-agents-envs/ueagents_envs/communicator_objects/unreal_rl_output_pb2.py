# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: ueagents_envs/communicator_objects/unreal_rl_output.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
from google.protobuf.internal import builder as _builder
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from ueagents_envs.communicator_objects import agent_info_pb2 as ueagents__envs_dot_communicator__objects_dot_agent__info__pb2


DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n9ueagents_envs/communicator_objects/unreal_rl_output.proto\x12\x14\x63ommunicator_objects\x1a\x33ueagents_envs/communicator_objects/agent_info.proto\"\xa0\x02\n\x13UnrealRLOutputProto\x12M\n\nagentInfos\x18\x01 \x03(\x0b\x32\x39.communicator_objects.UnrealRLOutputProto.AgentInfosEntry\x1aI\n\x12ListAgentInfoProto\x12\x33\n\x05value\x18\x01 \x03(\x0b\x32$.communicator_objects.AgentInfoProto\x1ao\n\x0f\x41gentInfosEntry\x12\x0b\n\x03key\x18\x01 \x01(\t\x12K\n\x05value\x18\x02 \x01(\x0b\x32<.communicator_objects.UnrealRLOutputProto.ListAgentInfoProto:\x02\x38\x01\x62\x06proto3')

_globals = globals()
_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, _globals)
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'ueagents_envs.communicator_objects.unreal_rl_output_pb2', _globals)
if _descriptor._USE_C_DESCRIPTORS == False:

  DESCRIPTOR._options = None
  _UNREALRLOUTPUTPROTO_AGENTINFOSENTRY._options = None
  _UNREALRLOUTPUTPROTO_AGENTINFOSENTRY._serialized_options = b'8\001'
  _globals['_UNREALRLOUTPUTPROTO']._serialized_start=137
  _globals['_UNREALRLOUTPUTPROTO']._serialized_end=425
  _globals['_UNREALRLOUTPUTPROTO_LISTAGENTINFOPROTO']._serialized_start=239
  _globals['_UNREALRLOUTPUTPROTO_LISTAGENTINFOPROTO']._serialized_end=312
  _globals['_UNREALRLOUTPUTPROTO_AGENTINFOSENTRY']._serialized_start=314
  _globals['_UNREALRLOUTPUTPROTO_AGENTINFOSENTRY']._serialized_end=425
# @@protoc_insertion_point(module_scope)
