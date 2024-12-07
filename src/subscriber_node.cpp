/**
 * @file subscriber_node.cpp
 * @brief Implements the MinimalSubscriber class for subscribing to a topic and processing incoming messages.
 * 
 * This node demonstrates logging with various severity levels and handles 
 * received messages from a custom topic.
 * 
 * @version 2.0
 * @date 2024-11-06
 * @copyright Copyright 2024
 * @license Apache 2.0 
 * Copyright 2024 Sivaram Dheeraj Vishnubhotla
 */

#include <functional>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

/**
 * @class MinimalSubscriber
 * @brief A ROS 2 node that listens to a topic and logs incoming messages.
 */
class MinimalSubscriber : public rclcpp::Node {
 public:
  /**
   * @brief Initializes the MinimalSubscriber node.
   * 
   * Sets up a subscription to "custom_topic" with a callback function to 
   * process received messages.
   */
  MinimalSubscriber() : Node("minimal_subscriber") {
    RCLCPP_DEBUG(this->get_logger(),
        "Setting up subscription to 'custom_topic'");

    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "custom_topic", 10,
        std::bind(&MinimalSubscriber::TopicCallback, this, _1));

    RCLCPP_INFO(this->get_logger(), "MinimalSubscriber node is now active.");
  }

 private:
  /**
   * @brief Callback to process messages received from the subscribed topic.
   * 
   * Logs the message content and demonstrates different logging levels based 
   * on message content.
   * 
   * @param msg The received message.
   */
  void TopicCallback(const std_msgs::msg::String &msg) const {
    RCLCPP_INFO(this->get_logger(), "Received message: '%s'",
        msg.data.c_str());

    if (msg.data.empty()) {
      RCLCPP_WARN(this->get_logger(), "Received an empty message!");
    }

    if (msg.data == "error") {
      RCLCPP_ERROR(this->get_logger(),
          "Simulated error log for 'error' message.");
    }

    if (msg.data == "fatal") {
      RCLCPP_FATAL(this->get_logger(),
          "Critical issue detected: 'fatal' message received.");
    }
  }

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

/**
 * @brief Main function to initialize and execute the MinimalSubscriber node.
 */
int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);

  RCLCPP_DEBUG(rclcpp::get_logger("rclcpp"),
      "Starting the MinimalSubscriber node.");

  rclcpp::spin(std::make_shared<MinimalSubscriber>());

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"),
      "Shutting down the MinimalSubscriber node.");

  rclcpp::shutdown();
  return 0;
}
