cmake_minimum_required(VERSION 3.8)
project(go2_navigation)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

# Declare header-only library
add_library(go2_navigation_interfaces INTERFACE)

target_include_directories(go2_navigation_interfaces INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(go2_navigation_interfaces INTERFACE
  rclcpp::rclcpp
  sensor_msgs::sensor_msgs
  geometry_msgs::geometry_msgs
  nav_msgs::nav_msgs
)

# Install headers
install(
  DIRECTORY include/
  DESTINATION include
)

# Export interface library
install(
  TARGETS go2_navigation_interfaces
  EXPORT export_${PROJECT_NAME}
)

ament_export_targets(export_${PROJECT_NAME} HAS_LIBRARY_TARGET)
ament_export_dependencies(rclcpp sensor_msgs geometry_msgs nav_msgs)



if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()

  # Add Mock Unit Tests
  find_package(ament_cmake_gmock REQUIRED)
  ament_add_gmock(test_interfaces
    test/test_interfaces.cpp
  )
  target_include_directories(test_interfaces PRIVATE
    include
    test
  )
  target_link_libraries(test_interfaces
    go2_navigation_interfaces
  )
endif()

ament_package()
