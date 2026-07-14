# Localization Configuration Guide: FAST_LIO_LOCALIZATION_HUMANOID

This guide details the parameters, sensor configurations, and extrinsic transformations required to deploy the Open3D map-based localization stack on Unitree G1 and Go2 robots.

---

## 1. Parameters Configuration (`open3d_loc`)

The core node parameters are configured in the launch files or via ROS 2 parameters:

| Parameter Name | Default Value | Description |
| :--- | :--- | :--- |
| `path_map` | `""` | Absolute path to the pre-built global `.pcd` or `.ply` point cloud map. |
| `pcd_queue_maxsize` | `5` | Number of scan frames to accumulate in the point cloud queue before registration. |
| `maxpoints_source` | `50000` | Maximum number of points allowed in the source scan for ICP registration (downsampled randomly if exceeded). |
| `maxpoints_target` | `200000` | Maximum number of points allowed in the target submap for ICP registration. |
| `loc_frequence` | `2.0` | Update frequency of the ICP registration (in seconds per update). |
| `confidence_loc_th` | `0.6` | Threshold for registration confidence. |
| `voxelsize_coarse` | `0.2` | Voxel size (in meters) for downsampling the map for initial localization. |
| `voxelsize_fine` | `0.05` | Voxel size (in meters) for downsampling the map for fine localization. |
| `threshold_fitness_init`| `0.9` | Minimum fitness score (overlap ratio) required for initial localization lock. |
| `threshold_fitness` | `0.9` | Minimum fitness score (overlap ratio) required to apply a tracking update. |
| `dis_updatemap` | `1.0` | Distance threshold (in meters) the robot must travel before updating the local submap. |
| `filter_odom2map` | `false` | Enable/disable Kalman filtering on the odom-to-map transform. |

---

## 2. Sensor Extrinsics Setup

### 2.1 Livox MID360 Configuration (`MID360_config.json`)
The LiDAR configuration file sets up the networking and pointcloud/IMU extrinsics. 

```json
{
  "lidar_configs" : [
    {
      "ip" : "192.168.123.120",
      "pcl_data_type" : 1,
      "pattern_mode" : 0,
      "extrinsic_parameter" : {
        "roll": 180.0,
        "pitch": 0.0,
        "yaw": 0.0,
        "x": 0,
        "y": 0,
        "z": 0
      }
    }
  ]
}
```

* **Unitree G1 (Humanoid):** The LiDAR is mounted upside down. A `180.0` degree `roll` extrinsic parameter must be defined to align the gravity vector of the IMU and correct the point cloud representation.
* **Unitree Go2 (Quadruped):** The LiDAR coordinate system differs by only `6.0` degrees on the Y-axis (pitch). In Go2 setups, the default official driver can be used directly without modified IMU extrinsics.

---

## 3. Launching the Stack

The localization stack is initiated by launching both Fast LIO and the Open3D localization nodes:

```bash
ros2 launch open3d_loc localization_3d_g1.launch.py
```

### Initial Pose Estimation:
1. Open RViz.
2. Select **2D Pose Estimate** from the top menu.
3. Click and drag the green arrow on the point cloud map to specify the robot's approximate position and orientation.
4. Once the fitness score exceeds `threshold_fitness_init` twice, the status updates to `localization initialize success!!!!`, and tracking begins.
