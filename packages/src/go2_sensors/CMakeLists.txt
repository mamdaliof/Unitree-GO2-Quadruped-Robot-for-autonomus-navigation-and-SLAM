cmake_minimum_required(VERSION 3.8)
project(go2_sensors)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(go2_navigation REQUIRED)

# Declare headers and library
add_library(go2_sensors_lib SHARED
  src/robot_imu.cpp
  src/lidar.cpp
)

target_include_directories(go2_sensors_lib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(go2_sensors_lib PUBLIC
  rclcpp::rclcpp
  sensor_msgs::sensor_msgs
  go2_navigation::go2_navigation_interfaces
)

# Install targets
install(
  TARGETS go2_sensors_lib
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

# Declare executable
add_executable(sensor_publisher_node src/sensor_publisher_node.cpp)
target_link_libraries(sensor_publisher_node
  go2_sensors_lib
  rclcpp::rclcpp
  sensor_msgs::sensor_msgs
)

install(
  TARGETS sensor_publisher_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY include/
  DESTINATION include
)

ament_package()



