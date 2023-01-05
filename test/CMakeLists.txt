cmake_minimum_required(VERSION 3.8)
project(test)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tutorial_interfaces REQUIRED)

# ament_export_dependencies(rosidl_default_runtime)

# rosidl_get_typesupport_target(cpp_typesupport_target
#   ${PROJECT_NAME} "rosidl_typesupport_cpp"
# )

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

add_executable(talker src/publisher.cpp)
ament_target_dependencies(talker rclcpp std_msgs)

add_executable(listener src/subscriber.cpp)
ament_target_dependencies(listener rclcpp std_msgs)

add_executable(talker2 src/pub_custom.cpp)
ament_target_dependencies(talker2 rclcpp tutorial_interfaces)

add_executable(listener2 src/sub_custom.cpp)
ament_target_dependencies(listener2 rclcpp tutorial_interfaces)

# add_executable(yourexename src/sub_custom.cpp)
# ament_target_dependencies(yourexename rclcpp )
# target_link_libraries(yourexename "${cpp_typesupport_target}")

install(TARGETS
  talker
  talker2
  listener
  listener2
  DESTINATION lib/${PROJECT_NAME}
  )

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)
ament_package()
