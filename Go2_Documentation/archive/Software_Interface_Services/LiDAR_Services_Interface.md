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
