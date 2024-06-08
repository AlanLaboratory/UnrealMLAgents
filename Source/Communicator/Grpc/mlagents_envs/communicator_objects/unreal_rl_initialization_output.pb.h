// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mlagents_envs/communicator_objects/unreal_rl_initialization_output.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_mlagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5finitialization_5foutput_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_mlagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5finitialization_5foutput_2eproto_2epb_2eh

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
#include "mlagents_envs/communicator_objects/brain_parameters.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_mlagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5finitialization_5foutput_2eproto

PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_mlagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5finitialization_5foutput_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable
    descriptor_table_mlagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5finitialization_5foutput_2eproto;
namespace communicator_objects {
class UnrealRLInitializationOutputProto;
struct UnrealRLInitializationOutputProtoDefaultTypeInternal;
extern UnrealRLInitializationOutputProtoDefaultTypeInternal _UnrealRLInitializationOutputProto_default_instance_;
}  // namespace communicator_objects
PROTOBUF_NAMESPACE_OPEN
template <>
::communicator_objects::UnrealRLInitializationOutputProto* Arena::CreateMaybeMessage<::communicator_objects::UnrealRLInitializationOutputProto>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

namespace communicator_objects {

// ===================================================================


// -------------------------------------------------------------------

class UnrealRLInitializationOutputProto final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:communicator_objects.UnrealRLInitializationOutputProto) */ {
 public:
  inline UnrealRLInitializationOutputProto() : UnrealRLInitializationOutputProto(nullptr) {}
  ~UnrealRLInitializationOutputProto() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR UnrealRLInitializationOutputProto(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  UnrealRLInitializationOutputProto(const UnrealRLInitializationOutputProto& from);
  UnrealRLInitializationOutputProto(UnrealRLInitializationOutputProto&& from) noexcept
    : UnrealRLInitializationOutputProto() {
    *this = ::std::move(from);
  }

  inline UnrealRLInitializationOutputProto& operator=(const UnrealRLInitializationOutputProto& from) {
    CopyFrom(from);
    return *this;
  }
  inline UnrealRLInitializationOutputProto& operator=(UnrealRLInitializationOutputProto&& from) noexcept {
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
  static const UnrealRLInitializationOutputProto& default_instance() {
    return *internal_default_instance();
  }
  static inline const UnrealRLInitializationOutputProto* internal_default_instance() {
    return reinterpret_cast<const UnrealRLInitializationOutputProto*>(
               &_UnrealRLInitializationOutputProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(UnrealRLInitializationOutputProto& a, UnrealRLInitializationOutputProto& b) {
    a.Swap(&b);
  }
  inline void Swap(UnrealRLInitializationOutputProto* other) {
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
  void UnsafeArenaSwap(UnrealRLInitializationOutputProto* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  UnrealRLInitializationOutputProto* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<UnrealRLInitializationOutputProto>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const UnrealRLInitializationOutputProto& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const UnrealRLInitializationOutputProto& from) {
    UnrealRLInitializationOutputProto::MergeImpl(*this, from);
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
  void InternalSwap(UnrealRLInitializationOutputProto* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "communicator_objects.UnrealRLInitializationOutputProto";
  }
  protected:
  explicit UnrealRLInitializationOutputProto(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kBrainParametersFieldNumber = 3,
    kNameFieldNumber = 1,
    kLogPathFieldNumber = 2,
  };
  // repeated .communicator_objects.BrainParametersProto brain_parameters = 3;
  int brain_parameters_size() const;
  private:
  int _internal_brain_parameters_size() const;

  public:
  void clear_brain_parameters() ;
  ::communicator_objects::BrainParametersProto* mutable_brain_parameters(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::communicator_objects::BrainParametersProto >*
      mutable_brain_parameters();
  private:
  const ::communicator_objects::BrainParametersProto& _internal_brain_parameters(int index) const;
  ::communicator_objects::BrainParametersProto* _internal_add_brain_parameters();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<::communicator_objects::BrainParametersProto>& _internal_brain_parameters() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<::communicator_objects::BrainParametersProto>* _internal_mutable_brain_parameters();
  public:
  const ::communicator_objects::BrainParametersProto& brain_parameters(int index) const;
  ::communicator_objects::BrainParametersProto* add_brain_parameters();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::communicator_objects::BrainParametersProto >&
      brain_parameters() const;
  // string name = 1;
  void clear_name() ;
  const std::string& name() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_name(Arg_&& arg, Args_... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* ptr);

  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(
      const std::string& value);
  std::string* _internal_mutable_name();

  public:
  // string log_path = 2;
  void clear_log_path() ;
  const std::string& log_path() const;




  template <typename Arg_ = const std::string&, typename... Args_>
  void set_log_path(Arg_&& arg, Args_... args);
  std::string* mutable_log_path();
  PROTOBUF_NODISCARD std::string* release_log_path();
  void set_allocated_log_path(std::string* ptr);

  private:
  const std::string& _internal_log_path() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_log_path(
      const std::string& value);
  std::string* _internal_mutable_log_path();

  public:
  // @@protoc_insertion_point(class_scope:communicator_objects.UnrealRLInitializationOutputProto)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::communicator_objects::BrainParametersProto > brain_parameters_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr log_path_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_mlagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5finitialization_5foutput_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// UnrealRLInitializationOutputProto

// string name = 1;
inline void UnrealRLInitializationOutputProto::clear_name() {
  _impl_.name_.ClearToEmpty();
}
inline const std::string& UnrealRLInitializationOutputProto::name() const {
  // @@protoc_insertion_point(field_get:communicator_objects.UnrealRLInitializationOutputProto.name)
  return _internal_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void UnrealRLInitializationOutputProto::set_name(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.name_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:communicator_objects.UnrealRLInitializationOutputProto.name)
}
inline std::string* UnrealRLInitializationOutputProto::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:communicator_objects.UnrealRLInitializationOutputProto.name)
  return _s;
}
inline const std::string& UnrealRLInitializationOutputProto::_internal_name() const {
  return _impl_.name_.Get();
}
inline void UnrealRLInitializationOutputProto::_internal_set_name(const std::string& value) {
  ;


  _impl_.name_.Set(value, GetArenaForAllocation());
}
inline std::string* UnrealRLInitializationOutputProto::_internal_mutable_name() {
  ;
  return _impl_.name_.Mutable( GetArenaForAllocation());
}
inline std::string* UnrealRLInitializationOutputProto::release_name() {
  // @@protoc_insertion_point(field_release:communicator_objects.UnrealRLInitializationOutputProto.name)
  return _impl_.name_.Release();
}
inline void UnrealRLInitializationOutputProto::set_allocated_name(std::string* value) {
  _impl_.name_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.name_.IsDefault()) {
          _impl_.name_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:communicator_objects.UnrealRLInitializationOutputProto.name)
}

// string log_path = 2;
inline void UnrealRLInitializationOutputProto::clear_log_path() {
  _impl_.log_path_.ClearToEmpty();
}
inline const std::string& UnrealRLInitializationOutputProto::log_path() const {
  // @@protoc_insertion_point(field_get:communicator_objects.UnrealRLInitializationOutputProto.log_path)
  return _internal_log_path();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void UnrealRLInitializationOutputProto::set_log_path(Arg_&& arg,
                                                     Args_... args) {
  ;
  _impl_.log_path_.Set(static_cast<Arg_&&>(arg), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:communicator_objects.UnrealRLInitializationOutputProto.log_path)
}
inline std::string* UnrealRLInitializationOutputProto::mutable_log_path() {
  std::string* _s = _internal_mutable_log_path();
  // @@protoc_insertion_point(field_mutable:communicator_objects.UnrealRLInitializationOutputProto.log_path)
  return _s;
}
inline const std::string& UnrealRLInitializationOutputProto::_internal_log_path() const {
  return _impl_.log_path_.Get();
}
inline void UnrealRLInitializationOutputProto::_internal_set_log_path(const std::string& value) {
  ;


  _impl_.log_path_.Set(value, GetArenaForAllocation());
}
inline std::string* UnrealRLInitializationOutputProto::_internal_mutable_log_path() {
  ;
  return _impl_.log_path_.Mutable( GetArenaForAllocation());
}
inline std::string* UnrealRLInitializationOutputProto::release_log_path() {
  // @@protoc_insertion_point(field_release:communicator_objects.UnrealRLInitializationOutputProto.log_path)
  return _impl_.log_path_.Release();
}
inline void UnrealRLInitializationOutputProto::set_allocated_log_path(std::string* value) {
  _impl_.log_path_.SetAllocated(value, GetArenaForAllocation());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.log_path_.IsDefault()) {
          _impl_.log_path_.Set("", GetArenaForAllocation());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:communicator_objects.UnrealRLInitializationOutputProto.log_path)
}

// repeated .communicator_objects.BrainParametersProto brain_parameters = 3;
inline int UnrealRLInitializationOutputProto::_internal_brain_parameters_size() const {
  return _impl_.brain_parameters_.size();
}
inline int UnrealRLInitializationOutputProto::brain_parameters_size() const {
  return _internal_brain_parameters_size();
}
inline ::communicator_objects::BrainParametersProto* UnrealRLInitializationOutputProto::mutable_brain_parameters(int index) {
  // @@protoc_insertion_point(field_mutable:communicator_objects.UnrealRLInitializationOutputProto.brain_parameters)
  return _internal_mutable_brain_parameters()->Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::communicator_objects::BrainParametersProto >*
UnrealRLInitializationOutputProto::mutable_brain_parameters() {
  // @@protoc_insertion_point(field_mutable_list:communicator_objects.UnrealRLInitializationOutputProto.brain_parameters)
  return _internal_mutable_brain_parameters();
}
inline const ::communicator_objects::BrainParametersProto& UnrealRLInitializationOutputProto::_internal_brain_parameters(int index) const {
  return _internal_brain_parameters().Get(index);
}
inline const ::communicator_objects::BrainParametersProto& UnrealRLInitializationOutputProto::brain_parameters(int index) const {
  // @@protoc_insertion_point(field_get:communicator_objects.UnrealRLInitializationOutputProto.brain_parameters)
  return _internal_brain_parameters(index);
}
inline ::communicator_objects::BrainParametersProto* UnrealRLInitializationOutputProto::_internal_add_brain_parameters() {
  return _internal_mutable_brain_parameters()->Add();
}
inline ::communicator_objects::BrainParametersProto* UnrealRLInitializationOutputProto::add_brain_parameters() {
  ::communicator_objects::BrainParametersProto* _add = _internal_add_brain_parameters();
  // @@protoc_insertion_point(field_add:communicator_objects.UnrealRLInitializationOutputProto.brain_parameters)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::communicator_objects::BrainParametersProto >&
UnrealRLInitializationOutputProto::brain_parameters() const {
  // @@protoc_insertion_point(field_list:communicator_objects.UnrealRLInitializationOutputProto.brain_parameters)
  return _internal_brain_parameters();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<::communicator_objects::BrainParametersProto>&
UnrealRLInitializationOutputProto::_internal_brain_parameters() const {
  return _impl_.brain_parameters_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<::communicator_objects::BrainParametersProto>*
UnrealRLInitializationOutputProto::_internal_mutable_brain_parameters() {
  return &_impl_.brain_parameters_;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace communicator_objects


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_mlagents_5fenvs_2fcommunicator_5fobjects_2funreal_5frl_5finitialization_5foutput_2eproto_2epb_2eh
