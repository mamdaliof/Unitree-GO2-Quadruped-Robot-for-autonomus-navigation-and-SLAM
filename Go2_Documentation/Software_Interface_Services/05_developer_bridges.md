# Developer Bridges: ROS 2, Python & DDS Configurations

This document details configuring the ROS 2 Jazzy interface, Python bindings, and the CycloneDDS network card configuration parameters.

---

## 1. Reference Links to Archive Sources
For original script lines and raw XML configuration schemas, refer to the archived guides:
* [[Go2_Documentation/archive/Software_Interface_Services/ROS2_Services_Interface|Raw ROS2 Services Interface Guide]]
* [[Go2_Documentation/archive/Software_Interface_Services/Python_Services_Interface|Raw Python Services Interface Guide]]
* [[Go2_Documentation/archive/Software_Interface_Services/DDS_Services_Interface|Raw DDS Services Interface Guide]]

---

## 2. ROS 2 Workspace Setup (Jazzy)

The Go2 Edu onboard system runs Ubuntu 24.04 and ROS 2 Jazzy.

* **Repository:** [https://github.com/unitreerobotics/unitree_ros2](https://github.com/unitreerobotics/unitree_ros2)

### Compiling the Workspace
1. Clone the package into your ROS 2 workspace src folder:
   ```bash
   cd ~/ros2_ws/src
   git clone https://github.com/unitreerobotics/unitree_ros2.git
   ```
2. Build the message interfaces first:
   ```bash
   cd ~/ros2_ws
   colcon build --packages-select unitree_go
   source install/setup.bash
   ```
3. Compile the remaining nodes:
   ```bash
   colcon build --symlink-install
   ```

### Launching the ROS 2 Driver Node
To bridge DDS topics to standard ROS 2 publishers and subscribers:
```bash
ros2 launch unitree_nav sport_mode_launch.py
```
This node subscribes to standard geometry velocity topics (`/cmd_vel`) and translates them to `rt/lowcmd` and `rt/sportmode` commands internally.

---

## 3. Python Service Bindings

The SDK provides a Python module (`unitree_sdk2py`) that wraps the C++ channels using ctypes.

* **Repository:** [https://github.com/unitreerobotics/unitree_sdk2_python](https://github.com/unitreerobotics/unitree_sdk2_python)

### Python Installation
```bash
cd ~/unitree_sdk2_python
pip install -e .
```

### Python SDK Hello World Example
```python
import time
import sys
from unitree_sdk2py.common.channel import ChannelFactory
from unitree_sdk2py.go2.sport.sport_client import SportClient

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} networkInterface")
        sys.exit(-1)
        
    # Bind to network interface (e.g. eth0)
    ChannelFactory.Initialize(0, sys.argv[1])
    
    # Instantiate client
    sc = SportClient()
    sc.Init()
    
    # Stand Up
    sc.StandUp()
    time.sleep(3)
    
    # Lie Down
    sc.StandDown()
```

---

## 4. CycloneDDS Configuration (`cyclonedds.xml`)

Because the robot communicates across multiple subnets, CycloneDDS must be configured to bind to the correct network adapter interface and manage multicast limits.

### Configuration File (`/home/unitree/cyclonedds_ws/cyclonedds.xml`)
Create or edit the XML file on the host computer:
```xml
<?xml version="1.0" encoding="UTF-8" ?>
<CycloneDDS xmlns="https://cdds.allocator.nl" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="https://cdds.allocator.nl http://cdds.allocator.nl/schema/TypeSupport.xsd">
    <Domain id="any">
        <General>
            <NetworkInterfaceAddress>enxf8e43b808e06</NetworkInterfaceAddress> <!-- Edit to match your network adapter name -->
            <AllowMulticast>true</AllowMulticast>
            <MaxMessageSize>65500B</MaxMessageSize>
        </General>
    </Domain>
</CycloneDDS>
```

### Export the configuration path
Export the environment variable in your `~/.bashrc`:
```bash
export CYCLONEDDS_URI=/home/unitree/cyclonedds_ws/cyclonedds.xml
```

---

## 5. Project Relevance
* **Multi-language Architecture:** We write high-level state machine decisions in Python using `unitree_sdk2py`, while performance-critical SLAM and LiDAR filtering algorithms are compiled in C++ under the ROS 2 Jazzy workspace.
