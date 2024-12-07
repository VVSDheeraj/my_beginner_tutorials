/**
 * @class MinimalPublisher
 * @brief A ROS 2 node that publishes messages to a topic and provides a service to update the base message dynamically.
 * @brief Implements the MinimalPublisher class for message publishing and dynamic service functionality.
 * 
 * This node publishes messages to a topic at fixed intervals and includes a service to dynamically update the message content.
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
 */
class MinimalPublisher : public rclcpp::Node {
 public:
  /**
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
  }

 private:
  /**
   * @brief Publishes the message content along with the current time.
   */
  void TimerCallback() {
    auto message = std_msgs::msg::String();
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    message.data = message_content_ + " Current time: " +
        std::string(std::ctime(&time));
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
  }

  /**
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
