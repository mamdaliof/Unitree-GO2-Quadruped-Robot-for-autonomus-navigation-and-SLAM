# Onboard Jetson & Expansion Dock Configuration

This document covers the specifications, networking, interface repairs, OS backup/recovery, and firmware update workflows for the onboard high-performance Jetson computation module.

---

## 1. Reference Links to Archive Sources
If this documentation lacks detail or you need to download specific firmware versions, refer to the original files:
* [Raw Expansion Dock Configuration Guide](file:///home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/Go2_Documentation/archive/Application_Development/Expansion_Dock_Configuration.md)

---

## 2. Onboard Computing Hardware Specifications

The expansion dock houses either a Jetson Orin Nano or Orin NX module, powering the onboard SLAM, perception, and navigation pipelines.

| Parameter | Jetson Orin Nano 8GB | Jetson Orin NX 16GB |
| :--- | :---: | :---: |
| **AI Performance** | 40 TOPS | 100 TOPS |
| **GPU Architecture** | 1024-core Ampere | 1024-core Ampere (32 Tensor Cores) |
| **Max GPU Frequency** | 625 MHz | 918 MHz |
| **CPU Architecture** | 6-core Arm Cortex-A78AE | 8-core Arm Cortex-A78AE |
| **Max CPU Frequency** | 1.5 GHz | 2.0 GHz |
| **Deep Learning Accel** | - | 2x NVDLA v2 (614 MHz) |
| **Memory Bandwidth** | 68 GB/s | 102 GB/s |
| **Power Budget** | 7W - 15W | 10W - 25W |

---

## 3. SSH and Web Interface Access

The Dock PC acts as the high-level ROS 2 execution target.

* **Default Dock IP Address:** `192.168.123.18`
* **Username:** `unitree`
* **Password:** `123`

### Connect via SSH
```bash
# Ensure your dev PC is in the 192.168.123.X subnet
ssh unitree@192.168.123.18
```

### Connect via Web UI
Open your browser and navigate to `http://192.168.123.18`. This web console manages the deployment updates of SLAM, odometry, and low-level firmware modules.

---

## 4. Dock Interface Repair & Updates

### Type-C Power Output Recovery
If the Type-C port fails to supply power, it is usually because the GPIO enable parameter was reset by deleting `/etc/rc.local`. 

To fix this (as root):
1. Copy the template service:
   ```bash
   sudo cp /lib/systemd/system/rc-local.service /etc/systemd/system
   ```
2. Modify `/etc/systemd/system/rc-local.service` to append:
   ```ini
   [Install]
   WantedBy=multi-user.target
   Alias=rc-local.service
   ```
3. Create `/etc/rc.local` and add the startup script:
   ```bash
   #!/bin/sh
   busybox devmem 0x02430030
   busybox devmem 0x02430030 w 0x004
   echo 446 > /sys/class/gpio/export
   echo out > /sys/class/gpio/PP.06/direction
   echo 1 > /sys/class/gpio/PP.06/value
   exit 0
   ```
4. Make executable and restart:
   ```bash
   sudo chmod +x /etc/rc.local
   sudo reboot
   ```

### USB 3.0 Type-A Port Recognition Fix
By default, the older system device tree incorrectly limits the USB Type-A port to USB 2.0 speeds. To upgrade it to USB 3.0 (needed for high-speed camera sensors):
1. Download the script zip: [b8afa4618f5f479db1bc94e2c3c166f7.zip](https://doc-cdn.unitree.com/static/2025/10/10/b8afa4618f5f479db1bc94e2c3c166f7.zip)
2. Extract and enter the directory:
   ```bash
   unzip b8afa4618f5f479db1bc94e2c3c166f7.zip
   cd unitree_dt_update/
   ```
3. Execute the device tree update script and reboot:
   ```bash
   chmod +x unitree_update.sh
   sudo ./unitree_update.sh
   ```
   *Verify that the target version reports `Sep 30 2025` or newer.*

---

## 5. System Backup and Recovery (NVMe Flashing)

> [!WARNING]
> System backup and recovery require removing the internal NVMe drive from the expansion dock. Hardware damage incurred during disassembly is not covered under warranty.

### System Backup (on Host PC)
1. Remove NVMe storage drive from the Dock and insert it into a USB reader connected to your host PC.
2. Identify disk node (e.g. `/dev/sdc`) using `lsblk -f`.
3. Create compressed disk image:
   ```bash
   sudo dd if=/dev/sdc status=progress | bzip2 > nx.img.bz2
   ```

### System Recovery (on Host PC)
1. Connect the target NVMe drive to your host PC.
2. Format disk:
   ```bash
   sudo mkfs -t ext4 /dev/sdc
   ```
3. Flash the compressed image back to the drive (Requires at least 300GB disk space):
   ```bash
   bzip2 -dc nx.img.bz2 | sudo dd of=/dev/sdc status=progress
   ```

---

## 6. Official Factory Image Downloads

If you do not have a personal backup, use the official Unitree system images:
* **Go2 NX (Jetpack 5.1.1 - Sep 30, 2025):** [Google Drive Link](https://drive.google.com/file/d/1BiBXlZwAiVGgNjyPKO9qP4BiOARJrASJ/view?usp=drive_link)
* **Historical NX Image (`Nx.img.bz2`):** [Google Drive Link](https://drive.google.com/file/d/13Zwgvn_ZaG_njdk1GnlSZrXRDCubmyom/view?usp=sharing)
* **Historical Nano Image (`Nano.img.bz2`):** [Google Drive Link](https://drive.google.com/file/d/1mKN-z8uD8PUpNbrH3MIodV-nLPNK5_fy/view?usp=sharing)

---

## 7. Project Relevance
* **Compute Optimization:** The 100 TOPS (Orin NX) budget must be monitored during active navigation. Point cloud filters and SLAM nodes should be optimized to run below the thermal throttle limit.
* **USB 3.0 Fix:** Critical to implement if using external depth cameras (like Intel RealSense D435i) at full resolution and framerate.
