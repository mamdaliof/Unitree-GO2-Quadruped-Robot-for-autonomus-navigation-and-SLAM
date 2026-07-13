# Expansion Dock Configuration

# Comparison of Jetson Module Specifications

|  | Jetson Orin Nano 8GB | Jetson Orin NX 16GB |
| :-: | :-: | :-: |
| AI Performance | 40 TOPS | 100TOPS |
| GPU |1024-core NVIDIA Ampere architecture GPU with Tensor Cores| 1024-core NVIDIA Ampere architecture GPU with 32 Tensor Cores |
| Maximum GPU Frequency | 625 MHz | 918 MHz |
| CPU |6-core Arm® Cortex®-A78AE v8.2 64-bit CPU 1.5MB L2 + 4MB L3 | 8-core Arm® Cortex® A78AE v8.2 64-bit CPU 2MB L2 + 4MB L3|
| Maximum CPU Frequency | 1.5 GHz | 2 GHz |
| DL Accelerator | - | 2x NVDLA v2 |
| Maximum DLA Frequency | - | 614 MHz |
| Vision Accelerator |  | 1x PVA v2 |
| Memory |8GB 128-bit LPDDR5 68 GB/s | 8GB 128-bit LPDDR5 68 GB/s |
| Storage | (Supports external NVMe) | (Supports external NVMe) |
| Video encoding | 1080p 30, supported by 1-2 CPU cores | 1x 4K60 (H.265)</br>3x 4K30 (H.265)</br>6x 1080p60 (H.265)</br>12x 1080p30 (H.265) |
| Video Decode | 1x 4K60 (H.265)</br>2x 4K30 (H.265)</br>5x 1080p60 (H.265)</br>11x 1080p30 (H.265)</br>| 1x 8K30 (H.265)</br>2x 4K60 (H.265)</br>4x 4K30 (H.265)</br>9x 1080p60 (H.265)</br>18x 1080p30 (H.265)|
| Power consumption |7W - 15W | 10W – 25W |

# Connecting Display Screen

Insert the Type-C to HDMI adapter into the Type-C full-function interface of the docking station, and use the display screen connecting cable to connect the display screen.

The network IP of Go2 docking station is 192.168.123.18. The system username for the docking station is Unitree, and the password is 123.

![](https://doc-cdn.unitree.com/static/2023/12/5/77a94d53ee404f68a25d7c4a47735040_5281x2511.png)

After successful connection, open your browser and you can access the docking station using the following address:

```text
IP:192.168.123.18
user name：unitree
password：123

```
!!! note Note:

- It is recommended to use GreenLink Technology, CM475 Type-C to HDMI converter.
- When using the docking station, pay attention to cooling down to prevent damage from high temperatures.

!!!

# Module Update

1. Use SSH connection to log in to the internal of the docking station. (Note: Before logging in, check if the SSH login port is in the same LAN as the docking station, and the network IP address of the SSH login port must be 192.168.123.xxx). The SSH login command is as follows:
     `ssh unitree@192.168.123.18`
2. After successfully connecting via SSH, you need to enter the password, which is the default as: 123.
3. Obtain the .zip docking station update package from the official website or sales. It can be used to upgrade relevant services of the docking station, such as SLAM service, odometer service, etc.
4. Connect the user's computer and the RJ45 user expansion Ethernet port (located at the rear of the expansion module) with a network cable, and ensure that the user's computer is in the 192.168.123.xx network segment.

<center>

![](https://doc-cdn.unitree.com/static/2024/1/4/a33bd756cb124c718ec7a0932aa2fd71_1417x1075.png)

</center>

5. Open a browser and enter http://192.168.123.18, the following interface will appear:

![](https://doc-cdn.unitree.com/static/2024/1/4/055525595f4140acb87f19d0a8ff8fa8_1557x1386.png)

Click![0](https://doc-cdn.unitree.com/static/2023/12/5/15f3581171c647778565d90edca028f1_758x671.png)to select the required update package.</br>
Click![0](https://doc-cdn.unitree.com/static/2023/12/5/1096887efc244450b280cf2b24eafe65_668x670.png)to upload the file to the expansion module. Then select the required update package.</br>
Click![0](https://doc-cdn.unitree.com/static/2023/12/5/f9ac4ddfdcae49e39818c8abc6584971_266x304.png)to start the update. The update progress will be displayed in the window on the right.</br>
Click![0](https://doc-cdn.unitree.com/static/2023/12/5/dcc695f17cfd4530984c5a8ca5f0010a_307x359.png)to delete the uploaded update package.</br>
Click![0](https://doc-cdn.unitree.com/static/2023/12/5/cf3694dc8a014fe990f355d0d4e67052_2944x549.png)to roll back to the previous version.</br>
At present, restoring to factory settings is not supported.	

# Expansion Dock Module Update Package
Please follow the above upgrade process, download the latest docking station firmware, and update it in a timely manner.

|Date | Update Description | Download Address|
| - | - | - |
|June 06, 2025 | Odometer Services.| [Click to download](https://firmware-cdn.unitree.com/tool/GO2_SLAM20250606.zip) |
| September 02, 2025 | GO2 SLAM service. <BR>1.Fix abnormal relocation issues <BR>2.Add YSN verification. | [Click to download](https://oss-global-cdn.unitree.com/static/9bb18494ff4545259103c2ace4440dca.zip) |
| September 02, 2025 | GO2_W SLAM service. <BR>1.Fix abnormal relocation issues <BR>2.Add YSN verification. | [Click to download](https://oss-global-cdn.unitree.com/static/ed80622f2fad4cfdb2e91558eb77eb18.zip) |
| April 01, 2026 | GO2 SLAM service. <BR>1.Adapted to Mid360s lidar | [Click to download](https://oss-global-cdn.unitree.com/static/2e44af167ebe4e6a89d35cdeae4705d5.zip) |
| April 01, 2026 | GO2_W SLAM service. <BR>1.Adapted to Mid360s lidar | [Click to download](https://oss-global-cdn.unitree.com/static/733c1dd4422147f184be6cda92db5b4f.zip) |

# Expansion Dock Type-C repair method
Phenomenon description: Some customers have reported that Type-C fails to supply power. After investigation, it was found that some customers deleted the /etc/rc.local file, resulting in the failure of Type-C enablement. Below are the solutions and repair methods for enabling Type-C through software.
!!! note Note:
 The following operations are all performed under root privileges.
!!!

Step 1: Check
1) First run the following command to see if it is enabled.

```
         cat /sys/class/gpio/PP.06/value
```

2) If the return value of the command is 1, it indicates that the software is running normally. It is recommended to troubleshoot the hardware.

<BR>

Step 2: If the first step fails, the following is the process for enabling the USB script.

1) If the above check process fails to obtain normal results, start the following operation.
```
        cp /lib/systemd/system/rc-local.service  /etc/systemd/system
```

2) Modify the `/etc/systemd/system/rc-local.service` file, adding the following two lines at the bottom of the file:
```
[Install]   
WantedBy=multi-user.target   
Alias=rc-local.service
```

3) Create the `rc.local` file under `/etc/` and output the following commands.
```
#!/bin/sh
`busybox devmem 0x02430030`
`busybox devmem 0x02430030 w 0x004`
`echo 446 > /sys/class/gpio/export`
`echo out > /sys/class/gpio/PP.06/direction`
`echo 1 > /sys/class/gpio/PP.06/value`
exit 0
```
4) Give `rc.local` file executable permission.
```
chmod +x /etc/rc.local
```
5) Restart and perform the self-test process in Step 1.

# To resolve the issue of the USB Type-A port on the dock being recognized as USB 2.0
1. Download the script file.
Script file download URL: <https://doc-cdn.unitree.com/static/2025/10/10/b8afa4618f5f479db1bc94e2c3c166f7.zip>

2. Unzip and enter the folder:
```bash
# Unzip the file
unzip b8afa4618f5f479db1bc94e2c3c166f7.zip 
# Enter the unzipped folder
cd unitree_dt_update/
```

3. Execute the script and reboot the system as prompted:
```bash
chmod +x unitree_update.sh
sudo ./unitree_update.sh
```
After running the script, you will see output similar to the following:
```bash
unitree@ubuntu:~/unitree_dt_update$ sudo ./unitree_update.sh 
Detecting unitree device type...
Found Go 2 NX docking station
Detecting device tree version...
Current device tree version: Mar 19 2023\008:08:40
Target device tree version: Sep 30 2025\017:55:09
Device tree version is incorrect, update is required
Preparing to update device tree...
Creating backup of current device tree...
Installing new device tree...
Device tree update completed, changes will take effect after reboot
Do you want to reboot now? [y/N]
```

**Current device tree version:** `Mar 19 2023\008:08:40` indicates the current device tree version of the system.
**Target device tree version:** `Sep 30 2025\017:55:09` indicates the device tree version to which the system needs to be updated.

**Note:** The device tree version `Mar 19 2023\008:08:40` contains an issue where the USB Type-A port on the Go2 docking station is incorrectly recognized as USB 2.0. This issue has been fixed in the latest version `Sep 30 2025\017:55:09`.

# Docking Station System Backup and Recovery

!!! warning Important Notice
System backup of the docking station requires you to remove the internal NVMe drive for operation. If damage occurs during the process, it will not be covered by free warranty. 
!!!

It is recommended that you perform a system backup immediately after receiving the device to prevent system crashes due to subsequent erroneous operations.

Note: To complete the following experiment, you will need an NVME storage device with a system installed (or use the NVME device that comes with the expansion dock, use with caution), an NVME card reader, and a PC host. Additionally, the following operations need to be performed under root privileges.
![](https://doc-cdn.unitree.com/static/2024/6/12/06341c460e404d34a2dbc8cc0a039fba_631x131.png)

## System Backup
1. Insert the docking station's NVMe storage device into the host PC (using a USB card reader). Use `lsblk -f` to check the device node of the storage device. For example, the storage device node is `/dev/sdc/`, and the storage device format is `ext4`.
2. Back up the NVMe storage device to the current host PC.
   ```
    sudo dd if=/dev/sdc status=progress | bzip2 > nx.img.bz2
   ```
After the command above finishes executing, remove the system drive from the host PC `(Not Docking Station)`.

## System Recovery
After the system backup is complete, you will need to restore it, which is the reverse process of the procedure above.
1. Remove the docking station's NVMe storage device, or use a new NVMe storage device, and insert it into the host PC (using a USB card reader). Confirm the device node of this NVMe storage device, for example: `/dev/sdc`. If the storage device is being used for the first time (a new storage device), you need to format this disk, for example, format it to `ext4`.
The formatting command is as follows:

   ```
   sudo mkfs -t ext4 /dev/sdc
   ```

2. Flash the system image backed up on the host PC to the NVMe storage device from the first step by executing the following command. Please note that you need to reserve at least 300GB of space.
   ```
   # nx.img.bz2 is the image name, please modify it according to the actual situation
   bzip2 -dc nx.img.bz2 | sudo dd of=/dev/sdc status=progress
   ```
Wait for the flashing process to complete. The speed depends on your connection bandwidth; 4 to 5 hours is also normal.

If you are unfamiliar with Linux disk flashing operations, you can also use `Rufus` on Windows to flash the image.

## unitree's Factory Image Download Link
If you decide not to use a personal backup system image for recovery, you can download the factory system image provided by Unitree Technology through the following link:

```
Note: The download link for our factory-installed image is here.40Tops file is nano image,100Tops is NX image,these two are the one without installing Cuda.The other  two .img files are installed with Cuda.

# The latest image:
# Go2 NX Docking Station Image Name: go2_nx_Jetpack5.1.1_20250930.img.bz2
https://drive.google.com/file/d/1BiBXlZwAiVGgNjyPKO9qP4BiOARJrASJ/view?usp=drive_link
# Go2 NANO Docking Station Image Name: go2_nano_Jetpack5.1.1_20250930.img.bz2

# historical image versions :
# 1. Nx.img.bz2
https://drive.google.com/file/d/13Zwgvn_ZaG_njdk1GnlSZrXRDCubmyom/view?usp=sharing
# 2.Nano.img.bz2
https://drive.google.com/file/d/1mKN-z8uD8PUpNbrH3MIodV-nLPNK5_fy/view?usp=sharing
```
