# LiDAR and Point Cloud API

The Unitree Go2 Edu is equipped with a 3D LiDAR. By default, it publishes raw point clouds, motion-deskewed clouds, height maps, and direction-specific obstacle ranges.

## 1. Point Cloud Message Topics

* **Raw Lidar Point Cloud:**
  * **Topic:** `rt/utlidar/cloud`
  * **Coordinate Frame:** `utlidar_lidar` (LiDAR sensor frame)
  * **Description:** Raw, uncorrected returns directly from the sensor.
* **Deskewed Point Cloud (Motion Corrected):**
  * **Topic:** `rt/utlidar/cloud_deskewed`
  * **Coordinate Frame:** `odom` (World coordinate frame aligned with body odometry)
  * **Description:** Compensates for robot body motion during the scanner sweep using high-frequency IMU and odometry states.

---

## 2. Point Cloud Data Structures (`PointCloud2`)

Point cloud messages conform to the standard ROS 2 `sensor_msgs/msg/PointCloud2` schema, mapped to IDL structure:

```cpp
struct PointCloud2_ {
  std_msgs::msg::dds_::Header_ header;
  unsigned long height;       // Unordered clouds set height = 1
  unsigned long width;        // Total points in a frame sweep
  sequence<sensor_msgs::msg::dds_::PointField_> fields;
  boolean is_bigendian;
  unsigned long point_step;   // Size of one point in bytes
  unsigned long row_step;     // Size of one row in bytes (point_step * width)
  sequence<octet> data;       // Flat binary blob containing the point data
  boolean is_dense;           // True if there are no invalid points (NaNs)
};
```

---

## 3. Height Map Topic (`rt/utlidar/height_map_array`)

The height map is a 2D elevation grid centered on the robot representing the surrounding surface heights. This is used for obstacle costmaps, foothold planning, and step-up navigation.

### Map Message Specification (`HeightMap_.idl`)
```cpp
struct HeightMap_ {
  double stamp;           // Message timestamp
  string frame_id;        // Coordinate frame name (odom)
  float resolution;       // Resolution of each cell in meters (e.g., 0.06m)
  unsigned long width;    // Cell count along the X-axis (e.g., 128)
  unsigned long height;   // Cell count along the Y-axis (e.g., 128)
  float origin[2];        // Map frame origin XY-position [m] in world odom frame
  sequence<float> data;   // Elevation values in X-major order. Size = width * height.
};
```

*Note: Cells with no return are populated with `1.0e9`. Use this value to filter out unmapped cells.*

---

## 4. Simplified Obstacle Ranges (`rt/utlidar/range_info`)

A processed 3-directional distance representation indicating the distance to the nearest obstacles.
* **Topic:** `rt/utlidar/range_info`
* **Message Type:** `geometry_msgs::msg::dds_::PointStamped_`
* **Mapping:**
  * `point.x` = Distance to front obstacle (m)
  * `point.y` = Distance to left obstacle (m)
  * `point.z` = Distance to right obstacle (m)

---

## 5. Controlling Lidar State (`rt/utlidar/switch`)

To save power or prevent interference, the LiDAR rotation can be switched off:
* **Topic:** `rt/utlidar/switch`
* **Message Type:** `std_msgs::msg::dds_::String_`
* **Turn OFF command:** Publish string `OFF`.
* **Turn ON command:** Publish string `ON`.

---

## 6. Point Cloud Subscription Example (C++)

Example C++ code subscribing to raw point clouds using the Unitree SDK 2 channel API:

```cpp
#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/idl/ros2/PointCloud2_.hpp>

#define TOPIC_CLOUD "rt/utlidar/cloud"

void PointCloudHandler(const void *message)
{
  const sensor_msgs::msg::dds_::PointCloud2_ *cloud = 
      (const sensor_msgs::msg::dds_::PointCloud2_ *)message;
      
  std::cout << "Received Point Cloud Frame:"
            << "\n\tTimestamp: " << cloud->header().stamp().sec() 
            << "." << cloud->header().stamp().nanosec()
            << "\n\tFrame ID: " << cloud->header().frame_id()
            << "\n\tPoints Count: " << cloud->width()
            << std::endl << std::endl;
}

int main(int argc, const char **argv)
{
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
    exit(-1);
  }

  // Initialize Channel Factory on the specified network interface card
  unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);

  unitree::robot::ChannelSubscriber<sensor_msgs::msg::dds_::PointCloud2_> subscriber(TOPIC_CLOUD);
  subscriber.InitChannel(PointCloudHandler);

  while (true) {
    sleep(10);
  }
  return 0;
}
```
