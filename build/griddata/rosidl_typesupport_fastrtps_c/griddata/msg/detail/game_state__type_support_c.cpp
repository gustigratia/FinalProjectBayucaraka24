// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from griddata:msg/GameState.idl
// generated code does not contain a copyright notice
#include "griddata/msg/detail/game_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "griddata/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "griddata/msg/detail/game_state__struct.h"
#include "griddata/msg/detail/game_state__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _GameState__ros_msg_type = griddata__msg__GameState;

static bool _GameState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GameState__ros_msg_type * ros_message = static_cast<const _GameState__ros_msg_type *>(untyped_ros_message);
  // Field name: cell
  {
    size_t size = 9;
    auto array_ptr = ros_message->cell;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: gameturn
  {
    cdr << ros_message->gameturn;
  }

  // Field name: over
  {
    cdr << (ros_message->over ? true : false);
  }

  return true;
}

static bool _GameState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GameState__ros_msg_type * ros_message = static_cast<_GameState__ros_msg_type *>(untyped_ros_message);
  // Field name: cell
  {
    size_t size = 9;
    auto array_ptr = ros_message->cell;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: gameturn
  {
    cdr >> ros_message->gameturn;
  }

  // Field name: over
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->over = tmp ? true : false;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_griddata
size_t get_serialized_size_griddata__msg__GameState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GameState__ros_msg_type * ros_message = static_cast<const _GameState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name cell
  {
    size_t array_size = 9;
    auto array_ptr = ros_message->cell;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gameturn
  {
    size_t item_size = sizeof(ros_message->gameturn);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name over
  {
    size_t item_size = sizeof(ros_message->over);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GameState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_griddata__msg__GameState(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_griddata
size_t max_serialized_size_griddata__msg__GameState(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: cell
  {
    size_t array_size = 9;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: gameturn
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: over
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _GameState__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_griddata__msg__GameState(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_GameState = {
  "griddata::msg",
  "GameState",
  _GameState__cdr_serialize,
  _GameState__cdr_deserialize,
  _GameState__get_serialized_size,
  _GameState__max_serialized_size
};

static rosidl_message_type_support_t _GameState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GameState,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, griddata, msg, GameState)() {
  return &_GameState__type_support;
}

#if defined(__cplusplus)
}
#endif
