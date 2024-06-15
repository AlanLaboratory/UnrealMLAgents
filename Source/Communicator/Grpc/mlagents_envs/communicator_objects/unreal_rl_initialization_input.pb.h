// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mlagents_envs/communicator_objects/unreal_rl_initialization_input.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_mlagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5finitialization_5finput_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_mlagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5finitialization_5finput_2eproto_2epb_2eh

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

#define PROTOBUF_INTERNAL_EXPORT_mlagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5finitialization_5finput_2eproto

PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_mlagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5finitialization_5finput_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable
    descriptor_table_mlagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5finitialization_5finput_2eproto;
namespace communicator_objects {
class UnrealRLInitializationInputProto;
struct UnrealRLInitializationInputProtoDefaultTypeInternal;
extern UnrealRLInitializationInputProtoDefaultTypeInternal _UnrealRLInitializationInputProto_default_instance_;
}  // namespace communicator_objects
PROTOBUF_NAMESPACE_OPEN
template <>
::communicator_objects::UnrealRLInitializationInputProto* Arena::CreateMaybeMessage<::communicator_objects::UnrealRLInitializationInputProto>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

namespace communicator_objects {

// ===================================================================


// -------------------------------------------------------------------

class UnrealRLInitializationInputProto final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:communicator_objects.UnrealRLInitializationInputProto) */ {
 public:
  inline UnrealRLInitializationInputProto() : UnrealRLInitializationInputProto(nullptr) {}
  ~UnrealRLInitializationInputProto() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR UnrealRLInitializationInputProto(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  UnrealRLInitializationInputProto(const UnrealRLInitializationInputProto& from);
  UnrealRLInitializationInputProto(UnrealRLInitializationInputProto&& from) noexcept
    : UnrealRLInitializationInputProto() {
    *this = ::std::move(from);
  }

  inline UnrealRLInitializationInputProto& operator=(const UnrealRLInitializationInputProto& from) {
    CopyFrom(from);
    return *this;
  }
  inline UnrealRLInitializationInputProto& operator=(UnrealRLInitializationInputProto&& from) noexcept {
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
  static const UnrealRLInitializationInputProto& default_instance() {
    return *internal_default_instance();
  }
  static inline const UnrealRLInitializationInputProto* internal_default_instance() {
    return reinterpret_cast<const UnrealRLInitializationInputProto*>(
               &_UnrealRLInitializationInputProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(UnrealRLInitializationInputProto& a, UnrealRLInitializationInputProto& b) {
    a.Swap(&b);
  }
  inline void Swap(UnrealRLInitializationInputProto* other) {
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
  void UnsafeArenaSwap(UnrealRLInitializationInputProto* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  UnrealRLInitializationInputProto* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<UnrealRLInitializationInputProto>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const UnrealRLInitializationInputProto& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const UnrealRLInitializationInputProto& from) {
    UnrealRLInitializationInputProto::MergeImpl(*this, from);
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
  void InternalSwap(UnrealRLInitializationInputProto* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "communicator_objects.UnrealRLInitializationInputProto";
  }
  protected:
  explicit UnrealRLInitializationInputProto(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kCommunicationVersionFieldNumber = 2,
    kPackageVersionFieldNumber = 3,
    kSeedFieldNumber = 1,
    kNumAreasFieldNumber = 4,
  };
  // string communication_version = 2;
  void clear_communication_version() ;
  const std::string& communication_version() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_communication_version(Arg_&& arg, Args_... args);
  std::string* mutable_communication_version();
  PROTOBUF_NODISCARD std::string* release_communication_version();
  void set_allocated_communication_version(std::string* ptr);

  private:
  const std::string& _internal_communication_version() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_communication_version(
      const std::string& value);
  std::string* _internal_mutable_communication_version();

  public:
  // string package_version = 3;
  void clear_package_version() ;
  const std::string& package_version() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_package_version(Arg_&& arg, Args_... args);
  std::string* mutable_package_version();
  PROTOBUF_NODISCARD std::string* release_package_version();
  void set_allocated_package_version(std::string* ptr);

  private:
  const std::string& _internal_package_version() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_package_version(
      const std::string& value);
  std::string* _internal_mutable_package_version();

  public:
  // int32 seed = 1;
  void clear_seed() ;
  ::int32_t seed() const;
  void set_seed(::int32_t value);

  private:
  ::int32_t _internal_seed() const;
  void _internal_set_seed(::int32_t value);

  public:
  // int32 num_areas = 4;
  void clear_num_areas() ;
  ::int32_t num_areas() const;
  void set_num_areas(::int32_t value);

  private:
  ::int32_t _internal_num_areas() const;
  void _internal_set_num_areas(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:communicator_objects.UnrealRLInitializationInputProto)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr communication_version_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr package_version_;
    ::int32_t seed_;
    ::int32_t num_areas_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_mlagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5finitialization_5finput_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// UnrealRLInitializationInputProto

// int32 seed = 1;
inline void UnrealRLInitializationInputProto::clear_seed() {
  _impl_.seed_ = 0;
}
inline ::int32_t UnrealRLInitializationInputProto::seed() const {
  // @@protoc_insertion_point(field_get:communicator_objects.UnrealRLInitializationInputProto.seed)
  return _internal_seed();
}
inline void UnrealRLInitializationInputProto::set_seed(::int32_t value) {
  _internal_set_seed(value);
  // @@protoc_insertion_point(field_set:communicator_objects.UnrealRLInitializationInputProto.seed)
}
inline ::int32_t UnrealRLInitializationInputProto::_internal_seed() const {
  return _impl_.seed_;
}
inline void UnrealRLInitializationInputProto::_internal_set_seed(::int32_t value) {
  ;
  _impl_.seed_ = value;
}

// string communication_version = 2;
inline void UnrealRLInitializationInputProto::clear_communication_version() {
  _impl_.communication_version_.ClearToEmpty();
}
inline const std::string& UnrealRLInitializationInputProto::communication_version() const {
  // @@protoc_insertion_point(field_get:communicator_objects.UnrealRLInitializationInputProto.communication_version)
  return _internal_communication_version();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void UnrealRLInitializationInputProto::set_communication_version(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.communication_version_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:communicator_objects.UnrealRLInitializationInputProto.communication_version)
}
inline std::string* UnrealRLInitializationInputProto::mutable_communication_version() {
  std::string* _s = _internal_mutable_communication_version();
  // @@protoc_insertion_point(field_mutable:communicator_objects.UnrealRLInitializationInputProto.communication_version)
  return _s;
}
inline const std::string& UnrealRLInitializationInputProto::_internal_communication_version() const {
  return _impl_.communication_version_.Get();
}
inline void UnrealRLInitializationInputProto::_internal_set_communication_version(const std::string& value) {
  ;


  _impl_.communication_version_.Set(value, GetArenaForAllocation());
}
inline std::string* UnrealRLInitializationInputProto::_internal_mutable_communication_version() {
  ;
  return _impl_.communication_version_.Mutable( GetArenaForAllocation());
}
inline std::string* UnrealRLInitializationInputProto::release_communication_version() {
  // @@protoc_insertion_point(field_release:communicator_objects.UnrealRLInitializationInputProto.communication_version)
  return _impl_.communication_version_.Release();
}
inline void UnrealRLInitializationInputProto::set_allocated_communication_version(std::string* value) {
  _impl_.communication_version_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.communication_version_.IsDefault()) {
          _impl_.communication_version_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:communicator_objects.UnrealRLInitializationInputProto.communication_version)
}

// string package_version = 3;
inline void UnrealRLInitializationInputProto::clear_package_version() {
  _impl_.package_version_.ClearToEmpty();
}
inline const std::string& UnrealRLInitializationInputProto::package_version() const {
  // @@protoc_insertion_point(field_get:communicator_objects.UnrealRLInitializationInputProto.package_version)
  return _internal_package_version();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void UnrealRLInitializationInputProto::set_package_version(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.package_version_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:communicator_objects.UnrealRLInitializationInputProto.package_version)
}
inline std::string* UnrealRLInitializationInputProto::mutable_package_version() {
  std::string* _s = _internal_mutable_package_version();
  // @@protoc_insertion_point(field_mutable:communicator_objects.UnrealRLInitializationInputProto.package_version)
  return _s;
}
inline const std::string& UnrealRLInitializationInputProto::_internal_package_version() const {
  return _impl_.package_version_.Get();
}
inline void UnrealRLInitializationInputProto::_internal_set_package_version(const std::string& value) {
  ;


  _impl_.package_version_.Set(value, GetArenaForAllocation());
}
inline std::string* UnrealRLInitializationInputProto::_internal_mutable_package_version() {
  ;
  return _impl_.package_version_.Mutable( GetArenaForAllocation());
}
inline std::string* UnrealRLInitializationInputProto::release_package_version() {
  // @@protoc_insertion_point(field_release:communicator_objects.UnrealRLInitializationInputProto.package_version)
  return _impl_.package_version_.Release();
}
inline void UnrealRLInitializationInputProto::set_allocated_package_version(std::string* value) {
  _impl_.package_version_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.package_version_.IsDefault()) {
          _impl_.package_version_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:communicator_objects.UnrealRLInitializationInputProto.package_version)
}

// int32 num_areas = 4;
inline void UnrealRLInitializationInputProto::clear_num_areas() {
  _impl_.num_areas_ = 0;
}
inline ::int32_t UnrealRLInitializationInputProto::num_areas() const {
  // @@protoc_insertion_point(field_get:communicator_objects.UnrealRLInitializationInputProto.num_areas)
  return _internal_num_areas();
}
inline void UnrealRLInitializationInputProto::set_num_areas(::int32_t value) {
  _internal_set_num_areas(value);
  // @@protoc_insertion_point(field_set:communicator_objects.UnrealRLInitializationInputProto.num_areas)
}
inline ::int32_t UnrealRLInitializationInputProto::_internal_num_areas() const {
  return _impl_.num_areas_;
}
inline void UnrealRLInitializationInputProto::_internal_set_num_areas(::int32_t value) {
  ;
  _impl_.num_areas_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace communicator_objects


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_mlagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5finitialization_5finput_2eproto_2epb_2eh
