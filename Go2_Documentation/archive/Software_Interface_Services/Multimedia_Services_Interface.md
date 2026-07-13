# Multimedia Services Interface

This chapter will introduce how the application layer uses multimedia interfaces, including obtaining image data and video streaming data from the robot dog camera.
!!! note Note:
It is recommended to use a directed UDP interface for image transmission (or customize other general interfaces such as RTMP), and it is not recommended to use **DDS** (because DDS only transmits videos encoded with H264, and users still need to perform video decoding to obtain the final image). However, for photography, the DDS interface can be used to obtain 720P JPEG images.
!!!

![](https://doc-cdn.unitree.com/static/2023/10/12/e48e25f227694ef3bb60ad1a71a6b6ad_8000x4500.png)

# Interface Description

**JPEG photography service interface**

Using this interface, the sender sends a photo request and then receives a response, which is a JPEG photo. The specific practice is achieved through the VideoClient class, which is a client provided by the Video service. The VideoClient class can obtain Go2 images through RPC.

**H264 image transmission service interface**

On the receiving end, if you need to directly view the image transmission video stream, you can enter the following command in the**command line**:

  ```C++
    gst-launch-1.0 udpsrc address=230.1.1.1 port=1720 multicast-iface=<interface_name> ! queue !  application/x-rtp, media=video, encoding-name=H264 ! rtph264depay ! h264parse ! avdec_h264 ! videoconvert ! autovideosink
```

Among them, 230.1.1.1 is a multicast address <interface_name> is the name of the network interface where the user's host connects to Go2, such as eth0.Set it to `multicast-iface=eth0`.

Currently, only UDP is supported, and support for other image transmission protocols will be added in the future.
The video frame rate is 15Hz. The camera resolution is 1280*720, with a horizontal Angle of view of 100 degrees and a vertical Angle of view of 56 degrees.

# JPEG photography service interface

## VideoClient Class

List of interface error codes:

Currently unavailable

Class and interface description:

|Class Name | Construction and Deconstruction|
|:---: | :---|
|  VideoClient  | VideoClient::~VideoClient() |

|**Function Name**|**GetImageSample**|
|:---: | :---|
|**Function Prototype**| int32_t GetImageSample(std::vector<uint8_t>& image_sample)  |
|**Function Overview**| Get Photos|
|**Parameters**|**image_ Sample**: photo content|
|**Return Value**| If the call is successful, 0 will be returned. Otherwise, relevant error codes will be returned|
|**Remarks**||

## Cases

This case demonstrates how to obtain and save images through the JPEG photography service interface.

``` C++
#include <unitree/robot/go2/video/video_client.hpp>
#include <iostream>
#include <fstream>
#include <ctime>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
      std::cout << "Usage: " << argv[0] << " networkInterface" << std::endl;
      exit(-1);
    }
    unitree::robot::ChannelFactory::Instance()->Init(0, argv[1]);
    //argv [1]  is network interface of the robot
  
    unitree::robot::go2::VideoClient video_client;

    /*
     * Set request timeout 1.0s
     */
    video_client.SetTimeout(1.0f);
    video_client.Init();

    //Test Api

    std::vector<uint8_t> image_sample;
    int ret;

    while (true)
    {
        ret = video_client.GetImageSample(image_sample);

        if (ret == 0) {
            time_t rawtime;
            struct tm *timeinfo;
            char buffer[80];

            time(&rawtime);
            timeinfo = localtime(&rawtime);

            strftime(buffer, sizeof(buffer), "%Y%m%d%H%M%S.jpg", timeinfo);
            std::string image_name(buffer);

            std::ofstream image_file(image_name, std::ios::binary);
            if (image_file.is_open()) {
                image_file.write(reinterpret_cast<const char*>(image_sample.data()), image_sample.size());
                image_file.close();
                std::cout << "Image saved successfully as " << image_name << std::endl;
            } else {
                std::cerr << "Error: Failed to save image." << std::endl;
            }
        }

        sleep(3);
    }

    return 0;
}
``` 

# H264 image transmission service interface

It is recommended to use Gst's directed UDP interface for image transmission. If you plan to use Gst for streaming, you can refer to the following content to implement using Gst for streaming in OpenCV.

Gst supports embedding OpenCV's VideoCapture function for streaming using the Gst pipeline method. At the same time, it also supports embedding in the **VideoWriter** function to push streams in a Gst pipeline manner.

## Dependency related

### Gst installation

Install in Ubuntu Linux environment:

```C++
    sudo apt-get install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-plugins-bad1.0-dev gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-tools gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio
```
!!! note  Note:
 For Windows environments, please refer to the official documentation: [https://gstreamer.freedesktop.org/documentation/installing/on-windows.html?gi-language=c](https://gstreamer.freedesktop.org/documentation/installing/on-windows.html?gi-language=c)
!!!

### OpenCV Compilation

!!! note Help
If you are unable to use the CMake GUI, encounter issues with configuration, or need to use python, you can refer to the [Help Center](https://global-serviceconsole.unitree.com/#/help/030102) for instructions on installing using the command-line compilation method.
!!!

To achieve the above functions, it is necessary to check the**WITH\_GSTREAMER**option when compiling OpenCV. Please refer to the following steps for the OpenCV source code compilation process:

1. Download OpenCV4.1.1 source code from Github [https://github.com/opencv/opencv/tree/4.1.1](https://github.com/opencv/opencv/tree/4.1.1)

2. Installation

``` C++
mkdir build              
cd build
cmake-gui ..
 

####At this point, enter the GUI dialog box
####Click on configure
####Check with cuda and with Gstreamer
####Click on configure again
####Then click on 'generate'
####Close GUI dialog box 

make 
sudo make install
``` 
3. In OpenCV, you can view the compilation status of OpenCV by calling the getBuildInformation function, as follows:

``` C++
#include <opencv2/opencv.hpp>

int main(void)
{
  std::cout << cv::getBuildInformation() << std::endl;
}
``` 
4. By running the above function, you can obtain the following output, where in Video I/O, you can check whether the Gstreamer option is turned on.

![](https://doc-cdn.unitree.com/static/2023/8/8/9e8da0c99c53459985ae715b3b2d7b7a_707x245.png)

![](https://doc-cdn.unitree.com/static/2023/8/8/4af46daae113422ca1ff2233ca4bacc7_756x212.png)

## Video streaming

The **VideoCapture** class of OpenCV supports video files, image sequences, or cameras as input to obtain data. By calling the following **VideoCapture** constructor, you can pull the USB camera data stream:

``` C++
cv::VideoCapture::VideoCapture(const String & filename,int apiPreference)	
``` 

|Variable | Description|
|:---: | :---|
|**filename**| This parameter can be of the following types: <br> * Video file path; <br> * Image sequence, for example, the image sequence name is image\_00.jpg, image\_01.jpg, image\_02.jpg, it can be set to image\_%02d.jpg ; <br>* The URL of the video stream, for example:rtsp://admin@password:192.168.170.XXX; <br>The **pipeline string** of Gstreamer, which can be tested for usability using **gst-launch-1.0**;|
|**apiReference**| What backend does the Capture API use, including CAP\_GSTREAMER or CAP\_FFMPEG or CAP\_IMAGES or CAP\_DSHOW et al|

## Reference Cases

If you use C++, you can refer to the following code

``` C++
#include <opencv2/opencv.hpp>
using namespace cv;

#include <iostream>
using namespace std;

int main()
{

  VideoCapture cap("udpsrc address=230.1.1.1 port=1720 multicast-iface=<interface_name> ! application/x-rtp, media=video, encoding-name=H264 ! rtph264depay ! h264parse ! avdec_h264 ! videoconvert ! video/x-raw,width=1280,height=720,format=BGR ! appsink drop=1", 
            CAP_GSTREAMER);
    
  if (!cap.isOpened()) {
        cerr <<"VideoCapture not opened"<<endl;
        exit(-1);
    }
    
    while (true) {

        Mat frame;

        cap.read(frame);

        imshow("receiver", frame);

        if (waitKey(1) == 27) {
            break;
        }
    }

    return 0;
}
``` 
If you are using Python, you can refer to the following code:
``` Python
import cv2
gstreamer_str = "udpsrc address=230.1.1.1 port=1720 multicast-iface=<interface_name> ! application/x-rtp, media=video, encoding-name=H264 ! rtph264depay ! h264parse ! avdec_h264 ! videoconvert ! video/x-raw,width=1280,height=720,format=BGR ! appsink drop=1"
cap = cv2.VideoCapture(gstreamer_str, cv2.CAP_GSTREAMER)
while(cap.isOpened()):
    ret, frame = cap.read()
    if ret:
        cv2.imshow("Input via Gstreamer", frame)
        if cv2.waitKey(25) & 0xFF == ord('q'):
            break
    else:
        break
cap.release()
cv2.destroyAllWindows()
```
