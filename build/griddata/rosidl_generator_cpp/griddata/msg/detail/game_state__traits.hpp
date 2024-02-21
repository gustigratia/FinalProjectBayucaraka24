// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from griddata:msg/GameState.idl
// generated code does not contain a copyright notice

#ifndef GRIDDATA__MSG__DETAIL__GAME_STATE__TRAITS_HPP_
#define GRIDDATA__MSG__DETAIL__GAME_STATE__TRAITS_HPP_

#include "griddata/msg/detail/game_state__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<griddata::msg::GameState>()
{
  return "griddata::msg::GameState";
}

template<>
inline const char * name<griddata::msg::GameState>()
{
  return "griddata/msg/GameState";
}

template<>
struct has_fixed_size<griddata::msg::GameState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<griddata::msg::GameState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<griddata::msg::GameState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GRIDDATA__MSG__DETAIL__GAME_STATE__TRAITS_HPP_
