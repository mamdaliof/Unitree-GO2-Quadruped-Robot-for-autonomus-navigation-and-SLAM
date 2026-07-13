# Go2 Developer Documentation Index

This directory contains the cleaned, restructured developer documentation for the Unitree Go2 Edu robot. It is designed to be highly legible for both humans (structured headings, tables, clean links) and LLMs (highly structured key-value configurations, clear syntax details, and an API reference JSON).

## Table of Contents

* **[[01_networking_and_dds.md]]** - Jetson and Dock PC network interfaces, DDS domain coordination, and CycloneDDS setup scripts.
* **[[02_ros2_integration.md]]** - ROS 2 Jazzy/Humble distributions, workspace compilation workflows, and topic names mapping.
* **[[03_lidar_and_pointclouds.md]]** - Raw and deskewed point cloud topics, height maps, range info message fields, and subscription examples in C++.
* **[[04_slam_and_navigation_api.md]]** - Transform matrices for LiDAR-to-IMU coordinate frames, the `slam_operate` JSON service APIs, and simulation warnings.
* **[[05_motion_control_and_state.md]]** - Sportmode high-level movement clients, low-level motor command structs, gait enumeration tables, and C++ control examples.
* **[[06_troubleshooting_and_faq.md]]** - Critical safety guidelines, damping states, CPU frequency throttling, and general FAQ resources.

## LLM Direct Reference Index
For direct structured context lookup by AI agents:
* **[[go2_sdk_api_reference.json]]** - Machine-readable registry of topics, message schemas, API IDs, and configurations.

## Original Documentation Archive
* **[[archive/README.md]]** - Index of the raw, untouched developer documentation files.
