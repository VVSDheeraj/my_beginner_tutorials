from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    msg_content_arg = DeclareLaunchArgument(
        "message_content", default_value="My name is Sivaram Dheeraj Vishnubhotla.",
        description="This is an initial message content for the publisher node")

    publisher_node = Node(
        package="beginner_tutorials",
        executable="publisher_node",
        parameters=[{"message_content": LaunchConfiguration("message_content")}]
    )

    subscriber_node = Node(
        package="beginner_tutorials",
        executable="subscriber_node",
    )

    return LaunchDescription([
        msg_content_arg,
        publisher_node,
        subscriber_node
    ])
