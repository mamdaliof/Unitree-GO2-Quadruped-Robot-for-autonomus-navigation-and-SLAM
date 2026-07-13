The paper reviews nine types of robotic systems for environmental inspection, with Unmanned Aerial Vehicles (UAVs) being the most common, followed by Unmanned Ground Vehicles (UGVs).

Exclusion criteria for the Learning Factory project:
- Marine robots
- Robots with extremely low payloads
- Robots that are not commercially available

![[Pasted image 20260707132433.png]]

## Unmanned Aerial Vehicles (UAV)
UAVs are the most common platform in the literature; therefore, the documentation on them is more extensive.

### Advantages and Suitability
- Versatile with low operational and maintenance costs.
- Capable of reaching locations inaccessible to humans.
- More suitable for outdoor building inspections, particularly civil inspections.

### Types of UAVs
- **Fixed-wing**: Fast movement, but cannot hover in one place.
- **Rotary-wing**: Capable of hovering, but slower with shorter range.

### Sensors and Payloads
- Cameras are the primary sensors used for inspection, though the captured images can be noisy.
- Low payload capacity.
- Many UAVs use additional sensors to aid navigation, including gyroscopes, magnetometers, barometers, SONAR, and inertial navigation systems (INS).

### Challenges and Limitations
- Collision avoidance is more challenging than for ground-based robots.
- While efficient outdoors, they have limited utility indoors due to visual obstructions and high dependency on GPS, which makes indoor applications unreliable.

### Future Phase Questions
- Is a camera sufficient for accurate localization?
- What is the positioning accuracy of a hovering UAV?

---

## Unmanned Ground Vehicles (UGV)
UGVs feature the simplest mechanical design.

### Advantages and Suitability
- Work well on flat surfaces.
- High stability and payload capacity due to a low center of gravity.

### Types of UGVs
- **Wheel-driven**: Best for flat surfaces.
- **Crawlers (tracked)**: Perform better on slick or wet terrain.

### Sensors and Payloads
- Common payloads include: stereo/monocular cameras, LiDAR, robotic arms for manipulation, ground-penetrating radar (GPR), ultrasonic sensors, infrared sensors (for sub-surface and behind-wall sensing), GPUs, IMUs, GPS, and UWB.

### Challenges and Limitations
- Perform poorly on cluttered or uneven surfaces.
- Low height is a disadvantage, limiting sensor reach and perspective in large halls.

---

## Wall-Climbing Robots
Primarily used for building facades, windows, or external piping.

### Capabilities and Limitations
- Heavy payload capacity is possible.
- **Industrial case application**: We require a robot to traverse the industrial setup to take measurements. Wall-climbing robots are restricted to specific vertical walls, making them unsuitable for general factory floor inspection.

---

## Cable-Crawling Robots
Primarily used for bridge inspection applications.

### Capabilities and Limitations
- Capable of carrying heavy payloads and achieving accurate localization.
- **Industrial case application**: Feasible but requires specialized guide cables. Further research is required if this setup becomes necessary.

---

## Legged Robots
Legged robots possess the adaptability and mobility to traverse diverse types of terrain.

### Capabilities and Limitations
- Historically limited practical deployment outside laboratories due to high technical complexity.
- **Industrial case application**: A major advantage over UGVs is the ability to traverse stairs, facilitating multi-story industrial inspection.

---

# Autonomous Navigation

## Localization
For indoor applications, a Local Navigation System (LNS) is utilized.
- **Traditional LNS**: Requires direct line-of-sight with anchor nodes. Accuracy degrades up to 11 meters in non-line-of-sight environments. Certain methods can improve this accuracy to 2 meters.
- **Centimeter-Level Accuracy**: Real-Time Kinematic (RTK), Differential GPS (DGPS), and Ultra-Wide Band (UWB) can enhance positioning accuracy to the centimeter range.
- **SLAM**: Simultaneous Localization and Mapping using LiDAR combined with IMU and GPS is feasible. Dead-reckoning is unsuitable due to cumulative drift.

## Path Planning
- **4D BIM**: Building Information Modeling (BIM) is used as a planning tool and provides crucial structural data (e.g., doors, openings) that must be accounted for in indoor path planning.
- **3D Point Clouds**: If BIM is unavailable, 3D point clouds can be substituted for path planning.
- **UAVs**: Path planning for UAVs commonly utilizes discrete particle swarm optimization.

## Navigation
No relevant or useful information provided in the source paper.