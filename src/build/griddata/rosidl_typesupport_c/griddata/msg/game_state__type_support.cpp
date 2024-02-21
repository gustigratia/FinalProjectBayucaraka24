// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from griddata:msg/GameState.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "griddata/msg/rosidl_typesupport_c__visibility_control.h"
#include "griddata/msg/detail/game_state__struct.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace griddata
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _GameState_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GameState_type_support_ids_t;

static const _GameState_type_support_ids_t _GameState_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GameState_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GameState_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GameState_type_support_symbol_names_t _GameState_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, griddata, msg, GameState)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, griddata, msg, GameState)),
  }
};

typedef struct _GameState_type_support_data_t
{
  void * data[2];
} _GameState_type_support_data_t;

static _GameState_type_support_data_t _GameState_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GameState_message_typesupport_map = {
  2,
  "griddata",
  &_GameState_message_typesupport_ids.typesupport_identifier[0],
  &_GameState_message_typesupport_symbol_names.symbol_name[0],
  &_GameState_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GameState_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GameState_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace griddata

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_griddata
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, griddata, msg, GameState)() {
  return &::griddata::msg::rosidl_typesupport_c::GameState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif