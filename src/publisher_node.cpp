/**
 * @file publisher_node.cpp
 * @brief This file contains the implementation of the MinimalPublisher class.
 *        It publishes a string message at regular intervals and provides a service
 *        to dynamically update the message string. The node also demonstrates logging
 *        with all five levels: DEBUG, INFO, WARN, ERROR, and FATAL.
 * @author 
 * @version 1.0
 * @date 2024-11-06
 * @copyright Copyright (c) 2024
 */

#include <chrono>                    // C++ system header for timing
#include "rclcpp/rclcpp.hpp"         // ROS header
#include "std_msgs/msg/string.hpp"   // ROS header for String message
#include "my_beginner_tutorials/srv/ChangeString.hpp"  // Include custom service header

using namespace std::chrono_literals;  // For using `500ms`

/**
 * @class MinimalPublisher
 * @brief A ROS 2 node that publishes messages to a topic and provides a service
 *        to update the base message dynamically.
 */
class MinimalPublisher : public rclcpp::Node {
 public:
  /**
   * @brief Constructor for the MinimalPublisher class.
   */
  MinimalPublisher() : Node("minimal_publisher"), base_message_("Hello, my name is Dheeraj and this is a beginner tutorial!") {
    // Create publisher
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);

    // Create timer to publish messages periodically
    timer_ = this->create_wall_timer(
        500ms, std::bind(&MinimalPublisher::timer_callback, this));

    // Create service to update the base message
    service_ = this->create_service<my_beginner_tutorials::srv::ChangeString>(
        "change_string", std::bind(&MinimalPublisher::change_string_callback, this, std::placeholders::_1, std::placeholders::_2));

    // Log info message
    RCLCPP_INFO(this->get_logger(), "MinimalPublisher node has started.");
  }

 private:
  /**
   * @brief Timer callback function that publishes messages periodically.
   */
  void timer_callback() {
    auto message = std_msgs::msg::String();
    message.data = base_message_;

    // Log at different levels
    RCLCPP_DEBUG_STREAM(this->get_logger(), "Debug: Timer triggered for publishing.");
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    RCLCPP_WARN_STREAM(this->get_logger(), "Warning: Publishing a message as a demonstration.");
    RCLCPP_ERROR_STREAM(this->get_logger(), "Error: Simulated error log for demonstration (non-critical).");
    RCLCPP_FATAL_STREAM(this->get_logger(), "Fatal: Simulated fatal log for testing (non-blocking).");

    // Publish message
    publisher_->publish(message);
  }

  /**
   * @brief Service callback to update the base message string.
   * @param request The service request containing the new string.
   * @param response The service response indicating success.
   */
  void change_string_callback(const std::shared_ptr<my_beginner_tutorials::srv::ChangeString::Request> request,
                              std::shared_ptr<my_beginner_tutorials::srv::ChangeString::Response> response) {
    base_message_ = request->input;
    response->success = true;
    RCLCPP_INFO_STREAM(this->get_logger(), "Base message updated to: " << base_message_);
  }

  // Publisher for publishing messages
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

  // Timer for periodic publishing
  rclcpp::TimerBase::SharedPtr timer_;

  // Service for updating the base message
  rclcpp::Service<my_beginner_tutorials::srv::ChangeString>::SharedPtr service_;

  // Base message string to publish
  std::string base_message_;
};

/**
 * @brief Main function to run the MinimalPublisher node.
 */
int main(int argc, char *argv[]) {
  // Initialize the ROS 2 system
  rclcpp::init(argc, argv);

  // Spin the MinimalPublisher node
  rclcpp::spin(std::make_shared<MinimalPublisher>());

  // Shutdown the ROS 2 system
  rclcpp::shutdown();
  return 0;
}