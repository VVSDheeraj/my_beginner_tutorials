/**
 * @file publisher_node.cpp
<<<<<<< HEAD
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
=======
 * @brief Implements the MinimalPublisher class for message publishing and dynamic service functionality.
 * 
 * This node publishes messages to a topic at fixed intervals and includes a 
 * service to dynamically update the message content.
 * 
 * @version 2.0
 * @date 2024-11-06
 * @copyright Copyright 2024
 * Copyright 2024 Sivaram Dheeraj Vishnubhotla
 */

#include <ctime>
#include <memory>
#include <rclcpp/logging.hpp>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "beginner_tutorials/srv/change_string.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

/**
 * @class MinimalPublisher
 * @brief ROS 2 node to publish messages and provide a service for modifying 
 * the message content.
>>>>>>> 8c9c43e (Correct changes)
 */
class MinimalPublisher : public rclcpp::Node {
 public:
  /**
<<<<<<< HEAD
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
=======
   * @brief Constructs the MinimalPublisher object.
   * 
   * Initializes a publisher on "custom_topic" to send periodic messages and 
   * sets up a service on "change_message" to modify the message content.
   */
  MinimalPublisher() : Node("minimal_publisher"),
    message_content_("My name is Sivaram Dheeraj Vishnubhotla.") {
    publisher_ = this->create_publisher<std_msgs::msg::String>(
        "custom_topic", 10);

    this->declare_parameter<std::string>("message_content", message_content_);
    this->get_parameter("message_content", message_content_);
    RCLCPP_DEBUG(this->get_logger(), "Initial message content: '%s'",
        message_content_.c_str());

    if (message_content_ == "My name is Sivaram Dheeraj Vishnubhotla.") {
      RCLCPP_ERROR(this->get_logger(),
          "This is a default message. Update it as needed.");
    }

    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(500),
        std::bind(&MinimalPublisher::TimerCallback, this));

    change_message_service_ =
        this->create_service<beginner_tutorials::srv::ChangeString>(
            "change_message",
            std::bind(&MinimalPublisher::ChangeMessageService, this, _1, _2));

    RCLCPP_INFO(this->get_logger(), "MinimalPublisher node is active.");
>>>>>>> 8c9c43e (Correct changes)
  }

 private:
  /**
<<<<<<< HEAD
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
=======
   * @brief Publishes the message content along with the current time.
   */
  void TimerCallback() {
    auto message = std_msgs::msg::String();
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    message.data = message_content_ + " Current time: " +
        std::string(std::ctime(&time));
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
>>>>>>> 8c9c43e (Correct changes)
    publisher_->publish(message);
  }

  /**
<<<<<<< HEAD
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
=======
   * @brief Service callback to update the message content.
   * 
   * @param request Contains the new message string.
   * @param response Indicates the success status of the operation.
   */
  void ChangeMessageService(
      const std::shared_ptr<beginner_tutorials::srv::ChangeString::Request>
      request,
      std::shared_ptr<beginner_tutorials::srv::ChangeString::Response>
      response) {
    RCLCPP_WARN(this->get_logger(),
        "Processing request to update message content.");
    message_content_ = request->message;
    response->success = true;
    RCLCPP_INFO(this->get_logger(),
        "Message content successfully updated to: '%s'",
        message_content_.c_str());
  }

  rclcpp::TimerBase::SharedPtr timer_;  ///< Timer to trigger message publish
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;  ///< Publish
  rclcpp::Service<beginner_tutorials::srv::ChangeString>::SharedPtr
      change_message_service_;  ///< Service to change message
  std::string message_content_;  ///< Holds the current message content
};

/**
 * @brief Main function to initialize and execute the MinimalPublisher node.
 */
int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
>>>>>>> 8c9c43e (Correct changes)
