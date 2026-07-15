# Remote Execution & Jetson Setup Guide

This guide details the step-by-step instructions to set up the Unitree Go2 robot's onboard Jetson processor, compile the SLAM and SDK packages, and run the execution processes on the Jetson while visualizing the real-time map in RViz2 on your local laptop.

---

## 1. Jetson Processor Environment Setup

Log into the Jetson processor on the Go2 robot via SSH. Usually, the robot has a default local IP on the ethernet network (e.g., `192.168.123.12` or similar).

```bash
ssh unitree@192.168.123.12
```

### 1.1 Install System Dependencies
Update the Jetson package index and install Ceres solver, glog, and the ROS 2 PCL integration packages:

```bash
sudo apt update
sudo apt install -y \
  libceres-dev \
  libgoogle-glog-dev \
  ros-${ROS_DISTRO}-pcl-conversions \
  ros-${ROS_DISTRO}-pcl-ros
```

### 1.2 Clone and Compile Workspace
1. Clone this repository into your workspace directory on the Jetson (e.g., `~/learning-factory-project`).
2. Build the ROS 2 workspace:

```bash
cd ~/learning-factory-project/packages
source /opt/ros/${ROS_DISTRO}/setup.bash
colcon build
```

---

## 2. Multi-Machine ROS 2 DDS Networking

To allow your laptop and the robot's Jetson to discover each other automatically over the network:

1. Connect both your laptop and the Jetson to the same network (e.g., wired Ethernet switch or local Wi-Fi router).
2. Set matching `ROS_DOMAIN_ID` environment variables on **both** machines. This isolates your ROS 2 topics from other developers on the network:

```bash
# Run this in the terminal on the Jetson
export ROS_DOMAIN_ID=42

# Run this in the terminal on your local laptop
export ROS_DOMAIN_ID=42
```

---

## 3. Running Mapping Processes on the Jetson

On the Jetson, source the compiled packages and launch the unified bringup script. Pass the `rviz:=false` argument to prevent launching the RViz GUI on the headless Jetson:

```bash
# On the Jetson
source /opt/ros/${ROS_DISTRO}/setup.bash
source ~/learning-factory-project/packages/install/setup.bash

# Start raw sensor publisher and SLAM (Point-LIO or A-LOAM depending on config json)
ros2 launch go2_bringup mapping_unilidar_launch.py rviz:=false
```

---

## 4. Running RViz2 Visualization on Local Laptop

On your laptop, you only need to run the visualization layer. ROS 2 DDS will transport the point clouds and tf frames from the Jetson to your laptop automatically:

```bash
# On your local laptop
source /opt/ros/${ROS_DISTRO}/setup.bash
source ~/learning-factory-project/packages/install/setup.bash

# If you configured go2_config.json to use Point-LIO:
rviz2 -d ~/learning-factory-project/packages/src/point_lio_unilidar/rviz_cfg/loam_livox2.rviz

# If you configured go2_config.json to use A-LOAM:
rviz2 -d ~/learning-factory-project/packages/src/aloam/rviz_cfg/aloam_velodyne_ros2.rviz
```

You can now use the Unitree physical remote controller to guide the robot. The laptop will display the live map building and pose estimation in real-time.
