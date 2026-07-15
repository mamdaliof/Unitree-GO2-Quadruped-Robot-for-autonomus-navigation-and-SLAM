# Project Rules

- **No Premature Architecture/Algorithm Decisions**: Do not assume that any SLAM algorithms, mapping toolboxes, or planners have been permanently selected for our Go2 stack. All options are currently candidate options/suggestions in the morphological diagram, pending further research and analysis.
- **No Hardcoded Absolute Paths**: Do not hardcode absolute file/directory paths (e.g. `/home/mamdaliof/...`) for configuration files or log directories inside ROS 2 node sources. Declared parameters (`config_path`, `log_dir`) must be passed/resolved dynamically from launch files or environment variables.
