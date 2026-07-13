# Onboard SLAM & Navigation Service API

This document details the software interfaces, API JSON schemas, coordinate transformation matrices (Mid-360 / XT-16), and DDS message topics of the onboard SLAM service.

---

## 1. Reference Links to Archive Sources
For original configuration parameters, shell scripts, and network configuration figures, refer to the archived guides:
* [Raw SLAM and Navigation Services Interface Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Software_Interface_Services/SLAM_and_Navigation_Services_Interface.md)

---

## 2. LiDAR Coordinate Transformation Matrices

To map point clouds correctly to the robot's body coordinate system, the relative spatial offset (rigid translation and rotation) between the LiDAR coordinate frame and the internal IMU center must be defined.

### Livox Mid-360 LiDAR matrix
The Mid-360 is mounted at translation `(0.1870m, 0.0m, 0.0803m)` and tilted `13.0°` pitch (around the Y-axis). The transformation matrix $T_{Dog2Lidar}$ is:
$$
\begin{bmatrix}
0.9743701 & 0.0 & 0.2249511 & 0.1870 \\
0.0 & 1.0 & 0.0 & 0.0 \\
-0.2249511 & 0.0 & 0.9743701 & 0.0803 \\
0.0 & 0.0 & 0.0 & 1.0
\end{bmatrix}
$$

### Hesai XT-16 LiDAR matrix
The XT-16 is mounted at translation `(0.1710m, 0.0m, 0.0908m)` with zero rotation offset. The transformation matrix $T_{Dog2Lidar}$ is:
$$
\begin{bmatrix}
1.0 & 0.0 & 0.0 & 0.1710 \\
0.0 & 1.0 & 0.0 & 0.0 \\
0.0 & 0.0 & 1.0 & 0.0908 \\
0.0 & 0.0 & 0.0 & 1.0
\end{bmatrix}
$$

---

## 3. SLAM API JSON Commands Reference

* **Service Name:** `"slam_operate"`
* **Service Version:** `"1.0.0.1"`

API calls send JSON payload requests via SDK RPC.

### 1. Start Mapping (API ID: `1801`)
* **Input Schema:**
  ```json
  { "data": { "slam_type": "indoor" } }
  ```
* **Feedback Schema:**
  ```json
  { "succeed": true, "errorCode": 0, "info": "", "data": {} }
  ```

### 2. End Mapping & Save PCD (API ID: `1802`)
* **Input Schema:**
  ```json
  { "data": { "address": "/home/unitree/test.pcd" } }
  ```

### 3. Initialize Localization Pose (API ID: `1804`)
* **Input Schema:**
  ```json
  {
    "data": {
      "x": 0.0, "y": 0.0, "z": 0.0,
      "q_x": 0.0, "q_y": 0.0, "q_z": 0.0, "q_w": 1.0,
      "address": "/home/unitree/test.pcd"
    }
  }
  ```

### 4. Target Pose Navigation (API ID: `1102`)
* **Input Schema:**
  ```json
  {
    "data": {
      "targetPose": {
        "x": 2.0, "y": 0.0, "z": 0.0,
        "q_x": 0.0, "q_y": 0.0, "q_z": 0.0, "q_w": 1.0
      },
      "mode": 1,
      "speed": 0.5
    }
  }
  ```
  * *Parameters:* `mode` sets obstacle avoidance (1 = Stop, 0 = Bypass). `speed` ranges `[0.2 ~ 1.0]` m/s.
  * *Limits:* The target distance cannot exceed `10 meters` from the active pose. Obstacles must be at least `20 cm` tall to be detected.

### 5. Navigation Control States
* **Pause Navigation (API ID: `1201`)**
* **Resume Navigation (API ID: `1202`)**
* **Close SLAM service (API ID: `1901`)**

---

## 4. DDS Telemetry Topics Description

The SLAM package publishes Point Cloud and Odometry data:
1. **`rt/unitree/slam_mapping/points`** (`PointCloud2_`): Real-time map points.
2. **`rt/unitree/slam_mapping/odom`** (`Odometry_`): Mapping odometry.
3. **`rt/unitree/slam_relocation/points`** (`PointCloud2_`): Relocalization points.
4. **`rt/unitree/slam_relocation/odom`** (`Odometry_`): Current localized pose.
5. **`rt/slam_info`** (`String_`): Publishes real-time JSON system telemetry:
   * **`robot_data`:** Contains motor temp, CPU load, and battery voltage.
   * **`pos_info`:** Contains `currentPose` coordinates and active PCD file name.
   * **`ctrl_info`:** Contains target node, state machine (`isOpenPlan`, `isClimbStairs`), and obstacle proximity status.
6. **`rt/slam_key_info`** (`String_`): Returns JSON task execution results (e.g. `"is_arrived": true`).

---

## 5. Host Setup & Environment Parameters

### 1. Increase Network Buffer size (Run once on Dock Jetson)
Configure network sockets to handle high-bandwidth point cloud streams:
```bash
sudo su
echo "net.core.rmem_max=52428800" >> /etc/sysctl.conf
echo "net.core.wmem_max=52428800" >> /etc/sysctl.conf
sysctl -p
```

### 2. Configure Lidar YAML Parameters
* **File path:** `/unitree/module/unitree_slam/config/slam_interfaces_server_config/param.yaml`
* **Configuration:** Edit `lidar_type` (`mid360` or `xt16`) and input your robot's Serial Number (`lidar_ysn`).
* **Lidar Transforms:** Edit `T_Dog2lidar` in `/unitree/module/unitree_slam/config/gridmap_config/config.yaml` to match the coordinate matrix.

### 3. Execution
```bash
# Terminal 1: Run SLAM service
/unitree/module/unitree_slam/bin/unitree_slam

# Terminal 2: Start Driver
/unitree/module/unitree_slam/bin/mid360_driver

# Terminal 3: Launch test UI
/unitree/module/unitree_slam/bin/keyDemo eth0
```

---

## 6. Project Relevance
* **Automated Map Generation:** During commissioning, the state machine (`go2_state_orchestrator`) sends the `1801` (Start Mapping) command to trigger map creation, and drives the robot along a patrol path to construct the baseline `factory.pcd` map.
* **Odom Recovery:** Reading `rt/unitree/slam_relocation/odom` provides accurate localized coordinates, which is essential to correct for wheel slippage errors on polished concrete factory floors.
