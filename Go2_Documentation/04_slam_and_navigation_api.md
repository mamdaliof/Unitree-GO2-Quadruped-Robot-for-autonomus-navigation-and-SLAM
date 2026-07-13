# SLAM and Navigation API Reference

This document details the coordinate system relations, JSON service API requests/replies, and output topics for the onboard Go2 SLAM service (`slam_operate`).

## 1. LiDAR to IMU Transform Matrices

The Unitree Go2 Edu supports official lidar mounts (Livox Mid-360 or Hesai XT-16). These sensors are mounted on the robot body relative to the internal IMU coordinate frame.

### Livox Mid-360 coordinate Transform
Mounted at translation `(0.1870, 0, 0.0803)` meters and rotated `13.0°` around the pitch Y-axis.
$$
T_{Dog2lidar} = \begin{bmatrix}
0.9743701 & 0.0 & 0.2249511 & 0.1870 \\
0.0 & 1.0 & 0.0 & 0.0 \\
-0.2249511 & 0.0 & 0.9743701 & 0.0803 \\
0.0 & 0.0 & 0.0 & 1.0
\end{bmatrix}
$$

### Hesai XT-16 coordinate Transform
Mounted at translation `(0.1710, 0, 0.0908)` meters with zero relative rotation.
$$
T_{Dog2lidar} = \begin{bmatrix}
1.0 & 0.0 & 0.0 & 0.1710 \\
0.0 & 1.0 & 0.0 & 0.0 \\
0.0 & 0.0 & 1.0 & 0.0908 \\
0.0 & 0.0 & 0.0 & 1.0
\end{bmatrix}
$$

*Note: In the dock configuration files (`/unitree/module/unitree_slam/config/gridmap_config/config.yaml`), edit the `T_Dog2lidar` parameters according to your model.*

---

## 2. Onboard SLAM Service (`slam_operate`)

* **Service Name:** `slam_operate`
* **Version:** `1.0.0.1`
* **Protocol:** Communication uses a request/response model by publishing to target control topics with designated API IDs in JSON format.

### API ID Commands list

#### `1801` - Start Mapping
* **Request Schema:**
  ```json
  {
    "data": {
      "slam_type": "indoor"
    }
  }
  ```

#### `1802` - End Mapping & Save PCD Map
* **Request Schema:**
  ```json
  {
    "data": {
      "address": "/home/unitree/test.pcd"
    }
  }
  ```

#### `1804` - Initialize Relocalization Pose
* **Request Schema:**
  ```json
  {
    "data": {
      "x": 0.0, "y": 0.0, "z": 0.0,
      "q_x": 0.0, "q_y": 0.0, "q_z": 0.0, "q_w": 1.0,
      "address": "/home/unitree/test.pcd"
    }
  }
  ```

#### `1102` - Pose Navigation
Commands the robot to traverse to a target pose.
* **Request Schema:**
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
  * *Parameters:*
    * `mode`: `1` = Stop at obstacles, `0` = Bypass obstacles.
    * `speed`: Navigation velocity limits: `0.2` to `1.0` m/s.
    * *Constraints:* Target distance must be `< 10 meters`. Traversal path is straight-line only.

#### `1201` / `1202` - Pause / Resume Navigation
* **Request Schema:**
  ```json
  {
    "data": {}
  }
  ```

#### `1901` - Close SLAM Service
* **Request Schema:**
  ```json
  {
    "data": {}
  }
  ```

---

## 3. SLAM Topic Outlets

The service publishes mapping, relocalization, and status feedback to specific topics:

| Topic | Data Type | Description |
| :--- | :--- | :--- |
| `rt/unitree/slam_mapping/points` | `sensor_msgs::msg::dds_::PointCloud2_` | Mapping point cloud returns. |
| `rt/unitree/slam_mapping/odom` | `nav_msgs::msg::dds_::Odometry_` | Real-time map odometry. |
| `rt/unitree/slam_relocation/points` | `sensor_msgs::msg::dds_::PointCloud2_` | Point cloud aligned to loaded map. |
| `rt/unitree/slam_relocation/odom` | `nav_msgs::msg::dds_::Odometry_` | Map-frame odometry state. |
| `rt/slam_info` | `std_msgs::msg::dds_::String_` | Continuous JSON status broadcast. |
| `rt/slam_key_info` | `std_msgs::msg::dds_::String_` | Execution results and arrival feedbacks. |

---

## 4. JSON Status Broadcasts (`rt/slam_info` / `rt/slam_key_info`)

### ① Relocalization info (`pos_info`)
```json
{
  "type": "pos_info",
  "errorCode": 0,
  "sec": 123456789,
  "data": {
    "currentPose": {
      "x": 1.5, "y": 1.5, "z": 0.0,
      "q_x": 0.0, "q_y": 0.0, "q_z": 0.0, "q_w": 1.0
    },
    "pcdName": "test",
    "address": "/home/unitree/test.pcd"
  }
}
```

### ② Navigation Status info (`ctrl_info`)
```json
{
  "type": "ctrl_info",
  "errorCode": 0,
  "data": {
    "targetNodeName": 9999,
    "is_arrived": false,
    "stateMachine": {
      "state": "follow",
      "isPause": false,
      "ctrName": "pid",
      "vx": 0.5, "vy": 0.0, "vyaw": 0.0
    },
    "obsInfo": {
      "state": false,
      "time": 0
    },
    "progress": {
      "completion_percentage": 0.12
    }
  }
}
```

### ③ Task Completion (`task_result` from `rt/slam_key_info`)
```json
{
  "type": "task_result",
  "errorCode": 0,
  "data": {
    "targetNodeName": 9999,
    "is_arrived": true
  }
}
```

---

## 5. Execution Test Routines
The SLAM binaries on the dock PC must be launched in order:
```bash
# SSH into Dock PC (Password: 123)
ssh unitree@192.168.123.18

# Terminal 1: Run the SLAM manager
cd /unitree/module/unitree_slam/bin
./unitree_slam

# Terminal 2: Run LiDAR driver (e.g., mid360)
./mid360_driver

# Terminal 3: Run the demo commander CLI
./keyDemo eth0
```
