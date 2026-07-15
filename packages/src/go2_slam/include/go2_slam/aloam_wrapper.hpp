#ifndef GO2_SLAM__ALOAM_WRAPPER_HPP_
#define GO2_SLAM__ALOAM_WRAPPER_HPP_

#include <chrono>
#include <memory>
#include <string>
#include <mutex>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <nav_msgs/msg/odometry.hpp>

#include <go2_navigation/slam_interface.hpp>

namespace go2_slam
{

/**
 * @brief Concrete implementation of SLAMInterface for A-LOAM.
 */
class ALoamWrapper : public go2_navigation::SLAMInterface
{
public:
  using SharedPtr = std::shared_ptr<ALoamWrapper>;

  /**
   * @brief Construct a new ALoamWrapper object.
   * @param nh Shared pointer to the parent ROS 2 node.
   */
  explicit ALoamWrapper(const rclcpp::Node::SharedPtr & nh)
  : node_(nh), mapping_active_(false), kidnap_detected_(false)
  {
  }

  virtual ~ALoamWrapper() = default;

  bool Init() override
  {
    RCLCPP_INFO(node_->get_logger(), "Initializing ALoamWrapper inside go2_slam...");

    // Subscribe to map cloud from A-LOAM
    map_sub_ = node_->create_subscription<sensor_msgs::msg::PointCloud2>(
      "/laser_cloud_map", 10,
      std::bind(&ALoamWrapper::MapCallback, this, std::placeholders::_1));

    // Subscribe to localized pose output from A-LOAM
    odom_sub_ = node_->create_subscription<nav_msgs::msg::Odometry>(
      "/aft_mapped_to_init", 10,
      std::bind(&ALoamWrapper::OdomCallback, this, std::placeholders::_1));

    // Publisher for loaded map visualization
    map_pub_ = node_->create_publisher<sensor_msgs::msg::PointCloud2>("/laser_cloud_map_loaded", 10);

    return true;
  }

  bool StartMapping() override
  {
    mapping_active_ = true;
    RCLCPP_INFO(node_->get_logger(), "ALoamWrapper: Mapping started.");
    return true;
  }

  bool StopMapping() override
  {
    mapping_active_ = false;
    RCLCPP_INFO(node_->get_logger(), "ALoamWrapper: Mapping stopped.");
    return true;
  }

  bool SaveMap(const std::string & path) override
  {
    RCLCPP_INFO(node_->get_logger(), "ALoamWrapper: Saving map to %s...", path.c_str());
    std::lock_guard<std::mutex> lock(map_mutex_);
    if (!latest_map_msg_) {
        RCLCPP_ERROR(node_->get_logger(), "ALoamWrapper: Map is empty, cannot save.");
        return false;
    }

    try {
        pcl::PointCloud<pcl::PointXYZI>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZI>());
        pcl::fromROSMsg(*latest_map_msg_, *pcl_cloud);
        
        pcl::PCDWriter pcd_writer;
        pcd_writer.writeBinary(path, *pcl_cloud);
        RCLCPP_INFO(node_->get_logger(), "ALoamWrapper: Map saved successfully with %zu points.", pcl_cloud->size());
        return true;
    } catch (const std::exception & e) {
        RCLCPP_ERROR(node_->get_logger(), "ALoamWrapper: Failed to save map PCD: %s", e.what());
        return false;
    }
  }

  bool LoadMap(const std::string & path) override
  {
    RCLCPP_INFO(node_->get_logger(), "ALoamWrapper: Loading map from %s...", path.c_str());
    try {
        pcl::PointCloud<pcl::PointXYZI>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZI>());
        if (pcl::io::loadPCDFile<pcl::PointXYZI>(path, *pcl_cloud) == -1) {
            RCLCPP_ERROR(node_->get_logger(), "ALoamWrapper: Failed to read PCD file %s", path.c_str());
            return false;
        }

        sensor_msgs::msg::PointCloud2 ros_cloud;
        pcl::toROSMsg(*pcl_cloud, ros_cloud);
        ros_cloud.header.frame_id = "camera_init";
        ros_cloud.header.stamp = node_->now();
        map_pub_->publish(ros_cloud);

        RCLCPP_INFO(node_->get_logger(), "ALoamWrapper: Map loaded and published to /laser_cloud_map_loaded.");
        RCLCPP_WARN(node_->get_logger(), "ALoamWrapper NOTE: A-LOAM does not support dynamic relocation localization against pre-loaded maps.");
        return true;
    } catch (const std::exception & e) {
        RCLCPP_ERROR(node_->get_logger(), "ALoamWrapper: Exception during map load: %s", e.what());
        return false;
    }
  }

  bool UpdateMap(const sensor_msgs::msg::PointCloud2 & cloud) override
  {
    (void)cloud;
    return mapping_active_;
  }

  bool Localize(geometry_msgs::msg::PoseStamped & pose) override
  {
    std::lock_guard<std::mutex> lock(pose_mutex_);
    if (!latest_odom_) {
        return false;
    }
    pose.header = latest_odom_->header;
    pose.pose.position = latest_odom_->pose.pose.position;
    pose.pose.orientation = latest_odom_->pose.pose.orientation;
    return true;
  }

  bool CheckKidnapStatus() override
  {
    if (!latest_odom_ && mapping_active_) {
        kidnap_detected_ = true;
    } else if (latest_odom_) {
        auto time_diff = node_->now() - latest_odom_->header.stamp;
        if (time_diff.seconds() > 1.5) {
            kidnap_detected_ = true;
        } else {
            kidnap_detected_ = false;
        }
    }
    return kidnap_detected_;
  }

private:
  void MapCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
  {
    std::lock_guard<std::mutex> lock(map_mutex_);
    latest_map_msg_ = msg;
  }

  void OdomCallback(const nav_msgs::msg::Odometry::SharedPtr msg)
  {
    std::lock_guard<std::mutex> lock(pose_mutex_);
    latest_odom_ = msg;
  }

  rclcpp::Node::SharedPtr node_;
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr map_sub_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr map_pub_;

  sensor_msgs::msg::PointCloud2::SharedPtr latest_map_msg_;
  nav_msgs::msg::Odometry::SharedPtr latest_odom_;
  
  std::mutex map_mutex_;
  std::mutex pose_mutex_;
  
  bool mapping_active_;
  bool kidnap_detected_;
};

} // namespace go2_slam

#endif // GO2_SLAM__ALOAM_WRAPPER_HPP_
