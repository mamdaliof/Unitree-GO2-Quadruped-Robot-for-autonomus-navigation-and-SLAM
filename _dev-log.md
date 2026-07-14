### 2026-05-20 — Project Kick-off & Proposal
- **Meeting**: [[02-Projects/meetings/2026-05-20 - Learning Factory Project Proposal|Meeting with Poorya and Leicai]].
- **Action**: Defined project scope for autonomous industrial inspection.
- **Decision**: Adopt Morphological Solution for research mapping.
- **Next Steps**: Conduct literature review and justify platform (Why dog?).

### 2026-06-01 — Meeting on SLAM & Quadruped Navigation
- **Meeting**: [[02-Projects/learning-factory-project/meetings/2026-06-01-meeting-poorya-leicai|Meeting with Poorya and Leicai]].
- **Action**: Detailed platform and technology selection (Why quadruped, SLAM, LiDAR, Go2 SDK constraints).
- **Decision**: Bypass default Unitree Go2 SDK closed-source mapping in favor of custom ROS 2 LiDAR SLAM (e.g., LIO-SAM/FAST-LIO2).
- **Next Steps**: Define user interface parameters (Leicai) and prepare for validation tests at Cube, basement, and AMC.

### 2026-07-13 — System Engineering Baselines & State Machine Decoupling
- **Actions**:
  - Restructured raw documentation archives into a modular format with Obsidian Wikilinks.
  - Created root-level configuration [[go2_config.json]], [[docs/requirements/system_requirements|system_requirements]], and [[docs/requirements/validation_matrix|validation_matrix]].
  - Built visual State Machine diagrams in [[docs/state_machines/system_state_machine.canvas|Obsidian Canvas]] and [[docs/state_machines/system_state_machine.drawio|Draw.io]] formats.
  - Cloned and audited `jizhang-cmu/autonomy_stack_go2` repo; extracted Point-LIO transforms, IMU calibration prerequisites, and self-reflection filters.
- **Decisions**:
  - Decoupled mapping from patrol navigation. Added `SIT_STANDBY` fallback for calibration fail. Routed charging exit to `INITIALIZATION`.

### 2026-07-14 — Literature Review & Change Proposals
- **Actions**:
  - Reviewed the research paper [[literature/Robot Type/Mobile Structural Health Monitoring Based on Legged Robots|Mobile Structural Health Monitoring Based on Legged Robots]] detailing vibration sensing and overlapping normalization.
  - Created [[docs/literature_reviews/autonomy_stack_go2/cmu_autonomy_stack_overview|CMU Stack Architecture Overview]] and [[docs/literature_reviews/autonomy_stack_go2/real_robot_tutorial|Real-Robot Tutorial Guide]].
  - Prepared modification proposals at the top of the core configuration files for user review.

### 2026-07-14 — APPROVED SENSOR CHANGES & CALIBRATION SETUP DECOUPLING
- **Actions**:
  - Me discard repository tilt of 15.1 degrees. Keep catalog value of 13.0 degrees. User will calculate actual physical tilt angle.
  - Me add distinct calibration phase for IMU, LiDAR, and cameras.
  - Me add setup run once phase to check accuracy: static IMU drift check, 1-meter walk check, and rotation check.
  - Me add perception self-filter box to discard point cloud returns on legs and chassis.
  - Me update [[docs/requirements/system_requirements|system_requirements.md]], [[docs/requirements/validation_matrix|validation_matrix.md]], and [[go2_config.json]].

