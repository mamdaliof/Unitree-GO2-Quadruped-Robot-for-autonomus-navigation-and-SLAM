# Troubleshooting and safety Protocol

This guide outlines safety guidelines, troubleshooting diagnostics, error codes, and FAQs for the Go2 Edu.

## 1. Critical safety Guidelines

* **LiDAR Hot-Plugging Warning:**
  * **Never hot-plug the Livox Mid-360 or Hesai XT-16 LiDAR while the robot is powered ON.** Doing so can cause permanent electrical damage to the sensor or the expansion dock. Turn off the main robot battery before connecting or disconnecting the sensor.
* **Indoor SLAM Range Constraints:**
  * The built-in mapping service is calibrated for flat indoor environments with rich feature geometries. The mapped boundary should not exceed **25 meters by 25 meters**.
* **Obstacle Heights:**
  * Due to the mounting height and LiDAR beam layout, objects lower than **20 cm** may fall inside the sensor's blind spot. Always monitor the robot when approaching small obstacles.

---

## 2. Onboard CPU Thermal & Performance Management

The Dock PC on the expansion dock has limited passive cooling:
* **Frequency Dropping:** Under prolonged heavy processing (real-time SLAM + navigation loops), the CPU may experience thermal throttling (frequency drop), which results in localization drift or lag.
* **Time Limits:** It is recommended to run active mapping and navigation tasks for **no more than 30 minutes** continuously. Allow the CPU core temperatures to return to normal before restarting.
* **Resource Optimization:** Do **NOT** run resource-heavy visualization tools like `rviz2` directly on the onboard Dock PC. Run them on a separate developer PC connected via Ethernet.

---

## 3. Damping State (Emergency Stop)

* **Function Call:** `sport_client.Damp()`
* **Damp Mode ID:** `7`
* **Behavior:** Entering damping mode instantly stops all joint motors, causing the robot to go limp.
* **Usage:** This mode has the highest execution priority. Use it as an emergency software stop if the robot behaves unpredictably.

---

## 4. Common Error Codes Reference

| Error Code | Source | Description | Resolution |
| :--- | :--- | :--- | :--- |
| **3104** | DDS Middleware | DDS command timeout. | Check Ethernet connectivity, verify IP matches `192.168.123.X`, and ensure CycloneDDS environment setup script was sourced. |
| **4101** | trajectory Planner | Wrong number of trajectory points. | Path point list must contain exactly 30 `PathPoint` entries. |
| **4201** | Locomotion Controller | Action timeout. | The commanded posture or stance adjustment took too long. Check if robot legs are obstructed. |
| **4205** | State Machine | Motion state machine not initialized. | Wait for the low-level motion controller to fully start up and stand before publishing velocity targets. |
| **4206** | Locomotion Controller | Incorrect robot attitude. | Adjust stance. Waving, sitting, or flipping actions will fail if the initial roll/pitch/yaw angles are off-center. |

---

## 5. Frequently Asked Questions (FAQ)

### Q: Why do I see empty returns from glass walls or partitions?
* **A:** LiDAR beams refract and pass through glass, resulting in either no returns or reflections. The modular design must use supplementary depth/camera filters (e.g., costmap boundaries or glass filtering nodes) to handle manufacturing setups with partition windows.

### Q: Can I run custom ROS 2 SLAM alongside the Unitree default SLAM service?
* **A:** Yes. The default SLAM service (`slam_operate`) conflicts with ROS 2 CycloneDDS and should be turned off via API command `1901` before launching custom nodes like FAST-LIO2 or LIO-SAM on the Dock PC.

### Q: What is the default password to SSH into the Dock PC?
* **A:** User: `unitree` | IP: `192.168.123.18` | Password: `123`.
