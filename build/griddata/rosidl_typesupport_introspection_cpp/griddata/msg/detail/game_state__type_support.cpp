// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from griddata:msg/GameState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "griddata/msg/detail/game_state__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace griddata
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void GameState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) griddata::msg::GameState(_init);
}

void GameState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<griddata::msg::GameState *>(message_memory);
  typed_message->~GameState();
}

size_t size_function__GameState__cell(const void * untyped_member)
{
  (void)untyped_member;
  return 9;
}

const void * get_const_function__GameState__cell(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<int8_t, 9> *>(untyped_member);
  return &member[index];
}

void * get_function__GameState__cell(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<int8_t, 9> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GameState_message_member_array[3] = {
  {
    "cell",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    9,  // array size
    false,  // is upper bound
    offsetof(griddata::msg::GameState, cell),  // bytes offset in struct
    nullptr,  // default value
    size_function__GameState__cell,  // size() function pointer
    get_const_function__GameState__cell,  // get_const(index) function pointer
    get_function__GameState__cell,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "gameturn",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(griddata::msg::GameState, gameturn),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "over",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(griddata::msg::GameState, over),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GameState_message_members = {
  "griddata::msg",  // message namespace
  "GameState",  // message name
  3,  // number of fields
  sizeof(griddata::msg::GameState),
  GameState_message_member_array,  // message members
  GameState_init_function,  // function to initialize message memory (memory has to be allocated)
  GameState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GameState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GameState_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace griddata


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<griddata::msg::GameState>()
{
  return &::griddata::msg::rosidl_typesupport_introspection_cpp::GameState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, griddata, msg, GameState)() {
  return &::griddata::msg::rosidl_typesupport_introspection_cpp::GameState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
