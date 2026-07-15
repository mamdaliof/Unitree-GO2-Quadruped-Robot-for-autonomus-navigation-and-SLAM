#ifndef GO2_SLAM__POINT_LIO_WRAPPER_HPP_
#define GO2_SLAM__POINT_LIO_WRAPPER_HPP_

#include <chrono>
#include <memory>
#include <string>
#include <thread>
#include <future>
#include <mutex>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <std_srvs/srv/trigger.hpp>
#include <rcl_interfaces/srv/set_parameters.hpp>

#include <go2_navigation/slam_interface.hpp>

namespace go2_slam
{

/**
 * @brief SLAMInterface wrapper implementing Point-LIO node controls.
 */
class PointLioWrapper : public go2_navigation::SLAMInterface
{
public:
  using SharedPtr = std::shared_ptr<PointLioWrapper>;

  /**
   * @brief Construct a new PointLioWrapper object.
   * @param nh Shared pointer to the parent ROS 2 node.
   */
  explicit PointLioWrapper(const rclcpp::Node::SharedPtr & nh)
  : node_(nh), mapping_active_(false), kidnap_detected_(false)
  {
  }

  virtual ~PointLioWrapper() = default;

  bool Init() override
  {
    RCLCPP_INFO(node_->get_logger(), "Initializing PointLioWrapper inside go2_slam...");

    // Create service client for save map
    save_map_client_ = node_->create_client<std_srvs::srv::Trigger>("/save_map");

    // Create client to set parameters dynamically
    set_params_client_ = node_->create_client<rcl_interfaces::srv::SetParameters>("/laserMapping/set_parameters");

    // Subscribe to localized pose output from Point-LIO
    odom_sub_ = node_->create_subscription<nav_msgs::msg::Odometry>(
      "/state_estimation", 10,
      std::bind(&PointLioWrapper::OdomCallback, this, std::placeholders::_1));

    // Publisher for manual cloud updates if needed
    cloud_pub_ = node_->create_publisher<sensor_msgs::msg::PointCloud2>("/cloud_registered", 10);

    return true;
  }

  bool StartMapping() override
  {
    mapping_active_ = true;
    RCLCPP_INFO(node_->get_logger(), "PointLioWrapper: Mapping started.");
    return true;
  }

  bool StopMapping() override
  {
    mapping_active_ = false;
    RCLCPP_INFO(node_->get_logger(), "PointLioWrapper: Mapping stopped.");
    return true;
  }

  bool SaveMap(const std::string & path) override
  {
    RCLCPP_INFO(node_->get_logger(), "PointLioWrapper: Saving map to %s...", path.c_str());
    if (!save_map_client_->wait_for_service(std::chrono::seconds(2))) {
        RCLCPP_ERROR(node_->get_logger(), "Save map service not available.");
        return false;
    }

    // Set parameter "map_save_path" first
    if (!SetNodeParameter("map_save_path", path)) {
        RCLCPP_WARN(node_->get_logger(), "Could not set map_save_path parameter, will save to default path.");
    }

    auto request = std::make_shared<std_srvs::srv::Trigger::Request>();
    auto result = save_map_client_->async_send_request(request);
    
    if (rclcpp::spin_until_future_complete(node_, result, std::chrono::seconds(5)) ==
        rclcpp::FutureReturnCode::SUCCESS)
    {
        auto response = result.get();
        if (response->success) {
            RCLCPP_INFO(node_->get_logger(), "Map saved: %s", response->message.c_str());
            return true;
        } else {
            RCLCPP_ERROR(node_->get_logger(), "Map save failed: %s", response->message.c_str());
            return false;
        }
    }
    RCLCPP_ERROR(node_->get_logger(), "Timeout waiting for save map service.");
    return false;
  }

  bool LoadMap(const std::string & path) override
  {
    RCLCPP_INFO(node_->get_logger(), "PointLioWrapper: Requesting load map from %s...", path.c_str());
    return SetNodeParameter("map_load_path", path);
  }

  bool UpdateMap(const sensor_msgs::msg::PointCloud2 & cloud) override
  {
    if (!mapping_active_) return false;
    cloud_pub_->publish(cloud);
    return true;
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
        if (time_diff.seconds() > 1.0) {
            kidnap_detected_ = true;
        } else {
            kidnap_detected_ = false;
        }
    }
    return kidnap_detected_;
  }

private:
  bool SetNodeParameter(const std::string & param_name, const std::string & param_value)
  {
    if (!set_params_client_->wait_for_service(std::chrono::seconds(2))) {
        return false;
    }
    auto request = std::make_shared<rcl_interfaces::srv::SetParameters::Request>();
    rcl_interfaces::msg::Parameter param;
    param.name = param_name;
    param.value.type = rcl_interfaces::msg::ParameterType::PARAMETER_STRING;
    param.value.string_value = param_value;
    request->parameters.push_back(param);

    auto result = set_params_client_->async_send_request(request);
    if (rclcpp::spin_until_future_complete(node_, result, std::chrono::seconds(2)) ==
        rclcpp::FutureReturnCode::SUCCESS)
    {
        auto response = result.get();
        if (!response->results.empty() && response->results[0].successful) {
            return true;
        }
    }
    return false;
  }

  void OdomCallback(const nav_msgs::msg::Odometry::SharedPtr msg)
  {
    std::lock_guard<std::mutex> lock(pose_mutex_);
    latest_odom_ = msg;
  }

  rclcpp::Node::SharedPtr node_;
  rclcpp::Client<std_srvs::srv::Trigger>::SharedPtr save_map_client_;
  rclcpp::Client<rcl_interfaces::srv::SetParameters>::SharedPtr set_params_client_;
  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
  rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr cloud_pub_;

  nav_msgs::msg::Odometry::SharedPtr latest_odom_;
  std::mutex pose_mutex_;
  bool mapping_active_;
  bool kidnap_detected_;
};

} // namespace go2_slam

#endif // GO2_SLAM__POINT_LIO_WRAPPER_HPP_
