// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_beginner_tutorials:srv/ChangeString.idl
// generated code does not contain a copyright notice

#ifndef MY_BEGINNER_TUTORIALS__SRV__DETAIL__CHANGE_STRING__BUILDER_HPP_
#define MY_BEGINNER_TUTORIALS__SRV__DETAIL__CHANGE_STRING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_beginner_tutorials/srv/detail/change_string__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_beginner_tutorials
{

namespace srv
{

namespace builder
{

class Init_ChangeString_Request_data
{
public:
  Init_ChangeString_Request_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_beginner_tutorials::srv::ChangeString_Request data(::my_beginner_tutorials::srv::ChangeString_Request::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_beginner_tutorials::srv::ChangeString_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_beginner_tutorials::srv::ChangeString_Request>()
{
  return my_beginner_tutorials::srv::builder::Init_ChangeString_Request_data();
}

}  // namespace my_beginner_tutorials


namespace my_beginner_tutorials
{

namespace srv
{

namespace builder
{

class Init_ChangeString_Response_success
{
public:
  Init_ChangeString_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::my_beginner_tutorials::srv::ChangeString_Response success(::my_beginner_tutorials::srv::ChangeString_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_beginner_tutorials::srv::ChangeString_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_beginner_tutorials::srv::ChangeString_Response>()
{
  return my_beginner_tutorials::srv::builder::Init_ChangeString_Response_success();
}

}  // namespace my_beginner_tutorials

#endif  // MY_BEGINNER_TUTORIALS__SRV__DETAIL__CHANGE_STRING__BUILDER_HPP_
