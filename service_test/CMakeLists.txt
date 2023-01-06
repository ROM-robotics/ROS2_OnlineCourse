cmake_minimum_required(VERSION 3.8)
project(service_test)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tutorial_interfaces REQUIRED)


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

add_executable(client src/service_client.cpp)
ament_target_dependencies(client rclcpp tutorial_interfaces)

add_executable(server src/service_server.cpp)
ament_target_dependencies(server rclcpp tutorial_interfaces)

# add_executable(yourexename src/sub_custom.cpp)
# ament_target_dependencies(yourexename rclcpp )
# target_link_libraries(yourexename "${cpp_typesupport_target}")

install(TARGETS
  client
  server
  DESTINATION lib/${PROJECT_NAME}
  )

ament_package()
