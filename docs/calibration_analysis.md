# Calibration Algorithm Analysis & Math Reference

This document provides a mathematical audit and description of the sensor calibration sequence implemented for the Go2 quadruped robot. It details the coordinate frame alignment, static bias estimation, and dynamic rotation axis cross-coupling analysis.

---

## 1. Sequence Timeline & State Machine

The calibration node executes a time-indexed state machine over a **37-second** window:

| Time (seconds) | State ID | Name | Description |
| :--- | :--- | :--- | :--- |
| **0 – 2** | `0` | Alignment | Robot commanded to stand still. Commands `StopMove` via SportClient to establish static equilibrium. |
| **2 – 15** | `1` | Static Calibration | Robot remains completely stationary. From $t = 5$ to $t = 15$ (allowing initial mechanical transients to settle), raw sensor data is accumulated. |
| **15 – 35** | `2` | Active Rotation | Robot executes active Z-axis rotation at a commanded yaw rate of $\Omega_z = 1.396\text{ rad/s}$ ($80^\circ/\text{s}$). Dynamic gyro values are recorded. |
| **35 – 37** | `3` | Processing & Save | Rotation ceases. The node computes accelerometer/gyroscope biases and axial projection factors, then saves them to a daily YAML log. |

---

## 2. Coordinate Transformation (LiDAR Tilt Alignment)

The Unitree LiDAR contains an internal IMU that is physically pitched at an angle $\theta$ relative to the robot's horizontal body plane. In order to use these measurements in navigation and mapping, raw measurements must be rotated into the Z-up base coordinate frame.

### Axis Inversion (Right-Hand Rule)
First, raw axes must be inverted to match a standard ROS Right-Hand Rule (RHR) coordinate frame ($X$ forward, $Y$ left, $Z$ up):
$$x_{\text{rhr}} = x_{\text{raw}}$$
$$y_{\text{rhr}} = -y_{\text{raw}}$$
$$z_{\text{rhr}} = -z_{\text{raw}}$$

### Pitch Rotation Matrix
To rotate the RHR-aligned vector about the $Y$-axis by the LiDAR pitch tilt angle $\theta$, we apply the pitch rotation matrix $R_y(\theta)$:
$$R_y(\theta) = \begin{bmatrix} \cos(\theta) & 0 & -\sin(\theta) \\ 0 & 1 & 0 \\ \sin(\theta) & 0 & \cos(\theta) \end{bmatrix}$$

Applying this rotation to the RHR vector:
$$\begin{bmatrix} x' \\ y' \\ z' \end{bmatrix} = R_y(\theta) \begin{bmatrix} x_{\text{rhr}} \\ y_{\text{rhr}} \\ z_{\text{rhr}} \end{bmatrix} = \begin{bmatrix} \cos(\theta) & 0 & -\sin(\theta) \\ 0 & 1 & 0 \\ \sin(\theta) & 0 & \cos(\theta) \end{bmatrix} \begin{bmatrix} x_{\text{raw}} \\ -y_{\text{raw}} \\ -z_{\text{raw}} \end{bmatrix}$$

Multiplying the matrix out yields the aligned base frame measurements:
$$x' = x_{\text{raw}} \cos(\theta) + z_{\text{raw}} \sin(\theta)$$
$$y' = -y_{\text{raw}}$$
$$z' = x_{\text{raw}} \sin(\theta) - z_{\text{raw}} \cos(\theta)$$

In the implementation, $z$ represents the intermediate term $-z_{\text{raw}}$, meaning the code writes:
$$x' = x_{\text{raw}} \cos(\theta) - z \sin(\theta)$$
$$z' = x_{\text{raw}} \sin(\theta) + z \cos(\theta)$$
which is mathematically identical.

---

## 3. Mathematical Modeling & Static Analysis

### Measurement Model
The measured linear acceleration $\vec{a}'$ and angular velocity $\vec{\omega}'$ in the aligned base frame are modeled as:
$$\vec{a}' = R_y(\theta) \left( \vec{a}_{\text{true}} + \vec{b}_a + \vec{\eta}_a \right)$$
$$\vec{\omega}' = R_y(\theta) \left( \vec{\omega}_{\text{true}} + \vec{b}_\omega + \vec{\eta}_\omega \right)$$

where:
- $\vec{b}_a, \vec{b}_\omega$ are the constant accelerometer and gyroscope biases.
- $\vec{\eta}_a, \vec{\eta}_\omega$ are zero-mean white Gaussian sensor noise.
- $\vec{a}_{\text{true}}, \vec{\omega}_{\text{true}}$ are the true physical states.

### Static Bias Calculations
During the static phase (State 1), the true angular velocity is zero, and the true linear acceleration consists solely of vertical gravity:
$$\vec{\omega}_{\text{true}} = \begin{bmatrix} 0 \\ 0 \\ 0 \end{bmatrix}, \quad \vec{a}_{\text{true}} = \begin{bmatrix} 0 \\ 0 \\ g \end{bmatrix} \approx \begin{bmatrix} 0 \\ 0 \\ 9.81 \end{bmatrix} \text{ m/s}^2$$

By taking the expectation (temporal average) over $N$ static samples, the zero-mean noise terms $\vec{\eta}$ vanish:
$$\vec{b}'_\omega = E[\vec{\omega}'] = \frac{1}{N} \sum_{i=1}^{N} \begin{bmatrix} x'_i \\ y'_i \\ z'_i \end{bmatrix}$$

$$\vec{b}'_a = E[\vec{a}'] - \begin{bmatrix} 0 \\ 0 \\ g \end{bmatrix} = \left( \frac{1}{N} \sum_{i=1}^{N} \begin{bmatrix} acc'_{x, i} \\ acc'_{y, i} \\ acc'_{z, i} \end{bmatrix} \right) - \begin{bmatrix} 0 \\ 0 \\ 9.81 \end{bmatrix}$$

This yields the static bias parameters:
$$\text{acc\_bias\_x} = \bar{acc'}_x$$
$$\text{acc\_bias\_y} = \bar{acc'}_y$$
$$\text{acc\_bias\_z} = \bar{acc'}_z - 9.81$$
$$\text{ang\_bias\_x} = \bar{\omega'}_x$$
$$\text{ang\_bias\_y} = \bar{\omega'}_y$$
$$\text{ang\_bias\_z} = \bar{\omega'}_z$$

---

## 4. Dynamic Misalignment & Cross-Coupling Analysis

During the active rotation phase (State 2), the robot executes a pure yaw rotation around its kinematic vertical axis at commanded velocity $\Omega_z$.

### Cross-Coupling Projection
If the IMU sensor frame is perfectly aligned with the robot's physical rotation axis, the measured yaw-rate-corrected angular velocities around the $X$ and $Y$ base axes should be zero. Any non-zero mean values are caused by mechanical misalignment:
$$\bar{\omega}_{\text{rot}, x} = \left( \frac{1}{M} \sum_{j=1}^{M} x'_j \right) - \text{ang\_bias\_x}$$
$$\bar{\omega}_{\text{rot}, y} = \left( \frac{1}{M} \sum_{j=1}^{M} y'_j \right) - \text{ang\_bias\_y}$$
$$\bar{\omega}_{\text{rot}, z} = \left( \frac{1}{M} \sum_{j=1}^{M} z'_j \right) - \text{ang\_bias\_z}$$

The cross-coupling projection coefficients (or scaling factors) representing the projection of rotation from the $Z$-axis onto the $X$ and $Y$ base axes are computed as:
$$\text{ang\_z2x\_proj} = -\frac{\bar{\omega}_{\text{rot}, x}}{\bar{\omega}_{\text{rot}, z}}$$
$$\text{ang\_z2y\_proj} = -\frac{\bar{\omega}_{\text{rot}, y}}{\bar{\omega}_{\text{rot}, z}}$$

These projection coefficients allow point-cloud undistortion and state-estimation algorithms to compensate dynamically for sensor tilt errors relative to the robot's actual kinematic rotation axis.
