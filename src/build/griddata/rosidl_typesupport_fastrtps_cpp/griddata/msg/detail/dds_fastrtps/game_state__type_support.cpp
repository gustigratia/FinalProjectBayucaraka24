// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from griddata:msg/GameState.idl
// generated code does not contain a copyright notice
#include "griddata/msg/detail/game_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "griddata/msg/detail/game_state__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace griddata
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_griddata
cdr_serialize(
  const griddata::msg::GameState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: cell
  {
    cdr << ros_message.cell;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_griddata
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  griddata::msg::GameState & ros_message)
{
  // Member: cell
  {
    cdr >> ros_message.cell;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_griddata
get_serialized_size(
  const griddata::msg::GameState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: cell
  {
    size_t array_size = 9;
    size_t item_size = sizeof(ros_message.cell[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_griddata
max_serialized_size_GameState(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: cell
  {
    size_t array_size = 9;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _GameState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const griddata::msg::GameState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GameState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<griddata::msg::GameState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GameState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const griddata::msg::GameState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GameState__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_GameState(full_bounded, 0);
}

static message_type_support_callbacks_t _GameState__callbacks = {
  "griddata::msg",
  "GameState",
  _GameState__cdr_serialize,
  _GameState__cdr_deserialize,
  _GameState__get_serialized_size,
  _GameState__max_serialized_size
};

static rosidl_message_type_support_t _GameState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GameState__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace griddata

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_griddata
const rosidl_message_type_support_t *
get_message_type_support_handle<griddata::msg::GameState>()
{
  return &griddata::msg::typesupport_fastrtps_cpp::_GameState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, griddata, msg, GameState)() {
  return &griddata::msg::typesupport_fastrtps_cpp::_GameState__handle;
}

#ifdef __cplusplus
}
#endif
