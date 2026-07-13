# Networking and DDS Configuration

This guide details the network topology and DDS middleware settings required to communicate with and control the Unitree Go2 Edu robot.

## 1. Network Topology & IP Table

The robot uses a localized subnet (`192.168.123.X`) over Ethernet/Wi-Fi to route CycloneDDS messages between the different onboard systems and user PCs.

| Device | Default IP | Description |
| :--- | :--- | :--- |
| **Motion Control PC** | `192.168.123.161` | Runs the low-level motor drivers and sportmode posture controllers. |
| **Dock PC** | `192.168.123.18` | Runs the high-level SLAM, navigation, and custom user applications. |
| **LiDAR Sensor** | `192.168.123.20` | Broadcasts 3D point cloud data. |
| **User Development PC** | `192.168.123.99` | Target IP for compiling, debugging, and monitoring ROS 2 nodes. |

---

## 2. User PC Network Setup
1. Connect the development PC to the Go2 Edu robot using an Ethernet cable.
2. In the OS network settings, select **Manual IPv4** configuration:
   * **IP Address:** `192.168.123.99` (or any free IP except `.18`, `.20`, or `.161`)
   * **Netmask:** `255.255.255.0`
   * **Gateway:** (Leave blank)
3. Ping the onboard systems from the developer PC to verify connections:
   ```bash
   ping 192.168.123.18   # Ping Dock PC
   ping 192.168.123.20   # Ping Lidar
   ping 192.168.123.161  # Ping Motion Control
   ```

---

## 3. DDS Setup & Environment Script

Unitree SDK 2 relies on **Eclipse CycloneDDS** for communication. To link ROS 2 and the robot's internal DDS networks, environment variables must point to CycloneDDS and specify the correct interface card.

### Local Environment script (`~/unitree_ros2/setup.sh`)
Create this script to automate sourcing:
```bash
#!/bin/bash
echo "Configuring Unitree ROS2 & CycloneDDS environment..."

# Source ROS2 and Workspace setups
source /opt/ros/jazzy/setup.bash
source $HOME/unitree_ros2/cyclonedds_ws/install/setup.bash

# Force ROS2 to use CycloneDDS
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp

# Define the network interface card (replace 'enp3s0' with your actual ethernet card name)
export CYCLONEDDS_URI='<CycloneDDS><Domain><General><Interfaces>
                            <NetworkInterface name="enp3s0" priority="default" multicast="default" />
                        </Interfaces></General></Domain></CycloneDDS>'
```

*Note: Use `ifconfig` to find the exact name of the network interface connected to the robot, and replace `enp3s0` in the script.*

---

## 4. Off-Robot Simulation Network
If you are compiling or testing code locally without connecting to the physical robot:
* Use the local loopback card (`lo`) configuration script:
  ```bash
  source ~/unitree_ros2/setup_local.sh
  ```
