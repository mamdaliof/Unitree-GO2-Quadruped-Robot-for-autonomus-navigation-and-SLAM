---
aliases: ["Topic: Autonomous Navigation & Localization in Industrial Environments", "Project: Learning Factory"]
created: ["01-06-2026 10:00"]
tags:
- Meeting/LearningFactory
---

# 🚀 Meeting -> Autonomous Navigation & Localization in Industrial Environments for Quadruped Robots

---
## 📢 - Project information
Created:: 01-06-2026 10:00
Deadline:: 
Hibernating:: 
Completion date expected:: 
Completed:: 
Type:: Technical Sync / Progress Review
Tags:: #domain/robotics #domain/ml #project/learning-factory #domain/slam
Platform:: In-person
Meeting Members :: Farhad Hoseyni, Dr. Poorya Ghafoorpoor Yazdi, MSc. Leicai Xiao

# 📅 - Agenda
1. Review objectives and scope of Leicai's Master Assignment II.
2. Address core research questions: Why SLAM? Why quadruped (dog bot)? Why dog + SLAM? Why LiDAR?
3. Discuss technical limitations of the default Unitree Go2 (GO2x) SDK / built-in navigation packages.
4. Distinguish between localization and navigation.
5. Identify tools, technologies, and strategies for industrial navigation.
6. Detail validation and testing plans.

# 🎯 - Goals
1. Establish a clear rationale for the robotic platform (quadruped) and sensing modality (LiDAR-based SLAM).
2. Justify why bypassing the proprietary Go2 built-in navigation is necessary (due to the "black box" limitations).
3. Align on the differences between localization and navigation.
4. Define concrete test sites and environments for validation.

# 📝 - Discussion notes

### 1. Platform and Technology Rationale (The "Why" Questions)
During the meeting, the team audited the choice of platform and sensors, addressing key conceptual questions:
- **Why SLAM (Simultaneous Localization and Mapping)?**
  - Traditional infrastructure-dependent systems (e.g., UWB beacons, GPS, RTLS, or physical reflectors) are difficult and costly to deploy in dynamic industrial environments. GPS signals are unavailable or highly degraded indoors. SLAM enables infrastructure-independent navigation, allowing the robot to map and navigate unknown areas on the fly.
- **Why a Quadruped Robot (DOG bot)?**
  - Wheeled AGVs (Automated Guided Vehicles) and carriers struggle with rough terrain, steps, stairs, hanging cables, and floor debris common in manufacturing plants.
  - Aerial systems (drones) have short battery life, strict payload constraints, air distribution issues, and represent high collision/safety risks in indoor spaces.
  - Quadruped platforms offer superior legged locomotion, enabling them to climb stairs, step over obstacles, and traverse cluttered industrial layouts with a small footprint and high agility.
- **Why Dog and SLAM?**
  - Combining a quadruped's physical mobility with the autonomy of SLAM creates a fully autonomous, infrastructure-free mobile sensor platform capable of inspecting complex, multi-level plants without altering the existing facility.
- **Why LiDAR?**
  - Industrial plants are harsh environments with low light, dust, reflective metallic surfaces, or variable lighting. Visual SLAM (cameras) struggles under these conditions. LiDAR (Light Detection and Ranging) provides active sensing via laser pulses, generating accurate 3D geometric point clouds robust to lighting variations.

### 2. Limitations of Unitree Go2 Built-in Program (GO2x)
- The built-in navigation and mapping packages provided by Unitree (`unitree_slam`) act as a closed-source **"black box."**
- Internal algorithms cannot be modified, which prevents custom optimization and debugging of drift, rotation slip, or mapping failures.
- The default system is officially designed for small, flat, static indoor spaces (under 25m x 25m). It is unstable in dynamic, large-scale, or multi-level industrial zones.
- **Decision**: Bypass the proprietary `unitree_slam` service and access raw sensor data (LiDAR point clouds, IMU, odometry) via the ROS 2 SDK to implement custom, open-source SLAM algorithms (e.g., LIO-SAM, FAST-LIO2, or SLAM Toolbox).

### 3. Navigation vs. Localization
- **Localization**: Determining the robot's pose (position and orientation) within a frame. It does not strictly require an environmental map beforehand (e.g., odometry or raw IMU tracking, or using external markers like UWB).
- **Navigation**: The complete ability to traverse from point A to point B. This requires knowing the environment (having a map) to plan paths, avoid dynamic obstacles, and make intelligent routing decisions. SLAM integrates both: localizing the robot while simultaneously building/updating the environmental map.

### 4. Tools, Technologies, and Approaches
- **Localization & Navigation Strategies**:
  - Investigating active-sensing SLAM algorithms (LiDAR SLAM vs. Visual SLAM vs. Thermal SLAM).
  - Alternative localization technologies (such as tag-based UWB) can aid navigation but lack the flexibility of LiDAR SLAM.
- **Target Interface**:
  - Leicai Xiao is to specify the integration requirements and parameters for the quadruped robot navigation user interface.
- **Industrial Environment Constraints**:
  - Indoor settings that are highly complex, dynamic, and harsh.

### 5. Validation and Testing Plan
The proposed navigation strategies must be validated across three physical sites of varying complexity:
1. **UT Learning Factory (Cube)**: Testing in a semi-controlled, smart-factory environment.
2. **Cube Basement**: A darker, more challenging environment to test sensor robustness (LiDAR and thermal) and localization drift.
3. **AMC Fraunhofer (FIP - Fraunhofer Innovation Platform)**: High-fidelity industrial environment to evaluate practical performance, obstacle avoidance, and path planning.

# 💠 - Action items
- [ ] **Technical Specification**: Leicai to outline specific user interface requirements for robot navigation.
- [ ] **SLAM Selection**: Investigate and evaluate specific LiDAR SLAM algorithms (e.g., FAST-LIO2, LIO-SAM) for localization accuracy.
- [ ] **Environment Setup**: Set up ROS 2 packages to interface with Go2 raw sensors.
- [ ] **Validation Prep**: Prepare test protocols and parameters for testing at UT Learning Factory, Cube Basement, and AMC Fraunhofer.

---
# 📎 - Attachments & References
- **Leicai's Report**: [[02-Projects/learning-factory-project/meetings/attachments/Master assignment II - Autonomous Navigation in Industrial Environments for Quadruped Robots -LeicaiXiao.pdf|Leicai's Report]] / [Markdown Link](attachments/Master%20assignment%20II%20-%20Autonomous%20Navigation%20in%20Industrial%20Environments%20for%20Quadruped%20Robots%20-LeicaiXiao.pdf)
- **Meeting 1 Notes**: [[02-Projects/learning-factory-project/meetings/attachments/Notes_meeting1_Poorya_Farhad.pdf|Meeting 1 Notes]] / [Markdown Link](attachments/Notes_meeting1_Poorya_Farhad.pdf)
- **Related Project**: [[02-Projects/learning-factory-project/_overview|Project Overview]]
- **Devlog**: [[02-Projects/learning-factory-project/_dev-log|Devlog]]
