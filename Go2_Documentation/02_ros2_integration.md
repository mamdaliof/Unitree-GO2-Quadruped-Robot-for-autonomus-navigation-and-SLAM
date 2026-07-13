# ROS 2 Integration Guide

This guide covers building the ROS 2 workspace, handling dependencies, and mapping DDS topics to ROS 2 topics for the Unitree Go2.

## 1. System Requirements & Compatibility

The Go2 SDK and ROS 2 wrappers support different distributions depending on the host OS.

| Target Platform | Recommended ROS 2 Distro | Ubuntu Version |
| :--- | :--- | :--- |
| Onboard Jetson (EDU Dock) | ROS 2 Jazzy Jalisco | Ubuntu 24.04 LTS |
| Local Developer PC (Legacy) | ROS 2 Humble Hawksbill | Ubuntu 22.04 LTS |

---

## 2. Compilation and Workspace Setup

The communication stack is divided into two parts:
1. **`cyclonedds_ws`:** Contains custom message/service IDL definitions for `unitree_go` and `unitree_api`.
2. **`Go2_ROS2_example`:** Contains example control nodes.

### Step 1: Install DDS dependencies
Before compiling, install RMW DDS generators:
```bash
sudo apt update
sudo apt install ros-${ROS_DISTRO}-rmw-cyclonedds-cpp
sudo apt install ros-${ROS_DISTRO}-rosidl-generator-dds-idl
```

### Step 2: Clone Workspace Repositories
```bash
git clone https://github.com/unitreerobotics/unitree_ros2.git
```

### Step 3: Compile CycloneDDS RMW Wrapper
> [!IMPORTANT]
> The CycloneDDS version used by the Unitree robot is `0.10.2`. You must compile the matching RMW implementation. Ensure your standard ROS environment is **NOT** sourced in the terminal during this compilation step.

```bash
# Verify ROS environment is empty (no output expected)
echo $ROS_DISTRO

cd ~/unitree_ros2/cyclonedds_ws/src
git clone https://github.com/ros2/rmw_cyclonedds -b ${ROS_DISTRO}
git clone https://github.com/eclipse-cyclonedds/cyclonedds -b releases/0.10.x 
cd ..
colcon build --packages-select cyclonedds
```

### Step 4: Compile Message Packages
Source your ROS distribution environment, then build the custom message and API definition packages:
```bash
source /opt/ros/${ROS_DISTRO}/setup.bash
colcon build
```

---

## 3. Topic Prefix Mapping (DDS vs. ROS 2)

Because the Unitree SDK 2 communicates natively via CycloneDDS, ROS 2 topics undergo automatically managed prefix translations.

* **Prefix Removal:** The DDS real-time prefix `rt/` is automatically stripped in ROS 2.
* **Namespace Translation:** Topics prefixed with `rt/utlidar/...` in DDS become `/utlidar/...` in the ROS 2 node graph.

### Topic Translation Reference Table

| DDS Topic Name | ROS 2 Target Topic Name | ROS 2 Message Type |
| :--- | :--- | :--- |
| `rt/utlidar/cloud_deskewed` | `/utlidar/cloud_deskewed` | `sensor_msgs/msg/PointCloud2` |
| `rt/sportmodestate` | `/sportmodestate` | `unitree_go/msg/SportModeState` |
| `rt/lowstate` | `/lowstate` | `unitree_go/msg/LowState` |
| `rt/utlidar/range_info` | `/utlidar/range_info` | `geometry_msgs/msg/PointStamped` |
| `rt/utlidar/switch` | `/utlidar/switch` | `std_msgs/msg/String` |

---

## 4. Verification CLI Commands
To verify the interface is running and topics are mapped correctly, run:
```bash
source ~/unitree_ros2/setup.sh
ros2 topic list
```
Verify topic data is publishing:
```bash
ros2 topic echo /sportmodestate
```
