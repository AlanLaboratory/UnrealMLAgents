// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mlagents_envs/communicator_objects/command.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_mlagents_5fenvs_2fcommunicator_5fobjects_2fcommand_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_mlagents_5fenvs_2fcommunicator_5fobjects_2fcommand_2eproto_2epb_2eh

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
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/generated_enum_reflection.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_mlagents_5fenvs_2fcommunicator_5fobjects_2fcommand_2eproto

PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_mlagents_5fenvs_2fcommunicator_5fobjects_2fcommand_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable
    descriptor_table_mlagents_5fenvs_2fcommunicator_5fobjects_2fcommand_2eproto;
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

namespace communicator_objects {
enum CommandProto : int {
  STEP = 0,
  RESET = 1,
  QUIT = 2,
  CommandProto_INT_MIN_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::min(),
  CommandProto_INT_MAX_SENTINEL_DO_NOT_USE_ =
      std::numeric_limits<::int32_t>::max(),
};

bool CommandProto_IsValid(int value);
constexpr CommandProto CommandProto_MIN = static_cast<CommandProto>(0);
constexpr CommandProto CommandProto_MAX = static_cast<CommandProto>(2);
constexpr int CommandProto_ARRAYSIZE = 2 + 1;
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
CommandProto_descriptor();
template <typename T>
const std::string& CommandProto_Name(T value) {
  static_assert(std::is_same<T, CommandProto>::value ||
                    std::is_integral<T>::value,
                "Incorrect type passed to CommandProto_Name().");
  return CommandProto_Name(static_cast<CommandProto>(value));
}
template <>
inline const std::string& CommandProto_Name(CommandProto value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfDenseEnum<CommandProto_descriptor,
                                                 0, 2>(
      static_cast<int>(value));
}
inline bool CommandProto_Parse(absl::string_view name, CommandProto* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<CommandProto>(
      CommandProto_descriptor(), name, value);
}

// ===================================================================



// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace communicator_objects


PROTOBUF_NAMESPACE_OPEN

template <>
struct is_proto_enum<::communicator_objects::CommandProto> : std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor<::communicator_objects::CommandProto>() {
  return ::communicator_objects::CommandProto_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_mlagents_5fenvs_2fcommunicator_5fobjects_2fcommand_2eproto_2epb_2eh
