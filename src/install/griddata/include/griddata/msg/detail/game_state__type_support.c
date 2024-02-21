// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from griddata:msg/GameState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "griddata/msg/detail/game_state__rosidl_typesupport_introspection_c.h"
#include "griddata/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "griddata/msg/detail/game_state__functions.h"
#include "griddata/msg/detail/game_state__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void GameState__rosidl_typesupport_introspection_c__GameState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  griddata__msg__GameState__init(message_memory);
}

void GameState__rosidl_typesupport_introspection_c__GameState_fini_function(void * message_memory)
{
  griddata__msg__GameState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember GameState__rosidl_typesupport_introspection_c__GameState_message_member_array[1] = {
  {
    "cell",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    9,  // array size
    false,  // is upper bound
    offsetof(griddata__msg__GameState, cell),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GameState__rosidl_typesupport_introspection_c__GameState_message_members = {
  "griddata__msg",  // message namespace
  "GameState",  // message name
  1,  // number of fields
  sizeof(griddata__msg__GameState),
  GameState__rosidl_typesupport_introspection_c__GameState_message_member_array,  // message members
  GameState__rosidl_typesupport_introspection_c__GameState_init_function,  // function to initialize message memory (memory has to be allocated)
  GameState__rosidl_typesupport_introspection_c__GameState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GameState__rosidl_typesupport_introspection_c__GameState_message_type_support_handle = {
  0,
  &GameState__rosidl_typesupport_introspection_c__GameState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_griddata
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, griddata, msg, GameState)() {
  if (!GameState__rosidl_typesupport_introspection_c__GameState_message_type_support_handle.typesupport_identifier) {
    GameState__rosidl_typesupport_introspection_c__GameState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GameState__rosidl_typesupport_introspection_c__GameState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
