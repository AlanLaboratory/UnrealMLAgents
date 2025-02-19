// Copyright © 2025 Stephane Capponi and individual contributors. All Rights Reserved.

#pragma warning(disable : 4100 4127 4267 4324)

// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ueagents_envs/communicator_objects/brain_parameters.proto

#include "ueagents_envs/communicator_objects/brain_parameters.pb.h"

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
PROTOBUF_CONSTEXPR ActionSpecProto::ActionSpecProto(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.discrete_branch_sizes_)*/ {}
  ,/* _impl_._discrete_branch_sizes_cached_byte_size_ = */ { 0 }

  , /*decltype(_impl_.action_descriptions_)*/{}
  , /*decltype(_impl_.num_continuous_actions_)*/ 0

  , /*decltype(_impl_.num_discrete_actions_)*/ 0

  , /*decltype(_impl_._cached_size_)*/{}} {}
struct ActionSpecProtoDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ActionSpecProtoDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ActionSpecProtoDefaultTypeInternal() {}
  union {
    ActionSpecProto _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ActionSpecProtoDefaultTypeInternal _ActionSpecProto_default_instance_;
template <typename>
PROTOBUF_CONSTEXPR BrainParametersProto::BrainParametersProto(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_._has_bits_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}
  , /*decltype(_impl_.brain_name_)*/ {
    &::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized {}
  }

  , /*decltype(_impl_.action_spec_)*/nullptr
  , /*decltype(_impl_.is_training_)*/ false
} {}
struct BrainParametersProtoDefaultTypeInternal {
  PROTOBUF_CONSTEXPR BrainParametersProtoDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~BrainParametersProtoDefaultTypeInternal() {}
  union {
    BrainParametersProto _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 BrainParametersProtoDefaultTypeInternal _BrainParametersProto_default_instance_;
}  // namespace communicator_objects
static ::_pb::Metadata file_level_metadata_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto[2];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto = nullptr;
const ::uint32_t TableStruct_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    ~0u,  // no _has_bits_
    PROTOBUF_FIELD_OFFSET(::communicator_objects::ActionSpecProto, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::communicator_objects::ActionSpecProto, _impl_.num_continuous_actions_),
    PROTOBUF_FIELD_OFFSET(::communicator_objects::ActionSpecProto, _impl_.num_discrete_actions_),
    PROTOBUF_FIELD_OFFSET(::communicator_objects::ActionSpecProto, _impl_.discrete_branch_sizes_),
    PROTOBUF_FIELD_OFFSET(::communicator_objects::ActionSpecProto, _impl_.action_descriptions_),
    PROTOBUF_FIELD_OFFSET(::communicator_objects::BrainParametersProto, _impl_._has_bits_),
    PROTOBUF_FIELD_OFFSET(::communicator_objects::BrainParametersProto, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::communicator_objects::BrainParametersProto, _impl_.brain_name_),
    PROTOBUF_FIELD_OFFSET(::communicator_objects::BrainParametersProto, _impl_.is_training_),
    PROTOBUF_FIELD_OFFSET(::communicator_objects::BrainParametersProto, _impl_.action_spec_),
    ~0u,
    ~0u,
    0,
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        { 0, -1, -1, sizeof(::communicator_objects::ActionSpecProto)},
        { 12, 23, -1, sizeof(::communicator_objects::BrainParametersProto)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::communicator_objects::_ActionSpecProto_default_instance_._instance,
    &::communicator_objects::_BrainParametersProto_default_instance_._instance,
};
const char descriptor_table_protodef_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n9ueagents_envs/communicator_objects/bra"
    "in_parameters.proto\022\024communicator_object"
    "s\"\213\001\n\017ActionSpecProto\022\036\n\026num_continuous_"
    "actions\030\001 \001(\005\022\034\n\024num_discrete_actions\030\002 "
    "\001(\005\022\035\n\025discrete_branch_sizes\030\003 \003(\005\022\033\n\023ac"
    "tion_descriptions\030\004 \003(\t\"{\n\024BrainParamete"
    "rsProto\022\022\n\nbrain_name\030\001 \001(\t\022\023\n\013is_traini"
    "ng\030\002 \001(\010\022:\n\013action_spec\030\003 \001(\0132%.communic"
    "ator_objects.ActionSpecProtob\006proto3"
};
static ::absl::once_flag descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto = {
    false,
    false,
    356,
    descriptor_table_protodef_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto,
    "ueagents_envs/communicator_objects/brain_parameters.proto",
    &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto_once,
    nullptr,
    0,
    2,
    schemas,
    file_default_instances,
    TableStruct_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto::offsets,
    file_level_metadata_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto,
    file_level_enum_descriptors_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto,
    file_level_service_descriptors_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto,
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
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto_getter() {
  return &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto(&descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto);
namespace communicator_objects {
// ===================================================================

class ActionSpecProto::_Internal {
 public:
};

ActionSpecProto::ActionSpecProto(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:communicator_objects.ActionSpecProto)
}
ActionSpecProto::ActionSpecProto(const ActionSpecProto& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  ActionSpecProto* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.discrete_branch_sizes_) { from._impl_.discrete_branch_sizes_ }
    ,/* _impl_._discrete_branch_sizes_cached_byte_size_ = */ { 0 }

    , decltype(_impl_.action_descriptions_){from._impl_.action_descriptions_}
    , decltype(_impl_.num_continuous_actions_) {}

    , decltype(_impl_.num_discrete_actions_) {}

    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&_impl_.num_continuous_actions_, &from._impl_.num_continuous_actions_,
    static_cast<::size_t>(reinterpret_cast<char*>(&_impl_.num_discrete_actions_) -
    reinterpret_cast<char*>(&_impl_.num_continuous_actions_)) + sizeof(_impl_.num_discrete_actions_));
  // @@protoc_insertion_point(copy_constructor:communicator_objects.ActionSpecProto)
}

inline void ActionSpecProto::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_.discrete_branch_sizes_) { arena }
    ,/* _impl_._discrete_branch_sizes_cached_byte_size_ = */ { 0 }

    , decltype(_impl_.action_descriptions_){arena}
    , decltype(_impl_.num_continuous_actions_) { 0 }

    , decltype(_impl_.num_discrete_actions_) { 0 }

    , /*decltype(_impl_._cached_size_)*/{}
  };
}

ActionSpecProto::~ActionSpecProto() {
  // @@protoc_insertion_point(destructor:communicator_objects.ActionSpecProto)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ActionSpecProto::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.discrete_branch_sizes_.~RepeatedField();
  _internal_mutable_action_descriptions()->~RepeatedPtrField();
}

void ActionSpecProto::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void ActionSpecProto::Clear() {
// @@protoc_insertion_point(message_clear_start:communicator_objects.ActionSpecProto)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _internal_mutable_discrete_branch_sizes()->Clear();
  _internal_mutable_action_descriptions()->Clear();
  ::memset(&_impl_.num_continuous_actions_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.num_discrete_actions_) -
      reinterpret_cast<char*>(&_impl_.num_continuous_actions_)) + sizeof(_impl_.num_discrete_actions_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ActionSpecProto::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 num_continuous_actions = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 8)) {
          _impl_.num_continuous_actions_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else {
          goto handle_unusual;
        }
        continue;
      // int32 num_discrete_actions = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 16)) {
          _impl_.num_discrete_actions_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else {
          goto handle_unusual;
        }
        continue;
      // repeated int32 discrete_branch_sizes = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 26)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedInt32Parser(_internal_mutable_discrete_branch_sizes(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<::uint8_t>(tag) == 24) {
          _internal_add_discrete_branch_sizes(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else {
          goto handle_unusual;
        }
        continue;
      // repeated string action_descriptions = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 34)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_action_descriptions();
            ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(ptr);
            CHK_(::_pbi::VerifyUTF8(str, "communicator_objects.ActionSpecProto.action_descriptions"));
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<34>(ptr));
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

::uint8_t* ActionSpecProto::_InternalSerialize(
    ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:communicator_objects.ActionSpecProto)
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 num_continuous_actions = 1;
  if (this->_internal_num_continuous_actions() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(
        1, this->_internal_num_continuous_actions(), target);
  }

  // int32 num_discrete_actions = 2;
  if (this->_internal_num_discrete_actions() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(
        2, this->_internal_num_discrete_actions(), target);
  }

  // repeated int32 discrete_branch_sizes = 3;
  {
    int byte_size = _impl_._discrete_branch_sizes_cached_byte_size_.Get();
    if (byte_size > 0) {
      target = stream->WriteInt32Packed(3, _internal_discrete_branch_sizes(),
                                                 byte_size, target);
    }
  }

  // repeated string action_descriptions = 4;
  for (int i = 0, n = this->_internal_action_descriptions_size(); i < n; ++i) {
    const auto& s = this->_internal_action_descriptions(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
        s.data(), static_cast<int>(s.length()), ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE, "communicator_objects.ActionSpecProto.action_descriptions");
    target = stream->WriteString(4, s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:communicator_objects.ActionSpecProto)
  return target;
}

::size_t ActionSpecProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:communicator_objects.ActionSpecProto)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated int32 discrete_branch_sizes = 3;
  {
    std::size_t data_size = ::_pbi::WireFormatLite::Int32Size(
        this->_internal_discrete_branch_sizes())
    ;
    _impl_._discrete_branch_sizes_cached_byte_size_.Set(::_pbi::ToCachedSize(data_size));
    std::size_t tag_size = data_size == 0
        ? 0
        : 1 + ::_pbi::WireFormatLite::Int32Size(
                            static_cast<int32_t>(data_size))
    ;
    total_size += tag_size + data_size;
  }

  // repeated string action_descriptions = 4;
  total_size += 1 * ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(_internal_action_descriptions().size());
  for (int i = 0, n = _internal_action_descriptions().size(); i < n; ++i) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        _internal_action_descriptions().Get(i));
  }

  // int32 num_continuous_actions = 1;
  if (this->_internal_num_continuous_actions() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_num_continuous_actions());
  }

  // int32 num_discrete_actions = 2;
  if (this->_internal_num_discrete_actions() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
        this->_internal_num_discrete_actions());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ActionSpecProto::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    ActionSpecProto::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ActionSpecProto::GetClassData() const { return &_class_data_; }


void ActionSpecProto::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<ActionSpecProto*>(&to_msg);
  auto& from = static_cast<const ActionSpecProto&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:communicator_objects.ActionSpecProto)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.discrete_branch_sizes_.MergeFrom(from._impl_.discrete_branch_sizes_);
  _this->_internal_mutable_action_descriptions()->MergeFrom(from._internal_action_descriptions());
  if (from._internal_num_continuous_actions() != 0) {
    _this->_internal_set_num_continuous_actions(from._internal_num_continuous_actions());
  }
  if (from._internal_num_discrete_actions() != 0) {
    _this->_internal_set_num_discrete_actions(from._internal_num_discrete_actions());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ActionSpecProto::CopyFrom(const ActionSpecProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:communicator_objects.ActionSpecProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ActionSpecProto::IsInitialized() const {
  return true;
}

void ActionSpecProto::InternalSwap(ActionSpecProto* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.discrete_branch_sizes_.InternalSwap(&other->_impl_.discrete_branch_sizes_);
  _internal_mutable_action_descriptions()->InternalSwap(
      other->_internal_mutable_action_descriptions());
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ActionSpecProto, _impl_.num_discrete_actions_)
      + sizeof(ActionSpecProto::_impl_.num_discrete_actions_)
      - PROTOBUF_FIELD_OFFSET(ActionSpecProto, _impl_.num_continuous_actions_)>(
          reinterpret_cast<char*>(&_impl_.num_continuous_actions_),
          reinterpret_cast<char*>(&other->_impl_.num_continuous_actions_));
}

::PROTOBUF_NAMESPACE_ID::Metadata ActionSpecProto::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto_getter, &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto_once,
      file_level_metadata_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto[0]);
}
// ===================================================================

class BrainParametersProto::_Internal {
 public:
  using HasBits = decltype(std::declval<BrainParametersProto>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(BrainParametersProto, _impl_._has_bits_);
  static const ::communicator_objects::ActionSpecProto& action_spec(const BrainParametersProto* msg);
  static void set_has_action_spec(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

const ::communicator_objects::ActionSpecProto&
BrainParametersProto::_Internal::action_spec(const BrainParametersProto* msg) {
  return *msg->_impl_.action_spec_;
}
BrainParametersProto::BrainParametersProto(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:communicator_objects.BrainParametersProto)
}
BrainParametersProto::BrainParametersProto(const BrainParametersProto& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  BrainParametersProto* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){from._impl_._has_bits_}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.brain_name_) {}

    , decltype(_impl_.action_spec_){nullptr}
    , decltype(_impl_.is_training_) {}
  };

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.brain_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.brain_name_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_brain_name().empty()) {
    _this->_impl_.brain_name_.Set(from._internal_brain_name(), _this->GetArenaForAllocation());
  }
  if ((from._impl_._has_bits_[0] & 0x00000001u) != 0) {
    _this->_impl_.action_spec_ = new ::communicator_objects::ActionSpecProto(*from._impl_.action_spec_);
  }
  _this->_impl_.is_training_ = from._impl_.is_training_;
  // @@protoc_insertion_point(copy_constructor:communicator_objects.BrainParametersProto)
}

inline void BrainParametersProto::SharedCtor(::_pb::Arena* arena) {
  (void)arena;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.brain_name_) {}

    , decltype(_impl_.action_spec_){nullptr}
    , decltype(_impl_.is_training_) { false }

  };
  _impl_.brain_name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        _impl_.brain_name_.Set("", GetArenaForAllocation());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

BrainParametersProto::~BrainParametersProto() {
  // @@protoc_insertion_point(destructor:communicator_objects.BrainParametersProto)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void BrainParametersProto::SharedDtor() {
  ABSL_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.brain_name_.Destroy();
  if (this != internal_default_instance()) delete _impl_.action_spec_;
}

void BrainParametersProto::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void BrainParametersProto::Clear() {
// @@protoc_insertion_point(message_clear_start:communicator_objects.BrainParametersProto)
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.brain_name_.ClearToEmpty();
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    ABSL_DCHECK(_impl_.action_spec_ != nullptr);
    _impl_.action_spec_->Clear();
  }
          #pragma warning(disable: 4800)
  _impl_.is_training_ = false;
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* BrainParametersProto::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    ::uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string brain_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_brain_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "communicator_objects.BrainParametersProto.brain_name"));
        } else {
          goto handle_unusual;
        }
        continue;
      // bool is_training = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 16)) {
          #pragma warning(disable: 4800)
          _impl_.is_training_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else {
          goto handle_unusual;
        }
        continue;
      // .communicator_objects.ActionSpecProto action_spec = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::uint8_t>(tag) == 26)) {
          ptr = ctx->ParseMessage(_internal_mutable_action_spec(), ptr);
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
  _impl_._has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

::uint8_t* BrainParametersProto::_InternalSerialize(
    ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:communicator_objects.BrainParametersProto)
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string brain_name = 1;
  if (!this->_internal_brain_name().empty()) {
    const std::string& _s = this->_internal_brain_name();
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE, "communicator_objects.BrainParametersProto.brain_name");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  // bool is_training = 2;
  if (this->_internal_is_training() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(
        2, this->_internal_is_training(), target);
  }

  cached_has_bits = _impl_._has_bits_[0];
  // .communicator_objects.ActionSpecProto action_spec = 3;
  if (cached_has_bits & 0x00000001u) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, _Internal::action_spec(this),
        _Internal::action_spec(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:communicator_objects.BrainParametersProto)
  return target;
}

::size_t BrainParametersProto::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:communicator_objects.BrainParametersProto)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string brain_name = 1;
  if (!this->_internal_brain_name().empty()) {
    total_size += 1 + ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
                                    this->_internal_brain_name());
  }

  // .communicator_objects.ActionSpecProto action_spec = 3;
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.action_spec_);
  }

  // bool is_training = 2;
  if (this->_internal_is_training() != 0) {
    total_size += 2;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData BrainParametersProto::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    BrainParametersProto::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*BrainParametersProto::GetClassData() const { return &_class_data_; }


void BrainParametersProto::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<BrainParametersProto*>(&to_msg);
  auto& from = static_cast<const BrainParametersProto&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:communicator_objects.BrainParametersProto)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_brain_name().empty()) {
    _this->_internal_set_brain_name(from._internal_brain_name());
  }
  if ((from._impl_._has_bits_[0] & 0x00000001u) != 0) {
    _this->_internal_mutable_action_spec()->::communicator_objects::ActionSpecProto::MergeFrom(
        from._internal_action_spec());
  }
  if (from._internal_is_training() != 0) {
    _this->_internal_set_is_training(from._internal_is_training());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void BrainParametersProto::CopyFrom(const BrainParametersProto& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:communicator_objects.BrainParametersProto)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BrainParametersProto::IsInitialized() const {
  return true;
}

void BrainParametersProto::InternalSwap(BrainParametersProto* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.brain_name_, lhs_arena,
                                       &other->_impl_.brain_name_, rhs_arena);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(BrainParametersProto, _impl_.is_training_)
      + sizeof(BrainParametersProto::_impl_.is_training_)
      - PROTOBUF_FIELD_OFFSET(BrainParametersProto, _impl_.action_spec_)>(
          reinterpret_cast<char*>(&_impl_.action_spec_),
          reinterpret_cast<char*>(&other->_impl_.action_spec_));
}

::PROTOBUF_NAMESPACE_ID::Metadata BrainParametersProto::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto_getter, &descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto_once,
      file_level_metadata_ueagents_5fenvs_2fcommunicator_5fobjects_2fbrain_5fparameters_2eproto[1]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace communicator_objects
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::communicator_objects::ActionSpecProto*
Arena::CreateMaybeMessage< ::communicator_objects::ActionSpecProto >(Arena* arena) {
  return Arena::CreateMessageInternal< ::communicator_objects::ActionSpecProto >(arena);
}
template<> PROTOBUF_NOINLINE ::communicator_objects::BrainParametersProto*
Arena::CreateMaybeMessage< ::communicator_objects::BrainParametersProto >(Arena* arena) {
  return Arena::CreateMessageInternal< ::communicator_objects::BrainParametersProto >(arena);
}
PROTOBUF_NAMESPACE_CLOSE
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"
