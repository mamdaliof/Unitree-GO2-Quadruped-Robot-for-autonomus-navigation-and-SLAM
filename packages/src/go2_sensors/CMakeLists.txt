cmake_minimum_required(VERSION 3.8)
project(go2_sensors)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(unitree_api REQUIRED)
find_package(go2_sport_api REQUIRED)
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

# Declare executable: sensor_publisher_node
add_executable(sensor_publisher_node src/sensor_publisher_node.cpp)
target_link_libraries(sensor_publisher_node
  go2_sensors_lib
  rclcpp::rclcpp
  sensor_msgs::sensor_msgs
)

# Declare executable: sensor_calibration_node
add_executable(sensor_calibration_node src/sensor_calibration_node.cpp)
target_link_libraries(sensor_calibration_node
  go2_sensors_lib
  rclcpp::rclcpp
  sensor_msgs::sensor_msgs
  geometry_msgs::geometry_msgs
)
# Explicitly include the dependency directories
target_include_directories(sensor_calibration_node PRIVATE
  ${go2_sport_api_INCLUDE_DIRS}
  ${unitree_api_INCLUDE_DIRS}
)
# Note: go2_sport_api requires unitree_api and unitree_go.
# Linking via ament dependencies is standard:
ament_target_dependencies(sensor_calibration_node
  unitree_api
  go2_sport_api
)

install(
  TARGETS sensor_publisher_node sensor_calibration_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()



