# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: ueagents_envs/communicator_objects/unreal_rl_input.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
from google.protobuf.internal import builder as _builder
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from ueagents_envs.communicator_objects import agent_action_pb2 as ueagents__envs_dot_communicator__objects_dot_agent__action__pb2
from ueagents_envs.communicator_objects import command_pb2 as ueagents__envs_dot_communicator__objects_dot_command__pb2


DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n8ueagents_envs/communicator_objects/unreal_rl_input.proto\x12\x14\x63ommunicator_objects\x1a\x35ueagents_envs/communicator_objects/agent_action.proto\x1a\x30ueagents_envs/communicator_objects/command.proto\"\xf5\x02\n\x12UnrealRLInputProto\x12Q\n\ragent_actions\x18\x01 \x03(\x0b\x32:.communicator_objects.UnrealRLInputProto.AgentActionsEntry\x12\x33\n\x07\x63ommand\x18\x02 \x01(\x0e\x32\".communicator_objects.CommandProto\x12\x14\n\x0cside_channel\x18\x03 \x01(\x0c\x1aM\n\x14ListAgentActionProto\x12\x35\n\x05value\x18\x01 \x03(\x0b\x32&.communicator_objects.AgentActionProto\x1ar\n\x11\x41gentActionsEntry\x12\x0b\n\x03key\x18\x01 \x01(\t\x12L\n\x05value\x18\x02 \x01(\x0b\x32=.communicator_objects.UnrealRLInputProto.ListAgentActionProto:\x02\x38\x01\x62\x06proto3')

_globals = globals()
_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, _globals)
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'ueagents_envs.communicator_objects.unreal_rl_input_pb2', _globals)
if _descriptor._USE_C_DESCRIPTORS == False:

  DESCRIPTOR._options = None
  _UNREALRLINPUTPROTO_AGENTACTIONSENTRY._options = None
  _UNREALRLINPUTPROTO_AGENTACTIONSENTRY._serialized_options = b'8\001'
  _globals['_UNREALRLINPUTPROTO']._serialized_start=188
  _globals['_UNREALRLINPUTPROTO']._serialized_end=561
  _globals['_UNREALRLINPUTPROTO_LISTAGENTACTIONPROTO']._serialized_start=368
  _globals['_UNREALRLINPUTPROTO_LISTAGENTACTIONPROTO']._serialized_end=445
  _globals['_UNREALRLINPUTPROTO_AGENTACTIONSENTRY']._serialized_start=447
  _globals['_UNREALRLINPUTPROTO_AGENTACTIONSENTRY']._serialized_end=561
# @@protoc_insertion_point(module_scope)
