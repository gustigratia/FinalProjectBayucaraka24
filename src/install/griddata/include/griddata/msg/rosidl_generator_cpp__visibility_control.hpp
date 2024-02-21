// generated from rosidl_generator_cpp/resource/rosidl_generator_cpp__visibility_control.hpp.in
// generated code does not contain a copyright notice

#ifndef GRIDDATA__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
#define GRIDDATA__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_CPP_EXPORT_griddata __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_CPP_IMPORT_griddata __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_CPP_EXPORT_griddata __declspec(dllexport)
    #define ROSIDL_GENERATOR_CPP_IMPORT_griddata __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_CPP_BUILDING_DLL_griddata
    #define ROSIDL_GENERATOR_CPP_PUBLIC_griddata ROSIDL_GENERATOR_CPP_EXPORT_griddata
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_griddata ROSIDL_GENERATOR_CPP_IMPORT_griddata
  #endif
#else
  #define ROSIDL_GENERATOR_CPP_EXPORT_griddata __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_CPP_IMPORT_griddata
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_CPP_PUBLIC_griddata __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_griddata
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // GRIDDATA__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
