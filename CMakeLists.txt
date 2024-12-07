cmake_minimum_required(VERSION 3.8)
<<<<<<< HEAD
project(my_beginner_tutorials)

=======
project(beginner_tutorials)

# Check if compiler is GCC or Clang, then add extra warnings
>>>>>>> 8c9c43e (Correct changes)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

<<<<<<< HEAD
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)
# find_package(catch_ros2 REQUIRED)

=======
# Set C++ standard to C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable compile_commands.json for linting
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
execute_process(COMMAND cmake -E create_symlink
                "${PROJECT_BINARY_DIR}/compile_commands.json"
                "${PROJECT_SOURCE_DIR}/compile_commands.json")

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)  # For custom service generation

# Enable custom service generation
>>>>>>> 8c9c43e (Correct changes)
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/ChangeString.srv"
  DEPENDENCIES std_msgs
)
<<<<<<< HEAD
ament_export_dependencies(rosidl_default_runtime)


add_executable(publisher_node src/publisher_node.cpp)
ament_target_dependencies(publisher_node rclcpp std_msgs)

add_executable(subscriber_node src/subscriber_node.cpp)
ament_target_dependencies(subscriber_node rclcpp std_msgs)

rosidl_get_typesupport_target(type_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(publisher_node ${type_target})
=======

# Build publisher_node (publisher) node
add_executable(publisher_node src/publisher_node.cpp)
ament_target_dependencies(publisher_node rclcpp std_msgs)

# Build subscriber_node (subscriber) node
add_executable(subscriber_node src/subscriber_node.cpp)
ament_target_dependencies(subscriber_node rclcpp std_msgs)

# ROS Interface dependencies for custom service
rosidl_get_typesupport_target(typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(publisher_node ${typesupport_target})
# target_link_libraries(subscriber_node ${typesupport_target})

# Install binaries and launch files
>>>>>>> 8c9c43e (Correct changes)
install(TARGETS
  publisher_node
  subscriber_node
  DESTINATION lib/${PROJECT_NAME})

<<<<<<< HEAD
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

=======
install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME})


# Google C++ Style and Lint checks
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  
  ament_lint_auto_find_test_dependencies()
endif()

# Check if cpplint executable is available
find_program(CPPLINT_EXECUTABLE cpplint)
if(CPPLINT_EXECUTABLE)
  # Run cpplint when configuring the project
  message(DEBUG " - Running cpplint on source files")
  execute_process(
    COMMAND ${CPPLINT_EXECUTABLE} --filter=-build/c++11,+build/c++17,-build/namespaces,-build/include_order src/*.cpp
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_FILE ${CMAKE_BINARY_DIR}/results/cpplint.txt
    RESULT_VARIABLE CPPLINT_RESULT
    COMMAND echo "Running cpplint on source files"
  )
endif()

# Check if clang-tidy executable is available
find_program(CLANG_TIDY_EXECUTABLE clang-tidy)
if(CLANG_TIDY_EXECUTABLE)
  message(DEBUG " - Running clang-tidy on source files")
  # Run clang-tidy when configuring the project
  execute_process(
    COMMAND ${CLANG_TIDY_EXECUTABLE} --extra-arg=-stdlib=libc++ --extra-arg=-I/usr/include/c++/11 --extra-arg=-I/usr/include/x86_64-linux-gnu/c++/11 src/*.cpp
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_FILE ${CMAKE_BINARY_DIR}/results/clang-tidy.txt
    RESULT_VARIABLE CLANG_TIDY_RESULT
  )

endif()


>>>>>>> 8c9c43e (Correct changes)
ament_package()
