# Architecture Description

# System architecture diagram

![](https://doc-cdn.unitree.com/static/2025/9/3/026cde35cfe3496bb17b3fd8bdd99e05_8000x4500.jpg)

   > Go2 will only connect to cloud services after user authorization.

# Cloud Services

**Cloud services mainly have several functions:**

1. Collect Go2 operation data (not involving privacy) for fault detection and statistics.

2. Assist users in remote operations, mainly through WebRTC. Image and control traffic can be forwarded point-to-point or through a turn server, and the server will not collect or analyze these traffic.

3. System upgrade iteration.

**Communication for cloud services**:

1. mqtt is used to establish IoT communication with each robot dog, responsible for monitoring faults, system upgrades, and transmitting WebRTC signaling.

2. Connect the app and web front-end using HTTP services to establish a binding relationship between users and dogs.

3. The turn/run server is used to assist in WebRTC peer-to-peer connections and provide server data forwarding when peer-to-peer connections cannot be achieved.

# Go2

1. The OTA module communicates with the cloud server through mqtt, responsible for uploading fault information, system upgrades, and forwarding WebRTC signaling.

2. The WebRTC module implements the main data pipeline with the app, including audio and video streams, radar point clouds, motion status, and control commands.

3. The Bluetooth (BLE) section is used to establish contact with the app, mainly for configuring the network and verifying security.

4. The communication between various functional modules is mainly achieved through DDS. The DDS IDL is compatible with ROS2 (an adaptive RMW needs to be selected), and the EDU version can call the interface through DDS or ROS2.

5. Sensor data such as motor, radar, UWB, etc. are collected through serial ports and forwarded to the DDS intermediate layer.

6. EDU and above multimedia modules are designed for secondary development and support GST streaming.

# App

1. User management module, connected to the Unitree Robocits management platform through HTTP web API. Responsible for binding dog, WebRTC connection, and other functions.

2. The Bluetooth module of Go2 is used to configure the network.

3. The WebRTC module mainly implements data traffic through WebRTC, including image transmission, point cloud, motion status, and control command issuance.

# Development Interface

1. DDS, supports C++and Python.

2. ROS2 interface.

3. GST, only for image transmission.
