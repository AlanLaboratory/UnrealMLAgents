// Copyright © 2025 Stephane Capponi and individual contributors. All Rights Reserved.

// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ueagents_envs/communicator_objects/agent_action.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION < 4023000
#error "This file was generated by a newer version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please update"
#error "your headers."
#endif  // PROTOBUF_VERSION

#if 4023004 < PROTOBUF_MIN_PROTOC_VERSION
#error "This file was generated by an older version of protoc which is"
#error "incompatible with your Protocol Buffer headers. Please"
#error "regenerate this file with a newer version of protoc."
#endif  // PROTOBUF_MIN_PROTOC_VERSION
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto

PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable
    descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto;
namespace communicator_objects {
class AgentActionProto;
struct AgentActionProtoDefaultTypeInternal;
extern AgentActionProtoDefaultTypeInternal _AgentActionProto_default_instance_;
}  // namespace communicator_objects
PROTOBUF_NAMESPACE_OPEN
template <>
::communicator_objects::AgentActionProto* Arena::CreateMaybeMessage<::communicator_objects::AgentActionProto>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

namespace communicator_objects {

// ===================================================================


// -------------------------------------------------------------------

class AgentActionProto final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:communicator_objects.AgentActionProto) */ {
 public:
  inline AgentActionProto() : AgentActionProto(nullptr) {}
  ~AgentActionProto() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR AgentActionProto(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  AgentActionProto(const AgentActionProto& from);
  AgentActionProto(AgentActionProto&& from) noexcept
    : AgentActionProto() {
    *this = ::std::move(from);
  }

  inline AgentActionProto& operator=(const AgentActionProto& from) {
    CopyFrom(from);
    return *this;
  }
  inline AgentActionProto& operator=(AgentActionProto&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const AgentActionProto& default_instance() {
    return *internal_default_instance();
  }
  static inline const AgentActionProto* internal_default_instance() {
    return reinterpret_cast<const AgentActionProto*>(
               &_AgentActionProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(AgentActionProto& a, AgentActionProto& b) {
    a.Swap(&b);
  }
  inline void Swap(AgentActionProto* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(AgentActionProto* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  AgentActionProto* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<AgentActionProto>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const AgentActionProto& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const AgentActionProto& from) {
    AgentActionProto::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(AgentActionProto* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "communicator_objects.AgentActionProto";
  }
  protected:
  explicit AgentActionProto(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kContinuousActionsFieldNumber = 2,
    kDiscreteActionsFieldNumber = 3,
    kValueFieldNumber = 1,
  };
  // repeated float continuous_actions = 2;
  int continuous_actions_size() const;
  private:
  int _internal_continuous_actions_size() const;

  public:
  void clear_continuous_actions() ;
  float continuous_actions(int index) const;
  void set_continuous_actions(int index, float value);
  void add_continuous_actions(float value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField<float>& continuous_actions() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField<float>* mutable_continuous_actions();

  private:
  float _internal_continuous_actions(int index) const;
  void _internal_add_continuous_actions(float value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField<float>& _internal_continuous_actions() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField<float>* _internal_mutable_continuous_actions();

  public:
  // repeated int32 discrete_actions = 3;
  int discrete_actions_size() const;
  private:
  int _internal_discrete_actions_size() const;

  public:
  void clear_discrete_actions() ;
  ::int32_t discrete_actions(int index) const;
  void set_discrete_actions(int index, ::int32_t value);
  void add_discrete_actions(::int32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t>& discrete_actions() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t>* mutable_discrete_actions();

  private:
  ::int32_t _internal_discrete_actions(int index) const;
  void _internal_add_discrete_actions(::int32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t>& _internal_discrete_actions() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t>* _internal_mutable_discrete_actions();

  public:
  // float value = 1;
  void clear_value() ;
  float value() const;
  void set_value(float value);

  private:
  float _internal_value() const;
  void _internal_set_value(float value);

  public:
  // @@protoc_insertion_point(class_scope:communicator_objects.AgentActionProto)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedField<float> continuous_actions_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t> discrete_actions_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _discrete_actions_cached_byte_size_;
    float value_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// AgentActionProto

// float value = 1;
inline void AgentActionProto::clear_value() {
  _impl_.value_ = 0;
}
inline float AgentActionProto::value() const {
  // @@protoc_insertion_point(field_get:communicator_objects.AgentActionProto.value)
  return _internal_value();
}
inline void AgentActionProto::set_value(float value) {
  _internal_set_value(value);
  // @@protoc_insertion_point(field_set:communicator_objects.AgentActionProto.value)
}
inline float AgentActionProto::_internal_value() const {
  return _impl_.value_;
}
inline void AgentActionProto::_internal_set_value(float value) {
  ;
  _impl_.value_ = value;
}

// repeated float continuous_actions = 2;
inline int AgentActionProto::_internal_continuous_actions_size() const {
  return _impl_.continuous_actions_.size();
}
inline int AgentActionProto::continuous_actions_size() const {
  return _internal_continuous_actions_size();
}
inline void AgentActionProto::clear_continuous_actions() {
  _internal_mutable_continuous_actions()->Clear();
}
inline float AgentActionProto::continuous_actions(int index) const {
  // @@protoc_insertion_point(field_get:communicator_objects.AgentActionProto.continuous_actions)
  return _internal_continuous_actions(index);
}
inline void AgentActionProto::set_continuous_actions(int index, float value) {
  _internal_mutable_continuous_actions()->Set(index, value);
  // @@protoc_insertion_point(field_set:communicator_objects.AgentActionProto.continuous_actions)
}
inline void AgentActionProto::add_continuous_actions(float value) {
  _internal_add_continuous_actions(value);
  // @@protoc_insertion_point(field_add:communicator_objects.AgentActionProto.continuous_actions)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField<float>& AgentActionProto::continuous_actions() const {
  // @@protoc_insertion_point(field_list:communicator_objects.AgentActionProto.continuous_actions)
  return _internal_continuous_actions();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField<float>* AgentActionProto::mutable_continuous_actions() {
  // @@protoc_insertion_point(field_mutable_list:communicator_objects.AgentActionProto.continuous_actions)
  return _internal_mutable_continuous_actions();
}

inline float AgentActionProto::_internal_continuous_actions(int index) const {
  return _internal_continuous_actions().Get(index);
}
inline void AgentActionProto::_internal_add_continuous_actions(float value) {
  _internal_mutable_continuous_actions()->Add(value);
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField<float>& AgentActionProto::_internal_continuous_actions() const {
  return _impl_.continuous_actions_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField<float>* AgentActionProto::_internal_mutable_continuous_actions() {
  return &_impl_.continuous_actions_;
}

// repeated int32 discrete_actions = 3;
inline int AgentActionProto::_internal_discrete_actions_size() const {
  return _impl_.discrete_actions_.size();
}
inline int AgentActionProto::discrete_actions_size() const {
  return _internal_discrete_actions_size();
}
inline void AgentActionProto::clear_discrete_actions() {
  _internal_mutable_discrete_actions()->Clear();
}
inline ::int32_t AgentActionProto::discrete_actions(int index) const {
  // @@protoc_insertion_point(field_get:communicator_objects.AgentActionProto.discrete_actions)
  return _internal_discrete_actions(index);
}
inline void AgentActionProto::set_discrete_actions(int index, ::int32_t value) {
  _internal_mutable_discrete_actions()->Set(index, value);
  // @@protoc_insertion_point(field_set:communicator_objects.AgentActionProto.discrete_actions)
}
inline void AgentActionProto::add_discrete_actions(::int32_t value) {
  _internal_add_discrete_actions(value);
  // @@protoc_insertion_point(field_add:communicator_objects.AgentActionProto.discrete_actions)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t>& AgentActionProto::discrete_actions() const {
  // @@protoc_insertion_point(field_list:communicator_objects.AgentActionProto.discrete_actions)
  return _internal_discrete_actions();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t>* AgentActionProto::mutable_discrete_actions() {
  // @@protoc_insertion_point(field_mutable_list:communicator_objects.AgentActionProto.discrete_actions)
  return _internal_mutable_discrete_actions();
}

inline ::int32_t AgentActionProto::_internal_discrete_actions(int index) const {
  return _internal_discrete_actions().Get(index);
}
inline void AgentActionProto::_internal_add_discrete_actions(::int32_t value) {
  _internal_mutable_discrete_actions()->Add(value);
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t>& AgentActionProto::_internal_discrete_actions() const {
  return _impl_.discrete_actions_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t>* AgentActionProto::_internal_mutable_discrete_actions() {
  return &_impl_.discrete_actions_;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace communicator_objects


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5faction_2eproto_2epb_2eh
