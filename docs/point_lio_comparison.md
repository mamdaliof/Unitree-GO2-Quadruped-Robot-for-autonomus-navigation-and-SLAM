# Point-LIO Codebase Comparison Report

This report compares the official, open-source **`point_lio_unilidar`** repository (cloned from unitreerobotics) against the modified **`point_lio_unilidar`** package in the `autonomy_stack_go2` stack.

---

## 1. Structural Comparison

| Feature / File | Official Repository (ROS 1) | Autonomy Stack Version (ROS 2) |
| :--- | :--- | :--- |
| **ROS Framework** | ROS 1 (Catkin build tool) | ROS 2 Jazzy (Ament CMake & Python build tool) |
| **Dependencies** | `roscpp`, `rospy`, `tf`, `std_msgs` | `rclcpp`, `rclpy`, `tf2`, `tf2_ros`, `std_msgs` |
| **Launch System** | XML format (`.launch`) | XML/Python format (`.py` or `.launch`) |
| **Configuration** | Separated L1/L2 YAMLs | Combined parameters for Go2 robot settings |

---

## 2. Key Code Modifications

### 2.1 ROS 2 Node Adaptation
The main source files (`laserMapping.cpp`, `IMU_Processing.hpp`, `parameters.cpp`, `preprocess.cpp`) were completely refactored to use ROS 2 node handles, shared pointers, and RCLCPP loggers instead of standard `ros::NodeHandle` and `ROS_INFO` macros.

### 2.2 Time Synchronisation and Stamp Resolution
In ROS 2, time stamps are retrieved using `msg->header.stamp.sec + msg->header.stamp.nanosec * 1e-9` instead of `msg->header.stamp.toSec()`. The autonomy stack version implements helper utilities to extract double-precision seconds across all sensor topics.

### 2.3 TF2 Broadcaster Migration
The legacy TF broadcaster `tf::TransformBroadcaster` was replaced with `tf2_ros::TransformBroadcaster` to broadcast localized coordinates in the TF tree relative to the `map` and `odom` frames.

### 2.4 Map Saving Limitations
- **Official version:** Supports saving point clouds periodically based on fixed scan counts.
- **Autonomy stack version:** Maintains the same periodic PCD writer, but lacks an interactive ROS 2 service or interface to trigger manual map saving, load pre-built maps for localization, or support dynamic LiDAR selection.
