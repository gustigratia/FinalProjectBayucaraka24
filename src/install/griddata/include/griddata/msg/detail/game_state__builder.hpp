// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from griddata:msg/GameState.idl
// generated code does not contain a copyright notice

#ifndef GRIDDATA__MSG__DETAIL__GAME_STATE__BUILDER_HPP_
#define GRIDDATA__MSG__DETAIL__GAME_STATE__BUILDER_HPP_

#include "griddata/msg/detail/game_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace griddata
{

namespace msg
{

namespace builder
{

class Init_GameState_cell
{
public:
  Init_GameState_cell()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::griddata::msg::GameState cell(::griddata::msg::GameState::_cell_type arg)
  {
    msg_.cell = std::move(arg);
    return std::move(msg_);
  }

private:
  ::griddata::msg::GameState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::griddata::msg::GameState>()
{
  return griddata::msg::builder::Init_GameState_cell();
}

}  // namespace griddata

#endif  // GRIDDATA__MSG__DETAIL__GAME_STATE__BUILDER_HPP_
