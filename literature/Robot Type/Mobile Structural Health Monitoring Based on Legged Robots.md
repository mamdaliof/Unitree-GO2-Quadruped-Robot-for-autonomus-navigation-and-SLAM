They compare the performance of a legged robot with sensors for inspection in comparision with fixed location sensors. 
Although the UGV robots are empeleyed for inspection, but there si room for improvments with legged robot regarding maneuverability, transversability, and efficiency.
eing easy to control, design, and maintain, quadruped robots exhibit better equilibrium than robots with fewer legs, while walking control is not as complex as walking control of multi-legged robots
# Inspection of Vibration
In this research they mainly interested into vibration data.
vibration-based SHM is selected, because accelerometers require neither to be fixed with strong adhesives for measuring accurately, as is the case with strain gauges, nor to be insulated, as is the case with temperature sensors.
# Robot Config
+ Quadruped robot, IDOG based on A unitree.
+ Sensors
	+ acceleration data
	+ LIDAr
	+ IMU
# Measurement Grid
Find locations to measure data.
they use a discretionary technique and based on the complexity of the are, increase the points in the grid.
To stitch together a complete vibration map of a large structure using only two devices, the mobile system utilizes an overlapping "leapfrog" strategy across successive pairs of measurement locations. Because random ambient forces like wind or traffic fluctuate constantly, data from isolated setups cannot be directly compared; therefore, for a grid of $m$ locations, the robots conduct at least $m-1$ setups, ensuring that each new session contains one identical location from the previous setup. This shared, overlapping data point acts as a mathematical baseline, allowing a centralized server to calculate relative amplitude differences and normalize the changing scales between separate sessions. Through this successive normalization process, the system seamlessly stitches individual local measurements into a single, continuous, and highly detailed experimental mode shape of the entire structure.
# read later:
Ramasamy, V. Mobile wireless sensor networks: An overview. In Wireless Sensor Networks—Insights and Innovations; Sallis, P.J., Ed.;
IntechOpen Ltd.: London, UK, 2017; pp. 3–19.