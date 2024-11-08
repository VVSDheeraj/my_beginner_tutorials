/**
 * @file publisher_node.cpp
 * @brief This file contains the implementation of the MinimalPublisher class.
 * @author Sivaram Dheeraj Vishnubhotla
 * @version 1.0
 * @date 2024-11-06
 * @copyright Copyright (c) 2024
 */

#include <chrono>                    // C++ system header
#include "rclcpp/rclcpp.hpp"         // ROS header
#include "std_msgs/msg/string.hpp"   // ROS header

class MinimalPublisher : public rclcpp::Node {
 public:
  MinimalPublisher() : Node("minimal_publisher") {
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(500),
        std::bind(&MinimalPublisher::timer_callback, this));
  }

 private:
  void timer_callback() {
    auto message = std_msgs::msg::String();
    message.data = "Hello my name is Dheeraj and this is a beginner tutorial!";
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
  }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
