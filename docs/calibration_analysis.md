# Calibration Analysis & Multi-IMU Math Reference

This document provides a mathematical audit of the sensor calibration sequence for the Unitree Go2 quadruped robot. It details coordinate frame alignment, static bias estimation, dynamic cross-coupling projections, and limitations regarding closed-source onboard IMUs.

---

## 1. Calibration Sequence & State Machine

The calibration node executes a time-indexed state machine over a **37-second** window to collect calibration data:

| Time (seconds) | State ID | Name | Description |
| :--- | :--- | :--- | :--- |
| **0 – 2** | `0` | Alignment | Robot is commanded to stand still. Commands `StopMove` via SportClient to establish static equilibrium. |
| **2 – 15** | `1` | Static Calibration | Robot remains stationary. From $t = 5$ to $t = 15$ (allowing mechanical transients to settle), raw static sensor readings are accumulated. |
| **15 – 35** | `2` | Active Rotation | Robot executes active Z-axis yaw rotation at a commanded speed of $\Omega_z = 1.396\text{ rad/s}$ ($80^\circ/\text{s}$). Dynamic gyro values are recorded. |
| **35 – 37** | `3` | Processing & Save | Rotation ceases. The node computes accelerometer/gyroscope biases and axial projection factors, saving them to a daily YAML log. |

---

## 2. Coordinate Transformation (LiDAR Tilt Alignment)

The Unitree L1 and L2 LiDAR payloads are physically pitched at specific tilt angles relative to the robot's horizontal body plane. To align their measurements with the Z-up base coordinate frame, raw inputs must undergo coordinate transformation.

### 2.1 Configured Tilt Angles
- **L1 LiDAR (`l1_lidar_tilt_angle_deg`):** $\theta_1 = 13.0^\circ$ (catalog tilt).
- **L2 LiDAR (`l2_lidar_tilt_angle_deg`):** $\theta_2 = 15.0^\circ$ (measured tilt).

### 2.2 Axis Inversion (Right-Hand Rule)
Raw axes are first inverted to match the ROS Right-Hand Rule (RHR) conventions ($X$ forward, $Y$ left, $Z$ up):
$$x_{\text{rhr}} = x_{\text{raw}}$$
$$y_{\text{rhr}} = -y_{\text{raw}}$$
$$z_{\text{rhr}} = -z_{\text{raw}}$$

### 2.3 Pitch Rotation Matrix
To rotate the RHR-aligned vector about the $Y$-axis by the LiDAR pitch tilt angle $\theta$, we apply the pitch rotation matrix $R_y(\theta)$:
$$R_y(\theta) = \begin{bmatrix} \cos(\theta) & 0 & -\sin(\theta) \\ 0 & 1 & 0 \\ \sin(\theta) & 0 & \cos(\theta) \end{bmatrix}$$

Multiplying this rotation by the RHR vector yields the aligned base frame measurements:
$$\begin{bmatrix} x' \\ y' \\ z' \end{bmatrix} = R_y(\theta) \begin{bmatrix} x_{\text{raw}} \\ -y_{\text{raw}} \\ -z_{\text{raw}} \end{bmatrix} = \begin{bmatrix} x_{\text{raw}} \cos(\theta) + z_{\text{raw}} \sin(\theta) \\ -y_{\text{raw}} \\ x_{\text{raw}} \sin(\theta) - z_{\text{raw}} \cos(\theta) \end{bmatrix}$$

In our C++ implementation, we define $z = -z_{\text{raw}}$, resulting in the equivalent code form:
$$x' = x_{\text{raw}} \cos(\theta) - z \sin(\theta)$$
$$z' = x_{\text{raw}} \sin(\theta) + z \cos(\theta)$$

---

## 3. Mathematical Modeling & Static Analysis

### 3.1 Measurement Model
The measured linear acceleration $\vec{a}'$ and angular velocity $\vec{\omega}'$ in the aligned base frame are modeled as:
$$\vec{a}' = R_y(\theta) \left( \vec{a}_{\text{true}} + \vec{b}_a + \vec{\eta}_a \right)$$
$$\vec{\omega}' = R_y(\theta) \left( \vec{\omega}_{\text{true}} + \vec{b}_\omega + \vec{\eta}_\omega \right)$$

where:
- $\vec{b}_a, \vec{b}_\omega$ are the constant accelerometer and gyroscope biases.
- $\vec{\eta}_a, \vec{\eta}_\omega$ are zero-mean white Gaussian sensor noise.
- $\vec{a}_{\text{true}}, \vec{\omega}_{\text{true}}$ are the true physical states.

### 3.2 Static Bias Calculations
During the static phase (State 1), the true angular velocity is zero, and the true linear acceleration consists solely of vertical gravity:
$$\vec{\omega}_{\text{true}} = \begin{bmatrix} 0 \\ 0 \\ 0 \end{bmatrix}, \quad \vec{a}_{\text{true}} = \begin{bmatrix} 0 \\ 0 \\ g \end{bmatrix} \approx \begin{bmatrix} 0 \\ 0 \\ 9.81 \end{bmatrix} \text{ m/s}^2$$

By taking the expectation (temporal average) over $N$ static samples, the zero-mean white noise terms $\vec{\eta}$ vanish ($E[\vec{\eta}] \to 0$):
$$\vec{b}'_\omega = E[\vec{\omega}'] = \frac{1}{N} \sum_{i=1}^{N} \begin{bmatrix} x'_i \\ y'_i \\ z'_i \end{bmatrix}$$
$$\vec{b}'_a = E[\vec{a}'] - \begin{bmatrix} 0 \\ 0 \\ g \end{bmatrix} = \left( \frac{1}{N} \sum_{i=1}^{N} \begin{bmatrix} acc'_{x, i} \\ acc'_{y, i} \\ acc'_{z, i} \end{bmatrix} \right) - \begin{bmatrix} 0 \\ 0 \\ 9.81 \end{bmatrix}$$

This isolates the static bias parameters:
$$\text{acc\_bias\_x} = \bar{acc'}_x$$
$$\text{acc\_bias\_y} = \bar{acc'}_y$$
$$\text{acc\_bias\_z} = \bar{acc'}_z - 9.81$$
$$\text{ang\_bias\_x} = \bar{\omega'}_x$$
$$\text{ang\_bias\_y} = \bar{\omega'}_y$$
$$\text{ang\_bias\_z} = \bar{\omega'}_z$$

---

## 4. Dynamic Misalignment & Cross-Coupling Analysis

During the active rotation phase (State 2), the robot executes a pure yaw rotation around its kinematic vertical axis at commanded velocity $\Omega_z$.

### 4.1 Cross-Coupling Projection
If the IMU sensor frame is perfectly aligned with the robot's physical rotation axis, the measured yaw-rate-corrected angular velocities around the $X$ and $Y$ base axes should be zero. Any non-zero mean values are caused by mechanical misalignment:
$$\bar{\omega}_{\text{rot}, x} = \left( \frac{1}{M} \sum_{j=1}^{M} x'_j \right) - \text{ang\_bias\_x}$$
$$\bar{\omega}_{\text{rot}, y} = \left( \frac{1}{M} \sum_{j=1}^{M} y'_j \right) - \text{ang\_bias\_y}$$
$$\bar{\omega}_{\text{rot}, z} = \left( \frac{1}{M} \sum_{j=1}^{M} z'_j \right) - \text{ang\_bias\_z}$$

The cross-coupling projection coefficients representing the projection of rotation from the $Z$-axis onto the $X$ and $Y$ base axes are computed as:
$$\text{ang\_z2x\_proj} = -\frac{\bar{\omega}_{\text{rot}, x}}{\bar{\omega}_{\text{rot}, z}}$$
$$\text{ang\_z2y\_proj} = -\frac{\bar{\omega}_{\text{rot}, y}}{\bar{\omega}_{\text{rot}, z}}$$

These coefficients allow point-cloud undistortion and state-estimation algorithms to compensate dynamically for sensor tilt errors relative to the robot's actual kinematic rotation axis.

---

## 5. Open Question: Onboard vs. External Calibration

### 5.1 Onboard Motherboard IMU Calibration Problem
The Unitree Go2 motherboard contains its own internal IMU, which runs proprietary, closed-source estimation algorithms to maintain robot balance and gate locomotion.
- **Access Limits:** We do not have register-level access to the motherboard IMU, nor can we change or read its internal calibration parameters.
- **Factory Drift:** The onboard IMU undergoes automatic self-calibration at boot. If the robot boots on a slope or during disturbance, this factory calibration introduces an uncorrectable attitude bias, which we cannot access or correct.

### 5.2 Independent L1 & L2 LiDAR IMUs
Because both the L1 and L2 LiDAR units contain their own integrated IMUs, we must calibrate them independently from the motherboard's IMU:
- **No Shared Calibration:** Motherboard calibration parameters cannot be reused for L1 and L2 IMUs.
- **Independent Tilts:** Since L1 and L2 are physically pitched at different angles ($\theta_1 = 13.0^\circ$ vs $\theta_2 = 15.0^\circ$), their coordinate rotations and cross-coupling projections differ.
- **Tightly-Coupled SLAM Impact:** SLAM packages (like Point-LIO) require highly accurate IMU streams for point-cloud deskewing. Performing this independent, dual-sensor external calibration sequence is critical to prevent spatial mapping drift.
