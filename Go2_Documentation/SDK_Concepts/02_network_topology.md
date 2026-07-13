# Network Topology & Configuration Modes

This document details the Go2 wireless networking architecture, including connection priorities, fallback rules, and Bluetooth pairing configurations.

---

## 1. Reference Links to Archive Sources
For original configuration screenshots and application setup workflows, refer to the archived guides:
* [Raw Network Application Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/SDK_Concepts/Robot_Dog_Application/Network_Application.md)

---

## 2. Wireless Channels & Automatic Fallbacks

The Go2 supports three independent communication interfaces:
1. **Wi-Fi AP (Access Point) Mode:** The robot radiates its own local hotspot (default name: `GO2-XXXXXX`). Allows local peer-to-peer control without external network infrastructure.
2. **Wi-Fi STA (Station) Mode:** The robot connects to an existing environmental Wi-Fi network (e.g. factory intranet). Enables remote telemetry streaming over local subnets.
3. **4G Cellular Mode:** Connects to cellular base stations via an onboard SIM IoT card. Provides remote cloud access when Wi-Fi is unavailable.

### Interface Selection Priority & Logic
To optimize bandwidth and reduce mobile data consumption, the Go2 uses an automatic network arbitrator:

```
           [Robot Boot]
                 │
                 ▼
     [Is Wi-Fi STA configured?]
         ├── Yes ──► [Try connecting to Wi-Fi STA AP]
         │                 ├── Success ──► [Use Wi-Fi STA channel (4G Idle)]
         │                 └── Timeout ──► [Fallback to 4G Cellular]
         │
         └── No ───► [Radiation Wi-Fi AP Hotspot (4G Idle)]
```

> [!WARNING]
> Only one Wi-Fi interface (AP or STA) can be active at a time. Toggling Wi-Fi STA mode off automatically turns the Wi-Fi AP hotspot on, and vice versa.

---

## 3. Bluetooth Pairing & App Configuration Workflow

Bluetooth (BLE) is used as the secure out-of-band channel to transmit network settings (SSID, Password) from the phone to the robot.

### Configuration for Unbound/New Robots
1. Open the **Unitree Go App** and click **Connect Machine Dog**.
2. Select your robot from the discovered Bluetooth device list to establish a secure link.
3. Choose your desired routing mode:
   * **AP Mode:** Enter a custom SSID name and password. The robot will reboot and generate the hotspot.
   * **STA Mode:** Scan for environmental SSIDs, select the target access point, and enter the password. The robot will reboot, turn off its hotspot, and bind to the designated Wi-Fi network.

### Configuration for Bound Robots
1. Connect your phone to the robot's local Wi-Fi subnet.
2. Go to **Settings -> Robot Settings -> Network Modes**.
3. Re-configure the SSID credentials. The app sends the parameters to the robot over the active network link.

---

## 4. Project Relevance
* **Local Subnet Setup:** In our smart inspection project, we configure the robot's Wi-Fi STA mode to bind to the manufacturing facility's local network. This allows our development computer to communicate with the onboard Jetson NX over a stable, high-bandwidth connection without relying on cellular data limits.
* **AP Mode Recovery:** If the robot is deployed to an area with weak Wi-Fi coverage, it can be forced back into AP Mode to allow immediate local override control using the mobile app or remote controller.
