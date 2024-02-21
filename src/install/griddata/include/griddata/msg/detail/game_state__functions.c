// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from griddata:msg/GameState.idl
// generated code does not contain a copyright notice
#include "griddata/msg/detail/game_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
griddata__msg__GameState__init(griddata__msg__GameState * msg)
{
  if (!msg) {
    return false;
  }
  // cell
  return true;
}

void
griddata__msg__GameState__fini(griddata__msg__GameState * msg)
{
  if (!msg) {
    return;
  }
  // cell
}

bool
griddata__msg__GameState__are_equal(const griddata__msg__GameState * lhs, const griddata__msg__GameState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cell
  for (size_t i = 0; i < 9; ++i) {
    if (lhs->cell[i] != rhs->cell[i]) {
      return false;
    }
  }
  return true;
}

bool
griddata__msg__GameState__copy(
  const griddata__msg__GameState * input,
  griddata__msg__GameState * output)
{
  if (!input || !output) {
    return false;
  }
  // cell
  for (size_t i = 0; i < 9; ++i) {
    output->cell[i] = input->cell[i];
  }
  return true;
}

griddata__msg__GameState *
griddata__msg__GameState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  griddata__msg__GameState * msg = (griddata__msg__GameState *)allocator.allocate(sizeof(griddata__msg__GameState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(griddata__msg__GameState));
  bool success = griddata__msg__GameState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
griddata__msg__GameState__destroy(griddata__msg__GameState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    griddata__msg__GameState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
griddata__msg__GameState__Sequence__init(griddata__msg__GameState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  griddata__msg__GameState * data = NULL;

  if (size) {
    data = (griddata__msg__GameState *)allocator.zero_allocate(size, sizeof(griddata__msg__GameState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = griddata__msg__GameState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        griddata__msg__GameState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
griddata__msg__GameState__Sequence__fini(griddata__msg__GameState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      griddata__msg__GameState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

griddata__msg__GameState__Sequence *
griddata__msg__GameState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  griddata__msg__GameState__Sequence * array = (griddata__msg__GameState__Sequence *)allocator.allocate(sizeof(griddata__msg__GameState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = griddata__msg__GameState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
griddata__msg__GameState__Sequence__destroy(griddata__msg__GameState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    griddata__msg__GameState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
griddata__msg__GameState__Sequence__are_equal(const griddata__msg__GameState__Sequence * lhs, const griddata__msg__GameState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!griddata__msg__GameState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
griddata__msg__GameState__Sequence__copy(
  const griddata__msg__GameState__Sequence * input,
  griddata__msg__GameState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(griddata__msg__GameState);
    griddata__msg__GameState * data =
      (griddata__msg__GameState *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!griddata__msg__GameState__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          griddata__msg__GameState__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!griddata__msg__GameState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
