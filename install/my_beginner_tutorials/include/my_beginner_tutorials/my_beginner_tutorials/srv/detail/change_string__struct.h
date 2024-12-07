// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_beginner_tutorials:srv/ChangeString.idl
// generated code does not contain a copyright notice

#ifndef MY_BEGINNER_TUTORIALS__SRV__DETAIL__CHANGE_STRING__STRUCT_H_
#define MY_BEGINNER_TUTORIALS__SRV__DETAIL__CHANGE_STRING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ChangeString in the package my_beginner_tutorials.
typedef struct my_beginner_tutorials__srv__ChangeString_Request
{
  rosidl_runtime_c__String data;
} my_beginner_tutorials__srv__ChangeString_Request;

// Struct for a sequence of my_beginner_tutorials__srv__ChangeString_Request.
typedef struct my_beginner_tutorials__srv__ChangeString_Request__Sequence
{
  my_beginner_tutorials__srv__ChangeString_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_beginner_tutorials__srv__ChangeString_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ChangeString in the package my_beginner_tutorials.
typedef struct my_beginner_tutorials__srv__ChangeString_Response
{
  bool success;
} my_beginner_tutorials__srv__ChangeString_Response;

// Struct for a sequence of my_beginner_tutorials__srv__ChangeString_Response.
typedef struct my_beginner_tutorials__srv__ChangeString_Response__Sequence
{
  my_beginner_tutorials__srv__ChangeString_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_beginner_tutorials__srv__ChangeString_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_BEGINNER_TUTORIALS__SRV__DETAIL__CHANGE_STRING__STRUCT_H_
