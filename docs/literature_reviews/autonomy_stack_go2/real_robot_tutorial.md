# Real-Robot Tutorial: CMU Autonomy Stack for Go2

This guide outlines step-by-step instructions for deploying, calibrating, and launching the CMU autonomy stack on the physical Unitree Go2 quadruped robot.

---

## 1. Hardware Infrastructure Setup
To interact with the robot's onboard computer as it walks around the workspace, configure the following wireless desktop workstation:

* **Hardware Needed:**
  1. Wireless HDMI transmitter/receiver kit.
  2. Multi-port USB-C Hub.
  3. Wireless keyboard and mouse (with USB dongle).
  4. Standard gamepad controller (PS3/PS4 or Xbox with USB/Bluetooth).
  5. Dual lock mounting tape.
* **On-Robot Setup:**
  1. Mount the USB-C Hub and Wireless HDMI transmitter to the Go2's chassis back plate using dual-lock tape.
  2. Plug the USB-C Hub into the Go2's onboard computer port.
  3. Connect the HDMI transmitter and keyboard/mouse USB dongles into the hub.
  4. Connect the transmitter's video feed to the workstation monitor. The robot will now transmit its screen UI wirelessly.

---

## 2. Onboard Network & DDS Configuration

### A. Network Interface Configuration
1. Connect the external computer (ground station) to the backward-facing Ethernet port on the Go2.
2. Manually set the ground station's IP address:
   * **IP Address:** `192.168.123.100`
   * **Netmask:** `255.255.255.0`
   * **Gateway:** `192.168.123.1`
3. The robot's default onboard computer IP is `192.168.123.18`.

### B. CycloneDDS Environment Configuration
Unitree's ROS 2 SDK uses CycloneDDS. Sourcing standard ROS 2 variables directly can cause communication dropouts, so configure the DDS RMW variables:
1. Open a terminal and source `unitree_ros2_setup.sh` (provided in the Unitree SDK directory).
2. Export the RMW environment variables:
   ```bash
   export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
   ```
3. Define the CYCLONEDDS URI binding (ensuring it matches the active network interface, e.g., `enp3s0` or `eth0`):
   ```bash
   export CYCLONEDDS_URI='<CycloneDDS><Domain><General><Interfaces><NetworkInterface name="enp3s0" priority="default" multicast="default" /></Interfaces></General></Domain></CycloneDDS>'
   ```
4. Run `ros2 topic list` to verify that active SDK topics (such as `/api/sport/request` or `/rt/lowstate`) show up on the ground station.

---

## 3. Mandatory IMU Calibration
The Point-LIO SLAM backend requires pre-calibrated IMU static bias values. Perform this calibration **once** on the physical robot:
1. Place the Go2 on a flat, level surface and power it on. Let the robot stand up.
2. In a terminal, navigate to the autonomy stack workspace directory, source the workspace, and run:
   ```bash
   source install/setup.bash
   ros2 run calibrate_imu calibrate_imu
   ```
3. **Execution Sequence (Must be executed exactly):**
   * Let the Go2 step in place for **2 seconds**.
   * Let it stand completely still for **10 seconds**.
   * Let it rotate (spin) in place for **20 seconds**.
4. The script will calculate bias offsets and generate `imu_calib_data.yaml` on the computer's desktop (`~/Desktop/`). Do not move or rename this file.

---

## 4. Launching the Autonomy Stack

### A. Base System (SLAM + Local Planner)
To launch the core SLAM mapping and local obstacle avoidance nodes:
1. Open a terminal, source the DDS variables, and source the compiled workspace.
2. Run the bringup script:
   ```bash
   ./system_real_robot.sh
   ```
3. Use the RVIZ interface on the control monitor to set waypoints near the robot or toggle joystick overrides.

### B. Route Planner Mode (Visibility Graph)
To launch with FAR Planner (global visibility graph route planning active):
```bash
./system_real_robot_with_route_planner.sh
```

### C. Launching the Camera Republisher
To stream the Go2's front camera H.264 video feed and publish decoded images to `/camera/image/raw`:
```bash
source install/setup.bash
ros2 run go2_h264_repub go2_h264_repub
```

### D. Recording Dataset bags
To record LiDAR and IMU raw scans for offline replay:
```bash
ros2 bag record /utlidar/cloud /utlidar/imu
```
Ensure you transfer both the `.db3` bagfile and the `imu_calib_data.yaml` parameter file to your offline analysis computer.
