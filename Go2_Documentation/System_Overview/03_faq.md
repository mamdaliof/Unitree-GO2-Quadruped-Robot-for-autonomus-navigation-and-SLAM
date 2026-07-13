# Developer FAQ & Environment Troubleshooting

This document compiles common developer questions, compiling issues, dependency setups, and hardware quirks of the Go2.

---

## 1. Reference Links to Archive Sources
For the raw FAQ document, refer to the archived file:
* [[Go2_Documentation/archive/FAQ|Raw FAQ Guide]]

---

## 2. Compilation & Library Link Failures

### `cmake` Command Not Found
* **Cause:** The CMake build utility is not installed.
* **Fix:**
  ```bash
  sudo apt update
  sudo apt install -y cmake
  ```

### CXX Compiler Not Found
* **Cause:** The C++ compiler toolchain is missing.
* **Fix:**
  ```bash
  sudo apt update
  sudo apt install -y build-essential
  ```

### OpenCV Headers Link Error (`fatal error: opencv2/opencv.hpp: No such file...`)
* **Cause:** CMake fails to locate OpenCV4 headers because they reside under `/usr/include/opencv4/opencv2/` rather than the standard `/usr/include/opencv2/`.
* **Fix:** Create a soft symbolic link (soft-link) in your include directory:
  ```bash
  sudo ln -s /usr/include/opencv4/opencv2 /usr/include/
  ```

### PyTorch OpenBLAS Missing (`libopenblas.so.0: cannot open shared object...`)
* **Cause:** Missing math libraries required by PyTorch and Isaac Gym.
* **Fix:** Install the BLAS and algebra runtime dependencies:
  ```bash
  sudo apt update
  sudo apt install -y libopenblas-dev gfortran
  ```

---

## 3. Onboard Operating & Power-On Quirks

### Legs Out of Position on Power-On
* **Cause:** The Go2 does **not** support being powered on while suspended or hanging in a rack. The joint encoders calibrate absolute zero relative to the stance ground compression during boot.
* **Fix:** Always place the robot on flat ground in its natural lying-down stance before pressing the power button.

### Permission Denied Executing SDK Binaries
* **Cause:** Compiled binaries lack execution flags, or network interfaces require root access.
* **Fix:** Make executable and launch with sudo:
  ```bash
  chmod +x your_binary
  sudo ./your_binary [network_card]
  ```

---

## 4. Hardware Telemetry & Performance Questions

### What is the communication frequency of the SDK?
The Go2 low-level motor FOC loop operates at **500 Hz** over CycloneDDS. The high-level sports client locomotion interface also accepts velocity commands at **500 Hz**.

### Foot Sensor Value Drift
* **Cause:** The foot force sensors (only on EDU models) experience temperature-induced electrical drift.
* **Fix:** Implement software filters or calibrating thresholds in your controllers to reject low-force reading drift when the leg is fully extended.

---

## 5. Project Relevance
* **Compiling Pipelines:** This troubleshooting list helps us configure our CI/CD pipelines and setup scripts (like installing `libopenblas-dev` and soft-linking `opencv2`) on the Jetson NX developer PC.
