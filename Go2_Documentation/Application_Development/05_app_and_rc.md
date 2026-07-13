# Mobile App & Screen Remote Controller

This document details the configuration workflows for the Unitree Go App and the screen-equipped remote controller, including voice alerts, thermal gimbal controls, and subnet IP mappings.

---

## 1. Reference Links to Archive Sources
If this documentation lacks detail or you need to inspect raw interface images, refer to the original files:
* [Raw App Binding Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Application_Development/App_Binding.md)
* [Raw TouchScreen RC Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Application_Development/TouchScreen_RC_Supporting_Instructions.md)

---

## 2. Unitree Go App Connections & Controls

The Unitree Go App is used to bind the robot via Bluetooth and toggle active background processes.

### App Connection Modes
* **AP Router Mode (Hotspot):** 
  * The robot generates an AP hotspot (`GO2-XXXXXX`). Connect your phone to this network using the default 8-digit password.
* **Wi-Fi Router Mode:** 
  * Link both the robot and your phone to an external router network segment. Useful for monitoring the robot while maintaining internet access.

### Process Service Status
Under **App -> Device -> Service Status**, developers can monitor background processes and disable the default movement node (`mcf`/`sport_mode`/`wheeled_sport`) to allow custom SDK controls.

---

## 3. TouchScreen Remote Controller Setup

The touchscreen controller maps to the standard joysticks and communicates over a separate subnet (`192.168.144.X`).

### Unlocking Control (Critical Startup Step)
> [!IMPORTANT]
> After booting the robot and standing it upright, you must **turn the right wheel switch (START) to the right** to unlock controller inputs. The joysticks and buttons remain locked until this action is completed.

### Compatible Accessories & Floating App Windows
When using smart payloads (dual cameras, warning lights, text-to-speech module), double-click the **Smart Load** app on the remote desktop to initialize the receiver. The following controls are mapped to floating windows:
1. **Voice Broadcast:** Play real-time audio from the remote controller microphone or select preset alert sounds.
2. **Text-To-Speech (TTS):** Input text messages for translation into spoken warnings at the robot's speakers.
3. **Audio Recorder:** Record, save, and upload custom audio clips.
4. **Flashing Warning Lights:** Toggles the spotlight and triggers the red/blue emergency flashing warning lights.

### Dual-Camera Thermal Imaging Gimbal
* Run the **SIYI FPV** app and input IP address `192.168.144.29`.
* Swipe up, down, left, or right on the remote controller touchscreen to adjust gimbal angles.

---

## 4. Subnet IP Addresses Mappings (`192.168.144.X`)

The remote controller network operates on the `144` subnet. Ensure custom payloads do not conflict with these hardcoded IPs:

| IP Address | Device Name |
| :--- | :--- |
| **192.168.144.11** | Sky End |
| **192.168.144.12** | Ground End |
| **192.168.144.20** | Remote Controller |
| **192.168.144.23** | Three-in-One Voice Module |
| **192.168.144.25** | Front Camera (Camera 1) |
| **192.168.144.26** | Rear Camera (Camera 2) |
| **192.168.144.29** | Dual-Camera Thermal Imaging Gimbal |

---

## 5. Troubleshooting Remote Anomalies

* **Controller Buttons Unresponsive:** Verify that the right wheel has been clicked/turned to the right. Check if **Low Battery Mode** is enabled on the remote OS (System Settings -> Battery Management -> Turn off Low Battery Mode) as this disables key wireless receivers.
* **Smart Load Connection Failures:** If the floating overlay fails to load after 30 seconds, restart the remote controller.

---

## 6. Project Relevance
* **Dynamic Warning Alerts:** Our autonomous inspection machine can use the text-to-speech API or the red/blue flashing lights to signal dynamic obstacles or manufacturing safety hazards during patrol runs.
* **Safety Lockout:** Knowing the right wheel unlock sequence is essential to manually take control and override autonomous navigation if a software crash occurs.
