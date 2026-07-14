# Track Specification: repo-audit-go2-slam-nav

## 1. Goal
Audit the `h-naderi/unitree-go2-slam-nav2` repository to evaluate its RTAB-Map SLAM configuration, Nav2 parameters, the `sport_ctrl` velocity bridging node, and other system frameworks (such as frontier exploration). The audit aims to capture design decisions, parameters, and frameworks to integrate into our morphological and system engineering documentation.

## 2. Requirements & Audit Scope
The audit must resolve:
* **Twist-to-SDK Bridging (`sport_ctrl.py`):** Understand the ROS 2 Twist to Unitree Go2 SDK `/api/sport/request` message conversion, watchdog/timeout safety features, and exposed services.
* **Nav2 Parameters & Costmap Tuning:** Analyze costmap layers, planning/control algorithms, and recovery behaviors in `nav2_params.yaml`.
* **RTAB-Map SLAM & ICP Odometry:** Evaluate the parameterization of `rtab_lidar.launch.py` (e.g. ICP parameters, update rates, and database management).
* **System Frameworks & Design Decisions:** Identify any external frameworks (like Frontier Exploration or facial recognition) used by the repository to add as alternatives in our morphological diagram.
* **Method Comparison & Documentation Update:** Compare these configurations with our current Go2 system specs to extract improvements.

## 3. Deliverables
* **Audit Report:** Located in `docs/literature_reviews/unitree-go2-slam-nav2/audit_report.md` detailing all findings, parameters, and framework alternatives.

## 4. Acceptance Criteria
* Audit repository `3rdparty/unitree-go2-slam-nav2` successfully analyzed.
* File `docs/literature_reviews/unitree-go2-slam-nav2/audit_report.md` contains the complete audit report.
* Morphological and system engineering insights are ready for integration.
