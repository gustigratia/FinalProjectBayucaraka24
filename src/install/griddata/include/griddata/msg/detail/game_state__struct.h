// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from griddata:msg/GameState.idl
// generated code does not contain a copyright notice

#ifndef GRIDDATA__MSG__DETAIL__GAME_STATE__STRUCT_H_
#define GRIDDATA__MSG__DETAIL__GAME_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/GameState in the package griddata.
typedef struct griddata__msg__GameState
{
  int8_t cell[9];
  int64_t gameturn;
  bool over;
} griddata__msg__GameState;

// Struct for a sequence of griddata__msg__GameState.
typedef struct griddata__msg__GameState__Sequence
{
  griddata__msg__GameState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} griddata__msg__GameState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRIDDATA__MSG__DETAIL__GAME_STATE__STRUCT_H_
