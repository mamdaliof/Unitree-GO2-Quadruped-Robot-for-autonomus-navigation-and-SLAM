# SDK Installation & Development Environment Setup

This document describes how to configure your developer computer's network interface, compile the `unitree_sdk2` library, and run the basic low-level examples.

---

## 1. Reference Links to Archive Sources
If this documentation lacks detail or you need to inspect raw installation scripts, refer to the original files:
* [[Go2_Documentation/archive/Application_Development/Obtain_SDK|Raw Obtain SDK Guide]]
* [[Go2_Documentation/archive/Application_Development/Quick_Start|Raw Quick Start Guide]]

---

## 2. System and Dependency Requirements

### Host Operating System
* **Recommended System:** Ubuntu 20.04 or Ubuntu 22.04.
* **Limitations:** macOS, Windows, and direct development on the internal Go2 computer are not supported for compilation.

### Toolchain Dependencies
Before installing the SDK, run the following command to install the required compilation libraries:
```bash
sudo apt update
sudo apt install cmake gcc build-essential libeigen3-dev
```

---

## 3. Downloading & Compiling `unitree_sdk2`

The SDK provides the low-level motor FOC wrappers and high-level `sport_client` APIs.

* **GitHub Repository:** [https://github.com/unitreerobotics/unitree_sdk2](https://github.com/unitreerobotics/unitree_sdk2)

### Standard Installation
Compile and install the library headers and binaries globally:
```bash
cd ~/unitree_sdk2/
mkdir build && cd build
cmake ..
sudo make install
```

### Custom Directory Installation (Recommended for ROS 2)
To keep the system libraries clean, you can install the SDK to a custom path (e.g., `/opt/unitree_robotics`):
```bash
cmake .. -DCMAKE_INSTALL_PREFIX=/opt/unitree_robotics
sudo make install
```

---

## 4. Network Configuration (The '123' Subnet)

To communicate with the robot's onboard computers, the developer PC must reside on the `192.168.123.X` subnet.

### Ethernet Card Adapter IP Configuration
1. Connect an Ethernet cable between the robot and your development computer.
2. In the OS network card configurations, set the IP manually:
   * **IPv4 Address:** `192.168.123.222` (Ensure you do **not** use `192.168.123.161` as it is reserved for the robot's main computer).
   * **Netmask:** `255.255.255.0`
3. Verify connection:
   ```bash
   ping 192.168.123.161
   ```

### Finding the Network Adapter Name
Run `ifconfig` in the terminal to find the specific adapter name bound to IP `192.168.123.222` (for example, `enxf8e43b808e06`):
```bash
ifconfig
```
Record this adapter name as it is a required execution argument for all compiled binaries.

---

## 5. Compiling and Running SDK Examples

SDK examples generate binary files under `build/bin/`.

### Compile Examples
```bash
cd ~/unitree_sdk2
mkdir build && cd build
cmake ..
make
```

### Run Low-Level example (`go2_low_level`)
This example commands the robot's front right leg to swing rhythmically.

> [!WARNING]
> Ensure the Go2 robot's legs are **fully suspended off the ground** (suspended by a harness or rack) before running low-level joint tests. This prevents the robot from falling or jumping unpredictably.

```bash
cd ~/unitree_sdk2/build/bin
./go2_low_level [Network Interface]  # e.g., ./go2_low_level enxf8e43b808e06
```

---

## 6. Project Relevance

* **Subnet Coordination:** Our custom ROS 2 nodes must bind to the correct network adapter name identified via `ifconfig` to subscribe to point clouds or publish motion commands.
* **Low-Level Disabling:** Before running custom motor-control nodes, the default motion services (`mcf` or `sport_mode`) must be disabled to prevent signal collisions.
