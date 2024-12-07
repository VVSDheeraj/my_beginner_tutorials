// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from my_beginner_tutorials:srv/ChangeString.idl
// generated code does not contain a copyright notice

#ifndef MY_BEGINNER_TUTORIALS__SRV__DETAIL__CHANGE_STRING__TRAITS_HPP_
#define MY_BEGINNER_TUTORIALS__SRV__DETAIL__CHANGE_STRING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "my_beginner_tutorials/srv/detail/change_string__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace my_beginner_tutorials
{

namespace srv
{

inline void to_flow_style_yaml(
  const ChangeString_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: data
  {
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ChangeString_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ChangeString_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_beginner_tutorials

namespace rosidl_generator_traits
{

[[deprecated("use my_beginner_tutorials::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_beginner_tutorials::srv::ChangeString_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_beginner_tutorials::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_beginner_tutorials::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_beginner_tutorials::srv::ChangeString_Request & msg)
{
  return my_beginner_tutorials::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_beginner_tutorials::srv::ChangeString_Request>()
{
  return "my_beginner_tutorials::srv::ChangeString_Request";
}

template<>
inline const char * name<my_beginner_tutorials::srv::ChangeString_Request>()
{
  return "my_beginner_tutorials/srv/ChangeString_Request";
}

template<>
struct has_fixed_size<my_beginner_tutorials::srv::ChangeString_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<my_beginner_tutorials::srv::ChangeString_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<my_beginner_tutorials::srv::ChangeString_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace my_beginner_tutorials
{

namespace srv
{

inline void to_flow_style_yaml(
  const ChangeString_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ChangeString_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ChangeString_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace my_beginner_tutorials

namespace rosidl_generator_traits
{

[[deprecated("use my_beginner_tutorials::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const my_beginner_tutorials::srv::ChangeString_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  my_beginner_tutorials::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use my_beginner_tutorials::srv::to_yaml() instead")]]
inline std::string to_yaml(const my_beginner_tutorials::srv::ChangeString_Response & msg)
{
  return my_beginner_tutorials::srv::to_yaml(msg);
}

template<>
inline const char * data_type<my_beginner_tutorials::srv::ChangeString_Response>()
{
  return "my_beginner_tutorials::srv::ChangeString_Response";
}

template<>
inline const char * name<my_beginner_tutorials::srv::ChangeString_Response>()
{
  return "my_beginner_tutorials/srv/ChangeString_Response";
}

template<>
struct has_fixed_size<my_beginner_tutorials::srv::ChangeString_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<my_beginner_tutorials::srv::ChangeString_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<my_beginner_tutorials::srv::ChangeString_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<my_beginner_tutorials::srv::ChangeString>()
{
  return "my_beginner_tutorials::srv::ChangeString";
}

template<>
inline const char * name<my_beginner_tutorials::srv::ChangeString>()
{
  return "my_beginner_tutorials/srv/ChangeString";
}

template<>
struct has_fixed_size<my_beginner_tutorials::srv::ChangeString>
  : std::integral_constant<
    bool,
    has_fixed_size<my_beginner_tutorials::srv::ChangeString_Request>::value &&
    has_fixed_size<my_beginner_tutorials::srv::ChangeString_Response>::value
  >
{
};

template<>
struct has_bounded_size<my_beginner_tutorials::srv::ChangeString>
  : std::integral_constant<
    bool,
    has_bounded_size<my_beginner_tutorials::srv::ChangeString_Request>::value &&
    has_bounded_size<my_beginner_tutorials::srv::ChangeString_Response>::value
  >
{
};

template<>
struct is_service<my_beginner_tutorials::srv::ChangeString>
  : std::true_type
{
};

template<>
struct is_service_request<my_beginner_tutorials::srv::ChangeString_Request>
  : std::true_type
{
};

template<>
struct is_service_response<my_beginner_tutorials::srv::ChangeString_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MY_BEGINNER_TUTORIALS__SRV__DETAIL__CHANGE_STRING__TRAITS_HPP_
