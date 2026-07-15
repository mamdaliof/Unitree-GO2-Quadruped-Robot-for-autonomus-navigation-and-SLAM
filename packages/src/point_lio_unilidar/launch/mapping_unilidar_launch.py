import os
import json
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    # Declare config_path argument
    config_path_arg = DeclareLaunchArgument(
        'config_path',
        default_value='/home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/go2_config.json',
        description='Absolute path to the go2_config.json file'
    )

    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use simulation clock time if true'
    )

    map_load_path_arg = DeclareLaunchArgument(
        'map_load_path',
        default_value='',
        description='PCD file path to pre-load map'
    )

    map_save_path_arg = DeclareLaunchArgument(
        'map_save_path',
        default_value='',
        description='PCD file path to save map manually'
    )

    # We read config_path directly to set topics dynamically
    config_path = '/home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/go2_config.json'
    lidar_topic = '/go2/l1_lidar'
    imu_topic = '/go2/l1_imu'
    debug_enabled = False

    try:
        if os.path.exists(config_path):
            with open(config_path, 'r') as f:
                config = json.load(f)
                active_lidar = config.get("sensors", {}).get("active_lidars", "L1")
                if active_lidar == "L2":
                    lidar_topic = config.get("topics", {}).get("l2_lidar_output", "/go2/l2_lidar")
                    imu_topic = config.get("topics", {}).get("l2_imu_output", "/go2/l2_imu")
                else:
                    lidar_topic = config.get("topics", {}).get("l1_lidar_output", "/go2/l1_lidar")
                    imu_topic = config.get("topics", {}).get("l1_imu_output", "/go2/l1_imu")
                
                # Check if debug mode is enabled
                debug_enabled = config.get("system", {}).get("debug_mode", {}).get("enabled", False)
    except Exception as e:
        print(f"Error parsing config_path: {e}")

    # Point-LIO mapping node
    point_lio_node = Node(
        package='point_lio_unilidar',
        executable='pointlio_mapping',
        name='laserMapping',
        output='screen',
        parameters=[
            os.path.join(get_package_share_directory('point_lio_unilidar'), 'config', 'utlidar.yaml'),
            {
                'common.lid_topic': lidar_topic,
                'common.imu_topic': imu_topic,
                'use_sim_time': LaunchConfiguration('use_sim_time'),
                'map_load_path': LaunchConfiguration('map_load_path'),
                'map_save_path': LaunchConfiguration('map_save_path')
            }
        ],
        remappings=[
            ('/cloud_registered', '/registered_scan'),
            ('/aft_mapped_to_init', '/state_estimation')
        ]
    )

    actions = [
        config_path_arg,
        use_sim_time_arg,
        map_load_path_arg,
        map_save_path_arg,
        point_lio_node
    ]

    # Conditionally add rosbag record if debug mode is enabled in go2_config.json
    if debug_enabled:
        rosbag_record = ExecuteProcess(
            cmd=[
                'ros2', 'bag', 'record', '-o', 'debug_bag',
                '/utlidar/cloud', '/utlidar/cloud_l2',
                '/utlidar/imu', '/utlidar/imu_l2',
                '/registered_scan', '/state_estimation',
                '/tf', '/tf_static'
            ],
            output='screen'
        )
        actions.append(rosbag_record)

    return LaunchDescription(actions)
