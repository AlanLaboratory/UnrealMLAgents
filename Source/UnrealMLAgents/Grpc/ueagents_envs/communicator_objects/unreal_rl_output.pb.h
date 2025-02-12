// Copyright © 2025 Stephane Capponi and individual contributors. All Rights Reserved.

// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ueagents_envs/communicator_objects/unreal_rl_output.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto_2epb_2eh

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
#include "google/protobuf/map.h"  // IWYU pragma: export
#include "google/protobuf/map_entry.h"
#include "google/protobuf/map_field_inl.h"
#include "google/protobuf/unknown_field_set.h"
#include "ueagents_envs/communicator_objects/agent_info.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto

PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable
    descriptor_table_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto;
namespace communicator_objects {
class UnrealRLOutputProto;
struct UnrealRLOutputProtoDefaultTypeInternal;
extern UnrealRLOutputProtoDefaultTypeInternal _UnrealRLOutputProto_default_instance_;
class UnrealRLOutputProto_AgentInfosEntry_DoNotUse;
struct UnrealRLOutputProto_AgentInfosEntry_DoNotUseDefaultTypeInternal;
extern UnrealRLOutputProto_AgentInfosEntry_DoNotUseDefaultTypeInternal _UnrealRLOutputProto_AgentInfosEntry_DoNotUse_default_instance_;
class UnrealRLOutputProto_ListAgentInfoProto;
struct UnrealRLOutputProto_ListAgentInfoProtoDefaultTypeInternal;
extern UnrealRLOutputProto_ListAgentInfoProtoDefaultTypeInternal _UnrealRLOutputProto_ListAgentInfoProto_default_instance_;
}  // namespace communicator_objects
PROTOBUF_NAMESPACE_OPEN
template <>
::communicator_objects::UnrealRLOutputProto* Arena::CreateMaybeMessage<::communicator_objects::UnrealRLOutputProto>(Arena*);
template <>
::communicator_objects::UnrealRLOutputProto_AgentInfosEntry_DoNotUse* Arena::CreateMaybeMessage<::communicator_objects::UnrealRLOutputProto_AgentInfosEntry_DoNotUse>(Arena*);
template <>
::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto* Arena::CreateMaybeMessage<::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

namespace communicator_objects {

// ===================================================================


// -------------------------------------------------------------------

class UnrealRLOutputProto_ListAgentInfoProto final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:communicator_objects.UnrealRLOutputProto.ListAgentInfoProto) */ {
 public:
  inline UnrealRLOutputProto_ListAgentInfoProto() : UnrealRLOutputProto_ListAgentInfoProto(nullptr) {}
  ~UnrealRLOutputProto_ListAgentInfoProto() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR UnrealRLOutputProto_ListAgentInfoProto(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  UnrealRLOutputProto_ListAgentInfoProto(const UnrealRLOutputProto_ListAgentInfoProto& from);
  UnrealRLOutputProto_ListAgentInfoProto(UnrealRLOutputProto_ListAgentInfoProto&& from) noexcept
    : UnrealRLOutputProto_ListAgentInfoProto() {
    *this = ::std::move(from);
  }

  inline UnrealRLOutputProto_ListAgentInfoProto& operator=(const UnrealRLOutputProto_ListAgentInfoProto& from) {
    CopyFrom(from);
    return *this;
  }
  inline UnrealRLOutputProto_ListAgentInfoProto& operator=(UnrealRLOutputProto_ListAgentInfoProto&& from) noexcept {
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
  static const UnrealRLOutputProto_ListAgentInfoProto& default_instance() {
    return *internal_default_instance();
  }
  static inline const UnrealRLOutputProto_ListAgentInfoProto* internal_default_instance() {
    return reinterpret_cast<const UnrealRLOutputProto_ListAgentInfoProto*>(
               &_UnrealRLOutputProto_ListAgentInfoProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(UnrealRLOutputProto_ListAgentInfoProto& a, UnrealRLOutputProto_ListAgentInfoProto& b) {
    a.Swap(&b);
  }
  inline void Swap(UnrealRLOutputProto_ListAgentInfoProto* other) {
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
  void UnsafeArenaSwap(UnrealRLOutputProto_ListAgentInfoProto* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  UnrealRLOutputProto_ListAgentInfoProto* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<UnrealRLOutputProto_ListAgentInfoProto>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const UnrealRLOutputProto_ListAgentInfoProto& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const UnrealRLOutputProto_ListAgentInfoProto& from) {
    UnrealRLOutputProto_ListAgentInfoProto::MergeImpl(*this, from);
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
  void InternalSwap(UnrealRLOutputProto_ListAgentInfoProto* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "communicator_objects.UnrealRLOutputProto.ListAgentInfoProto";
  }
  protected:
  explicit UnrealRLOutputProto_ListAgentInfoProto(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kValueFieldNumber = 1,
  };
  // repeated .communicator_objects.AgentInfoProto value = 1;
  int value_size() const;
  private:
  int _internal_value_size() const;

  public:
  void clear_value() ;
  ::communicator_objects::AgentInfoProto* mutable_value(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::communicator_objects::AgentInfoProto >*
      mutable_value();
  private:
  const ::communicator_objects::AgentInfoProto& _internal_value(int index) const;
  ::communicator_objects::AgentInfoProto* _internal_add_value();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<::communicator_objects::AgentInfoProto>& _internal_value() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<::communicator_objects::AgentInfoProto>* _internal_mutable_value();
  public:
  const ::communicator_objects::AgentInfoProto& value(int index) const;
  ::communicator_objects::AgentInfoProto* add_value();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::communicator_objects::AgentInfoProto >&
      value() const;
  // @@protoc_insertion_point(class_scope:communicator_objects.UnrealRLOutputProto.ListAgentInfoProto)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::communicator_objects::AgentInfoProto > value_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto;
};// -------------------------------------------------------------------

class UnrealRLOutputProto_AgentInfosEntry_DoNotUse final : public ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<UnrealRLOutputProto_AgentInfosEntry_DoNotUse,
    std::string, ::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE> {
public:
  typedef ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<UnrealRLOutputProto_AgentInfosEntry_DoNotUse,
    std::string, ::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE> SuperType;
  UnrealRLOutputProto_AgentInfosEntry_DoNotUse();
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR UnrealRLOutputProto_AgentInfosEntry_DoNotUse(
      ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);
  explicit UnrealRLOutputProto_AgentInfosEntry_DoNotUse(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void MergeFrom(const UnrealRLOutputProto_AgentInfosEntry_DoNotUse& other);
  static const UnrealRLOutputProto_AgentInfosEntry_DoNotUse* internal_default_instance() { return reinterpret_cast<const UnrealRLOutputProto_AgentInfosEntry_DoNotUse*>(&_UnrealRLOutputProto_AgentInfosEntry_DoNotUse_default_instance_); }
  static bool ValidateKey(std::string* s) {
    return ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(s->data(), static_cast<int>(s->size()), ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::PARSE, "communicator_objects.UnrealRLOutputProto.AgentInfosEntry.key");
 }
  static bool ValidateValue(void*) { return true; }
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  friend struct ::TableStruct_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto;
};
// -------------------------------------------------------------------

class UnrealRLOutputProto final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:communicator_objects.UnrealRLOutputProto) */ {
 public:
  inline UnrealRLOutputProto() : UnrealRLOutputProto(nullptr) {}
  ~UnrealRLOutputProto() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR UnrealRLOutputProto(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  UnrealRLOutputProto(const UnrealRLOutputProto& from);
  UnrealRLOutputProto(UnrealRLOutputProto&& from) noexcept
    : UnrealRLOutputProto() {
    *this = ::std::move(from);
  }

  inline UnrealRLOutputProto& operator=(const UnrealRLOutputProto& from) {
    CopyFrom(from);
    return *this;
  }
  inline UnrealRLOutputProto& operator=(UnrealRLOutputProto&& from) noexcept {
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
  static const UnrealRLOutputProto& default_instance() {
    return *internal_default_instance();
  }
  static inline const UnrealRLOutputProto* internal_default_instance() {
    return reinterpret_cast<const UnrealRLOutputProto*>(
               &_UnrealRLOutputProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(UnrealRLOutputProto& a, UnrealRLOutputProto& b) {
    a.Swap(&b);
  }
  inline void Swap(UnrealRLOutputProto* other) {
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
  void UnsafeArenaSwap(UnrealRLOutputProto* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  UnrealRLOutputProto* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<UnrealRLOutputProto>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const UnrealRLOutputProto& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const UnrealRLOutputProto& from) {
    UnrealRLOutputProto::MergeImpl(*this, from);
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
  void InternalSwap(UnrealRLOutputProto* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "communicator_objects.UnrealRLOutputProto";
  }
  protected:
  explicit UnrealRLOutputProto(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef UnrealRLOutputProto_ListAgentInfoProto ListAgentInfoProto;

  // accessors -------------------------------------------------------

  enum : int {
    kAgentInfosFieldNumber = 1,
    kSideChannelFieldNumber = 2,
  };
  // map<string, .communicator_objects.UnrealRLOutputProto.ListAgentInfoProto> agentInfos = 1;
  int agentinfos_size() const;
  private:
  int _internal_agentinfos_size() const;

  public:
  void clear_agentinfos() ;
  private:
  const ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto >&
      _internal_agentinfos() const;
  ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto >*
      _internal_mutable_agentinfos();
  public:
  const ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto >&
      agentinfos() const;
  ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto >*
      mutable_agentinfos();
  // bytes side_channel = 2;
  void clear_side_channel() ;
  const std::string& side_channel() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_side_channel(Arg_&& arg, Args_... args);
  std::string* mutable_side_channel();
  PROTOBUF_NODISCARD std::string* release_side_channel();
  void set_allocated_side_channel(std::string* ptr);

  private:
  const std::string& _internal_side_channel() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_side_channel(
      const std::string& value);
  std::string* _internal_mutable_side_channel();

  public:
  // @@protoc_insertion_point(class_scope:communicator_objects.UnrealRLOutputProto)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::MapField<
        UnrealRLOutputProto_AgentInfosEntry_DoNotUse,
        std::string, ::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto,
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE> agentinfos_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr side_channel_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// UnrealRLOutputProto_ListAgentInfoProto

// repeated .communicator_objects.AgentInfoProto value = 1;
inline int UnrealRLOutputProto_ListAgentInfoProto::_internal_value_size() const {
  return _impl_.value_.size();
}
inline int UnrealRLOutputProto_ListAgentInfoProto::value_size() const {
  return _internal_value_size();
}
inline ::communicator_objects::AgentInfoProto* UnrealRLOutputProto_ListAgentInfoProto::mutable_value(int index) {
  // @@protoc_insertion_point(field_mutable:communicator_objects.UnrealRLOutputProto.ListAgentInfoProto.value)
  return _internal_mutable_value()->Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::communicator_objects::AgentInfoProto >*
UnrealRLOutputProto_ListAgentInfoProto::mutable_value() {
  // @@protoc_insertion_point(field_mutable_list:communicator_objects.UnrealRLOutputProto.ListAgentInfoProto.value)
  return _internal_mutable_value();
}
inline const ::communicator_objects::AgentInfoProto& UnrealRLOutputProto_ListAgentInfoProto::_internal_value(int index) const {
  return _internal_value().Get(index);
}
inline const ::communicator_objects::AgentInfoProto& UnrealRLOutputProto_ListAgentInfoProto::value(int index) const {
  // @@protoc_insertion_point(field_get:communicator_objects.UnrealRLOutputProto.ListAgentInfoProto.value)
  return _internal_value(index);
}
inline ::communicator_objects::AgentInfoProto* UnrealRLOutputProto_ListAgentInfoProto::_internal_add_value() {
  return _internal_mutable_value()->Add();
}
inline ::communicator_objects::AgentInfoProto* UnrealRLOutputProto_ListAgentInfoProto::add_value() {
  ::communicator_objects::AgentInfoProto* _add = _internal_add_value();
  // @@protoc_insertion_point(field_add:communicator_objects.UnrealRLOutputProto.ListAgentInfoProto.value)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::communicator_objects::AgentInfoProto >&
UnrealRLOutputProto_ListAgentInfoProto::value() const {
  // @@protoc_insertion_point(field_list:communicator_objects.UnrealRLOutputProto.ListAgentInfoProto.value)
  return _internal_value();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<::communicator_objects::AgentInfoProto>&
UnrealRLOutputProto_ListAgentInfoProto::_internal_value() const {
  return _impl_.value_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<::communicator_objects::AgentInfoProto>*
UnrealRLOutputProto_ListAgentInfoProto::_internal_mutable_value() {
  return &_impl_.value_;
}

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// UnrealRLOutputProto

// map<string, .communicator_objects.UnrealRLOutputProto.ListAgentInfoProto> agentInfos = 1;
inline int UnrealRLOutputProto::_internal_agentinfos_size() const {
  return _impl_.agentinfos_.size();
}
inline int UnrealRLOutputProto::agentinfos_size() const {
  return _internal_agentinfos_size();
}
inline void UnrealRLOutputProto::clear_agentinfos() {
  _impl_.agentinfos_.Clear();
}
inline const ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto >&
UnrealRLOutputProto::_internal_agentinfos() const {
  return _impl_.agentinfos_.GetMap();
}
inline const ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto >&
UnrealRLOutputProto::agentinfos() const {
  // @@protoc_insertion_point(field_map:communicator_objects.UnrealRLOutputProto.agentInfos)
  return _internal_agentinfos();
}
inline ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto >*
UnrealRLOutputProto::_internal_mutable_agentinfos() {
  return _impl_.agentinfos_.MutableMap();
}
inline ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::communicator_objects::UnrealRLOutputProto_ListAgentInfoProto >*
UnrealRLOutputProto::mutable_agentinfos() {
  // @@protoc_insertion_point(field_mutable_map:communicator_objects.UnrealRLOutputProto.agentInfos)
  return _internal_mutable_agentinfos();
}

// bytes side_channel = 2;
inline void UnrealRLOutputProto::clear_side_channel() {
  _impl_.side_channel_.ClearToEmpty();
}
inline const std::string& UnrealRLOutputProto::side_channel() const {
  // @@protoc_insertion_point(field_get:communicator_objects.UnrealRLOutputProto.side_channel)
  return _internal_side_channel();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void UnrealRLOutputProto::set_side_channel(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.side_channel_.SetBytes(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:communicator_objects.UnrealRLOutputProto.side_channel)
}
inline std::string* UnrealRLOutputProto::mutable_side_channel() {
  std::string* _s = _internal_mutable_side_channel();
  // @@protoc_insertion_point(field_mutable:communicator_objects.UnrealRLOutputProto.side_channel)
  return _s;
}
inline const std::string& UnrealRLOutputProto::_internal_side_channel() const {
  return _impl_.side_channel_.Get();
}
inline void UnrealRLOutputProto::_internal_set_side_channel(const std::string& value) {
  ;


  _impl_.side_channel_.Set(value, GetArenaForAllocation());
}
inline std::string* UnrealRLOutputProto::_internal_mutable_side_channel() {
  ;
  return _impl_.side_channel_.Mutable( GetArenaForAllocation());
}
inline std::string* UnrealRLOutputProto::release_side_channel() {
  // @@protoc_insertion_point(field_release:communicator_objects.UnrealRLOutputProto.side_channel)
  return _impl_.side_channel_.Release();
}
inline void UnrealRLOutputProto::set_allocated_side_channel(std::string* value) {
  _impl_.side_channel_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.side_channel_.IsDefault()) {
          _impl_.side_channel_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:communicator_objects.UnrealRLOutputProto.side_channel)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace communicator_objects


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_ueagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5foutput_2eproto_2epb_2eh
