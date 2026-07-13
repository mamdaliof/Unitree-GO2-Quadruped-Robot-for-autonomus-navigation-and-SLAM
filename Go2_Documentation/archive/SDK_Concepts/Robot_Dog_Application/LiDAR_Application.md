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
