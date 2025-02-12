// Copyright © 2025 Stephane Capponi and individual contributors. All Rights Reserved.

#pragma warning(disable : 4100 4127 4267 4324)

// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ueagents_envs/communicator_objects/agent_action.proto

#include "ueagents_envs/communicator_objects/agent_action.pb.h"

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
PROTOBUF_CONSTEXPR AgentActionProto::AgentActionProto(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.continuous_actions_)*/ {}

  , /*decltype(_impl_.discrete_actions_)*/ {}
  ,/* _impl_._discrete_actions_cached_byte_size_ = */ { 0 }

  , /*decltype(_impl_.value_)*/ 0

  , /*decltype(_impl_._cached_size_)*/{}} {}
struct AgentActionProtoDefaultTypeInternal {
  PROTOBUF_CONSTEXPR AgentActionProtoDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~AgentActionProtoDefaultTypeInternal() {}
  union {
    AgentActionProto _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 AgentActionProtoDefaultTypeInternal _AgentActionProto_default_instance_;
}  // namespace communicator_objects
static ::_pb::Metadata file_level_metadata_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto = nullptr;
const ::uint32_t TableStruct_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::communicator_objects::AgentActionProto, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::communicator_objects::AgentActionProto, _impl_.value_),
    PROTOBUF_FIELD_OFFSET(::communicator_objects::AgentActionProto, _impl_.continuous_actions_),
    PROTOBUF_FIELD_OFFSET(::communicator_objects::AgentActionProto, _impl_.discrete_actions_),
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        { 0, -1, -1, sizeof(::communicator_objects::AgentActionProto)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::communicator_objects::_AgentActionProto_default_instance_._instance,
};
const char descriptor_table_protodef_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n5ueagents_envs/communicator_objects/age"
    "nt_action.proto\022\024communicator_objects\"W\n"
    "\020AgentActionProto\022\r\n\005value\030\001 \001(\002\022\032\n\022cont"
    "inuous_actions\030\002 \003(\002\022\030\n\020discrete_actions"
    "\030\003 \003(\005b\006proto3"
};
static ::absl::once_flag descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto = {
    false,
    false,
    174,
    descriptor_table_protodef_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto,
    "ueagents_envs/communicator_objects/agent_action.proto",
    &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto_once,
    nullptr,
    0,
    1,
    schemas,
    file_default_instances,
    TableStruct_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto::offsets,
    file_level_metadata_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto,
    file_level_enum_descriptors_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto,
    file_level_service_descriptors_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto,
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
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto_getter() {
  return &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto(&descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto);
namespace communicator_objects {
// ===================================================================

class AgentActionProto::_Internal {
 public:
};

AgentActionProto::AgentActionProto(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:communicator_objects.AgentActionProto)
}
AgentActionProto::AgentActionProto(const AgentActionProto& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  AgentActionProto* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.continuous_actions_) { from._impl_.continuous_actions_ }

    , decltype(_impl_.discrete_actions_) { from._impl_.discrete_actions_ }
    ,/* _impl_._discrete_actions_cached_byte_size_ = */ { 0 }

    , decltype(_impl_.value_) {}

    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _this->_impl_.value_ = from._impl_.value_;
  // @@protoc_insertion_point(copy_constructor:communicator_objects.AgentActionProto)
}

inline void AgentActionProto::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_.continuous_actions_) { arena }

    , decltype(_impl_.discrete_actions_) { arena }
    ,/* _impl_._discrete_actions_cached_byte_size_ = */ { 0 }

    , decltype(_impl_.value_) { 0 }

    , /*decltype(_impl_._cached_size_)*/{}
  };
}

AgentActionProto::~AgentActionProto() {
  // @@protoc_insertion_point(destructor:communicator_objects.AgentActionProto)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void AgentActionProto::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.continuous_actions_.~RepeatedField();
  _impl_.discrete_actions_.~RepeatedField();
}

void AgentActionProto::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void AgentActionProto::Clear() {
// @@protoc_insertion_point(message_clear_start:communicator_objects.AgentActionProto)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _internal_mutable_continuous_actions()->Clear();
  _internal_mutable_discrete_actions()->Clear();
  _impl_.value_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* AgentActionProto::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // float value = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 13)) {
          _impl_.value_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr);
          ptr += sizeof(float);
        } else {
          goto handle_unusual;
        }
        continue;
      // repeated float continuous_actions = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 18)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedFloatParser(_internal_mutable_continuous_actions(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<::uint8_t>(tag) == 21) {
          _internal_add_continuous_actions(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<float>(ptr));
          ptr += sizeof(float);
        } else {
          goto handle_unusual;
        }
        continue;
      // repeated int32 discrete_actions = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 26)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedInt32Parser(_internal_mutable_discrete_actions(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<::uint8_t>(tag) == 24) {
          _internal_add_discrete_actions(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
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

::uint8_t* AgentActionProto::_InternalSerialize(
    ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:communicator_objects.AgentActionProto)
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // float value = 1;
  static_assert(sizeof(::uint32_t) == sizeof(float), "Code assumes ::uint32_t and float are the same size.");
  float tmp_value = this->_internal_value();
  ::uint32_t raw_value;
  memcpy(&raw_value, &tmp_value, sizeof(tmp_value));
  if (raw_value != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFloatToArray(
        1, this->_internal_value(), target);
  }

  // repeated float continuous_actions = 2;
  if (this->_internal_continuous_actions_size() > 0) {
    target = stream->WriteFixedPacked(2, _internal_continuous_actions(), target);
  }

  // repeated int32 discrete_actions = 3;
  {
    int byte_size = _impl_._discrete_actions_cached_byte_size_.Get();
    if (byte_size > 0) {
      target = stream->WriteInt32Packed(3, _internal_discrete_actions(),
                                                 byte_size, target);
    }
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:communicator_objects.AgentActionProto)
  return target;
}

::size_t AgentActionProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:communicator_objects.AgentActionProto)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated float continuous_actions = 2;
  {
    std::size_t data_size = std::size_t{4} *
        ::_pbi::FromIntSize(this->_internal_continuous_actions_size())
    ;
    std::size_t tag_size = data_size == 0
        ? 0
        : 1 + ::_pbi::WireFormatLite::Int32Size(
                            static_cast<int32_t>(data_size))
    ;
    total_size += tag_size + data_size;
  }

  // repeated int32 discrete_actions = 3;
  {
    std::size_t data_size = ::_pbi::WireFormatLite::Int32Size(
        this->_internal_discrete_actions())
    ;
    _impl_._discrete_actions_cached_byte_size_.Set(::_pbi::ToCachedSize(data_size));
    std::size_t tag_size = data_size == 0
        ? 0
        : 1 + ::_pbi::WireFormatLite::Int32Size(
                            static_cast<int32_t>(data_size))
    ;
    total_size += tag_size + data_size;
  }

  // float value = 1;
  static_assert(sizeof(::uint32_t) == sizeof(float), "Code assumes ::uint32_t and float are the same size.");
  float tmp_value = this->_internal_value();
  ::uint32_t raw_value;
  memcpy(&raw_value, &tmp_value, sizeof(tmp_value));
  if (raw_value != 0) {
    total_size += 5;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData AgentActionProto::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    AgentActionProto::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*AgentActionProto::GetClassData() const { return &_class_data_; }


void AgentActionProto::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<AgentActionProto*>(&to_msg);
  auto& from = static_cast<const AgentActionProto&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:communicator_objects.AgentActionProto)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.continuous_actions_.MergeFrom(from._impl_.continuous_actions_);
  _this->_impl_.discrete_actions_.MergeFrom(from._impl_.discrete_actions_);
  static_assert(sizeof(::uint32_t) == sizeof(float), "Code assumes ::uint32_t and float are the same size.");
  float tmp_value = from._internal_value();
  ::uint32_t raw_value;
  memcpy(&raw_value, &tmp_value, sizeof(tmp_value));
  if (raw_value != 0) {
    _this->_internal_set_value(from._internal_value());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void AgentActionProto::CopyFrom(const AgentActionProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:communicator_objects.AgentActionProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AgentActionProto::IsInitialized() const {
  return true;
}

void AgentActionProto::InternalSwap(AgentActionProto* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.continuous_actions_.InternalSwap(&other->_impl_.continuous_actions_);
  _impl_.discrete_actions_.InternalSwap(&other->_impl_.discrete_actions_);

  swap(_impl_.value_, other->_impl_.value_);
}

::PROTOBUF_NAMESPACE_ID::Metadata AgentActionProto::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto_getter, &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto_once,
      file_level_metadata_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace communicator_objects
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::communicator_objects::AgentActionProto*
Arena::CreateMaybeMessage< ::communicator_objects::AgentActionProto >(Arena* arena) {
  return Arena::CreateMessageInternal< ::communicator_objects::AgentActionProto >(arena);
}
PROTOBUF_NAMESPACE_CLOSE
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"
