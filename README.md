# YOLOv4-LibTorch
This is a YOLOv4 post-processing code based on pure libtorch API

Environment：
CMake 3.13.2
OpenCV 3.4.10 opencv-contrib-3.4.10
torchvision-0.6.0
LibTorch1.5.0-CPU

英文不太行就直接中文简单说下用法：  
1、首先将CMakeLists.txt文件中的set(CMAKE_PREFIX_PATH "......")后的路径换成自己环境下的相应值。  
2、将yolo.h文件中的先验框、图片大小、类别三个参数改成自己的相应数据。
3、主函数是main.cpp,里面有单独的图片检测和摄像头视频检测两部分

