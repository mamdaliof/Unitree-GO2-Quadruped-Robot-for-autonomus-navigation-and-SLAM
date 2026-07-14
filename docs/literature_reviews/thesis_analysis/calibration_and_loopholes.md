# Sensor Calibration and System Loopholes: Wilhelm (2025)

This document details the sensor calibration workflows (intrinsics and extrinsics), safety fallbacks, and vulnerabilities identified in the Wilhelm (2025) thesis.

---

## 1. Sensor Calibration Methodologies

### 1.1 LiDAR-IMU Extrinsics
For both LIO-SAM and DLIO, rigid transformation matrices between the IMU frame and the LiDAR frame must be precisely configured. 
- The translation vector $\mathbf{t}$ and rotation matrix $\mathbf{R}$ must align the LiDAR's coordinate system with the robot's primary IMU base link.
- **Reference Baselines:** Extrinsic translation values can be extracted from the robot's URDF description. However, because physical installations introduce minor angles, manual rotational tuning is necessary.

### 1.2 Camera-LiDAR Intrinsics & Extrinsics
To enable colorized 3D point cloud generation using an RGB-D camera (Intel RealSense D435i) and a 3D LiDAR:
- **Intrinsics:** Camera focal length, optical center, and lens distortion coefficients were either extracted from the RealSense factory calibration ROS wrapper or computed using standard chessboard pattern detection.
- **Extrinsics:** Translation and rotation parameters between the camera optical frame and the LiDAR scan center were resolved by manually selecting corresponding 3D/2D points in both the LiDAR point cloud and the camera image (chessboard corners or highly structured scene features).
- **Vibration Loopholes:** Loco-manipulation vibrations and gait adaptations during quadruped walking continuously shift the relative alignment between the camera and LiDAR mounts, causing color misalignments.
- **Recommendation:** Perform checkerboard calibration before each scan deployment, and utilize rubber vibration-damping mounts.

---

## 2. System Loopholes & Vulnerabilities

* **Onboard Jetson Compute Bottleneck:**
  - Running 2D SLAM (SLAM Toolbox), 3D SLAM (LIO-SAM/DLIO), and real-time visualization simultaneously on the Go2 onboard NVidia Jetson processor causes memory depletion and calculation failures.
  - **Correction:** Offload computation. Run the core driver nodes on the Go2, compress LiDAR and camera streams using standard compression tools (e.g. zlib), and transmit them over Wi-Fi to a powerful external PC for SLAM execution.
* **Agile Gait Locomotion Shifts:**
  - Unitree's recent firmware updates force the Go2 into "Agile Gait Mode" at startup. This mode dynamically adapts the leg height and pitch angle based on terrain. 
  - These dynamic changes shift the LiDAR's relative height and introduce artificial noise in the SLAM estimation.
  - **Correction:** Manually lock the robot's locomotion mode to "Normal Mode" (General walking) via the SDK before starting a scan.
* **LiDAR Close-Range Blind Spots:**
  - Top-mounted LiDAR configurations create a vertical blind spot around the immediate legs and chassis. Obstacles lower than $0.3\text{ m}$ directly in front of the robot are missed.
  - **Correction:** Fuse bottom-mounted Unitree 4D L1 LiDAR data or camera depth streams to map immediate close-range obstacles.
* **Voxel Filter Sensitivity:**
  - Indoor vs. outdoor environments require completely different voxel sizes. Setting indoor voxel sizes (e.g. $0.05\text{ m}$) in large spaces causes point cloud buffers to overflow, while setting large voxel sizes in narrow spaces causes registration failures.
* **LIO-SAM IMU Pre-integration Lag:**
  - The LIO-SAM setup suffered from misalignment due to lack of tight hardware-level synchronization between the IMU timestamp and the LiDAR timestamp. This results in rotational "ghosting" artifacts in the map when turning.
