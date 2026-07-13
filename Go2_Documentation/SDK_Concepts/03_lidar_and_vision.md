# LiDAR Sensing & Camera Vision Application

This document covers the technical specifications of the Unitree L1 LiDAR, the point cloud distortion correction pipeline, 2.5D height mapping, 3D voxel maps, and WebRTC camera stream rendering.

---

## 1. Reference Links to Archive Sources
For original coordinate diagrams and application guides, refer to the archived documents:
* [[Go2_Documentation/archive/SDK_Concepts/Robot_Dog_Application/LiDAR_Application|Raw LiDAR Application Guide]]
* [[Go2_Documentation/archive/SDK_Concepts/Robot_Dog_Application/Image_Application|Raw Image Application Guide]]

---

## 2. Unitree 4D LiDAR-L1 Specifications

The Unitree 4D LiDAR-L1 measures 3D spatial points along with a 1D grayscale reflectivity index.

| Parameter | Specification |
| :--- | :--- |
| **Field of View (FOV)** | 360° Horizontal × 90° Vertical (Hemispherical coverage) |
| **Ranging Rate** | 21,600 laser samples per second (Time-of-Flight ranging) |
| **Built-in IMU** | 6-axis (3-axis acceleration + 3-axis gyro) |
| **IMU Output Rate** | 250 Hz |
| **Origin (0,0,0)** | Centered at the internal IMU center. |

The scan head combines a high-speed rotating motor (adjusting azimuth angle) and a low-speed rotating motor (adjusting elevation angle) to execute a dense hemispherical scan pattern.

---

## 3. LiDAR Service Pipeline & Distortion Removal

Because the robot moves while the laser is scanning, point clouds suffer from motion distortion. The `Unilidar Node` corrects this by combining scan data with high-rate odometer updates:

```
                  [LiDAR Hardware]
                         │
                         ▼ (Raw measurement packets)
                  [Unilidar SDK]
                         │
                         ▼ (Uncorrected Point Cloud + IMU)
                  [Unilidar Node] <─── [Odom Telemetry (from MCU)]
                         │
                         ▼ (Motion Distortion Removal)
    ┌────────────────────┴────────────────────┐
    ▼                                         ▼
[rt/utlidar/cloud_desk]                  [rt/utlidar/cloud_world]
(Original lidar coordinate frame)        (World coordinate frame)
```

---

## 4. Map Types: 2.5D Height Maps vs. 3D Voxel Maps

The filtered point clouds populate two map structures:
1. **2.5D Height Map:** Mapped on a 2D grid where each cell contains a height value. Updated in real-time centered around the robot's local body frame. Used by the locomotion controller for terrain adaptation, step planning, and obstacle avoidance.
2. **3D Voxel Map:** Tracks volumetric spatial occupancy in a 3D grid. Transmitted to the companion app via WebRTC. Used for remote operation, providing first-person or third-person views of the robot's environment.

---

## 5. Vision Services & Gestures

The Go2 head camera streams live video to the App using WebRTC. 

### Remote View Modes
* **First-Person View (FPV):** The virtual camera tracks behind the robot model, rotating synchronously with the IMU heading.
* **Third-Person View (TPV):** Fixed perspective that allows the operator to rotate and zoom around the robot.
* **Gesture Controls:** Double-tapping the screen toggles between FPV and TPV modes. Sliding two fingers horizontally splits the screen to show the live video feed alongside the 3D voxel map.

---

## 6. Project Relevance
* **Point Cloud Processing:** Our custom SLAM pipeline subscribes to `rt/utlidar/cloud_world` to get distortion-corrected point clouds. This minimizes frame matching errors during rapid mapping.
* **Camera Feeds:** In smart inspection tasks, the FPV video stream is routed to our computer vision nodes to check for manufacturing anomalies or detect safety hazards (e.g. wet floors or misplaced cargo).
