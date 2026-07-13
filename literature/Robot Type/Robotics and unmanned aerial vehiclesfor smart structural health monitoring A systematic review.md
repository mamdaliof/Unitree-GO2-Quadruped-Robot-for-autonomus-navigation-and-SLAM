Exclusion criteria for the Learning Factory project:
- Vertical robots that are restricted to climbing a specific wall.

# Ground Vehicles

Technically, recent progress in SLAM, real-time navigation, and sensor fusion enables ground mobile robots to perform high-precision measurements in dynamic and unstructured environments. These robots enhance efficiency, repeatability, and safety by performing routine monitoring tasks with reduced or minimal human involvement, often in environments that are hazardous or inaccessible to human inspectors.

## Wheeled Robots and Railed Robots
- Primarily suitable for flat and semi-structured surfaces.
- Capable of carrying heavy sensor payloads and traversing long distances autonomously.
- Comparison with legged robots: Wheeled and tracked robots generally offer smoother and more stable motion on even terrain, resulting in lower vibration-induced noise during data acquisition and more consistent sensor readings, especially for imaging or laser-scanning tasks.

## Legged Robots
- Rely on articulated multi-joint limbs that emulate animal or human gaits, allowing them to step over obstacles, climb stairs, and maintain stable contact on highly irregular or cluttered surfaces.
- While wheeled and tracked robots perform well on relatively smooth terrain, they face challenges in highly uneven or cluttered environments, such as climbing stairs.
- Provide superior performance on irregular or obstacle-dense surfaces in comparison with wheeled/tracked UGVs.
- Control tasks are computationally intensive, which limits their speed and energy efficiency in comparison with wheeled systems.
- Best suited for operations in highly irregular or hazardous environments where conventional wheeled systems cannot maintain stability or traction.
- Several recent studies highlight advancements in legged robots that strengthen autonomous perception, human-robot collaboration, and site-scale data acquisition.
- In scenarios where human presence is unavoidable, quadruped robots support repetitive monitoring tasks in close coordination with operators.

## Collaborative and Multi-Robot Systems
- Multiple autonomous agents cooperate to perform inspections, data collection, and decision-making.
- Requires a robust communication network (such as Wi-Fi, cellular, or dedicated IoT links) to synchronize tasks, share sensor data, and adapt trajectories in real time.

## Unmanned Aerial Vehicles (UAV)
- Capable of flying freely in 3D space and covering large areas efficiently.

# Related Works
- [Mobile Structural Health Monitoring Based on Legged Robots](https://www.mdpi.com/2412-3811/8/9/136): Quadruped robots function as mobile sensing nodes and modal-testing agents. Instead of relying on dense stationary sensor deployments, the robots autonomously move across predefined measurement locations, collect vibration responses, and perform basic spectral processing on board before transmitting condensed modal information to a remote server for mode-shape reconstruction. Implemented on commercial quadruped platforms with LiDAR and inertial sensing, the approach demonstrates that legged robots can recover modal characteristics of a pedestrian bridge with accuracy comparable to stationary wireless systems while requiring fewer sensing nodes.
- [Construction inspection & monitoring with quadruped robots in future human-robot teaming: A preliminary study](https://www.sciencedirect.com/science/article/pii/S2352710222018204): Demonstrates that legged robots can reliably perform routine inspection missions alongside human workers, contributing to improved site safety and monitoring efficiency.
- [Fundamentals and Prospects of Four-Legged Robot Application in Construction Progress Monitoring](https://www.facilities.vt.edu/content/dam/facilities_vt_edu/campus-construction-projects/ASC_2021_proceedings-282-290%20VTMLSOC%20042221.pdf)

