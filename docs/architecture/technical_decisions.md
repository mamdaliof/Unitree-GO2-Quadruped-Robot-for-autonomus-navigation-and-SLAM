# Technical Decisions & Research Report

This document compiles the research, brainstorming of alternative methods, compatibility with the latest Unitree Go2 SDK, and detailed trade-off analysis tables for the key architectural decisions in the Go2 navigation and SLAM stack.

---

## 1. Locomotion Mode Lock vs. Dynamic Height/Pitch Estimation

To mitigate point cloud distortion and SLAM drift caused by the robot's dynamic walking movements:
### Alternative Methods Researched
1. **Locomotion Mode Lock (Normal Mode):** Forcing the robot's locomotion controller into a stable, non-adaptive gait (Normal Mode) using the Unitree Sport SDK (API ID `1001` / `1008` / SwitchGait). This locks the stand height and stabilizes the chassis pitch/roll angles.
2. **Dynamic Base Link TF Estimation (Joint Kinematics):** Subscribing to the high-frequency joint state encoders (`/rt/lowstate` joint angles) and using forward kinematics to dynamically calculate the leg heights, body pitch, and roll offsets relative to the floor. The coordinate transformation matrix $T_{base\_link \to base\_footprint}$ is updated continuously.
3. **Intrinsic LIO Gravity Alignment:** Relying entirely on tightly-coupled LiDAR-IMU Odometry (e.g., FAST-LIO2 or Point-LIO) to dynamically track the 6-DoF state (including pitch, roll, and height fluctuations) without stabilizing the robot's locomotion or joint tf.
### Compatibility with Latest Go2 SDK
* The latest Go2 SDK fully supports locking locomotion via the `SportClient` and the `MotionSwitcherClient` (MCF Service V2.0). 
* By invoking `switcher.SetSilent(true)`, the default motion control loop is disabled, allowing developer nodes to lease control and command custom stance heights or gaits using `BalanceStand()` and `Euler()`. 
* Gait switches (`Trot`, `StaticWalk`) can be commanded via `SportClient::SwitchGait(gait)` or direct topic republishing to `/api/sport/request` (API ID `1012`).

### Trade-off Analysis Table
| Decision Criteria | Option 1: Locomotion Normal Lock | Option 2: Dynamic base_link TF | Option 3: Intrinsic LIO Alignment |
| :--- | :--- | :--- | :--- |
| **SLAM Drift** | **Low:** Stabilized sensor base minimizes high-frequency scan matching noise. | **Medium:** Sensor noise is corrected but kinematic latency can introduce minor errors. | **Low:** Tightly-coupled IMU integration tracks high-frequency changes. |
| **Computational Cost** | **Zero:** Simple startup command sent via DDS. | **Medium:** High-frequency forward kinematics loop on Jetson. | **High:** Complex Kalman Filter/optimization updates on point clouds. |
| **Terrain Versatility** | **Low:** Locked height/gait cannot climb stairs or navigate rough rubble. | **High:** Dynamically adapts to uneven ground. | **High:** Works on all terrains supported by the walking controller. |
| **Risk of Collision** | **Low:** Predictable gait and sensor height. | **Medium:** High-frequency joint noise can cause false obstacle projections. | **Low:** True 6-DoF tracking. |
| **Implementation Effort** | **Very Low:** Single DDS command call. | **High:** Full URDF/joint subscriber and kinematics math. | **Medium:** Parameter tuning of existing LIO package. |

* **Final Decision:** **Use Option 1 (Locomotion Normal Lock) for Phase 1** mapping in structured environments (Cube, basement) to ensure clean map generation.
  * **Dynamic Locomotion Mode Switching:** To navigate stairs or high obstacles, the state machine or path follower node can temporarily release/turn off the Normal Mode Lock (transitioning back to Agile Gait Mode or Climb Mode) and automatically re-engage the lock once the obstacles are cleared.
  * **Phase 2 Exploration:** **Investigate Option 3 (Intrinsic LIO Alignment) for Phase 2** to support rougher active factory floors (AMC) where walking gaits must continuously adapt.

---

## 2. Hardware PTP/NTP vs. Software Timestamp Offset Estimation

To prevent rotational "ghosting" artifacts in SLAM, the LiDAR point cloud and IMU data must be precisely synchronized.

### Alternative Methods Researched
1. **Linux PTP (IEEE 1588):** Configuring the companion Jetson and the Livox LiDAR on the same subnetwork using a PTP daemon (`ptpd` or `linuxptp`). The Jetson acts as the PTP master, and the LiDAR synchronizes its internal clock to sub-microsecond accuracy.
2. **Software Timestamp Offset Estimation:** Calculating the time difference at node bringup by measuring network round-trip time (RTT) and dynamically adding a static/rolling time offset (as done in CMU's `transform_everything.py` startup offset).
3. **NTP Time Synchronization:** Using Network Time Protocol (NTP) to synchronize the Jetson and LiDAR clocks via an external local router NTP server.

### Compatibility with Latest Go2 SDK & Sensors
* **Livox Mid-360:** Fully supports IEEE 1588 PTP synchronization. The synchronization mode can be configured to PTP in the Livox LiDAR config file.
* **Unitree Onboard Jetson:** Running standard Ubuntu Linux, which natively supports `linuxptp` and `ptpd` configuration.

### Trade-off Analysis Table
| Decision Criteria | Option 1: Hardware PTP (IEEE 1588) | Option 2: Software Offset Estimation | Option 3: NTP Sync |
| :--- | :--- | :--- | :--- |
| **Time Sync Accuracy** | **Sub-microsecond (< 1 µs):** Extremely precise hardware alignment. | **Millisecond-level (~5-10 ms):** Subject to network jitter. | **Millisecond-level (~1-5 ms):** Subject to routing latency. |
| **SLAM Ghosting Risk** | **Zero:** Scan points align perfectly during fast rotations. | **Low to Medium:** Sudden turns can cause minor mapping artifacts. | **Medium:** Network load spikes cause sync drift. |
| **Configuration Complexity**| **High:** Requires setting up host daemons (`ptpd`) and config files. | **Low:** Single Python helper node calculates offset on boot. | **Medium:** Requires local NTP server and router config. |
| **Hardware Dependency** | **None:** Direct ethernet cable link. | **None:** Software-based. | **High:** Requires router/NTP master on the physical stack. |

* **Final Decision:** **Option 1 (Hardware PTP) is the primary method** for physical deployments. **Option 2 (Software Offset Estimation) is the fallback option** implemented in the simulation/mock workspace configuration when PTP setup is unavailable.

---

## 3. ROS 2 Twist Bridge vs. Custom DDS Client Republisher

To bridge velocity commands between standard ROS 2 navigation packages (Nav2) and the Unitree Go2 SDK:

### Alternative Methods Researched
1. **Unified OOP Interface Class:** Creating abstract base interfaces where the control class `ControlInterface` is subclassed into `SimControl` (publishing standard `geometry_msgs/msg/TwistStamped`) and `RealControl` (sending DDS `SportClient` commands).
2. **Parameter-Switched Republisher Node:** A single ROS 2 C++ or Python node (`sport_ctrl.py` or `vel_ctrl_repub.cpp`) that subscribes to `/cmd_vel` and republishes commands either to simulator `/cmd_vel` or the `/api/sport/request` topic based on the `is_real_robot` flag.
3. **Separate Custom Driver Packages:** Maintaining separate software stacks and packages entirely for simulation (`go2_sim_control`) and physical deployment (`go2_real_control`).

### Trade-off Analysis Table
| Decision Criteria | Option 1: Unified OOP Interface | Option 2: Parameter-Switched Node | Option 3: Separate Packages |
| :--- | :--- | :--- | :--- |
| **Code Maintainability** | **High:** Core business logic is isolated from hardware details. | **Medium:** Single file handles two different protocols; can get messy. | **Low:** Code duplication across duplicate packages. |
| **Execution Performance** | **High:** Direct C++ virtual method calls. | **Medium:** Node adds extra pub-sub hop latency. | **High:** Native direct compilation. |
| **Ease of Testing** | **High:** Mock subclasses can be easily injected for unit tests. | **Medium:** Requires launching the full node and checking topic streams. | **Low:** Testing must be replicated across two projects. |
| **DDS Resource Overhead** | **Low:** No additional nodes or topics. | **Medium:** Spawns an extra active ROS 2 node. | **Low:** Native nodes. |

* **Final Decision:** **Option 1 (Unified OOP Interface Class) is selected** as the core C++ architectural standard.
  * **Parameter-Driven Publishing:** The interface and active control wrappers must be governed by two configuration parameters: `publish_ros_twist` and `publish_unitree_dds`. 
    - If `publish_ros_twist` is true, publish standard Twist topics.
    - If `publish_unitree_dds` is true, publish Unitree Sport SDK DDS request packets.
    - If both are true, publish both streams simultaneously; if both are false, suppress all outputs.

---

## 4. Bounding Box Self-Filtering Bounds

To prevent the robot from mapping its own feet and body as obstacles, a spatial filter is required.

### Rationale and Sensor Range Considerations
* **Minimum Sensor Range vs. Leg Proximity:** Although some built-in LiDAR sensors may have blind spots, the primary 3D LiDAR has a very short minimum detection range. Because it is mounted on top of the robot and scans downwards in a hemispherical field of view, the robot's own legs and chassis links fall directly within its active range and scanning path.
* **SLAM Obstacle Confusion:** Without a self-filtering filter, SLAM scan-matching and costmap planning will register the robot's own moving legs as static obstacles. This results in navigation blocks and mapping failures. Hence, a self-filter is critical for both the built-in and top-mounted sensors.

### Candidate Options
1. **Chassis Bounding Box (Livox pointcloud filtering):** Discarding all points within fixed spatial bounds relative to `base_link`:
   * $x \in [-0.7, -0.1]$
   * $y \in [-0.3, 0.3]$
   * $z \in [-0.6, 0.0]$ (Subject to calibration updates).
2. **URDF Self-Collision Filter:** Using standard ROS 2 self-filter packages (e.g. `robot_self_filter`) that dynamically track joint state URDF links to construct dynamic collision collision meshes and discard intersecting LiDAR points.

### Trade-off Analysis Table
| Decision Criteria | Option 1: Fixed Bounding Box | Option 2: URDF Dynamic Filter |
| :--- | :--- | :--- |
| **CPU Footprint** | **Very Low:** Simple coordinate boundary check per point. | **High:** Continual ray-to-mesh intersection checks. |
| **Filtering Accuracy** | **Medium:** Can discard valid ground points close to legs. | **High:** Discards only points hitting the actual physical leg links. |
| **Implementation Effort** | **Very Low:** Ten lines of code in perception node. | **High:** Requires complete URDF meshes and joint state sync. |

* **Final Decision:** **Option 1 (Fixed Bounding Box) is the baseline** for Phase 1. If leg reflections cause navigation errors, Option 2 will be investigated in subsequent phases.

---

## 5. Kidnap Detection and Recovery Thresholds

If the robot slips or is physically moved ("kidnapped"), SLAM must detect the mismatch to prevent map corruption.

### Candidate Options
1. **ICP Registration Fitness Score Threshold:** Monitoring the fitness score returned by Open3D ICP registration. If fitness falls below `threshold_fitness` (e.g., 0.9), lock map updates and warn.
2. **Odometry covariance disparity:** Comparing the covariance error output of the LIO high-frequency odometry against the ICP alignment displacement. If the difference exceeds a threshold, trigger kidnap state.
3. **Manual Operator Re-localization:** Disable automatic recovery and halt navigation, requiring the user to publish a new estimated position via RViz `/initialpose`.

* **Final Decision:** **Option 1 (ICP Registration Fitness Score < 0.9) is the primary fallback** to trigger safety stop and raise warnings. Option 3 is used to recover the localized position.
