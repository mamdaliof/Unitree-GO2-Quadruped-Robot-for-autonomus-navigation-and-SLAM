import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    # Declare the launch argument for configuration path
    # Users can override this parameter when running the launch file
    config_path_arg = DeclareLaunchArgument(
        'config_path',
        default_value='/home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/go2_config.json',
        description='Absolute path to the go2_config.json file'
    )

    # Declare the launch argument for simulation time flag
    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Use simulation (bag/clock) time if true'
    )

    # Declare the launch argument for calibration log directory
    log_dir_arg = DeclareLaunchArgument(
        'log_dir',
        default_value='/home/mamdaliof/Documents/GitHub/mamdaliof-obsidian/02-Projects/learning-factory-project/packages/src/go2_sensors/log',
        description='Directory to save daily calibration log files'
    )

    # Configure the sensor publisher node action
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

    # Configure the sensor calibration node action
    sensor_calibration_node = Node(
        package='go2_sensors',
        executable='sensor_calibration_node',
        name='go2_sensor_calibration',
        output='screen',
        parameters=[{
            'config_path': LaunchConfiguration('config_path'),
            'log_dir': LaunchConfiguration('log_dir')
        }]
    )

    return LaunchDescription([
        config_path_arg,
        use_sim_time_arg,
        log_dir_arg,
        sensor_publisher_node,
        sensor_calibration_node
    ])
