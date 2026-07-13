# Simulation Guide: Unitree Go2 Unity-ROS 2 Environment

This document describes the simulation architecture, dependencies, execution sequence, and integration setup for the Unitree Go2 quadruped simulator.

---

## 1. Simulation Architecture Overview
The simulation environment uses a decoupled architecture where the physical engine/rendering and the control stack run separately:

```
┌─────────────────────────────────┐          ┌──────────────────────────────────┐
│        Unity Environment        │          │          ROS 2 Workspace         │
│  (Terrain models, motor physics,│ ◄──────► │     (Point-LIO, Local Planner,   │
│   LiDAR rays, IMU simulation)   │   TCP    │      FAR Planner, Control)       │
│                                 │          │                                  │
│   - Port: 10000 (ROS-TCP)       │          │   - ROS-TCP-Endpoint Node        │
└─────────────────────────────────┘          └──────────────────────────────────┘
```

* **Physical Simulator (Unity):** Simulates the robot's physical model, joints, kinematics, Livox L1 LiDAR raycasts, and IMU data.
* **Control Stack (ROS 2):** Processes simulated point clouds, performs SLAM, calculates local paths, and outputs command velocities.
* **Bridge (ROS-TCP-Endpoint):** A TCP socket bridge that translates ROS 2 messages (`/cmd_vel`) to Unity inputs and converts Unity sensor payloads back to ROS 2 topics (`/utlidar/cloud`, `/utlidar/imu`, `/state_estimation`).

---

## 2. Dependencies & Setup

### A. ROS 2 Packages
The simulation has been verified on **ROS 2 Foxy** (Ubuntu 20.04) and **ROS 2 Humble** (Ubuntu 22.04). Install the required ROS 2 dependencies:

```bash
sudo apt update
sudo apt install libusb-dev \
                 ros-humble-perception-pcl \
                 ros-humble-sensor-msgs-py \
                 ros-humble-tf-transformations \
                 ros-humble-joy \
                 ros-humble-rmw-cyclonedds-cpp \
                 ros-humble-rosidl-generator-dds-idl \
                 python3-colcon-common-extensions \
                 python-is-python3
pip install transforms3d pyyaml
```

### B. Unity Environment Binary
1. Download the pre-compiled Unity environment zip file.
2. Unzip and place it under `src/base_autonomy/vehicle_simulator/mesh/unity/environment/`.
3. Ensure the folder contains:
   * `Model.x86_64` (Executable binary)
   * `Model_Data/`
   * `UnityPlayer.so`
   * `Dimensions.csv`
   * `Categories.csv`

---

## 3. Running the Simulation

### A. Execution Script
To launch the simulation, run the root-level script:
```bash
./system_simulation.sh
```

This script:
1. Launches the Unity environment binary in the background:
   ```bash
   ./src/base_autonomy/vehicle_simulator/mesh/unity/environment/Model.x86_64 &
   ```
2. Pauses for 3 seconds to let the TCP socket bind.
3. Launches the main ROS 2 simulation stack:
   ```bash
   ros2 launch vehicle_simulator system_simulation.launch
   ```

### B. Route Planner Mode
To run the simulation with active global route planning (visibility graph-based path finding), run:
```bash
./system_simulation_with_route_planner.sh
```

---

## 4. Control Modes in Simulation
Once RVIZ and the Unity simulator window are active, three control modes can be used:

1. **Smart Joystick Mode (Default):** The robot follows joystick inputs (published via `joy_node`) while running local collision avoidance. Activating gamepad inputs automatically triggers this mode.
2. **Waypoint Mode:** The robot navigates autonomously to target points. Use the `Waypoint` button in RVIZ to set coordinates near the robot.
3. **Manual Mode:** Full manual control bypassing obstacle avoidance. The operator directly drives the robot using the remote controller.

---

## 5. Limitations & Troubleshooting

* **ROS-TCP-Endpoint Crash:** If the TCP bridge fails to connect on startup, displaying a socket binding error, close all running processes and relaunch the script.
* **Large Data Delay on Humble:** Under ROS 2 Humble (Ubuntu 22.04), data transport through the TCP bridge can occasionally experience latency exceeding $1\text{ s}$. Setting `use_sim_time: true` in all launch files is required to maintain transform synchronization.
* **Path Generation Limits:** Setting waypoint goals too far from the robot in unknown space can cause the local planner to get stuck at dead ends. Waypoints must be placed within the immediate $5\text{ m}$ visibility horizon.
