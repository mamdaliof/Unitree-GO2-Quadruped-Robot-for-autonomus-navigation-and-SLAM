# SLAM and Navigation Services Interface

!!! warning Usage Notice
Please ensure you fully understand and are familiar with the characteristics of the external radar (MID-360/XT16) and strictly adhere to the usage guidelines.
Important Note:
Hot-plugging is strictly prohibited during radar operation. Hot-plugging may cause radar malfunctions, and such malfunctions are not covered under warranty. Thank you for your cooperation and understanding!
!!!

!!! tip Function Description

Applicable Scenarios and Scope: `Static indoor flat ground` environments with `rich features` and `less than 25m*25m` in size. Do not exceed the recommended range!
This feature is intended for the `education and research` industry and is not recommended for commercial applications. For commercial use, please contact sales!
!!!

!!! tip Update Instructions
- Dock Module Update: Refer to [Application Development -> Dock Configuration -> Module Update](https://support.unitree.com/home/en/developer/module_update#heading-3) for SLAM and navigation program update methods. `Ensure updates are completed before use.`
- Firmware Update: To use the latest SLAM package, upgrade the firmware to the latest version (≥1.1.7).
!!!

# SLAM and Navigation Services Interface

The SLAM navigation service interface only supports the EDU robot dogs with expansion dock and the official Unitree-purchased lidar (MID-360/XT16) versions!!!

<p align = "center">

<img src="https://doc-cdn.unitree.com/static/2023/11/13/492e14d9686a4322ad5502b743d707e1_2933x3088.png" width="400"/>

The coordinates of the Mid-360 lidar in the IMU coordinate system inside the Go2 body are (0.1870, 0, 0.0803), and it rotates 13 ° around the Y-axis. The relative rotation and translation relationship of Mid-360 in the IMU coordinate system inside the Go2 body can be represented by the following transformation matrix:
$$
\begin{bmatrix}
0.9743701 & 0.0 & 0.2249511 & 0.1870 \\
0.0 & 1.0 & 0.0 & 0.0 \\
-0.2249511 & 0.0 & 0.9743701 & 0.0803 \\
0.0 & 0.0 & 0.0 & 1.0
\end{bmatrix} \
$$
<p align = "center">
<img src="https://doc-cdn.unitree.com/static/2023/11/13/eacd82eee2644568bdb093c40cb97235_2945x3110.png" width="400"/>

The coordinates of the XT-16 lidar in the IMU coordinate system inside the Go2 body are (0.1710, 0, 0.0908), without relative rotation. The relative rotation and translation relationship of XT-16 in the IMU coordinate system inside the Go2 body can be represented by the following transformation matrix:
$$
\begin{bmatrix}
1.0 & 0.0 & 0.0 & 0.171 \\
0.0 & 1.0 & 0.0 & 0.0 \\
0.0 & 0.0 & 1.0 & 0.0908 \\
0.0 & 0.0 & 0.0 & 1.0
\end{bmatrix} \
$$

</p>

## I. Introduction

The SLAM and navigation service interfaces are based on the Unitree SDK2. Before using, please ensure that you are on the same LAN segment as the robot. The client can implement basic SLAM and navigation functions by configuring different API ID and subscribing to different topic data.

For SLAM and navigation program update methods, refer to Application Development->Expansion Dock Configuration->Module Update.. Please confirm whether the update is complete before use.

## 2. Network configuration check

The SLAM and navigation services are deployed in dock PC. Its default IP address is 192.168.123.18. Users can access the local area network through a direct network cable. The lidar IP address used by this service is 192.168.123.20. Please ensure that the lidar IP address is correct before use. The network check steps are as follows:

The SLAM and navigation services are deployed on the dock PC on the back of the robot, with the default IP address being 192.168.123.18. Users can connect to this local network directly using an Ethernet cable. The IP address of the lidar used by this service is 192.168.123.20. Before using the service, please make sure the lidar IP address is correct. The steps for network checking and starting the service are as follows:

1.After connecting the user's PC to the dock PC using an Ethernet cable, modify the IP address to 192.168.123.XXX (please make sure XXX does not conflict with existing IP).

![](https://doc-cdn.unitree.com/static/2023/11/13/f7d396e8cf3e4e1ab5e305ebc2df86ee_924x637.png)

2.Open the terminal on the user's PC and enter the following commands to check if the connection is successful. If the results shown are as in the following figure, the connection is normal. Otherwise, please check if the connection and IP settings are correct.

```
ping 192.168.123.18 #Dock PC IP

ping 192.168.123.20 #Lidar IP

ping 192.168.123.161 #Motion Control PC IP
```
![](https://doc-cdn.unitree.com/static/2023/11/13/1d007982588a4b05a94e299c3dce1603_942x604.png)

  3.The user's PC can access the dock PC via SSH using the default password: **123**. The SLAM and navigation services is conflict to the ROS/ROS2 environment, please press Enter to refuse activating any ROS environment when enter the bash interface.

```
ssh 192.168.123.18
```

![](https://doc-cdn.unitree.com/static/2023/11/13/3c0ac30fcd1a4583b5f0144ddf7fae19_726x517.png)

4.The /home/unitree/cyclonedds_ws/cyclonedds.xml file on the dock PC is the configuration file for DDS. Before using this service, please confirm that its network card parameters and the **network card** with the IP address 192.168.123.18 on the dock PC are **the same** (you can check this using the ifconfig command).

```
ifconfig  #View the IP address of the dock PC
```
![](https://doc-cdn.unitree.com/static/2023/11/13/713cb98ee3df47deba2c6288884455d6_985x536.png)

5.Open another terminal and enter the following command. You will be able to see the relevant topic information sent by the robot's main PC, indicating that the data communication is normal.

```
ros2 topic list #View message topics
```

![](https://doc-cdn.unitree.com/static/2023/11/13/ee32e6d98e0c429c8d30466eb2c87e8a_783x638.png)

## 3. Service Data Description
Service name and version: SERVICE_NAME = "slam_operate", VERSION = "1.0.0.1"
Currently, the open interfaces api-id: 1801 start mapping, 1802 end mapping, 1804 initialize pose, 1102 pose navigation, 1201 pause navigation, 1202 resume navigation, 1901 close slam. The service request parameters and feedback data formats are both Json, and the specific parameters are as follows:
1.start mapping
```
api id: 1801

input parameters:
{
  "data": {
      "slam_type": "indoor" #fixed value
    }
}

feedback data:
{
    "succeed":true, #Whether the execution was successful or not
    "errorCode":0,  #Error code, 0 means normal
    "info":"",      #Description information
    "data":{}       #Rest of data
}
```
2.end mapping
```
api id: 1802

input parameters:
{
  "data": {
      "address": "/home/unitree/test.pcd" #Pcd save address
    }
}

feedback data:
{
    "succeed":true, #Whether the execution was successful or not
    "errorCode":0,  #Error code, 0 means normal
    "info":"",      #Description information
    "data":{}       #Rest of data
}
```
3.initialize pose
```
api id: 1804

input parameters:
{
  "data": {
        "x": 0.0,    #Translation information
        "y": 0.0,
        "z": 0.0,
        "q_x": 0.0,  #Rotation information
        "q_y": 0.0,
        "q_z": 0.0,
        "q_w": 1.0,
        "address": "/home/unitree/test.pcd" #Pcd load address
    }
}

feedback data:
{
    "succeed":true, #Whether the execution was successful or not
    "errorCode":0,  #Error code, 0 means normal
    "info":"",      #Description information
    "data":{}       #Rest of data
}
```
4.pose navigation
```
api id: 1102

input parameters:
{
  "data": {
       "targetPose": {  
          "x": 2.0,    #Target pose information
          "y": 0.0,
          "z": 0.0,
          "q_x": 0.0,
          "q_y": 0.0,
          "q_z": 0.0,
          "q_w": 1.0
        },
        "mode": 1,      #Obstacle mode, 1 is stop, 0 is bypass, (In obstacle-avoidance mode, a navigable area with a width of at least 0.8m is required, and obstacles must not be wider than 0.5m)
        "speed": 0.5    #Speed, range of go2: 0.2 (m/s) ~ 1.0 (m/s), range of go2_w: 0.2 (m/s) ~ 1.5 (m/s)
    }
}

feedback data:
{
    "succeed":true, #Whether the execution was successful or not
    "errorCode":0,  #Error code, 0 means normal
    "info":"",      #Description information
    "data":{}       #Rest of data
}
```
`Note`:
The distance between the target point and the current position cannot exceed `10 meters`. The robot will move in a straight line. Due to the radar's field of view, obstacles should be no less than `20 cm` high.
5.pause navigation
```
api id: 1201

input parameters:
{
  "data": {
    }
}

feedback data:
{
    "succeed":true, #Whether the execution was successful or not
    "errorCode":0,  #Error code, 0 means normal
    "info":"",      #Description information
    "data":{}       #Rest of data
}
```
6.resume navigation
```
api id: 1202

input parameters:
{
  "data": {
    }
}

feedback data:
{
    "succeed":true, #Whether the execution was successful or not
    "errorCode":0,  #Error code, 0 means normal
    "info":"",      #Description information
    "data":{}       #Rest of data
}
```
7.close slam
```
api id: 1901

input parameters:
{
  "data": {
    }
}

feedback data:
{
    "succeed":true, #Whether the execution was successful or not
    "errorCode":0,  #Error code, 0 means normal
    "info":"",      #Description information
    "data":{}       #Rest of data
}
```
## 4. Topic Data Description
1.Real-time point cloud data for mapping. Topic: rt/unitree/slam_mapping/points  Data type: sensor_msgs::msg::dds_::PointCloud2_

2.Real-time odom data for mapping. Topic: rt/unitree/slam_mapping/odom Data type: nav_msgs::msg::dds_::Odometry_

3.Relocation real-time point cloud data. Topic: rt/unitree/slam_relocation/points   Data type: sensor_msgs::msg::dds_::PointCloud2_

4.Relocation real-time odom data. Topic: rt/unitree/slam_relocation/odom  Data type: nav_msgs::msg::dds_::Odometry_

5.Real-time broadcast information. Topic: rt/slam_info   Data type: std_msgs::msg::dds_::String_

6.Implementation status feedback. Topic: rt/slam_key_info  Data type: std_msgs::msg::dds_::String_

The data in real-time broadcast information and execution status feedback information are all in `Json` format and can be judged and obtained through different fields, as follows:
① Real-time broadcast information type (rt/slam_info): basic status information
```
{
    "type": "robot_data",  #Data type
    "errorCode":0,         #Error code, 0 means normal
    "sec": 123456789,      #Timestamp
    "nanosec": 987654321,
    "info":XXX,            #Description information
    "data":{
        "motorTemp": [30.5,30.5,...],   #Motor temperature (unit: °C)
        "motorError": [0,0,0,...],      #Motor error code
        "batteryAmp": 1000.5,           #Battery current value (unit: mA)
        "batteryPower":10.0,            #Battery percentage (unit %)
        "batteryTemp":30.5,             #Battery temperature (unit: °C)
        "batteryVol":1000.5,            #Battery voltage (unit: mV)
        "sportMode":-1,                 #Sport mode, temporarily unavailable
        "gaitType":-1,                  #gait type, temporarily unavailable
        "cpuTemp":30.5,                 #Average temperature of CPU core (unit: ° C)
        "cpuUsage":30.5,                #CPU core occupancy rate (unit:%)
        "cpuMemory":30.5,               #Memory usage rate (unit:%)
        "cpuFrequency":100.5            #CPU average core frequency (unit:MHz)
    }
}

```
②Real-time broadcast information type (rt/slam_info): relocation information
```
{
    "type": "pos_info",  #Data type pos_info or mapping_info
    "errorCode":0,       #Error code, 0 means normal
    "sec": 123456789,    #Timestamp
    "nanosec": 987654321,
    "info":XXX,          #Description information
    "data":
      {
        "currentPose": { #Pose
          "x": 1.5,      
          "y": 1.5,
          "z": 1.5,
          "q_x": 0.0,
          "q_y": 0.0,
          "q_z": 0.0,
          "q_w": 1.0
          },
         "pcdName": "test"                    #Pcd name
         "address": "/home/unitree/test.pcd"  #Pcd address
      }
}
```
③ Real-time broadcast information type (rt/slam_info): control information
```
{
   "type": "ctrl_info", #Data type
    "errorCode":0,      #Error code, 0 means normal
    "sec": 123456789,   #Timestamp
    "nanosec": 987654321,
    "info":"XXX",       #Description information
    "data":
    {
      "targetNodeName": 9999,
      "is_arrived": false,
      "startPose": {
        "x": 1.1,
        "y": 1.2,
        "z": 1.3,
        "roll": 0.0,
        "pitch": 0.0,
        "yaw": 1.2
      },
      "targetPose": {
        "x": 1.1,
        "y": 1.2,
        "z": 1.3,
        "roll": 0.0,
        "pitch": 0.0,
        "yaw": 1.2
      },
      "stateMachine": {
        "state":"follow",      
        "isOpenPlan":false,    
        "isBack":false,       
        "isClimbStairs":false, 
        "isRotate":false,      
        "isPause":false,       # Whether to pause
        "ctrName":"pid",       
        "vx": 1.1,
        "vy": 1.2,
        "vyaw": 1.3
      },
      "obsInfo":{
        "state":false,         # Obstacles
        "time":0,              # Accumulated time (s)
      },
      "progress": {
        "used_time": 12.3,
        "last_time": 23.3,
        "completion_percentage": 0.12
      }
    }
}

```
④Execution feedback information (rt/slam_key_info): single task execution feedback
```
{
   "type": "task_result",     #Data type
    "errorCode":0,            #Error code, 0 means normal
    "sec": 123456789,         #Timestamp
    "nanosec": 987654321,
    "info":"XXX",             #Description information
    "data":
    {
      "targetNodeName": 9999, #Target
      "is_arrived": false     #Arrived
    }
}

```
## 5.Reference Examples

!!! warning Function Test Routines Have Binary Conflicts with ROS2  
The Unitree SDK2 and functional test routines (including unitree_slam, mid-360 or xt16 drivers, key_demo) require CycloneDDS and cannot be launched in an environment where ROS/ROS2 has been initialized.  
If you are using this set of programs on the expansion dock, please press Enter directly when selecting the ROS environment in Terminal, without choosing the ROS environment.  
!!!

(1)Install unitree sdk2 in the dock PC, download address:
[unitree_sdk2 ](https://github.com/unitreerobotics/unitree_sdk2 )

(2) Update the unitree_slam module. Refer to `Application Development->Expansion Dock Configuration->Module Update.`

(3) Set the Power mode of the dock PC to `0:MAXN`
![](https://doc-cdn.unitree.com/static/2024/9/20/37102f7cd0f9497ebb3ff71a26e9ec67_274x204.png)

(4) Modify the buffer size for data reception and transmission.(Only execute once)
```
sudo su
echo "net.core.rmem_max=52428800" >> /etc/sysctl.conf
echo "net.core.wmem_max=52428800" >> /etc/sysctl.conf
sysctl -p
```

(5) Modify executable file permissions
```
sudo chmod 777 -R /unitree/module/unitree_slam
```
(6) Modify the lidar type and YSN parameters
The configuration file address for the lidar parameters is /unitree/module/unitree_slam/config/slam_interfaces_server_config/param.yaml. Modify the corresponding `lidar_type` and `lidar_ysn` parameter in param.yaml according to the actual lidar type (mid360/xt16) and robot type (Go2/Go2_W). If you do not know YSN, please contact sales or technical support.
![](https://doc-cdn.unitree.com/static/2025/9/2/29eb63dd204f4bd1be65d83768b9ab7b_1156x677.png)

(7) Modify the external parameters of the corresponding radar. The address of the corresponding external parameter file is /unitree/module/unitree_slam/config/gridmap_config/config.yaml. Find the parameters **T_Dog2lidar** for the corresponding model (Go2/Go2_W) and use the corresponding parameters based on the radar model (default mid360).
![](https://doc-cdn.unitree.com/static/2025/8/6/d52f981072314609b0b832a003d177c2_1066x736.png)

(8) Run the key test program
```
#Run unitree slam service
cd /unitree/module/unitree_slam/bin
./unitree_slam
```
```
#Run lidar
cd /unitree/module/unitree_slam/bin
./mid360_driver       #or ./xt16_driver
```
```
#Run keydemo
cd /unitree/module/unitree_slam/bin
./keyDemo eth0
```
`Note`:
1.The source file directory of the keyDemo project is /unitree/module/unitree_slam/example, which can be used for reference.

2.When mapping the pcd, please do not control the robot too fast.

3.The rviz2 configuration file directory is /unitree/module/unitree_slam/rviz2. You can select the corresponding configuration file through File->Open Config in the rviz2 interface to view the mapping and relocation process.

4.Considering the limited computing resources of the dock pc, it is not recommended to start other `resource-consuming processes`, such as rviz2, while using SLAM.

5.Turn off the obstacle avoidance mode that comes with the robot, and the head light will `turn blue`.

6.When running for a long time or under high temperature conditions, the dock CPU may experience a `frequency drop` phenomenon, leading to abnormal positioning. It is recommended to use this interface function continuously for no more than 30 minutes, and continue using it after the CPU core temperature drops to normal.
