// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from griddata:msg/GameState.idl
// generated code does not contain a copyright notice

#ifndef GRIDDATA__MSG__DETAIL__GAME_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define GRIDDATA__MSG__DETAIL__GAME_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "griddata/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "griddata/msg/detail/game_state__struct.hpp"

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

#include "fastcdr/Cdr.h"

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
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_griddata
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  griddata::msg::GameState & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_griddata
get_serialized_size(
  const griddata::msg::GameState & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_griddata
max_serialized_size_GameState(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace griddata

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_griddata
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, griddata, msg, GameState)();

#ifdef __cplusplus
}
#endif

#endif  // GRIDDATA__MSG__DETAIL__GAME_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
