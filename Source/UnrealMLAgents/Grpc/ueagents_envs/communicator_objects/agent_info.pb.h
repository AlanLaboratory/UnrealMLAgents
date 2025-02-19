// Copyright © 2025 Stephane Capponi and individual contributors. All Rights Reserved.

// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ueagents_envs/communicator_objects/agent_info.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5finfo_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5finfo_2eproto_2epb_2eh

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
#include "ueagents_envs/communicator_objects/observation.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5finfo_2eproto

PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5finfo_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable
    descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5finfo_2eproto;
namespace communicator_objects {
class AgentInfoProto;
struct AgentInfoProtoDefaultTypeInternal;
extern AgentInfoProtoDefaultTypeInternal _AgentInfoProto_default_instance_;
}  // namespace communicator_objects
PROTOBUF_NAMESPACE_OPEN
template <>
::communicator_objects::AgentInfoProto* Arena::CreateMaybeMessage<::communicator_objects::AgentInfoProto>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

namespace communicator_objects {

// ===================================================================


// -------------------------------------------------------------------

class AgentInfoProto final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:communicator_objects.AgentInfoProto) */ {
 public:
  inline AgentInfoProto() : AgentInfoProto(nullptr) {}
  ~AgentInfoProto() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR AgentInfoProto(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  AgentInfoProto(const AgentInfoProto& from);
  AgentInfoProto(AgentInfoProto&& from) noexcept
    : AgentInfoProto() {
    *this = ::std::move(from);
  }

  inline AgentInfoProto& operator=(const AgentInfoProto& from) {
    CopyFrom(from);
    return *this;
  }
  inline AgentInfoProto& operator=(AgentInfoProto&& from) noexcept {
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
  static const AgentInfoProto& default_instance() {
    return *internal_default_instance();
  }
  static inline const AgentInfoProto* internal_default_instance() {
    return reinterpret_cast<const AgentInfoProto*>(
               &_AgentInfoProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(AgentInfoProto& a, AgentInfoProto& b) {
    a.Swap(&b);
  }
  inline void Swap(AgentInfoProto* other) {
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
  void UnsafeArenaSwap(AgentInfoProto* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  AgentInfoProto* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<AgentInfoProto>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const AgentInfoProto& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const AgentInfoProto& from) {
    AgentInfoProto::MergeImpl(*this, from);
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
  void InternalSwap(AgentInfoProto* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "communicator_objects.AgentInfoProto";
  }
  protected:
  explicit AgentInfoProto(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kActionMaskFieldNumber = 5,
    kObservationsFieldNumber = 6,
    kRewardFieldNumber = 1,
    kDoneFieldNumber = 2,
    kMaxStepReachedFieldNumber = 3,
    kIdFieldNumber = 4,
    kGroupIdFieldNumber = 7,
    kGroupRewardFieldNumber = 8,
  };
  // repeated bool action_mask = 5;
  int action_mask_size() const;
  private:
  int _internal_action_mask_size() const;

  public:
  void clear_action_mask() ;
  bool action_mask(int index) const;
  void set_action_mask(int index, bool value);
  void add_action_mask(bool value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField<bool>& action_mask() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField<bool>* mutable_action_mask();

  private:
  bool _internal_action_mask(int index) const;
  void _internal_add_action_mask(bool value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField<bool>& _internal_action_mask() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField<bool>* _internal_mutable_action_mask();

  public:
  // repeated .communicator_objects.ObservationProto observations = 6;
  int observations_size() const;
  private:
  int _internal_observations_size() const;

  public:
  void clear_observations() ;
  ::communicator_objects::ObservationProto* mutable_observations(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::communicator_objects::ObservationProto >*
      mutable_observations();
  private:
  const ::communicator_objects::ObservationProto& _internal_observations(int index) const;
  ::communicator_objects::ObservationProto* _internal_add_observations();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<::communicator_objects::ObservationProto>& _internal_observations() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<::communicator_objects::ObservationProto>* _internal_mutable_observations();
  public:
  const ::communicator_objects::ObservationProto& observations(int index) const;
  ::communicator_objects::ObservationProto* add_observations();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::communicator_objects::ObservationProto >&
      observations() const;
  // float reward = 1;
  void clear_reward() ;
  float reward() const;
  void set_reward(float value);

  private:
  float _internal_reward() const;
  void _internal_set_reward(float value);

  public:
  // bool done = 2;
  void clear_done() ;
  bool done() const;
  void set_done(bool value);

  private:
  bool _internal_done() const;
  void _internal_set_done(bool value);

  public:
  // bool max_step_reached = 3;
  void clear_max_step_reached() ;
  bool max_step_reached() const;
  void set_max_step_reached(bool value);

  private:
  bool _internal_max_step_reached() const;
  void _internal_set_max_step_reached(bool value);

  public:
  // int32 id = 4;
  void clear_id() ;
  ::int32_t id() const;
  void set_id(::int32_t value);

  private:
  ::int32_t _internal_id() const;
  void _internal_set_id(::int32_t value);

  public:
  // int32 group_id = 7;
  void clear_group_id() ;
  ::int32_t group_id() const;
  void set_group_id(::int32_t value);

  private:
  ::int32_t _internal_group_id() const;
  void _internal_set_group_id(::int32_t value);

  public:
  // float group_reward = 8;
  void clear_group_reward() ;
  float group_reward() const;
  void set_group_reward(float value);

  private:
  float _internal_group_reward() const;
  void _internal_set_group_reward(float value);

  public:
  // @@protoc_insertion_point(class_scope:communicator_objects.AgentInfoProto)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedField<bool> action_mask_;
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::communicator_objects::ObservationProto > observations_;
    float reward_;
    bool done_;
    bool max_step_reached_;
    ::int32_t id_;
    ::int32_t group_id_;
    float group_reward_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5finfo_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// AgentInfoProto

// float reward = 1;
inline void AgentInfoProto::clear_reward() {
  _impl_.reward_ = 0;
}
inline float AgentInfoProto::reward() const {
  // @@protoc_insertion_point(field_get:communicator_objects.AgentInfoProto.reward)
  return _internal_reward();
}
inline void AgentInfoProto::set_reward(float value) {
  _internal_set_reward(value);
  // @@protoc_insertion_point(field_set:communicator_objects.AgentInfoProto.reward)
}
inline float AgentInfoProto::_internal_reward() const {
  return _impl_.reward_;
}
inline void AgentInfoProto::_internal_set_reward(float value) {
  ;
  _impl_.reward_ = value;
}

// bool done = 2;
inline void AgentInfoProto::clear_done() {
  _impl_.done_ = false;
}
inline bool AgentInfoProto::done() const {
  // @@protoc_insertion_point(field_get:communicator_objects.AgentInfoProto.done)
  return _internal_done();
}
inline void AgentInfoProto::set_done(bool value) {
  _internal_set_done(value);
  // @@protoc_insertion_point(field_set:communicator_objects.AgentInfoProto.done)
}
inline bool AgentInfoProto::_internal_done() const {
  return _impl_.done_;
}
inline void AgentInfoProto::_internal_set_done(bool value) {
  ;
  _impl_.done_ = value;
}

// bool max_step_reached = 3;
inline void AgentInfoProto::clear_max_step_reached() {
  _impl_.max_step_reached_ = false;
}
inline bool AgentInfoProto::max_step_reached() const {
  // @@protoc_insertion_point(field_get:communicator_objects.AgentInfoProto.max_step_reached)
  return _internal_max_step_reached();
}
inline void AgentInfoProto::set_max_step_reached(bool value) {
  _internal_set_max_step_reached(value);
  // @@protoc_insertion_point(field_set:communicator_objects.AgentInfoProto.max_step_reached)
}
inline bool AgentInfoProto::_internal_max_step_reached() const {
  return _impl_.max_step_reached_;
}
inline void AgentInfoProto::_internal_set_max_step_reached(bool value) {
  ;
  _impl_.max_step_reached_ = value;
}

// int32 id = 4;
inline void AgentInfoProto::clear_id() {
  _impl_.id_ = 0;
}
inline ::int32_t AgentInfoProto::id() const {
  // @@protoc_insertion_point(field_get:communicator_objects.AgentInfoProto.id)
  return _internal_id();
}
inline void AgentInfoProto::set_id(::int32_t value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:communicator_objects.AgentInfoProto.id)
}
inline ::int32_t AgentInfoProto::_internal_id() const {
  return _impl_.id_;
}
inline void AgentInfoProto::_internal_set_id(::int32_t value) {
  ;
  _impl_.id_ = value;
}

// repeated bool action_mask = 5;
inline int AgentInfoProto::_internal_action_mask_size() const {
  return _impl_.action_mask_.size();
}
inline int AgentInfoProto::action_mask_size() const {
  return _internal_action_mask_size();
}
inline void AgentInfoProto::clear_action_mask() {
  _internal_mutable_action_mask()->Clear();
}
inline bool AgentInfoProto::action_mask(int index) const {
  // @@protoc_insertion_point(field_get:communicator_objects.AgentInfoProto.action_mask)
  return _internal_action_mask(index);
}
inline void AgentInfoProto::set_action_mask(int index, bool value) {
  _internal_mutable_action_mask()->Set(index, value);
  // @@protoc_insertion_point(field_set:communicator_objects.AgentInfoProto.action_mask)
}
inline void AgentInfoProto::add_action_mask(bool value) {
  _internal_add_action_mask(value);
  // @@protoc_insertion_point(field_add:communicator_objects.AgentInfoProto.action_mask)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField<bool>& AgentInfoProto::action_mask() const {
  // @@protoc_insertion_point(field_list:communicator_objects.AgentInfoProto.action_mask)
  return _internal_action_mask();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField<bool>* AgentInfoProto::mutable_action_mask() {
  // @@protoc_insertion_point(field_mutable_list:communicator_objects.AgentInfoProto.action_mask)
  return _internal_mutable_action_mask();
}

inline bool AgentInfoProto::_internal_action_mask(int index) const {
  return _internal_action_mask().Get(index);
}
inline void AgentInfoProto::_internal_add_action_mask(bool value) {
  _internal_mutable_action_mask()->Add(value);
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField<bool>& AgentInfoProto::_internal_action_mask() const {
  return _impl_.action_mask_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField<bool>* AgentInfoProto::_internal_mutable_action_mask() {
  return &_impl_.action_mask_;
}

// repeated .communicator_objects.ObservationProto observations = 6;
inline int AgentInfoProto::_internal_observations_size() const {
  return _impl_.observations_.size();
}
inline int AgentInfoProto::observations_size() const {
  return _internal_observations_size();
}
inline ::communicator_objects::ObservationProto* AgentInfoProto::mutable_observations(int index) {
  // @@protoc_insertion_point(field_mutable:communicator_objects.AgentInfoProto.observations)
  return _internal_mutable_observations()->Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::communicator_objects::ObservationProto >*
AgentInfoProto::mutable_observations() {
  // @@protoc_insertion_point(field_mutable_list:communicator_objects.AgentInfoProto.observations)
  return _internal_mutable_observations();
}
inline const ::communicator_objects::ObservationProto& AgentInfoProto::_internal_observations(int index) const {
  return _internal_observations().Get(index);
}
inline const ::communicator_objects::ObservationProto& AgentInfoProto::observations(int index) const {
  // @@protoc_insertion_point(field_get:communicator_objects.AgentInfoProto.observations)
  return _internal_observations(index);
}
inline ::communicator_objects::ObservationProto* AgentInfoProto::_internal_add_observations() {
  return _internal_mutable_observations()->Add();
}
inline ::communicator_objects::ObservationProto* AgentInfoProto::add_observations() {
  ::communicator_objects::ObservationProto* _add = _internal_add_observations();
  // @@protoc_insertion_point(field_add:communicator_objects.AgentInfoProto.observations)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::communicator_objects::ObservationProto >&
AgentInfoProto::observations() const {
  // @@protoc_insertion_point(field_list:communicator_objects.AgentInfoProto.observations)
  return _internal_observations();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<::communicator_objects::ObservationProto>&
AgentInfoProto::_internal_observations() const {
  return _impl_.observations_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<::communicator_objects::ObservationProto>*
AgentInfoProto::_internal_mutable_observations() {
  return &_impl_.observations_;
}

// int32 group_id = 7;
inline void AgentInfoProto::clear_group_id() {
  _impl_.group_id_ = 0;
}
inline ::int32_t AgentInfoProto::group_id() const {
  // @@protoc_insertion_point(field_get:communicator_objects.AgentInfoProto.group_id)
  return _internal_group_id();
}
inline void AgentInfoProto::set_group_id(::int32_t value) {
  _internal_set_group_id(value);
  // @@protoc_insertion_point(field_set:communicator_objects.AgentInfoProto.group_id)
}
inline ::int32_t AgentInfoProto::_internal_group_id() const {
  return _impl_.group_id_;
}
inline void AgentInfoProto::_internal_set_group_id(::int32_t value) {
  ;
  _impl_.group_id_ = value;
}

// float group_reward = 8;
inline void AgentInfoProto::clear_group_reward() {
  _impl_.group_reward_ = 0;
}
inline float AgentInfoProto::group_reward() const {
  // @@protoc_insertion_point(field_get:communicator_objects.AgentInfoProto.group_reward)
  return _internal_group_reward();
}
inline void AgentInfoProto::set_group_reward(float value) {
  _internal_set_group_reward(value);
  // @@protoc_insertion_point(field_set:communicator_objects.AgentInfoProto.group_reward)
}
inline float AgentInfoProto::_internal_group_reward() const {
  return _impl_.group_reward_;
}
inline void AgentInfoProto::_internal_set_group_reward(float value) {
  ;
  _impl_.group_reward_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace communicator_objects


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_ueagents_5fenvs_2fcommunicator_5fobjects_2fagent_5finfo_2eproto_2epb_2eh
