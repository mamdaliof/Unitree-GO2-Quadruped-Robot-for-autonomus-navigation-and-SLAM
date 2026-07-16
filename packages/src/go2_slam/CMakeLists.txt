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
find_package(pcl_conversions REQUIRED)
find_package(pcl_ros REQUIRED)

# For sensor_msgs
if(TARGET sensor_msgs::sensor_msgs)
  set(sensor_msgs_target sensor_msgs::sensor_msgs)
else()
  set(sensor_msgs_target sensor_msgs::sensor_msgs__rosidl_generator_cpp)
endif()

# For geometry_msgs
if(TARGET geometry_msgs::geometry_msgs)
  set(geometry_msgs_target geometry_msgs::geometry_msgs)
else()
  set(geometry_msgs_target geometry_msgs::geometry_msgs__rosidl_generator_cpp)
endif()

# For nav_msgs
if(TARGET nav_msgs::nav_msgs)
  set(nav_msgs_target nav_msgs::nav_msgs)
else()
  set(nav_msgs_target nav_msgs::nav_msgs__rosidl_generator_cpp)
endif()

# For std_srvs
if(TARGET std_srvs::std_srvs)
  set(std_srvs_target std_srvs::std_srvs)
else()
  set(std_srvs_target std_srvs::std_srvs__rosidl_generator_cpp)
endif()

# For pcl_ros
if(TARGET pcl_ros::pcl_ros)
  set(pcl_ros_target pcl_ros::pcl_ros)
else()
  set(pcl_ros_target "")
endif()

# Declare header-only library
add_library(go2_slam INTERFACE)

target_include_directories(go2_slam INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(go2_slam INTERFACE
  rclcpp::rclcpp
  ${sensor_msgs_target}
  ${geometry_msgs_target}
  ${nav_msgs_target}
  ${std_srvs_target}
  go2_navigation::go2_navigation_interfaces
  pcl_conversions::pcl_conversions
  ${pcl_ros_target}
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
ament_export_dependencies(rclcpp sensor_msgs geometry_msgs nav_msgs std_srvs go2_navigation pcl_conversions pcl_ros)

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
