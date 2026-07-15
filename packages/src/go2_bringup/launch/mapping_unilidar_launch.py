import os
import json
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    config_path_arg = DeclareLaunchArgument(
        'config_path',
        default_value='/home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/go2_config.json',
        description='Absolute path to the go2_config.json file'
    )

    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
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

    config_path = '/home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/go2_config.json'
    
    # Default variables
    active_lidar = "L1"
    lidar_topic = '/go2/l1_lidar'
    imu_topic = '/go2/l1_imu'
    debug_enabled = False
    slam_backend = "Point-LIO"

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
                
                debug_enabled = config.get("system", {}).get("debug_mode", {}).get("enabled", False)
                slam_backend = config.get("system", {}).get("slam_backend", "Point-LIO")
    except Exception as e:
        print(f"Error parsing config_path: {e}")

    # 1. ALWAYS launch the sensor publisher
    sensor_publisher_node = Node(
        package='go2_sensors',
        executable='sensor_publisher_node',
        name='go2_sensor_publisher',
        output='screen',
        parameters=[{
            'config_path': LaunchConfiguration('config_path'),
            'use_sim_time': LaunchConfiguration('use_sim_time')
        }]
    )

    actions = [
        config_path_arg,
        use_sim_time_arg,
        map_load_path_arg,
        map_save_path_arg,
        sensor_publisher_node
    ]

    # 2. Launch the selected SLAM backend nodes
    if slam_backend == "A-LOAM":
        # A-LOAM nodes
        scan_line = 16
        minimum_range = 1.0
        
        # A-LOAM expects input cloud on /velodyne_points (remap to active output)
        ascanRegistration_node = Node(
            package='aloam_velodyne_ros2',
            executable='ascanRegistration',
            name='ascanRegistration',
            output='screen',
            parameters=[
                {'scan_line': scan_line},
                {'minimum_range': minimum_range}
            ],
            remappings=[
                ('/velodyne_points', lidar_topic)
            ]
        )

        alaserOdometry_node = Node(
            package='aloam_velodyne_ros2',
            executable='alaserOdometry',
            name='alaserOdometry',
            output='screen'
        )

        alaserMapping_node = Node(
            package='aloam_velodyne_ros2',
            executable='alaserMapping',
            name='alaserMapping',
            output='screen',
            parameters=[
                {'mapping_skip_frame': 1},
                {'mapping_line_resolution': 0.2},
                {'mapping_plane_resolution': 0.4}
            ]
        )

        transform_map = Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='camera_init_to_map',
            arguments=['0', '0', '0', '0', '0', '0', 'map', 'camera_init'],
        )

        # RViz for A-LOAM
        rviz_config_path = os.path.join(
            get_package_share_directory('aloam_velodyne_ros2'),
            'rviz_cfg',
            'aloam_velodyne_ros2.rviz'
        )
        rviz_node = Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', rviz_config_path],
            output='screen'
        )

        actions.extend([
            ascanRegistration_node,
            alaserOdometry_node,
            alaserMapping_node,
            transform_map,
            rviz_node
        ])

    else:
        # Point-LIO nodes
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

        # RViz for Point-LIO
        rviz_config_path = os.path.join(
            get_package_share_directory('point_lio_unilidar'),
            'rviz_cfg',
            'loam_livox2.rviz'
        )
        rviz_node = Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', rviz_config_path],
            output='screen'
        )

        actions.extend([
            point_lio_node,
            rviz_node
        ])

    # 3. Conditionally add rosbag record if debug mode is enabled in go2_config.json
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
