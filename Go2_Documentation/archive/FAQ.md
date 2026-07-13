# FAQ

# FAQ

## If you encounter a log related to Permission denied
1. Check the execution permissions of the file you are operating on, and change them with `chmod` .
1. Use `sudo` to execute permissions.

## How can I solve the problem when the dog is hung up and turned on but the legs are not in the right position?
The Go2 does not support hanging and powering on, it must be placed in the initial position before powering on.

## When Go2 turns on the obstacle avoidance function, does it go around the obstacle or stop the obstacle?
Currently there are 2 effects, the algorithm will automatically recognize the width of the obstacle, if it is too wide to avoid the obstacle, it will stop, if it is too narrow, it will go around it by itself.

## Command 'cmake' not found
The reason is command 'cmake' is not installed.You can follow this
    
  ```
  sudo apt install -y cmake
  ```

## No CMAKE CXX COMPILER Could be found.
  A: The compilation toolchain is missing from the environment.
  ```
  sudo apt-get install -y build-essential
  ```
## Opencv4 is already installed, but when compiling with cmake, cmake can also find opencv4, but the compilation reports error: fatal error: opencv2/opencv.hpp: No such file or directory #include <opencv2/opencv. hpp>
  This is because there is an extra opencv4 folder in the path of the opencv header file: `/usr/include/opencv4/opencv2`, we suggest to take the way 2.
  1. Copy opencv2 into your own include folder.
  2. Copy opencv2 to your own include folder, and soft-link opencv2 to your include folder.
  ```
  sudo ln -s /usr/include/opencv4/opencv2 /usr/include/
  ```
 ## What version of Go2 can be developed? /Differences in development capabilities between Go2 versions/Why can't I develop on my Go2?
Only EDU or above versions can be developed, other versions such as PRO and AIR versions do not open the secondary development interface, EDU version can be equipped with **40tops** or **100tops** docking station for development, you can refer to the reference document for details about Go2 [About Go2](https://support.unitree.com/home/en/developer/about%20Go2), and for development capabilities, see [Docking Station Configuration](https://support.unitree.com/home/en/developer/module_update).
    
## What do I need to prepare for development? /# Development environment requirements? /How to develop Go2?
Before development, you need to prepare a Linux system computer or virtual machine, and the system version needs to be **Ubuntu20.04**, you can refer to the document [Quick Start](https://support.unitree.com/home/en/developer/Quick_start) for specific development.
    
## Does Go2 support wireless development?
No, Go2 only supports wired connection for development.
  
## What is the low-level communication frequency of Go2 SDK?
Go2 SDK currently has 500hz communication frequency for low level, and 500hz for high level service interface.
  
## What development interfaces does Go2 support?
Go2 EDU version currently only provides SDK interface, no other standard function modules need to be combined with the computer and docking station development, the official standard module can refer to [About Go2](https://support.unitree.com/home/en/developer/about%20Go2).
  
## What is the resolution of the Go2 camera?
The head camera has 1080P(HD) 30fps or 720p 60fps HD recording capability with F2.2 aperture and 120° field of view. App HD transmission is available, and the camera can ensure smooth 720p 60fps HD transmission in a non-interference and unobstructed environment.

## What to pay attention to the development of foot sensor for Go2
The data of the foot sensor development has the characteristic of drift, so you need to consider the error situation when developing your own screening.

## Are there any remote software tools to recommend?

The official docking station has built-in nomachine, but when using it because there is no monitor, you need to log in to the docking station via SSH in advance and execute the nomachine.sh script in the home directory, so that you can use the nomachine remote tool normally.

## After installing pytorch, an ImportError appears when using it: libopenblas.so.0: cannot open shared object file: No such file or directory

Relevant dependent libraries are missing, install relevant dependent libraries
```language
sudo apt-get -y install autoconf bc build-essential g++-8 gcc-8 clang-8 lld-8 gettext-base gfortran-8 iputils-ping libbz2-dev libc++-dev libcgal-dev libffi-dev libfreetype6-dev libhdf5- dev libjpeg-dev liblzma-dev libncurses5-dev libncursesw5-dev libpng-dev libreadline-dev libssl-dev libsqlite3-dev libxml2-dev libxslt-dev locales moreutils openssl python-openssl rsync scons python3-pip libopenblas-dev
```
## More Questions
For more questions, you can also refer to the [Help Center](https://serviceconsole.unitree.com/#/help/0311)
