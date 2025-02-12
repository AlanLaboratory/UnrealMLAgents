// Copyright © 2025 Stephane Capponi and individual contributors. All Rights Reserved.

#pragma warning(disable : 4100 4127 4267 4324)

// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ueagents_envs/communicator_objects/unreal_rl_output.proto

#include "ueagents_envs/communicator_objects/unreal_rl_output.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = ::PROTOBUF_NAMESPACE_ID::internal;
namespace communicator_objects {
template <typename>
PROTOBUF_CONSTEXPR UnrealRLOutputProto_ListAgentInfoProto::UnrealRLOutputProto_ListAgentInfoProto(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.value_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct UnrealRLOutputProto_ListAgentInfoProtoDefaultTypeInternal {
  PROTOBUF_CONSTEXPR UnrealRLOutputProto_ListAgentInfoProtoDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~UnrealRLOutputProto_ListAgentInfoProtoDefaultTypeInternal() {}
  union {
    UnrealRLOutputProto_ListAgentInfoProto _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 UnrealRLOutputProto_ListAgentInfoProtoDefaultTypeInternal _UnrealRLOutputProto_ListAgentInfoProto_default_instance_;
template <typename>
PROTOBUF_CONSTEXPR UnrealRLOutputProto_AgentInfosEntry_DoNotUse::UnrealRLOutputProto_AgentInfosEntry_DoNotUse(
    ::_pbi::ConstantInitialized) {}
struct UnrealRLOutputProto_AgentInfosEntry_DoNotUseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR UnrealRLOutputProto_AgentInfosEntry_DoNotUseDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~UnrealRLOutputProto_AgentInfosEntry_DoNotUseDefaultTypeInternal() {}
  union {
    UnrealRLOutputProto_AgentInfosEntry_DoNotUse _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 UnrealRLOutputProto_AgentInfosEntry_DoNotUseDefaultTypeInternal _UnrealRLOutputProto_AgentInfosEntry_DoNotUse_default_instance_;
template <typename>
PROTOBUF_CONSTEXPR UnrealRLOutputProto::UnrealRLOutputProto(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.agentinfos_)*/{}
  , /*decltype(_impl_.side_channel_)*/ {
    &::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized {}
  }

  , /*decltype(_impl_._cached_size_)*/{}} {}
struct UnrealRLOutputProtoDefaultTypeInternal {
  PROTOBUF_CONSTEXPR UnrealRLOutputProtoDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~UnrealRLOutputProtoDefaultTypeInternal() {}
  union {
    UnrealRLOutputProto _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 UnrealRLOutputProtoDefaultTypeInternal _UnrealRLOutputProto_default_instance_;
}  // namespace communicator_objects
static ::_pb::Metadata file_level_metadata_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto[3];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto = nullptr;
const ::uint32_t TableStruct_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto, _impl_.value_),
    PROTOBUF_FIELD_OFFSET(::communicator_objects::UnrealRLOutputProto_AgentInfosEntry_DoNotUse, _has_bits_),
    PROTOBUF_FIELD_OFFSET(::communicator_objects::UnrealRLOutputProto_AgentInfosEntry_DoNotUse, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::communicator_objects::UnrealRLOutputProto_AgentInfosEntry_DoNotUse, key_),
    PROTOBUF_FIELD_OFFSET(::communicator_objects::UnrealRLOutputProto_AgentInfosEntry_DoNotUse, value_),
    0,
    1,
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::communicator_objects::UnrealRLOutputProto, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::communicator_objects::UnrealRLOutputProto, _impl_.agentinfos_),
    PROTOBUF_FIELD_OFFSET(::communicator_objects::UnrealRLOutputProto, _impl_.side_channel_),
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        { 0, -1, -1, sizeof(::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto)},
        { 9, 19, -1, sizeof(::communicator_objects::UnrealRLOutputProto_AgentInfosEntry_DoNotUse)},
        { 21, -1, -1, sizeof(::communicator_objects::UnrealRLOutputProto)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::communicator_objects::_UnrealRLOutputProto_ListAgentInfoProto_default_instance_._instance,
    &::communicator_objects::_UnrealRLOutputProto_AgentInfosEntry_DoNotUse_default_instance_._instance,
    &::communicator_objects::_UnrealRLOutputProto_default_instance_._instance,
};
const char descriptor_table_protodef_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n9ueagents_envs/communicator_objects/unr"
    "eal_rl_output.proto\022\024communicator_object"
    "s\0323ueagents_envs/communicator_objects/ag"
    "ent_info.proto\"\266\002\n\023UnrealRLOutputProto\022M"
    "\n\nagentInfos\030\001 \003(\01329.communicator_object"
    "s.UnrealRLOutputProto.AgentInfosEntry\022\024\n"
    "\014side_channel\030\002 \001(\014\032I\n\022ListAgentInfoProt"
    "o\0223\n\005value\030\001 \003(\0132$.communicator_objects."
    "AgentInfoProto\032o\n\017AgentInfosEntry\022\013\n\003key"
    "\030\001 \001(\t\022K\n\005value\030\002 \001(\0132<.communicator_obj"
    "ects.UnrealRLOutputProto.ListAgentInfoPr"
    "oto:\0028\001b\006proto3"
};
static const ::_pbi::DescriptorTable* const descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto_deps[1] =
    {
        &::descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5finfo_2eproto,
};
static ::absl::once_flag descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto = {
    false,
    false,
    455,
    descriptor_table_protodef_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto,
    "ueagents_envs/communicator_objects/unreal_rl_output.proto",
    &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto_once,
    descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto_deps,
    1,
    3,
    schemas,
    file_default_instances,
    TableStruct_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto::offsets,
    file_level_metadata_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto,
    file_level_enum_descriptors_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto,
    file_level_service_descriptors_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto_getter() {
  return &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto(&descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto);
namespace communicator_objects {
// ===================================================================

class UnrealRLOutputProto_ListAgentInfoProto::_Internal {
 public:
};

void UnrealRLOutputProto_ListAgentInfoProto::clear_value() {
  _internal_mutable_value()->Clear();
}
UnrealRLOutputProto_ListAgentInfoProto::UnrealRLOutputProto_ListAgentInfoProto(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:communicator_objects.UnrealRLOutputProto.ListAgentInfoProto)
}
UnrealRLOutputProto_ListAgentInfoProto::UnrealRLOutputProto_ListAgentInfoProto(const UnrealRLOutputProto_ListAgentInfoProto& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  UnrealRLOutputProto_ListAgentInfoProto* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.value_){from._impl_.value_}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:communicator_objects.UnrealRLOutputProto.ListAgentInfoProto)
}

inline void UnrealRLOutputProto_ListAgentInfoProto::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_.value_){arena}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

UnrealRLOutputProto_ListAgentInfoProto::~UnrealRLOutputProto_ListAgentInfoProto() {
  // @@protoc_insertion_point(destructor:communicator_objects.UnrealRLOutputProto.ListAgentInfoProto)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void UnrealRLOutputProto_ListAgentInfoProto::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _internal_mutable_value()->~RepeatedPtrField();
}

void UnrealRLOutputProto_ListAgentInfoProto::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void UnrealRLOutputProto_ListAgentInfoProto::Clear() {
// @@protoc_insertion_point(message_clear_start:communicator_objects.UnrealRLOutputProto.ListAgentInfoProto)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _internal_mutable_value()->Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* UnrealRLOutputProto_ListAgentInfoProto::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // repeated .communicator_objects.AgentInfoProto value = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_value(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else {
          goto handle_unusual;
        }
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::uint8_t* UnrealRLOutputProto_ListAgentInfoProto::_InternalSerialize(
    ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:communicator_objects.UnrealRLOutputProto.ListAgentInfoProto)
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .communicator_objects.AgentInfoProto value = 1;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_value_size()); i < n; i++) {
    const auto& repfield = this->_internal_value(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(1, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:communicator_objects.UnrealRLOutputProto.ListAgentInfoProto)
  return target;
}

::size_t UnrealRLOutputProto_ListAgentInfoProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:communicator_objects.UnrealRLOutputProto.ListAgentInfoProto)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .communicator_objects.AgentInfoProto value = 1;
  total_size += 1UL * this->_internal_value_size();
  for (const auto& msg : this->_internal_value()) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData UnrealRLOutputProto_ListAgentInfoProto::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    UnrealRLOutputProto_ListAgentInfoProto::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*UnrealRLOutputProto_ListAgentInfoProto::GetClassData() const { return &_class_data_; }


void UnrealRLOutputProto_ListAgentInfoProto::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<UnrealRLOutputProto_ListAgentInfoProto*>(&to_msg);
  auto& from = static_cast<const UnrealRLOutputProto_ListAgentInfoProto&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:communicator_objects.UnrealRLOutputProto.ListAgentInfoProto)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_value()->MergeFrom(from._internal_value());
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void UnrealRLOutputProto_ListAgentInfoProto::CopyFrom(const UnrealRLOutputProto_ListAgentInfoProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:communicator_objects.UnrealRLOutputProto.ListAgentInfoProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UnrealRLOutputProto_ListAgentInfoProto::IsInitialized() const {
  return true;
}

void UnrealRLOutputProto_ListAgentInfoProto::InternalSwap(UnrealRLOutputProto_ListAgentInfoProto* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _internal_mutable_value()->InternalSwap(other->_internal_mutable_value());
}

::PROTOBUF_NAMESPACE_ID::Metadata UnrealRLOutputProto_ListAgentInfoProto::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto_getter, &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto_once,
      file_level_metadata_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto[0]);
}
// ===================================================================

UnrealRLOutputProto_AgentInfosEntry_DoNotUse::UnrealRLOutputProto_AgentInfosEntry_DoNotUse() {}
UnrealRLOutputProto_AgentInfosEntry_DoNotUse::UnrealRLOutputProto_AgentInfosEntry_DoNotUse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
    : SuperType(arena) {}
void UnrealRLOutputProto_AgentInfosEntry_DoNotUse::MergeFrom(const UnrealRLOutputProto_AgentInfosEntry_DoNotUse& other) {
  MergeFromInternal(other);
}
::PROTOBUF_NAMESPACE_ID::Metadata UnrealRLOutputProto_AgentInfosEntry_DoNotUse::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto_getter, &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto_once,
      file_level_metadata_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto[1]);
}
// ===================================================================

class UnrealRLOutputProto::_Internal {
 public:
};

UnrealRLOutputProto::UnrealRLOutputProto(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:communicator_objects.UnrealRLOutputProto)
}
UnrealRLOutputProto::UnrealRLOutputProto(const UnrealRLOutputProto& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  UnrealRLOutputProto* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      /*decltype(_impl_.agentinfos_)*/{}
    , decltype(_impl_.side_channel_) {}

    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _this->_impl_.agentinfos_.MergeFrom(from._impl_.agentinfos_);
  _impl_.side_channel_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.side_channel_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_side_channel().empty()) {
    _this->_impl_.side_channel_.Set(from._internal_side_channel(), _this->GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:communicator_objects.UnrealRLOutputProto)
}

inline void UnrealRLOutputProto::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      /*decltype(_impl_.agentinfos_)*/{::_pbi::ArenaInitialized(), arena}
    , decltype(_impl_.side_channel_) {}

    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.side_channel_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.side_channel_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

UnrealRLOutputProto::~UnrealRLOutputProto() {
  // @@protoc_insertion_point(destructor:communicator_objects.UnrealRLOutputProto)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void UnrealRLOutputProto::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.agentinfos_.~MapField();
  _impl_.side_channel_.Destroy();
}

void UnrealRLOutputProto::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void UnrealRLOutputProto::Clear() {
// @@protoc_insertion_point(message_clear_start:communicator_objects.UnrealRLOutputProto)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.agentinfos_.Clear();
  _impl_.side_channel_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* UnrealRLOutputProto::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // map<string, .communicator_objects.UnrealRLOutputProto.ListAgentInfoProto> agentInfos = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 10)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(&_impl_.agentinfos_, ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<10>(ptr));
        } else {
          goto handle_unusual;
        }
        continue;
      // bytes side_channel = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_side_channel();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else {
          goto handle_unusual;
        }
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::uint8_t* UnrealRLOutputProto::_InternalSerialize(
    ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:communicator_objects.UnrealRLOutputProto)
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // map<string, .communicator_objects.UnrealRLOutputProto.ListAgentInfoProto> agentInfos = 1;
  if (!this->_internal_agentinfos().empty()) {
    using MapType = ::_pb::Map<std::string, ::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto>;
    using WireHelper = UnrealRLOutputProto_AgentInfosEntry_DoNotUse::Funcs;
    const auto& map_field = this->_internal_agentinfos();
    auto check_utf8 = [](const MapType::value_type& entry) {
      (void)entry;
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
          entry.first.data(), static_cast<int>(entry.first.length()),
 ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE, "communicator_objects.UnrealRLOutputProto.agentInfos");
    };

    if (stream->IsSerializationDeterministic() && map_field.size() > 1) {
      for (const auto& entry : ::_pbi::MapSorterPtr<MapType>(map_field)) {
        target = WireHelper::InternalSerialize(1, entry.first, entry.second, target, stream);
        check_utf8(entry);
      }
    } else {
      for (const auto& entry : map_field) {
        target = WireHelper::InternalSerialize(1, entry.first, entry.second, target, stream);
        check_utf8(entry);
      }
    }
  }

  // bytes side_channel = 2;
  if (!this->_internal_side_channel().empty()) {
    const std::string& _s = this->_internal_side_channel();
    target = stream->WriteBytesMaybeAliased(2, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:communicator_objects.UnrealRLOutputProto)
  return target;
}

::size_t UnrealRLOutputProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:communicator_objects.UnrealRLOutputProto)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // map<string, .communicator_objects.UnrealRLOutputProto.ListAgentInfoProto> agentInfos = 1;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(this->_internal_agentinfos_size());
  for (::PROTOBUF_NAMESPACE_ID::Map< std::string, ::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto >::const_iterator
      it = this->_internal_agentinfos().begin();
      it != this->_internal_agentinfos().end(); ++it) {
    total_size += UnrealRLOutputProto_AgentInfosEntry_DoNotUse::Funcs::ByteSizeLong(it->first, it->second);
  }

  // bytes side_channel = 2;
  if (!this->_internal_side_channel().empty()) {
    total_size += 1 + ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
                                    this->_internal_side_channel());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData UnrealRLOutputProto::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    UnrealRLOutputProto::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*UnrealRLOutputProto::GetClassData() const { return &_class_data_; }


void UnrealRLOutputProto::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<UnrealRLOutputProto*>(&to_msg);
  auto& from = static_cast<const UnrealRLOutputProto&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:communicator_objects.UnrealRLOutputProto)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.agentinfos_.MergeFrom(from._impl_.agentinfos_);
  if (!from._internal_side_channel().empty()) {
    _this->_internal_set_side_channel(from._internal_side_channel());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void UnrealRLOutputProto::CopyFrom(const UnrealRLOutputProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:communicator_objects.UnrealRLOutputProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool UnrealRLOutputProto::IsInitialized() const {
  return true;
}

void UnrealRLOutputProto::InternalSwap(UnrealRLOutputProto* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.agentinfos_.InternalSwap(&other->_impl_.agentinfos_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.side_channel_, lhs_arena,
                                       &other->_impl_.side_channel_, rhs_arena);
}

::PROTOBUF_NAMESPACE_ID::Metadata UnrealRLOutputProto::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto_getter, &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto_once,
      file_level_metadata_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto[2]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace communicator_objects
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto*
Arena::CreateMaybeMessage< ::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto >(Arena* arena) {
  return Arena::CreateMessageInternal< ::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto >(arena);
}
template<> PROTOBUF_NOINLINE ::communicator_objects::UnrealRLOutputProto_AgentInfosEntry_DoNotUse*
Arena::CreateMaybeMessage< ::communicator_objects::UnrealRLOutputProto_AgentInfosEntry_DoNotUse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::communicator_objects::UnrealRLOutputProto_AgentInfosEntry_DoNotUse >(arena);
}
template<> PROTOBUF_NOINLINE ::communicator_objects::UnrealRLOutputProto*
Arena::CreateMaybeMessage< ::communicator_objects::UnrealRLOutputProto >(Arena* arena) {
  return Arena::CreateMessageInternal< ::communicator_objects::UnrealRLOutputProto >(arena);
}
PROTOBUF_NAMESPACE_CLOSE
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"
