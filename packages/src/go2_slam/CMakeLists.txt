cmake_minimum_required(VERSION 3.8)
project(go2_slam)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(go2_navigation REQUIRED)

# Declare header-only library
add_library(go2_slam INTERFACE)

target_include_directories(go2_slam INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(go2_slam INTERFACE
  rclcpp::rclcpp
  sensor_msgs::sensor_msgs
  geometry_msgs::geometry_msgs
  nav_msgs::nav_msgs
  std_srvs::std_srvs
  go2_navigation::go2_navigation_interfaces
)

# Install headers
install(
  DIRECTORY include/
  DESTINATION include
)

# Export interface library
install(
  TARGETS go2_slam
  EXPORT export_${PROJECT_NAME}
)

ament_export_targets(export_${PROJECT_NAME} HAS_LIBRARY_TARGET)
ament_export_dependencies(rclcpp sensor_msgs geometry_msgs nav_msgs std_srvs go2_navigation)

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

ament_package()
