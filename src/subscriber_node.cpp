/**
 * @file subscriber_node.cpp
 * @brief This file contains the implementation of the MinimalSubscriber class.
 * @author Sivaram Dheeraj Vishnubhotla
 * @version 1.0
 * @date 2024-11-06
 * @copyright Copyright (c) 2024
 */

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class MinimalSubscriber : public rclcpp::Node {
 public:
  MinimalSubscriber() : Node("minimal_subscriber") {
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "topic", 10,
        std::bind(&MinimalSubscriber::topic_callback, this,
                  std::placeholders::_1));
  }

 private:
  void topic_callback(const std_msgs::msg::String::SharedPtr msg) const {
    RCLCPP_INFO(this->get_logger(),
                "I heard: '%s'", msg->data.c_str());
  }

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}