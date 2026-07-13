# Unitree Go2 Robot Developer Documentation

--- 

# About Go2

# Go2 Product List

<div style="text-align:center;">
<table borter="1">
<tr>
<th bgcolor="#D3D3D3" colspan="2"> Model</th>
<th bgcolor="#D3D3D3" style="width: 17%;"> AIR</th>
<th bgcolor="#D3D3D3" style="width: 17%;"> PRO</th>
<th bgcolor="#D3D3D3" style="width: 17%;"> X</th>
<th bgcolor="#D3D3D3" style="width: 17%;"> EDU<BR>*Multiple configurations available, please contact Unitree for details</th>
</tr>
<tr>
<td colspan="2"> Rendering</th>
<td> <img src="https://doc-cdn.unitree.com/static/2023/8/8/b58af3de0590450fb51121bc477ccd15_3773x3507.png"></td> 
<td> <img src="https://doc-cdn.unitree.com/static/2023/8/8/72bbaa0105844ee38aca99cb4d925f42_3773x3507.png"></td> 
<td> <img src="https://doc-cdn.unitree.com/static/2023/8/8/bb70d214b5044f3d891f43bebc4e91fa_3773x3507.png"></td> 
<td> <img src="https://doc-cdn.unitree.com/static/2025/8/22/61962a60e60b48bb98f2c1bc1143e684_1761x1790.png"></td>
</tr>
<tr>
<td rowspan="4" style="width: 10%;">Mechanical Parameters</td>
<td>Standing Dimensions</td>
<td>70cmx31cmx40cm</td>
<td>70cmx31cmx40cm</td>
<td>70cmx31cmx40cm</td>
<td>70cmx31cmx40cm</td>
</tr>
<tr>
<td>Lying Down Dimensions</td>
<td>76cmx31cmx20cm</td>
<td>76cmx31cmx20cm</td>
<td>76cmx31cmx20cm</td>
<td>76cmx31cmx20cm</td>
</tr>
<tr>
<td>Weight with battery</td>
<td>Approximately 15kg</td>
<td>Approximately 15kg</td>
<td>Approximately 15kg</td>
<td>Approximately 15kg</td>
</tr>
<tr>
<td>Material information</td>
<td>Aluminum alloy +<br>High-strength engineering plastic</td>
<td>Aluminum alloy +<br>High-strength engineering plastic</td>
<td>Aluminum alloy +<br>High-strength engineering plastic</td>
<td>Aluminum alloy +<br>High-strength engineering plastic</td>
</tr>
<tr>
  <td rowspan="2">Electrical Parameters</td>
  <td>Power Supply Voltage</td>
  <td>28V~33.6V</td>
  <td>28V~33.6V</td>
  <td>28V~33.6V</td>
  <td>28V~33.6V</td>
</tr>
<tr>
  <td>Maximum Operating Power</td>
  <td>Approximately 3000W</td>
  <td>Approximately 3000W</td>
  <td>Approximately 3000W</td>
  <td>Approximately 3000W</td>
</tr> 
<tr>
<td rowspan="5">Performance Parameters</td>
<td>Load</td>
<td>≈7kg((Limit ~10kg)</td>
<td>≈8kg (Limit ~10kg)</td>
<td>≈8kg (Limit ~12kg)</td>
<td>≈8kg (Limit ~12kg)</td>
</tr>
<tr>
<td>Movement Speed</td>
<td>0-2.5m/s</td>
<td>0-3.5m/s</td>
<td>0-3.7m/s<br>(Limit ~5m/s)</td>
<td>0-3.7m/s<br>(Limit ~5m/s)</td>
</tr>
<tr>
<td>Maximum Climbing Height</td>
<td>Approximately 15cm</td>
<td>Approximately 16cm</td>
<td>Approximately 16cm</td>
<td>Approximately 16cm</td>
</tr>
<tr>
<td>Maximum climbing slope angle</td>
<td>30°</td>
<td>40°</td>
<td>40°</td>
<td>40°</td>
</tr>
<tr>
<td>Basic computing power</td>
<td>/</td>
<td>8-core high-performance CPU[4]</td>
<td>8-core high-performance CPU</td>
<td>8-core high-performance CPU</td>
</tr>
<tr>
<td rowspan="5">Joint parameters</td>
<td>Maximum joint torque[1]</td>
<td>/</td>
<td>About 45N.m</td>
<td>About 45N.m</td>
<td>About 45N.m</td>
</tr>
<tr>
<td>Aluminum alloy precision joint motors</td>
<td>12</td>
<td>12</td>
<td>12</td>
<td>12</td>
</tr>
<tr>
<td>Extremely large joint motion range</td>
<td>Body: -48° to 48° <br>Thigh: -200° to 90° <br>Calf: -156° to -48°</td>
<td>Body: -48° to 48° <br>Thigh: -200° to 90° <br>Calf: -156° to -48°</td>
<td>Body: -48° to 48° <br>Thigh: -200° to 90° <br>Calf: -156° to -48°</td>
<td>Body: -48° to 48° <br>Thigh: -200° to 90° <br>Calf: -156° to -48°</td>
</tr> 
<tr>
<td>Inner knee joint cable routing</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
</tr>
<tr>
<td>Joint heat pipe for auxiliary cooling</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
</tr>
<tr>
<td rowspan="4">Sensor Configuration</td>
<td>Ultra-wide-angle 3D LiDAR</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
  <td>Yes</td>
</tr>
<tr>
<td>Wireless vector positioning<br>Companion module</td>
<td>No</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
</tr>
<tr>
<td>High-definition wide-angle camera</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
</tr>
<tr>
<td>Foot force sensor</td>
<td>No</td>
<td>No</td>
<td>No</td>
<td>Yes</td>
</tr>
<tr>
<td rowspan="14">Function list</td>
<td>Basic exercise, dance, etc.</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
  <td>Yes</td>
</tr>
<tr>
<td>Automatic retractable handle</td>
<td>No</td>
<td>Yes</td>
<td>No</td>
<td>No</td>
</tr>
<tr>
<td>Smart OTA upgrade</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
</tr>
<tr>
<td>RTT 2.0 image transmission</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
</tr>
<tr>
<td>Graphical programming</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
</tr>
<tr>
<td>Front Light (3W)</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
</tr>
<tr>
<td>Wi-Fi 6 Dual-Band Wireless</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
</tr>
<tr>
<td>Bluetooth 5.2/4.2/2.1</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
</tr>
<tr>
<td>4G Module(with GPS)</td>
<td>No</td>
<td>Yes, CN/GB</td>
<td>Yes, CN/GB</td>
<td>Yes, CN/GB</td>
</tr>
<tr>
<td>Voice function[5]</td>
<td>No</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
</tr>
<tr>
<td>ISS 2.0 Intelligent Companion</td>
<td>No</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
</tr>
<tr>
<td>Obstacle detection and avoidance</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
<td>Yes</td>
</tr>
<tr>
<td>Charging pile recharge</td>
<td>No</td>
<td>No</td>
<td>Support</td>
<td>Support</td>
</tr>
<tr>
<td>Secondary development[6]</td>
<td>No</td>
<td>No</td>
<td>Basic support</td>
<td>Support</td>
</tr>
<tr>
<td rowspan="6">Accessories</td>
<td>Handheld remote control</td>
<td>Optional</td>
<td>Optional</td>
<td>Yes</td>
<td>Yes</td>
</tr>
<tr>
<td>High computing power module</td>
<td>No</td>
<td>No</td>
<td>No</td>
<td>Optional NVIDIA Jetson Orin<br>(40-100 Tops of Computing Power)</td>
</tr>
<tr>
<td>Depth Camera</td>
<td>No</td>
<td>No</td>
<td>No</td>
<td>Yes</td>
</tr>
<tr>
<td>Smart Battery</td>
<td>Standard<br>(8000mAh) x 1</td>
<td>Standard<br>(8000mAh) x 1</td>
  <td>Standard<br>(8000mAh) x 1</td>
<td>Long-Life<br>(15000mAh) x 1</td>
</tr>
<tr>
<td>Battery Life</td>
<td>About 1-2h</td>
<td>About 1-2h</td>
<td>About 1-2h</td>
<td>About 2-4h</td>
</tr>
<tr>
<td>Charger</td>
<td>Standard (33.6V 3.5A)</td>
<td>Standard (33.6V 3.5A)</td>
<td>Standard (33.6V 3.5A)</td>
<td>Fast Charge (33.6V 9A)</td>
</tr>
<tr>
<td colspan="2">Warranty Period[7]</td>
<td>Half a Year</td>
<td>1 Year</td>
<td>1 Year</td>
<td>1 Year</td>
</tr>
</table>
</div>

[1] The maximum torque in the table refers to the maximum torque of the largest joint motor; the actual maximum torque varies for the 12 joint motors.
[2] In open environment without interference and blocking.
[3] 3.Transformation and quality varies considerably in different network environments.
[4] 8-core High-performance CPU ：Supports a variety of modes, including advanced mode, AI mode, 3D LiDAR mapping, etc.
[5] Voice functions include offline voice interaction, commands, intercom and music play.
[6] For more information, please read the secondary development manual.
[7] For more detailed warranty terms, please read the product warranty brochure.
[8] The above parameters may vary in different scenarios and configurations, please subject to actual situation.
[9] If any change in the appearance of the product, please refer to the actual product.
[10] The 4G function of non-Chinese mainland version will only support 43 European countries (except Ukraine), and some Asian regions.
!!!note   Tip:
* Limited to the current technique and computing power resources, part of function shall be realized human operation or secondary development.
* This product is a civilian robot. We kindly request that all users refrain from making any dangerous modifications or using the robot in a hazardous manner.

* Please visit Unitree Robotics Website for more related terms and policies, and comply with local laws and regulations.

!!!

## List of accessories
|  |  | |  |
| :-: | :-: | :-: | :-: |
| ![0](https://doc-cdn.unitree.com/static/2023/10/24/dca8f05ce2cc410794187a450c7386d8_2410x1543.png) | ![0](https://doc-cdn.unitree.com/static/2023/10/24/3ab97a04226f4fd9951bc13aff7436ba_2332x1770.png) | ![0](https://doc-cdn.unitree.com/static/2023/10/24/8e9adf7b5bf440068886461ae13947ae_3840x2160.png) |![0](https://doc-cdn.unitree.com/static/2023/9/5/127f57b4193f47d691d3fc7df40c8e20_2438x1772.png) |
|  Manual controller | Standard Battery <br>8000mAh  | Long Endurance Battery <br>15000mAh | Charger (Standard 3.5A) |
| ![0](https://doc-cdn.unitree.com/static/2023/9/5/4d0f32021c564aa6aa3b68c731246ac8_2437x1777.png) | ![0](https://doc-cdn.unitree.com/static/2023/9/5/9a023f2b1d5248afa8a12e5038df9c37_536x330.png) | ![0](https://doc-cdn.unitree.com/static/2023/10/24/e2ae72d77c3649d6a45d74b723d6f1cf_1838x1999.png) |![0](https://doc-cdn.unitree.com/static/2023/8/8/e392953e083e44a490facbbfc4bd702d_2560x1440.png) |
| Fast Charger (Standard 9A) |Foot End  | Charging Pile | Expansion Dock (Orin Nano 8GB)  |
| ![0](https://doc-cdn.unitree.com/static/2023/8/8/e392953e083e44a490facbbfc4bd702d_2560x1440.png) | ![0](https://doc-cdn.unitree.com/static/2023/10/24/33643b2ea06d4d0bab1279368aca342c_3072x1932.png) |  ![0](https://doc-cdn.unitree.com/static/2023/8/8/c83eb45df5e9463981b5436c980506e8_2560x1440.png) | ![0](https://doc-cdn.unitree.com/static/2023/10/24/3f9d429024a94665a44302e2a2779845_3072x1932.png)
 |
|  Expansion Dock (Orin NX 16GB) | Dual Cameras | The Small Servo Arm | Dual Cameras+Three in One |
| ![0](https://doc-cdn.unitree.com/static/2023/8/8/066eff9a8b0d4ac49f096dca158f7ab2_536x299.png) |  ![0](https://doc-cdn.unitree.com/static/2023/8/8/3c00959992274e90b7666944d082a1f1_536x299.png)|  ![0](https://doc-cdn.unitree.com/static/2023/8/8/5b69bc9b087d436887a98c95cb015524_536x299.png) | ![0](https://doc-cdn.unitree.com/static/2023/9/5/a1240cfde83e468bab7b1597699f3a7f_2349x2195.png) |
|The Depth Camera D435i | The 3D Navigation Radar<br> (MID-360) | The 3D Navigation Radar<br> (HESAI XTi6)| Protective Bracket - Small |

# Hardware Architecture

![](https://doc-cdn.unitree.com/static/2023/11/17/93c9c8f714e34e28b723c78d78276209_1295x913.png)

# Hardware architecture

**GO2 EDU**

<center>
  
![10](https://doc-cdn.unitree.com/static/2023/12/20/e2d667a9f89e42fa89c9136a04e6c5f7_1268x715.png)
<br>
<br>

![10](https://doc-cdn.unitree.com/static/2024/11/27/d9cf91963c33444ca301969849f4d3f3_1268x715.png)

</center>

Back load installation hole map: unit: mm

<center>

![10](https://doc-cdn.unitree.com/static/2023/12/20/f7dea4fe9cce4c1190f158d608f2cd33_1268x715.png)

</center>

## Electrical interface

![](https://doc-cdn.unitree.com/static/2024/2/19/b24fbf6ab5ec4604bd0110464da2a848_7261x2328.png)

!!! warning Regarding Electrical Interfaces

The Go2 Pro and Go2 Air versions do not support any of the extended electrical interfaces, including the SBUS port, DC 28.8V power output, and the Ethernet (RJ45) interface. These interfaces are exclusive to the Go2 EDU version.

[Notes on the SBUS Interface](https://global-serviceconsole.unitree.com/#/help/0311h2)

!!!

*   **Power interface**
    

DC 28.8V output, connected to Orin NX 8/16GB high computing power module BAT input.

*   **Ethernet interface**
    

Standard RJ45 interface, connected to User PC/Orin NX 8/16GB, RJ45 Ethernet interface.

*   **SBUS interface**
    
Used for communication connection on a universal remote control. This interface does not provide power output, and the interface definition (from left to right) is NC/GND/SBUS.

<center>

![0](https://doc-cdn.unitree.com/static/2023/11/6/5b97b31f76444c9491eb3eff74a25a12_1432x1381.png)

</center>

    

## LIDAR

The head 4D LiDAR-L2 adopts Unitree Unitree's self-developed 4D radar technology (3D position+1D grayscale), which can achieve high-speed laser ranging sampling 21600 times per second, obtain real-time 3D information of the surrounding environment, and can be used for motion obstacle avoidance to cope with various complex road conditions!

|  Unitree 4D LiDAR  |  |
| :--- | --- |
|  Model  |  L2  |
|  Model  |  75（W）x75（D）x65（H）mm  |
|  Supply Voltage  |  12V DC  |
|  Laser wavelength  |  905nm  |
|  FOV  |  360°\*96°  |

## Pilot Lamp

| Color<div style="width:35pt"></div> | Color and Flashing<div style="width:  55pt"></div> | Meaning<div style="width:  200pt"></div> |
|  :-: | :-: |  :- |
| ![6](https://doc-cdn.unitree.com/static/2023/11/13/08cad318f563421085276aeb2573583e_623x623.png) | Flash in green | Switching on |
| ![6](https://doc-cdn.unitree.com/static/2023/11/13/c6b6c1027fef4347b6c90073f10f5a8f_623x622.png) | Permanently on in green | Powered on, default obstacle avoidance on |
| ![6](https://doc-cdn.unitree.com/static/2023/11/13/96f67e5c335b4c24acfeed0c017e38ce_622x622.png) | Permanently on in blue | Obstacle avoidance closure |
| ![6](https://doc-cdn.unitree.com/static/2023/11/13/dbb1090c84004afcaae6e1ca34c26b3c_621x621.png) | Permanently on in yellow | Range mode |
| ![6](https://doc-cdn.unitree.com/static/2023/11/13/480aa86dc2fb4e919a4c100c882fc5e6_620x620.png) | Permanently on in purple | Accompanying mode on state |
| ![6](https://doc-cdn.unitree.com/static/2023/11/13/70fa6eae1d7044ccaad9501034400bc8_761x762.png) | Low flash rate in blue |Motor & IMU calibration in progress |
| ![6](https://doc-cdn.unitree.com/static/2023/11/13/5fbdf8e5a72a4f6f83514338743a74ff_762x762.png) | Low flash rate in yellow | Low battery warning, will automatically crouch down within 10 minutes |
| ![6](https://doc-cdn.unitree.com/static/2023/11/13/aae8bb7890834e82a6958cb5dc29e3ad_761x762.png) | Low flash rate in red | System abnormality, boot failure, hardware failure, need to contact after-sales service. |
| ![6](https://doc-cdn.unitree.com/static/2023/11/13/49568a40c2e948b7a794392dcf6dc1e3_758x758.png) | Fast flash rate in red | Motor & IMU calibration failed |
| ![6](https://doc-cdn.unitree.com/static/2023/11/13/2e65f7dbaa8c42d6990ca9ac1df47eca_621x621.png) | Permanently on in white | Head indicator light |

!!!note
Light priority: companion mode on (purple light always on)>endurance mode (yellow light always on)>obstacle avoidance off (blue light always on)
!!!

## Camera

The head camera supports 720p, 15fps, 1080p, 15fps dual streams. The camera has 1080P (HD) 15fps or 720p 15fps high-definition shooting capabilities, a light aperture of F2.2, and a field of view of 120°. App high-definition image transmission is possible. In an undisturbed and unobstructed environment, the camera can ensure smooth 720p 15fps high-definition image transmission.

#

## Joint serial number and joint limit

A quadruped robot is like an animal, with its body (Trunk) and limbs (Legs) symmetrical from side to side. It has four legs and is divided into two groups in front and back,

These two groups have the same coordinate system and joint range of motion, except for the differences before and after.

|  Number of legs and joints:  |
| :--- |
|  Leg 0 ：FR，right front leg  |
|  Leg 1 ：FL，left front leg  |
|  Leg 2 ：RR，right hind leg  |
|  Leg 3 ：RL，left hind leg |
|  Joint 0 ：Hip， body joint  |
|  Joint 1 ：Thigh，thigh joint  |
|  Joint 2 ：Calf，calf joint  |
|  e.g.FR\_thigth：Right front leg thigh joint  |

|  Each joint limit:  |
| :--- |
|  Each joint limit: -48°~48°  |
|  Thigh joint: Vertical direction is 0°, forward direction is positive, hind legs -260°~30°, forelegs -200°~90°  |
| Lower leg joint:  -156°~-48°  |

![](https://doc-cdn.unitree.com/static/2023/8/9/bffd59ff97974f2eadd9a2a124d71eca_9748x6316.png "Body joint limit")

## Coordinate system, joint rotation axis and joint zero point

<center>

![](https://doc-cdn.unitree.com/static/2023/8/9/87b2581cd788435582b4eff863906b65_773x722.png)

</center>

The rotation axis of the body joint is the x-axis, while the rotation axis of the thigh joint and calf joint is the y-axis. The positive direction of rotation conforms to the right-hand rule.

When all joints are at zero degrees, the coordinate systems are shown in the figure above. The red represents the x-axis, the green represents the y-axis, and the blue represents the z-axis. The calf joint cannot actually reach this position due to its limit position, and this is only to indicate the zero point position. It can be seen that the initial posture of each joint coordinate system is consistent, but the position and rotation axis are different.

# Robot specifications

## Dimensions

|  Parameter  |  Specification  |
| :--- | :--- |
|  Naked machine length, width, and height (standing)  |  70cm\*31cm\*40cm  |
|  Naked machine length, width, and height (lying down)  |  76cm\*31cm\*20cm  |
|  Bare metal net weight (excluding battery)  |  About 15kg  |
|  Degrees of Freedom  |  12  |
|  Maximum speed  |  3.7m/s (limit~5m/s) |

## Environment

|  Parameter  |  Specification  |
| :--- | :--- |
|  Operating temperature | 5 ℃ -35 ℃, operating in a good weather environment  |
|  Slope  |  +/- 40°  |
|  Maximum step height  |  16cm  |
| Lighting  |  3W searchlight  |

## Battery related

|  Specification parameters  |   |    |
| :--- | --- |  ---  |
|  Battery model  |  BT2-05  |  BT2-06  |
|  Battery weight  |  2.5kg  |  2.5kg  |
|  Battery capacity  |  8000mAh，236.8Wh  |  15000mAh，432Wh  |
|  Rated voltage  |  DC 29.6V  |  DC 28.8V  |
|  Charging limit voltage  |  DC 33.6V  |  DC 33.6V  |
|  Running time  |  1-2h  |  3-5h  |
| Charging method  |  slow charging  |  fast charging/charging station  |
| Charging current   |  3.5A  |  9A  |
|  Charging duration  |  2h  |  1h"15  |

## Internal correlation

|  Specification parameters |    |
| :--- | --- |
|  Internal correlation  |   8-core processor  |
|  4G  |  built-in patch SIM card |
|  Wi-Fi  |  WiFi 6 Dual Band Wireless 802.11x  |
|  Bluetooth  |  5.2/4.2/2.1  |
|  Storage Space  |  64G  |
|  Output power supply  | DC 28.8V (battery voltage)  |
|  Connection  |  RJ45 Ethernet port  |

## External Mount

### Expansion dock

|  Specification parameters  |    |    |
| :--- | --- | --- |
|  Mode  |  Orin Nano 8GB  |  Orin NX 16GB  |
|  Power supply voltage range  |  16-60V DC  |  16-60V DC  |
|  Computing power   |  Support up to 40Tops of computing power  | Support up to 100Tops of computing power |
|  Functional interface  | USB 3.0 Type A X1, USB 3.0 Type C X1, USB 2.0 Type C X1, Gigabit Ethernet port (standard RJ45) X2, 100Mbps Ethernet (GH1.25-4PIN) X1, M8 aviation plug interface X1  |  USB 3.0 Type A X1, USB 3.0 Type C X1, USB 2.0 Type C X1, Gigabit Ethernet port (standard RJ45) X2, 100Mbps Ethernet (GH1.25-4PIN) X1, M8 aviation plug interface X1  |

### The 3D Navigation Radar

Go2 is compatible with two types of LiDARs, MID-360 and Hesai XT16 LiDARs, which can be used for Slam navigation.

|  Specification parameters  |    |    |
| :--- | --- | --- |
|  Model  |  MID-360  |  HESAI XTi6R  |
|  XT-16 LiDAR  |  65mm\*65mm\*60mm  |  Φ100.0 / 103.0 mm\*76mm  |
|  Power supply voltage range  |  9-27V DC  |  9-36V DC  |
| Laser wavelength  |  905nm  |  905nm  |
|  FOV  |  Horizontal 360°,  Vertical -7°~52°  |  Horizontal field of view angle 360°, Vertical field of view angle 30°（-15°~+15°）  |

### Depth camera
|  Specification parameters  |    |
| :--- | --- |
|  Model  |  D435i  |
|  Size  |  124mm\*29mm\*26mm  |
|  Minimum depth distance |  0.105 meters  |
|  Depth image resolution  |  1280\*720 @ 30fps；848\*480 @ 90 fps  |
|  Deep field angle  |  86° \* 57° （±3°）  |

### The Small Servo Arm

<table>
<tr>
<th bgcolor="#D3D3D3" align="left">Model</th>
<th bgcolor="#D3D3D3" align="left">D1</th>
<th bgcolor="#D3D3D3" align="left">D1-550</th>
</tr>
<tr>
<td>Weight</td>
<td>Approximately 2.37kg</td>
<td>About 3.15kg</td>
</tr>
<tr>
<td>Degree of freedom</td>
<td>6 degrees of freedom+1 claw clamp</td>
<td>6 degrees of freedom+1 claw clamp</td>
</tr>
<tr>
<td>Load</td>
<td>500g (ideal weight)</td>
<td>500g (including clamp weight)</td>
</tr>
<tr>
<td>Maximum arm span</td>
<td>550mm (excluding claw clamp)<br>670mm (including claw clamp)</td>
<td>550mm (excluding jaws)<br>670mm (including jaws)</td>
</tr>
<tr>
<td>Motor type</td>
<td>Servo motor</td>
<td>Servo motor</td>
</tr>
<tr>
<td>Working radius</td>
<td>/</td>
<td>550mm</td>
</tr>  
<tr>
<td>Power demand</td>
<td>24V 2.5A (MAX 5A)</td>
<td>24V 10A(15～48V)</td>
</tr> 
<tr>
<td>Power</td>
<td>60W</td>
<td>240W </td>
</tr> 
<tr>
<td>Controller</td>
<td>/</td>
<td>Integrated (4 x Cortex-A55 1.8GHz)</td>
</tr> 
<tr>
<td>Communication method</td>
<td>Control communication interface RJ45 (ETH)</td>
<td>RJ45 (Ethernet 100Mbps communication)+Type-C (serial port debugging)</td>
</tr> 
<tr>
<td>Control method</td>
<td>DDS subscription</td>
<td>DDS subscription</td>
</tr> 
<td>Control cycle</td>
<td>/</td>
<td>10Hz </td>
</tr>
<tr>
<td>Torque of each joint motor</td>
<td>/</td>
<td valign="top">J0: 3.3NM <BR>J1: 3.3NM <BR>J2: 1.7NM <BR>J3: 1.7NM <BR>J4: 1.7NM <BR>J5: 1.7NM <BR>J6: 1.7NM</td>
</tr>
<td>Range of motion for each joint</td>
<td valign="top">J1: ±135°<BR>J2:  ±90°<BR>J3:  ±90°<BR>J4:  ±135°<BR>J5:  ±90°<BR>J6:  ±135°</td>
<td valign="top">J0: ±135°<BR>J1:  ±90°<BR>J2:  ±90°<BR>J3:  ±135°<BR>J4:  ±90°<BR>J5:  ± 135 °<BR>Claw stroke: 0-65mm</td>
</tr>
</table>

### Remote control with screen

|  Specification parameters  |   |
| :--- | --- |
| Remote control  |  |
|  Camera display device  |  5.5 inch 1080P high-definition and bright LCD touch screen display |
|  System Configuration  |  Android 9.02GB running memory, 16GB storage space  |
|  Size (antenna retracted)  |  189mm\* 138mm\*41 mm  |
|  Weigh)   |  850 g  |
|  Battery capacity and type:  |  10200 mAh 7.4V 2S ion battery  |
|  Fast charging protocol:  |  PD 20W  |
|  Charging time:  |  5 hours (20W fast charging)  |
|  Assignment range:  |  13 hours  |
|  Functional interface  |  Video output: Standard HDMI * Industry version only External device: USB-A Charging: Type-C Firmware upgrade: Upgrade port (bottom GH1.25 4Pin) File transfer: Type-C/USB-A Mobile network: SIM card slot External storage: TF card slot/USB-A Tripod fixed: 1/4 threaded hole  |
|  Camera perspective  |  FOV 120°  |
|  **Dual cameras**  |  |
|  Product size  |  106mm\*25mm\*41mm  |
|  Weight  |  108g  |
|  Power consumption  |  3W  |
|  Searchlight power率  |  8W  |
|  Luminous flux  |  1W/120~140lm  |
|  Searchlight type  |  transparent  |

### Dual Cameras+Three in One

|  Specification parameters  |   |
| :--- | --- |
|  Size  |  270mm\*143mm\*133mm  |
|  Weight  |  690g±10g  |
|  Power supply voltage range  |  16-60V  |
|  Brightness  |  3000lm  |
|  Light output angle  |  15°  |
|  Power  |  Lighting: 30W; Speaker: 30W; Red and blue; 10W  |
|  Effective sound transmission distance  |  500M  |
|  Maximum sound transmission distance  |  800M  |
|  Maximum sound pressure  |  130dB  |
|  Audio Format  |  mp3/wav/m4a/flac/aac  |
|  Control Method  |  App (Remote Control)  |
|  Function  |  Real time shouting, recording, uploading, audio playback, text conversion, voice lighting, flash lighting, constant lighting, brightness adjustment, red blue flash, red blue flash mode switching  |

--- 

# Remote Controller

## Download Remote Controller Sticker

![](https://doc-cdn.unitree.com/static/2025/12/19/d7f06fdfa74d4e45965d660efb36306a_948x507.png)

[Download Here](https://oss-global-cdn.unitree.com/static/697b96893c144fea976e13815199bd70.pdf)

--- 

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

--- 

# Basic Application

## Description

The basic service is to obtain the motor, battery, remote control, and attitude status and send them to the operation control service. After receiving the control command from the operation control service, the motor and battery are controlled.

![](https://doc-cdn.unitree.com/static/2023/10/16/7ebaebf051fd4a0a87359cf645055eac_8000x4500.png)

--- 

# Motion Application

# Robot Coordinate System

The coordinate system of a robot is defined as X facing forward, Y facing left, and Z facing up. The default ground clearance for standing robots is 0.33m, the distance between the left front foot and the center of the body is [x: 0.19257, y: 0.135], and the leg lift height for walking is 0.09m.

 

![](https://doc-cdn.unitree.com/static/2023/9/5/7ba474139e0e46878156aebf948a1bdb_8000x4500.jpg " Coordinate System Definition ")

   
![](https://doc-cdn.unitree.com/static/2023/9/5/46cc9394c1dc45e4b41d6c9f9de8aeae_8000x4500.jpg " Default standing state ")

                                                                      

# Robot Status

![](https://doc-cdn.unitree.com/static/2023/10/16/92c7ff0ab69f460c9ac788dd1dc2ca61_8000x4500.png)

**Robot state switching mechanism**

## Introduction to robot status

The motion of a robot includes damping, standing locking, balanced standing, basic motion, special actions, and protective state states. During operation, the robot switches between different states through a state machine to achieve different control tasks. The explanations for each state are as follows:

|Robot status | Description | Schematic diagram|
| :---: | :--- | :---: |
|Damping state | All joint motors immediately stop moving and enter damping mode.  |  ![](https://doc-cdn.unitree.com/static/2023/8/31/e179c2e36b3f4094aa771a7c77788849_640x360.gif) |
|Standing locked state | The robot remains standing while keeping the motor locked.  | ![](https://doc-cdn.unitree.com/static/2023/8/31/5ac38327816149d89720abf3de8a1957_640x360.gif)
 |
|Balanced Standing State | The robot remains standing in place. Compared to the standing locked state, in this state, the robot will adapt to changes in terrain and maintain a constant posture and body height.  | ![](https://doc-cdn.unitree.com/static/2023/8/31/1ff4657d37fe40f088c5c90b033e3b77_640x360.gif)
 |
|Basic motion state | The robot executes the given motion commands according to the given gait, such as speed tracking, trajectory tracking, etc. The walking state provides multiple optional gaits and supports speed control and trajectory tracking control modes.  |![](https://doc-cdn.unitree.com/static/2023/8/31/8bf0df1ca5cc45c48429a60d75b8c4cd_640x360.gif)
 |
|Special Action Status | The robot executes a given special action command, such as forward jump, forward somersault, etc!  | ![](https://doc-cdn.unitree.com/static/2023/8/31/bc517f60f77a4fdcbe4feee47a3448e9_640x360.gif)
 |
|Protected state | The robot may experience an irresistible strong impact that may cause its posture to flip and enter a protected state. This state can be automatically restored to standing state by calling the interface.  | ![](https://doc-cdn.unitree.com/static/2023/8/31/216c06f3947a49acb88c81a7112cf6ed_640x360.gif)
 |

## Switching mechanism of robot state

The switching mechanism of each state of the robot is shown in Figure 2.1, and the specific switching process of each state is explained below:

* **Damping**: Switching the damping state has the highest priority, and all states can immediately switch to the damping state, equivalent to a soft emergency stop system.

* **Standing lock**: Standing lock is the state of connecting damping and balanced standing. The robot dog needs to enter the balanced standing state from the damping state before calling the corresponding motion service to achieve robot control.

* **Balanced Standing**: In a balanced standing state, various interfaces of the SDK can be called to achieve robot motion control.

* **Protection state**: When the robot recognizes a strong impact and determines that it cannot perform normal motion actions, it will enter the protection state. The SDK provides an interface for restoring from packet state to damping or standing state.

* **Basic Motion**: During the motion execution process, the SDK interface can be called to put the robot into a damped or balanced standing state to terminate the current motion service.

* **Special Action**: When entering the special action execution state, other motion control services will be suspended first, waiting for the current action to complete and enter the balanced standing state before taking effect.

# Robot high-level motion control

The high-level motion control interface services of robots can be divided into basic motion control and special motion control. In basic motion control services, corresponding interfaces can be called to achieve different movements of robots such as posture and body height control, speed control, trajectory tracking control, and obstacle avoidance. At the same time, interfaces can be called to switch the walking gait of robots according to different terrain scenarios and task requirements. In the special action control service, the corresponding interface can be called to implement the built-in special actions of the robot, such as sitting, jumping forward, and flipping forward. The high-level motion control interface supported by the robot is shown in the following figure.

![](https://doc-cdn.unitree.com/static/2023/10/16/be9bce9970634d30af7bb222a1f323b0_8000x4500.png " Robot high-level motion control interface diagram ")

## Basic motion control

### Sports mode

|Motion control mode | Description | Schematic diagram|
| :---: | :--- | :---: |
|  Attitude and body height control | In standing and walking modes, the body maintains the given posture and height  |![](https://doc-cdn.unitree.com/static/2023/8/31/65a5f65a8c6c49ba883c08d3a791259e_640x360.gif)
 |
|  Speed control | The robot travels at a given speed  |  ![](https://doc-cdn.unitree.com/static/2023/8/31/9685cd39c9634828aaa461613230d783_640x360.gif)
 |
|Trajectory tracking control | The robot follows a given trajectory |    |
|Obstacle avoidance | The robot travels at a given speed while avoiding obstacles around it |       |

### Gait

|Robot gait | Description | Schematic diagram|
| :---: | :--- | :---: |
|  trot gait  |  trotgait is the most efficient gait among quadruped robots  | ![](https://doc-cdn.unitree.com/static/2023/8/31/027192a494f64638a5de8c6400560bef_640x360.gif)
 |
|  trot running Gait  |  This gait has a higher stride and frequency than a normal trot gait, and has a higher walking speed | ![](https://doc-cdn.unitree.com/static/2023/8/31/b625b98f1a03413ea25e37586f82db92_640x360.gif)
 |
|  climbing mode |  This gait can adapt to more complex terrain and achieve functions such as climbing buildings and climbing obstacles  |   |

## Special Actions

Sports services provide a variety of built-in actions that can be arranged as needed. The following are the built-in special actions and related descriptions.

|Special Action | Action Execution Process | Schematic Diagram|
| :---: | :---: | :---: |
|  sit down  | ![](https://doc-cdn.unitree.com/static/2023/10/16/1f987e4291c8465ba3d1c37d03e8ee7f_596x339.png) |  ![](https://doc-cdn.unitree.com/static/2023/8/31/b253c11e31e8436e9545a3337eea188b_640x360.gif)    |
|  Recovery from sitting down movements  |
|  Stretch out  | ![](https://doc-cdn.unitree.com/static/2023/10/16/1305f5f4cb3e44caba625ceb092a7f00_557x321.png) | ![](https://doc-cdn.unitree.com/static/2023/8/31/016b836cc3bf41fbbec7ca52fe4e659c_640x360.gif) |
|  Roll around  | ![](https://doc-cdn.unitree.com/static/2023/10/16/4d8d05ad67824f2ba89496bf1489d922_557x321.png) | ![](https://doc-cdn.unitree.com/static/2023/8/31/df90a2aeb7ca4cebaa9b70cb76a05e2a_640x360.gif) |
|  Happy  | ![](https://doc-cdn.unitree.com/static/2023/10/16/e182a947266b4e3b8aa9781f7a4b90b4_557x321.png) | ![](https://doc-cdn.unitree.com/static/2023/8/31/f4b37ed34d7a4720a3db6d653613d671_640x360.gif)
 |
|  Dance  | ![](https://doc-cdn.unitree.com/static/2023/10/16/61c31e858c084b62ba1dcebc053abf62_557x321.png) |![](https://doc-cdn.unitree.com/static/2023/8/31/93130a44dcad484f964310eff29283f9_640x360.gif)
 |
| Greeting the New Year with a bow  |![](https://doc-cdn.unitree.com/static/2023/10/16/d78e5553eff14421acd4d20d8c06f514_557x321.png) | ![](https://doc-cdn.unitree.com/static/2023/8/31/584cda13e04e474a9afb07963d33a8ec_640x360.gif)
 |
| Forward somersault  | ![](https://doc-cdn.unitree.com/static/2023/10/16/b917d299b7fe476f8e116de909135d71_557x321.png) |   |
|  Jump forward  | ![](https://doc-cdn.unitree.com/static/2023/10/16/ba26b87858cb4b7ba85ff28c015fe765_557x321.png) | ![](https://doc-cdn.unitree.com/static/2023/8/31/2ed0caa577024c3d934010075e28d1f6_640x360.gif)
 |
|  Move forward!  | ![](https://doc-cdn.unitree.com/static/2023/10/16/8da3b57d28154847811eb218a3473c6b_914x294.png)
 |   |

--- 

# DDS Application

## DDS

DDS (Data Distribution Service) is a middleware that is a distributed communication specification published by OMG. It adopts a publish/subscribe model and provides various QoS service quality policies to ensure real-time, efficient, and flexible data distribution, meeting the needs of various distributed real-time communication applications.

![](https://doc-cdn.unitree.com/static/2023/9/5/bc447ffc02cf442186d8b7d57e52fb7d_754x448.jpeg)

(Image source: [https://www.dds-foundation.org](https://www.dds-foundation.org/))

--- 

# Image Application

# Overview

The Unitree Go2 image service is a functional module independently developed by Unitree Technology, which displays real-time camera transmitted videos and high-frequency radar scanned images (voxel images), and achieves different perspectives switching between camera videos and radar scanned images.

<center>

![1](https://doc-cdn.unitree.com/static/2023/11/20/cccd4e3a12704baf82b24b4add706149_1672x780.png)

</center>

# Video images

Video image is one of the core functions of the Unitree Go2 image service. The video image source mainly receives the camera video source data from the Go2 head and transmits it in real-time to the APP for display.

**Video image function entry:**

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/715d8d6d9c6942bfb91dd7d8a98bc1b3_1792x828.png)

</center>

**After entering the image video page, it will automatically trigger the acquisition of the video stream**

<center>

![1](https://doc-cdn.unitree.com/static/2023/11/20/2bd39876b4a44e7e98228cf636145ac5_1672x780.png)

</center>

# Radar scanning image

Radar scanning images (hereinafter referred to as 3D voxel maps) are also an important feature of Unitree Go2 imaging services. They continuously receive surrounding environmental information data scanned by radar hardware at high frequencies, and through calculation and processing, depict real-time 3D voxel maps.

<center>

![1](https://doc-cdn.unitree.com/static/2023/11/20/667f6ff983674feaa7277f446ac293bc_1672x780.png)

</center>

There are two perspectives for displaying 3D voxel images: first person perspective and third person perspective.

The camera with a first person perspective will follow behind the GO2 model and perform corresponding operations synchronously as the model moves and rotates. The effect is as follows:

<center>

![1](https://doc-cdn.unitree.com/static/2023/11/20/daaff084b392448da57c46b6020b873b_762x352.gif)

</center>

Double click on the screen to switch the perspective, from the first person perspective to the third person perspective. The effect of the third person perspective is as follows:

<center>

![1](https://doc-cdn.unitree.com/static/2023/11/20/05308720fe994563953776288de9b7a6_1672x774.png)

</center>

# Switching between video and radar images

The image and radar scanning images can be switched by clicking and gesture sliding:
*   If it is currently in video image mode, you can click on the radar image window in the bottom left corner to switch:
<center>

![1](https://doc-cdn.unitree.com/static/2023/11/20/77121d8247b44274a3bc6682883f3bfd_1672x780.png)

</center>

    
*   If it is currently in radar image mode, you can click on the video image window in the bottom left corner to switch: 

<center>

![1](https://doc-cdn.unitree.com/static/2023/11/20/92d7b18e10a642e2b1944ad647d2baf9_1672x780.png)

</center>

    

The actual switching effect is as follows:

<center>

![1](https://doc-cdn.unitree.com/static/2023/11/20/ea3c712bf9494b3c8d5dda9df909cc46_762x352.gif)

</center>

In addition to clicking, you can also switch by sliding your fingers sideways on the screen at the same time, and through gesture switching, you can switch to a mode where two view modes coexist. The effect is as follows:

<center>

![1](https://doc-cdn.unitree.com/static/2023/11/20/3c2451c1709f41cf92202ff26f236647_762x352.gif)
</center>

# Shooting

The shooting function is one of the functions of the image application, which captures images and photos of the Go2 head camera and transfers them to the APP for storage.

Click the capture button on the right to take photos: 

<center>

![1](https://doc-cdn.unitree.com/static/2023/11/20/e58c8dec3729415fb649fc4f8d9572ab_1672x780.png)

</center>

The actual effect is as follows:

<center>

![1](https://doc-cdn.unitree.com/static/2023/11/20/de24dec8c1744035a675a8efc03ef093_762x352.gif)

</center>

--- 

# Network Application

This chapter will introduce the design concept of Go2 network connections (**Wi-Fi STA**, **Wi-Fi AP**, and **4G**) and how users can apply the network.

# Network Introduction

Go2 supports three network connections: **Wi-Fi STA**, **Wi-Fi AP**, and **4G**. Among them, **Wi-Fi STA** and **Wi-Fi AP** are open for user settings.

- **Wi-Fi STA**: Go2 connects to a **Wi-Fi** hotspot in the environment, achieving external network access capability.

- **Wi-Fi AP**: Go2 comes with a built-in hotspot, which is a built-in local area network that supports mobile phone and other device connections.

- **4G**: Go2's built-in 4G IoT network card is connected to the operator's base station to achieve external network access capability.

!!! note Note:

To reduce traffic consumption, priority should be given to using Wi-Fi STA channels when both Wi-Fi STA and 4G are enabled. When Wi-Fi STA is turned off or unable to access the external network, the 4G channel is automatically enabled. When using 4G channels, some restrictions are placed on accessing domain names to prevent traffic consumption.

!!!

The 4G network connection is automatically controlled by Go2 based on the principle of high priority WIFI and reduced traffic consumption, without the need for users to manually enable it. Users can view the card information and traffic consumption of the current 4G IoT network card through the Go2 app.

The activation of **Wi-Fi STA** and **Wi-Fi AP** network connections is controlled by the user, and users can interact with Go2 via Bluetooth through the Go2 APP, achieving the following functions:

- Enable **Wi-Fi STA** to connect to a **Wi-Fi** hotspot in the environment.

- Enable **Wi-Fi AP**, modify the built-in hotspot of Go2, namely **Wi-Fi** name and **Wi-Fi** password.

!!! note  Note:
 
After Go2 restarts, if the user has not configured **Wi-Fi STA** and **Wi-Fi AP**, then the existing **Wi-Fi STA** or **Wi-Fi AP** and their corresponding configuration parameters will be enabled, depending on the user configuration before shutting down. If the user sets a **Wi-Fi STA** network connection before shutting down, Go2 will try to connect to a **Wi-Fi** hotspot in the environment based on the user's configuration information after restarting. If the user sets a **Wi-Fi AP** network connection before shutting down, Go2 will radiate the AP outward according to the user's configuration information after restarting.

!!!

Operate the Go2 APP (see the application functions in the next section for specific steps). After establishing a Bluetooth connection between Go2 and the APP, the user enters network settings information, and the APP sends relevant instructions for network settings to Go2. Go2 will respond to the instructions, enable **Wi-Fi STA** or **Wi-Fi AP** network connection, and provide feedback on the execution status of the instructions to the APP. The following figure shows the schematic diagram of the interaction between Go2 and the APP network configuration.

!!! note Note:

Only one **Wi-Fi STA** and **Wi-Fi AP** channel will be enabled for Go2. If the user sets **Wi-Fi STA**, the **Wi-Fi AP** will be turned off, and Go2 will try to connect to a **Wi-Fi** hotspot in the environment according to the user's configuration information. If the user has set the **Wi-Fi AP**, the **Wi-Fi STA** will be turned off, and Go2 will radiate the AP outward according to the user's configuration information.

!!!

![image](https://doc-cdn.unitree.com/static/2023/10/23/1bc0a68c81854ac3a80511270c26b340_8001x4501.png)
<center>Schematic diagram of Go2 and APP network configuration interaction</center>

# Application functions

This section mainly includes viewing **4G** IoT network card information, configuring **Wi-Fi AP** and **Wi-Fi STA**.

## View 4G IoT network card information

Click on Settings on the homepage.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/7dae56065c514822b66c41703921516b.PNG)

</center>

Click on Mobile Network.

<center>

![1](https://doc-cdn.unitree.com/static/2023/8/8/d4ce10259cf0409a8da1f97885b00e0e_876x392.png)

</center>

## Configure Wi-Fi AP

### Unbound machine dog

To configure the **Wi-Fi AP** without binding the machine dog, perform the following steps.

Add a machine dog device and click on Connect Machine Dog.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/edb80a34d0744e088cb037f701930059.PNG)

</center>

Attempt to bind the machine dog.

<center>
  

  ![1](https://doc-cdn.unitree.com/static/2023/10/23/d3dc183fe8564640be6f7dd0f803896c.PNG)

  
  </center>

Select AP router mode.

<center>

 ![1](https://doc-cdn.unitree.com/static/2023/10/23/27b7a7d776404c058c47908727a5058a.PNG)

</center>

Set the hotspot name and password.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/c18c0141b4364c1f8cfd902fc6089427.PNG)

</center>

Connect your phone to the hot spot of the dog and return to the app.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/3a544c1356cd433e9e9e69ed0569b6c1_1792x828.png)

</center>

### Machine dog bound

If the machine dog is already bound, the following steps can be performed to configure Wi-Fi AP.

Click on Settings on the homepage.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/1f44b4218bec4a5e8d6d9547033c53ba.PNG)

</center>

Click on Robot Settings.

<center>

![1](https://doc-cdn.unitree.com/static/2023/8/8/46326f67a9db42e1b54e4d7a51ee849f_876x392.png)</center>

Select AP router mode.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/65558f78488d4389b226416e1167e7fa.PNG)

</center>

Set the hotspot name and password.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/b2ea8854dbda4be3af2548be4e9cf2c0.PNG)
</center>

## Configure Wi-Fi STA

### Unbound machine dog

To configure **Wi-Fi STA** without binding the machine dog, follow the steps below.

Add a robotic dog device.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/e7d0ca3f33f2443689b32414932427d2.PNG)

</center>

Attempt to bind the machine dog.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/bfd38034dd5242d2b2df13e273331ff0.PNG)

</center>

Select Wi-Fi connection mode.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/7db855929e224889b6e6a3a6ea3688e2.PNG)

</center>

Enter the Wi-Fi name and password.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/6902529f72564f23a9c2a3ca49d11700.PNG)

</center>

### Machine dog bound

If the machine dog is already bound, to configure**Wi-Fi STA**, the following steps can be performed.

Click on Settings.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/3cf1db0911644e5f8161b0f2d1ad31f3.PNG)

</center>

Click on Robot Settings.

<center>

![1](https://doc-cdn.unitree.com/static/2023/8/8/43275da4b0df4a41829de23f7cc5af6e_876x392.png)

</center>

Select Wi-Fi connection mode.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/dacb8c9a6f824e9ab5663f8449ce50c0.PNG)

</center>

Enter the Wi-Fi name and password.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/23/6902529f72564f23a9c2a3ca49d11700.PNG)

</center>

--- 

# UWB Application

# Summary

Unitree Go2 UWB is a vector positioning module developed by Yushu Technology, which can achieve centimeter level positioning within the plane of the aircraft body. Built in 3-axis accelerometer and 3-axis gyroscope IMU, providing labeled posture. This module is applied to the accompanying functions of Go2 integration and can also be used for user secondary development.

![](https://doc-cdn.unitree.com/static/2023/8/8/e96a4a4e42dd43d8834fc0394635589b_5000x2813.png)

# Technical Proposal

The UWB module consists of two parts: a tag and a base station, with an integrated antenna, joystick, buttons, etc. on the tag; There are 4 antennas of the same specification arranged on the base station. The base station interacts with the tag antenna through the antenna and analyzes the pose information of the tag.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/24/7405daf5f6c2496cbba4d71432083a35_5244x2329.png)
</center>

# Instructions for use

## Key Description

|**Keys** | **Functions** | **Specific Instructions**|
| :---: | :---: | --- |
|  Power button | Turn on/off power | - Press briefly once to turn it on <BR>  - Press and hold for more than 2 seconds to turn off       |
|  P key | System reset | - Short press twice continuously to cycle between damping, lying down, and standing up modes for the robot  <BR>   - When the robot rolls over, long press for 1 second to restore standing     |
| M key | Companion mode switch | - Short press once to exit Companion mode and enter Rocker mode  <BR>    - Quick short press twice to enter Slow Auto Companion mode with a maximum speed of 1.5m/s   <BR>     -  In Slow Auto Companion mode, short press twice to enter Fast Auto Companion mode with a maximum speed of 3.0m/s    |
|  L1 key | Robot orientation setting |- Short press once to adjust the robot counterclockwise by approximately    <BR>    -  Short press twice to adjust the robot clockwise by approximately 5.7°       |
|  L2 key | Enable/disable automatic obstacle avoidance | - Short press 2 times continuously to activate obstacle avoidance function <BR>    - Short press 1 time to disable obstacle avoidance    |

## Rocker Description

The label joystick belongs to a two axis joystick, and by moving the joystick, the robot can be controlled to move forward and turn. The corresponding relationship between the direction of joystick movement and the direction of robot motion is shown in the following figure.

<center>

![](https://doc-cdn.unitree.com/static/2023/10/24/191b50f44c354e69881463c92952867c_687x529.png)

</center>

## Usage process

After Go2 is powered on and stands up automatically, the accompanying remote control can be used. By default, the companion function is disabled, and functions such as joystick control can be used normally. If you need to use the companion function, please follow the procedure below to switch to companion. The specific process is as follows:

**Wearing and activating companion mode** **[Important steps!!!]**

* With the antenna facing upwards, wear the accompanying remote control on the right side of the waist; The human body is standing on the left side of the robot, with the torso aligned with the robot's orientation

* Quickly press the M key twice to enter slow companion mode

* In slow companion mode, briefly press the M key twice again to enter fast companion mode

**Turn obstacle avoidance on/off**

Press the L2 key twice in a row to activate obstacle avoidance, and briefly press once to deactivate obstacle avoidance

**Exit Companion Mode**

* Short press the M key once

* Move the joystick in any direction

* Shutdown

* Place the remote control horizontally

--- 

# LiDAR Application

## Overview

![](https://doc-cdn.unitree.com/static/2023/8/8/33c87925266a4e6bac638247d3f30552_7453x1979.jpg "Architecture diagram of LiDAR service system")

The system framework of the LiDAR service is shown in the figure.

* The Unilidar SDK obtains raw measurement data packets from LiDAR hardware through a serial port and parses them into point cloud data and IMU data

* The Unilidar Node module obtains the parsed point cloud data and IMU data through the Unilidar SDK, and preprocesses the point cloud using robot state information obtained from the robot dog motion program to remove distortion. Finally, it publishes the point cloud and robot odometer information in the world coordinate system after removing motion distortion.

* The Height Mapping module utilizes point cloud and odometer information to construct a 2.5D height map and provides it to the motion planning module for path planning, obstacle avoidance, and foot landing control functions.

* The Voxel Mapping module utilizes point cloud and odometer information to construct a 3D voxel map and transmit it to the mobile app, enabling real-time visualization of the 3D environment map around the robot on the mobile end, facilitating remote operation of the robot.
    

## Unitree L1 LiDAR

Unitree 4D LiDAR-L1 is a safe and reliable 4D LiDAR developed by Unitree (3D position+1D grayscale). It has the ability to achieve high-speed laser ranging sampling every 21600 times and excellent ultra wide angle scanning ability. The field of view (FOV) is extended to 360 ° horizontally and 90 ° vertically, enabling three-dimensional spatial detection of hemispherical field of view angles; IMU module with built-in 3-axis acceleration and 3-axis gyroscope, supporting a push frequency of 250Hz. Possessing strong obstacle detection and avoidance capabilities, capable of handling various complex road conditions, achieving obstacle avoidance in the movement of GO2 quadruped robots.

L1 radar mainly includes laser emission and ranging core, reflector, high-speed rotating motor, and low-speed rotating motor. In the working state, according to the perspective shown in the diagram, the rotation direction of the high-speed rotating motor and the low-speed rotating motor is shown in the following figure.

<center>

![0](https://doc-cdn.unitree.com/static/2023/10/24/8d2be6a12902408bb6e9095ca1b75c1d_1438x1543.png
 "High speed motor rotation direction")

![0](https://doc-cdn.unitree.com/static/2023/10/24/71ea2dad20e840adae862db52ccc98ea_2056x1341.png 
"Low speed motor rotation direction")

</center>

L1 adopts laser time-of-flight ranging technology, combined with high-speed laser acquisition and processing mechanisms, to achieve 21600 ranging actions per second. For each ranging action, L1 emits a ns level narrow pulse infrared laser signal. The reflected light after the laser signal is irradiated on the target object will be received by the radar's laser acquisition system. After analysis and processing by the processor, the distance value between the irradiated target object and L1, as well as the current angle, will be output from the communication interface.

![](https://doc-cdn.unitree.com/static/2023/10/24/560dc9305d1941ed8d6b016b5bb1aa70_3648x2084.png  "Schematic diagram of working principle")

The definition of the Cartesian coordinate system O-XYZ for L1 is shown in the following figure. Point O is the origin (IMU position), and O-XYZ is the point cloud coordinate system of L1 (the specific location of the origin can refer to the origin in the L1 3D model, which can be referenced when using Unilidar point cloud software).

![](https://doc-cdn.unitree.com/static/2023/10/24/b04316d7261d47d3bf45e64d9bc3cdde_3402x1471.png
 "Unitree4D LiDAR-L1 Coordinate Definition")

## LiDAR point cloud

The Go2 machine dog will automatically start the relevant programs of the LiDAR when turned on, and publish the point cloud collected by the LiDAR to the DDS topic.

By default, LiDAR posts two point cloud topics:
*   **Original point cloud of LiDAR**, Its coordinate system is the original LiDAR coordinate system;
    
*   **Point cloud after removing motion distortion** ,Its coordinate system is the world coordinate system that is consistent with the robot odometer.

<center>

![](https://doc-cdn.unitree.com/static/2023/8/8/38399bbee5674278b39993854d3bec52_855x713.png
 " Lidar point cloud after distortion removal")

</center>
 

## Altitude map

This service utilizes a LiDAR point cloud and a robot body odometer to construct a 2.5D height map centered around the robot in real-time, and updates it as the robot moves. This map can provide information about the surrounding environment, including the position, height, and shape of objects, allowing the robot dog to perform more accurate path planning, obstacle avoidance, and foot control functions in complex environments.

Height map is a special type of map that accurately reflects the environmental characteristics of the robot dog, including ground height, wall height, obstacle height, etc. Unlike traditional 2D maps, each point in a height map contains height information, thus providing more detailed environmental information. At the same time, the application can also dynamically adjust the height map based on the height information of the robot dog, thereby adapting to different altitude environments.

The robot body odometer can be used to obtain the position and posture information of the robotic dog, and combined with LiDAR point clouds, an accurate height map can be constructed. Lidar point clouds can obtain environmental information around robotic dogs, including walls, obstacles, and objects, which can be used to update altitude maps. When the robot dog moves, the height map will also be updated accordingly and can be provided for use by the robot dog at any time.

![](https://doc-cdn.unitree.com/static/2023/8/8/ac2a719fed4346f299e74ee26576733a_1027x771.png
 " 2.5D altitude map")

## 3D voxel map

This service utilizes a LiDAR point cloud and a robot body odometer to build a real-time 3D voxel map centered around the robot and able to follow the robot's movement, and transmits the map in real-time to the mobile app for visualization. This 3D voxel map can provide more detailed environmental information, including walls, obstacles, furniture, etc., which can accurately reflect the environmental characteristics around the robot dog.

This service can also achieve real-time visualization of the environment map around the robot dog by transmitting the constructed 3D voxel map to the mobile app in real time. Users can view the environmental map around the robot dog in real-time in the mobile app, including information such as obstacle location and height. In addition, users can also remotely operate the robot dog based on map information, achieving the function of remote control of the robot dog.

A three-dimensional voxel map is a map that represents the occupation information of three-dimensional space and can provide more detailed environmental information. Traditional two-dimensional maps can only represent occupation information on a fixed height plane, while three-dimensional voxel maps contain occupation information throughout the entire three-dimensional space. Therefore, this application can provide more detailed environmental information, enabling the robot dog to perform more accurate path planning, obstacle avoidance, and foot landing control functions.

The robot body odometer can be used to obtain the position and posture information of the robot dog, and combined with LiDAR point clouds, three-dimensional voxel maps can be accurately constructed. Lidar point clouds can obtain environmental information around robotic dogs, which can be used to update 3D voxel maps. When the robot dog moves, the 3D voxel map will also be updated accordingly and can be provided to the mobile app at any time.

The display effect of the 3D voxel map app is shown in the following figure.
![](https://doc-cdn.unitree.com/static/2023/8/8/c9dab98d503342b88fa41b3737c4da78_1792x828.png)

--- 

# SLAM Application

# SLAM Services

> The SLAM navigation service interface only supports EDU robot dogs with docking stations and Unitree's officially purchased LiDAR (MID-360/XT16) versions!!!

# Introduction

The SLAM application is divided into three parts: mapping, positioning, and navigation. Mapping is used to obtain feature information (corner and face features) in the current environment and generate a current environment map for relocation; Positioning is based on the map generated by the mapping module and combined with the perception of the current sensor to determine the robot's pose in the current environment, providing position feedback and other information for navigation; The navigation module automatically plans the path to the target point based on the positioning results and the deviation from the target point.

* The Go2 motion data extraction module is used to convert Go2 motion data into standard Odom and IMU data to support mapping, positioning, and navigation modules

* The LiDAR data acquisition module is used to obtain point cloud data of the 3D LiDAR carried by Go2

* The topology point reading module is used to load the marked navigation points

* The motion control module is used to control Go2 to safely reach the designated target endpoint

![](https://doc-cdn.unitree.com/static/2023/10/24/0b9ca475de95488e99d0eb380f6623c7_2016x545.png)

## Project Overview

The SLAM service runs in a high-performance computing expansion board, and the onboard host is responsible for providing motion information for Go2. Users can connect to the high-performance computing expansion board through a direct network cable or WIFI connection (additional wireless network card installation is required) to obtain SLAM service data from remote desktops or user hosts with Ubuntu systems installed.

![](https://doc-cdn.unitree.com/static/2023/10/24/5d4c45760b344dd7879aca272df9cf91_8000x4500.png)

!!! note
The algorithm startup entry for the SLAM service is detailed in the SLAM service interface in the software interface service in the same document.
!!!

## Point cloud map construction process

Precondition: Before constructing the map, it is necessary to ensure that Go2 is in a standing state, and the motion information has been correctly extracted into data in Odom and IMU standard formats. At the same time, the onboard host can obtain point cloud data from LiDAR normally.

<center>

![](https://doc-cdn.unitree.com/static/2023/10/24/1a919a74e9634307a9c428a36040b1c3_622x545.png)
</center>

#### Map construction startup effect

Open the visualization tool to discover the point cloud information of the current environment, as shown in the figure (the environment in the figure is only for reference, and there may be differences in the actual use process). Among them, the red arrow represents the pose of the robot, and the blue-green point cloud represents the constructed environment map.

![](https://doc-cdn.unitree.com/static/2023/9/5/9a2143da39e447739373c3183a716282_1435x557.png)

#### PCD Map Save Effect

If the map name is saved as' demo ', a file named demo.pcd can be found in the target folder, which is the point cloud map corresponding to the current environment.
<center>

![](https://doc-cdn.unitree.com/static/2023/9/5/90590a4d633745309fd500b36429d6f1_93x72.png)
</center>
It is possible to close the nodes related to drawing creation, as shown in the following figure.

<center>

![](https://doc-cdn.unitree.com/static/2023/9/5/f1327acb172f48708fbd0a0ae129d220_582x107.png)

</center>

## Positioning process

![](https://doc-cdn.unitree.com/static/2023/10/24/fc9dc87ad73942678b27b666df8d2402_1552x705.png)

Based on the constructed PCD map, Go2 can be located. Before positioning services, it is necessary to first obtain the motion data and LiDAR data of Go2, and also provide an initial pose of Go2.

#### Positioning algorithm startup results

Due to the need to specify the initial pose for Go2 after starting the positioning node, the visualization interface is empty at this time. To enable the robot to quickly and accurately locate its position, it is necessary to move Go2 to the starting point of the mapping, and then set the initial pose of Go2.

Set the initial pose for Go2 to quickly obtain its own positioning information in the environment to support navigation tasks.

#### Initial pose setting completion result

After sending the initial pose, the perception data of current LiDAR sensors such as Go2 is matched with the map saved during the point cloud map construction process, and the pose calculation is completed. At this time, the TF transformation of Go2 will be displayed in the map coordinate system.
![](https://doc-cdn.unitree.com/static/2023/9/5/9169c2d517c041e49b623be6aac76848_1225x501.png)

## Navigation process

The following figure represents the process of completing navigation tasks. Based on the positioning results and the marked topology points, navigation services can be performed. Go2 will autonomously plan its motion based on the deviation between its own posture and the target point, and safely move to the target point.

![](https://doc-cdn.unitree.com/static/2023/10/24/026ae4f14939437ebfa3a52f21084e1d_1126x651.png)

You can choose to navigate to a specific topology point. If the target topology point is successfully sent, the edge between the current position and the target topology point will be selected in red, indicating that Go2 is currently moving along the current edge to the target point. During the movement process, Go2's gait, speed, etc. are all constrained by the corresponding edges.
![](https://doc-cdn.unitree.com/static/2023/9/5/7709cbd76e954e5a8ddadf225ab61fd1_1444x453.png)

--- 

# FAULTS

# Fault

The engineers of Go2 have put in a lot of effort in the design and manufacturing process, but they still inevitably encounter some unexpected problems in practical use. When problems occur, operators, developers, and other devices will be notified through fault alarms.

There are different types and sources of faults. The current fault information can be obtained through the APP or SDK.

**System malfunction**

A system malfunction indicates a hardware or software malfunction in the robot. They include fault source code and fault code, and can be notified to users through apps or SDKs, and recorded by cloud services in online mode. Resolving these faults requires a solution based on the specific fault code.

**Behavioral malfunction**

A behavioral fault indicates that the robot is unable to execute a certain instruction. This usually indicates that the current operating conditions of the robot do not allow the execution of the command or that the robot is currently in an occupied state.

**Application failure**

App failure, such as the dog not being bound, unable to connect, or network abnormality.

**Fault recovery**

Normal warning faults and other warning conditions will automatically disappear after they disappear.

Special faults such as motor protection, motherboard disconnection, etc. require a restart of the dog to recover.

<center>

![](https://doc-cdn.unitree.com/static/2023/11/17/2afe89c56a3c4c4ebc72c87ac1a9b7fd_2400x1080.jpg)

![](https://doc-cdn.unitree.com/static/2023/11/17/d4fb9302ae6b46039e564076849c67f1_2400x1080.jpg)

</center>

--- 

# Obtain SDK

## SDK Introduction 

The **unitree_sdk2** is an SDK developed by Unitree Technology for their new generation of robots. The SDK encapsulates interfaces for low-level motor control, high-level motion control, LiDAR point cloud data, audio and video transmission, SLAM (Simultaneous Localization and Mapping), odometry, and other functionalities. It also provides relevant function interfaces.

You can learn robot control and complete secondary development tasks for the Go2 robot by following the provided interfaces and examples in the 《Go2 SDK Development Guide》 that we offer.

## SDK Support Status
Currently, the **unitree_sdk2** supports the Unitree Go2 EDU version (include X) of robots. Other models or versions of robots are not supported for secondary development using this SDK.

> The SDK supports both Unitree B2 and Unitree H1 robots simultaneously.

    
## SDK download address
[https://github.com/unitreerobotics/unitree_sdk2](https://github.com/unitreerobotics/unitree_sdk2)

## Other information

### Go2 Simplified Model - STEP
Without expansion dock version: [Click to download](https://oss-global-cdn.unitree.com/static/GO2%E7%AE%80%E5%8C%96-%E4%B8%8D%E5%B8%A6%E6%8B%93%E5%B1%95%E5%9D%9E-0912.zip)

With extended dock version: [Click to download](https://oss-global-cdn.unitree.com/static/GO2%E7%AE%80%E5%8C%96-%E5%B8%A6%E6%8B%93%E5%B1%95%E5%9D%9E-0911.7z)

### Go2 URDF
[URDF Click to Download](https://oss-global-cdn.unitree.com/static/Go2_URDF.zip)

--- 

# Quick Start

This article introduces how to develop for the Go2 robot using the unitree\_sdk2.

## Environment Dependencies

### System Environment

It is recommended to develop on **Ubuntu 20.04** or **Ubuntu 22.04**. Development on Mac or Windows systems is currently not supported, nor is development on Go2's internal computer.

### Network Environment

The network adapter on the user's computer that communicates with the Go2 robot must be set to the **123 subnet**. The IP address for this adapter is recommended to be set to **192.168.123.222** ("222" can be changed to something else). It is **not allowed** to set this adapter's IP address to 192.168.123.161, as this is the IP address of the Go2 robot's built-in computer.

### Dependency Installation

The following dependencies need to be installed:

```bash
sudo apt install cmake
sudo apt install gcc
sudo apt install build-essential
sudo apt install libeigen3-dev
```

## Installation and Compilation

> **The following description assumes the working directory is the user's home directory.**

### Installing unitree\_sdk2

Download the [ unitree\_sdk2](https://github.com/unitreerobotics/unitree_sdk2) compressed package and extract it to the user's home directory. Open a terminal and execute the following commands sequentially to install unitree\_sdk2:

```c++
cd ~/unitree_sdk2/
mkdir build
cd build
cmake ..
sudo make install
```

Or, install to a specified directory:

```c++
cd ~/unitree_sdk2/
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/opt/unitree_robotics
sudo make install
```

!!! note Attention
In the above command, CMAKE\_INSTALL\_PREFIX is used to specify that unitree\_sdk2 should be installed in the `/opt/unitree_robotics` directory. If you want to install unitree\_sdk2 in a different directory, modify this path accordingly.
!!!

### Example Compilation

Open a terminal and execute the following commands sequentially to compile the examples:

```c++
cd ~/unitree_sdk2
mkdir build
cd build
cmake ..
make
```

If the `make` command finishes with 100% progress and no errors, it means the compilation was successful.

<center>

</center>

If the `make` command is executed successfully, the generated examples will be located in the `build/bin` directory. The files shown in green characters in the image below are the binary files corresponding to the successfully compiled examples.

<center>

</center>

!!! note Attention
Due to continuous updates to unitree\_sdk2, the executable files shown in the image above may differ from the latest version.
!!!

### Network Configuration

When running examples, control commands will be sent from the user's computer to the Go2 robot's built-in computer via the local area network. Therefore, it is necessary to perform a few essential configuration steps to form a local network between the two computers.

Configuration Steps:

1.  Connect one end of a network cable to the Go2 robot and the other end to the user's computer. Enable and configure the computer's **USB Ethernet**. The IP address of the robot's onboard computer is **192.168.123.161**, so the computer's USB Ethernet address needs to be set to the same subnet as the robot, for example, by entering **192.168.123.222** ("222" can be changed to something else) in the Address field.

<center>
    

</center>

      To test whether the user's computer and the Go2 robot's built-in computer are connected properly, you can enter `ping 192.168.123.161` in the terminal. The connection is successful if output similar to the image below appears.

2.  Check the network card name corresponding to the 123 subnet
       Use the `ifconfig` command to view the network card name for the 123 subnet, as shown below:

<center>
   

</center>

As shown in the image above, the network card name corresponding to the IP **192.168.123.222** is `enxf8e43b808e06`. Users need to remember this name, as it will be a necessary parameter when running the examples.

## Running Examples

After successful compilation, the `unitree_sdk2/build/bin` folder will contain the binary files corresponding to examples like `low_level`, `high_level`, and `wireless`. These examples can generally be divided into high-level control examples and low-level control examples. For details, please refer to the section on **[Example Reference](https://support.unitree.com/home/zh/developer/Basic_motion_control)**. The following section uses the `low_level` example as an illustration. This is a low-level control example that controls the Go2 robot's front right leg to swing rhythmically.

### Disabling Motion Control Service

Before running this example, you must first disable Go2's main motion control service (MCF). This can be done in **App -\> Device -\> Service Status** by clicking to disable the corresponding service. Alternatively, you can disable the motion control service by calling the service status switch interface. For information on this method, refer to the [ go2\_stand\_example ](https://www.google.com/search?q=https://github.com/unitreerobotics/unitree_sdk2/blob/main/example/go2/go2_stand_example.cpp) example in `unitree_sdk2`, which demonstrates how to disable the motion control service by calling the [ Motion Switcher Service Interface](https://support.unitree.com/home/zh/developer/Motion%20Switcher%20Service%20Interface).

!!! note Attention
The main motion control service must be disabled because the low-level control example also acts as a motion control service. Both send control commands to Go2. If multiple motion controls are active simultaneously, the Go2 robot will receive two or more control commands, leading to confusion and potential loss of control. Therefore, before running a low-level control program, ensure the corresponding service is disabled.
!!!

Motion Control Service Names:
| Service Name | Corresponding Version |
| --- | --- |
| mcf | Go2 Main Motion Control Service (Software Version \> 1.1.6) |
| sport\_mode | Go2 Main Motion Control Service (Software Version \< 1.1.6)|
| wheeled\_sport | Go2 W Main Motion Control Service |

### Running the Example

Open a terminal and execute the following commands sequentially to run the example.

```c++
cd ~/unitree_sdk2/build/bin
./go2_low_level [Network Interface]
```

`[Network Interface]` is the name of the network adapter you use to link the robot, such as `enxf8e43b808e06`. You can use the `ifconfig` command to view the network card name. Be sure to select the network card name with the IP address previously set to 192.168.123.222.

!!! note Attention
This example will cause the Go2 robot's legs to swing. To protect the robot, you should ensure all four legs are suspended off the ground before running this example.
!!!

### Example Running Result Preview

At this point, the robot's front right lower leg will swing rhythmically.

## More Examples

The `go2_stand_example` example can control the quadruped robot to transition from a resting (crawling) state to a standing state, and then return to the resting state after a period of standing. This example also uses the [ Motion Switcher Service Interface](https://support.unitree.com/home/zh/developer/Motion%20Switcher%20Service%20Interface) to disable Go2's main motion control service. Therefore, users do not need to manually disable Go2's main motion control service (`sport_mode`/`mcf`) via the App before running this example.

### Running the Example

Open a terminal and execute the following commands sequentially to run the example.

```c++
cd ~/unitree_sdk2/build/bin
./go2_stand_example [Network Interface]
```

!!! note Attention
Before running the `go2_stand_example` example, the Go2 robot should be stationary and resting on the ground.
!!!

--- 

# Creating Customer Application

This document will guide users on how to create their own high-level application routine program using the **unitree\_sdk2**.

By utilizing the **sport\_client** class of `unitree_sdk2`, users can create various high-level applications. This section will provide a step-by-step tutorial on using `sport_client` to create a high-level application that **"makes the Go2 robot, which is lying on its back with its four legs in the air, flip over to stand up, adjust its body height, and then walk forward for a certain distance."**

## Reviewing the sport\_client Interface

`sport_client` is a high-level interface class encapsulated by `unitree_sdk2`. By calling the methods of this class, high-level interfaces can be invoked to control the Go2 robot to perform specified actions.

This class is located at `unitree_sdk2/include/unitree/robot/go2/sport/sport_client.hpp`, as shown below:

```c++
#ifndef __UT_ROBOT_GO2_SPORT_CLIENT_HPP__
#define __UT_ROBOT_GO2_SPORT_CLIENT_HPP__

#include <unitree/robot/client/client.hpp>

namespace unitree
{
namespace robot
{
namespace go2
{
/*
 * PathPoint
 */
struct stPathPoint
{
  float timeFromStart;
  float x;
  float y;
  float yaw;
  float vx;
  float vy;
  float vyaw;
};

typedef struct stPathPoint PathPoint;

/*
 * SportClient
 */
class SportClient : public Client
{
public:
  explicit SportClient(bool enableLease = false);
  ~SportClient();

  void Init();

  int32_t Damp();
  int32_t BalanceStand();
  int32_t StopMove();
  int32_t StandUp();
  int32_t StandDown();
  int32_t RecoveryStand();
  int32_t Euler(float roll, float pitch, float yaw);
  int32_t Move(float vx, float vy, float vyaw);
  int32_t Sit();
  int32_t RiseSit();
  int32_t SpeedLevel(int level);
  int32_t Hello();
  int32_t Stretch();
  int32_t SwitchJoystick(bool flag);
  int32_t Content();
  int32_t Heart();
  int32_t Pose(bool flag);
  int32_t Scrape();
  int32_t FrontFlip();
  int32_t FrontJump();
  int32_t FrontPounce();
  int32_t Dance1();
  int32_t Dance2();
  int32_t LeftFlip();
  int32_t BackFlip();
  int32_t HandStand(bool flag);
  int32_t FreeWalk();
  int32_t FreeBound(bool flag);
  int32_t FreeJump(bool flag);
  int32_t FreeAvoid(bool flag);
  int32_t ClassicWalk(bool flag);
  int32_t WalkUpright(bool flag);
  int32_t CrossStep(bool flag);
  int32_t AutoRecoverSet(bool flag);
  int32_t AutoRecoverGet(bool& flag);
  int32_t StaticWalk();
  int32_t TrotRun();
  int32_t EconomicGait();
  int32_t SwitchAvoidMode();

};
}
}
}

#endif//__UT_ROBOT_GO2_SPORT_CLIENT_HPP__
```

> **For a detailed introduction to the motion interfaces, please refer to the chapter [High-Level Sport Service Interface](https://support.unitree.com/home/en/developer/sports_services)**

## Creating the Application File

Next, let's create the application file in the `example` folder of `unitree_go2_sdk` for better management.

> **The following narration assumes the working path is /home/unitree/**

Enter the following commands sequentially. This sequence of commands will create a folder named `user` under the `example` folder of `unitree_go2_sdk`, where users can manage the application code and files. Then, it will create a file named `app_height.cpp`. The user will write the application logic mentioned earlier in this file.

```c++
cd /home/unitree/unitree_go2_sdk/example
mkdir user
cd user
touch app_height.cpp
```

Next, let's edit `app_height.cpp`.

1.  **Include Header Files:**

```c++
#include <unitree/robot/client/client.hpp>
#include "robot/go2/sport/sport_client.hpp"
```

2.  **Initialize DDS Interface and Create High-Level Interface Object**

```c++
unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
 //argv[1] is the network interface name connected to the robot dog, passed from the terminal
unitree::robot::go2::SportClient sport_client;
sport_client.SetTimeout(10.0f);//Timeout duration
sport_client.Init();
sport_client.WaitLeaseApplied();
```

3.  **Call Functions to Implement Application Logic**

```c++
sport_client.RecoveryStand(); //Recovery stand-up
sleep(3);
sport_client.Sit(); //Sit down
sleep(3);
sport_client.RiseSit(); //Recover from sitting position
sleep(1);
sport_client.Move(0.2,0,0); //Set the desired velocity in the X direction to control the Go2 robot to walk forward for a certain distance
sleep(2); //Walk forward for 2 seconds
```

**The complete code is:**

```c++
#include <unitree/robot/client/client.hpp>
#include <unitree/robot/go2/sport/sport_client.hpp>

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }
  //Initialize interface
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
  
  //Instantiate sport_client and initialize
  unitree::robot::go2::SportClient sport_client;
  sport_client.SetTimeout(10.0f);//Timeout duration
  sport_client.Init();
  sport_client.WaitLeaseApplied();
  int moveTime = 3; // move 3 second
  auto startTime = std::chrono::steady_clock::now();
  while(true)
  { 
    
    sport_client.RecoveryStand(); //Recovery stand-up
    sleep(3);
    sport_client.Sit(); //Sit down
    sleep(3);
    sport_client.RiseSit(); //Recover from sitting position
    sleep(1);
    sport_client.Move(0.2,0,0); //Set the desired velocity in the X direction to control the Go2 robot to walk forward for a certain distance
    sleep(2); //Walk forward for 2 seconds
    
    // Get current time point
    auto currentTime = std::chrono::steady_clock::now();
    // Calculate elapsed time
    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
    // Exit loop if elapsed time is greater than or equal to 3 seconds (Note: The variable is moveTime=3, not 2 as in the comment above)
    if (elapsedTime.count() >= moveTime) 
    {
        break;
    }
  }
  
    sleep(2); 
    return 0;
}
```

## Compiling the Application File

After completing the application logic, the next step is to compile the application file.

Add the compilation commands at the very bottom of the `unitree_go2_sdk/CMakeLists.txt` file to include the routine you just wrote and generate the corresponding executable file, then save the file.

```c++
    add_executable(app example/user/app_height.cpp)
target_link_libraries(app unitree_sdk2)
    
```

Finally, compile the routine. You can refer to the routine compilation section in the [Quick Start (快速开始)](https://support.unitree.com/home/zh/developer/Quick_start) chapter for compilation methods.

```c++
cd /home/unitree/unitree_go2_sdk
mkdir build
cd build
cmake ..
make
```

## Running the Application

Open a terminal and execute the following commands sequentially to run the application:

```c++
cd /home/unitree/unitree_go2_sdk/build
sudo ./app_height
```

\!\!\! note Note
This application forwards the control commands to the Go2 robot via the main motion control service. Therefore, ensure that the main motion control service is running normally before running this application. For details, please refer to the Quick Start and App Binding chapters.
\!\!\!

## More Applications

This is for posture control while the robot is in a standing state. Users can refer to the above process to try it themselves.

```c++
#include <unitree/robot/client/client.hpp>
#include <unitree/robot/go2/sport/sport_client.hpp>
#include <unistd.h>
#include <cmath>

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }
  //Initialize interface
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
  
  //Instantiate sport_client and initialize
  unitree::robot::go2::SportClient sport_client;
  sport_client.SetTimeout(10.0f);//Timeout duration
  sport_client.Init();
  sport_client.WaitLeaseApplied();
  double t=0;
  double dt=0.01;
  {
    t+=dt;
    sport_client.Euler(0.4*sin(2*t), 0.4*cos(2*t)-0.4, 0.); 
    sport_client.BalanceStand();
    usleep(int(dt*1000000));
  }
  return 0;
}
```

--- 

# App Binding

Unitree Go is an application tailored for Unitree Technology quadruped robots. Equipped with rich teaching resources, it helps you quickly understand and master the operating skills of quadruped robots, bringing endless fun. The Android and IOS system platforms support two control methods: touch screen and dedicated joystick. This section takes the Unitree Go App as an example to explain, and the specific interface is displayed on the corresponding platform.

## Function

**High definition image transmission**: It can ensure smooth 720p 60fps high-definition image transmission in a non-interference and unobstructed environment (depending on phone performance).
**Basic remote control**: It can control the robot to complete actions such as walking, running, climbing stairs, lying down, standing up, dancing, etc.
**Data View**：Real time display of various sensor data, including IMU information, dog leg information, and foot sensors.

## Download address

[https://www.unitree.com/app/go2](https://unitree.com/en/app/go2/)

## Binding a machine dog

### Register to log in

Download and open the Unitree Go App, register an account using email on the homepage login page, and log in.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/17/210918ea70f745dd824399574f79a36e_2532x1170.png)

</center>

### Add robot

Click on the homepage to add a robot

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/17/14fc2c72071748cb94cd9f400e309449_2532x1170.png)

</center>

Turn on the Go2 power, turn on the Bluetooth on your phone, and select the device you want to add for binding.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/17/e0303d169b864cdf91183c0a0f1c1e98_2532x1170.png)

</center>

Set robot information

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/17/782a5b48faa140b9b589189b0c26a7f3_2532x1170.png)

</center>

## Connecting robots

Go2 needs to establish a connection with the app. After binding the robot, you can see two modes of connection: AP router and Wi-Fi. Please connect according to your needs.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/17/fa64684cb520483ebfe5a45be3d3519f_2532x1170.png)

</center>

### AP router mode

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/17/01de12b758a145c1b1fdcd1b7afdd5bc_2532x1170.png)

</center>

Mobile connection to Go2 hotspot

Run the Unitree Go App, select AP router mode to establish a connection, and follow the prompts to set the hotspot name (GO2-XXXXXX) and 8-digit password.

Open the mobile wireless LAN, select the Wi Fi name you just set, and enter the password to complete the connection.

<center>
  
![1](https://doc-cdn.unitree.com/static/2023/10/19/31a5bca114f740618028024d11276313_1792x828.png)

</center>

After connecting, return to the Unitree Go App and click - I have completed, indicating that Go2 and App have successfully connected.
### Wi-Fi connection mode

<center>

![0](https://doc-cdn.unitree.com/static/2023/8/8/9dde1f7ae68549e0bf99b8447c735833_907x167.png)

</center>

Connect your phone to Go2 through a router

Run the Unitree Go App, select Wi Fi mode to establish a connection, select an existing Wi Fi network, and enter a password.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/17/38eb8cb9155d483abc5841533b7ac8f4_2532x1170.png)

</center>

Wait for the connection to complete.

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/19/a74faf19d60a4687afd68bc807221eff_1792x828.png)

![1](https://doc-cdn.unitree.com/static/2023/10/19/fb2926dadcd14933a9f2853cf566cdef.PNG)

</center>

After the Wi-Fi connection is completed, return to the homepage of the Unitree Go App, indicating that the connection between Go2 and the App is successful.

## Service status

You can view the current service status of the dog here, and click to turn on or off the specified service.

<center>

![1](https://doc-cdn.unitree.com/static/2023/8/28/9c14fb47df7048739e5902fac1a18b35_3138x1428.png)

</center>

## View corresponding sensor data

<center>

![1](https://doc-cdn.unitree.com/static/2023/8/28/2f055b6fee1b462e9f7f64a45ba07731_1397x705.png)

</center>

--- 

# Payload

# Electrical interface

![](https://doc-cdn.unitree.com/static/2024/5/14/7ca51de5cdc34b63bd6ff3a7ec74216b_1814x396.png)

|  **Interface**  |  **Meaning**  |
| --- | --- |
|  **XT30U-F Power Interface:**  | - 16V-45V (Peak 60V) input: 2 inputs (1 for powering the expansion dock internally, 1 for powering the robotic arm externally) <br>- 12V output: 1 output, current output 3A (1 output for external user)<br>- 5V output: 1 output, current output 3A (1 output for external user)      |
|  **Gigabit Ethernet Interface**  | - Total number of interfaces: 2 ports (standard RJ45 interfaces)<br>- Gigabit Ethernet: 1 channel connected to GO2, 1 channel externally connected to the user    |
|  **M8 Aviation Plug Interface<br> (Gigabit Ethernet + 12V Power)**  |  - Total number of interfaces: 1 port (standard European aviation plug interface)<br>- Gigabit Ethernet: 1 channel for radar-specific interface<br> - Power output: 1 channel 12V/2A output for powering the radar   |
|  **USB-Type A Interface**  |  - Total number of interfaces: 1 USB3.2 Gen2<br>- Supported modes: Only USB host<br>- Power output: Supports 5V/1A<br>- Transfer speed: Supports 10Gbps    |
|  **USB-DP Alt Mode Type-C Full-Featured Interface (USB+DP)**  |  - Total number of interfaces: 1 Type-C<br>- Supported modes: Supports USB host or DP Alternative Mode<br>* USB: Supports USB2.0 <br> *  DP: Supports DP1.4<br>- Power output: Supports 5V/3A<br>  |
|  **USB-Type-C Interface**  | - Total number of interfaces: 1 Type-C<br>- Interface type: Supports USB3.2 Gen2 <br>- Power output: Supports 5V/2A
   |
|  **GH1.25-4PIN Interface <br>(Gigabit Ethernet)**  |  - Total number of interfaces: 1 port<br> - Gigabit Ethernet: 1 channel externally connected to the user   |

![](https://doc-cdn.unitree.com/static/2023/12/4/2485b955598a4e7981d64c1ebb109d69_5889x2954.png)

# Install additional equipment

## Rail size

<center>

![1](https://doc-cdn.unitree.com/static/2024/1/23/77c28496348147a4a93103a1822ba812_1580x802.png)
</center>

## Install expansion dock

Step 1: Use the hex L-shaped wrench to remove the screws securing the back cover of the Go2, then open the back cover as shown in the figure below.
<center>

![1](https://doc-cdn.unitree.com/static/2023/12/1/193b76952c394bae830f15a37fcff4f6_6488x5075.png)

</center>

Step 2: Connect the power and Ethernet ports of the main body to the high-performance module's power and Ethernet ports, then secure the cables in the expansion dock cable groove, as shown in the figure below.

<center>

![1](https://doc-cdn.unitree.com/static/2023/12/1/697708f685ab4831a4d1823d87ee2a26_6488x5601.png)

</center>

Step 3: Use screws M3×50 to secure the expansion dock to the back of the Go2, as shown in the figure below.

<center>

![1](https://doc-cdn.unitree.com/static/2023/12/1/40b0ea796e5046fb90a59586ffdd860a_6488x5197.png)
  

</center>

Step 4: Secure the back cover of the main body to the expansion dock cover, as shown in the figure below.

<center>

![1](https://doc-cdn.unitree.com/static/2023/12/1/e3f41fe6e9644dc28e57483d1620173a_6488x5053.png)

</center>

Step 5: Installation complete.

<center>

![1](https://doc-cdn.unitree.com/static/2023/12/1/3596156fe57b4ce8a95247edf2a8cd5d_6488x4509.png)

</center>

## Installing a depth camera D435i

### List of items

|   |   |   |
| :---: | :---: | :---: |
|  ![0](https://doc-cdn.unitree.com/static/2023/10/11/68a84731d62c423eba1b6095923ce967_4066x1647.png) |  ![0](https://doc-cdn.unitree.com/static/2023/10/11/b74b0142d54f485d99e8d6795cf8ff2d_1310x1436.png)|  ![0](https://doc-cdn.unitree.com/static/2023/10/11/14ea5b79fd8f411a97d5b8107f420769_11829x4108.png)|
|Depth camera D435i * 1 | Depth camera fixed base * 1 | Type - C connector * 1|
|  ![0](https://doc-cdn.unitree.com/static/2023/10/11/308dda44909b49398952c863d6ab1313_4070x1938.png) |   ![0](https://doc-cdn.unitree.com/static/2023/10/11/0ceca8c62102413fb63664dae4a95a54_2852x2552.png) | ![0](https://doc-cdn.unitree.com/static/2023/10/11/0b67948c25f04eb0b92f71e1ef1f1ada_2057x1875.png)  |
|Depth camera support * 1 | Fixed plate 1 * 1 | Fixed plate 2 * 1|
| ![0](https://doc-cdn.unitree.com/static/2023/10/11/e720284e8b26485da2fe557494650e85_1510x1893.png)   |  ![0](https://doc-cdn.unitree.com/static/2023/10/11/0bc5d9f4fa2641999e7041e2bd8e7493_769x761.png)| ![0](https://doc-cdn.unitree.com/static/2023/10/11/682e4ddc41df418c93ddc1a143c9b1a0_1530x1983.png) |
|M3 screw * 2 | Shim * 2 | Fixing plate fastening screws * 2|
| ![0](https://doc-cdn.unitree.com/static/2023/10/11/4488e32189ad44b9b1e4627c0b49b8c6_4258x1687.png)
 |   |   |
|  Internal hexagonal L-shaped wrench * 1  |   |   |

!!! note Description:
Please be careful whether the items are complete and intact. All pictures in this manual are for reference only. If they do not match the actual items, please refer to the actual ones.
!!!

### Installation instructions

#### Step 1: Connect Type - C cable

Insert the Type - C connector into the depth camera interface first, and then pass through the depth camera support.

![](https://doc-cdn.unitree.com/static/2023/10/19/f867a49403634a5e98d6d26924670d8f_5362x3145.png)

!!! note Description:
Please insert the Type - C connection cable before proceeding to the next step. If the cable needs to be pulled out after installation, the fastening screw needs to be removed first, and do not forcefully pull to avoid damaging the cable!
!!! 
#### Step 2: Install fixing plate 1

Use two M3 screws to secure the fixing plate 1 and support to the hole position on the back of the depth camera, and then tighten it.

![](https://doc-cdn.unitree.com/static/2023/10/19/5a16f2cc708a43adbb517475606f3dd7_4918x3008.png)

#### Step 3: Install fixing plate 2

Use two fastening screws to pass through the hole position of fixing plate 1, the gasket, and fixing plate 2 in sequence, and then tighten them.
![](https://doc-cdn.unitree.com/static/2023/10/19/b11fa89e8569474e9ebdf60fbe9f2298_5349x2548.png)

There are four gears available for the fixed plate 1 hole position, which can adjust the camera height and angle range. Users can choose different gear heights and angles according to their needs, as shown in the following figure:

<center>

![](https://doc-cdn.unitree.com/static/2023/10/19/1993feef2f424051a0ca2b8ab6561592_5178x3964.png)

</center>

#### Step 4: Fixed depth camera to dog head

Remove the screw from the fixed hole of the head depth camera, used for fixing.

<center>

![4](https://doc-cdn.unitree.com/static/2023/12/1/636fd69cf33e431d92de098a04c2377f_2519x2237.png)

</center>

Place the fixed base on the Go2 head, aligning it with the head installation hole, use the removed screw to fix the depth camera to the GO2 head, and then tighten it. 

<center>

![1](https://doc-cdn.unitree.com/static/2023/12/1/d982e725356842c4be340c99bb4b8596_4318x2808.png)

</center>

#### Step5：Complete installation

Connect the other end of the Type-C cable to the docking station, complete installation。

<center>

![1](https://doc-cdn.unitree.com/static/2023/10/19/c93dc3dfef4747f7a75df2ac273f8a67_4195x3229.png)

</center>

## Installing radar

### Install MID-360 laser radar

Step 1: Use fastening screws to secure the laser radar in the position shown in the diagram.

<center>

  
![1](https://doc-cdn.unitree.com/static/2023/12/1/02252e52fd39471caab27aedaf9c1d46_760x853.png)

</center>

Step 2: Connect the laser radar interface to the M8 navigation interface on the expansion dock.

<center>

![1](https://doc-cdn.unitree.com/static/2023/12/1/65038909058b4df088961ea891aa037b_1003x924.png)

</center>

Step 3: Installation Completed.

### Install XT-16 laser radar

Step 1: Use fastening screws to secure the laser radar in the position shown in the diagram.

<center>

![1](https://doc-cdn.unitree.com/static/2023/12/1/8646d5d06cc849d9aae16664a6b8fb97_937x852.png)

</center>

Step 2: Connect the laser radar interface to the M8 navigation interface on the expansion dock.

<center>

![1](https://doc-cdn.unitree.com/static/2023/12/1/bed74e7be377497d8bfce22345eda4cf_1003x924.png)

</center>

Step 3: Installation Completed.

## Installing the Small Servo Arm

Step 1: Fixed Mechanical Arm: First, pass the square nut through the expansion dock guide rail, and then use M4*10 internal hexagon screws to fix the servo mechanical arm to the Go2 expansion dock guide rail, as shown in the picture position.
<center>
  
![1](https://doc-cdn.unitree.com/static/2023/11/23/934aaec6f3794b9da946dc7f45f7e36b_1299x862.png)

</center>

Step 2: Cable Connection: Connect the expansion dock power input interface to the servo mechanical arm power interface, and connect the expansion dock GP1.25-4PIN 100-megabit Ethernet port to the servo mechanical arm Ethernet port.

<center>

![1](https://doc-cdn.unitree.com/static/2023/11/23/94b66c3efdb44b05a9d09680d1aba76f_1278x862.png)

</center>

Complete installation.

<center>

![1](https://doc-cdn.unitree.com/static/2023/11/23/d5509063f2354db796cf533af01af4d8_5961x7048.png)

</center>

## The Charging Pile

### Installation of the charging pile

#### Items List

|  |  | |  |
| :-: |  :-:  |  :-:  |  :-:  |
| ![6](https://doc-cdn.unitree.com/static/2023/12/27/f422bcc7e1ae4b24ab11dfdd9337daa4_1344x730.png) | ![6](https://doc-cdn.unitree.com/static/2023/12/27/351d84bc056b4ceca8e35793e2c182bf_875x447.png) | ![6](https://doc-cdn.unitree.com/static/2023/12/27/373e83551cbc4bde85683af580a66bf7_877x453.png) | ![6](https://doc-cdn.unitree.com/static/2023/12/27/c501401deaca43bcbfcdbd304b7b741f_369x350.png) |
|Nameplate support ×1	|Nameplate ×1	|Charging board ×1	|Knurled hand screw M3*6 screws ×2|

#### Installation Instructions

Step 1: Install the nameplate by fixing the nameplate board to the nameplate support using the knurled hand screws.
![](https://doc-cdn.unitree.com/static/2023/12/27/f37c57c0252e420a8e9a273cb32402d0_3491x1664.png)

Step 2: Install the charging board by fixing it to the nameplate support.

![](https://doc-cdn.unitree.com/static/2023/12/27/35333914563542258081454aeaa372c8_4125x1921.png)

!!! note Note:

**<u>Please fix the charging board according to the indicated direction and do not install it in the opposite direction ！！!</u>**

!!!

### Instructions for use
Step 1: **Pre-charging check:** Before each charging, please check if there are any foreign objects obstructing the charging electrodes on the bottom of the Go2 body, as well as any obstructions on the surface of the charging board’s charging electrodes. Use a dry cloth to wipe the surface of the charging electrodes to ensure good contact during the charging process.

Step 2: **Connect the power:** Place the Go2 charging station in an open indoor area, first plug the fast charging charger into the AC power supply, and then connect the power interface on the bottom of the charging board. Secure the cable in the cable slot of the charging board as shown in the diagram.

![](https://doc-cdn.unitree.com/static/2023/12/27/be13bbf6711841a0b1373019d9c7c072_2424x1303.png)

Step 3: **Charging:** When using the charging station to charge, first place the Go2 in a prone position, aligning the head with the orientation of the nameplate on the charging station. This allows the two charging electrodes on the bottom of the Go2 to make contact with the two charging electrodes on the charging board to initiate charging. When the battery is fully charged, the charging station will automatically disconnect from the battery.

![](https://doc-cdn.unitree.com/static/2023/12/27/2927f4d242e74b3b8003c56ad423585e_1831x1478.png)

!!! note Note: 
The charging station has polarity, please align the head in the direction of the nameplate during charging and do not reverse it! If charging abnormalities occur, please check if the charging electrodes are in good contact.
!!!

LED Indicator Status

|Mode	|LED	|Status|
| :-: | :-: | :- |
| Charging complete | ![7](https://doc-cdn.unitree.com/static/2023/12/27/6123ac50cbc049b9b48ce06f46cb1375_111x52.png)| Constantly on |
| Charging in progress |![8](https://doc-cdn.unitree.com/static/2023/12/27/91d6e28f4a5549efb5f50c8047e438da_149x98.png) |Slow flashing at 500ms intervals |
 |Overcurrent protection/<br>Undervoltage protection | ![8](https://doc-cdn.unitree.com/static/2023/12/27/d70b5e0adc974e5dbe5ec77b43e8ba92_149x98.png) |	Rapid flashing 3 times at 100ms intervals, always on for 1.5 seconds, then continues rapid flashing |
|Idle state | ![7](https://doc-cdn.unitree.com/static/2023/12/27/171bad445c1443fcbc545fc4f25465ee_111x52.png)| 	Breathing state with changing brightness over time |

## Charging Pad - L1 Return Charge Guide

Use the Go2 charging pad with the corresponding return charge marking board to achieve the automatic return charge function based on Go2's built-in L1.

> New purchase of Unitree charging pad comes with an exclusive L1 return charge marking board. Currently applicable to Go2 App - 3D LiDAR mapping, and the SDK interface will be opened later.

### App Usage Tutorial
[Click here to view](https://oss-global-cdn.unitree.com/static/go2_tutorial/go2_tutorial_15_en.mp4)

### Installation Requirements

![](https://doc-cdn.unitree.com/static/2024/12/23/091cce5366ed40b1ae97a2d35d148b86_5165x3215.jpg) 

### Precautions

1. Before starting the mapping process, move the robot dog onto the charging pad (refer to the position reference diagram on the right side showing the robot dog and the charging pad). If no positioning board is placed, the robot dog will only return to the mapping starting point (the default setting for the mapping starting point is the charging point), and will not proceed with automatic charging.
2. Ensure that the charging pad is oriented correctly and is powered on properly.
3. If the return charge effect is not satisfactory, you may attempt to remap the environment. Please avoid placing the charging pad in a walkway with a width of less than 1 meter and ensure there are not many obstacles around it.
4. To ensure normal contact of the charging contact points, place the charging pad on a flat surface.
5. The final step of automatic return charging relies on the recognition capability of the L1  Lidar. If the L1 Lidar is dirty or damaged, it may affect the charging success rate. If you encounter any issues, please contact Unitree Technical Support.
6. If you have purchased a charging pad and wish to configure a positioning board on your own, please contact Unitree Technical Support to obtain the specifications and placement requirements for the positioning board.

--- 

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

--- 

# TouchScreen RC Supporting Instructions

The Go2 with a screen remote controller is compatible with accessories like dual cameras, three-in-one systems, dual-camera thermal imaging gimbals, enabling features such as HD image transmission, real-time audio transmission, recording upload, audio playback, text-to-speech, lighting functions (flash/constant/brightness adjustment), red/blue flashing modes, and more. Through voice prompts and red/blue warning lights, it provides safety alerts, promptly notifying users of environmental changes and potential dangers.

# Basic Functions

## Joystick Buttons

![](https://doc-cdn.unitree.com/static/2024/1/10/566ba9b606164945b6daf1c26b03787f_2226x1553.png)

![](https://doc-cdn.unitree.com/static/2024/1/10/bb4a35e407fe4b9dbbb733e3de6b5d2e_2226x705.png)

!!! note **Note**
1. After booting up and standing upright, please turn the right wheel/START to the right to unlock control! Otherwise, the Go2 cannot be operated with the buttons while locked.
2. Remember to reset the three-stage switch after completing the corresponding function to avoid misoperation.
!!!

## Control Modes

The screen remote controller is mapped similarly to the dual-hand controller. If you're familiar with the operation of the dual-hand controller, you can quickly adapt.

Briefly press the power button on the screen remote controller once, then press and hold the power button for **2** seconds or more to turn on the screen remote controller. Once the signal light turns green after booting up, you can use the screen remote controller to control the robot dog.

Command Reference:

<center>

![](https://doc-cdn.unitree.com/static/2025/9/25/432bf8b383f74eef81ce5f1675013acf_1365x1277.png)

</center>

# Compatible Accessories

## Dual Camera/Three-in-One

<center>

![1](https://doc-cdn.unitree.com/static/2024/1/10/72e79b297bdf4ddb9ebfbab65227bf4d_4685x4446.png)      ![1](https://doc-cdn.unitree.com/static/2024/1/10/8c161b8703e2451fb83f3b88724fd616_4686x5156.png)

</center>

### Camera

Run the SIYI FPV app, enter the settings menu, fill in the IP addresses of the front and rear cameras (192.168.144.25/192.168.144.26) in the address settings menu. Settings are preconfigured, open to display camera image transmission.

<center>

![3](https://doc-cdn.unitree.com/static/2024/1/10/ba5fa4e1c87b469f8da96c662accb940_1660x904.png)

</center>

### Voice Broadcasting

Click on the smart load icon on the remote controller's desktop, wait for about **30s**, return to the desktop. When the control icon appears on the desktop, it means the screen remote controller and the three-in-one receiver are successfully connected. You can now click on the desktop icon to control the Go2 three-in-one device.

![](https://doc-cdn.unitree.com/static/2024/1/10/9cffe0b712354d72b7ca9352fe673f13_2006x729.png)

<center>

</center>

The first floating window button can be used for real-time voice broadcasting, playing alarms, and adjusting the volume.
<center>

![3](https://doc-cdn.unitree.com/static/2024/1/10/560e27c4995244b3b375d7391325c86f_1660x904.png)

</center>

The second floating window button allows text-to-speech operations.

<center>

![3](https://doc-cdn.unitree.com/static/2024/1/10/f1557dcb49e145d89844ed55301ef77e_1660x904.png)

</center>

The third floating window button operates the recording function.

<center>

![3](https://doc-cdn.unitree.com/static/2024/1/10/060fdad63aa941d4913aac8c2d62847e_1659x904.png)

</center>

### Red/Blue Flashing Lights

The fourth floating window button controls lighting and red/blue flashing.

<center>

![3](https://doc-cdn.unitree.com/static/2024/1/10/7244cc9647b64c23b2ffa0c8bf98be0d_1660x904.png)

</center>

## Dual-Camera Thermal Imaging Gimbal

<center>

![1](https://doc-cdn.unitree.com/static/2024/1/10/dc00082a2068484c9be512191da801af_4521x5086.png)
</center>

Run the SIYI FPV app (APP version >= 2.5.15.691), enter the settings menu, fill in the IP address of the dual-camera thermal imaging gimbal (192.168.144.29) to display RGB/thermal imaging screens. Use **swiping up/down/left/right on the screen** to operate the gimbal and capture angles.
<center>

![3](https://doc-cdn.unitree.com/static/2024/1/10/20c0fb79ad014e1387b3860af8e1419c_1660x904.png)
</center>

For more gimbal settings, click on the settings button on the top right of the app.

<center>

![3](https://doc-cdn.unitree.com/static/2024/1/10/371aad6a5c4146e39f3ef6661d39c57e_1659x904.png)

</center>

# Troubleshooting

## Abnormal Use of Screen Remote Controller

When powering on, unlock the Go2 by turning the right wheel/START to the right. Otherwise, the Go2 cannot be controlled by the remote commands when locked! 
During screen remote controller usage, do not activate low battery mode! If any abnormalities occur during usage, disable low battery mode.
【System Settings】->【Battery Management】-> Turn off low battery mode.

## Smart Load App Failure to Connect to Go2

After entering the Smart Load App, wait for approximately 30s. If the control floating window does not appear upon returning to the desktop, it means no connection has been established. Please restart the screen remote controller and try connecting again.

## Other Device Connection Issues

Check if other device IPs are conflicting. After changing IPs, attempt to reconnect.

The following IPs are already in use:

| IP Address      | Device Name     |
| :--------------- | :--------------- |
| 192.168.144.11  | Sky End         |
| 192.168.144.12  | Ground End      |
| 192.168.144.20  | Remote Control  |
| 192.168.144.23  | Three-in-One    |
| 192.168.144.25  | Camera 1        |
| 192.168.144.26  | Camera 2        |
| 192.168.144.29  | Dual-Camera Thermal Imaging Gimbal |

--- 

# Motion Services Interface V2.0

!!! note  Attention:

### Motion Control Service Interface V2.0 Update Notice

**Release Date**: May 12, 2025  
**Version Update Content**: Go2 officially releases V1.1.6. This update primarily involves adjustments to high-level motion control interfaces and calling logic, with corresponding SDK updates.

---

#### Compatibility Instructions

- **Applicability**: This document's interfaces apply to **Go2 Edu models** with software version ≥ V1.1.6. 
- **SDK Update**: Before calling interfaces, ensure you update [unitree_sdk2](https://github.com/unitreerobotics/unitree_sdk2) to the latest version.

---

#### Version Check & Compatibility

- **Version Check**: Use the **Unitree App** to check your device's current software version.  
- If your Go2 software version is below V1.1.6, refer to these legacy documents:  
  - [Motion Switcher Service Interface](https://support.unitree.com/home/en/developer/Motion%20Switcher%20Service%20Interface)  
  - [High-Level Motion Service Interface](https://support.unitree.com/home/en/developer/sports_services)  
  - [AI Motion Service Interface](https://support.unitree.com/home/en/developer/AI_motion_service)  

---

Thank you for your support! For questions, [contact official technical support](https://global-serviceconsole.unitree.com/#/).  

!!!

# Introduction

The high-level interface of operation control service is divided into two parts: high-level control interface and high-level status interface.

- **High-level control interface**: By calling the `sport_client` of the SDK, motion commands such as mode switching and speed control can be sent to Go2.
- **High-level status interface**: By subscribing to the `sportmodestate` message in the SDK, you can obtain the motion status of Go2, including its position, speed, attitude, and current motion mode.

# High-level control interface

## Call method of high-level control interface

```C++

#include <unitree/robot/go2/sport/sport_client.hpp>
#include <unistd.h>

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
  // argv[1] is passed from the terminal and represents the network interface name of the robot's connection

  // Create a sport client object
  unitree::robot::go2::SportClient sport_client;
  sport_client.SetTimeout(10.0f); // Set timeout
  sport_client.Init();

  sport_client.Sit(); // Special action: the robot sits down
  sleep(3); // Delay for 3 seconds
  sport_client.RiseSit(); // Recover
  sleep(3);

  return 0;
}

```

## Introduction to High-Level Motion Control Interfaces

The high-level control interface can achieve control of Go2's posture, speed, somersaults, jumps, handstands, and more. Below is a list of related functions for the motion control interface.

| **Function Name**   | **Damp**                                                                                   |
|---------------------|--------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t Damp()`                                                                          |
| **Function Overview**| Enter damping state.                                                                      |
| **Parameters**      | None                                                                                      |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                      |
| **Notes**           | All motor joints stop moving and enter damping state. This mode has the highest priority and is used for emergency stops in unexpected situations. |

| **Function Name**   | **BalanceStand**                                                                                                    |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t BalanceStand()`                                                                                             |
| **Function Overview**| Release lock.                                                                                                       |
| **Parameters**      | None                                                                                                                                               |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | Release the joint motor lock and switch from normal standing mode to balance standing mode. In this mode, the robot's posture and height will remain balanced regardless of terrain. You can control the robot's posture by calling the Euler() interface (see corresponding sections in the table). |

| **Function Name**   | **StopMove**                                                                                                         |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t StopMove()`                                                                                                 |
| **Function Overview**| Stop the current movement and reset most parameters to their default values.                                        |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | Stops the current motion and resets the internal motion parameters of Go2 to their default values.                  |

| **Function Name**   | **StandUp**                                                                                                         |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t StandUp()`                                                                                                  |
| **Function Overview**| Lock joints and stand tall.                                                                                         |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | The robot stands tall with locked joints. Unlike the balance standing mode, the robot's posture will not remain balanced in this mode. The default standing height is 0.33m. Locked posture can easily cause motor overheating, so please unlock in time. |

| **Function Name**   | **StandDown**                                                                                                        |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t StandDown()`                                                                                                 |
| **Function Overview**| Lock joints and crouch low.                                                                                         |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | The robot crouches low with locked joints.                                                                          |

| **Function Name**   | **RecoveryStand**                                                                                                    |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t RecoveryStand()`                                                                                              |
| **Function Overview**| Recover to standing position.                                                                                       |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | Recover from a fallen or crouched state to a balanced standing position. Regardless of whether it is fallen or not, it will recover to standing. |

| **Function Name**   | **Euler**                                                                                                            |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t Euler(float roll, float pitch, float yaw)`                                                                 |
| **Function Overview**| Posture during standing and walking.                                                                                |
| **Parameters**      | **roll:** Range \[-0.75~0.75\] (rad); **pitch:** Range \[-0.75~0.75\] (rad); **yaw:** Range \[-0.6~0.6\] (rad).       |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | Set the robot's posture angle during balanced standing or movement. The Euler angles are represented in the order of rotation around the robot's relative axes and z-y-x. |

| **Function Name**   | **Move**                                                                                                             |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t Move(float vx, float vy, float vyaw)`                                                                       |
| **Function Overview**| Movement control.                                                                                                   |
| **Parameters**      | **vx:** Range \[-2.5~3.8\] (m/s); **vy:** Range \[-1.0~1.0\] (m/s); **vyaw:** Range \[-4~4\] (rad/s).                 |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | Control movement speed. The set speed is represented in the robot's coordinate system. The Move interface has two characteristics: (1) The motion control part does not filter the Move command; (2) The latest Move command will be maintained for 1 second. Recommendation: When using this interface, apply filtering before sending; when not using Move, send Move(0,0,0) or StopMove(). |

| **Function Name**   | **Sit**                                                                                                              |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t Sit()`                                                                                                       |
| **Function Overview**| Sit down.                                                                                                            |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | Special action: the robot sits down. Note that special actions should be executed only after the previous action has been completed; otherwise, it may cause abnormal actions. |

| **Function Name**   | **RiseSit**                                                                                                          |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t RiseSit()`                                                                                                   |
| **Function Overview**| Stand up (relative to sitting).                                                                                     |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | Recover from a sitting state to a balanced standing position.                                                        |

| **Function Name**   | **SpeedLevel**                                                                                                       |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t SpeedLevel(int level)`                                                                                      |
| **Function Overview**| Set speed level.                                                                                                    |
| **Parameters**      | **level:** Speed level enumeration value, -1 for slow, 0 for normal, and 1 for fast.                                  |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           |                                                                                                                      |

| **Function Name**   | **Hello**                                                                                                            |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t Hello()`                                                                                                     |
| **Function Overview**| Greet.                                                                                                               |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           |                                                                                                                      |

| **Function Name**   | **Stretch**                                                                                                          |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t Stretch()`                                                                                                    |
| **Function Overview**| Stretch.                                                                                                             |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           |                                                                                                                      |

| **Function Name**   | **SwitchJoystick**                                                                                                   |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t SwitchJoystick(bool flag)`                                                                                   |
| **Function Overview**| Enable or disable the native joystick response.                                                                     |
| **Parameters**      | **flag:** Set to true to enable the native joystick response, and false to disable it.                               |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           | After disabling the joystick response, moving the joystick will not interfere with the current program's operation. |

| **Function Name**   | **Content**                                                                                                          |
|---------------------|---------------------------------------------------------------------------------------------------------------------|
| **Prototype**       | `int32_t Content()`                                                                                                   |
| **Function Overview**| Express happiness.                                                                                                   |
| **Parameters**      | None                                                                                                                |
| **Return Value**    | Returns 0 on successful call, otherwise returns relevant error code.                                                 |
| **Notes**           |                                                                                                                      |

| **Function Name**   | **Heart**                            |
|--------------------|-------------------------------------|
| **Prototype**      | `int32_t Heart()`                     |
| **Function Overview**| Make a heart shape with paws.       |
| **Parameters**     | None                                |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          |                                     |

| **Function Name**   | **Pose**                                   |
|--------------------|--------------------------------------------|
| **Prototype**      | `int32_t Pose(bool flag)`                  |
| **Function Overview**| Strike a pose.                            |
| **Parameters**     | **flag:** Set to `true` to strike a pose, `false` to return to normal stance. |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          |                                           |

| **Function Name**   | **Scrape**                            |
|--------------------|---------------------------------------|
| **Prototype**      | `int32_t Scrape()`                     |
| **Function Overview**| Bow as a greeting.                    |
| **Parameters**     | None                                  |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          |                                       |

| **Function Name**   | **FrontFlip**                         |
|--------------------|---------------------------------------|
| **Prototype**      | `int32_t FrontFlip()`                  |
| **Function Overview**| Perform a front flip.                |
| **Parameters**     | None                                  |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | This action is potentially dangerous. Please maintain a safe distance from others before execution to ensure personal safety. Note that Unitree Technology will not be liable for any accidents caused by improper operation. Additionally, this action may accelerate hardware damage and reduce its lifespan. Use with caution. |

| **Function Name**   | **FrontJump**                         |
|--------------------|---------------------------------------|
| **Prototype**      | `int32_t FrontJump()`                  |
| **Function Overview**| Perform a front jump.                |
| **Parameters**     | None                                  |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          |                                       |

| **Function Name**   | **FrontPounce**                       |
|--------------------|---------------------------------------|
| **Prototype**      | `int32_t FrontPounce()`                |
| **Function Overview**| Lunge forward.                       |
| **Parameters**     | None                                  |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          |                                       |

| Function Name | Dance1                               |
|---------------|--------------------------------------|
| Function Prototype     | `int32_t Dance1()`           |
| Overview      | Dance Sequence 1          |
| Parameters    | None.                                |
| Return Value  | Returns 0 on success, otherwise returns the relevant error code. |
| Remarks       |  |

| **Function Name**   | **FreeBound**                                           |
| ------------ | ------------------------------------------------------------ |
| **Function Prototype** | `int32_t FreeBound(bool flag)`                            |
| **Overview** | Bound Run Mode.                                                   |
| **Parameters**     | flag: Set to true to enter bound run; set to false to exit bound run and enter agile mode.                     |
| **Return Value**   | Returns 0 on success, otherwise returns the relevant error code.                        |
| **Remarks**     | Enters bound run mode. Bound gait.|
| **Function Name**   | **FreeJump**                                           |
| ------------ | ------------------------------------------------------------ |
| **Function Prototype** | `int32_t FreeJump(bool flag)`                         |
| **Overview** | Jump Mode.                                                   |
| **Parameters**     | flag: Set to true to enter jump mode; set to false to exit jump mode and enter agile mode.                     |
| **Return Value**   | Returns 0 on success, otherwise returns the relevant error code.                        |
| **Remarks**     | Enters jump mode. Jump-running gait.|

| **Function Name**   | **FreeAvoid**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t FreeAvoid(bool flag)`                            |
| **Function Overview**| Enter avoidance mode.                                    |
| **Parameters**     | **flag:** Set to `true` to enter avoidance mode, `false` to exit and enter agile mode. |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | In this mode, the robot can avoid obstacles while moving; when stationary, it can dodge objects in front of it. |

| **Function Name**   | **WalkUpright**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t WalkUpright(bool flag)`                           |
| **Function Overview**| Enter rear-leg standing mode.                              |
| **Parameters**     | **flag:** Set to `true` to enter rear-leg standing mode, `false` to exit and enter agile mode. |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | Entering rear-leg standing mode.<BR> The motors in this gait are prone to overheating, so please manage your business logic to avoid robot falls due to motor overheating. |

| **Function Name**   | **CrossStep**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t CrossStep(bool flag)`                          |
| **Function Overview**| Enter cross-step mode.                                  |
| **Parameters**     | **flag:** Set to `true` to enter cross-step mode, `false` to exit and enter agile mode. |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | Entering cross-step mode.<BR> The motors in this gait are prone to overheating, so please manage your business logic to avoid robot falls due to motor overheating. |

| **Function Name**   | **AutoRecoverSet**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t AutoRecoverSet(bool flag)`                          |
| **Function Overview**| Enable or disable auto-recovery.                            |
| **Parameters**     | **flag:** Set to `true` to enable auto-recovery, `false` to disable it. |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | When the device has a payload, it is recommended to disable this setting. If the device falls and flips violently, it may damage the payload, such as the gimbal, camera, and other sensors installed on the robot's head. To avoid this, please make sure to disable this setting. |

| **Function Name**   | **AutoRecoverGet**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t AutoRecoverGet(bool& flag)`                         |
| **Function Overview**| Check if auto-recovery is enabled.                          |
| **Parameters**     | None.                     |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. `flag` is `true` if auto-recovery is enabled, `false` if disabled. |
| **Notes**          | |

| **Function Name**   | **ClassicWalk**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t ClassicWalk(bool flag)`                           |
| **Function Overview**| Enter classic gait mode.                                  |
| **Parameters**     | **flag:** Set to `true` to enter classic gait mode, `false` to exit and enter agile mode. |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | AI-classic gait, with strong adaptability to complex terrain, supports climbing stairs, gravel, meadows, and slippery surfaces. The walking posture is stable and elegant. |

| **Function Name**   | **TrotRun**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t TrotRun()`                                      |
| **Function Overview**| Enter regular running mode.                              |
| **Parameters**     | None.                     |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | Running gait, with a maximum speed of 3.7m/s. This gait is somewhat risky due to its high speed, so please operate with caution. It does not have the ability to handle complex terrain, so it is prone to falling on uneven ground. |

| **Function Name**   | **StaticWalk**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t StaticWalk()`                                    |
| **Function Overview**| Enter regular walking mode.                              |
| **Parameters**     | None.                     |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | The default gait of the original regular mode, this gait does not have the ability to handle complex terrain, but the walking posture is elegant. |

| **Function Name**   | **EconomicGait**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t EconomicGait()`                                   |
| **Function Overview**| Enter regular endurance mode.                              |
| **Parameters**     | None.                     |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | The robot's height is higher in this mode, and the rate of power consumption is slower, which can extend the usage time. A single long-endurance battery can last up to 4 hours on a full charge. |

| **Function Name**   | **SwitchAvoidMode**                                           |
|--------------------|------------------------------------------------------------|
| **Prototype**      | `int32_t SwitchAvoidMode()`                                  |
| **Function Overview**| In avoidance mode, disable obstacle avoidance in front when the joystick is not pushed, as well as obstacle avoidance behind. |
| **Parameters**     | None.                     |
| **Return Value**   | Returns 0 on successful call, otherwise returns relevant error code. |
| **Notes**          | It is generally not recommended to use this mode. If you need to use it, please understand the function overview. |

The interface error codes are as follows:
| **Error Code** | **Description**     |
|---------------|---------------------|
| 4101          | Trajectory point count error, returned by the client. |
| 4201          | Action timeout error, the specified action was not completed within the expected time. |
| 4205          | State machine not initialized. |
| 4206          | Robot posture is not suitable for performing waving or bowing actions, so they are not executed. |
| 3104          | DDS timeout. |

## Example

Below is an example of controlling the robot dog to achieve posture control while standing.

```c++

#include <cmath>
#include <signal.h>
#include <unistd.h>

#include <unitree/robot/go2/sport/sport_client.hpp>

bool stopped = false;

void sigint_handler(int sig)
{
  if (sig == SIGINT)
  {
    stopped = true;
  }
}

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
  // argv[1] is the network interface name passed from the terminal

  // Create a sport_client object
  unitree::robot::go2::SportClient sport_client;
  sport_client.SetTimeout(10.0f); // Set timeout
  sport_client.Init(); // Initialize sport client

  double t = 0; // Program running time
  double dt = 0.01; // Control step size

  // Create a signal object to capture the program exit signal
  signal(SIGINT, sigint_handler);

  while (1)
  {
    t += dt;
    // Posture tracking a trigonometric function trajectory
    sport_client.Euler(0.2 * sin(2 * t), 0.2 * cos(2 * t) - 0.2, 0.);
    sport_client.BalanceStand();
    usleep(int(dt * 1000000));
    if(stopped)
    {
      break;
    }

  }
  // Reset posture when the program exits
  sport_client.Euler(0, 0, 0);
  return 0;
}

```

# High-Level Status Interface

## Calling Method of the High-Level Status Interface

By subscribing to the "rt/sportmodestate" topic, you can obtain the robot's position, speed, posture, and other motion states.

```C++

#include <unitree/idl/go2/SportModeState_.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>

// High-level status topic, where rt indicates real-time and lf indicates low frequency
#define TOPIC_HIGHSTATE "rt/sportmodestate"

using namespace unitree::robot;

// Callback function to obtain motion status
void HighStateHandler(const void* message)
{
  unitree_go::msg::dds_::SportModeState_ state = *(unitree_go::msg::dds_::SportModeState_*)message;

  // Print the robot's position
  std::cout<<"position: "
           <<state.position()[0]<<", "
           <<state.position()[1]<<", "
           <<state.position()[2]<<std::endl;
  // Print the robot's posture quaternion (w,x,y,z)
  std::cout<<": "
           <<state.imu_state().quaternion()[0]<<", "
           <<state.imu_state().quaternion()[1]<<", "
           <<state.imu_state().quaternion()[2]<<", "
           <<state.imu_state().quaternion()[3]<<std::endl;
}

int main()
{
  // Initialize the SDK interface
  std::string networkInterface = "enp2s0"; // Network interface name connected to the robot
  unitree::robot::ChannelFactory::Instance()->Init(0, networkInterface);

  // Create a Subscriber
  ChannelSubscriber<unitree_go::msg::dds_::SportModeState_> suber(TOPIC_HIGHSTATE);

  // Initialize Channel
  suber.InitChannel(HighStateHandler);

  while(1)
  {
    usleep(20000);
  }

  return 0;
}

```

## Introduction to High-Level Status Types

The method to obtain the high-level status is as follows:

```c++
TimeSpec stamp(); 
uint32_t error_code(); // Current mode (since there are many modes, this member variable is used to feedback information)
IMU imu_state(); // IMU status
std::array<float, 3> position(); // 3D position
float body_height(); // Body height
std::array<float, 3> velocity(); // 3D velocity
float yaw_speed(); // Yaw speed
```

The method to obtain the IMU data is as follows:

```C++

std::array<float, 4> quaternion();     // Quaternion (w,x,y,z)
std::array<float, 3> gyroscope();      // Angular velocity (unit: rad/s)
std::array<float, 3> accelerometer();  // Acceleration m/(s^2)
std::array<float, 3> rpy();            // Euler angles (unit: rad)
int8_t temperature(); // Temperature
```

In the "rt/sportmodestate" topic, the motion state machine corresponding to the `error_code` field is shown in the table below.

<table style="width: 100%;">
  <tr style="background-color: #f0f0f0;">
    <th style="width: 50%;">error_code</th>
    <th style="width: 50%;">State Machine Name</th>
  </tr>
  <tr>
    <td>100</td> <td>Agile</td></td>
  </tr>
  <tr>
    <td>1001</td> <td>Damping</td>
  </tr>
  <tr>
    <td>1002</td> <td>Standing Lock</td>
  </tr>
  <tr>
    <td>1004/2006</td> <td>Crouch</td>
  </tr>
  <tr>
    <td>1006</td> <td>Greeting/Stretching/Dancing/Bowing/Heart Shape/Happy</td>
  </tr>
  <tr>
    <td>1007</td> <td>Sit</td>
  </tr>
  <tr>
    <td>1008</td> <td>Front Jump</td>
  </tr>
  <tr>
    <td>1009</td> <td>Lunge</td>
  </tr>
  <tr>
    <td>1013</td> <td>Balance Standing</td>
  </tr>
  <tr>
    <td>1015</td> <td>Regular Walking</td>
  </tr>
  <tr>
    <td>1016</td> <td>Regular Running</td>
  </tr>
  <tr>
    <td>1017</td> <td>Regular Endurance</td>
  </tr>
  <tr>
    <td>1091</td> <td>Strike a Pose</td>
  </tr>
  <tr>
    <td>2007</td> <td>Dodge</td>
  </tr>
  <tr>
    <td>2008</td> <td>Bound Run</td>
  </tr>
  <tr>
    <td>2009</td> <td>Jump Run</td>
  </tr>
  <tr>
    <td>2010</td> <td>Classic</td>
  </tr>
  <tr>
    <td>2011</td> <td>Handstand</td>
  </tr>
  <tr>
    <td>2012</td> <td>Front Flip</td>
  </tr>
  <tr>
    <td>2013</td> <td>Back Flip</td>
  </tr>
  <tr>
    <td>2014</td> <td>Left Flip</td>
  </tr>
  <tr>
    <td>2016</td> <td>Cross Step</td>
  </tr>
  <tr>
    <td>2017</td> <td>Upright</td>
  </tr>
  <tr>
    <td>2019</td> <td>Towing</td>
  </tr>
</table>

--- 

# DDS Services Interface

# Introduction to Unitree Go2 Sdk

**unitree_sdk2** It is a layer of encapsulation on DDS that supports QoS configuration of DDS components, provides a simple encapsulation interface for application development, and implements an RPC mechanism based on DDS Topic. It is suitable for data communication in different scenarios through publish/subscribe and request/response methods between internal and external processes in Go2.

!!! note Explanation:
**unitree_sdk2** The installation and configuration tutorial will not be repeated in this article. Please refer to the "[Quick Start](https://support.unitree.com/home/en/developer/Quick_start)" section

!!!

# Interface Description

## unitree::robot::ChannelFactory

`unitree::robot::ChannelFactory` provides a single instance of ChannelFactory under Unitree:: robot to create a DDS Topic based Channel. ChannelFactory must call the initialization interface before use to initialize the underlying DDS configuration. The calling method is as follows
`unitree::robot::ChannelFactory::Instance()->Init(0)`

The descriptions of each interface are as follows:

|  **Function Name**  |  **Instance**  |
| :---: | :--- |
|  **Function Prototype**  |  static  unitree::robot::ChannelFactory\* unitree::robot::ChannelFactory::Instance()  |
|  **Functional Overview**  |  Obtain a singleton static pointer  |
|  **Parameters**  |  **None**  |
|  **Return Value**  |  Unitree::robot::ChannelFactory singleton static pointer  |
|  **Remarks**  |   |

|  **Function Name**  |  **Init**  |
| :---: | :--- |
|  **Function Prototype**  |  void Init(int32\_t domainId, const std::string& networkInterface = "", bool enableSharedMemory = false)  |
|  **Functional Overview**  |  Initialize ChannelFactory by specifying three initialization parameters: Domain Id, network card name, and whether to use shared memory.  |
|  **Parameters**  |  **domainId**: Default domain id for constructing DdsParticipant；<BR> **networkInterface**: Specify the network card name, default to blank; <BR> **enableSharedMemory**: Whether to use shared memory, default to false.  |
|  **Return Value**  |  None  |
|  **Remarks**  |  If the **networkInterface** is empty, automatic selection of network card configuration will be generated; When developing applications outside of Go2, enableSharedMemory needs to be set to false.  |
 
|  **Function Name**  |  **Init**  |
| :---: | :--- |
|  **Function Prototype**  |  void Init(const std::string& ddsParameterFileName = "")  |
|  **Functional Overview**  |  Initialize DdsParticipant by specifying a configuration file.  |
|  **Parameters**  |  **ddsParameterFileName**: Specify a configuration file path in JSON format. When ddsParameterFileName is empty, The default is the configuration file named dds\_parameter.json in the current program directory.  |
|  **Return Value**  |  None  |
|  **Remarks**  |  If the file does not exist, an exception will be thrown indicating that the configuration file does not exist; If the specified network is not available, a DDS exception will be thrown.  |

|  **Function Name**  |  **Init**  |
| :---: | :--- |
|  **Function Prototype**  |  void Init(const JsonMap& param)  |
|  **Functional Overview**  |  Specify JsonMap configuration to initialize DdsParticipant.  |
|  **Parameters**  |  **param** JsonMap format configuration.  |
|  **Return Value**  |  None  |
|  **Remarks**  |  If the specified network is not available, a DDS exception will be thrown.  |

|  **Function Name**  |  CreateSendChannel  |
| :---: | :--- |
|  **Function Prototype**  |  template<typename MSG> ChannelPtr<MSG> CreateSendChannel(const std::string& name)  |
|  **Functional Overview**  |  Specify name to create a Channel with a specified message type of MSG for sending data.  |
|  **Parameters**  |  **name**：Channel Name.  |
|  **Return Value**  |  template<typename MSG> ChannelPtr<MSG>   |
|  **Remarks**  |   |

|  **Function Name**  |  CreateRecvChannel  |
| :---: | :--- |
|  **Function Prototype**  |  template<typename MSG> ChannelPtr<MSG> CreateRecvChannel(const std::string& name, std::function<void(const void\*)> callback, int32\_t queuelen = 0)  |
|  **Functional Overview**  |  Specify name to create a Channel with a specified message type of MSG for receiving data.  |
|  **Parameters**  |  **name**：Channel Name；<BR> **callback**: callback function when the message arrives; <BR> **queuelen**: The length of the message cache queue; If the length is 0, do not enable columns in the message cache.  |
|  **Return Value**  |  template<typename MSG> ChannelPtr<MSG>   |
|  **Remarks**  |  If the message takes a long time to process in the callback function, it is recommended to enable the message cache queue to avoid blocking the DDS callback thread.  |

|  **Function Name**  |  **Release**  |
| :---: | :--- |
|  **Function Prototype**  |  void Release()  |
|  **Functional Overview**  |  Release ChannelFactory static resources.  |
|  **Parameters**  |  None  |
|  **Return Value**  |  None  |
|  **Remarks**  |  unitree::robot::ChannelFactory::Instance()->Release()  |

## unitree::robot::ChannelPublisher

`unitree::robot::ChannelPublisher` Class implements the message publishing function of the specified type

|  Class name  |  Constructors and Destructors  |
| :---: | :--- |
|  template<typename MSG> ChannelPublisher  |  explicit ChannelPublisher(const std::string& channelName); ~ChannelPublisher()  |

!!! note Explanation:
unitree::robot::ChannelPublisher Used during construction unitree::robot::ChannelFactory::Instance()->CreateSendChannel<MSG>(mChannelName)，So when using unitree::robot::ChannelPublisher Before that, you need to initialize the unitree::robot::ChannelFactory singleton.
!!!

|  **Function Name**  |  **InitChannel**  |
| :---: | :--- |
|  **Function Prototype**  |  void InitChannel()  |
|  **Functional Overview**  |  Initialize the Channel and prepare it for sending messages.  |
|  **Parameters**  |  None  |
|  **Return Value**  |  None  |
|  **Remarks**  |   |

|  **Function Name**  |  **CloseChannel**  |
| :---: | :--- |
|  **Function Prototype**  |  void CloseChannel()  |
|  **Functional Overview**  |  Close Channel  |
|  **Parameters**  |  None  |
|  **Return Value**  |  None  |
|  **Remarks**  |   |

|  **Function Name**  |  **Write**  |
| :---: | :--- |
|  **Function Prototype**  |  bool Write(const MSG& msg)  |
|  **Functional Overview**  |  Send a specified type of message.  |
|  **Parameters**  |  msg: Send a message of type MSG.  |
|  **Return Value**  |  true: Successfully sent; false: Sending failed.  |
|  **Remarks**  |   |

## unitree::robot::ChannelSubscriber

`unitree::robot::ChannelSubscriber` Implemented the specified type of message subscription function.

|  **Class Name**  |  Constructors and Destructors  |
| :---: | :--- |
|  template<typename MSG> ChannelSubscriber  |  explicit ChannelSubscriber(const std::string& channelName); ~ChannelSubscriber()  |

!!! note  Attention:
unitree::robot::ChannelSubscriber Used during construction unitree::robot::ChannelFactory::Instance()->CreateSendChannel<MSG>(mChannelName)，So when using unitree::robot::ChannelSubscriber initialization is required before proceeding unitree::robot::ChannelFactory singleton。
!!!

|  **Function Name**  |  **InitChannel**  |
| :---: | :--- |
|  **Function Prototype**  |  void InitChannel(const std::function<void(const void\*)>& callback, int64\_t queuelen = 0)  |
|  **Functional Overview**  |  Initialize the Channel and prepare it for receiving or processing messages.  |
|  **Parameters**  |  **callback**: callback function when the message arrives; <BR> **queuelen**: The length of the message cache queue; If the length is 0, do not enable columns in the message cache.  |
|  **Return Value**  |  None  |
|  **Remarks**  |  If the message takes a long time to process in the callback function, it is recommended to enable the message cache queue to avoid blocking the DDS callback thread.  |

|  **Function Name**  |  **CloseChannel**  |
| :---: | :--- |
|  **Function Prototype**  |  void CloseChannel()  |
|  **Functional Overview**  |  Close Channel。  |
|  **Parameters**  |  None  |
|  **Return Value**  |  None  |
|  **Remarks**  |   |

|  **Function Name**  |  **GetLastDataAvailableTime**  |
| :---: | :--- |
|  **Function Prototype**  |  int64\_t GetLastDataAvailableTime()  |
|  **Functional Overview**  |  Gets the last time a message was received.  |
|  **Parameters**  |  None  |
|  **Return Value**  |  Returns -1 when the Channel is not initialized; Otherwise, it returns a timestamp that monotonically increments from 0 starting from system startup, accurate to microseconds.  |
|  **Remarks**  |   |

# Go2 Service Client Interface

Multiple service components within Go2 provide partial functional interfaces through RPC Client, allowing users to easily access Control or data acquisition of Go2.

### List of some general error codes

|  Number |  Error description |  Remarks  |
| :---: | :---: | :---: |
|  3001  |  Unknown error  |  Client/server returned  |
|  3102  |  Request sending error | Client returned  |
|  3103  |  API not registered  |  Client returned  |
|  3104  |  Request timeout  |  Client returned  |
|  3105  | Request and response data do not match |  Client returned  |
|  3106  |   Invalid response data  |  Client returned  |
|  3107  |   Invalid lease   |  Client returned  |
|  3201  |  Response sending error  |  Occurred on the server and will not be returned to the client  |
|  3202  |  Internal server error  | Server returned  |
|  3203  |  API not implemented on the server  |  Server returned |
|  3204  |  API parameter error  |  Server returned  |
|  3205  |  Request rejected  |  Server returned  |
|  3206  |  Invalid lease  |  Server returned  |
|  3207  |  Lease already exists |  Server returned  |

### Partial Client Common Interface Description

|  **Function Name**  |  **Init**  |
| :---: | :--- |
|  **Function Prototype**  |  void Init()  |
|  **Functional Overview**  | Client initialization, completing logic such as client API registration.  |
|  **Parameters**  |  None  |
|  **Return Value**  |  None  |
|  **Remarks**  |   |

|  **Function Name**  |  **SetTimeout**  |
| :---: | :--- |
|  **Function Prototype**  |  void SetTimeout(float timeout)  |
|  **Functional Overview**  |  Set the RPC request timeout time.  |
|  **Parameters**  |  timeout: in seconds.  |
|  **Return Value**  |  None  |
|  **Remarks**  |  If no timeout is set, the default timeout time is 1 second.  |

|  **Function Name**  |  **WaitLeaseApplied**  |
| :---: | :--- |
|  **Function Prototype**  |  void WaitLeaseApplied()  |
|  **Functional Overview**  | Applying for a lease, the function will block until the lease is applied for.  |
|  **Parameters**  |  None  |
|  **Return Value**  |  None  |
|  **Remarks**  |  Only valid when lease is enabled.  |

|  **Function Name**  |  **GetApiVersion**  |
| :---: | :--- |
|  **Function Prototype**  |  const std::string& GetApiVersion()  |
|  **Functional Overview**  |  Obtain the client API version.  |
|  **Parameters**  |  None  |
|  **Return Value**  |  Returns the client API version.  |
|  **Remarks**  |   |

|  **Function Name**  |  **GetApiServerVersion**  |
| :---: | :--- |
|  **Function Prototype**  |  const std::string& GetServerApiVersion()  |
|  **Functional Overview**  |  Obtain the server API version.  |
|  **Parameters**  |  None  |
|  **Return Value**  |  Returns the server API version.  |
|  **Remarks**  |   |

### Other service component interfaces

Multiple service components within Go2 provide partial functional interfaces to external users through RPC clients, such as the **SportClient** class, **RobotStateClient** class, **VuiClient** class, **ObstaclesAvoidClient** class.
<BR>
For specific interface descriptions, please refer to "[Obstacle Avoidance Service Interface](https://support.unitree.com/home/en/developer/ObstaclesAvoidClient)", [Volume and Light Service Interface](https://support.unitree.com/home/en/developer/VuiClient)", "[Device Status Service Interface](https://support.unitree.com/home/en/developer/RobotStateClient)", "[High level Sports Service Interface](https://support.unitree.com/home/en/developer/sports_services)"Documentation.

--- 

# Avoidance Services Interface

## ObstaclesAvoidClient Class

ObstaclesAvoidClient is the client provided by the Go2 obstacle avoidance service. Through ObstaclesAvoidClient, you can use the RPC method to enable/disable and get the status of the Go2 obstacle avoidance function.

### Interface Error Code List:

This Client does not have a specific error list. For the general list, please refer to: [List of some general error codes](https://support.unitree.com/home/en/developer/DDS_services#heading-7)

### Class and Interface Description:

|  **Class Name**  |  **Constructor and Destructor**  |
| :---: | :--- |
|  ObstaclesAvoidClient  |  explicit ObstaclesAvoidClient(); \~ObstaclesAvoidClient();  |

|  **Function Name**  |  **SwitchSet**  |
| :---: | :--- |
|  **Function Prototype**  |  int32\_t SwitchSet(bool enable)  |
|  **Function Summary**  |  Sets the obstacle avoidance function to be enabled or disabled.  |
|  **Parameters**  |  **enable**: Set to true to enable, false to disable.  |
|  **Return Value**  |  Returns 0 on success, otherwise returns the relevant error code.  |
|  **Notes**  |   |

|  **Function Name**  |  **SwitchGet**  |
| :---: | :--- |
|  **Function Prototype**  |  int32\_t SwitchGet(bool& enable);  |
|  **Function Summary**  |  Gets whether the obstacle avoidance function is enabled.  |
|  **Parameters**  |  **enable**: Return value, true for enabled, false for disabled.  |
|  **Return Value**  |  Returns 0 on success, otherwise returns the relevant error code.  |
|  **Notes**  |   |

|  **Function Name**  |  **UseRemoteCommandFromApi**  |
| :---: | :--- |
|  **Function Prototype**  |  int32\_t UseRemoteCommandFromApi(bool isRemoteCommandsFromApi)  |
|  **Function Summary**  |  Takes over the speed command control from the remote controller.  |
|  **Parameters**  |  **isRemoteCommandsFromApi**: Set to true to enable takeover, false to disable takeover.  |
|  **Return Value**  |  Returns 0 on success, otherwise returns the relevant error code.  |
|  **Notes**  |  `isRemoteCommandsFromApi` must be set to true to control dog obstacle avoidance via API. |

|  **Function Name**  |  **Move**  |
| :---: | :--- |
|  **Function Prototype**  |  int32\_t Move(float x, float y, float yaw);  |
|  **Function Summary**  |  Movement control in obstacle avoidance mode.  |
|  **Parameters**  |  **x**: Body x-direction velocity command, limited to -1.5\~+1.5(m/s); **y**: Body y-direction velocity command, limited to -1\~+1(m/s); **yaw**: Body yaw angular velocity command, limited to -1.57\~+1.57(rad/s).  |
|  **Return Value**  |  Returns 0 on success, otherwise returns the relevant error code.  |
|  **Notes**  | `isRemoteCommandsFromApi` must be set to true to control dog obstacle avoidance via the Move function.  |

|  **Function Name**  |  **MoveToIncrementPosition**  |
| :---: | :--- |
|  **Function Prototype**  |  int32\_t MoveToIncrementPosition(float x, float y, float yaw);  |
|  **Function Summary**  |  Movement control in obstacle avoidance mode.  |
|  **Parameters**  |  **x**: Incremental position in the body's x-direction, limited to -2.0\~+2.0(m); **y**: Incremental position in the body's y-direction, limited to -2.0\~+2.0(m); **yaw**: Incremental yaw angle, limited to -1.57\~+1.57(rad).  |
|  **Return Value**  |  Returns 0 on success, otherwise returns the relevant error code.  |
|  **Notes**  | `isRemoteCommandsFromApi` must be set to true to control dog obstacle avoidance via the MoveToIncrementPosition function.  |

|  **Function Name**  |  **MoveToAbsolutePosition**  |
| :---: | :--- |
|  **Function Prototype**  |  int32\_t MoveToAbsolutePosition(float x, float y, float yaw);  |
|  **Function Summary**  |  Movement control in obstacle avoidance mode.  |
|  **Parameters**  |  **x**: Absolute position in the world coordinate system x-direction; **y**: Absolute position in the world coordinate system y-direction; **yaw**: Yaw angle in the world coordinate system.  |
|  **Return Value**  |  Returns 0 on success, otherwise returns the relevant error code.  |
|  **Notes**  | `isRemoteCommandsFromApi` must be set to true to control dog obstacle avoidance via the MoveToAbsolutePosition function.  |

Example:

```c++
#include <unitree/robot/go2/obstacles_avoid/obstacles_avoid_client.hpp>

using namespace unitree::common;
using namespace unitree::robot;
using namespace unitree::robot::go2;

int main()
{
    unitree::robot::ChannelFactory::Instance()->Init(0, "enx00e04c36141b");//enx00e04c36141b is the network port number, users should modify it according to their situation
    unitree::robot::go2::ObstaclesAvoidClient sc;
    sc.SetTimeout(5.0f);
    sc.Init();
    sc.SwitchSet(true);//Enable obstacle avoidance
    usleep(1000000);
    sc.UseRemoteCommandFromApi(true);//Take over speed control from the remote controller
    sc.Move(1.0,0.0,0.0);//Move along the body's x-direction at 1m/s, automatically avoiding obstacles when encountered
    int tem = 0;
    while (true)
    {
      usleep(1000000);
      if(tem<=5)
      {
        tem++;
      }
      else
      {
        sc.UseRemoteCommandFromApi(false);//Disable after 5 seconds
        sc.SwitchSet(false);//Disable after 5 seconds
      }
    }
    return 0;
}

```

--- 

# VuiClient Interface

# Volume and Lighting Service Interface

### VuiClient Class

`VuiClient` is the Client provided by the voice and lighting service status service. Through `VuiClient`, you can use RPC to control and retrieve information about Go2's volume and lighting (some functional interfaces are not yet open).

#### Interface Error Code List:

| **Error Code** | **Meaning** |
| --- | --- |
| 100 | The parameter passed in is incorrect |

#### Class and Interface Description:

| Class Name | Construction and Destruction |
| :---: | :--- |
| VuiClient | explicit VuiClient(); ~VuiClient(); |

| **Function Name** | **SetBrightness** |
| :---: | :--- |
| **Function Prototype** | `int32_t SetBrightness(int level)` |
| **Function Overview** | Sets the lighting brightness. |
| **Parameters** | **level**: Lighting brightness, value range 0~10. |
| **Return Value** | Returns 0 on successful call, otherwise returns the relevant error code. |
| **Notes** | |

| **Function Name** | **GetBrightness** |
| :---: | :--- |
| **Function Prototype** | `int32_t GetBrightness(int& level);` |
| **Function Overview** | Gets the lighting brightness. |
| **Parameters** | **level**: The returned lighting brightness. |
| **Return Value** | Returns 0 on successful call, otherwise returns the relevant error code. |
| **Notes** | |

| **Function Name** | **SetVolume** |
| :---: | :--- |
| **Function Prototype** | `int32_t SetVolume(int level);` |
| **Function Overview** | Sets the volume level. |
| **Parameters** | **level**: Volume level, value range 0~10. |
| **Return Value** | Returns 0 on successful call, otherwise returns the relevant error code. |
| **Notes** | |

| **Function Name** | **GetVolume** |
| :---: | :--- |
| **Function Prototype** | `int32_t GetVolume(int& level);` |
| **Function Overview** | Gets the volume level. |
| **Parameters** | **level**: The returned volume level. |
| **Return Value** | Returns 0 on successful call, otherwise returns the relevant error code. |
| **Notes** | |

---

--- 

# RobotStateClient Interface

## RobotStateClient class

RobotStateClient is a client provided by the device state service. Through RobotClient, it is convenient to control the internal services of Go2, obtain service status, device status, and system resource usage information through RPC (some functional interfaces are not yet open).

### List of interface error codes:

|Error number | Error description | Remarks|
|:---: | :--- | :---|
|5201 | Service switch execution error| Server return|
|5202 | The service is protected and cannot be turned on or off| Server return|

### Class and interface description:

|Class Name | Creation and Deconstruction|
|:---: | :---|
|RobotStateClient | explicit RobotStateClient(); ~RobotStateClient();|

| **Function name** | **ServiceSwitch** |
| --- | --- |
| **Function prototype** | int32\_t ServiceSwitch(const std::string& name, int32\_t swit, int32\_t& status) |
| **Function overview** | Service switch. |
| **Parameter** | **name**: service name <BR> **swit**: switch, value 1 for on, 0 for off. <BR> **status**: service status after the operation is executed (0: on, 1: off) |
| **Return value** | Return 0 if the call is successful, otherwise return the relevant error code. |
| **Remark** | |

|**Function Name**|**SetReportFreq**|
|:---: | :---|
|**Function Prototype**| int32_t SetReportFreq(int32_t interval, int32_t duration)|
|**Function Overview**| Set the frequency of service status reporting|
|**Parameter**|**interval**: Set the reporting time interval in seconds< BR>**duration**: Set the duration in seconds|
|**Return Value**| If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
|**Note**| Currently, the app's service status function is used and the refresh frequency is set|

| **Function Name** | **Service List** |
| --- | --- |
| **Function Prototype** | int32_t ServiceList(std::vector<ServiceState>& serviceStateList); |
| **Function Overview** | Query the current service status. |
| **Parameters** | **serviceStateList**: List of current services and their statuses. |
| **Return Value** | Returns the list upon successful call, otherwise returns the relevant error code. |
| **Remarks** | List format: Name: Service name, Status: Status, Protect: Protected status |

### Service Name List

|Service Name | Description|
|:---: |:---:|
|sport_ mode | Main motion control service （The software version is less than 1.1.6） |
|mcf | Main motion control service （The software version is greater than or equal to 1.1.6）|
|basic_ service | underlying service|
|chat_ go | Clumsy Dog Service|
|net_ switcher | Net switch|
|obstacles_ avoidance | Obstacle Avoidance Service|
|ota_ box | OTA firmware upgrade service|
|unitree_ lidar | Radar Services|
|utrack | accompanying services|
|video_ hub | Video Source Service|
|webrtc_ bridge | webrtc communication service|
|vui_ service | Offline voice service|

--- 

# Motion Switcher Service Interface

!!! note  **Applicable Scope**  

This document's interface description is applicable to the **Go2 Edu model**.  

  - Should you have any other questions, you are welcome to [contact official technical support](https://serviceconsole.unitree.com/#/work-order).  

Thank you for your support!

!!!

## Motion Control Mode Name Description

| Service Name | Motion Control Service Version |
| --- | --- |
| mcf | $\ge$1.1.6 |
| ai=AI Mode, normal = Normal Mode, advanced = Advanced Mode | \<1.1.6 |

## MotionSwitcherClient Class

MotionSwitcherClient is the Client provided by the motion control switching service. Through MotionSwitcherClient, you can easily switch the Go2 motion control mode via RPC. It also provides interfaces to set or get whether Go2 is in a silent state (when Go2 is in a silent state, Go2's default motion controls are not started, and this setting remains effective after Go2 restarts).

### Interface Error Code List

| Error Number | Error Description | Notes |
| --- | --- | --- |
| 7001 | Request parameter error. | Server response |
| 7002 | Switching service is busy, please try again later. | Server response |
| 7004 | Motion control mode name is not supported. | Server response |
| 7005 | Internal command execution error in motion control mode. | Server response |
| 7006 | Detection command execution error in motion control mode. | Server response |
| 7007 | Switching command execution error in motion control mode. | Server response |
| 7008 | Release command execution error in motion control mode. | Server response |
| 7009 | Custom configuration error. | Server response |

### Class and Interface Description

| Class Name | Construction and Destruction |
| --- | --- |
| MotionSwitcherClient | explicit MotionSwitcherClient(); \</BR\> \~MotionSwitcherClient(); |

| **Function Name** | **CheckMode** |
| --- | --- |
| **Function Prototype** | int32\_t CheckMode(std::string& form, std::string& name) |
| **Function Summary** | Detects the current form and motion control mode. |
| **Parameters** | **form**: The current Go2 form. "0" for Standard Form; "1" for Wheel-Foot Form \<BR\> **name**: Motion control mode name. Please refer to "Motion Control Mode Name" above for details. |
| **Return Value** | Returns 0 if the call is successful, otherwise returns the relevant error code. |
| **Notes** | |

| **Function Name** | **SelectMode** |
| --- | --- |
| **Function Prototype** | int32\_t SelectMode(const std::string& name) |
| **Function Summary** | Selects the motion control mode. |
| **Parameters** | **name**: Motion control mode name. |
| **Return Value** | Returns 0 if the call is successful, otherwise returns the relevant error code. |
| **Notes** | |

| **Function Name** | **ReleaseMode** |
| --- | --- |
| **Function Prototype** | int32\_t ReleaseMode() |
| **Function Summary** | Releases the motion control mode. |
| **Parameters** | None |
| **Return Value** | Returns 0 if the call is successful, otherwise returns the relevant error code. |
| **Notes** | |

| **Function Name** | **SetSilent** |
| --- | --- |
| **Function Prototype** | int32\_t SetSilent(bool silent) |
| **Function Summary** | Sets the silent state. |
| **Parameters** | **silent:** Whether to set the silent state |
| **Return Value** | Returns 0 if the call is successful, otherwise returns the relevant error code. |
| **Notes** | |

| **Function Name** | **GetSilent** |
| --- | --- |
| **Function Prototype** | int32\_t GetSilent(bool& silent) |
| **Function Summary** | Gets the silent setting. |
| **Parameters** | **silent:** Whether the silent state is set |
| **Return Value** | Returns 0 if the call is successful, otherwise returns the relevant error code. |
| **Notes** | |

--- 

# Sports Services Interface

!!! note **Scope of Application**

This document interface description is applicable to the **Go2 Edu model**, requiring the Go2 software version to be less than V1.1.6.

- If your software version is greater than or equal to V1.1.6, please refer to [Motion Services Interface V2.0](https://support.unitree.com/home/en/developer/Motion_Services_Interface_V2.0).
- For any other questions, feel free to [contact our official technical support](https://global-serviceconsole.unitree.com/#/login?redirect=/work-order).

Thank you for your support!

!!!

# High level control interface
By calling the SDK's sport_ Client, to send motion commands such as speed control and trajectory tracking to Go2w.
## The calling method of high-level control interface

```C++

#include <unitree/robot/go2/sport/sport_client.hpp>
#include <unistd.h>

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
//argv[1] is network interface of the robot
  
  //Create a sports client object
  unitree::robot::go2::SportClient sport_client;
  sport_client.SetTimeout(10.0f);//Timeout time
  sport_client.Init();

  sport_client.StandUp(); //Special action, robot dog sitting down
  sleep(3);//delay 3s
  sport_client.StandDown(); //Restore
  sleep(3);

  return 0;
}

```

## Introduction to high-level motion control interface

The high-level control interface can achieve control of Go2's posture, speed, and trajectory tracking, flipping, jumping, and handstand. The relevant functions of the motion control interface are listed below.

| **Function Name** | **Damp**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Damp()| 
| **Function Overview** |  Enter damping state| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  All motor joints stop moving and enter a damping state. This mode has the highest priority and is used for emergency stops in unexpected situations| 

| **Function Name** | **BalanceStand**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t BalanceStand()| 
| **Function Overview** |  Unlock| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Unlock the joint motor and switch from normal standing mode to balanced standing mode. In this mode, the attitude and height of the fuselage will always remain balanced, independent of the terrain. You can control the font of the body by calling the Euler() interface (see the corresponding section of the table for details)|  

| **Function Name** | **StopMove**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t StopMove()| 
| **Function Overview** |  Stop the current action and restore the majority of commands to their default values| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Stop the current motion and restore the internal motion parameters of Go2 to the default values| 

| **Function Name** | **StandUp**  |    
| :-- |  :--|  
| **Function Prototype** |  int32_t StandUp()| 
| **Function Overview** |  Joint locking, standing high| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  The machine dog is standing tall normally, and the motor joint remains locked. Compared to the balanced standing mode, the posture of the robotic dog in this mode will not always maintain balance. The default standing height is 0.33m| 

| **Function Name** | **StandDown**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t StandDown()| 
| **Function Overview** |  Joint locking, standing low| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  The robotic dog lies down and the motor joint remains locked| 

| **Function Name** | **RecoveryStand**| 
| :-- |  :--|  
| **Function Prototype** |  int32_t RecoveryStand()| 
| **Function Overview** |  Restore Standing| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Restore from a overturned or lying state to a balanced standing state. Whether it is overturned or not, it will return to standing| 

| **Function Name** | **Euler**| 
| :-- |  :--|  
| **Function Prototype** |  int32_t Euler(float roll, float pitch, float yaw)| 
| **Function Overview** |  Posture when standing and walking| 
| **Parameter** | **Roll:** Value range [-0.75~0.75 ] (rad) **Pitch:** Value range [-0.75~0.75 ] (rad) **Yaw:** Value range [-0.6~0.6 ] (rad)| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Set the body posture angle for Go2 balance when standing or moving. The Euler angle is represented by the rotation order around the relative axis of the body and z-y-x| 

| **Function Name** | **Move**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Move(float vx, float vy, float vyaw)| 
| **Function Overview** |  Mobile| 
| **Parameter** | **vx:** Value range [-2.5~3.8 ] (m/s) **vy:** Value range [-1.0~1.0 ] (m/s) **vyaw:** Value range [-4~4 ] (rad/s)| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Control movement speed. The set speed is the speed represented by the body coordinate system| 

| **Function Name** | **Sit**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Sit()| 
| **Function Overview** |  Sit down.  |                                                                             | **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Special action, robot dog sitting down. It should be noted that special actions need to be executed after the previous action is completed, otherwise it may result in abnormal actions| 

| **Function Name** | **RiseSit**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t RiseSit()| 
| **Function Overview** |  Stand up (relative to sitting down)| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Restore from sitting to balanced standing| 

| **Function Name** | **SwitchGait**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t SwitchGait (int d)| 
| **Function Overview** |  Switch gait| 
| **Parameter** | **d:** Gait enumeration value, with values ranging from 0 to 4, where 0 is idle, 1 is trot, 2 is trot running, 3 is forward climbing mode, and 4 is reverse climbing mode| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  The forward climbing mode is for the robot to face the stairs, while the reverse climbing mode is for the robot to face the stairs with its back| 

| **Function Name** | **BodyHeight**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t BodyHeight (float height)| 
| **Function Overview** |  Set the relative height of the body above the ground when standing and walking.  |                                                                                          
| **Parameter** | **Height:** Relative value to the default fuselage height, value [-0.18~0.03 ] (m)| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Adjust the height of the body relative to the default state when standing or walking in balance. The default body height for Go2 is 0.33. For example, BodyHeight (-0.1) indicates adjusting the body height to 0.33-0.1=0.23 (m)| 

| **Function Name** | **FootRaiseHeight**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t FootRaiseHeight (float height)| 
| **Function Overview** |  Set the relative height of foot lift during movement| 
| **Parameter** | **Height:** Relative value to the default foot lift height, value [-0.06~0.03 ] (m)| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Note** |  Set the leg lift height relative to the default state during Go2 movement, with Go2 default foot lift height of 0.09. For example, FootRaiseHeight (0.01) indicates setting the leg lift height to 0.09+0.01=0.1 (m)| 

| **Function Name** | **SpeedLevel**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t SpeedLevel (int level)| 
| **Function Overview** |  Set the speed range| 
| **Parameter** | **level**: Speed range enumeration value, with values of -1 for slow speed, 0 for normal speed, and 1 for fast speed| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **Hello**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Hello()| 
| **Function Overview** |  Say hello| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **Stretch**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Stretch()| 
| **Function Overview** |  Stretch| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **TrajectoryFollow** | 
| :-- |  :--| 
| **Function Prototype** |  int32_trajectoryFollow (std:: vector<PathPoint>path)| 
| **Function Overview** |  Track Tracking. | 
| **Parameter** |  path is the target motion trajectory of the robotic dog in the future, It consists of 30 trajectory points, PathPoints| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Note** |  The structure definition of the trajectory point (PathPoint) in the path is as follows:![](https://doc-cdn.unitree.com/static/2023/10/18/cac6508a993845eea0e4b7125f9009ad_530x273.png)Each trajectory point contains the position and speed of the robotic dog at a certain time in the future, with the reference coordinate system being the absolute coordinate system of the robot. Through trajectory tracking, more complex and flexible movements can be achieved. For specific usage methods, please refer to examples| 

| **Function Name** | **SwitchJoystick**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Switch Joystick (bool flag)| 
| **Function Overview** |  Native remote control response switch| 
| **Parameter** |  flag: Set true to respond to the native remote control, and false to not respond to the remote control| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  After turning off the remote control response, the remote control commands will not interfere with the current program operation| 

| **Function Name** | **ContinuousGait**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Continuously Gait (bool flag)| 
| **Function Overview** |  Continuous movement| 
| **Parameter** |  flag: Set true to on and false to off| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Note** |  After starting a continuous gait, the robot dog will continue to maintain a gait state, even if the current speed is 0| 

| **Function Name** | **Wallow**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Wallow()| 
| **Function Overview** |  Rolling| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **Pose**| 
| :-- |  :--|  
| **Function Prototype** |  int32_t Pose (bool flag)| 
| **Function Overview** |  Pose| 
| **Parameter** |  flag: Set true to pose and false to restore| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **Scrape**| 
| :-- |  :--|  
| **Function Prototype** |  int32_t Scrape()| 
| **Function Overview** |  Greeting the New Year| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **FrontFlip**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t FrontFlip()| 
| **Function Overview** |  Front flip| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **FrontJump**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t FrontJump()| 
| **Function Overview** |  Jump Forward| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **FrontPounce**| 
| :-- |  :--|  
| **Function Prototype** |  int32_t FrontPounce()| 
| **Function Overview** |  Move Forward| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **Dance1**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t Dance1()| 
| **Function Overview** |  Dance Paragraph 1| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **Dance2**| 
| :-- |  :--|  
| **Function Prototype** |  int32_t Dance2()| 
| **Function Overview** |  Dance Paragraph 2| 
| **Parameter** |  None| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** | | 

| **Function Name** | **GetState**| 
| :-- |  :--| 
| **Function Prototype** |  int32_t GetState (const std:: vector<std:: string>&_vector, std:: map<std:: string, std:: string>&_map)| 
| **Function Overview** |  Retrieve the current status of the robot, including:<br>state: motion status<br>bodyHeight: body height,<br>footRaiseHeight: leg lift height,<br>speedLevel: speed gear,<br>gait gait,<br>joystick: remote control status,<br>dance: in motion,<br>continuous gait: in continuous gait,<br>economicGait: in power-saving gait| 
| **Parameters** | **_ Vector**: the vector reference of the robot status name**_ Map**: Map reference for the state name and corresponding value.
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Remarks** |  Reference example:![]( https://doc-cdn.unitree.com/static/2023/10/11/d603f3b753694f478e6d97d4a548461c_812x422.png )When the robot is in a damping state, the above example will output {"data": "damping"} results| 

The interface error code is as follows:
| Error number |  Error description| 
| :-- |  :--| 
| 4101 |  Wrong number of trajectory points, returned by the client| 
| 4201   | Action timeout error, the specified action was not completed within the expected time
|   
|4205|The state machine has not been initialized|
|4206| If the attitudes of robot are not correct before performing actions such as waving or greeting, the action will not be executed|
| 3104 | DDS timeout|

## example

Here is an example of controlling a robotic dog to achieve posture control while standing.

```c++

#include <cmath>
#include <signal.h>
#include <unistd.h>

#include <unitree/robot/go2/sport/sport_client.hpp>

bool stopped = false;

void sigint_handler(int sig)
{
  if (sig == SIGINT)
  {
    stopped = true;
  }
}

int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
  //argv[1] is network interface of the robot

  //Create a sport_ Client object
  unitree::robot::go2::SportClient sport_client;
  sport_client.SetTimeout(10.0f); //Timeout
  sport_client.Init(); //Initializationsport client

  double t = 0; //Program runtime
  double dt = 0.01; // Control step size

  // Create a signal object to capture the signal for program exit
  signal(SIGINT, sigint_handler);

  while (1)
  {
    t += dt;
    // Attitude tracking a trigonometric function trajectory
    sport_client.Euler(0.2 * sin(2 * t), 0.2 * cos(2 * t) - 0.2, 0.);
    sport_client.BalanceStand();
    usleep(int(dt * 1000000));
    if(stopped)
    {
      break;
    }

  }
  // Reset posture upon program exit
  sport_client.Euler(0, 0, 0);
  return 0;
}

```

# High level state interface

## High level state interface call method

By subscribing to the "rt/portmodestate" topic, you can obtain the position, speed, posture, and other motion states of the robot.

```C++

#include <unitree/idl/go2/SportModeState_.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>

//High level status topic, where rt represents real-time and lf represents low-frequency
#define TOPIC_HIGHSTATE "rt/sportmodestate"

using namespace unitree::robot;

// Callback function for obtaining motion status
void HighStateHandler(const void* message)
{
  unitree_go::msg::dds_::SportModeState_ state = *(unitree_go::msg::dds_::SportModeState_*)message;

  // Print output machine dog position
  std::cout<<"position: "
           <<state.position()[0]<<", "
           <<state.position()[1]<<", "
           <<state.position()[2]<<std::endl;
  // Print out quaternion of robot dog posture (w,x,y,z)
  std::cout<<": "
           <<state.imu_state().quaternion()[0]<<", "
           <<state.imu_state().quaternion()[1]<<", "
           <<state.imu_state().quaternion()[2]<<", "
           <<state.imu_state().quaternion()[3]<<std::endl;
}

int main()
{
  //Initializationsdk Interface
  std::string networkInterface = "enp2s0";// Name of the network card connected by the robot
  unitree::robot::ChannelFactory::Instance()->Init(0, networkInterface);

  // Create a Subscriber
  ChannelSubscriber<unitree_go::msg::dds_::SportModeState_> suber(TOPIC_HIGHSTATE);

  //InitializationChannel
  suber.InitChannel(HighStateHandler);

  while(1)
  {
    usleep(20000);
  }

  return 0;
}

```

## Introduction to Creating High Level State Types

The method to obtain the status of high-level parts is as follows

```c++
TimeSpec stamp(); 
uint32_t errorCode(); // Error
IMU imuState();// IMU status
Uint8_t mode();// Sports mode
/* Sports mode
0. idle, default stand
1. balanceStand
2. pose
3. locomotion
4. reserve
5. lieDown
6. jointLock
7. damping
8. recoveryStand
9. reserve
10. sit
11. frontFlip
12. frontJump
13. frontPounc
*/

float progress(); // Action execution status: 0. dance false; 1. dance true
uint8_t gaitType(); // Gait type
/*
Gait type 
0.idle  
1.trot  
2.run  
3.climb stair  
4.forwardDownStair   
9.adjust
*/

float footRaiseHeight();// Leg lift height
std::array<float, 3> position();// 3D position
float bodyHeight();// Body height
std::array<float, 3> velocity();// Three-dimensional velocity
float yawSpeed();// Yaw speed
std::array<float,4> rangeObstacle();// Obstacle distance
std::array<int16_t,4> footForce();// Four foot force
std::array<float,12> footPositionBody();// The position of the foot end relative to the body
std::array<float,12> footSpeedBody();// The speed of the foot relative to the body
std::array<PathPoint, 10> pathPoints();// The current tracked path point
```

The method for obtaining IMU data is:

```C++

std::array<float, 4> quaternion();    // Quaternion (w, x, y, z)
std::array<float, 3> gyroscope();    // Angular velocity (unit: rad/s)
std::array<float, 3> accelerometer();    // Acceleration m/(s2)
std::array<float, 3> rpy();    // Unit: rad
int8_Temperature ();// temperature

```

The structure of PathPoint is:

```C++

typedef struct
{
  float tFromStart; // Time at which the path point is located
  float x; //x position
  float y; //y position
  float yaw; // Yaw angle
  float vx; //x speed
  float vy; //y speed
  float vyaw; // Yaw speed
} PathPoint;

```

--- 

# AI motion Services interface

!!! note **Scope of Application**

This document interface description is applicable to the **Go2 Edu model**, requiring the Go2 software version to be less than V1.1.6.

- If your software version is greater than or equal to V1.1.6, please refer to [Motion Services Interface V2.0](https://support.unitree.com/home/en/developer/Motion_Services_Interface_V2.0).
- For any other questions, feel free to [contact our official technical support](https://global-serviceconsole.unitree.com/#/login?redirect=/work-order).

Thank you for your support!

!!!

AI Motion Service corresponds to the AI mode on the Unitree Go App. To control the Go2 robot through the interfaces provided in this chapter, you first need to switch the Go2's motion control mode to AI mode. Here are two methods to switch the mode:
1. Use the Unitree Go App to switch to AI mode. For specific operations, please refer to the corresponding [tutorial video](https://oss-global-cdn.unitree.com/static/go2_tutorial/go2_tutorial_14_en.mp4).
2. Use the motion switcher service interface to switch the motion control to AI mode. For specific operations, please refer to the [interface description](https://support.unitree.com/home/en/developer/Motion%20Switcher%20Service%20Interface).

# Interface Type

The Ai sports service is divided into two parts: Ai sport control interface and state interface.

- **Ai sport control interface**：By calling the sport_client of SDK, Go2 is sent motion commands such as speed control, position control, crouching and standing.
- **Ai sport state interface**：By subscribing to the sportmodestate message in the SDK, the position, speed, attitude and other motion states of Go2 can be obtained.

# Ai sport control interface

## The calling method of Ai sport control interface
The control interface adopts Api mode for users to interact with Go2 motion control module. You can call the SportClient class in the SDK to program, the example program is as follows.

```C++

/**
 * @file sport_client_test.cpp
 * @brief Use the class named SportClient to request sport mode
 * @date 2023-12-20
 */
#include <unitree/robot/go2/sport/sport_client.hpp>
#include <unistd.h>

//Forced close progress
void MySigintHandler(int sig)
{
  exit(0);
}

int main()
{ 
  signal(SIGINT, MySigintHandler);
  
  //Init channel
  unitree::robot::ChannelFactory::Instance()->Init();

  //Create SportClient
  unitree::robot::SportClient sport_client;

  //Set time-out period for request
  sport_client.SetTimeout(10.0f);
  
  //Init SportClient
  sport_client.Init();

  //Use api to balance stand  
  sport_client.BalanceStand();
  
  sleep(3);

  //Use api to sit down
  sport_client.StandDown();
  
  sleep(3);

  return 0;
}

```

## Introduction of Ai motion control interface 

The control interface can realize the speed, position control and mode switching of Go2. The related functions of the motion control interface are listed below.

| **Function Name**  | **Damp**|
| -- | -- |
| **Function Prototype** | int32_t Damp() |
| **Function Overview** | Enter damping state|
| **Parameter** | None |
| **Return Value**  | If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
| **Remarks**  | All motor joints stop moving and enter a damping state. This mode has the highest priority and is used for emergency stops in unexpected situations |

| **Function Name**  | **BalanceStand**|
| -- | -- |
| **Function Prototype** | int32_t BalanceStand() |
| **Function Overview** | Unlock|
| **Parameter** | None |
| **Return Value**  | If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
| **Remarks**  | Release the joint motor lock and switch from normal standing, crouching, continuous stepping state to balanced standing mode. In this mode, push the remote control stick and the robot will move |

| **Function Name**  | **StopMove**|
| -- | -- |
| **Function Prototype** | int32_t StopMove() |
| **Function Overview** | Stop the current action and restore most instructions to their default values|
| **Parameter** | None |
| **Return Value**  | If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
| **Remarks**  | Stop the current action and restore most instructions to their default values|

| **Function Name**  | **StandUp**|
| -- | -- |
| **Function Prototype** | int32_t StandUp() |
| **Function Overview** | Joint locking, standing high|
| **Parameter** | None |
| **Return Value**  | If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
| **Remarks**  | The robot dog stands normally tall and the motor joints remain locked. Compared to the balanced standing mode, the posture of the robot dog in this mode will not always be balanced. The default standing height is 0.32m|

| **Function Name**  | **StandDown**|
| -- | -- |
| **Function Prototype** | int32_t StandDown() |
| **Function Overview** | Joint locking, standing low|
| **Parameter** | None |
| **Return Value**  | If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
| **Remarks**  |  The robotic dog lies down and the motor joint remains locked|                                

| **Function Name**  | **RecoveryStand**|
| -- | -- |
| **Function Prototype** | int32_t RecoveryStand() |
| **Function Overview** | Recovery standing|
| **Parameter** | None |
| **Return Value**  | If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
| **Remarks**  |  Return from overturned to balanced standing. For safety, the response will only return to standing in the overturned state|  

| **Function Name**  | **Move**|
| -- | -- |
| **Function Prototype** | int32_t Move(float vx, float vy, float vyaw)|
| **Function Overview** | Move at the specified speed|
| **Parameter** | Value range [-0.6~0.6 ] (m/s) **Vy:** Value range [-0.4~0.4 ] (m/s) **Vyaw:** Value range [-0.8~0.8 ] (rad/s) |
| **Return Value**  | If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
| **Remarks**  |  Control the moving speed, the set speed is the speed of the body coordinate system. It is recommended that you call BalanceStand once before you call Move to ensure that you unlock and enter a removable state| 

| **Function Name**  | **SpeedLevel**|
| -- | -- |
| **Function Prototype** | int32_t SpeedLevel (int level)|
| **Function Overview** | Set the speed range|
| **Parameter** | Speed range enumeration value, with values of -1 for slow speed, and 1 for fast speed|
| **Return Value**  | If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
| **Remarks**  | | 

| **Function Name**  | **ContinuousGait**|
| -- | -- |
| **Function Prototype** | int32_t ContinuousGait(bool flag)|
| **Function Overview** | Continuous walk|
| **Parameter** | flag: Set true to open continuous walk, and false to close continuous walk|
| **Return Value**  | If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
| **Remarks**  | After starting a continuous walk, the robot dog will keep stepping, even if the current speed is 0| 

| **Function Name**  | **MoveToPos**|
| -- | -- |
| **Function Prototype** | int32_t MoveToPos(float x, float y, float yaw)|
| **Function Overview** | Move to the specified position and yaw|
| **Parameter** | (x,y) is the position, and yaw is the yaw angle in odometer coordinate system|
| **Return Value**  | If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
| **Remarks**  | | 

| **Function Name**  | **HandStand**|
| -- | -- |
| **Function Prototype** | int32_t HandStand(bool flag)|
| **Function Overview** | The robot use forward leg to stand|
| **Parameter** | flag: Set true to open hand stand, and false to close hand stand|
| **Return Value**  | If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
| **Remarks**  | | 

| **Function Name**  | **FrontFlip**|
| -- | -- |
| **Function Prototype** | int32_t FrontFlip()|
| **Function Overview** | The robot front flip|
| **Parameter** | flag: none|
| **Return Value**  | If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
| **Remarks**  | | 

| **Function Name**  | **SwitchMoveMode**|
| -- | -- |
| **Function Prototype** | int32_t SwitchMoveMode(bool flag)|
| **Function Overview** | Switch the mode of Move()|
| **Parameter** | Set the flag true to enable the continuous response mode. In the motion mode, the robot responds to the latest command all the time. And set the flag false to close the continuous response mode. If a new command is not received, the robot automatically stops after one second.|
| **Return Value**  | If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
| **Remarks**  | The continuous response mode is disabled by default. For security purposes, you are advised to enable the continuous response mode with caution. | 

| **Function Name** | **TrajectoryFollow** | 
| :-- |  :--| 
| **Function Prototype** |  int32_trajectoryFollow (std:: vector< PathPoint >& path)| 
| **Function Overview** |  Track Tracking. | 
| **Parameter** |  path is the target motion trajectory of the robotic dog in the future, It consists of 30 trajectory points, PathPoints| 
| **Return Value** |  If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned| 
| **Note** |  The structure definition of the trajectory point (PathPoint) in the path is as follows:![](https://doc-cdn.unitree.com/static/2023/10/18/cac6508a993845eea0e4b7125f9009ad_530x273.png)Each trajectory point contains the position and speed of the robotic dog at a certain time in the future, with the reference coordinate system being the absolute coordinate system of the robot. Through trajectory tracking, more complex and flexible movements can be achieved. For specific usage methods, please refer to examples| 

| **Function Name**   | **LeftFlip**                                           |
| ------------------- | ------------------------------------------------------------ |
| **Function Prototype** | `int32_t LeftFlip()`                            |
| **Overview**        | Performs a left flip.                                                   |
| **Parameters**      | None.                     |
| **Return Value**    | Returns `0` on success, otherwise returns the relevant error code.                        |
| **Remarks**         | Executes a single left flip. After the flip, it automatically enters the Agile Mode. This mode can only be entered when not in motion. |

| **Function Name**   | **BackFlip**                                           |
| ------------------- | ------------------------------------------------------------ |
| **Function Prototype** | `int32_t BackFlip()`                            |
| **Overview**        | Performs a backflip.                                                   |
| **Parameters**      | None.                     |
| **Return Value**    | Returns `0` on success, otherwise returns the relevant error code.                        |
| **Remarks**         | Executes a single backflip. After the flip, it automatically enters the Agile Mode. This mode can only be entered when not in motion. |

| **Function Name**   | **FreeWalk**                                           |
| ------------------- | ------------------------------------------------------------ |
| **Function Prototype** | `int32_t FreeWalk()`                            |
| **Overview**        | Enters the Agile Mode.                                                   |
| **Parameters**      | None.                     |
| **Return Value**    | Returns `0` on success, otherwise returns the relevant error code.                        |
| **Remarks**         | Enters the Agile Mode. |

| **Function Name**   | **FreeBound**                                           |
| ------------------- | ------------------------------------------------------------ |
| **Function Prototype** | `int32_t FreeBound(bool flag)`                            |
| **Overview**        | Enters the Bound Run Mode.                                                   |
| **Parameters**      | `flag`: Set to `true` to enter Bound Run Mode; set to `false` to exit Bound Run Mode and enter Agile Mode.                     |
| **Return Value**    | Returns `0` on success, otherwise returns the relevant error code.                        |
| **Remarks**         | Enters the Bound Run Mode. |

| **Function Name**   | **FreeJump**                                           |
| ------------------- | ------------------------------------------------------------ |
| **Function Prototype** | `int32_t FreeJump(bool flag)`                            |
| **Overview**        | Enters the Jump Mode.                                                   |
| **Parameters**      | `flag`: Set to `true` to enter Jump Mode; set to `false` to exit Jump Mode and enter Agile Mode.                     |
| **Return Value**    | Returns `0` on success, otherwise returns the relevant error code.                        |
| **Remarks**         | Enters the Jump Mode. |

| **Function Name**   | **FreeAvoid**                                           |
| ------------------- | ------------------------------------------------------------ |
| **Function Prototype** | `int32_t FreeAvoid(bool flag)`                            |
| **Overview**        | Enters the Avoidance Mode.                                                   |
| **Parameters**      | `flag`: Set to `true` to enter Avoidance Mode; set to `false` to exit Avoidance Mode and enter Agile Mode.                     |
| **Return Value**    | Returns `0` on success, otherwise returns the relevant error code.                        |
| **Remarks**         | Enters the Avoidance Mode. In this mode, the robot can avoid obstacles while moving; when stationary, it can dodge objects in front. |

| **Function Name**   | **WalkStair**                                           |
| ------------------- | ------------------------------------------------------------ |
| **Function Prototype** | `int32_t WalkStair(bool flag)`                            |
| **Overview**        | Enters the Stair Climbing Mode.                                                   |
| **Parameters**      | `flag`: Set to `true` to enter Stair Climbing Mode; set to `false` to exit Stair Climbing Mode and enter Agile Mode.                     |
| **Return Value**    | Returns `0` on success, otherwise returns the relevant error code.                        |
| **Remarks**         | Enters the Stair Climbing Mode. |

| **Function Name**   | **WalkUpright**                                           |
| ------------------- | ------------------------------------------------------------ |
| **Function Prototype** | `int32_t WalkUpright(bool flag)`                            |
| **Overview**        | Enters the Upright Hind Legs Mode.                                                   |
| **Parameters**      | `flag`: Set to `true` to enter Upright Hind Legs Mode; set to `false` to exit Upright Hind Legs Mode and enter Agile Mode.                     |
| **Return Value**    | Returns `0` on success, otherwise returns the relevant error code.                        |
| **Remarks**         | Enters the Upright Hind Legs Mode. |

| **Function Name**   | **CrossStep**                                           |
| ------------------- | ------------------------------------------------------------ |
| **Function Prototype** | `int32_t CrossStep(bool flag)`                            |
| **Overview**        | Enters the Cross-Step Mode.                                                   |
| **Parameters**      | `flag`: Set to `true` to enter Cross-Step Mode; set to `false` to exit Cross-Step Mode and enter Agile Mode.                     |
| **Return Value**    | Returns `0` on success, otherwise returns the relevant error code.                        |
| **Remarks**         | Enters the Cross-Step Mode. |

## Example

There are examples of speed control and position control.

```c++

/**
 * @file move_test.cpp
 * @brief Use the api named Move to control the vel of robot
 * @date 2023-12-20
 */
#include <unitree/robot/go2/sport/sport_client.hpp>
#include <unistd.h>

//Forced close progress
void MySigintHandler(int sig)
{
  exit(0);
}

int main()
{ 
  signal(SIGINT, MySigintHandler);
  
  //Init channel
  unitree::robot::ChannelFactory::Instance()->Init();

  //Create SportClient
  unitree::robot::SportClient sport_client;

  //Set time-out period for request
  sport_client.SetTimeout(10.0f);
  
  //Init SportClient
  sport_client.Init();
  
  //sport_client.WaitLeaseApplied();

  //Use api to balance stand  
  sport_client.BalanceStand();
  
  sleep(3);

  //Use api to move
  sport_client.Move(0.1, 0., 0.);
  
  sleep(3);

  //Stop move
  sport_client.StopMove();
  
  return 0;
}

```
```c++
/**
 * @file move_to_pos_test.cpp
 * @brief Use the api named MoveToPos to control the pos of robot
 * @date 2023-12-20
 */
#include <unitree/robot/go2/sport/sport_client.hpp>
#include <Eigen/Dense>
#include <unitree/robot/channel/channel_subscriber.hpp>

//The topic of odom
#define TOPIC_ODOM_STATE "rt/lf/odommodestate"

using namespace std;
using namespace unitree::common;
using namespace unitree::robot;

//Forced close progress
void MySigintHandler(int sig)
{
  exit(0);
}

class MoveToPosTest{
public:
    MoveToPosTest(){
        sport_client_.SetTimeout(1.0f);
        sport_client_.Init();
    }
    ~MoveToPosTest(){}
    
    void Init(){
        
        odommodestate_subscriber_.reset(new ChannelSubscriber<unitree_go::msg::dds_::SportModeState_>(TOPIC_ODOM_STATE));
        odommodestate_subscriber_->InitChannel(std::bind(&MoveToPosTest::OdomModeStateMessageHandler, this, std::placeholders::_1), 1);
    }
    
    void OdomModeStateMessageHandler(const void *message){
        unitree_go::msg::dds_::SportModeState_ sport_mode_state = *(unitree_go::msg::dds_::SportModeState_*)message;
        
        Eigen::Matrix<float, 3, 1> cur_pose;
        
        yaw_ = sport_mode_state.imu_state().rpy()[2];

        cur_pose[0] = sport_mode_state.position()[0];
        cur_pose[1] = sport_mode_state.position()[1];
        cur_pose[2] = 0.0;

        if(this->have_odom_data_ == false){

            this->have_odom_data_ = true;

            Eigen::Matrix<float, 3, 1> target_in_base;

            //Move one meter along the robot's direction
            target_in_base << 1.0, 0.0, 0.0;

            Eigen::Matrix<float, 4, 1> qua;

            Eigen::Matrix<float, 3, 3> r;

            float c_yaw = cos(yaw_);
            float s_yaw = sin(yaw_);

            r << c_yaw,-s_yaw,0,
                 s_yaw,c_yaw,0,
                 0,0,1;

            target_pos_ = cur_pose + r * target_in_base;

            std::cout<<"[Target Pos] is : "<<target_pos_.transpose()<<std::endl;
            std::cout<<"[Target Yaw] is : "<<yaw_<<std::endl;

        }
    }

    void run(){
        if(have_send_ == false && have_odom_data_ == true){
            sport_client_.MoveToPos(target_pos_[0],target_pos_[1],yaw_);
            
            have_send_ = true;
        }
    }

private:
    
    ChannelSubscriberPtr<unitree_go::msg::dds_::SportModeState_> odommodestate_subscriber_;
    
    bool have_odom_data_ = false;    
    bool have_send_ = false;

    Eigen::Matrix<float, 3, 1> target_pos_;
    float yaw_;

    unitree::robot::SportClient sport_client_;
};

int main(){

    signal(SIGINT, MySigintHandler);

    unitree::robot::ChannelFactory::Instance()->Init();

    MoveToPosTest move_to_pos_test_;

    move_to_pos_test_.Init();

    while(true){
        move_to_pos_test_.run();
    
        sleep(1.0);
    }

    return 0;
}

```

# Ai sport state interface

## Ai sport state interface call method

By subscribing the topic of "rt/sportmodestate", you can realize the acquisition of the robot's position, speed, attitude and other motion states. 

```C++
/**
 * @file sportmodestate_test.cpp
 * @brief Subscribe the sportmodestate to get state of robot
 * @date 2023-12-20
 */
#include <unitree/idl/go2/SportModeState_.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>

//high frequency (500Hz)
#define TOPIC_HIGHSTATE "rt/sportmodestate"

using namespace unitree::robot;

//Callback function
void SportModeStateHandler(const void* message) 
{
  unitree_go::msg::dds_::SportModeState_ state = *(unitree_go::msg::dds_::SportModeState_*)message;
  
  
  std::cout<<"position: "
           <<state.position()[0]<<", "
           <<state.position()[1]<<", "
           <<state.position()[2]<<std::endl;
  
  std::cout<<": "
           <<state.imu_state().quaternion()[0]<<", "
           <<state.imu_state().quaternion()[1]<<", "
           <<state.imu_state().quaternion()[2]<<", "
           <<state.imu_state().quaternion()[3]<<std::endl;
}

int main()
{
  //Init
  unitree::robot::ChannelFactory::Instance()->Init();

  //Create a subscriber to get sport mode state
  ChannelSubscriber<unitree_go::msg::dds_::SportModeState_> sport_mode_state_sub_(TOPIC_HIGHSTATE);

  //Init channel
  sport_mode_state_sub_.InitChannel(SportModeStateHandler);
  
  while(1)
  {
    usleep(20000);
  }
  
  return 0;
}

```

## Introduction of Ai sport state types

The method to obtain the status of Ai sport parts is as follows

```c++
TimeSpec stamp(); 
uint32_t errorCode(); // Error
IMU imuState();// IMU status
Uint8_t mode();// Sports mode
/* Sports mode
0. idle, default stand
1. balanceStand
2. pose
3. locomotion
4. reserve
5. lieDown
6. jointLock
7. damping
8. recoveryStand
*/

float progress(); // Action execution status: 0. dance false; 1. dance true
uint8_t gaitType(); // Gait type
/*
Gait type 
0.idle  
1.trot  
2.run  
3.climb stair  
4.forwardDownStair   
9.adjust
*/

float footRaiseHeight();// Leg lift height
std::array<float, 3> position();// 3D position
float bodyHeight();// Body height
std::array<float, 3> velocity();// Three-dimensional velocity
float yawSpeed();// Yaw speed
std::array<float,4> rangeObstacle();// Obstacle distance
std::array<int16_t,4> footForce();// Four foot force
std::array<float,12> footPositionBody();// The position of the foot end relative to the body
std::array<float,12> footSpeedBody();// The speed of the foot relative to the body
std::array<PathPoint, 10> pathPoints();// The current tracked path point
```

The method for obtaining IMU data is:

```C++

std::array<float, 4> quaternion();    // Quaternion (w, x, y, z)
std::array<float, 3> gyroscope();    // Angular velocity (unit: rad/s)
std::array<float, 3> accelerometer();    // Acceleration m/(s2)
std::array<float, 3> rpy();    // Unit: rad
int8_Temperature ();// temperature

```

The structure of PathPoint is:

```C++

typedef struct
{
  float tFromStart; // Time at which the path point is located
  float x; //x position
  float y; //y position
  float yaw; // Yaw angle
  float vx; //x speed
  float vy; //y speed
  float vyaw; // Yaw speed
} PathPoint;

```

--- 

# Basic Services Interface

The underlying communication mainly involves obtaining data from the motor, battery, remote control, and IMU, publishing **rt/lowstate**, subscribing to control commands **rt/lowcmd**, and controlling the motor and battery.

# Interface Description

### Lower level control instructions

Users can send control commands for motors, batteries, automatic charging, and motor power switches by subscribing to the DDS topic "**rt/lowcmd**". The data format is **LowCmd_.idl**.

* **Motor control command**: There are a total of 12 motors on the body, and the control sequence can be carried out as follows. For details, please refer to **MotorCmd_.idl**.

* **Battery Control Command**: Turn off the battery on the body of the machine. For details, refer to **BmsCmd_.idl**.

* **Automatic Charging Command**: A command to control automatic charging, where **&0xFE**->automatic charging is turned on and **|0x01**->automatic charging is turned off.

* **Motor Power Control Command**: A command to control the power supply of the motor. **&0xFD** ->The power switches of the 12 motors are turned on, and **|0x02** ->the power switches of the 12 motors are turned off.    

```C

    // generated from rosidl_generator_dds_idl/resource/idl.idl.em
    // with input from unitree_go:msg/LowCmd.idl
    // generated code does not contain a copyright notice
    #include "BmsCmd_.idl"
    #include "MotorCmd_.idl"
    
    #ifndef __unitree_go__msg__low_cmd__idl__
    #define __unitree_go__msg__low_cmd__idl__
    
    
    module unitree_go {
    
    module msg {
    
    module dds_ {
    
    
    struct LowCmd_ {
    octet head[2];             // Frame header, used for data verification (0xFE, 0xEF).
    
    octet level_flag;          //Reserved, currently not used.
    octet frame_reserve;       //Reserved, currently not used.
    unsigned long sn[2];       //Reserved, currently not used.
    unsigned long version[2];  //Reserved, currently not used.
    unsigned short bandwidth;  //Reserved, currently not used.
      
    // FR_0 -> 0 , FR_1 -> 1  , FR_2 -> 2   The motor control sequence is currently only 12 motors, which will be retained later.
    // FL_0 -> 3 , FL_1 -> 4  , FL_2 -> 5
    // RR_0 -> 6 , RR_1 -> 7  , RR_2 -> 8
    // RL_0 -> 9 , RL_1 -> 10 , RL_2 -> 11
    unitree_go::msg::dds_::MotorCmd_ motor_cmd[20];   //Motor control command data
    unitree_go::msg::dds_::BmsCmd_ bms_cmd;           // Battery control command data
      
    octet wireless_remote[40];  //Reserved, currently not used.
    octet led[12];              //It has been changed to internal control and is currently not used
    octet fan[2];               //It has been changed to internal control and is currently not used
    
    //&0xFE automatic charging on, | 0x01 automatic charging off
    //&0xFD 12 motor power switches on, | 0x02 12 motor power switches off    octet gpio;
      
    unsigned long reserve;  // reserved
    unsigned long crc;      // For data CRC verification, it is used for 32crc verification.
    
    };
    
    
    };  // module dds_
    
    };  // module msg
    
    };  // module unitree_go
    
    
    #endif  // __unitree_go__msg__low_cmd__idl__
```    

#### **MotorCmd_.idl**

Real time information of motor control commands for motion control.

```C
#ifndef __unitree_go__msg__motor_cmd__idl__
#define __unitree_go__msg__motor_cmd__idl__

module unitree_go {

module msg {

module dds_ {

struct MotorCmd_ {
octet mode;  // Motor control mode (Foc mode (working mode) ->0x01, stop mode (standby mode) ->0x00.)
float q;     //Joint target position
float dq;    //Joint target speed
float tau;   //Joint target torque
float kp;    //Joint stiffness coefficient
float kd;    //Joint damping coefficient
unsigned long reserve[3];   //reserved

};

};  // module dds_

};  // module msg

};  // module unitree_go

#endif  // __unitree_go__msg__motor_cmd__idl__   
```
#### **BmsCmd\_.idl**

Command to turn off the body battery.

```C
// generated from rosidl_generator_dds_idl/resource/idl.idl.em
// with input from unitree_go:msg/BmsCmd.idl
// generated code does not contain a copyright notice

#ifndef __unitree_go__msg__bms_cmd__idl__
#define __unitree_go__msg__bms_cmd__idl__

module unitree_go {

module msg {

module dds_ {

struct BmsCmd_ {
octet off;         // Turn off battery: (Command: 0xA5)
octet reserve[3];  //reserve

};

};  // module dds_

};  // module msg

};  // module unitree_go

#endif  // __unitree_go__msg__bms_cmd__idl__
```    

### Low level data reception

Users can obtain motor, battery, IMU, and remote control data by publishing the DDS topic "**rt/lowstate**" in the format of **LowState_.idl**.

* **Motor status information**: A total of 12 motors can be obtained in the following order. Please refer to **MotorState_.idl** for details.

* **IMU status information**: includes three axis acceleration and angular velocity information, quaternion information, Euler angle information, and temperature information. Please refer to  **IMUState_.idl** for details.

* **Battery Status Information**: Contains battery version, status information, battery level information, charging and discharging, cycle times, temperature, and single battery voltage. For details, please refer to **BmsState_.idl**.

* **foot\_force**\[4\]: represents the foot force information of each leg. Order (0-FR，1-FL，2-RR, 3-RL).

* **bit\_ Flag**: The status information of each component, used for real-time detection of the status of each component. (1. Detect whether the motor, small MCU, remote control, battery, and operation command have timed out. 2. Detect whether there is an error flag in the onboard current, and trigger the hardware current protection to generate an error flag. 3. Detect whether it is in the automatic charging state.).

* **fan\_frequency**\[4\]: Fan speed and locked rotor detection (0-Left rear speed, 1-Right rear speed, 2-Front speed, in revolutions per minute) (locked rotor detection: 3-&0x01: Left rear locked rotor,&0x02: Right rear locked rotor,&0x04: Front locked rotor).

* **Protection Mechanism**: **adc\_reel**- >Winder current, **temperature\_ntc1**->motherboard center temperature value, **temperature\_ntc2**->Automatic charging temperature, **power\_v**->Battery voltage, **power\_a**->Motor current.
    
```C

// generated from rosidl_generator_dds_idl/resource/idl.idl.em
// with input from unitree_go:msg/LowState.idl
// generated code does not contain a copyright notice
#include "BmsState_.idl"
#include "IMUState_.idl"
#include "MotorState_.idl"

#ifndef __unitree_go__msg__low_state__idl__
#define __unitree_go__msg__low_state__idl__

module unitree_go {

module msg {

module dds_ {

struct LowState_ {
octet head[2];               // Frame header, used for data verification (0xFE, 0xEF).

octet level_flag;            //It is still used, but not currently used.
octet frame_reserve;         //It is still used, but not currently used.
unsigned long sn[2];         // It has been changed to file storage format and is currently not used.
unsigned long version[2];    //It is still used, but not currently used.
unsigned short bandwidth;    //It is still used, but not currently used.。
  
unitree_go::msg::dds_::IMUState_ imu_state;           // IMU data information.

//FR_ 0->0, FR_ 1->1, FR_ 2->2 motor sequence, currently only 12 motors are used, later reserved.
//FL_ 0->3, FL_ 1->4, FL_ 2->5
//RR_ 0->6, RR_ 1->7, RR_ 2->8
//RL_ 0->9, RL_ 1->10, RL_ 2->11

unitree_go::msg::dds_::MotorState_ motor_state[20];   // Motor total data.
unitree_go::msg::dds_::BmsState_ bms_state;           // Battery total data.

short foot_force[4];        //Foot force (range 0-4095), can be displayed according to actual values. (Arrays: 0-FR, 1-FL, 2-RR, 3-RL)
short foot_force_est[4];    //It is still used, but not currently used.

unsigned long tick;         //1ms计时用，按照1ms递增。
octet wireless_remote[40];  //遥控器原始数据。

//&0x80- Motor timeout flag 1- timeout 0- normal
//&0x40- Small Mcu timeout flag 1- timeout 0- normal
//&0x20- Remote control timeout flag 1- timeout 0- normal
//&0x10- Battery timeout flag 1- timeout 0- normal
//&0x04- Automatic charging automatic charging status flag 1- Not charging 0- Charging
//&0x02- On board current error flag Error flag 1- On board current abnormal 0- Normal
//&0x01- Operation control command timeout timeout flag 1- timeout 0- normal

octet bit_flag;             // Display of status of each component
  
float adc_reel;             // Winder current (range: 0-3A).
octet temperature_ntc1;    	// The central temperature value of the motherboard (range: -20-100 ℃).
octet temperature_ntc2;    	// Automatic charging temperature (range: -20-100 ℃).
float power_v;      				// This voltage value is the motherboard voltage ->battery voltage.
float power_a;      				// This current value is the motherboard current value ->motor current.
  
unsigned short fan_frequency[4];    // Fan speed (currently displaying 0-10000 based on actual values). (0- Left rear speed, 1- Right rear speed, 2- Front speed, in revolutions per minute) (Locked rotor detection: 3-&0x01: Left rear locked rotor,&0x02: Right rear locked rotor,&0x04: Front locked rotor)

unsigned long reserve;   //reserved。
unsigned long crc;       // Used for data CRC verification.

};

};  // module dds_

};  // module msg

};  // module unitree_go

#endif  // __unitree_go__msg__low_state__idl__
```    

#### IMUState\_.idl

1.  **quaternion**\[4\]: Provides real-time quaternion information for the body posture. (0-w, 1-x, 2-y, 3-z).
    
2.  **rpy**\[3\]: Provides real-time Euler angle information for the body posture of the aircraft. (0-roll, 1-switch, 2-yaw).
    
3.  **gyroscope**\[3\]: Provides real-time three-axis angular velocity information of the fuselage posture. (0-x, 1-y, 2-z).
    
4.  **accelerometer**\[3\]: Provides real-time three-axis acceleration information of the fuselage posture information. (0-x, 1-y, 2-z).
    
``` C
// generated from rosidl_generator_dds_idl/resource/idl.idl.em
// with input from unitree_go:msg/IMUState.idl
// generated code does not contain a copyright notice

#ifndef __unitree_go__msg__imu_state__idl__
#define __unitree_go__msg__imu_state__idl__

module unitree_go {

module msg {

module dds_ {

struct IMUState_ {
float quaternion[4];    // Quaternion data

float gyroscope[3];     // Angular velocity information (0->x, 0->y, 0->z)

float accelerometer[3]; // Acceleration information (0->x, 0->y, 0->z)

float rpy[3];           //Euler angle information: defaults to the radian value (which can be changed to the angle value according to the actual situation), and can be displayed according to the actual value (radian value range: -7-+7, displaying 3 decimal places). (Array: 0-roll (roll angle), 1-pitch (pitch angle), 2-yaw (yaw angle)).

octet temperature;      //IMU temperature information in degrees Celsius.

};

};  // module dds_

};  // module msg

};  // module unitree_go

#endif  // __unitree_go__msg__imu_state__idl__
 ```   

#### **MotorState\_.idl** 

Real time information fed back by the motor for motion control.

```C
// generated from rosidl_generator_dds_idl/resource/idl.idl.em
// with input from unitree_go:msg/MotorState.idl
// generated code does not contain a copyright notice

#ifndef __unitree_go__msg__motor_state__idl__
#define __unitree_go__msg__motor_state__idl__

module unitree_go {

module msg {

module dds_ {

struct MotorState_ {
octet mode;     //Motor control mode (Foc mode (working mode) ->0x01, stop mode (standby mode) ->0x00.)
float q;        // Joint feedback position information: Default is in radians (can be changed to degrees as needed), and can be displayed according to actual values (radian range: -7 to +7, displayed with 3 decimal places).
float dq;       //Joint feedback speed
float ddq;      //Joint feedback acceleration
float tau_est;  //Joint feedback torque
  
float q_raw;    //It is still used, but not currently used.
float dq_raw;   //It is still used, but not currently used.
float ddq_raw;  //It is still used, but not currently used.
octet temperature;          //Motor temperature information: Type: int8_t. It can be displayed according to actual values (range: -100-150).
unsigned long lost;         //Motor packet loss information: can be displayed according to actual values (range: 0-9999999999).
unsigned long reserve[2];   //Current motor communication frequency+motor error flag bits: (Array: 0- Motor error flag bits (Range: 0-255, can be displayed according to actual values), 1- Current motor communication frequency (Range: 0-800, can be displayed according to actual values)

};

};  // module dds_

};  // module msg

};  // module unitree_go

#endif  // __unitree_go__msg__motor_state__idl__
```    

#### **BmsState\_.idl**

*   **version\_high** and **version\_low**: Information on the version of the constituent battery.
    
*   **status**: Display states such as battery not turned on, wake-up event, battery pre charging, battery charging normally, battery discharging normally, battery self discharging, battery presence warning, waiting for button reset warning, and resetting.
    
*   **soc**: Battery level information (1% -100%).
    
*   **current**: Charging and discharging information:
    
    *   Positive: represents charging.
        
    *   Negative: represents discharge.
        
*   **cycle**: The number of charging cycles.
    
*   **bq\_ntc**\[2\]: The temperature of the two NTCs inside the battery
    
    *   0\-BAT1
        
    *   1-BAT2
        
*   **mcu\_ntc**\[2\]: Battery NTC array
    
    *   0\-RES
        
    *   1\-MOS
        
*   **cell\_vol**\[15\]: Single section voltage.
    
```C
// generated from rosidl_generator_dds_idl/resource/idl.idl.em
// with input from unitree_go:msg/BmsState.idl
// generated code does not contain a copyright notice

#ifndef __unitree_go__msg__bms_state__idl__
#define __unitree_go__msg__bms_state__idl__

module unitree_go {

module msg {

module dds_ {

struct BmsState_ {
octet version_high;    //Battery version
octet version_low;     //Battery version

//0: SAFE, (battery not turned on)
//1: WAKE_ UP, (wake up event)
//6: PRECHG, (during battery pre charging)
//7: CHG, (during normal battery charging)
//8: DCHG, (during normal battery discharge)
//9: SELF_ DCHG (during battery self discharge)
//11: ALARM, (battery presence warning)
//12: RESET_ ALARM, (waiting for button reset warning)
//13: AUTO_ RECOVERYOctet status // Battery status information.  
octet soc;             // Battery level information: (Type: uint8_t) (Range 1% -100%)
long current;          // Charging and discharging information: (positive: represents charging, negative represents discharging) can be displayed according to actual values
unsigned short cycle;  // Number of charging cycles
octet bq_ntc[2];       // The temperature of the two NTCs inside the battery (int8_t) (range: -100-150). 0- BAT1; 1- BAT2

octet mcu_ntc[2];      // Battery NTC array: 0- RES, 1- MOS (int8_t) (range: -100-150).

unsigned short cell_vol[15];      // The voltage of 15 batteries inside the battery.

};

};  // module dds_

};  // module msg

};  // module unitree_go

#endif  // __unitree_go__msg__bms_state__idl__

```

--- 

# LiDAR Services Interface

The Go2 robot dog will automatically start the relevant programs of the LiDAR when turned on, and publish the point clouds collected by the LiDAR and the established environmental altitude map to the DDS topic.

## 1. Obtain LiDAR point cloud

### 1.1 Message Topics of Point Cloud

By default, LiDAR posts two point cloud topics:

* **Original point cloud of LiDAR**: The topic name is "**rt/utlidar/cloud**", and its coordinate system is the LiDAR coordinate system "**utlidar _lidar**";

* **Point cloud after removing motion distortion**: The topic name is "**rt/utlidar/cloud desckewed**", and its coordinate system is the world coordinate system "**odom**" that is consistent with the body odometer.

!!! note Attention:
When removing motion distortion, we used the fuselage odometer and IMU data (published by the topic "**rt/portmodestate**") to transform all points in a point cloud from the LiDAR coordinate system at different times to the world coordinate system at the same time. This timestamp defaults to the collection timestamp of the last point in a frame of point cloud.

!!!

### 1.2 Message Types of Point Clouds

The IDL message format for point clouds is PointCloud2_Idl, its point cloud message format with ROS2 [PointCloud2.msg](https://docs.ros2.org/foxy/api/sensor_msgs/msg/PointCloud2.html) Consistent definition.

**PointCloud2_.idl** is a message type used to represent 3D point cloud data. PointCloud2 messages define a multidimensional array containing point cloud data, where each element contains one or more fields. Each field can be a predefined type, such as **float32**, **int32**, etc., or it can be a custom type. The size and arrangement of each element can be defined.

The definition and explanation of message format for **PointCloud2_.idl** are as follows:

```C++
// generated from rosidl_generator_dds_idl/resource/idl.idl.em
// with input from sensor_msgs:msg/PointCloud2.idl
// generated code does not contain a copyright notice

#include "PointField_.idl"
#include "Header_.idl"

#ifndef __sensor_msgs__msg__point_cloud2__idl__
#define __sensor_msgs__msg__point_cloud2__idl__

module sensor_msgs {

module msg {

module dds_ {

struct PointCloud2_ {
  // Message header (including time of sensor data acquisition, and the coordinate frame ID for 3d points).
  std_msgs::msg::dds_::Header_ header;
  
  // 2D structure of the point cloud. 
  // If the cloud is unordered, height is 1 and width is the length of the point cloud.
  unsigned long height;
  unsigned long width;
  
  // Describes the channels and their layout in the binary data blob.
  sequence<sensor_msgs::msg::dds_::PointField_> fields;

  // data
  boolean is_bigendian;       // Is this data bigendian?
  unsigned long point_step;   // Length of a point in bytes
  unsigned long row_step;     // Length of a row in bytes
  sequence<octet> data;       // Actual point data, size is (row_step*height)
  boolean is_dense;           // True if there are no invalid points
};

};  // module dds_

};  // module msg

};  // module sensor_msgs

#endif  // __sensor_msgs__msg__point_cloud2__idl__
```

* **header**: A standard ROS message header that contains metadata such as timestamps, coordinate systems, etc.

* **height** and **width** represent the dimensions of point cloud data in the vertical and horizontal directions, respectively. If the point cloud is an unordered point cloud, then height =1, width =the number of points in the point cloud.

* **fields**: An array of PointField types, representing the fields contained in each element along with their type and offset.

* **is_Bigendian**: Indicates whether the data is in bigendian byte order.

* **point_step**: represents the size of each element.

* **row_step**: represents the size of each row of data.

* **data**: represents the actual point cloud data.

### 1.3 Case: Obtaining Point Clouds Using DDS

Before using DDS subscription to process point clouds, please ensure that `unitree_sdk2`. If you have not yet installed it, please read the Quick Start documentation first.

In the following example program, we subscribed to the DDS point cloud topic "**rt/utlidar/cloud**" and printed point cloud related information in the callback function.

**The example program is as follows:**

```C++
/**
 * @file subscribe_pointcloud.cpp
 * @brief Subscribe the pointcloud published from DDS topic
 * @date 2023-11-23
 */

#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/common/time/time_tool.hpp>
#include <unitree/idl/ros2/PointCloud2_.hpp>

#define TOPIC_CLOUD "rt/utlidar/cloud"

using namespace unitree::robot;
using namespace unitree::common;

void Handler(const void *message)
{
  const sensor_msgs::msg::dds_::PointCloud2_ *cloud_msg = (const sensor_msgs::msg::dds_::PointCloud2_ *)message;
  std::cout << "Received a raw cloud here!"
            << "\n\tstamp = " << cloud_msg->header().stamp().sec() << "." << cloud_msg->header().stamp().nanosec()
            << "\n\tframe = " << cloud_msg->header().frame_id()
            << "\n\tpoints number = " << cloud_msg->width()
            << std::endl
            << std::endl;
}

int main(int argc, const char **argv)
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }

  ChannelFactory::Instance()->Init(0, argv[1]);

  ChannelSubscriber<sensor_msgs::msg::dds_::PointCloud2_> subscriber(TOPIC_CLOUD);
  subscriber.InitChannel(Handler);

  while (true)
  {
    sleep(10);
  }

  return 0;
}
```

**The CMakeLists.txt configuration is as follows:**
```CMake
project(helloworld)
cmake_minimum_required(VERSION 3.5)

SET(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include/ddscxx /usr/local/include/iceoryx/v2.0.2)
link_libraries(unitree_sdk2 ddsc ddscxx rt pthread)

add_executable(subscribe_pointcloud example/lidar/subscribe_pointcloud.cpp)
```

**The operation results are as follows:**

```C++
$ ./subscribe_pointcloud 
Received a raw cloud here!
  stamp = 1683713030.572689533
  frame = utlidar_lidar
  points number = 1402

Received a raw cloud here!
  stamp = 1683713030.640552759
  frame = utlidar_lidar
  points number = 1423

Received a raw cloud here!
  stamp = 1683713030.705702066
  frame = utlidar_lidar
  points number = 1393

Received a raw cloud here!
  stamp = 1683713030.773043155
  frame = utlidar_lidar
  points number = 1413
...
```

### 1.4 Case: Visualizing Point Clouds Using ROS2

On Ubuntu systems with ROS2 installed, the rviz2 tool can also be run to visualize the current point cloud.

!!! note Attention:

For the installation and configuration tutorial of ROS2, please refer to ['ROS2 Services Interface'](https://support.unitree.com/home/en/developer/ROS2_service).

!!!

**The steps are as follows:**

* Firstly, run the following command **rviz2** to open **rviz2**

* Then, set the coordinate system to "**odom**" at [**Fixed Frame**]

* Click on [**Add**] in the bottom left corner, select [**By topic**], and then select the corresponding point cloud topic "**/utlidar/cloud_deskewed**".

* You can set [**Decay Time**] to be equal to 1 second or longer to cache point cloud data for a certain period of time

!!! note Attention:

The prefix rt of the topic name in DDS will automatically disappear when subscribing to ROS2, for example, the topic "**rt/utlidar/cloud_deskewed**" in DDS will automatically change to "**/utlidar/cloud_deskewed**" in ROS2.

!!!

The display effect of rviz2 is as follows:

![](https://doc-cdn.unitree.com/static/2023/10/12/cf234ed24c514040bd8a947cf5c33088_1856x1055.png)

## 2. Obtain height map

We have also established a height map centered on the robot that represents environmental height information, using data such as the distorted point cloud and robot odometer from LiDAR. The message topic is "**rt/utlidar/height\_map\_array**", and its coordinate system is the world coordinate system "**odom**" that is consistent with the body odometer. This map can be used for robot obstacle avoidance, foot landing planning, and other functions.

`Note that the height map function requires the use of the "sportmode state" topic message published by the robot's own motion control program, such as odometer and other related data. Therefore, it is necessary to ensure that the Unitree operation control program is running normally before the height map is published. If the operation control is turned off, such as when debugging your own operation control program, the height map data cannot be obtained. `

### 2.1 Message format for height map

The IDL message format for point clouds is **HeightMap_.idl**, the definition and description of the message format are as follows:

```C++
// generated from rosidl_generator_dds_idl/resource/idl.idl.em
// with input from sensor_msgs:msg/PointCloud2.idl
// generated code does not contain a copyright notice

#ifndef __unitree_go_msgs__height_map__idl__
#define __unitree_go_msgs__height_map__idl__

module unitree_go {

module msg {

module dds_ {

struct HeightMap_ {
  
  // Header
  double stamp;           // timestamp
  string frame_id;        // world frame id

  // Map info
  float resolution;       // The map resolution [m/cell]
  unsigned long width;    // Map width along x-axis [cells]
  unsigned long height;   // Map height alonge y-axis [cells]
  float origin[2];        // Map frame origin xy-position [m] 
                          //  the xyz-axis direction of map frame is aligned with the world frame

  // Map data, in x-major order, starting with [0,0], ending with [width-1, height-1]
  // For a cell whose 2d-array-index is [ix, iy]，
  //   its position in world frame is: [origin[0] + ix * resolution, origin[1] + iy * resolution]
  //   its cell value is: data[width * iy + ix]
  sequence<float> data;
};

};  // module dds_

};  // module msg

};  // module unitree_go

#endif  // __unitree_go_msgs__height_map__idl__
```

* stamp: Message timestamp

* frame_id: World coordinate system name

* resolution: Map resolution

* height and width: the number of grids in the x and y directions of the map

* origin[2]: The xy position of the origin of the map coordinate system in the world coordinate system

* data: Map height data

### 2.2 Case: Using DDS to subscribe to height map

Before using DDS subscription to process altitude maps, please ensure that `unitree_sdk2`. If you have not yet installed it, please read the Quick Start documentation first.

In the following example program, we subscribed to the DDS height map topic `"rt/utlidar/height_map_array"` and printed the relevant information of the obtained height map in the callback function.

**The example program is as follows:**

```C++
/**
 * @file subscribe_height_map.cpp
 * @brief Subscribe the height map published from DDS topic
 * @date 2023-06-25
 */

#include "common/dds/dds_easy_model.hpp"
#include "HeightMap_.hpp"
#define TOPIC_CLOUD "rt/utlidar/height_map_array"

/*
 * Callback function.
 */
void MessageHandler(const void *message)
{
  // print msg info
  const unitree_go::msg::dds_::HeightMap_ *map_msg = (const unitree_go::msg::dds_::HeightMap_ *)message;
  std::cout << "Received a height map msg here!"
            << "\n\tstamp = " << map_msg->stamp()
            << "\n\tframe = " << map_msg->frame_id()
            << "\n\twidth = " << map_msg->width()
            << "\n\theight = " << map_msg->height()
            << "\n\tresolution = " << map_msg->resolution()
            << std::endl << std::endl;
  
  // Parse a height map to a pointcloud in world frame
  std::vector<std::array<float, 3>> cloud; // the element of std::array is x, y and z respectively
  int width = map_msg->width();
  int height = map_msg->height();
  float resolution = map_msg->resolution();
  float originX = map_msg->origin()[0];
  float originY = map_msg->origin()[1];
  
  int index;
  std::array<float, 3> pt;
  for (int iy = 0; iy< height; iy++){
    for (int ix = 0; ix< width; ix++){
      index = ix + width * iy;
      pt[2] = map_msg->data()[index];
      if (pt[2] == 1.0e9) { // skip empty cell value which is set to 1.0e9
        continue;
      }
      pt[0] = ix * resolution + originX;
      pt[1] = iy * resolution + originY;
      cloud.push_back(pt);
    }
  }
}

int main()
{
  unitree::common::DdsEasyModel dm;

  /*
   * Init with defalue domain 0.
   * We can specified a cyclone dds config file in xml format by env name CYCLONEDDS_URI
   * just like 'export CYCLONEDDS_URI=/unitree/etc/cyclonedds.xml' in current shell or set to .bashrc/.bash_file
   */
  dm.Init(0);

  /*
   * set topic to read.
   */
  dm.SetTopic<unitree_go::msg::dds_::HeightMap_>(TOPIC_CLOUD, std::bind(MessageHandler, std::placeholders::_1));

  while (true)
  {
    sleep(10);
  }

  return 0;
}
```

**The CMakeLists.txt configuration is as follows:**
```CMake
project(helloworld)
cmake_minimum_required(VERSION 3.5)

SET(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include/ddscxx /usr/local/include/iceoryx/v2.0.2)
link_libraries(unitree_sdk2 ddsc ddscxx rt pthread)

add_executable(subscribe_height_map example/lidar/subscribe_height_map.cpp)
```

**The operation results are as follows:**
```C++
$ ./subscribe_height_map
Received a height map msg here!
  stamp = 1683713537.840576896
  frame = odom
  width = 128
    height = 128
    resolution = 0.06

Received a height map msg here!
  stamp = 1683713537.927782453
  frame = odom
  width = 128
    height = 128
    resolution = 0.06
...
```

## 3. Obtain simple obstacle distance

By processing the LiDAR point cloud, we generated real-time obstacle distance information for the robot in three directions: forward, left, and right, which can be used for simple obstacle avoidance needs. Users can obtain the distance information of the obstacle by subscribing to the corresponding topic.

The DDS topic for publishing the distance information of this simple obstacle is: `"rt/utlidar/range_info"`

### 3.1 Message format for obstacle distance

Considering that the distance information of the obstacle only includes the first, left, and right distance information, and is compatible with the existing ROS2 message format, we use the IDL message type - `geometry_msgs::msg::dds_::PointStamped_`, which is consistent with the `geometry_msgs::PointStamped_` in ROS2. The specific definition is as follows:

```C++
#include "Point_.idl"
#include "Header_.idl"

#ifndef __geometry_msgs__msg__point_stamped__idl__
#define __geometry_msgs__msg__point_stamped__idl__

// Default Topic: "rt/utlidar/range_info"

module geometry_msgs {

module msg {

module dds_ {

struct PointStamped_ {
std_msgs::msg::dds_::Header_ header;
geometry_msgs::msg::dds_::Point_ point; // x, y and z of this point stands for front, left and right range distance respectively

};

};  // module dds_

};  // module msg

};  // module geometry_msgs

#endif  // __geometry_msgs__msg__point_stamped__idl__
 ```

* header: Message frame header

* point: The three components of xyz represent the distance from obstacles in the front, left, and right directions to the origin of the robot coordinate system

### 3.2 Case: Using DDS to Subscribe to Obstacle Distance

Before using DDS subscription to process obstacle distance, please ensure that `unitree_sdk2`. If you have not yet installed it, please read the Quick Start documentation first.

In the following example program, we subscribed to the DDS obstacle distance topic  `"rt/utlidar/range_info"` and printed the relevant information of the obtained obstacle distance in the callback function.

**The example program is as follows:**
```C++
/**
 * @file subscribe_range_info.cpp
 * @brief Subscribe the range info msg published from DDS topic
 * @date 2023-11-23
 */

#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/common/time/time_tool.hpp>
#include <unitree/idl/ros2/PointStamped_.hpp>

#define TOPIC_RANGE_INFO "rt/utlidar/range_info"

using namespace unitree::robot;
using namespace unitree::common;

void Handler(const void *message)
{
  // print msg info
  const geometry_msgs::msg::dds_::PointStamped_ *range_msg = (const geometry_msgs::msg::dds_::PointStamped_ *)message;
    std::cout << "Received a range info message here!"
            << "\n\tstamp = " << range_msg->header().stamp().sec() << "." << range_msg->header().stamp().nanosec() 
            << "\n\tframe = " << range_msg->header().frame_id()
            << "\n\trange front = " << range_msg->point().x()
            << "\n\trange left = " << range_msg->point().y()
            << "\n\trange right = " << range_msg->point().z()
            << std::endl << std::endl;
}
int main(int argc, const char **argv)
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }

  ChannelFactory::Instance()->Init(0, argv[1]);

  ChannelSubscriber<geometry_msgs::msg::dds_::PointStamped_> subscriber(TOPIC_RANGE_INFO);
  subscriber.InitChannel(Handler);

  while (true)
  {
    sleep(10);
  }

  return 0;
}
```

**The CMakeLists.txt configuration is as follows:**
```CMake
project(helloworld)
cmake_minimum_required(VERSION 3.5)

SET(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include/ddscxx /usr/local/include/iceoryx/v2.0.2)
link_libraries(unitree_sdk2 ddsc ddscxx rt pthread)

add_executable(subscribe_range_info example/lidar/subscribe_range_info.cpp)
```

**The operation results are as follows:**
```C++
$ ./subscribe_range_info
Received a range info message here!
  stamp = 1683716737.840576896
  frame = odom
  range front = 1.5
    range left = 0.7
    range right = 2.3

```

## 4. Turn the LiDAR On or Off

The LiDAR is set to start automatically by default. If you need to turn off the LiDAR (i.e., stop it from rotating), you can publish control commands to either open or close the LiDAR. The DDS topic required for publishing is "`rt/utlidar/switch`", and the DDS message type is `std_msgs::msg::dds_::String_`. To turn off the LiDAR, send a string content of `OFF`. To turn on the LiDAR, send a string content of `ON`.

--- 

# Multimedia Services Interface

This chapter will introduce how the application layer uses multimedia interfaces, including obtaining image data and video streaming data from the robot dog camera.
!!! note Note:
It is recommended to use a directed UDP interface for image transmission (or customize other general interfaces such as RTMP), and it is not recommended to use **DDS** (because DDS only transmits videos encoded with H264, and users still need to perform video decoding to obtain the final image). However, for photography, the DDS interface can be used to obtain 720P JPEG images.
!!!

![](https://doc-cdn.unitree.com/static/2023/10/12/e48e25f227694ef3bb60ad1a71a6b6ad_8000x4500.png)

# Interface Description

**JPEG photography service interface**

Using this interface, the sender sends a photo request and then receives a response, which is a JPEG photo. The specific practice is achieved through the VideoClient class, which is a client provided by the Video service. The VideoClient class can obtain Go2 images through RPC.

**H264 image transmission service interface**

On the receiving end, if you need to directly view the image transmission video stream, you can enter the following command in the**command line**:

  ```C++
    gst-launch-1.0 udpsrc address=230.1.1.1 port=1720 multicast-iface=<interface_name> ! queue !  application/x-rtp, media=video, encoding-name=H264 ! rtph264depay ! h264parse ! avdec_h264 ! videoconvert ! autovideosink
```

Among them, 230.1.1.1 is a multicast address <interface_name> is the name of the network interface where the user's host connects to Go2, such as eth0.Set it to `multicast-iface=eth0`.

Currently, only UDP is supported, and support for other image transmission protocols will be added in the future.
The video frame rate is 15Hz. The camera resolution is 1280*720, with a horizontal Angle of view of 100 degrees and a vertical Angle of view of 56 degrees.

# JPEG photography service interface

## VideoClient Class

List of interface error codes:

Currently unavailable

Class and interface description:

|Class Name | Construction and Deconstruction|
|:---: | :---|
|  VideoClient  | VideoClient::~VideoClient() |

|**Function Name**|**GetImageSample**|
|:---: | :---|
|**Function Prototype**| int32_t GetImageSample(std::vector<uint8_t>& image_sample)  |
|**Function Overview**| Get Photos|
|**Parameters**|**image_ Sample**: photo content|
|**Return Value**| If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
|**Remarks**||

## Cases

This case demonstrates how to obtain and save images through the JPEG photography service interface.

``` C++
#include <unitree/robot/go2/video/video_client.hpp>
#include <iostream>
#include <fstream>
#include <ctime>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
      std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
      exit(-1);
    }
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
    //argv [1]  is network interface of the robot
  
    unitree::robot::go2::VideoClient video_client;

    /*
     * Set request timeout 1.0s
     */
    video_client.SetTimeout(1.0f);
    video_client.Init();

    //Test Api

    std::vector<uint8_t> image_sample;
    int ret;

    while (true)
    {
        ret = video_client.GetImageSample(image_sample);

        if (ret == 0) {
            time_t rawtime;
            struct tm *timeinfo;
            char buffer[80];

            time(&rawtime);
            timeinfo = localtime(&rawtime);

            strftime(buffer, sizeof(buffer), "%Y%m%d%H%M%S.jpg", timeinfo);
            std::string image_name(buffer);

            std::ofstream image_file(image_name, std::ios::binary);
            if (image_file.is_open()) {
                image_file.write(reinterpret_cast<const char*>(image_sample.data()), image_sample.size());
                image_file.close();
                std::cout << "Image saved successfully as " << image_name << std::endl;
            } else {
                std::cerr << "Error: Failed to save image." << std::endl;
            }
        }

        sleep(3);
    }

    return 0;
}
``` 

# H264 image transmission service interface

It is recommended to use Gst's directed UDP interface for image transmission. If you plan to use Gst for streaming, you can refer to the following content to implement using Gst for streaming in OpenCV.

Gst supports embedding OpenCV's VideoCapture function for streaming using the Gst pipeline method. At the same time, it also supports embedding in the **VideoWriter** function to push streams in a Gst pipeline manner.

## Dependency related

### Gst installation

Install in Ubuntu Linux environment:

```C++
    sudo apt-get install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-plugins-bad1.0-dev gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-tools gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio
```
!!! note  Note:
 For Windows environments, please refer to the official documentation: [https://gstreamer.freedesktop.org/documentation/installing/on-windows.html?gi-language=c](https://gstreamer.freedesktop.org/documentation/installing/on-windows.html?gi-language=c)
!!!

### OpenCV Compilation

!!! note Help
If you are unable to use the CMake GUI, encounter issues with configuration, or need to use python, you can refer to the [Help Center](https://global-serviceconsole.unitree.com/#/help/030102) for instructions on installing using the command-line compilation method.
!!!

To achieve the above functions, it is necessary to check the**WITH\_GSTREAMER**option when compiling OpenCV. Please refer to the following steps for the OpenCV source code compilation process:

1. Download OpenCV4.1.1 source code from Github [https://github.com/opencv/opencv/tree/4.1.1](https://github.com/opencv/opencv/tree/4.1.1)

2. Installation

``` C++
mkdir build              
cd build
cmake-gui ..
 

####At this point, enter the GUI dialog box
####Click on configure
####Check with cuda and with Gstreamer
####Click on configure again
####Then click on 'generate'
####Close GUI dialog box 

make 
sudo make install
``` 
3. In OpenCV, you can view the compilation status of OpenCV by calling the getBuildInformation function, as follows:

``` C++
#include <opencv2/opencv.hpp>

int main(void)
{
  std::cout << cv::getBuildInformation() << std::endl;
}
``` 
4. By running the above function, you can obtain the following output, where in Video I/O, you can check whether the Gstreamer option is turned on.

![](https://doc-cdn.unitree.com/static/2023/8/8/9e8da0c99c53459985ae715b3b2d7b7a_707x245.png)

![](https://doc-cdn.unitree.com/static/2023/8/8/4af46daae113422ca1ff2233ca4bacc7_756x212.png)

## Video streaming

The **VideoCapture** class of OpenCV supports video files, image sequences, or cameras as input to obtain data. By calling the following **VideoCapture** constructor, you can pull the USB camera data stream:

``` C++
cv::VideoCapture::VideoCapture(const String & filename,int apiPreference)	
``` 

|Variable | Description|
|:---: | :---|
|**filename**| This parameter can be of the following types: <br> * Video file path; <br> * Image sequence, for example, the image sequence name is image\_00.jpg, image\_01.jpg, image\_02.jpg, it can be set to image\_%02d.jpg ; <br>* The URL of the video stream, for example:rtsp://admin@password:192.168.170.XXX; <br>The **pipeline string** of Gstreamer, which can be tested for usability using **gst-launch-1.0**;|
|**apiReference**| What backend does the Capture API use, including CAP\_GSTREAMER or CAP\_FFMPEG or CAP\_IMAGES or CAP\_DSHOW et al|

## Reference Cases

If you use C++, you can refer to the following code

``` C++
#include <opencv2/opencv.hpp>
using namespace cv;

#include <iostream>
using namespace std;

int main()
{

  VideoCapture cap("udpsrc address=230.1.1.1 port=1720 multicast-iface=<interface_name> ! application/x-rtp, media=video, encoding-name=H264 ! rtph264depay ! h264parse ! avdec_h264 ! videoconvert ! video/x-raw,width=1280,height=720,format=BGR ! appsink drop=1", 
            CAP_GSTREAMER);
    
  if (!cap.isOpened()) {
        cerr <<"VideoCapture not opened"<<endl;
        exit(-1);
    }
    
    while (true) {

        Mat frame;

        cap.read(frame);

        imshow("receiver", frame);

        if (waitKey(1) == 27) {
            break;
        }
    }

    return 0;
}
``` 
If you are using Python, you can refer to the following code:
``` Python
import cv2
gstreamer_str = "udpsrc address=230.1.1.1 port=1720 multicast-iface=<interface_name> ! application/x-rtp, media=video, encoding-name=H264 ! rtph264depay ! h264parse ! avdec_h264 ! videoconvert ! video/x-raw,width=1280,height=720,format=BGR ! appsink drop=1"
cap = cv2.VideoCapture(gstreamer_str, cv2.CAP_GSTREAMER)
while(cap.isOpened()):
    ret, frame = cap.read()
    if ret:
        cv2.imshow("Input via Gstreamer", frame)
        if cv2.waitKey(25) & 0xFF == ord('q'):
            break
    else:
        break
cap.release()
cv2.destroyAllWindows()
```

--- 

# UWB Services Interface

The UWB module consists of a UWB base station and UWB tags. It adopts ultra wideband positioning method and can provide the pose information of the tags in the base station. We will convert the collected UWB data into idl format and publish it through DDS. If you need to use UWB data for secondary development, you can obtain it by subscribing to the corresponding DDS topic. The specific usage steps are as follows, and a simple case is attached for reference.
# Interface Description

![](https://doc-cdn.unitree.com/static/2023/10/12/d246a79283a24ea2a4b3d89788ba1ce2_8856x4501.png)

Users can obtain UWB data by subscribing to the DDS topic “**rt/uwbstate**”  in the format of **UwbState\_.idl**.

```C++

// generated from rosidl_generator_dds_idl/resource/idl.idl.em
// with input from unitree_go:msg/UwbState.idl
// generated code does not contain a copyright notice

#ifndef __unitree_go__msg__uwb_state__idl__
#define __unitree_go__msg__uwb_state__idl__

module unitree_go {

module msg {

module dds_ {

struct UwbState_ {
octet version[2];         // Version number (array: 0-hardware, 1-software)

octet channel;            // Signal channel
octet joy_mode;           // Mode (0-joystick control, 1-walk tracking, 2-run tracking, 3-stand up, 4-lie down, 5-damping, 6-roll, 7-trigger motion, 8-stand)

float orientation_est;    // The azimuth of the label in the base station coordinate system
float pitch_est;          // The elevation angle of the label in the base station coordinate system
float distance_est;       // Distance between tag and base station

float yaw_est;            // The yaw angle corresponding to the label orientation in the base station coordinate system

float tag_roll;           // Roll angle of label
float tag_pitch;          // The pitch angle of the label
float tag_yaw;            // Yaw angle of the label

float base_roll;          // Roll angle of the fuselage
float base_pitch;         // The pitch angle of the fuselage
float base_yaw;           // Yaw angle of the fuselage

float joystick[2];        // Rocker value, ranging from -1.00 to 1.00. Joystick [0] is x, and joystick [1] is y. The x-axis is facing upwards and the y-axis is facing left.

octet error_state;        // Error status code
octet buttons;            // Key mode
octet enabled_from_app;   // Does the App turn on tracking (0 is off, 1 is tracking)

};
};  // module dds_
};  // module msg
};  // module unitree_go

#endif  // __unitree_go__msg__uwb_state__idl__
```    
The data available for user secondary development in **UwbState\_.idl** mainly includes the position and orientation of the tag in the base station coordinate system, tag IMU, body IMU, and joystick value. The remaining data is used for displaying the status of the **Unitree Go App** developed by Yushu.

     
* The position and orientation of the label in the base station: The position is in spherical coordinates

* **orientation\_est**: The azimuth angle of the label in the base station coordinate system, in rad, as shown in the schematic diagram β。

* **distance\_est**: The elevation angle of the label in the base station coordinate system, in rad, as shown in the schematic diagram α。

* **distance\_est**: The distance between the label and the base station, in meters, as shown in the diagram.

* **yaw\_est**: The yaw angle corresponding to the label orientation in the base station coordinate system, in rad, as shown in the diagram γ.

![](https://doc-cdn.unitree.com/static/2023/8/8/bb4cc7c94014420eac610157169167d7_8001x4501.jpeg)

*   Label IMU
    
    *   **tag\_roll**：Tag roll angle, in rad.
        
    *   **tag\_pitch**：Tag pitch angle, in rad.
        
    *   **tag\_yaw**：Tag yaw angle, in rad.
        
*   Body IMU
    
    *   **base\_roll**：Body roll angle, in rad.
        
    *   **base\_pitch**：The elevation angle of the fuselage, in rad.
        
    *   **base\_yaw**：Airframe yaw angle, in rad.
        
*   Rocker value
    
    *   **joystick**\[2\]: Accompanying the two axis joystick values of the remote control, the range is -1.00~1.00. **joystick**\[0\] is the x-axis value, and upward is positive; joystick\[1\] is the y-axis value, with a positive value to the left.

<center>
        
![](https://doc-cdn.unitree.com/static/2023/8/8/c1348daeb1424d34ba16b8a43dc8b57c_146x268.png)

</center>

*   The remaining parts are intended for use by Yushu **Unitree Go App** and have special meanings that you do not need to care about.
    
    *   **version**\[2\]: version number, **version**\[0 \] is the hardware version, **version**\[1\] is the software version.
        
    *   **channel**：Signal channel
        
    *   **joy\_mode**：Robot motion mode
        
    *   **error\_state**：Error status code
        
    *   **buttons**：Button mode
        
    *   **enabled\_from\_app**：Does the App open accompanying
        

# Cases

A simple example of subscribing to "**rt/uwbstate**" to obtain UWB data is as follows. This case needs to be used after the DDS related environment configuration is completed. If not clear, please install unitree_sdk2 first.Use "./subscribe_uwb_state eno1" to run it, where "eno1" is your network interface in local.

```C++
/**
 * @file subscribe_uwb_state.cpp
 * @brief Subscribe the uwb state published from DDS topic
 * @date 2025-01-02
 */
#include "iostream"
#include <unitree/idl/go2/UwbState_.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>

#define TOPIC_UWBSTATE "rt/uwbstate"

using namespace unitree::robot;

void HighStateHandler(const void* message)
{
    unitree_go::msg::dds_::UwbState_ uwbstate_ = *(unitree_go::msg::dds_::UwbState_*)message;

    std::cout << "orientation_est:" << uwbstate_.orientation_est() << std::endl;
    std::cout << "pitch_est:" << uwbstate_.pitch_est() << std::endl;
    std::cout << "distance_est:" << uwbstate_.distance_est() << std::endl;
    std::cout << "yaw_est:" << uwbstate_.yaw_est() << std::endl;

    std::cout << "tag_roll:" << uwbstate_.tag_roll() << std::endl;
    std::cout << "tag_pitch:" << uwbstate_.tag_pitch() << std::endl;
    std::cout << "tag_yaw:" << uwbstate_.tag_yaw() << std::endl;

    std::cout << "base_roll:" << uwbstate_.base_roll() << std::endl;
    std::cout << "base_pitch:" << uwbstate_.base_pitch() << std::endl;
    std::cout << "base_yaw:" << uwbstate_.base_yaw() << std::endl;

    std::cout << std::endl;
}

int main(int argc, char **argv)
{

  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);

  //创建一个Subscriber
  ChannelSubscriber<unitree_go::msg::dds_::UwbState_> suber(TOPIC_UWBSTATE);

  //初始化Channel
  suber.InitChannel(HighStateHandler);

  while(1)
  {
    usleep(20000);
  }

  return 0;
}
 ```   

**The CMakeLists.txt configuration is as follows**

```C++
project(example)
cmake_minimum_required(VERSION 3.16)

include_directories(/usr/local/include/ddscxx /usr/local/include/iceoryx/v2.0.2)

link_libraries(unitree_sdk2 ddsc ddscxx rt pthread)

add_executable(subscribe_uwb_state subscribe_uwb_state.cpp)
```
**Print Results**
```C
orientation_est:1.45361
pitch_est:0.612117
distance_est:2.2581
yaw_est:1.74529
tag_roll:-1.57486
tag_pitch:0.00332104
tag_yaw:-1.33394
base_roll:-0.00436199
base_pitch:-0.0273653
base_yaw:0.0620915
```
# Other

In addition to “**rt/uwbstate**”, there are also DDS topics related to UWB, such as "rt/api/uwbswitch", which is used to disable and enable Go2 companion functions for use by the **Unitree Go App**.

--- 

# Fault Services Interface

# Introduction

Fault information is distributed across different DDS data and topics, such as fault data from sources such as BMS and motors in **rt/lowstate**(**LowState\_.idl**), and faults in peripheral devices such as radar and UWB also have corresponding topics and idl. If you only care about the fault data of a specific device, you can directly obtain it using the corresponding topic and idl. However, if you need to subscribe to all faults, you can subscribe to the fault set. The fault set is obtained by the WebRTC module by subscribing to all fault related topics and integrating them.

![](https://doc-cdn.unitree.com/static/2023/10/13/7665aa89a58e4322b9f4876f8a949d3a_8000x4500.png)

A typical fault code is formatted as uint32, uint16, or uint8, with each bit representing a fault. A single fault code can represent up to 32, 16, or 8 faults. In order to distinguish different fault sources, the concept of fault source code was introduced.

|**Fault source code: UINT32** | **Fault code: UINT32 (maximum of 32 faults)**|
|:--- | :---|

Topic: rt/errorlist, IDL: String\_.idl

```C++
#ifndef __std_msgs__msg__string__idl__
#define __std_msgs__msg__string__idl__

module std_msgs {
module msg {
module dds_ {
struct String_ {
string data;
};

};  // module dds_
};  // module msg
};  // module std_msgs

#endif  // __std_msgs__msg__string__idl__
```    

|  **Field**  |  **Type**  |  **Description**  |  **value**  |
| :---: | :---:| :---: | --- |
|  data  |  string (json)  |  Current fault set  |  {"errors":\[\[Timestamp, fault source, fault code\], \[Timestamp, fault source, fault code\], \[Timestamp, fault source, fault code\], \[Timestamp, fault source, fault code\]\]}  |

The fault code is defined as follows:

|  **Fault source code: UINT32**  |  **Fault code: UINT32 (maximum of 32 faults)**  |
| :--- | :--- |

Distinguish the fault source through the fault source code, and determine the specific fault for the same fault source through the fault code.

A single fault is implemented through bit operations, and each fault code represents up to 32 independent faults.

## Error code

|   | Fault Source Code | Fault Source Topic | Fault IDL | Fault Code | Error Name | Other | Level|
| :---: | :---: | :---: | :---: | :---: | --- | :---: | :---: |
|Bottom communication firmware | 100 | rt/lf/lowstate | LowState.bit\_flag | 0x20 | Remote control communication error | Abandoned | Fault|
|  |  |  |  |  0x01 | Bottom communication detection motion control DDS message timeout | Obsolete | Fault|
|  |  |  |  |  0x40 | MCU communication abnormality | | Fault|
|  |  |  |  |  0x80 | Abnormal motor communication | | Fault|
|  |  |  |  |  0x10 | Abnormal battery communication | | Fault|
|  |  |  |  |  0x02  |  Abnormal distribution switch  |   |  Fault  |
|  |  200  |  rt/lf/lowstate  |  LowState.fanFrequency\[3\]  | 0x01 | Left rear fan stuck | Abandoned | Fault|
|  |  |  |  |  0x02  |  Right rear fan blocked rotation | | Fault|
|  |  |  |  |  0x04  |  Front fan blocked rotation  |  |  Fault  |
|  Motor  |  300+(leg\*3 + motor)  |  rt/lf/lowstate  |  MotorState\[leg\*3 + motor\].reserve\[0\]  |  0x01  |  Overcurrent  |  MotorState\[leg\*3 + motor\].reserve\[1\] (communication frequency of this motor at this moment)  |  Fault  |
|  |  |  |  |  0x02  |  Overvoltage fault  |  |  Fault  |
|  |  |  |  |  0x04  |  Drive overheating  |  |  Fault  |
|  |  |  |  |  0x08  |  Bus undervoltage  |  |  Fault  |
|  |  |  |  |  0x10  |  Winding overheating  |  |  Fault  |
|  |  |  |  |  0x20  |  Encoder abnormal  |  |  Fault  |
|  |  |  |  |  0x100  |  Motor communication interrupted  |  |  Fault  |
|  Radar  |  400  |  rt/utlidar/lidar\_state  |  LidarState.error\_state  |  0x01  |  Abnormal motor speed  |   |  Fault  |
|  |  |  |  |  0x02  |  Point cloud data abnormality  |   |  Fault  |
|  |  |  |  |  0x04  |  Serial port data abnormality  |   |  Fault  |
|  UWB  |  500  |  rt/uwbstate  |  UwbState.error\_state  |  0x01  |  UWB serial port opening exception | When abnormal, no UWB data  |  Fault  |
|  |  |  |  |  0x02  |  Abnormal acquisition of robot status information | When abnormal, no UWB data  |  Fault  |
|  Motion Control  |   |   |   |   |   |   |   |

--- 

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

--- 

# Aruco Recharge Service Interface

# Go2 Aruco Recharge Service Interface

!!! note Attention:

Only Go2 with NX docking station is supported to use this service. During use, only the front camera of Go2 is called, so it is necessary to ensure that the front camera of Go2 is not obstructed.
  Before recharging, please install the charging board and Aruco maker holder correctly, and when recharging with the Aruco maker correctly, the Go2 should face the Aruco maker as much as possible, and the distance from the Aruco maker should not exceed `1.5m`. Users need to remotely control to the vicinity of the charging pad or use navigation to allow Go2 to navigate to the vicinity of the charging pad, and then call the Aruco maker recharge service. In addition, the camera parameters of each Go2 may be different, which may result in deviations in Aruco maker recognition. Different versions of motion control for Go2 may result in prolonged pose adjustment time during recharging.
!!!

### Aruco Recharge Service Download
[Go2 Download](https://oss-global-cdn.unitree.com/static/d778b298a34647f8bf27d14512896bfd.zip)
[Go2-W Download](https://oss-global-cdn.unitree.com/static/dae7aa244f1a41728fcaf225b4b7cecf.zip)

### 1.Aruco maker printing and installation instructions

​	Download the [Aruco Recharge](https://oss-global-cdn.unitree.com/static/af1fdf42bc334572a0375523d1f4daef.zip) and unzip it, attach a Aruco maker image to the file for self printing and pasting. If you need to replace the Aruco maker with another one, there are the following restrictions: the Aruco maker type only supports `36h11` type, the length of the black part of the printed Aruco maker is` 0.1075m`, and the x positive direction of the printed Aruco maker must face left and the y positive direction must face down, as shown in the picture. 

![](https://doc-cdn.unitree.com/static/2024/9/27/bb5127f5b2da4bb2a6a0b2e5be71798b_200x200.png)

If the length of the black part of the printed Aruco maker is not `0.1075m`, it is necessary to modify the corresponding parameters of `aruco_size` in `aruco_config.yaml` to match the actual measured parameters.

![](https://doc-cdn.unitree.com/static/2024/10/21/8a7543df128e4936953510001f928c59_915x717.png)

Please install the charging pad bracket and paste the Aruco maker according to the following diagram.
![](https://doc-cdn.unitree.com/static/2023/12/27/be13bbf6711841a0b1373019d9c7c072_2424x1303.png)

!!! note Printing precautions: 
 It is best to print with hard matte material to avoid reflection that may cause problems with Aruco maker recognition; And there should be a white edge of about `1cm` around the Aruco maker, and the Aruco maker should be kept flat when pasting.
!!!

### 2. Recharge restriction conditions

When recharging, try to face the Aruco maker with the Go2's head as close as possible, and the distance from the Aruco maker should not exceed `1.5m`. Do not move the Aruco maker during the Go2 movement, and do not place other Aruco makers in the field of view. If you need to use the aruco recharge service at night, you need to supplement the light source separately and do not use the indicator light that comes with the Go2's head.

### 3.Instructions for the operation, interface calling, and status feedback of the recharge service

​	Use command `/aruco_recharge` program with aruco_charge; Open another terminal and use `ros2` to publish the topic of starting recharge. The example is as follows:

`ros2 topic pub /aruco_cmd std_msgs/msg/String "data: 'aruco_start'" -t 1`； DDS can also be used to publish topics in the corresponding format. After release, if a Aruco maker within the field of view is recognized, the recharge service will automatically issue control instructions to move Go2 onto the charging pad.

​	When Go2 successfully lies on the charging pad, it will post the topic`/aruco_state` to the public, with the content being `"aruco_arrive"`. At this time, Go2 will detect the charging status. If it is in the charging state for a certain period of time (about `10 seconds`), it will publish the`/aruco_state` topic to the public, with the content of `"aruco_success"`. At this time, the recharge service will automatically shut down and exit. The topic feedback results are shown in the figure:

![](https://doc-cdn.unitree.com/static/2024/9/27/03a4902b1ce04fceb9291171d27b59f9_283x111.png)

​	If Go2 does not detect that it is in a charging state, it will stand up again to adjust its posture. If the charging status is not detected after lying on the charging pad for three consecutive times, the`/aruco_state` topic will be posted to the public with the content `"aruco_failed"`. At this point, the recharge service automatically shuts down and exits. The topic feedback results are shown in the figure:

![](https://doc-cdn.unitree.com/static/2024/9/27/109a341c3fd9458481c6aa3352074649_230x228.png)

### 4. Additional document description

​	When running the recharge service, several `CSV` format log files will be automatically generated, and deleting them will not affect the operation of the recharge service. It won't take up too much space and can be ignored directly.

### 5.Explanation of failed recharge situations

​	When calling the recharge service, Go2 will automatically detect the charging status. If Go2 is lying behind the charging pad and not in a charging state, it will automatically stand up and readjust its position. Try again up to three times. If it is still not in charging state after three attempts, it is considered a charging failure. At this point, it is necessary to manually shut down or restart the recharge node.

### 6.Explanation of failed operation of recharge service

​	The SDK version that comes with the docking station can directly run the recharge service. If the SDK is upgraded or the location of individual link libraries is changed, it will cause the recharge program to not run properly.
!!! note Attention
If the following error occurs when running the recharge program

![](https://doc-cdn.unitree.com/static/2024/9/27/de56ece73efe4750b9564c4e7be25b24_799x42.png)
!!!

​	This indicates that the version of the Unitree SDK linked by this program is inconsistent with the SDK version in the current system or that the location of the dynamic link library has changed.

​	Enter `ldd aruco_charge` on the terminal to view the link location of the current program's dynamic library.

![](https://doc-cdn.unitree.com/static/2024/9/27/08866062df5c4790bdb601eb2fe201be_1368x691.png)

The two link libraries highlighted by the red box are the cause of this issue.

#### Solution 1

​	Firstly, delete these two soft links. Use the following command

`sudo rm /usr/local/lib/aarch64/libddsc.so.0`

`sudo rm /usr/local/lib/aarch64/libddscxx.so.0`

​	Then, enter `ldd aruco_recharge` on the terminal`

![](https://doc-cdn.unitree.com/static/2024/9/27/4d46fef255c34166939514561a506837_1419x617.png)

​	If the information popped up by the terminal at this time is consistent with the link position circled in the red box, it can run normally. Input/ The aruco_charge interface will appear as follows

![](https://doc-cdn.unitree.com/static/2024/9/27/ad95f330a382462da13f909b07ef53c7_1228x72.png)

At this point, the recharge program can run normally.

#### Solution 2

If method one is completed

```shell
sudo rm /usr/local/lib/aarch64/libddsc.so.0
sudo rm /usr/local/lib/aarch64/libddscxx.so.0
```

​	Afterwards, `ldd aruco_recharge` found that the linked positions of `libddsc.so.0` and `libddscxx.so.0` were different from those in the figure or had broken links. You will need to reinstall Unitree SDK2, which comes with an SDK included in this compressed package and can be installed directly. It is recommended to install to the default location during installation, otherwise linking to dynamic libraries may easily fail.

Precautions for installing SDK

​	If you have previously installed the SDK, you need to delete `libunitree_sdk2. a` from the original installation directory. The default installation location is in the/usr/local/lib directory, and you can use `sudo rm/usr/local/lib/libunitree_sdk2. a`

![](https://doc-cdn.unitree.com/static/2024/9/27/2b181c3b753942bd9bc4006c2c2cc7a6_1410x900.png)

​	After deletion, create a new folder named `build` in unitree_sdk2 and `cd`  into that folder.

![](https://doc-cdn.unitree.com/static/2024/9/27/3e1f9b3a08864a9eb0bdc0e40036d49c_1406x428.png)

​	Execute `cmake ..` (Recommended to install directly to the system default location)

![](https://doc-cdn.unitree.com/static/2024/9/27/11ae14dbf70b43068157b9d7c74df8f9_1290x712.png)

​	After execution, if the terminal prompt message is consistent with the above picture, it can proceed normally downwards.

​	Enter `sudo make install`

​	Just wait for the installation to complete

![](https://doc-cdn.unitree.com/static/2024/9/27/fc4027eb859a417da27aad1a54bd0d0d_1465x803.png)

![](https://doc-cdn.unitree.com/static/2024/9/27/438a6a5546dd4b7a8f5c890f46a51a07_1450x801.png)

​	At this point, return to the directory where the recharge program is located and enter `ldd aruco_charge`

It will appear
![](https://doc-cdn.unitree.com/static/2024/9/27/b055bad5e55f48f184921d7df927e720_1368x691.png)

​	At this point, follow the first step to delete the incorrect soft link

```shell
sudo rm /usr/local/lib/aarch64/libddsc.so.0
sudo rm /usr/local/lib/aarch64/libddscxx.so.0
```

​	Enter `ldd aruco_charge`

![](https://doc-cdn.unitree.com/static/2024/9/27/3c769b156ca94f209ab541b7e1dff6dd_1419x617.png)

You can see the link to the location where the SDK was installed just now. At this point, the recharge program can run `./aruco_recharge` normally, as shown in the figure

![](https://doc-cdn.unitree.com/static/2024/9/27/69c31e2c16fc4b9d974638e2ef4270a7_1284x925.png)

--- 

# Odometer Services Interface

## Legged Fusion Odometry Interface  
Go2 provides an odometry interface that fuses legged (motor) data with IMU integration data. By reading the high-level states, you can obtain the robot's pose information from this interface.  

For Go2 with software version > V1.1.6, please refer to `std::array<float, 3> position()` in https://support.unitree.com/home/zh/developer/Motion_Services_Interface_V2.0#heading-9.  

For Go2 with software version <= V1.1.6, please refer to `std::array<float, 3> position();` in https://support.unitree.com/home/zh/developer/AI_motion_service#heading-6.

## Hardware environment

|**Name** | **Environment**|
| :---: | :--- |
|  host  |  Nvidia orin nx + ubuntu20.04 + ros1 noetic  |
|  deivce  |  realsense D435i(IR1 camera with global shutter)  |

<center>

![10](https://doc-cdn.unitree.com/static/2023/11/15/7ee32fe6cb3c4d13a3f5bb093da19f91_4195x3229.png)

</center>

## Introduction

The high-speed semi direct visual odometer has been successfully deployed locally and adapted to the realsense IR1 monocular camera, which can generate movement trajectories. This article takes the IR1 camera of the Realsense D435i camera as the entity, sends the IR1 camera's topic as the input information of the visual odometer through the ros noeitc, and finally sends the ros topic of the camera's pose.

## Usage Guidelines
1, Due to the feature-based matching nature of visual odometry and the computational limitations of hardware deployed on mobile devices, it is recommended to avoid extremely close-range scenes and rapidly changing scene dynamics in the camera feed.

2, The system performs more reliably when the target distance is maintained at least 1 meter or more. This is primarily because a greater number of trackable and distinctive feature points can be observed, which helps to avoid sudden visual disruptions.

3, If you encounter unsatisfactory performance or frequent system crashes despite following the above guidelines, please consider the following options:
a. Adjust the external environment to a more optimal state.
b. Refer to the official paper and documentation of SVO and attempt to modify the parameters of SVO in the code and configuration files accordingly. When fine-tuning, it is recommended to focus on adjusting the parameters related to inter-frame matching and system recovery after crashes. Please note that increasing the matching threshold results in higher accuracy but also increases the likelihood of system crashes.

## D435i Camera Configuration

1.Install the D435i camera driver for ROS1 version on Ubuntu 20.04 system:

(The default ROS package has been installed)

    sudo apt-get install ros-$ROS_DISTRO-realsense2-camera
    sudo apt-get install ros-$ROS_DISTRO-realsense2-description

For more information on installation, please refer to: [https://github.com/IntelRealSense/realsense-ros/tree/ros1-legacy](https://github.com/IntelRealSense/realsense-ros/tree/ros1-legacy)

2.After successful installation, the default IR camera will not be turned on and you need to modify the configuration yourself:

Enter /opt/ros/noetic/share/realsense2\_camera/launch directory, edit rs\_camera.launch file:

 ```C++
<launch>
  <arg name="serial_no"           default=""/>
  <arg name="usb_port_id"         default=""/>
  <arg name="device_type"         default=""/>
  <arg name="json_file_path"      default=""/>
  <arg name="camera"              default="camera"/>
  <arg name="tf_prefix"           default="$(arg camera)"/>
  <arg name="external_manager"    default="false"/>
  <arg name="manager"             default="realsense2_camera_manager"/>
  <arg name="output"              default="screen"/>
  <arg name="respawn"              default="false"/>

  <arg name="fisheye_width"       default="-1"/>
  <arg name="fisheye_height"      default="-1"/>
  <arg name="enable_fisheye"      default="false"/>

  <arg name="depth_width"         default="-1"/>
  <arg name="depth_height"        default="-1"/>
  <arg name="enable_depth"        default="true"/>

  <arg name="confidence_width"    default="-1"/>
  <arg name="confidence_height"   default="-1"/>
  <arg name="enable_confidence"   default="true"/>
  <arg name="confidence_fps"      default="-1"/>

  <arg name="infra_width"         default="640"/>
  <arg name="infra_height"        default="480"/>
  <arg name="enable_infra"        default="true"/>
  <arg name="enable_infra1"       default="true"/>
  <arg name="enable_infra2"       default="true"/>
  <arg name="infra_rgb"           default="false"/>

  <arg name="color_width"         default="-1"/>
  <arg name="color_height"        default="-1"/>
  <arg name="enable_color"        default="true"/>

  <arg name="fisheye_fps"         default="-1"/>
  <arg name="depth_fps"           default="-1"/>
  <arg name="infra_fps"           default="90"/>
  <arg name="color_fps"           default="-1"/>
  <arg name="gyro_fps"            default="-1"/>
  <arg name="accel_fps"           default="-1"/>
  <arg name="enable_gyro"         default="false"/>
  <arg name="enable_accel"        default="false"/>

  <arg name="enable_pointcloud"         default="false"/>
  <arg name="pointcloud_texture_stream" default="RS2_STREAM_COLOR"/>
  <arg name="pointcloud_texture_index"  default="0"/>
  <arg name="allow_no_texture_points"   default="false"/>
  <arg name="ordered_pc"                default="false"/>

  <arg name="enable_sync"               default="false"/>
  <arg name="align_depth"               default="false"/>

  <arg name="publish_tf"                default="true"/>
  <arg name="tf_publish_rate"           default="0"/>

  <arg name="filters"                   default=""/>
  <arg name="clip_distance"             default="-2"/>
  <arg name="linear_accel_cov"          default="0.01"/>
  <arg name="initial_reset"             default="false"/>
  <arg name="reconnect_timeout"         default="6.0"/>
  <arg name="wait_for_device_timeout"   default="-1.0"/>
  <arg name="unite_imu_method"          default=""/>
  <arg name="topic_odom_in"             default="odom_in"/>
  <arg name="calib_odom_file"           default=""/>
  <arg name="publish_odom_tf"           default="true"/>

  <arg name="stereo_module/exposure/1"  default="7500"/>
  <arg name="stereo_module/gain/1"      default="16"/>
  <arg name="stereo_module/exposure/2"  default="1"/>
  <arg name="stereo_module/gain/2"      default="16"/>
  
  

  <group ns="$(arg camera)">
    <include file="$(find realsense2_camera)/launch/includes/nodelet.launch.xml">
      <arg name="tf_prefix"                value="$(arg tf_prefix)"/>
      <arg name="external_manager"         value="$(arg external_manager)"/>
      <arg name="manager"                  value="$(arg manager)"/>
      <arg name="output"                   value="$(arg output)"/>
      <arg name="respawn"                  value="$(arg respawn)"/>
      <arg name="serial_no"                value="$(arg serial_no)"/>
      <arg name="usb_port_id"              value="$(arg usb_port_id)"/>
      <arg name="device_type"              value="$(arg device_type)"/>
      <arg name="json_file_path"           value="$(arg json_file_path)"/>

      <arg name="enable_pointcloud"        value="$(arg enable_pointcloud)"/>
      <arg name="pointcloud_texture_stream" value="$(arg pointcloud_texture_stream)"/>
      <arg name="pointcloud_texture_index"  value="$(arg pointcloud_texture_index)"/>
      <arg name="enable_sync"              value="$(arg enable_sync)"/>
      <arg name="align_depth"              value="$(arg align_depth)"/>

      <arg name="fisheye_width"            value="$(arg fisheye_width)"/>
      <arg name="fisheye_height"           value="$(arg fisheye_height)"/>
      <arg name="enable_fisheye"           value="$(arg enable_fisheye)"/>

      <arg name="depth_width"              value="$(arg depth_width)"/>
      <arg name="depth_height"             value="$(arg depth_height)"/>
      <arg name="enable_depth"             value="$(arg enable_depth)"/>

      <arg name="confidence_width"         value="$(arg confidence_width)"/>
      <arg name="confidence_height"        value="$(arg confidence_height)"/>
      <arg name="enable_confidence"        value="$(arg enable_confidence)"/>
      <arg name="confidence_fps"           value="$(arg confidence_fps)"/>

      <arg name="color_width"              value="$(arg color_width)"/>
      <arg name="color_height"             value="$(arg color_height)"/>
      <arg name="enable_color"             value="$(arg enable_color)"/>

      <arg name="infra_width"              value="$(arg infra_width)"/>
      <arg name="infra_height"             value="$(arg infra_height)"/>
      <arg name="enable_infra"             value="$(arg enable_infra)"/>
      <arg name="enable_infra1"            value="$(arg enable_infra1)"/>
      <arg name="enable_infra2"            value="$(arg enable_infra2)"/>
      <arg name="infra_rgb"                value="$(arg infra_rgb)"/>

      <arg name="fisheye_fps"              value="$(arg fisheye_fps)"/>
      <arg name="depth_fps"                value="$(arg depth_fps)"/>
      <arg name="infra_fps"                value="$(arg infra_fps)"/>
      <arg name="color_fps"                value="$(arg color_fps)"/>
      <arg name="gyro_fps"                 value="$(arg gyro_fps)"/>
      <arg name="accel_fps"                value="$(arg accel_fps)"/>
      <arg name="enable_gyro"              value="$(arg enable_gyro)"/>
      <arg name="enable_accel"             value="$(arg enable_accel)"/>

      <arg name="publish_tf"               value="$(arg publish_tf)"/>
      <arg name="tf_publish_rate"          value="$(arg tf_publish_rate)"/>

      <arg name="filters"                  value="$(arg filters)"/>
      <arg name="clip_distance"            value="$(arg clip_distance)"/>
      <arg name="linear_accel_cov"         value="$(arg linear_accel_cov)"/>
      <arg name="initial_reset"            value="$(arg initial_reset)"/>
      <arg name="reconnect_timeout"        value="$(arg reconnect_timeout)"/>
      <arg name="wait_for_device_timeout"  value="$(arg wait_for_device_timeout)"/>
      <arg name="unite_imu_method"         value="$(arg unite_imu_method)"/>
      <arg name="topic_odom_in"            value="$(arg topic_odom_in)"/>
      <arg name="calib_odom_file"          value="$(arg calib_odom_file)"/>
      <arg name="publish_odom_tf"          value="$(arg publish_odom_tf)"/>
      <arg name="stereo_module/exposure/1" value="$(arg stereo_module/exposure/1)"/>
      <arg name="stereo_module/gain/1"     value="$(arg stereo_module/gain/1)"/>
      <arg name="stereo_module/exposure/2" value="$(arg stereo_module/exposure/2)"/>
      <arg name="stereo_module/gain/2"     value="$(arg stereo_module/gain/2)"/>

      <arg name="allow_no_texture_points"  value="$(arg allow_no_texture_points)"/>
      <arg name="ordered_pc"               value="$(arg ordered_pc)"/>
      
    </include>
  </group>
</launch>
```

To activate the IR camera topic posting, set their resolution to 640\*480 and frame rate to 90.

3.Then run the camera's ROS node in Terminal

    roslaunch realsense2_camera rs_camera.launch

4.Create a new window and enter the following command:

    rostopic list

View the list of published topics Successfully published topics:

*   /camera/infra1/image\_rect\_raw

5.Create a new window and enter the following command:
  
rostopic hz /camera/infra1/image_rect_raw

Check that the image transmission frequency is 90.

6.Turn off the laser transmitter for realsense D435i

After the third step is successfully executed, execute the following command

    rosrun rqt_reconfigure rqt_reconfigure 

Turn off the laser emitter in the pop-up interface:
![](https://doc-cdn.unitree.com/static/2023/9/11/f3b2cd2061c3423ba7cfe5887dcaa29b_1254x659.png)

## Visual odometer configuration

1.This device is already compatible with the visual odometer, and this document does not state the details of the build project or parameter adjustment. For more information, please refer to the official homepage: [https://github.com/uzh-rpg/rpg\_svo\_pro\_open](https://github.com/uzh-rpg/rpg_svo_pro_open). The various parameter adjustments, project settings, and camera calibration for this project have been completed. The detailed details are presented below for reference. If you are not interested in this process, you can directly skip and enter the project running process.

2.Enter the project folder  /home/unitree/unitree/Odometer_service/src/rpg\_svo\_pro\_open/svo\_ros/param directory, add the configuration file " rs\_camera\_param.yaml ":

```c++
# Instructions:
# - Most of the time you will just need to change the basic parameters.
# - The parameters in this file are set for the resolution of 752x480.
#   If you use a different resolution, change the parameters for
#   each module according to the comments.

############################
##### Basic parameters #####
############################

# Pipeline type
pipeline_is_stereo: False

# Feature and keyframe number
# To run faster, you can decrease `max_fts` and `max_n_kfs`, for example:
# max_fts: 120
# max_n_kfs: 5
max_fts: 180
max_n_kfs: 30

# Map scale when initialized (not used for stereo)
# Increase if the initial scene depth is larger
map_scale: 1.0

# Initial rotation
T_world_imuinit/qx: 0
T_world_imuinit/qy: 0
T_world_imuinit/qz: 0
T_world_imuinit/qw: 1

# Keyframe selection
kfselect_criterion: FORWARD    # alterntive: DOWNLOOKING
# The following kfselect_* ONLY affects FORWARD
# If the number of features: >upper, no keyframe; <lower, take keyframe
kfselect_numkfs_upper_thresh: 120
kfselect_numkfs_lower_thresh: 70
# If the current frame is within the following range of any visible keyframes,
```

3.Enter the new camera calibration parameter file " rs\_camera\_calib.yaml " in the src/rpg\_svo\_pro\_open/svo\_ros/param/calib directory:

  ```c++
label: my_stereo_camera
cameras:
- camera:
    label: cam0
    line-delay-nanoseconds: 0
    image_height: 480
    image_width: 640
    type: pinhole
    intrinsics:
      cols: 1
      rows: 4
      data: [384.901397705078, 384.901397705078, 321.478607177734, 239.256011962891]
    distortion:
      type: radial-tangential  
      parameters:
        cols: 1
        rows: 4
        data: [0, 0, 0, 0]
  T_B_C:
    cols: 4
    rows: 4
    data: [1, 0.0, 0, 0,
           0.0, 1, 0, 0,
           0.0, 0.0, 1.0, 0 ,
           0.0, 0.0, 0.0, 1.0]
```

4.Enter directory  /unitree/module/Odometer_service/src/rpg\_svo\_pro\_open/svo\_ros/launch, add the launch file “rs\_camera.launch”:

 ```c++
<launch>

  <node pkg="svo_ros" type="svo_node" name="svo" respawn="true" clear_params="true" output="screen">

  
    <param name="cam0_topic" value="/camera/infra1/image_rect_raw" type="str" />

  
    <param name="calib_file" value="$(find svo_ros)/param/calib/rs_camera_calib.yaml" type="str" />

  
    <rosparam file="$(find svo_ros)/param/rs_camera_param.yaml" />

  
    <param name="init_rx" value="3.14" />
    <param name="init_ry" value="0.00" />
    <param name="init_rz" value="0.00" />
  </node>

</launch>
```

5.Adjust the inter frame matching standard parameters of the project source code to make the project more suitable for the usage scenarios of land walking mobile robots, and reduce the probability of project crashes and restarts.

## Running the overall system

1.Open the terminal to run roscore

```language
roscore
```

2.Open the new terminal to run the camera and raise a topic.

```language
roslaunch realsense2_camera rs_camera.launch
```

3.Run the terminal and open rviz

```language
rviz
```

Open the “rviz\_config.rviz” configuration file located in the project folder directory  /home/unitree/unitree/Odometer\_service/src/rpg\_svo\_pro\_open/svo\_ros in rviz to book project topics.

4.Run Project
Before running the project, open the terminal source space in the project root directory /home/unitree/unitree/Odometer\_service/:
```language
source devel/setup.bash

```

The enter the  /home/unitree/unitree/Odometer\_service/src/rpg\_svo\_pro\_open/svo\_ros/launch path in the project folder and open the terminal to input:

```language
roslaunch rs_camera.launch 
```

5.The mobile camera has completed project initialization and the project is running normally.

6.View topics emitted by the project

```language
rostopic list
```

7.Subscribe to camera pose trajectory

`/svo/pose\_cam/0`

At this point, users can view the camera position in real-time

8.Reviz View Key Data and Camera Trajectories, Enter the  /home/unitree/unitree/Odometer\_service/src/rpg\_svo\_pro\_open/svo\_ros/ path in the project folder and open the terminal to input:

```language
rviz -d rviz_config_vio.rviz
```

--- 

# D1 Mechanical Arm Services Interface

# Introduction

The service starts when the steering gear arm of D1 is powered on, and the control function of the manipulator arm is realized by invoking the interface of the service. The specific functions are as follows.

|                                 |                                                              |
| ------------------------------- | ------------------------------------------------------------ |
| joint Angle control of a single robot arm | By controlling the motor Angle of a single joint of the robot arm, the control of the robot arm |
| all joint Angle control of the robot arm | By controlling the motor Angle of all joints of the robot arm, the control of the robot arm |
| single arm joint motor enable/discharge force control | the control joint motor state is locked/free. In the free state, with the joint Angle feedback interface, drag memory teaching | can be realized
| all joint motors of the manipulator arm enable/unload force control | The state of all joint motors is controlled as lock/free. With the joint Angle feedback interface in free state, drag memory teaching | can be realized
| The power supply switch of the motor of the manipulator | controls whether to power the motor (can be used for emergency stop) |
| robotic arm position return to zero | In any position return to zero |
|                                 |                                                              |
| robot arm joint Angle feedback | Feedback real-time Angle of robot arm joint |
| robot arm status feedback | Feedback the enable/discharge status and power-on status of the robot arm |
|                                 |                                                              |
| command receive feedback | The feedback after receiving the control command is regarded as the successful reception |
| command execution feedback | Feedback after the control command is executed, which indicates that the command is successfully executed |

# Specification Parameters

|Structural parameters ||
| - | - |
|Model | D1-550|
|Weight | 3152g|
|Degrees of Freedom | 6 (degrees of freedom)+1 (gripper)|
|Arm length | 550mm (excluding jaws), 670mm (including jaws)|
|Rated load | 500g (including clamp weight)|
|Working radius | 550mm|
|Torque of each joint motor | J0: 3.3NM <BR>J1:  3.3NM <BR>J2:  1.7NM <BR>J3:  1.7NM <BR>J4:  1.7NM <BR>J5:  1.7NM <BR>J6:  1.7NM |
|Range of motion for each joint | J0: ±135°<BR>J1:  ±90°<BR>J2:  ±90°<BR>J3:  ±135°<BR>J4:  ±90°<BR>J5:  ± 135 °<BR>Claw stroke: 0-65mm|
|Motor type | Bus servo|

|Electrical parameters ||
| - | - |
|Power requirement | 24V 10A (15-48V)|
|Power | 240W|
|Controller | Integrated (4 x Cortex-A55 1.8GHz)|
|Communication method | RJ45 (Ethernet 100Mbps communication)+Type-C (serial port debugging)|
|Control Method | DDS Subscription|
|Control cycle | 10Hz|

#  Mechanical arm structure diagram 

<center>

![](https://doc-cdn.unitree.com/static/2023/10/13/c011ca1e58c54b3ea66df65a90e56f51_645x736.png)

</center>

The robot arm basic 6 axis +1 clamp, starting from the base is 0, to the clamp is 6.

#  Interface Protocol 

All data is transmitted using strings in Json format, including seq (unique identifier), address (instruction address code), funcode (instruction function code), and data (data content). data content can be nested with Json data.

The seq of the command to be sent is automatically generated by the calling end, except that the seq of the active message is 10 (write dead). In order to distinguish the sequence of reply messages, no parsing is required, and only the seq of this command is sent back when the reply is made.

| function | seq | address | funcode | data | Example data | description         |
| ------------------------------- | ---------- | ------- | ------- |  ------------------------------------------------------------ |  ------------------------------------------------------------ |  ------------------------------------------------------------ |
| angle control of single robotic arm joint | The calling end generates | 1 | 1 | id, Angle, and delay_ms | {"seq":4,"address":1,"funcode":1",data":{"id": joint number,"angle": joint target angle,"delay_ms": execution time}} | id is the corresponding joint number, angle is the joint target Angle, delay_ms Execution time is temporarily set to 0 |
| All robotic arm joint Angle control | The calling end generates | 1 | 2 | mode and angle0~6 | {" seq ": 4," address ": 1," funcode ": 2," data ": {" mode" : control mode, the angle0 ": joint Angle of 0," angle1 ": joint 1 Angle value," angle2 ": joint Angle value, 2" angle3 ": 3 joints Angle value," ang le4": Angle value of joint 4,"angle5": Angle value of joint 5,"angle6": Angle value of joint 6}} | are respectively the mode control mode and the joint Angle value of angle0~6. mode 0 is the small smoothing of 10Hz data, and mode 1 is the large smoothing of trajectory use |
| Enable/force discharge control of a single manipulator joint motor | The calling end generates | 1 | 4 | mode | {"seq":4,"address":1,"funcode":4,"data":{"id": joint id,"mode": enable mode}} | ID indicates the joint ID, mode is 0 to release force, and mode is 1 to enable |
| Enable/force discharge control of all mechanical arm joint motors | The calling end generates | 1 | 5 | mode | {"seq":4,"address":1,"funcode":5,"data":{"mode": enable mode}} | mode indicates that 0 is removed and mode 1 indicates that | is enabled
| power supply switch of the mechanical arm motor | The calling end generates | 1 | 6 | power | {"seq":4,"address":1,"funcode":6,"data":{"power": enable mode}} | power if 0 is powered off, power 1 is powered on |
| robotic arm posture returns to zero | | 1 | 7 | none | is generated on the calling end {"seq":4,"address":1,"funcode":7} | None    |
|                                 |            |         |         |                                                               |                                                              |                                                               |
| mechanical joint Angle feedback | 10 | 2 | 1 | angle0~6   |  {" seq ": 10," address ": 2," funcode ": 1," data ": {0" angle0 ": joint Angle value," angle1 ": joint 1 Angle value," angle2 ": joint Angle value, 2" angle3 ": joint 3 point of value," angle4 ": joint four angles Value,"angle5": Angle value of joint 5,"angle6": Angle value of joint 6}} | Feedback real-time Angle of the joint of the manipulator, upload frequency 10Hz |
| Robotic arm status feedback | 10 | 2 | 3 | enable_status, pow_status, and error_status | {"seq":10,"address":2,"funcode":3,"data":{"enable_status": enable status,"power_status": power-on status,"error_status": fault status}} | Provides the real-time status of the manipulator. enable_status Indicates that the function is enabled. 1 Indicates that the function is enabled. 0 Indicates that the function is removed. power_status: Indicates the power supply status. 1 indicates the power supply. 0 indicates the power supply. error_status indicates the fault status. 1 is normal, 0 is abnormal |
| Online status detection of mechanical arm motor | 10 | 2 | 4 | motor0_status, motor1_status, motor2_status, motor3_status, motor4_status, motor5_status, motor6_status | {"seq":10,"address":2,"funcode":4,"data":{"motor0_status":motor0 status,"motor1_status":motor1 status,"motor2_status":motor2 status,"mo tor3_status":motor3 status,"motor4_status":motor4 status,"motor5_status":motor5 status,"motor6_status":motor6 status}} | Feedback motor status, If the motor is faulty, the corresponding status is 0, and normally it is 1 |
|                                 |            |         |         |                                                               |                                                              |                                                               |
| feedback | The caller generates | 3 | 1 | recv_status | {"seq":10,"address":3,"funcode":1,"data":{"recv_status": Receive status}} | The reception is successful. If recv_status is 1, the reception is successful. A value of 0 indicates that the sent data is incorrect (the format is incorrect, cannot be parsed, is out of function scope, etc.) |
| command execution feedback | | 3 | 2 | exec_status | is generated on the invoke end {"seq":10,"address":3,"funcode":2,"data":{"exec_status": execution status}} | If exec_status is 1, the execution succeeds, and 0, the execution fails |

The service provides two interfaces to the outside world, namely rt/arm_Command and rt/arm_Feedback. rt/arm_Command sends data and command requests to the service. rt/arm_Feedback gets data uploaded by the service. Where rt/arm_

```idl
// generated from rosidl_generator_dds_idl/resource/idl.idl.em
// with input from unitree_arm:msg/ArmString.idl
// generated code does not contain a copyright notice

#ifndef __unitree_arm__msg__arm_string__idl__
#define __unitree_arm__msg__arm_string__idl__

module unitree_arm {

module msg {

module dds_ {

struct ArmString_ {
string data_;

};

};  // module dds_

};  // module msg

};  // module unitree_arm

#endif  // __unitree_arm__msg__arm_string__idl__

```

# Acquisition and use of SDK and sample programs

The SDK and sample program running environment of the robot arm rely on unitree_sdk2, and it is necessary to deploy unitree_sdk2 before the development of D1.

The SDK and sample programs for D1 can be downloaded here:

[https://unitree-firmware.oss-cn-hangzhou.aliyuncs.com/tool/d1_sdk.zip](https://unitree-firmware.oss-cn-hangzhou.aliyuncs.com/tool/d1_sdk.zip)

After the download is complete, create a folder in it, and use cmake to build and make to compile.

![](https://doc-cdn.unitree.com/static/2024/2/28/731e146128ea4db69b93362a5d624932_1292x340.png)

**arm_zero_control.cpp:** Robot arm zero_example program;

**get_arm_joint_angle.cpp**: Obtain the robotic arm joint Angle value sample program;

**joint_angle_control.cpp:** Robot arm single joint Angle control example program;

**joint_enable_control.cpp:** Robot arm joint enable control example program;

**multiple_joint_angle_control:** Robot arm multi-joint Angle control example program.

Among them, msg file is the D1 robot arm SDK interface file that we need to use. In the future, we only need to add these files in our own project. You can also copy the file to /usr/local/include, add it to the directory include_directories, and use link_libraries to link files .  Currently, only ubuntu is supported. And depends on unitree_sdk2.

# Robotic Arm  Download
Gripper version: [https://oss-global-cdn.unitree.com/static/90b2525be5d84531ab9814f48b2f86a7.zip](https://oss-global-cdn.unitree.com/static/90b2525be5d84531ab9814f48b2f86a7.zip)
Grip-free version: [https://oss-global-cdn.unitree.com/static/02c95ece8e354143b874a3c963241467.zip](https://oss-global-cdn.unitree.com/static/02c95ece8e354143b874a3c963241467.zip)
STEP：[STEP Simplified Model](https://oss-global-cdn.unitree.com/static/5bade30b2a454376978ab2853589e5f7.zip)
D1-550 STEP: [D1-550 STEP](https://oss-global-cdn.unitree.com/static/fc33175f0fbd4fb0842e588080c2b3d9.zip)
D1-550 URDF: [D1-550 URDF](https://oss-global-cdn.unitree.com/static/9b20252a26374d50aa369532657d0143.zip)
D1-550 gripper open source files: [D1-550 gripper open source files](https://oss-global-cdn.unitree.com/static/6f0d89dcedde40f1a59272b71c5363a2.zip)

| Category | differences |
| -  | - |
| gripper version | The end gripper can be opened and closed through the slider interface, which is suitable for the development of grasping tasks under simulation |
| gripless version | The end gripper has a fixed structure and is fixed to the end shaft of the manipulator. The gripper cannot be opened or closed. It is suitable for only cloud end pose simulation task |

#  Use examples 

##### 1. Single joint Angle control of mechanical arm

Using the rt/arm_Command topic, assume that the generated seq value is 4 and set the Angle of joint 5 to 60. The data content for ` {" seq ": 4," address ": 1," code ": 1," data ": {" id" : 5, "Angle" : 60, "delay_ms" : 0}} `

```c++
#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>
#include "msg/ArmString_.hpp"

#define TOPIC "rt/arm_Command"

using namespace unitree::robot;
using namespace unitree::common;

int main()
{
    ChannelFactory::Instance()->Init(0);
    ChannelPublisher<unitree_arm::msg::dds_::ArmString_> publisher(TOPIC);
    publisher.InitChannel();

    unitree_arm::msg::dds_::ArmString_ msg{};
    msg.data_() = "{\"seq\":4,\"address\":1,\"funcode\":1,\"data\":{\"id\":5,\"angle\":60,\"delay_ms\":0}}";
    publisher.Write(msg);
 
    return 0;
}

```

##### 2. Multi-joint Angle control of mechanical arm

Using the rt/arm_Command topic, it is assumed that the generated seq value is 4 and the joint Angle of the manipulator arm is {0, -60, 60, 0, 30, 0, 0, 0}. The data content for ` {" seq ": 4," address ": 1," funcode ": 2," data ": {" mode" : 1, "angle0" : 0, "angle1" : to 60, "angle2" : 60, "angle3" : 0, "angle4" : 30, "ang le5":0,"angle6":0}}`

```c++
#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>
#include "msg/ArmString_.hpp"

#define TOPIC "rt/arm_Command"

using namespace unitree::robot;
using namespace unitree::common;

int main()
{
    ChannelFactory::Instance()->Init(0);
    ChannelPublisher<unitree_arm::msg::dds_::ArmString_> publisher(TOPIC);
    publisher.InitChannel();

    unitree_arm::msg::dds_::ArmString_ msg{};
    msg.data_() = "{\"seq\":4,\"address\":1,\"funcode\":2,\"data\":{\"mode\":1,\"angle0\":0,\"angle1\":-60,\"angle2\":60,\"angle3\":0,\"angle4\":30,\"angle5\":0,\"angle6\":0}}";
    publisher.Write(msg);
 
    return 0;
}
```

##### 3. Enable/unload force control of mechanical arm joint motor

Through the rt/arm_Command topic, assuming that the seq value generated at this time is 4, control all joint unloading force. The data content for ` {" seq ": 4," address ": 1," funcode ": 5," data ": {" mode" : 0}} `

```c++
#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>
#include "msg/ArmString_.hpp"

#define TOPIC "rt/arm_Command"

using namespace unitree::robot;
using namespace unitree::common;

int main()
{
    ChannelFactory::Instance()->Init(0);
    ChannelPublisher<unitree_arm::msg::dds_::ArmString_> publisher(TOPIC);
    publisher.InitChannel();

    unitree_arm::msg::dds_::ArmString_ msg{};
    msg.data_() = "{\"seq\":4,\"address\":1,\"funcode\":5,\"data\":{\"mode\":0}}";
    publisher.Write(msg);
 
    return 0;
}
```

The mode ranges from 0 to 80000. 0 is fully unloaded and 80000 is fully locked.

##### 4. Robotic arm position and posture return to zero

Through the rt/arm_Command topic, assuming that the seq value generated at this time is 4, the manipulator is controlled to return to zero position. The data content is' {"seq":4,"address":1,"funcode":7} '

```c++
#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>
#include "msg/ArmString_.hpp"

#define TOPIC "rt/arm_Command"

using namespace unitree::robot;
using namespace unitree::common;

int main()
{
    ChannelFactory::Instance()->Init(0);
    ChannelPublisher<unitree_arm::msg::dds_::ArmString_> publisher(TOPIC);
    publisher.InitChannel();

    unitree_arm::msg::dds_::ArmString_ msg{};
    msg.data_() = "{\"seq\":4,\"address\":1,\"funcode\":7}";
    publisher.Write(msg);
 
    return 0;
}
```

##### 5. Obtain real-time joint Angle

The seq value of the instruction is fixed at 10, the upload frequency is 10Hz, and the data is distinguished by the address address +code function code, which requires callback monitoring.

```c++
#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/common/time/time_tool.hpp>
#include "msg/PubServoInfo_.hpp"
#include "msg/ArmString_.hpp"

#define TOPIC "current_servo_angle"
#define TOPIC1 "arm_Feedback"

using namespace unitree::robot;
using namespace unitree::common;

void Handler(const void* msg)
{
    const unitree_arm::msg::dds_::PubServoInfo_* pm = (const unitree_arm::msg::dds_::PubServoInfo_*)msg;

    std::cout << "servo0_data:" << pm->servo0_data_() << ", servo1_data:" << pm->servo1_data_() << ", servo2_data:" << pm->servo2_data_()<< ", servo3_data:" << pm->servo3_data_()<< ", servo4_data:" << pm->servo4_data_()<< ", servo5_data:" << pm->servo5_data_()<< ", servo6_data:" << pm->servo6_data_() << std::endl;
}

void Handler1(const void* msg)
{
    const unitree_arm::msg::dds_::ArmString_* pm = (const unitree_arm::msg::dds_::ArmString_*)msg;

    std::cout << "armFeedback_data:" << pm->data_() << std::endl;
}

int main()
{
    ChannelFactory::Instance()->Init(0);
    ChannelSubscriber<unitree_arm::msg::dds_::PubServoInfo_> subscriber(TOPIC);
    subscriber.InitChannel(Handler);

    ChannelSubscriber<unitree_arm::msg::dds_::ArmString_> subscriber1(TOPIC1);
    subscriber1.InitChannel(Handler1);

    while (true)
    {
        sleep(10);
    }

    return 0;
}
```

# D1-T configuration and usage

[Basic Demo](https://oss-global-cdn.unitree.com/static/82b7daf1ca8d43a3aa0f6b8421272abe.zip)

D1-T is the use of routers/switches to achieve data communication between two D1 robotic arms, the joint data of one robotic arm is input to the other robotic arm for execution. The default IP address of the D1 robot arm is 192.168.123.100. When using D1-T, we need to change the IP address of the other robot arm to 192.168.123.xxx, which is 192.168.123.99. We can also modify it according to our own needs.

The D1-T consists of two sets of D1 robotic arms, one of which has a hand-held claw at the end, which acts as the data acquisition end. Power on any robot arm and connect it to the router/switch through a network cable.

#### Router Configuration

We need to go to the background management interface of the router, change the WAN network segment to 192.168.123.xx in the location of the router IP address assignment.

After the modification is successful and saved, use your PC to connect to the router and run ping 192.168.123.100 through the terminal to check whether the communication is normal.

#### Change the IP address of the manipulator

After ensuring that the communication between the computer and the robot arm is correct, open the terminal and log in to the robot arm system through ssh, password 123, and the instructions are as follows.

```shell
ssh ubuntu@192.168.123.100
```

After the login is successful, enter the ip configuration path /etc/network, and change the IP address in the interface file to 192.168.123.99 through the vim command. After the modification, save the IP address and restart the system.

![](https://doc-cdn.unitree.com/static/2024/2/28/193d10bb373c4a94962ffb475fbab7a4_804x366.png)

Power on the other robotic arm and connect it to the router. The IP addresses of the two robotic arms are 192.168.123.99 and 192.168.123.100 respectively. Run the ping command to check the two IP addresses to ensure normal communication.

#### Multi-Robot Arm Control

When using two or more robotic arms, there are two possible scenarios: 
1. Multiple robotic arms connected to the same computer  
2. The computer and robotic arms connected to the same router  

To control these two or more robotic arms individually, there are two methods:

##### 1. When multiple robotic arms are connected to the same computer, multiple network adapters (NICs) will appear on the computer. You only need to bind each robotic arm to the corresponding NIC.

First, we need to know which NIC the robotic arm to be controlled is bound to. You can get the NIC information using the following command:

![](https://doc-cdn.unitree.com/static/2024/6/18/91975755829442a398e93e415acc2ddd_576x180.png)

In this example, the robotic arm is bound to the `eth0` NIC.  
Open the official sample program **"Arm Pose Zeroing"**, and in the first line of the main function you can see the initialization code for the robotic arm:

```c++
int main()
{
    ChannelFactory::Instance()->Init(0);
    ChannelPublisher<unitree_arm::msg::dds_::ArmString_> publisher(TOPIC);
    publisher.InitChannel();

    unitree_arm::msg::dds_::ArmString_ msg{};
    msg.data_() = "{\"seq\":4,\"address\":1,\"funcode\":7}";
    publisher.Write(msg);
 
    return 0;
}
```

In the initialization, simply add the NIC name you want to bind to in order to control the robotic arm connected to that NIC:

```c++
ChannelFactory::Instance()->Init(0, "eth0");
```

##### 2. When the computer and robotic arms are connected to the same router, the computer has only one NIC connected to all the robotic arms. In this case, you need to modify the internal driver files of the robotic arms.

First, you need to know that all control commands of the robotic arm are transmitted via DDS. By subscribing to the required topic in the program, you can get the desired messages.  
Since all robotic arms use the same topic for control commands, to control different robotic arms within the same LAN, you just need to make each robotic arm’s control topic unique. Start by connecting only one robotic arm.

When modifying the robotic arm driver code, first stop the default running services:

```shell
sudo systemctl stop marm_controller.service
sudo systemctl stop marm_control.service
sudo systemctl stop marm_communication.service
sudo systemctl stop marm_subscripber.service

sudo systemctl disable marm_controller.service
sudo systemctl disable marm_control.service
sudo systemctl disable marm_communication.service
sudo systemctl disable marm_subscripber.service
```

After connecting to the robotic arm via SSH, enter the following command:

```bash
vim marm_code/src/marm_communication_node.cpp
```

You will see the internal driver code:

```c++
#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/common/time/time_tool.hpp>

#include "msg/ArmString_.hpp"
#include "msg/PubServoInfo_.hpp"
#include "msg/SetServoAngle_.hpp"
#include "msg/SetServoDumping_.hpp"

#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

#include <iostream>
#include <thread>
#include <chrono>

#define SubArmCommand_Topic "rt/arm_Command"
#define SubServoCurrentAngle_Topic "current_servo_angle"
#define PubArmFeedback_Topic "rt/arm_Feedback"
#define PubArmZero_Topic "arm_zero"
#define PubServoAngle_Topic "set_servo_angle"
#define PubServoAngleControl_Topic "set_servo_angle_control"
#define PubServoDumping_Topic "set_servo_dumping"
```

Find the topic that matches the control command in the **"Arm Pose Zeroing"** sample program: 

```c++
#define SubArmCommand_Topic "rt/arm_Command"
```

Change it to a unique topic, for example: 

```c++
#define SubArmCommand_Topic "rt/arm_Command_1"
```

After finishing, save and exit, wait for recompilation to complete, then restart the services and the robotic arm:

```bash
cd
cd marm_code/build/
make clean
make

sudo systemctl enable marm_communication.service 
sudo systemctl enable marm_control.service 
sudo systemctl enable marm_controller.service 
sudo systemctl enable marm_subscripber.service 

sudo reboot

sudo systemctl start marm_communication.service 
sudo systemctl start marm_control.service 
sudo systemctl start marm_controller.service 
sudo systemctl start marm_subscripber.service 
```

Once this operation succeeds, append a special suffix to all topics in the `marm_code/src` driver files inside the robotic arm, so that each arm has unique topics within the LAN. For example:

`/marm_code/src/marm_communication_node.cpp`
```c++
#define SubArmCommand_Topic "rt/arm_Command_1"
#define SubServoCurrentAngle_Topic "current_servo_angle_1"
#define PubArmFeedback_Topic "rt/arm_Feedback_1"
#define PubArmZero_Topic "arm_zero_1"
#define PubServoAngle_Topic "set_servo_angle_1"
#define PubServoAngleControl_Topic "set_servo_angle_control_1"
#define PubServoDumping_Topic "set_servo_dumping_1"
```

`/marm_code/src/marm_control_node.cpp`
```c++
#define PubServoAngle_Topic "set_servo_angle_1"
#define PubArmFeedback_Topic "rt/arm_Feedback_1"
#define SubArmZero_Topic "arm_zero_1"
#define SubServoAngleControl_Topic "set_servo_angle_control_1"
#define SubServoCurrentAngle_Topic "current_servo_angle_1"
```

`/marm_code/src/marm_controller_node.cpp`
```c++
#define PubArmFeedback_Topic "rt/arm_Feedback_1"
#define PubServoAngle_Topic "current_servo_angle_1"
#define SubServoAngle_Topic "set_servo_angle_1"
#define SubServoDumping_Topic "set_servo_dumping_1"
```

!!! tip Possible compilation issues and solutions:  
1. **Compilation failure**: Delete the entire `build` folder and recompile.  
2. **Errors caused by incorrect file time**, such as:  
   ```
   make: Warning: File 'Makefile' has modification time xxx s in the future
   Warning: File 'xxx' has modification time yyy s in the future
   warning: Clock skew detected. Your build may be incomplete.
   ```
   Fix by setting the system clock to the current time, for example:  
   ```bash
   sudo date -s yyyy-mm-dd
   ```
 !!!

At this point, change the control command topic in the “Arm Pose Zeroing” sample program to match the unique topic. This way, you can control the specific robotic arm. The same principle applies if you want to get the angle data of a specific robotic arm. For example: 

```c++
#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>
#include "msg/ArmString_.hpp"

#define TOPIC "rt/arm_Command_1"

using namespace unitree::robot;
using namespace unitree::common;

int main()
{
    ChannelFactory::Instance()->Init(0);
    ChannelPublisher<unitree_arm::msg::dds_::ArmString_> publisher(TOPIC);
    publisher.InitChannel();

    unitree_arm::msg::dds_::ArmString_ msg{};
    msg.data_() = "{\"seq\":4,\"address\":1,\"funcode\":7}";
    publisher.Write(msg);
 
    return 0;
}
```

This completes the process of controlling a specific robotic arm.

#### Start the robotic arm program

A robot arm without a hand-held device is called an execution robot arm, and a robot arm with a hand-held device is called an acquisition robot arm.

To execute the robot arm, use the default program. To collect the robot arm, we need to stop the default program, use our acquisition interface program, and use the following command to stop the currently running service.

```shell
sudo systemctl stop marm_controller.service
sudo systemctl stop marm_control.service
sudo systemctl stop marm_communication.service
sudo systemctl stop marm_subscripber.service
```

This command will stop the factory program in the current system, if you need to stop permanently, continue to execute the following command.

```
sudo systemctl disable marm_controller.service
sudo systemctl disable marm_control.service
sudo systemctl disable marm_communication.service
sudo systemctl disable marm_subscripber.service

```

You can view the current status of the service by 'sudo systemctl statis service name'.

# Effect demonstration

Here is a demonstration of our company's teleoperation of the robotic arm. The source code is not currently available; please implement it yourself if needed.

<video src="https://doc-cdn.unitree.com/static/2024/2/27/302c624fb2d64ca7a0d042cce6571e7c.mp4" autoplay loop="loop" style="width: 100%" controls></video>

--- 

# ROS2 Services Interface

# Introduction
Unitree SDK2 implements an easy-to-use robot communication mechanism based on Cyclonedds, which enable developers to achieve robot communication and control (**Supports Unitree Go2, B2, and H1**). See: [https://github.com/unitreerobotics/unitree_sdk2](https://github.com/unitreerobotics/unitree_sdk2)

DDS is alos used in ROS2 as a communication mechanism. Therefore, the underlying layers of Unitree Go2, B2, and H1 robots can be compatible with ROS2. ROS2 msg can be direct used for communication and control of Unitree robot without wrapping the SDK interface.

# Configuration
## System requirements
Tested systems and ROS2 distro
|systems|ROS2 distro|
|--|--|
|Ubuntu 20.04|foxy|
|Ubuntu 22.04|humble|

Taking ROS2 foxy as an example, if you need another version of ROS2, replace "foxy" with the current ROS2 version name in the corresponding place.

!!!note
There may be differences in the APIs of different versions of ROS2, such as rosbag. The examples in the repository are developed under ROS2 Foxy. If using other ROS2 distributions, please refer to the official documentation for adjustments.
!!!

The installation of ROS2 foxy can refer to: [https://docs.ros.org/en/foxy/Installation/Ubuntu-Install-Debians.html](https://docs.ros.org/en/foxy/Installation/Ubuntu-Install-Debians.html)

ctrl+alt+T open the terminal, clone the repository: [https://github.com/unitreerobotics/unitree_ros2](https://github.com/unitreerobotics/unitree_ros2)

```bash
git clone https://github.com/unitreerobotics/unitree_ros2
```
where:
- **cyclonedds_ws**: The workspace of Unitree ros2 package. The msg for Unitree robot are supplied in the subfolder cyclonedds_ws/unitree/unitree_go and cyclonedds_ ws/unitree/unitree_api.
- **Go2_ROS2_example**: The workspace of some examples.

## Install Unitree ROS2 package

### 1. Dependencies
```bash
sudo apt install ros-foxy-rmw-cyclonedds-cpp
sudo apt install ros-foxy-rosidl-generator-dds-idl
```
For the convenience of using the interface, it is recommended to install unitree_sdk2 [https://github.com/unitreerobotics/unitree_sdk2](https://github.com/unitreerobotics/unitree_sdk2)

### 2. Compile cyclone dds
The cyclonedds version of Unitree robot is 0.10.2. To communicate with Unitree robots using ROS2, it is necessary to change the dds implementation. See：https://docs.ros.org/en/foxy/Concepts/About-Different-Middleware-Vendors.html

Before compiling cyclonedds, please ensure that ros2 environment has **NOT** been sourced when starting the terminal. Otherwise, it may cause errors in compilation.

If "source/opt/ros/foxy/setup. bash" has been added to the ~/.bashrc file when installing ROS2, it needs to be commented out:

```bash
sudo apt install gedit
sudo gedit ~/.bashrc
``` 
```bash
# source /opt/ros/foxy/setup.bash 
```

Compile cyclone-dds
```bash
cd ~/unitree_ros2/cyclonedds_ws/src
git clone https://github.com/ros2/rmw_cyclonedds -b foxy
git clone https://github.com/eclipse-cyclonedds/cyclonedds -b releases/0.10.x 
cd ..
colcon build --packages-select cyclonedds #Compile cyclone-dds package
```

### 3. Compile unitree_go and unitree_api packages
After compiling cyclone-dds, ROS2 dependencies is required for compilation of the unitree_go and unitree_api packages. Therefore, before compiling, it is necessary to source the environment of ROS2.
```bash
source /opt/ros/foxy/setup.bash # source ROS2 environment
colcon build # Compile all packages in the workspace
```

## Connect to Unitree robot

### 1. Network configuration
Connect Unitree robot and the computer using Ethernet cable. Then, use ifconfig to view the network interface that the robot connected. For example, "enp3s0" in the following figure.
![image](https://doc-cdn.unitree.com/static/2023/9/6/0f51cb9b12f94f0cb75070d05118c00a_980x816.jpg)

Next, open the network settings, find the network interface that the robot connected.In IPv4 setting, change the IPv4 mode to manual, set the address to 192.168.123.99, and set the mask to 255.255.255.0. After completion, click apply and wait for the network to reconnect.
![image](https://doc-cdn.unitree.com/static/2023/8/9/809e422d82334e5d82160cafc694c96a_1450x830.png)

Open setup.sh file.
```bash
sudo gedit ~/unitree_ros2/setup.sh
```
```bash
#!/bin/bash
echo "Setup unitree ros2 environment"
source /opt/ros/foxy/setup.bash
source $HOME/unitree_ros2/cyclonedds_ws/install/setup.bash
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
export CYCLONEDDS_URI='<CycloneDDS><Domain><General><Interfaces>
                            <NetworkInterface name="enp3s0" priority="default" multicast="default" />
                        </Interfaces></General></Domain></CycloneDDS>'
```
where "enp3s0" is the network interface name of unitree robot connected.
Modify it to the corresponding network interface according to the actual situation. 

Source the environment to setup the ROS2 support of Unitree robot: 
```bash
source ~/unitree_ros2/setup.sh
```
If you don't want to source the bash script every time when a new terminal opens, you can write the content of bash script into ~/.bashrc, but attention should be paid when there are multiple ROS environments coexisting in the system.

If your computer is not connected to the robot but you still want to use Unitree ROS2 for simulation and other functions, you can use the local loopback "lo" as the network interface.
```bash
source ~/unitree_ros2/setup_local.sh # use "lo" as the network interface
```
or
```bash
source ~/unitree_ros2/setup_default.sh # No network network interface specified 
```

### 2. Connect and test
After completing the above configuration, it is recommended to restart the computer before conducting the test.

Ensure that the network of robot is connected correctly, open a terminal and input:  
```bash
source ~/unitree_ros2/setup.sh
ros2 topic list
```
You can see the following topics:
![image](https://doc-cdn.unitree.com/static/2023/8/9/8ba3181e1f1446d784e8e40b21968db3_610x640.png)

Input ros2 topic echo /sportmodestate，you can see the data of the topic as shown in the following figure：
![image](https://doc-cdn.unitree.com/static/2023/8/9/5c3e505ff5724c14a4002d27caf41e4d_462x951.png)

### 3. Examples
Open a terminal and input:
```bash
source ~/unitree_ros2/setup.sh
cd ~unitree_ros2/example
colcon build
```
After compilation, run in the terminal:
```bash
./install/unitree_ros2_example/bin/read_motion_state 
```
You can see the robot status information output from the terminal:

```bash
[INFO] [1697525196.266174885] [motion_state_suber]: Position -- x: 0.567083; y: 0.213920; z: 0.052338; body height: 0.320000
[INFO] [1697525196.266230044] [motion_state_suber]: Velocity -- vx: -0.008966; vy: -0.001431; vz: -0.019455; yaw: -0.002131
[INFO] [1697525196.266282725] [motion_state_suber]: Foot position and velcity relative to body -- num: 0; x: 0.204149; y: -0.145194; z: -0.067804, vx: 0.002683; vy: 0.003745; vz: -0.010052
[INFO] [1697525196.266339057] [motion_state_suber]: Foot position and velcity relative to body -- num: 1; x: 0.204200; y: 0.145049; z: -0.068205, vx: -0.001954; vy: -0.003442; vz: -0.004828
[INFO] [1697525196.266392028] [motion_state_suber]: Foot position and velcity relative to body -- num: 2; x: -0.183385; y: -0.159294; z: -0.039468, vx: -0.000739; vy: -0.002028; vz: -0.004532
[INFO] [1697525196.266442766] [motion_state_suber]: Foot position and velcity relative to body -- num: 3; x: -0.182412; y: 0.159754; z: -0.039045, vx: -0.002803; vy: -0.001381; vz: -0.004794
[INFO] [1697525196.316189064] [motion_state_suber]: Gait state -- gait type: 1; raise height: 0.090000
```

# Usage
## State acquisition
### 1. Sportmode state
Sportmode state includes position, velcity, foot position, and other motion states of the robot. The acquisition of sportmode state can be achieved by subscribing "lf/sportmodestate" or "sportmodestate" topic, where "lf" represents low frequency. The msg of sportmodestate is defined as：

```C++
TimeSpec stamp // Time stamp
uint32 error_code //Error code
IMUState imu_state //IMU state
uint8 mode //Sport mode
/*
Sport mode
0. idle, default stand
1. balanceStand
2. pose
3. locomotion
4. reserve
5. lieDown
6. jointLock
7. damping
8. recoveryStand
9. reserve
10. sit
11. frontFlip
12. frontJump
13. frontPounc
*/
float32 progress //Is the dance action being executed?：0. dance false; 1. dance true
uint8 gait_type //Gait type
/*
Gait type
0.idle  
1.trot  
2.run  
3.climb stair  
4.forwardDownStair   
9.adjust
*/
float32 foot_raise_height 
float32[3] position 
float32 body_height
float32[3] velocity 
float32 yaw_speed
float32[4] range_obstacle
int16[4] foot_force 
float32[12] foot_position_body //foot positions in body frame
float32[12] foot_speed_body //foot velcities in body frame
```
For details, see：[https://support.unitree.com/home/en/developer/sports_services](https://support.unitree.com/home/en/developer/sports_services)

Complete examples is in /example/src/read_motion_state.cpp. Run in the terminal:
```bash
./install/unitree_ros2_example/bin/read_motion_state 
```

### 2. Low-level state
The low-level state includes motors states, power information, and other low level states.  Low-level states can be obtained by subscribing "lf/lowstate" or "lowstate" topic. The lowstate msg is defined as:

```C++
uint8[2] head
uint8 level_flag
uint8 frame_reserve
uint32[2] sn
uint32[2] version
uint16 bandwidth
IMUState imu_state //IMU
MotorState[20] motor_state //Motor state
BmsState bms_state
int16[4] foot_force 
int16[4] foot_force_est
uint32 tick
uint8[40] wireless_remote
uint8 bit_flag
float32 adc_reel
int8 temperature_ntc1
int8 temperature_ntc2
float32 power_v 
float32 power_a 
uint16[4] fan_frequency 
uint32 reserve
uint32 crc
```
where MotorState are defined as：
```C++
uint8 mode        // Mode, 0x01 for control
float32 q         // Joint angle
float32 dq        // Joint velocity
float32 ddq       // Joint acceleration
float32 tau_est   // Estimated torque
float32 q_raw     //raw data of q
float32 dq_raw    //raw data of dq
float32 ddq_raw   //raw data of dq
int8 temperature 
uint32 lost
uint32[2] reserve
```
For details, see: [https://support.unitree.com/home/en/developer/Basic_services](https://support.unitree.com/home/en/developer/Basic_services)
Complete examples is in example/src/read_low_state.cpp. 

### 3. Wireless controller

Wireless controller state can be obtained by subscribing "/wirelesscontroller" topic. The  wirelesscontroller msg is defiened as:

```C++
float32 lx // left joystick x, range [-1.0~1.0]
float32 ly // left joystick y, range [-1.0~1.0]
float32 rx // right joystick x, range [-1.0~1.0]
float32 ry // right joystick y, range [-1.0~1.0]
uint16 keys // key values
```
For details, see: [https://support.unitree.com/home/en/developer/Get_remote_control_status](https://support.unitree.com/home/en/developer/Get_remote_control_status)

Complete examples is in example/src/read_wireless_controller.cpp.

## Robot control
### 1. Sportmode 
Sportmode control is implemented by request/response mechanism. Sportmode control  can be achieved by sending unitree_api::msg::Request msg to the "/api/sport/request" topic.

The Request msg for different sportmode interfaces can be obtained by the SportClient (/example/src/common/ros2_sport_client.cpp) class. For example, control the robot to reach a desired attitude: 
```C++
 //Create a ros2 pubilsher 
rclcpp::Publisher<unitree_api::msg::Request>::SharedPtr req_puber = this->create_publisher<unitree_api::msg::Request>("/api/sport/request", 10);

SportClient sport_req; //Sportclient
unitree_api::msg::Request req; //Sportmode request msg
sport_req.Euler(req,roll,pitch,yaw); //Get Sportmode request msg from Sportclient 

req_puber->publish(req); // Publish request msg
```
For details about SportClient：[https://support.unitree.com/home/zh/developer/sports_services](https://support.unitree.com/home/zh/developer/sports_services)

Complete examples is in：example/src/sport_mode_ctrl.cpp. Run ./install/unitree_ros2_example/bin/sport_mode_ctrl in terminal. After 1 second of program startup, the robot will walk back and forth in the x direction.

### 2. Motor control
The torque, position and velocity control of motor can be implemented by subscribing "/lowcmd" topic and sending unitree_go::msg::LowCmd msg. LowCmd msg is defined as:
```C++
uint8[2] head
uint8 level_flag
uint8 frame_reserve
uint32[2] sn
uint32[2] version
uint16 bandwidth
MotorCmd[20] motor_cmd //motor command
BmsCmd bms_cmd
uint8[40] wireless_remote
uint8[12] led
uint8[2] fan
uint8 gpio
uint32 reserve
uint32 crc
```
where motor_cmd is defined as:
```C++
uint8 mode;  //Mode（Foc mode -> 0x01 ，stop mode -> 0x00)
float q;     //Target position (rad)
float dq;    //Target velocity (rad/s)
float tau;   //Target torque (N.M)
float kp;    
float kd;    
unsigned long reserve[3]; 
```
For details about low_cmd：[https://support.unitree.com/home/en/developer/Basic_services](https://support.unitree.com/home/en/developer/Basic_services)

Complete examples is in：example/src/low_level_ctrl.cpp. Run ./install/unitree_ros2_example/bin/low_level_ctrl in terminal. The hip motor and calf motor of the RL leg will rotate to the corresponding joint angle.

## Rviz
We can also use rviz to visualize Unitree robot data.The following is an example of visualizing robot lidar data:

Firstly, list all topics：
```bash
ros2 topic list
```
![image](https://z1.ax1x.com/2023/10/20/piFtteJ.png)

We can find the topic of lida：
```bash
utlidar/cloud
```
Then, echo frame_id of lidar：
```
ros2 topic echo --no-arr /utlidar/cloud
```
where frame_id: utlidar_lidar
![image](https://z1.ax1x.com/2023/10/20/piFtdF1.png)

Finally, run rviz：
```
ros2 run rviz2 rviz2
```
Add Pointcloud topic: utlidar/cloud in rviz2 and modify Fixed frame to utlidar_lidar. Then, the lidar data is displayed in rviz2. 

![image](https://z1.ax1x.com/2023/10/20/piFtsyD.png)
![image](https://z1.ax1x.com/2023/10/20/piFtyOe.png)

--- 

# Python Services Interface

# unitree_sdk2_python
unitree_sdk2 python interface

# Installation
## Dependencies
- python>=3.8
- cyclonedds==0.10.2
- numpy
- opencv-python

## Installing unitree_sdk2_python
Execute the following in the terminal:
```bash
cd ~
sudo apt install python3-pip
git clone [https://github.com/unitreerobotics/unitree_sdk2_python.git](https://github.com/unitreerobotics/unitree_sdk2_python.git)
cd unitree_sdk2_python
pip3 install -e .
````

## FAQ

##### 1\. Error when running `pip3 install -e .`

```bash
Could not locate cyclonedds. Try to set CYCLONEDDS_HOME or CMAKE_PREFIX_PATH
```

This error indicates that the cyclonedds path cannot be found. First, compile and install cyclonedds:

```bash
cd ~
git clone [https://github.com/eclipse-cyclonedds/cyclonedds](https://github.com/eclipse-cyclonedds/cyclonedds) -b releases/0.10.x 
cd cyclonedds && mkdir build install && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=../install -DBUILD_DDSPERF=OFF
cmake --build . --target install
```

Navigate to the `unitree_sdk2_python` directory, set `CYCLONEDDS_HOME` to the path where you just compiled cyclonedds, and then install `unitree_sdk2_python`:

```bash
cd ~/unitree_sdk2_python
export CYCLONEDDS_HOME="/{path to your cyclonedds}/cyclonedds/install"
pip3 install -e .
```

For details, see:
[https://pypi.org/project/cyclonedds/\#installing-with-pre-built-binaries](https://pypi.org/project/cyclonedds/#installing-with-pre-built-binaries)

# Usage

The python sdk2 interface remains consistent with the unitree\_sdk2 interface, achieving robot status acquisition and control through request-response or publish-subscribe topics. Corresponding examples are located in the `/example` directory. Before running the examples, you need to configure the robot's network connection according to the document [《Quick Start》](https://support.unitree.com/home/zh/developer/Quick_start).

## DDS Communication

Execute the following in the terminal:

```bash
python3 ./example/helloworld/publisher.py
```

Open a new terminal and execute:

```bash
python3 ./example/helloworld/subscriber.py
```

You should see the data information output in the terminal. The data transmitted by `publisher.py` and `subscriber.py` is defined in `user_data.py`. Users can define the data structures they need to transmit as required.

## High-Level State and Control

The data structures and control methods for the high-level interface are consistent with unitree\_sdk2. For details, see: [https://support.unitree.com/home/zh/developer/sports\_services](https://support.unitree.com/home/zh/developer/sports_services)

### High-Level Control

Execute the following in the terminal:

```bash
python3 ./example/go2/high_level/go2_sport_client.py [network_interface_name]
```

Where `[network_interface_name]` is the name of the network card connected to the robot. Please modify it according to the actual situation. Format examples: `enp2o`, `exp889dsxspod21`
This example provides several test methods; select one by inputting the sequence number to execute:

```python
TestOption(name="damp", id=0),        
TestOption(name="stand_up", id=1),    
TestOption(name="stand_down", id=2),  
TestOption(name="move forward", id=3),        
TestOption(name="move lateral", id=4),    
TestOption(name="move rotate", id=5),  
TestOption(name="stop_move", id=6),  
TestOption(name="switch_gait", id=7),    
TestOption(name="switch_gait", id=8),
TestOption(name="balanced stand", id=9),      
TestOption(name="recovery", id=10),
TestOption(name="recovery", id=10),      
TestOption(name="left flip", id=11),      
TestOption(name="back flip", id=12),
TestOption(name="free walk", id=13),  
TestOption(name="free bound", id=14),
TestOption(name="free avoid", id=15),  
TestOption(name="walk stair", id=16),
TestOption(name="walk upright", id=17),
TestOption(name="cross step", id=18),
TestOption(name="free jump", id=19)  
```

## Low-Level State and Control

The data structures and control methods for the low-level interface are consistent with unitree\_sdk2. For details, see: [https://support.unitree.com/home/zh/developer/Basic\_services](https://support.unitree.com/home/zh/developer/Basic_services)

### Low-Level Motor Control

First, use the app to turn off the high-level motion service (`sport_mode`), otherwise, it will cause command conflicts.
Execute the following in the terminal:

```bash
python3 ./example/go2/low_level/go2_stand_example.py [network_interface_name]
```

The rear-left thigh (hip) joint will be held at 0 degrees (for safety, $k_p=10$ and $k_d=1$ are set here), and the rear-left calf joint will continuously output $1 \text{ Nm}$ of torque.

## Wireless Controller Status Acquisition

Execute the following in the terminal:

```bash
python3 ./example/wireless_controller/wireless_controller.py [network_interface_name]
```

The terminal will output the status of each button. For the definition and data structure of the controller buttons, see: [https://support.unitree.com/home/zh/developer/Get\_remote\_control\_status](https://support.unitree.com/home/zh/developer/Get_remote_control_status)

## Front Camera

Use OpenCV to acquire the front camera (ensure the system has a graphical interface; press ESC to exit the program):

```bash
python3 ./example/go2/front_camera/camera_opencv.py [network_interface_name]
```

## Obstacle Avoidance Switch

```bash
python3 ./example/obstacles_avoid_switch/obstacles_avoid_switch.py [network_interface_name]
```

The robot will loop through enabling and disabling the obstacle avoidance function. For details on the obstacle avoidance service, see [https://support.unitree.com/home/zh/developer/ObstaclesAvoidClient](https://support.unitree.com/home/zh/developer/ObstaclesAvoidClient)

## Light and Volume Control

```bash
python3 ./example/vui_client/vui_client_example.py [network_interface_name]
```

The robot will cycle through adjusting the volume and light brightness. For details on this interface, see [https://support.unitree.com/home/zh/developer/VuiClient](https://support.unitree.com/home/zh/developer/VuiClient)

--- 

# DDS Communication

Routine path: `unitree_sdk2/example/helloworld/publisher.cpp` 
```C++
#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>                                  
#include "HelloWorldData.hpp"

#define TOPIC "TopicHelloWorld"

using namespace unitree::robot;
using namespace unitree::common;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
      std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
      exit(-1);
    }
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
    //argv [1]  is network interface of the robot

    /*
     * New ChannelPublisherPtr
     */
    ChannelPublisherPtr<HelloWorldData::Msg> publisher = ChannelPublisherPtr<HelloWorldData::Msg>(new ChannelPublisher<HelloWorldData::Msg>(TOPIC));

    /*
     * Init channel
     */
    publisher->InitChannel();

    while (true)
    {
        /*
         * Send message
         */
        HelloWorldData::Msg msg(unitree::common::GetCurrentTimeMillisecond(), "HelloWorld.");
        publisher->Write(msg);
        sleep(1);
    }   

    return 0;
}
```

Routine path: `unitree_sdk2/example/helloworld/subscriber.cpp`

```C++
#include <unitree/robot/channel/channel_subscriber.hpp>
#include "HelloWorldData.hpp"

#define TOPIC "TopicHelloWorld"

using namespace unitree::robot;
using namespace unitree::common;

void Handler(const void* msg)
{
    const HelloWorldData::Msg* pm = (const HelloWorldData::Msg*)msg;

    std::cout << "userID:" << pm->userID() << ", message:" << pm->message() << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
      std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
      exit(-1);
    }
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
    //argv [1]  is network interface of the robot
  
    /*
     * New ChannelSubscriberPtr
     */
    ChannelSubscriberPtr<HelloWorldData::Msg> subscriber = ChannelSubscriberPtr<HelloWorldData::Msg>(new ChannelSubscriber<HelloWorldData::Msg>(TOPIC));

    /*
     * Init channel
     */
    subscriber->InitChannel(std::bind(Handler, std::placeholders::_1), 1);

    sleep(5);
  
    /*
     * Close channel
     */
    subscriber->CloseChannel();

    std::cout << "reseted. sleep 3" << std::endl;

    sleep(3);

    /*
     * Init channel use last input parameter.
     */
    subscriber->InitChannel();

    /*
     * Loop wait message.
     */
    while (true)
    {
        sleep(10);
    }

    return 0;
}
```

Routine path: `unitree_sdk2/example/client/sport_client_example.cpp`

```C++
#include <unitree/robot/go2/sport/sport_client.hpp>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
      std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
      exit(-1);
    }
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
    //argv [1]  is network interface of the robot
  
    unitree::robot::go2::SportClient sc;

    /*
     * Set request timeout 1.0s
     */
    sc.SetTimeout(1.0f);
    sc.Init();

    //Test Api

    while (true)
    {
        int32_t ret = sc.Move(0.5, 0.0, 0.0);

        std::cout << "Call sc.Move ret:" << ret << std::endl;

        usleep(1000);
    }

    return 0;
}
```

--- 

# High Motion Control

This article introduces how to use the Go2 SDK to call the high-level control interface of Go2.

# High level control routine running test

The high-level routine files are located in `unitree_sdk2/example/go2/go2_sport_client.cpp`.

The beginning of the file lists test samples for various motion modes. The optional testing modes are divided into two parts: basic movements and special movements.

```c++
enum test_mode
{
  /*---Basic motion control---*/
  normal_stand,      // standing normally
  balance_stand,     // balanced standing
  velocity_move,     // speed control
  trajectory_follow, // trajectory tracking control
  stand_down,        // Get down
  stand_up,          // Get down
  damp,              // damping mode, soft emergency stop
  recovery_stand,    // restore standing
  /*---Special motion ---*/
  sit,           // sit down
  rise_sit,      // recover from sitting state
  stretch,       // stretch
  wallow,        // roll
  content,       // Happy
  pose,          // pose
  scrape,        // Bowing to the New Year
  front_flip,    // front flip
  front_jump,    // Jump before 16
  front_pounce,  // pounce forward
  stop_move = 99 // Stop moving
};
```

**Basic movements include:**

|<div style="width: 215pt">Basic Sports Mode</div> | Description|
| :--- | :--- |
|   normal\_stand  |  Normal standing, joint locking, standing high  |
|   balance\_stand  |  Balanced standing, while maintaining balance in body posture |
|   velocity\_move  |  Move at the specified speed, at the given x, y, and aw speeds, with the reference coordinate system being the body coordinate system  |
|   trajectory\_follow  | Track the given trajectory, track the given reference trajectory, and the reference coordinate system is the absolute coordinate system (with the starting position of the program as the origin)  |
|   stand\_down  |  Lie down, joint locked |
|   stand\_up  |  Stand tall, joint locked |
|   damp  |  Damping mode, all motors enter damping mode with the highest priority, equivalent to a soft emergency stop  |
|   recovery\_stand  |  Restore standing, restore standing from a overturned or prone state  |
|   stop\_move  | Stop all movements  |

**Special actions include:**

|Special Action | Description|
| :--- | :--- |
|   sit  |  Sit down  |
|   rise\_sit  |  Restore from sitting state to previous state |
|   stretch  |  Stretch  |
|   wallow  |  roll  |
|   content  |  Happy  |
|   pose  |  Pose  |
|   scrape  |  Bow to the New Year  |
|   front\_flip  |   Front flip  |
|   front\_jump  |  Jump forward |
|   front\_pounce  |   pounce forward  |

Modify variable TEST\_MODE, you can select the example you want to run. For example, a demo for testing speed control:

```c++
const int TEST_MODE = velocity_move;
```

After compiling the routine, use the remote control to put Go2 into motion mode, **ensure that the field is sufficiently open**, run the program in the terminal, wait for 1 second, and Go2 will start executing the corresponding action. Press ctrl+c to terminate the program.

```c++
~$ ./sportmode_test [network card name]
```

# Analysis of high-level control routines

## Main program

In the Custom class:

* The constructor Custom() calls sdk to complete the initialization of the sports client.

* RobotControl() calls the interface of SDK to implement various motion instances of Go2, and its code is explained in the high-level control instance.

* HighStateHandler() is a callback function for the high-level state, storing the obtained high-level state into the state variable.

* GetInitState() is used to obtain the initial state of the robot. Considering that the current position of the robot may not be near the origin of the odometer when running the program, for the sake of safety and intuition during the testing process, the testing routine will use the position and yaw angle of the program startup as the origin. Therefore, it is necessary to obtain the current position and yaw angle of the robot before the program starts.

```c++
Custom()
{
  // initialization sportclient
  sport_client.SetTimeout(10.0f); // Request timeout
  sport_client.Init(); // initialization

  //Subscribe to high-level status topics to obtain robot status
  suber.reset(new unitree::robot::ChannelSubscriber<unitree_go::msg::dds_::SportModeState_>(TOPIC_HIGHSTATE));
  suber->InitChannel(std::bind(&Custom::HighStateHandler, this, std::placeholders::_1), 1);
};

// Callback function for high-level data reception
void HighStateHandler(const void *message)
{
  state = *(unitree_go::msg::dds_::SportModeState_ *)message;
  std::cout << "Position: " << state.position()[0] << ", " << state.position()[1] << ", " << state.position()[2] << std::endl;
  std::cout << "IMU rpy: " << state.imu_state().rpy()[0] << ", " << state.imu_state().rpy()[1] << ", " << state.imu_state().rpy()[2] << std::endl;
};

//Example of high-level control
void RobotControl(){...};

//Obtain initial state
void GetInitState()
{
  px0 = state.position()[0];
  py0 = state.position()[1];
  yaw0 = state.imu_state().rpy()[2];
  std::cout << "initial position: x0: " << px0 << ", y0: " << py0 << ", yaw0: " << yaw0 << std::endl;
};
```

In the main program, the robot will wait for 1 second to obtain a stable initial state before starting high-level control testing.

```c++
int main(int argc, char **argv)
{
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }

  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
  Custom custom;

  sleep(1); // Wait for 1 second to obtain a stable state

  custom.GetInitState(); // Get initial position
  unitree::common::ThreadPtr threadPtr = unitree::common::CreateRecurrentThread(custom.dt * 1000000, std::bind(&Custom::RobotControl, &custom));

  while (1)
  {
    sleep(10);
  }
  return 0;
}
```

## Example of high-level control

A branch statement was used in the test code to select the test instances that need to be run. The code in each case is explained as follows:

### case Normal standing:
```c++
case normal_stand:                           
  sport_client.SwitchGait(0); //idle gait
  sport_client.StandUp(); // Standing with locked joints
  break;
```
### Case Balanced Standing:

* The range of Euler angles is: roll \[-0.75, 0.75\]; pitch\[-0.75, 0.75\]; yaw\[-0.6, 0.6\]

* The height of the fuselage is relative to the default state (0.33m), with a range of\[-0.18, 0.03\]

```c++
case balance_stand:                                 
  sport_client.Euler(0.1, 0.2, 0.3); // The input parameters are roll, pitch, and yaw angles, respectively
  sport_client.BodyHeight(0.0);      // The relative height of the fuselage, 0 corresponds to 0.33m
  sport_client.BalanceStand();       // balanced standing
Break;
  break;
```

### Case Speed Tracking:
```c++
case velocity_move:                                  
  sport_client.Move(0.3, 0, 0.3);     // The input parameters are vx, vy, and vyaw
  break;
```

### case tracks the given trajectory:

Tracking a circular trajectory, the variable path contains 30 future expected path points as a reference for the trajectory tracking process.

 ```c++
case trajectory_follow: // 4. path mode walking
  time_seg = 0.2; //Time step of reference trajectory
  time_temp = ct - time_seg; //Current moment

  for (int i = 0; i < 30; i++)
  {
    time_temp += time_seg;
  
    //Calculate the path point of a circular trajectory based on the position of the program at runtime
    px_local = 0.5 * sin(0.5 * time_temp);
    py_local = 0.5 * cos(0.5 * time_temp)-1;
    yaw_local = 0;
    vx_local = 0.25 * cos(0.5 * time_temp);
    vy_local = -0.25 * sin(0.5 * time_temp);
    vyaw_local = 0;
  
    //Convert to Path Points in Absolute Coordinate System
    path_point_tmp.timeFromStart = i * time_seg;
    path_point_tmp.x = px_local * cos(yaw0) - py_local * sin(yaw0) + px0;
    path_point_tmp.y = px_local * sin(yaw0) + py_local * cos(yaw0) + py0;
    path_point_tmp.yaw = yaw_local + yaw0;
    path_point_tmp.vx = vx_local * cos(yaw0) - vy_local * sin(yaw0);
    path_point_tmp.vy = vx_local * sin(yaw0) + vy_local * cos(yaw0);
    path_point_tmp.vyaw = vyaw_local;
    path.push_back(path_point_tmp);
  }
  sport_client.TrajectoryFollow(path);
  break;
```

### case Get down:

```C++
case stand_down: 
  sport_client.StandDown();
  break;
```

### case Station height:

```C++
case stand_up: 
  sport_client.StandUp();
  break;
```

### case damping mode, soft emergency stop:

```C++
case damp: 
  sport_client.Damp();
  break;
```

### case Restore Standing:

```C++
case recovery_stand: 
  sport_client.RecoveryStand();
  break;
```

### case Sit down:

Special actions can only be run once in a short period of time, so flag bits are used to determine whether the action is executed (the same below)
```C++
case sit:
  if (flag == 0) // Running flag
  {
    sport_client.Sit();
    flag = 1;
  }
  break;
```

### case Restore from sitting state to previous state:

 ```C++
case rise_sit:
  if (flag == 0)
  {
    sport_client.RiseSit();
    flag = 1;
  }
  break;
```

### case Stretch:

 ```C++
case stretch:
  if (flag == 0)
  {
    sport_client.Stretch();
    flag = 1;
  }
  break;
```

### case Roll:

 ```C++
case wallow:
  if (flag == 0)
  {
    sport_client.Wallow();
    flag = 1;
  }
  break;
```

### case Happy:

 ```C++
case content:
  if (flag == 0)
  {
    sport_client.Content();
    flag = 1;
  }
  break;
```

### case Pose:

 ```C++
case pose:
  if (flag == 0)
  {
    sport_client.Pose(true);
    flag = 1;
  }
  break;
```

### case Bowing to the New Year:

```C++
case scrape:
  if (flag == 0)
  {
    sport_client.Scrape();
    flag = 1;
  }
  break;
```

### case Front flip:

```C++
case front_flip:
  if (flag == 0)
  {
    sport_client.FrontFlip();
    flag = 1;
  }
  break;
```

### case Forward jump:

 ```C++
case front_jump:
  if (flag == 0)
  {
    sport_client.FrontJump();
    flag = 1;
  }
  break;
```

### case Forward thrust:

 ```C++
case front_pounce:
  if (flag == 0)
  {
    sport_client.FrontPounce();
    flag = 1;
  }
  break;
```

### case Stop movement:

```C++
case stop_move: // stop move
  sport_client.StopMove();
  break;
```

## High level status

The method to obtain the motion states of high-level buildings is as follows:

```c++
TimeSpec stamp(); 
uint32_t errorCode(); // error code
IMU imuState(); // IMU status
uint8_t mode(); // Sports mode
/*
Sports mode
0. idle, default stand
1. balanceStand
2. pose
3. locomotion
4. reserve
5. lieDown
6. jointLock
7. damping
8. recoveryStand
9. reserve
10. sit
11. frontFlip
12. frontJump
13. frontPounc
*/

float progress(); // Action execution status: 0. dance false; 1. dance true
uint8_t gaitType(); // Gait type
/*
Gait type
0.idle  
1.trot  
2.run  
3.climb stair  
4.forwardDownStair   
9.adjust
*/

float footRaiseHeight(); // Leg lift height
std::array<float, 3> position(); // 3D position
float bodyHeight(); // Body height
std::array<float, 3> velocity(); // Three-dimensional velocity
float yawSpeed(); // Yaw speed
std::array<float, 4> rangeObstacle(); // Obstacle distance
std::array<int16_t, 4> footForce(); // Four foot force
std::array<float, 12> footPositionBody(); // The position of the foot end relative to the body
std::array<float, 12> footSpeedBody(); // The speed of the foot relative to the body
std::array<PathPoint, 10>  pathPoints(); // The current tracked path point
```

For example:

```c
// Robot position
std::cout<<"position: "<<custom.state.position()[0]<<", "<<custom.state.position()[1]<<", "<<custom.state.position()[2]<<std::endl;

// Euler angle
std::cout<<"IMU rpy: "<<custom.state.imu_state().rpy()[0]<<", "<<custom.state.imu_state().rpy()[1]<<", "<<custom.state.imu_state().rpy()[2]<<std::endl;
```

--- 

# Basic Motion Control

This article introduces how to use **unitree_sdk2** calls the underlying interface to develop the Go2 robot, and the relevant code file is `go2_low_level.cpp` under the`unitree_sdk2/example/go2` path. In this routine, we will demonstrate how to call the underlying interface to control the right front leg swing of a quadruped robot. The method to run this routine can be found in the "[Quick Start](https://support.unitree.com/home/en/developer/Quick_start) This article will not go into detail here.

## Program Analysis

### Custom Class

In the `Custom` class, classes and functions related to DDS communication are defined, as well as some variables related to controlling leg swing.

#### Member variables

##### Variables related to leg control

|<div style="width: 80pt">Name</div> | <div style="width: 90pt">Type</div> | Description|
| :---: | :---: | :--- |
|  qInit  |  float type array  |  Used in this example to record the initial joint angles of each joint in the right front leg |
|  qDes  |  float type array  | In this example, it is used to express the expected joint angle of each joint in the right front leg  |
|  sin_mid_q  |  float type array  |  In this example, it is used to specify the intermediate joint angle in the cyclic reciprocating motion of each joint in the right front leg  |
|  Kp  |  float type array  |  In this example, it is used to specify the joint space control kp value of each joint in the right front leg  |
|  Kd  |  float type array  |  In this example, it is used to specify the joint space control Kd value of each joint in the right front leg |

##### Communication related variables

|<div style="width: 130pt">Name </div>|<div style="width: 130pt"> Type</div> | Description| 
| :---: | :--- | :--- |
|  lowcmd\_publisher  |  ChannelPublisherPtr<unitree\_go::msg::dds\_::LowCmd\_>  |  The underlying command sends the object, and calling the Write function of the object will send the underlying control command once to the Go2 robot  |
|  lowstate\_subscriber  |  ChannelSubscriberPtr<unitree\_go::msg::dds\_::LowState\_>  |  Subscribing objects to low-level status information, including motor information, IMU data, Unitree handle information, etc  |
|  lowCmdWriteThreadPtr  |  ThreadPtr  |  DDS related underlying command sending thread pointer |
|  cmd  |  unitree\_go::msg::dds\_::LowCmd\_  | The underlying command structure related to DDS is ultimately sent to the Go2 robot through DDS, which is different from LowCmd low\_cmd |
|  state  |  unitree\_go::msg::dds\_::LowState\_  |  DDS related underlying state structures  |
|  low\_cmd  |  UNITREE\_LEGGED\_SDK::LowCmd   |  UNITREE\_LEGGED\_SDKtype structure for underlying control commands  |
|  low\_state  |  UNITREE\_LEGGED\_SDK::low\_state   |  UNITREE\_LEGGED\_SDKStructure of SDK type regarding underlying state information  |

The variables related to communication can be mainly divided into two types: UNITREE\_LEGGED\_SDK Types and unitree\_go::msg::dds\_ The types and their relationships are shown in the following figure:
<center>

![](https://doc-cdn.unitree.com/static/2023/10/18/c6773a5a637a483ba15534118138c2d7_308x677.png)

</center>

In this routine, the user logic for controlling leg swing is first used with `UNITREE_LEGGED_SDK` type variable is expressed, and then converted to DDS related types through functions provided in some routines before sending commands to the Go2 robot. This is because SDK for robots such as A1 and Go1 also use `UNITREE_LEGGED_SDK` type, this is for the convenience of previous users to continue and migrate.

#### Member function

 **InitLowCmd()**

```C++
    void Custom::InitLowCmd()
    {
        low_cmd.head[0] = 0xFE; 
        low_cmd.head[1] = 0xEF;
        low_cmd.levelFlag = 0xFF;
        low_cmd.gpio = 0;
    
        for(int i=0; i<20; i++){
            low_cmd.motorCmd[i].mode = (0x01);   // motor switch to servo (PMSM) mode
            low_cmd.motorCmd[i].q = (PosStopF);
            low_cmd.motorCmd[i].Kp = (0);
            low_cmd.motorCmd[i].dq = (VelStopF);
            low_cmd.motorCmd[i].Kd = (0);
            low_cmd.motorCmd[i].tau = (0);
        }
    }
```

    
    

`InitLowCmd()` This function is used to initialize and set the `LowCmd` of type `low_cmd` structure. This function can be placed in the constructor of the `Custom` class and run once. Here are some key points:

1. The head member in the `LowCmd` type represents the frame header, which will be used for CRC verification Set the `head`, `levelFlag`, `gpio`, etc. to the default values as shown in the routine.

   
2. There are 20 members of `motorCmd` in the `LowCmd` type, each with a command to control a corresponding motor on the Go2 robot. However, there are only 12 motors on the Go2 robot, so only the first 12 are valid, and the remaining 8 are reserved.
    
3. `low_cmd.motorCmd[i].mode = (0x01)` ; This command sets the `mode` variable of the `motorCmd` member to 0x01, where 0x01 indicates that the motor is set to servo mode. If the user finds that they cannot control the joint motor of the Go2 robot during debugging, please check if the value of the variable is 0x01.

**LowStateMessageHandler**

The function is a DDS callback function for receiving low-level state information, and the DDS mechanism will trigger this callback function at a certain frequency. Each time the callback function is triggered, the underlying state information will be updated once.

 **LowCmdwriteHandler**()

The purpose of this function is to send a callback function for the underlying control command, which DDS will trigger at a certain frequency. The first part of the code for this callback function represents the user logic for calculating the right front calf swing control command, while the second part sends the control command to the Go2 robot.

```C++
    void LowCmdwriteHandler()
{
     motiontime++;
    
        for(int i=0; i<12; i++){
          printf("%f ", state.motor_state()[i].q());
        }
        printf("\n");
    
        // if( motiontime >= 100){
        if (motiontime >= 0){
            // first, get record initial position
            if (motiontime >= 0 && motiontime < 20){
                qInit[0] = state.motor_state()[FR_0].q();
                qInit[1] = state.motor_state()[FR_1].q();
                qInit[2] = state.motor_state()[FR_2].q();
            }
            // second, move to the origin point of a sine movement with Kp Kd
            if (motiontime >= 10 && motiontime < 400) {
                rate_count++;
                double rate = rate_count / 200.0; // needs count to 200
                Kp[0] = 5.0; Kp[1] = 5.0; Kp[2] = 5.0;
                Kd[0] = 1.0; Kd[1] = 1.0; Kd[2] = 1.0;
    
                qDes[0] = jointLinearInterpolation(qInit[0], sin_mid_q[0], rate);
                qDes[1] = jointLinearInterpolation(qInit[1], sin_mid_q[1], rate);
                qDes[2] = jointLinearInterpolation(qInit[2], sin_mid_q[2], rate);
            }
            double sin_joint1, sin_joint2;
            // last, do sine wave
            float freq_Hz = 1;
            // float freq_Hz = 5;
            float freq_rad = freq_Hz * 2 * M_PI;
            float t = dt * sin_count;
            if (motiontime >= 400){
                sin_count++;
                sin_joint1 = 0.6 * sin(t * freq_rad);
                sin_joint2 = -0.9 * sin(t * freq_rad);
                qDes[0] = sin_mid_q[0];
                qDes[1] = sin_mid_q[1] + sin_joint1;
                qDes[2] = sin_mid_q[2] + sin_joint2;
            }
    
            low_cmd.motorCmd[FR_2].q = qDes[2];
            low_cmd.motorCmd[FR_2].dq = 0;
            low_cmd.motorCmd[FR_2].Kp = Kp[2];
            low_cmd.motorCmd[FR_2].Kd = Kd[2];
            low_cmd.motorCmd[FR_2].tau = 0;
        }
        low_cmd.crc = crc32_core((uint32_t *)&low_cmd, (sizeof(LowCmd)>>2)-1);
    
        lowCmd2Dds(low_cmd, cmd);
        lowcmd_publisher->Write(cmd);
 }
```
The three if statements in the above code block can divide the user logic into three parts:
1. if (motiontime >= 0 && motiontime < 20) -> Record the initial joint angle
2.  if (motiontime >= 10 && motiontime < 400) -> Move to the starting angle of reciprocating motion
3.   if (motiontime >= 400) -> Start reciprocating motion

The following will explain:

1. Record the initial joint angle

```C++
  
  if (motiontime >= 0 && motiontime < 20)
{
  qInit[0] = state.motor_state()[FR_0].q();
  qInit[1] = state.motor_state()[FR_1].q();
  qInit[2] = state.motor_state()[FR_2].q();
}
  
```
This code indicates that when the `motiontime` is less than 20, the joint angle values of the body joint (FR_0), thigh joint (FR_1), and calf joint (FR_2) of the right front leg (FR) will be read and assigned to the elements in the `qInit` array. It can be summarized that the purpose of this code is to record the initial position of the right front leg, as shown in the following figure

![](https://doc-cdn.unitree.com/static/2023/10/18/339568d549984c76b299ec2dd318598e_1004x763.png)

2. Starting angle from motion to reciprocating motion

```C++
  
  if (motiontime >= 10 && motiontime < 400) {
    rate_count++;
    double rate = rate_count / 200.0; // needs count to 200
    Kp[0] = 5.0; Kp[1] = 5.0; Kp[2] = 5.0;
    Kd[0] = 1.0; Kd[1] = 1.0; Kd[2] = 1.0;
    
    qDes[0] = jointLinearInterpolation(qInit[0], sin_mid_q[0], rate);
    qDes[1] = jointLinearInterpolation(qInit[1], sin_mid_q[1], rate);
    qDes[2] = jointLinearInterpolation(qInit[2], sin_mid_q[2], rate);
  }
}
```
  
The purpose of this code segment is to calculate the control command `qDes`, which will drive the right front leg joints to slowly move from the angle specified in the `qDes` array to the joint angle specified in the `sim_mid_q`array, as shown in the following figure

![](https://doc-cdn.unitree.com/static/2023/9/26/6c7a23c310e441559dbd38b89b8c2612_1388x1080.gif)

3. Start reciprocating motion

```C++
  
double sin_joint1, sin_joint2;
// last, do sine wave
float freq_Hz = 1;
// float freq_Hz = 5;
float freq_rad = freq_Hz * 2 * M_PI;
float t = dt * sin_count;
if (motiontime >= 400)
{
  sin_count++;
  sin_joint1 = 0.6 * sin(t * freq_rad);
  sin_joint2 = -0.9 * sin(t * freq_rad);
  qDes[0] = sin_mid_q[0];
  qDes[1] = sin_mid_q[1] + sin_joint1;
  qDes[2] = sin_mid_q[2] + sin_joint2;
}
    
low_cmd.motorCmd[FR_2].q = qDes[2];
low_cmd.motorCmd[FR_2].dq = 0;
low_cmd.motorCmd[FR_2].Kp = Kp[2];
low_cmd.motorCmd[FR_2].Kd = Kd[2];
low_cmd.motorCmd[FR_2].tau = 0;
  
```
The purpose of this code is to calculate the control command `qDes`, which will drive the calf joint in the right front leg to swing around the joint angle specified in the `sim_mid_q` array. As shown in the figure below, the right front calf will swing within the sin_mid_q[2] ± 0.9 rad range, as shown in the figure below

![](https://doc-cdn.unitree.com/static/2023/9/26/e4b7693bb5134493a0a202af30e11d54_1388x1080.gif)

```C++
  
  low_cmd.crc = crc32_core((uint32_t *)&low_cmd, (sizeof(LowCmd)>>2)-1);
lowCmd2Dds(low_cmd, cmd);
lowcmd_publisher->Write(cmd);
  
```
The first line of this code first calculates the CRC checksum. The second line of code uses the `lowCmd2Dds()` function to convert `UNITREE_LEGGED_SDK::low_cmd` variable conversion to DDS  `unitree_go::msg::dds_::LowCmd`_ The `cmd` variable of type. The last line of code represents calling the `Write()` function of `lowcmd_publisher` to send control commands to the Go2 robot.

### DDS conversion function

The following is a series of DDS related conversion functions. When users express control logic, the main focus is on `UNITREE_LEGGED_SDK::LowCmd` and `UNITREE_LEGGED_SDK::LowState` These two types of variables are operated on because they have higher readability. When actually sending commands or obtaining status information to the Go2 robot, it is done through `unitree_go::msg::dds_::LowCmd_` and `unitree_go::msg::dds_::LowState_`  These two types of structures.

Therefore, it is necessary to convert these two types of structures through some conversion functions. Users can focus on the `lowCmd2Dds()` and `dds2LowState()` conversion functions. For intermediate functions, there is no need to overly focus on implementation details. When using them, simply copy and paste them.

|Name | Description|
| --- | --- |
|  void dds2Imu(unitree\_go::msg::dds\_::IMUState\_& dds, IMU& raw)  |  On the Conversion Function of IMU State Information，convert unitree\_go::msg::dds\_::IMUState\_ to UNITREE\_LEGGED\_SDK::IMUis an intermediate function.  |
|  void dds2BmsState(unitree\_go::msg::dds\_::BmsState\_& dds, BmsState& raw)  | Regarding the conversion function of IMU status information, convert unitree\_go::msg::dds\_::IMUState\_ Convert to UNITREE\_LEGGED\_SDK::IMU, which is an intermediate function.
  |
|  void dds2MotorState(std::array<unitree\_go::msg::dds\_::MotorState\_, 20>& dds, MotorState\* raw)  |  Regarding the conversion function of motor state information, unitree\_go::msg::dds\_::MotorState\_ Convert to UNITREE\_LEGGED\_SDK::MotorState, which is an intermediate function.
  |
|  void dds2LowState(unitree\_go::msg::dds\_::LowState\_& dds, LowState& raw)  |  Convert UNITREE\_LEGGED\_SDK::LowState to unitree\_go::msg::dds\_::LowState\_  |
|  void motorCmd2Dds(MotorCmd\* raw, std::array<unitree\_go::msg::dds\_::MotorCmd\_, 20>& dds)  |  Regarding the conversion function of motor control commands,convert UNITREE\_LEGGED\_SDK::MotorCmd to unitree\_go::msg::dds\_::MotorState\_is an intermediate function.  |
|  void bmsCmd2Dds(BmsCmd& raw, unitree\_go::msg::dds\_::BmsCmd\_& dds)  |  Regarding the conversion function of battery management commands, convert UNITREE\_LEGGED\_SDK::BmsCmd to unitree\_go::msg::dds\_::BmsCmd\_ is an intermediate function.  |
|  void lowCmd2Dds(LowCmd& raw, unitree\_go::msg::dds\_::LowCmd\_& dds)  |  convert UNITREE\_LEGGED\_SDK::LowCmd  to unitree\_go::msg::dds\_::LowCmd\_。  |
|  void crc32\_core(uint32\_t\* ptr, uint32\_t len)  | The crc verification function is an intermediate function. |

--- 

# Deployment Framework

When testing motion control algorithms, the robot needs to first stand up from the ground and then perform control; After the test is completed, the robot needs to return to the lying state; When an accident occurs during testing, the robot needs to exit the testing algorithm in a timely manner and slowly fall down.

In order to meet these requirements, developers need to develop a debugging framework in addition to developing motion control algorithms to achieve the above functions. This article will combine routines under `example/state_machine` to introduce how to design a debugging framework.

# Pre knowledge

Before reading this tutorial, please have a brief understanding of the following content:

*   Motor control（[bottom service interface](https://support.unitree.com/home/en/developer/Basic_services)、[Bottom Motion Control - Leg Swing](https://support.unitree.com/home/en/developer/Basic_motion_control)）
    
*   Remote control status acquisition（[Remote control status acquisition routine](https://support.unitree.com/home/en/developer/Get_remote_control_status)）
    
*   json parsing (`example/jsonize`)
    

# State switching

## Damping state

In a damped state, the motor has no driving force when stationary and is subjected to a driving force opposite to the direction of rotation during rotation, simulating the resistance during the rotation process. The pseudo code for motor control is as follows:
```
motorCmd.q = 0
motorCmd.dq = 0
motorCmd.Kp = 0
motorCmd.Kd = 2.0
motorCmd.tau = 0
```
In this mode, all motors of the robot will slowly stop. This mode can be used for the initial state of robot startup, and can also allow the robot to smoothly collapse in case of problems. Generally, the `L2 + B` combination key of the remote control is defined as the key to enter damping mode, and the robot can enter damping mode from any state.

## Standing state

This is the interface between the damping state and the control state. In this state, users can control the robot to stand and lie down through the remote control. A robot in a damping state can stand up through this state and enter the control state, giving the control mode a reasonable initial state for the robot. The standing of this routine is achieved by adjusting the `kp/kd` parameter, and the pseudo code is as follows:

```
motorCmd.q = q_stand
motorCmd.dq = 0
motorCmd.Kp = kp * pd_ratio
motorCmd.Kd = kd * pd_ratio
motorCmd.tau = 0
```
This routine adjusts the `pd_ratio` through the `R1/R2` button on the remote control to achieve the robot`s standing and lying down.

## Control status

The control algorithm that needs to be tested for control state operation. When the robot is in a standing state and the `pd_ratio` exceeds a certain threshold, it can enter the control state, but other conditions cannot enter the control state.

## Switching logic

The switching logic in the routine is shown in the following figure. When the robot starts, it lies on the ground and is in a damping state. Press the remote control `R2` to enter the standing state, and press and hold `R2` to make the robot stand up. After the robot stabilizes, press the remote control `A` to enter control mode and conduct testing. After the test is completed, you can press the remote control `R2` to return to standing mode. If there are any problems during the test, you can press the remote control `L2+B` or enter the damping state through the program judgment.

<certer>

![](https://doc-cdn.unitree.com/static/2023/10/18/6793be72ddc7469988ddfcb500ec18c1_3134x1698.png)

</center>

# Program implementation

Below is a brief introduction to the main code implementation. Please refer to the source code for specific details.

## Overall framework

The debugging program has a total of three sub threads, which are used to receive data, run the controller, and send data. The main class is `RobotController<USER_CTRL>`, which is used to store data, operate on 3 sub threads, and has built-in open loop control for damping and standing states `USER_CTRL` is the control algorithm `RobotInterface` encapsulates the underlying state and instructions `Gamepad` is an advanced packaging for remote controls `SimpleStateMachine` is a state machine.

## Underlying state class: RobotInterface

`RobotInterface` vectorizes and encapsulates the underlying state and instructions. Its parent class is `BasicRobotInterface`, and its member variables include the robot's motor status, IMU information, and motor instructions. The member function `GetState()` is used to parse the underlying state messages of dds, `SetCommand()` is used to generate dds messages corresponding to motor commands, and `UpdateProjectedGravity()` is a kinematic calculation tool used to calculate the projection of the unit vector of gravity direction under body coordinates.

 

``` c++
  class BasicRobotInterface
  {
  public:
      BasicRobotInterface();

      void GetState(unitree_go::msg::dds_::LowState_ &state);

      virtual void SetCommand(unitree_go::msg::dds_::LowCmd_ &cmd) = 0;

      // motor states
      std::array<float, 12> jpos, jvel, tau;
      // IMU
      std::array<float, 4> quat;
      std::array<float, 3> rpy, gyro, projected_gravity;
      // motor commands
      std::array<float, 12> jpos_des, jvel_des, kp, kd, tau_ff;

  private:
      inline void UpdateProjectedGravity();
  };
```
`RobotInterface`is a subclass ofb `BasicRobotInterface`, which contains the specific implementation of `SetCommand()`.

```c++
class RobotInterface : public BasicRobotInterface
{
public:
    RobotInterface() : BasicRobotInterface();

    void SetCommand(unitree_go::msg::dds_::LowCmd_ &cmd);

private:
    void InitLowCmd();

    UNITREE_LEGGED_SDK::LowCmd low_cmd_raw;
};
```

During use, the thread receiving the underlying state calls the `GetState()` function to record the robot state in this object; The control algorithm thread reads the robot state from member variables, calculates motor instructions, and stores them back into this object by accessing them; The thread that sends the underlying instruction calls the `SetCommand()` function to write the instruction to the underlying control message that needs to be sent.

## Motion control class:ExampleUserController

`ExampleUserController` is the motion controller that needs to be tested, and its parent class is `BasicUserController`. 

```c++
class BasicUserController
{
public:
    BasicUserController();

    virtual void LoadParam(fs::path &param_folder) = 0;

    virtual void Reset(RobotInterface &robot_interface, Gamepad &gamepad) = 0;

    virtual void GetInput(RobotInterface &robot_interface, Gamepad &gamepad) = 0;

    virtual void Calculate() = 0;

    virtual std::vector<float> GetLog() = 0;

    float dt, kp, kd;
    std::array<float, 12> init_pos;
    std::array<float, 12> jpos_des;
};
```
The member variable `dt` stores the time step, `kp` stores the joint gain, and `kd` stores the joint damping `init_pos` stores the initial position of the joint, `jpos_des` Stores the joint target position. The member function `LoadParam()` is used to load the configuration file, `Reset()` is used to reset the controller, `GetInput()` is used to read the robot status and remote control information, and `Calculate()` runs the main control logic to calculate the control quantity and store it in the member variable `GetLog()` is used to generate logs. The above member functions are all virtual functions, and when testing different control algorithms, they are implemented by inheriting `BasicUserController`.

In the control algorithm thread, when switching to the control state, the main program runs the control algorithm by calling the member function of the class and accessing the member variable to obtain the control quantity.

`ExampleUserController` is an example of an actual controller that includes a simple implementation of the above virtual function, which can be used as a reference **In actual debugging, different subclasses are mainly written to achieve the control algorithms that need to be tested**

## State machine class: SimpleStateMachine

`SimpleStateMachine` is a simple state machine that can switch between standing, damping, and controlling states.

```c++
enum class STATES
{
  DAMPING = 0,
  STAND = 1,
  CTRL = 2
};

class SimpleStateMachine
{
public:
  SimpleStateMachine(double pd_ratio_init = 0.1, double delta_pd = 0.005) : state(STATES::STAND), pd_ratio(pd_ratio_init), delta_pd(delta_pd) {}

  bool Stop()
  {
      state = STATES::DAMPING;
      pd_ratio = 0.0;
      return true;
  }

  bool Stand()
  {
      if (state == STATES::DAMPING || state == STATES::CTRL)
      {
          state = STATES::STAND;
          return true;
      }
      else
      {
          return false;
      }
  }

  bool Ctrl()
  {
      if (state == STATES::STAND && pd_ratio > 0.95)
      {
          state = STATES::CTRL;
          return true;
      }
      else
      {
          return false;
      }
  }

  void Standing(bool up = true)
  {
      if (state == STATES::STAND)
      {
          if (up)
          {
              pd_ratio += delta_pd;
          }
          else
          {
              pd_ratio -= delta_pd;
          }
          pd_ratio = std::max(0.0, std::min(1.0, pd_ratio));
      }
  }

  STATES state;
  double pd_ratio;
  double delta_pd;
};
```

`STATES` is an enumeration class that defines three states: damping, standing, and control `SimpleStateMachine` contains the object `state` of the enumeration class and parameters used to control standing and lying down `pd_ratio` and `delta_pd`. `Stop()`, `Stand()` and `Ctrl()` are used to enter three states, respectively. If the entry is successful, it returns`true`, otherwise it returns`false`.

The `Standing()` function is used to adjust the `kp` and `kd` parameters while standing, achieving control over standing and lying down.

n the main program, the control thread first determines and executes state switching based on the state of the remote control, and then calls different functions based on the state of the state machine to execute different control logic.

## Robot control class: RobotController

`RobotController<USER_CTRL>` is the core class used to control program execution. This is a template class, `<USER_CTRL>` can be a subclass of the motion control class `BasicUserController`. In the main function, different motion control algorithms can be debugged by setting different motion control classes.

```c++
template <typename USER_CTRL>
class RobotController
{
public:
    RobotController() {};

    RobotController(fs::path &log_file_name);

    void InitDdsModel(const std::string &networkInterface = "");

    void LoadParam(fs::path &param_folder);

    void StartControl();

protected:
    ChannelPublisherPtr<unitree_go::msg::dds_::LowCmd_> lowcmd_publisher;
    ChannelSubscriberPtr<unitree_go::msg::dds_::LowState_> lowstate_subscriber;
    ThreadPtr low_cmd_write_thread_ptr, control_thread_ptr;
    unitree_go::msg::dds_::LowCmd_ cmd;
    unitree_go::msg::dds_::LowState_ state;

    Gamepad gamepad;
    REMOTE_DATA_RX rx;

    SimpleStateMachine state_machine;
    USER_CTRL ctrl;
    RobotInterface robot_interface;

    std::mutex state_mutex, cmd_mutex;

    std::ofstream log_file;

    uint64_t ctrl_dt_micro_sec = 2000;

    std::vector<float> compute_time;

private:
    void LowStateMessageHandler(const void *message);

    void InteprateGamePad();

    void LowCmdwriteHandler();

    void StartSendCmd();
    
    void UpdateStateMachine();
    
    void ControlStep();

    void WriteLog();

    void StandCallback();

    void CtrlCallback();

    void Damping(float kd = 2.0);

    void Standing(float kp = 40.0, float kd = 1.0);

    void UserControlStep(bool send = true);

    bool CheckTermination();
};
```

In addition to the constructor, the public member functions also include `InitDdsModel()`, `LoadParam()`, and `StartControl()`.

### Main function

The main logic of the main function is as follows: first, construct the object and set the log path, then load the controller configuration file through `LoadParam()`, connect the robot through `InitDdsModel()`, and finally start control through `StartControl()`.

```c++
int main(int argc, char const *argv[])
{
    // parse command line params
    std::string param_folder;

    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];

        if (arg == "--param" && i + 1 < argc)
        {
            param_folder = argv[i + 1];
        }
    }
    fs::path param = fs::current_path() / param_folder;

    // set log file
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time), "%Y_%m_%d_%H_%M_%S");

    fs::path log_folder = fs::current_path() / "logs" / ss.str();
    fs::create_directories(log_folder);

    std::ofstream cfg_file(log_folder / "cfg.txt");
    cfg_file << "param_folder: " << param << std::endl;
    cfg_file.close();

    fs::path log_file_name = log_folder / "log.txt";
  
    // start control
    RobotController<ExampleUserController> robot_controller(log_file_name);
  
    robot_controller.LoadParam(param);

    robot_controller.InitDdsModel();

    robot_controller.StartControl();

    return 0;
}
```
The main program first sets the configuration file path through command line parameters; Create a log file based on the current time.

### Load Configuration File

The `LoadParam()` function simply called `USER_CTRL.LoadParam()` function is used to load the configuration file.

```c++
void LoadParam(fs::path &param_folder)
{
    ctrl.LoadParam(param_folder);
}
```

### Establishing a connection

The content of `InitDdsModel()` is similar to the previous low-level control routine, used to establish a connection with the robot and set binding and callback functions.
```c++
void InitDdsModel(const std::string &networkInterface = "")
{
    // init dds
    ChannelFactory::Instance()->Init(0, networkInterface);
    lowcmd_publisher.reset(new ChannelPublisher<unitree_go::msg::dds_::LowCmd_>(TOPIC_LOWCMD));
    lowstate_subscriber.reset(new ChannelSubscriber<unitree_go::msg::dds_::LowState_>(TOPIC_LOWSTATE));

    lowcmd_publisher->InitChannel();
    lowstate_subscriber->InitChannel(std::bind(&RobotController::LowStateMessageHandler, this, std::placeholders::_1), 1);
}
```
In this example program, the callback function `LowStateMessageHandler()` that receives the message first stores the message object in the member variable `state` as a backup, and then updates the underlying state interface `robot_interface`.

```c++
void LowStateMessageHandler(const void *message)
{
    state = *(unitree_go::msg::dds_::LowState_ *)message;
    {
        std::lock_guard<std::mutex> lock(state_mutex);
        robot_interface.GetState(state);
    }
}
```

### Turn on control

`StartControl()` is the core function for enabling control, with the main content as follows.

```c++
void StartControl()
{
    // waiting for gamepad command to start the control thread
    std::chrono::milliseconds duration(100);
    // listen to gamepad command
    while (true)
    {
        std::cout << "Press R2 to start!" << std::endl;
        std::this_thread::sleep_for(duration);

        InteprateGamePad();
        if (gamepad.R2.on_press)
        {
            break;
        }
    }

    // prepare for start
    // ...
}
```
After entering this function, the thread enters a dead loop to detect the status of the remote control. When the user presses` R2`, it jumps out of the loop for control.
```c++
void StartControl()
{
    // waiting for gamepad command to start the control thread
    // ...

    // prepare for start
    std::cout << "Start!" << std::endl;
    Damping();
    ctrl_dt_micro_sec = static_cast<uint64_t>(ctrl.dt * 1000000);

    // Start the control thread
    control_thread_ptr = CreateRecurrentThreadEx("ctrl", UT_CPU_ID_NONE, ctrl_dt_micro_sec, &RobotController::ControlStep, this);

    // Start the lowlevel command thread
    std::this_thread::sleep_for(duration);
    StartSendCmd();

    // keep the main thread alive
    while (true)
    {
        std::this_thread::sleep_for(duration);
    }
}
```

After jumping out of the loop, the program starts the **motion control thread** and calls the `ControlStep()` function in a loop; After waiting for a short time, call the `StartSendCmd()` function to start **the underlying instruction thread**.

### Motion Control Thread

The motion control thread periodically executes the `ControlStep()` function, executing the actual control logic based on instructions. Each step of control consists of the following steps:

1. Update remote control status and state machine

2. Control based on status

3. Update dds underlying control messages

4. Record logs and collect performance information

    
```c++
void ControlStep()
{
    // main loop

    // update state
    InteprateGamePad();
    UpdateStateMachine();

    // select control modes according to the state machine
    auto start = std::chrono::high_resolution_clock::now();
    if (state_machine.state == STATES::STAND)
    {
        Standing();
    }
    if (state_machine.state == STATES::DAMPING)
    {
        Damping();
    }
    if (state_machine.state == STATES::CTRL)
    {
        UserControlStep(true);
        if (CheckTermination())
        {
            state_machine.Stop();
        }
    }

    // update low-level command
    {
        std::lock_guard<std::mutex> lock(cmd_mutex);
        robot_interface.SetCommand(cmd);
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    compute_time.push_back(duration.count() / 1000.);

    // write log
    WriteLog();

    if (compute_time.size() == 100)
    {
        float sum = 0;
        for (auto &t : compute_time)
        {
            sum += t;
        }
        std::cout << "Performance: mean: " << sum / 100
                  << " ms; max: " << *std::max_element(compute_time.begin(), compute_time.end())
                  << " ms; min: " << *std::min_element(compute_time.begin(), compute_time.end())
                  << "ms." << std::endl;

        compute_time.clear();

        std::cout << "Current State: " << static_cast<size_t>(state_machine.state) << std::endl;
    }
}
```

#### State switching and callback

This routine uses a very simple state switching logic. When certain buttons are pressed, the program will call the member function in the `SimpleStateMachine` class for state switching. If successful, the corresponding callback function will be executed. The main implementation methods for state switching are as follows:

```c++
void UpdateStateMachine()
{
    // R2 -> Stand
    // A -> Ctrl
    // L2 + B -> Stop
    if (gamepad.R2.on_press)
    {
        if (state_machine.Stand())
        {
            StandCallback();
        }
    }
    if (gamepad.A.on_press)
    {
        if (state_machine.Ctrl())
        {
            CtrlCallback();
        }
    }
    if (gamepad.L2.pressed && gamepad.B.pressed)
    {
        state_machine.Stop();
    }
}
```

#### Damping state

When the state machine is in a damping state, the program calls the `Damping()` function for control, and the control logic is as follows:
```c++
void Damping(float kd = 2.0)
{
  robot_interface.jpos_des = ctrl.init_pos;
  robot_interface.jvel_des.fill(0.);
  robot_interface.kp.fill(0.);
  robot_interface.kd.fill(kd);
  robot_interface.tau_ff.fill(0.);
}
```

#### Control status

When the state machine is in control state, the program will first call `UserControlStep()` for control, then check the robot status. If protection is needed, it will automatically enter the damping state.

```c++
if (state_machine.state == STATES::CTRL)
{
    UserControlStep(true);
    if (CheckTermination())
    {
        state_machine.Stop();
    }
}
```
The `UserControlStep()` function calls the member function of the `ExampleUserController` class to run the controller that the user needs to test.

```c++
void UserControlStep(bool send = true)
{
    {
        std::lock_guard<std::mutex> lock(state_mutex);
        ctrl.GetInput(robot_interface, gamepad);
    }
    ctrl.Calculate();

    if (send)
    {
        robot_interface.jpos_des = ctrl.jpos_des;
    }
}
```
The `CheckTermination()` function in this routine checks whether the robot`s body tilt exceeds 90 degrees. If it exceeds 90 degrees, it triggers the protection to enter a damping state. During the development process, the protection rules can be adjusted according to the actual situation.

```c++
bool CheckTermination()
{
    if (robot_interface.projected_gravity.at(2) > 0)
    {
        return true;
    }
    return false;
}
```
#### Standing state

When the state machine is in a standing state, the program calls the `Standing()` function for control.

```c++
void Standing(float kp = 40.0, float kd = 1.0)
{
  if (gamepad.R2.pressed)
  {
      state_machine.Standing(true);
  }
  if (gamepad.R1.pressed)
  {
      state_machine.Standing(false);
  }

  UserControlStep(false);

  robot_interface.kp.fill(kp * state_machine.pd_ratio);
  robot_interface.kd.fill(kd * state_machine.pd_ratio);
}
```
The main control logic for standing status is to adjust the standing height based on the remote control buttons.

For debugging convenience, the standing mode of this routine will also run the user control logic as a test, which calculates the control amount based on the robot's state, but does not send instructions.

### Compile Run

After compiling the entire sdk routine, pass in parameters through --param when using it. The compile and run commands are as follows:

```bash
# build the sdk and all examples
mkdir build
cd build
cmake ..
make

# run
./state_machine_example --param ../example/state_machine/params
```
The above is an example of a debugging framework. If you need to directly use this framework, you can directly develop a new controller in `user_controller.hpp`.

--- 

# Light Control

This article will introduce how to use unitree_go2_sdk to control the LED emitting from the head of the GO2 robot dog

The SDK currently provides two methods for setting / obtaining **white** lights, and developers can customize the brightness of LEDs according to different scene requirements. Adjust the gear to between 0 and 10.
<center>
  

<img src="https://doc-cdn.unitree.com/static/2023/10/18/9c463ad1fe7540b1ba3855ed3514b4ba_5364x4986.png" width =500>
  
</center>

## Routine code

Path: `unitree_sdk2/example/go2/go2_vui_client.cpp`

The routine achieves the effect of controlling the light's off ->dark ->on ->off in a loop.

```C++
#include <unitree/robot/go2/vui/vui_client.hpp>

int main(int32_t argc, const char** argv)
{
    if (argc < 2)
    {
        std::cout << "Please fill in the correct network card name" << std::endl;
        exit(0);
    }
    /*
     * Initilaize ChannelFactory
     */
    std::string networkInterface = "eth0";
    networkInterface = argv[1];
    unitree::robot::ChannelFactory::Instance()->Init(0, networkInterface);
    unitree::robot::go2::VuiClient vc;

    /*
     * Set request timeout 1.0s
     */
    vc.SetTimeout(1.0f);
    vc.Init();

    //Test Api

    int level = 0, value = 0;
    int ret;

    while (true)
    {
        ret = vc.SetBrightness(level);
        std::cout << "SetBrightness  level=" << level << ", api return:" << ret << std::endl;
        ++level %= 11;
        sleep(1);
        ret = vc.GetBrightness(value);
        std::cout << "GetBrightness value=" << value << ", api return:" << ret << std::endl;
        sleep(1);
    }

    return 0;
}
```

## Introduction to relevant interfaces

|Function Name | SetBrightness|
|:-------- | :--------|
|**Function Prototype**| int32_t SetBrightness(int level); |
|**Parameter**| level: Brightness range 0-10|
|**Return Value**| If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
|**Remarks**| Set brightness|

|Function Name | GetBrightness|
|:-------- | :--------|
|**Function Prototype**| int32_t GetBrightness(int&);|
|**Parameter**| Integer reference parameter|
|**Return Value**| If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
|**Remarks**| Obtain the current brightness|

--- 

# Get Remote Control Status

# Introduction to Remote Control Data Interface

The buttons of each part of the remote control are explained as shown in the figure. The functions of a remote control mainly consist of left and right joystick and function buttons. Each joystick has two degrees of freedom and can output joystick values in the x and y directions, with a range of \[-1.0~1.0\]. The combination of function keys / function keys corresponds to a unique integer key value. Users can obtain the values of the joystick and the key values of the buttons by subscribing to the "rt/wirelesscontroller" message.

<centrt>

![](https://doc-cdn.unitree.com/static/2024/1/8/5a0057f38e464df3a1bdfb806edb1334_1600x819.png)

</centrt>

The source code of the program in the following sections can be found at [unitree_sdk2/example/wireless](https://github.com/unitreerobotics/unitree_sdk2/tree/main/example/wireless) and [unitree_sdk2/example/advanced_gamepad](https://github.com/unitreerobotics/unitree_sdk2/tree/main/example/advanced_gamepad), respectively.

# Remote control data

## Obtain remote control data

The method to obtain remote control data is as follows

```C++
unitree_go::msg::dds_::WirelessController_ joystick; // Remote control data dds

joystick.lx(); // Obtain data for left joystick x, range [-1.0~1.0]
joystick.ly(); // Obtain left joystick y data, range [-1.0~1.0]
joystick.rx(); // Obtain right joystick x data, range [-1.0~1.0]
joystick.ry(); // Obtain right joystick y data, range [-1.0~1.0]
joystick.keys(); // Obtain remote control key values
```

The correspondence between remote control key values and buttons is defined by the following consortium. Assign the obtained key value to the value variable in the union, and then determine whether the corresponding key has been pressed by determining whether the member variable in the components is 1.

```C++
typedef union
{
  struct
  {
    uint8_t R1 : 1;
    uint8_t L1 : 1;
    uint8_t start : 1;
    uint8_t select : 1;
    uint8_t R2 : 1;
    uint8_t L2 : 1;
    uint8_t F1 : 1;
    uint8_t F2 : 1;
    uint8_t A : 1;
    uint8_t B : 1;
    uint8_t X : 1;
    uint8_t Y : 1;
    uint8_t up : 1;
    uint8_t right : 1;
    uint8_t down : 1;
    uint8_t left : 1;
  } components;
  uint16_t value;
} xKeySwitchUnion;

```

For example:

 ```C++
xKeySwitchUnion key;
key.value = joystick.keys(); // Assign the obtained remote control key value to the value variable in the consortium

 // By determining the components A value in the consortium, it can be determined whether the A key has been pressed
if ((int)key.components.A == 1)
{
  std::cout << "The key A is pressed " << std::endl;
}
```

## Complete routine

*   In the main function, a joystick\_dds\_model dds model will be created and subscribed to messages from the "rt/wirelesscontroller" node    
*   When the value of the remote control changes, the program will enter the JoystickHandler() callback function and output the value of the remote control.
    

```C++
#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/idl/go2/WirelessController_.hpp>
#include <unitree/robot/client/client.hpp>

#define TOPIC_JOYSTICK "rt/wirelesscontroller"

using namespace unitree::common;

// Remote Control Key Value Consortium
typedef union
{
  struct
  {
    uint8_t R1 : 1;
    uint8_t L1 : 1;
    uint8_t start : 1;
    uint8_t select : 1;
    uint8_t R2 : 1;
    uint8_t L2 : 1;
    uint8_t F1 : 1;
    uint8_t F2 : 1;
    uint8_t A : 1;
    uint8_t B : 1;
    uint8_t X : 1;
    uint8_t Y : 1;
    uint8_t up : 1;
    uint8_t right : 1;
    uint8_t down : 1;
    uint8_t left : 1;
  } components;
  uint16_t value;
} xKeySwitchUnion;

// Callback function for obtaining motion status
void JoystickHandler(const void *message)
{
  unitree_go::msg::dds_::WirelessController_ joystick = *(unitree_go::msg::dds_::WirelessController_ *)message;
  
  // Remote control raw data
  std::cout << "lx: " << joystick.lx() << std::endl     // left joystick x
            << "ly: " << joystick.ly() << std::endl     // left joystick y
            << "rx: " << joystick.rx() << std::endl     // right joystick x
            << "ry: " << joystick.ry() << std::endl     // right joystick y
            << "keys: " << joystick.keys() << std::endl // key
            << "------" << std::endl;
  xKeySwitchUnion key;
  key.value = joystick.keys();

  // Determine whether a button has been pressed
  if ((int)key.components.A == 1)
  {
    std::cout << "The key A is pressed " << std::endl;
  }
}

int main(int argc, char **argv)
{
    // Initialize SDK interface
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }

  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);

  unitree::robot::ChannelSubscriberPtr<unitree_go::msg::dds_::WirelessController_> joystick_suber;
  joystick_suber.reset(new unitree::robot::ChannelSubscriber<unitree_go::msg::dds_::WirelessController_>(TOPIC_JOYSTICK));
  joystick_suber->InitChannel(JoystickHandler, 1);

  while (1)
  {
    usleep(20000);
  }
  return 0;
}

```
!!! note 
After running the program, there will only be output when the remote control joystick changes or a button is pressed.
!!!

# Remote Control Advanced Packaging

The above routine can only obtain the "pressed"/"released" states of the remote control button, and cannot reflect whether it is currently in the moment of pressing. The rocker data read is the original value, excluding dead zones, filtering, etc. If you want to solve the above problems, you can perform advanced encapsulation on the remote control data.The source code of the program can be found at `unitree_sdk2/example/wireless_controller`.

## Button class

Firstly, define a button state type as follows. Pressed indicates whether the button is currently in a pressed state, n\_press / on\_release indicates whether the button is currently exactly in the pressed or released state.

```C++
    class Button
    {
    public:
        Button() {}

        void update(bool state)
        {
            on_press = state ? state != pressed : false;
            on_release = state ? false : state != pressed;
            pressed = state;
        }

        bool pressed = false;
        bool on_press = false;
        bool on_release = false;
    };
```

## Advanced remote control class

Subsequently, define a new type of remote control and update the status of the remote control buttons and joystick based on the remote control status message.

   ```C++
 // full gamepad
    class Gamepad
    {
    public:
        Gamepad() {}

        void Update(unitree_go::msg::dds_::WirelessController_ &key_msg)
        {
            // update stick values with smooth and deadzone
            lx = lx * (1 - smooth) + (std::fabs(key_msg.lx()) < dead_zone ? 0.0 : key_msg.lx()) * smooth;
            rx = rx * (1 - smooth) + (std::fabs(key_msg.rx()) < dead_zone ? 0.0 : key_msg.rx()) * smooth;
            ry = ry * (1 - smooth) + (std::fabs(key_msg.ry()) < dead_zone ? 0.0 : key_msg.ry()) * smooth;
            ly = ly * (1 - smooth) + (std::fabs(key_msg.ly()) < dead_zone ? 0.0 : key_msg.ly()) * smooth;

            // update button states
            key.value = key_msg.keys();

            R1.update(key.components.R1);
            L1.update(key.components.L1);
            start.update(key.components.start);
            select.update(key.components.select);
            R2.update(key.components.R2);
            L2.update(key.components.L2);
            F1.update(key.components.F1);
            F2.update(key.components.F2);
            A.update(key.components.A);
            B.update(key.components.B);
            X.update(key.components.X);
            Y.update(key.components.Y);
            up.update(key.components.up);
            right.update(key.components.right);
            down.update(key.components.down);
            left.update(key.components.left);
        }

        float smooth = 0.03;
        float dead_zone = 0.01;

        float lx = 0.;
        float rx = 0.;
        float ry = 0.;
        float ly = 0.;

        Button R1;
        Button L1;
        Button start;
        Button select;
        Button R2;
        Button L2;
        Button F1;
        Button F2;
        Button A;
        Button B;
        Button X;
        Button Y;
        Button up;
        Button right;
        Button down;
        Button left;

    private:
        xKeySwitchUnion key;
    };

```

## Business logic implementation

In programming practice, two threads can be used, one thread listens to and stores remote control messages, and the other thread executes at a scheduled time to update remote control status and execute control logic. Taking the calculation of the number of times A key is pressed as an example, the callback functions for two threads are as follows:

    
 ```C++
class GamepadExample
{
public:
    // ...

    // Message listening callback
    void MessageHandler(const void *message)
    {
        std::lock_guard<std::mutex> lock(joystick_mutex);
        joystick_msg = *(unitree_go::msg::dds_::WirelessController_ *)message;
    }

    // Timing control callback
    void Step()
    {
        {
            std::lock_guard<std::mutex> lock(joystick_mutex);
            gamepad.Update(joystick_msg);
        }

        // some operations
        if (gamepad.A.on_press)
        {
            press_count += 1;
        }
    }

    // ...

protected:
    // ...
    unitree_go::msg::dds_::WirelessController_ joystick_msg;
    Gamepad gamepad;
    std::mutex joystick_mutex;
    int press_count = 0;
};
```

    

## Full code

Remote control and button type header files.

```C++
#pragma once

#include <stdint.h>
#include <cmath>
#include "unitree/idl/go2/WirelessController_.hpp"

namespace unitree::common
{
    // union for keys
    typedef union
    {
        struct
        {
            uint8_t R1 : 1;
            uint8_t L1 : 1;
            uint8_t start : 1;
            uint8_t select : 1;
            uint8_t R2 : 1;
            uint8_t L2 : 1;
            uint8_t F1 : 1;
            uint8_t F2 : 1;
            uint8_t A : 1;
            uint8_t B : 1;
            uint8_t X : 1;
            uint8_t Y : 1;
            uint8_t up : 1;
            uint8_t right : 1;
            uint8_t down : 1;
            uint8_t left : 1;
        } components;
        uint16_t value;
    } xKeySwitchUnion;

    // single button class
    class Button
    {
    public:
        Button() {}

        void update(bool state)
        {
            on_press = state ? state != pressed : false;
            on_release = state ? false : state != pressed;
            pressed = state;
        }

        bool pressed = false;
        bool on_press = false;
        bool on_release = false;
    };

    // full gamepad
    class Gamepad
    {
    public:
        Gamepad() {}

        void Update(unitree_go::msg::dds_::WirelessController_ &key_msg)
        {
            // update stick values with smooth and deadzone
            lx = lx * (1 - smooth) + (std::fabs(key_msg.lx()) < dead_zone ? 0.0 : key_msg.lx()) * smooth;
            rx = rx * (1 - smooth) + (std::fabs(key_msg.rx()) < dead_zone ? 0.0 : key_msg.rx()) * smooth;
            ry = ry * (1 - smooth) + (std::fabs(key_msg.ry()) < dead_zone ? 0.0 : key_msg.ry()) * smooth;
            ly = ly * (1 - smooth) + (std::fabs(key_msg.ly()) < dead_zone ? 0.0 : key_msg.ly()) * smooth;

            // update button states
            key.value = key_msg.keys();

            R1.update(key.components.R1);
            L1.update(key.components.L1);
            start.update(key.components.start);
            select.update(key.components.select);
            R2.update(key.components.R2);
            L2.update(key.components.L2);
            F1.update(key.components.F1);
            F2.update(key.components.F2);
            A.update(key.components.A);
            B.update(key.components.B);
            X.update(key.components.X);
            Y.update(key.components.Y);
            up.update(key.components.up);
            right.update(key.components.right);
            down.update(key.components.down);
            left.update(key.components.left);
        }

        float smooth = 0.03;
        float dead_zone = 0.01;

        float lx = 0.;
        float rx = 0.;
        float ry = 0.;
        float ly = 0.;

        Button R1;
        Button L1;
        Button start;
        Button select;
        Button R2;
        Button L2;
        Button F1;
        Button F2;
        Button A;
        Button B;
        Button X;
        Button Y;
        Button up;
        Button right;
        Button down;
        Button left;

    private:
        xKeySwitchUnion key;
    };
} // namespace unitree::common
```

A routine that calculates the number of times the A key is pressed.

 ```C++
#include <mutex>
#include "unitree/idl/go2/WirelessController_.hpp"
#include "unitree/robot/channel/channel_subscriber.hpp"

#include "gamepad_test.hpp"

#define TOPIC_JOYSTICK "rt/wirelesscontroller"

using namespace unitree::common;
using namespace unitree::robot;

class GamepadExample
{
public:
    GamepadExample() {}

    // setup dds model
    void InitDdsModel(const std::string &networkInterface = "")
    {
        ChannelFactory::Instance()->Init(0, networkInterface);
        joystick_subscriber.reset(new ChannelSubscriber<unitree_go::msg::dds_::WirelessController_>(TOPIC_JOYSTICK));

        joystick_subscriber->InitChannel(std::bind(&GamepadExample::MessageHandler, this, std::placeholders::_1), 1);
    }

    // set gamepad dead_zone parameter
    void SetGamepadDeadZone(float deadzone)
    {
        gamepad.dead_zone = deadzone;
    }

    // set gamepad smooth parameter
    void setGamepadSmooth(float smooth)
    {
        gamepad.smooth = smooth;
    }

    // callback function to save joystick message
    void MessageHandler(const void *message)
    {
        std::lock_guard<std::mutex> lock(joystick_mutex);
        joystick_msg = *(unitree_go::msg::dds_::WirelessController_ *)message;
    }

    // work thread
    void Step()
    {
        {
            std::lock_guard<std::mutex> lock(joystick_mutex);
            gamepad.Update(joystick_msg);
        }

        // some operations
        if (gamepad.A.on_press)
        {
            press_count += 1;
        }

        // print gamepad state
        std::cout << "lx: " << gamepad.lx << std::endl
                  << "A: pressed: " << gamepad.A.pressed
                  << "; on_press: " << gamepad.A.on_press
                  << "; on_release: " << gamepad.A.on_release
                  << std::endl << "press count: " << press_count
                  << std::endl << "===========================" << std::endl;
    }

    // start the work thread
    void Start()
    {
        control_thread_ptr = CreateRecurrentThreadEx("nn_ctrl", UT_CPU_ID_NONE, 40000, &GamepadExample::Step, this);
    }

protected:
    ChannelSubscriberPtr<unitree_go::msg::dds_::WirelessController_> joystick_subscriber;
    unitree_go::msg::dds_::WirelessController_ joystick_msg;

    Gamepad gamepad;

    ThreadPtr control_thread_ptr;

    std::mutex joystick_mutex;

    int press_count = 0;
};

int main()
{
    // create example object
    GamepadExample example;

    // set gamepad params
    example.setGamepadSmooth(0.2);
    example.SetGamepadDeadZone(0.5);

    // start program
    example.InitDdsModel();
    example.Start();

    while (1)
    {
        usleep(20000);
    }
    return 0;
}
```

--- 

# RL Control Routine

This document will provide a simple example of reinforcement learning control for Go2. The following will explain how to use **isaac_gym** simulation platform trains the Go2 control algorithm.

# Hardware preparation

Due to isaac_gym simulation platform requires `CUDA`, and this article suggests configuring NVIDIA graphics cards (graphics memory>8GB, RTX series graphics cards) for hardware and installing corresponding graphics card drivers. It is recommended that the system use `ubuntu18/20`, graphics card driver version 525.
<center>

![](https://doc-cdn.unitree.com/static/2023/9/11/3ab2cbb2083b489da41f7aecc6a8a299_715x448.png)

</center>

# Environmental configuration
   
   It is recommended to configure the virtual environment `conda`.
   1. Create a virtual environment
```bash
      conda create -n rl-go2 python=3.8
```

   2. Activate virtual environment
```bash
        conda activate rl-go2
```

   3. Install `CUDA`， `pytorch`
```bash
   pip3 install torch==1.10.0+cu113 torchvision==0.11.1+cu113 torchaudio==0.10.0+cu113 -f https://download.pytorch.org/whl/cu113/torch_stable.html
```
> Please note that the numpy library version should not be too high. It is recommended to install version 1.23.5.

4. Download [Isaac Gym Preview 4](https://developer.nvidia.com/isaac-gym) Simulate the platform, unzip it and enter the `python` directory to install using `pip`.

```bash
# current directory: isaacgym/python
pip install -e .
```

   Run the routine in the `Python/examples` directory to verify if the installation was successful.
```bash
# current directory: isaacgym/python/examples
python 1080_balls_of_solitude.py
```
If the installation is successful, you can see the following window.
  

  ![](https://doc-cdn.unitree.com/static/2023/9/11/3abb56841d1d49c5bf6cc11b43148bb6_1600x937.png)
 6. Install rsl_rl library (use v1.0.2)
 ```bash
git clone https://github.com/leggedrobotics/rsl_rl
cd rsl_rl
git checkout v1.0.2
pip install -e .
``` 

# Model training usage
   1. Download the official example code of Unitree
```bash
   git clone https://github.com/unitreerobotics/unitree_rl_gym.git
```
   2. Modify the `sys.path.append("/home/unitree/go2/legged_gym")` in `legged_gym/scripts/train.py`,  `legged_gym/scripts/play.py`  to its own path.
4. Activate reinforcement learning virtual environment

```bash
   conda activate rl-go2
```

   4. Execute training instructions and start training.
```bash
   python3  train.py --task=go2
```
Modify the `args.headless` parameter in the train.py file to turn on or off the visualization interface.

   isaac_gym appears on the following interface, then the training begins.
   ![](https://doc-cdn.unitree.com/static/2023/9/11/3c21ad393e5345d181ecb2d9896b5041_1848x1053.png)
   The terminal output window is as follows:
<center>
   
   ![](https://doc-cdn.unitree.com/static/2023/9/11/09da58438faf451cbb0c6a1ac62f0c75_838x527.png)
</center>
  
After 1500 training sessions, run the test instructions.
```c++
python play.py --task=go2
```
# Effect demonstration
<video src="https://doc-cdn.unitree.com/static/2023/9/12/37a70cf8c0d34f97b40ae35a4a26ecd1.mp4" autoplay loop="loop" style="width: 100%" controls></video>

--- 

# Exapmle of motor errors

This article introduces how to use unitree_sdk2 to read the motor error state.

#  Motor errors
Motor errors refer to the motor entering a protection state or experiencing a malfunction. Potential motor errors are as follows:
| Error type | Causes |
| - | - |
| Over current |The motor current exceeds the working range|
| Over voltage | Bus voltage exceeds 45V|
| Driver overheat | Temperature of the motor case or driver exceeds 90 ℃|
| Motor bus under voltage | Bus voltage below 11V |
|Winding overheat |Joint jamming or motor exceeding rated power for a long time resulting in winding temperature exceeding 140 ℃|
|Encoder abnormal|Motor encoder not available|

!!! note 
When the motor enters the protection state (overcurrent, overvoltage, etc.), please turn off the robot first, rest for a period of time, and then turn it back on to restore normal operation. If the problem persists after multiple restarts, please contact technical support.
!!!

 Users can get detial error information by analyzing the ``lost`` and ``reserve`` of [MotorState_.idl](https://support.unitree.com/home/zh/developer/Basic_services). The explanation of the variables is as follows:
|Variable|Describe|
|--|--|
|``lost``|Total lost packets in communication (Range：0-9999999999)|
|``reserve[0]``|Motor error code|
|``reserve[1]``|Current communication frequency (Range：0-800)|

where motor error code ``reserve[0]`` is an integer variable. Each bit of ``reserve[0]`` binary corresponds to an error state. The relationship between each bit and the corresponding error state is as follows (1 indicates error):

|bit|8|7|6|5|4|3|2|1|0|
|--|--|--|--|--|--|--|--|--|--|
|error_type|Communication interrupted|Reserved|Reserved|Encoder abnormal|Winding overheat|Motor bus under voltage|Driver overheat|Over voltage|Over current|

For example：For example, ``error_code = 6``, i. e. ``error_code = 0b000000110``, means Over voltage and Driver overheat.

# Example
In the example, ``GetDetailMotorErrors`` class is defined to parse the error code and report the corresponding error types.

```C++
class GetDetailMotorErrors
{
private:
    struct MotorErrorState
    {
        std::string error_type;
        short int state;
    };

    std::vector<MotorErrorState> motor_errors = {
        {error_type : "Over current", state : 0},
        {error_type : "Over voltage", state : 0},
        {error_type : "Driver overheat", state : 0},
        {error_type : "Motor bus under voltage", state : 0},
        {error_type : "Winding overheat", state : 0},
        {error_type : "Encoder abnormal", state : 0},
        {error_type : "Reserved, Not used", state : 0},
        {error_type : "Reserved, Not used", state : 0},
        {error_type : "Communication interrupted", state : 0},
    };

public:
    GetDetailMotorErrors(){};
    ~GetDetailMotorErrors(){};
    void ReportErrors(int error_code)
    {
        for (int i = 0; i < motor_errors.size(); i++)
        {   
            // Each bit of the error_code corresponds to a motor error type
            // For example, error_code = 6, i. e. error_code = 0b000000110, means Over voltage and Driver overheat.
            motor_errors[i].state = (error_code & (1 << i)) >> i; // Get every bit of error_code.
            if (motor_errors[i].state > 0)
            {
                std::cout << motor_errors[i].error_type << ", ";
            }
        }
        std::cout << std::endl;
    };
};
```
Then, use [low_level interface](https://support.unitree.com/home/zh/developer/Basic_services) to get the motor states, and use ``GetDetailMotorErrors:: ReportErrors()`` function to check motor errors.

```C++

std::array<::unitree_go::msg::dds_::MotorState_, 20> motor_state_{};
GetDetailMotorErrors motor_errors_;

for (int i = 0; i < 20; i++)
{   
    // Get motor state form low_state
    motor_state_[i] = low_state_.motor_state()[i]; 
    // Report motor errors
    motor_errors_.ReportErrors(motor_state_[i].reserve()[0]);
}

```

Full example is as follows:

```C++
#include <iostream>
#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/idl/go2/LowState_.hpp>
#include <unitree/idl/go2/MotorState_.hpp>
#include <unitree/common/time/time_tool.hpp>
#include <unitree/common/thread/thread.hpp>

using namespace unitree::common;
using namespace unitree::robot;

#define TOPIC_LOWSTATE "rt/lowstate"

class GetDetailMotorErrors
{
private:
    struct MotorErrorState
    {
        std::string error_type;
        short int state;
    };

    std::vector<MotorErrorState> motor_errors = {
        {error_type : "Over current", state : 0},
        {error_type : "Over voltage", state : 0},
        {error_type : "Driver overheat", state : 0},
        {error_type : "Motor bus under voltage", state : 0},
        {error_type : "Winding overheat", state : 0},
        {error_type : "Encoder abnormal", state : 0},
        {error_type : "Reserved, Not used", state : 0},
        {error_type : "Reserved, Not used", state : 0},
        {error_type : "Communication interrupted", state : 0},
    };

public:
    GetDetailMotorErrors(){};
    ~GetDetailMotorErrors(){};
    void ReportErrors(int error_code)
    {
        for (int i = 0; i < motor_errors.size(); i++)
        {   
            // Each bit of the error_code corresponds to a motor error type
            // For example, error_code = 6, i. e. error_code = 0b000000110, means Over voltage and Driver overheat.
            motor_errors[i].state = (error_code & (1 << i)) >> i;
            if (motor_errors[i].state > 0)
            {
                std::cout << motor_errors[i].error_type << ", ";
            }
        }
        std::cout << std::endl;
    };
};

class Custom
{
public:
    explicit Custom() {}

    ~Custom() {}
    void Init();

private:
    void LowStateMessageHandler(const void *messages);
    void ReportMotorState();

private:
    unitree_go::msg::dds_::LowState_ low_state_{};
    std::array<::unitree_go::msg::dds_::MotorState_, 20> motor_state_{};

    ChannelSubscriberPtr<unitree_go::msg::dds_::LowState_> lowstate_subscriber_;

    /*MotorState logging thread*/
    ThreadPtr MotorStateReportThreadPtr;
    GetDetailMotorErrors motor_errors_;
};

void Custom::Init()
{
    /*create subscriber*/
    lowstate_subscriber_.reset(new ChannelSubscriber<unitree_go::msg::dds_::LowState_>(TOPIC_LOWSTATE));
    lowstate_subscriber_->InitChannel(std::bind(&Custom::LowStateMessageHandler, this, std::placeholders::_1), 1);

    /*motor state logging thread*/
    MotorStateReportThreadPtr = CreateRecurrentThreadEx("log_motor_state", UT_CPU_ID_NONE, 500000, &Custom::ReportMotorState, this);
}

void Custom::LowStateMessageHandler(const void *message)
{
    low_state_ = *(unitree_go::msg::dds_::LowState_ *)message;
}

void Custom::ReportMotorState()
{
    for (int i = 0; i < 20; i++)
    {
        motor_state_[i] = low_state_.motor_state()[i]; // Get MotorState from LowState
    }

    // Report states of the first motor (motor[0])
    std::cout << "Mode: " << motor_state_[0].mode() << ", "
              << "Position: " << motor_state_[0].q() << ", "
              << "Velocity: " << motor_state_[0].dq() << ", "
              << "Estimated torque: " << motor_state_[0].tau_est() << ", "

              // Motor packet loss information (range: 0-9999999999).
              << "Motor packet loss: " << motor_state_[0].lost() << ", "

              // Current motor error flag bits and communication frequency:
              // Array: 0- Motor error flag bits (Range: 0-255)
              // Array: 1- Current motor communication frequency (Range: 0-800)
              << "Error code: " << motor_state_[0].reserve()[0] << std::endl;

    motor_errors_.ReportErrors(motor_state_[0].reserve()[0]);
}

int main(int argc, const char **argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
        exit(-1);
    }

    ChannelFactory::Instance()->Init(0, argv[1]);

    Custom custom;
    custom.Init();

    while (1)
    {
        sleep(10);
    }

    return 0;
}

```

--- 

# Debugging Specification

You can use own PC (with Ubuntu system) Ethernet port to connect Go2's Ethernet port, to build the communication between User PC and Go2.

![1](https://doc-cdn.unitree.com/static/2023/10/17/22b2ee2c6a514c4caccde708f54285e5_5807x3930.png)

--- 

# FAQ

# FAQ

## If you encounter a log related to Permission denied
1. Check the execution permissions of the file you are operating on, and change them with `chmod` .
1. Use `sudo` to execute permissions.

## How can I solve the problem when the dog is hung up and turned on but the legs are not in the right position?
The Go2 does not support hanging and powering on, it must be placed in the initial position before powering on.

## When Go2 turns on the obstacle avoidance function, does it go around the obstacle or stop the obstacle?
Currently there are 2 effects, the algorithm will automatically recognize the width of the obstacle, if it is too wide to avoid the obstacle, it will stop, if it is too narrow, it will go around it by itself.

## Command 'cmake' not found
The reason is command 'cmake' is not installed.You can follow this
    
  ```
  sudo apt install -y cmake
  ```

## No CMAKE CXX COMPILER Could be found.
  A: The compilation toolchain is missing from the environment.
  ```
  sudo apt-get install -y build-essential
  ```
## Opencv4 is already installed, but when compiling with cmake, cmake can also find opencv4, but the compilation reports error: fatal error: opencv2/opencv.hpp: No such file or directory #include <opencv2/opencv. hpp>
  This is because there is an extra opencv4 folder in the path of the opencv header file: `/usr/include/opencv4/opencv2`, we suggest to take the way 2.
  1. Copy opencv2 into your own include folder.
  2. Copy opencv2 to your own include folder, and soft-link opencv2 to your include folder.
  ```
  sudo ln -s /usr/include/opencv4/opencv2 /usr/include/
  ```
 ## What version of Go2 can be developed? /Differences in development capabilities between Go2 versions/Why can't I develop on my Go2?
Only EDU or above versions can be developed, other versions such as PRO and AIR versions do not open the secondary development interface, EDU version can be equipped with **40tops** or **100tops** docking station for development, you can refer to the reference document for details about Go2 [About Go2](https://support.unitree.com/home/en/developer/about%20Go2), and for development capabilities, see [Docking Station Configuration](https://support.unitree.com/home/en/developer/module_update).
    
## What do I need to prepare for development? /# Development environment requirements? /How to develop Go2?
Before development, you need to prepare a Linux system computer or virtual machine, and the system version needs to be **Ubuntu20.04**, you can refer to the document [Quick Start](https://support.unitree.com/home/en/developer/Quick_start) for specific development.
    
## Does Go2 support wireless development?
No, Go2 only supports wired connection for development.
  
## What is the low-level communication frequency of Go2 SDK?
Go2 SDK currently has 500hz communication frequency for low level, and 500hz for high level service interface.
  
## What development interfaces does Go2 support?
Go2 EDU version currently only provides SDK interface, no other standard function modules need to be combined with the computer and docking station development, the official standard module can refer to [About Go2](https://support.unitree.com/home/en/developer/about%20Go2).
  
## What is the resolution of the Go2 camera?
The head camera has 1080P(HD) 30fps or 720p 60fps HD recording capability with F2.2 aperture and 120° field of view. App HD transmission is available, and the camera can ensure smooth 720p 60fps HD transmission in a non-interference and unobstructed environment.

## What to pay attention to the development of foot sensor for Go2
The data of the foot sensor development has the characteristic of drift, so you need to consider the error situation when developing your own screening.

## Are there any remote software tools to recommend?

The official docking station has built-in nomachine, but when using it because there is no monitor, you need to log in to the docking station via SSH in advance and execute the nomachine.sh script in the home directory, so that you can use the nomachine remote tool normally.

## After installing pytorch, an ImportError appears when using it: libopenblas.so.0: cannot open shared object file: No such file or directory

Relevant dependent libraries are missing, install relevant dependent libraries
```language
sudo apt-get -y install autoconf bc build-essential g++-8 gcc-8 clang-8 lld-8 gettext-base gfortran-8 iputils-ping libbz2-dev libc++-dev libcgal-dev libffi-dev libfreetype6-dev libhdf5- dev libjpeg-dev liblzma-dev libncurses5-dev libncursesw5-dev libpng-dev libreadline-dev libssl-dev libsqlite3-dev libxml2-dev libxslt-dev locales moreutils openssl python-openssl rsync scons python3-pip libopenblas-dev
```
## More Questions
For more questions, you can also refer to the [Help Center](https://serviceconsole.unitree.com/#/help/0311)

