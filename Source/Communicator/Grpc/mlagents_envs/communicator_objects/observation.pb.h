// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mlagents_envs/communicator_objects/observation.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_mlagents_5fenvs_2fcommunicator_5fobjects_2fobservation_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_mlagents_5fenvs_2fcommunicator_5fobjects_2fobservation_2eproto_2epb_2eh

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
#include "google/protobuf/generated_enum_reflection.h"
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_mlagents_5fenvs_2fcommunicator_5fobjects_2fobservation_2eproto

PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_mlagents_5fenvs_2fcommunicator_5fobjects_2fobservation_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable
    descriptor_table_mlagents_5fenvs_2fcommunicator_5fobjects_2fobservation_2eproto;
namespace communicator_objects {
class ObservationProto;
struct ObservationProtoDefaultTypeInternal;
extern ObservationProtoDefaultTypeInternal _ObservationProto_default_instance_;
class ObservationProto_FloatData;
struct ObservationProto_FloatDataDefaultTypeInternal;
extern ObservationProto_FloatDataDefaultTypeInternal _ObservationProto_FloatData_default_instance_;
}  // namespace communicator_objects
PROTOBUF_NAMESPACE_OPEN
template <>
::communicator_objects::ObservationProto* Arena::CreateMaybeMessage<::communicator_objects::ObservationProto>(Arena*);
template <>
::communicator_objects::ObservationProto_FloatData* Arena::CreateMaybeMessage<::communicator_objects::ObservationProto_FloatData>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

namespace communicator_objects {
enum ObservationTypeProto : int {
  DEFAULT = 0,
  GOAL_SIGNAL = 1,
  ObservationTypeProto_INT_MIN_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::min(),
  ObservationTypeProto_INT_MAX_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::max(),
};

bool ObservationTypeProto_IsValid(int value);
constexpr ObservationTypeProto ObservationTypeProto_MIN = static_cast<ObservationTypeProto>(0);
constexpr ObservationTypeProto ObservationTypeProto_MAX = static_cast<ObservationTypeProto>(1);
constexpr int ObservationTypeProto_ARRAYSIZE = 1 + 1;
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
ObservationTypeProto_descriptor();
template <typename T>
const std::string& ObservationTypeProto_Name(T value) {
  static_assert(std::is_same<T, ObservationTypeProto>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to ObservationTypeProto_Name().");
  return ObservationTypeProto_Name(static_cast<ObservationTypeProto>(value));
}
template <>
inline const std::string& ObservationTypeProto_Name(ObservationTypeProto value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfDenseEnum<ObservationTypeProto_descriptor,
                                                 0, 1>(
      static_cast<int>(value));
}
inline bool ObservationTypeProto_Parse(absl::string_view name, ObservationTypeProto* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ObservationTypeProto>(
      ObservationTypeProto_descriptor(), name, value);
}

// ===================================================================


// -------------------------------------------------------------------

class ObservationProto_FloatData final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:communicator_objects.ObservationProto.FloatData) */ {
 public:
  inline ObservationProto_FloatData() : ObservationProto_FloatData(nullptr) {}
  ~ObservationProto_FloatData() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR ObservationProto_FloatData(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ObservationProto_FloatData(const ObservationProto_FloatData& from);
  ObservationProto_FloatData(ObservationProto_FloatData&& from) noexcept
    : ObservationProto_FloatData() {
    *this = ::std::move(from);
  }

  inline ObservationProto_FloatData& operator=(const ObservationProto_FloatData& from) {
    CopyFrom(from);
    return *this;
  }
  inline ObservationProto_FloatData& operator=(ObservationProto_FloatData&& from) noexcept {
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
  static const ObservationProto_FloatData& default_instance() {
    return *internal_default_instance();
  }
  static inline const ObservationProto_FloatData* internal_default_instance() {
    return reinterpret_cast<const ObservationProto_FloatData*>(
               &_ObservationProto_FloatData_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ObservationProto_FloatData& a, ObservationProto_FloatData& b) {
    a.Swap(&b);
  }
  inline void Swap(ObservationProto_FloatData* other) {
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
  void UnsafeArenaSwap(ObservationProto_FloatData* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ObservationProto_FloatData* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ObservationProto_FloatData>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ObservationProto_FloatData& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const ObservationProto_FloatData& from) {
    ObservationProto_FloatData::MergeImpl(*this, from);
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
  void InternalSwap(ObservationProto_FloatData* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "communicator_objects.ObservationProto.FloatData";
  }
  protected:
  explicit ObservationProto_FloatData(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDataFieldNumber = 1,
  };
  // repeated float data = 1;
  int data_size() const;
  private:
  int _internal_data_size() const;

  public:
  void clear_data() ;
  float data(int index) const;
  void set_data(int index, float value);
  void add_data(float value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField<float>& data() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField<float>* mutable_data();

  private:
  float _internal_data(int index) const;
  void _internal_add_data(float value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField<float>& _internal_data() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField<float>* _internal_mutable_data();

  public:
  // @@protoc_insertion_point(class_scope:communicator_objects.ObservationProto.FloatData)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedField<float> data_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_mlagents_5fenvs_2fcommunicator_5fobjects_2fobservation_2eproto;
};// -------------------------------------------------------------------

class ObservationProto final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:communicator_objects.ObservationProto) */ {
 public:
  inline ObservationProto() : ObservationProto(nullptr) {}
  ~ObservationProto() override;
  template<typename = void>
  explicit PROTOBUF_CONSTEXPR ObservationProto(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ObservationProto(const ObservationProto& from);
  ObservationProto(ObservationProto&& from) noexcept
    : ObservationProto() {
    *this = ::std::move(from);
  }

  inline ObservationProto& operator=(const ObservationProto& from) {
    CopyFrom(from);
    return *this;
  }
  inline ObservationProto& operator=(ObservationProto&& from) noexcept {
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
  static const ObservationProto& default_instance() {
    return *internal_default_instance();
  }
  enum ObservationDataCase {
    kFloatData = 2,
    OBSERVATION_DATA_NOT_SET = 0,
  };

  static inline const ObservationProto* internal_default_instance() {
    return reinterpret_cast<const ObservationProto*>(
               &_ObservationProto_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(ObservationProto& a, ObservationProto& b) {
    a.Swap(&b);
  }
  inline void Swap(ObservationProto* other) {
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
  void UnsafeArenaSwap(ObservationProto* other) {
    if (other == this) return;
    ABSL_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ObservationProto* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ObservationProto>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ObservationProto& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const ObservationProto& from) {
    ObservationProto::MergeImpl(*this, from);
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
  void InternalSwap(ObservationProto* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() {
    return "communicator_objects.ObservationProto";
  }
  protected:
  explicit ObservationProto(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef ObservationProto_FloatData FloatData;

  // accessors -------------------------------------------------------

  enum : int {
    kShapeFieldNumber = 1,
    kFloatDataFieldNumber = 2,
  };
  // repeated int32 shape = 1;
  int shape_size() const;
  private:
  int _internal_shape_size() const;

  public:
  void clear_shape() ;
  ::int32_t shape(int index) const;
  void set_shape(int index, ::int32_t value);
  void add_shape(::int32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t>& shape() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t>* mutable_shape();

  private:
  ::int32_t _internal_shape(int index) const;
  void _internal_add_shape(::int32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t>& _internal_shape() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t>* _internal_mutable_shape();

  public:
  // .communicator_objects.ObservationProto.FloatData float_data = 2;
  bool has_float_data() const;
  private:
  bool _internal_has_float_data() const;

  public:
  void clear_float_data() ;
  const ::communicator_objects::ObservationProto_FloatData& float_data() const;
  PROTOBUF_NODISCARD ::communicator_objects::ObservationProto_FloatData* release_float_data();
  ::communicator_objects::ObservationProto_FloatData* mutable_float_data();
  void set_allocated_float_data(::communicator_objects::ObservationProto_FloatData* float_data);
  private:
  const ::communicator_objects::ObservationProto_FloatData& _internal_float_data() const;
  ::communicator_objects::ObservationProto_FloatData* _internal_mutable_float_data();
  public:
  void unsafe_arena_set_allocated_float_data(
      ::communicator_objects::ObservationProto_FloatData* float_data);
  ::communicator_objects::ObservationProto_FloatData* unsafe_arena_release_float_data();
  void clear_observation_data();
  ObservationDataCase observation_data_case() const;
  // @@protoc_insertion_point(class_scope:communicator_objects.ObservationProto)
 private:
  class _Internal;
  void set_has_float_data();

  inline bool has_observation_data() const;
  inline void clear_has_observation_data();

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t> shape_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _shape_cached_byte_size_;
    union ObservationDataUnion {
      constexpr ObservationDataUnion() : _constinit_{} {}
        ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized _constinit_;
      ::communicator_objects::ObservationProto_FloatData* float_data_;
    } observation_data_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::uint32_t _oneof_case_[1];

  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_mlagents_5fenvs_2fcommunicator_5fobjects_2fobservation_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// ObservationProto_FloatData

// repeated float data = 1;
inline int ObservationProto_FloatData::_internal_data_size() const {
  return _impl_.data_.size();
}
inline int ObservationProto_FloatData::data_size() const {
  return _internal_data_size();
}
inline void ObservationProto_FloatData::clear_data() {
  _internal_mutable_data()->Clear();
}
inline float ObservationProto_FloatData::data(int index) const {
  // @@protoc_insertion_point(field_get:communicator_objects.ObservationProto.FloatData.data)
  return _internal_data(index);
}
inline void ObservationProto_FloatData::set_data(int index, float value) {
  _internal_mutable_data()->Set(index, value);
  // @@protoc_insertion_point(field_set:communicator_objects.ObservationProto.FloatData.data)
}
inline void ObservationProto_FloatData::add_data(float value) {
  _internal_add_data(value);
  // @@protoc_insertion_point(field_add:communicator_objects.ObservationProto.FloatData.data)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField<float>& ObservationProto_FloatData::data() const {
  // @@protoc_insertion_point(field_list:communicator_objects.ObservationProto.FloatData.data)
  return _internal_data();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField<float>* ObservationProto_FloatData::mutable_data() {
  // @@protoc_insertion_point(field_mutable_list:communicator_objects.ObservationProto.FloatData.data)
  return _internal_mutable_data();
}

inline float ObservationProto_FloatData::_internal_data(int index) const {
  return _internal_data().Get(index);
}
inline void ObservationProto_FloatData::_internal_add_data(float value) {
  _internal_mutable_data()->Add(value);
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField<float>& ObservationProto_FloatData::_internal_data() const {
  return _impl_.data_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField<float>* ObservationProto_FloatData::_internal_mutable_data() {
  return &_impl_.data_;
}

// -------------------------------------------------------------------

// ObservationProto

// repeated int32 shape = 1;
inline int ObservationProto::_internal_shape_size() const {
  return _impl_.shape_.size();
}
inline int ObservationProto::shape_size() const {
  return _internal_shape_size();
}
inline void ObservationProto::clear_shape() {
  _internal_mutable_shape()->Clear();
}
inline ::int32_t ObservationProto::shape(int index) const {
  // @@protoc_insertion_point(field_get:communicator_objects.ObservationProto.shape)
  return _internal_shape(index);
}
inline void ObservationProto::set_shape(int index, ::int32_t value) {
  _internal_mutable_shape()->Set(index, value);
  // @@protoc_insertion_point(field_set:communicator_objects.ObservationProto.shape)
}
inline void ObservationProto::add_shape(::int32_t value) {
  _internal_add_shape(value);
  // @@protoc_insertion_point(field_add:communicator_objects.ObservationProto.shape)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t>& ObservationProto::shape() const {
  // @@protoc_insertion_point(field_list:communicator_objects.ObservationProto.shape)
  return _internal_shape();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t>* ObservationProto::mutable_shape() {
  // @@protoc_insertion_point(field_mutable_list:communicator_objects.ObservationProto.shape)
  return _internal_mutable_shape();
}

inline ::int32_t ObservationProto::_internal_shape(int index) const {
  return _internal_shape().Get(index);
}
inline void ObservationProto::_internal_add_shape(::int32_t value) {
  _internal_mutable_shape()->Add(value);
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t>& ObservationProto::_internal_shape() const {
  return _impl_.shape_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField<::int32_t>* ObservationProto::_internal_mutable_shape() {
  return &_impl_.shape_;
}

// .communicator_objects.ObservationProto.FloatData float_data = 2;
inline bool ObservationProto::has_float_data() const {
  return observation_data_case() == kFloatData;
}
inline bool ObservationProto::_internal_has_float_data() const {
  return observation_data_case() == kFloatData;
}
inline void ObservationProto::set_has_float_data() {
  _impl_._oneof_case_[0] = kFloatData;
}
inline void ObservationProto::clear_float_data() {
  if (observation_data_case() == kFloatData) {
    if (GetArenaForAllocation() == nullptr) {
      delete _impl_.observation_data_.float_data_;
    }
    clear_has_observation_data();
  }
}
inline ::communicator_objects::ObservationProto_FloatData* ObservationProto::release_float_data() {
  // @@protoc_insertion_point(field_release:communicator_objects.ObservationProto.float_data)
  if (observation_data_case() == kFloatData) {
    clear_has_observation_data();
    ::communicator_objects::ObservationProto_FloatData* temp = _impl_.observation_data_.float_data_;
    if (GetArenaForAllocation() != nullptr) {
      temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
    }
    _impl_.observation_data_.float_data_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::communicator_objects::ObservationProto_FloatData& ObservationProto::_internal_float_data() const {
  return observation_data_case() == kFloatData
      ? *_impl_.observation_data_.float_data_
      : reinterpret_cast<::communicator_objects::ObservationProto_FloatData&>(::communicator_objects::_ObservationProto_FloatData_default_instance_);
}
inline const ::communicator_objects::ObservationProto_FloatData& ObservationProto::float_data() const {
  // @@protoc_insertion_point(field_get:communicator_objects.ObservationProto.float_data)
  return _internal_float_data();
}
inline ::communicator_objects::ObservationProto_FloatData* ObservationProto::unsafe_arena_release_float_data() {
  // @@protoc_insertion_point(field_unsafe_arena_release:communicator_objects.ObservationProto.float_data)
  if (observation_data_case() == kFloatData) {
    clear_has_observation_data();
    ::communicator_objects::ObservationProto_FloatData* temp = _impl_.observation_data_.float_data_;
    _impl_.observation_data_.float_data_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline void ObservationProto::unsafe_arena_set_allocated_float_data(::communicator_objects::ObservationProto_FloatData* float_data) {
  clear_observation_data();
  if (float_data) {
    set_has_float_data();
    _impl_.observation_data_.float_data_ = float_data;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:communicator_objects.ObservationProto.float_data)
}
inline ::communicator_objects::ObservationProto_FloatData* ObservationProto::_internal_mutable_float_data() {
  if (observation_data_case() != kFloatData) {
    clear_observation_data();
    set_has_float_data();
    _impl_.observation_data_.float_data_ = CreateMaybeMessage< ::communicator_objects::ObservationProto_FloatData >(GetArenaForAllocation());
  }
  return _impl_.observation_data_.float_data_;
}
inline ::communicator_objects::ObservationProto_FloatData* ObservationProto::mutable_float_data() {
  ::communicator_objects::ObservationProto_FloatData* _msg = _internal_mutable_float_data();
  // @@protoc_insertion_point(field_mutable:communicator_objects.ObservationProto.float_data)
  return _msg;
}

inline bool ObservationProto::has_observation_data() const {
  return observation_data_case() != OBSERVATION_DATA_NOT_SET;
}
inline void ObservationProto::clear_has_observation_data() {
  _impl_._oneof_case_[0] = OBSERVATION_DATA_NOT_SET;
}
inline ObservationProto::ObservationDataCase ObservationProto::observation_data_case() const {
  return ObservationProto::ObservationDataCase(_impl_._oneof_case_[0]);
}
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace communicator_objects


PROTOBUF_NAMESPACE_OPEN

template <>
struct is_proto_enum<::communicator_objects::ObservationTypeProto> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::communicator_objects::ObservationTypeProto>() {
  return ::communicator_objects::ObservationTypeProto_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_mlagents_5fenvs_2fcommunicator_5fobjects_2fobservation_2eproto_2epb_2eh
