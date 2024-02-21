// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from griddata:msg/GameState.idl
// generated code does not contain a copyright notice

#ifndef GRIDDATA__MSG__DETAIL__GAME_STATE__STRUCT_HPP_
#define GRIDDATA__MSG__DETAIL__GAME_STATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__griddata__msg__GameState __attribute__((deprecated))
#else
# define DEPRECATED__griddata__msg__GameState __declspec(deprecated)
#endif

namespace griddata
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GameState_
{
  using Type = GameState_<ContainerAllocator>;

  explicit GameState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int8_t, 9>::iterator, int8_t>(this->cell.begin(), this->cell.end(), 0);
    }
  }

  explicit GameState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cell(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int8_t, 9>::iterator, int8_t>(this->cell.begin(), this->cell.end(), 0);
    }
  }

  // field types and members
  using _cell_type =
    std::array<int8_t, 9>;
  _cell_type cell;

  // setters for named parameter idiom
  Type & set__cell(
    const std::array<int8_t, 9> & _arg)
  {
    this->cell = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    griddata::msg::GameState_<ContainerAllocator> *;
  using ConstRawPtr =
    const griddata::msg::GameState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<griddata::msg::GameState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<griddata::msg::GameState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      griddata::msg::GameState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<griddata::msg::GameState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      griddata::msg::GameState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<griddata::msg::GameState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<griddata::msg::GameState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<griddata::msg::GameState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__griddata__msg__GameState
    std::shared_ptr<griddata::msg::GameState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__griddata__msg__GameState
    std::shared_ptr<griddata::msg::GameState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GameState_ & other) const
  {
    if (this->cell != other.cell) {
      return false;
    }
    return true;
  }
  bool operator!=(const GameState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GameState_

// alias to use template instance with default allocator
using GameState =
  griddata::msg::GameState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace griddata

#endif  // GRIDDATA__MSG__DETAIL__GAME_STATE__STRUCT_HPP_
