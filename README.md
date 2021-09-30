# YOLOv4-LibTorch
This is a YOLOv4 post-processing code based on pure libtorch API  

环境：  
CMake 3.13.2  
OpenCV 3.4.10 opencv-contrib-3.4.10  
torchvision-0.6.0  
LibTorch1.5.0-CPU  

用法：  
1、首先将CMakeLists.txt文件中的set(CMAKE_PREFIX_PATH "......")后的路径换成自己环境下的相应值。  
2、将yolo.h文件中的先验框、图片大小、类别三个参数改成自己的相应数据。  
3、主函数是main.cpp,里面有单独的图片检测和摄像头视频检测两部分

说明：
这是CPU版本的，GPU版的看这里：https://github.com/wsx000/YOLOv4-LibTorch-GPU  

20210930-更新：
注意 utils.cpp里第172行代码有问题，我比较懒，就先不改啦，具体怎么改可看 https://github.com/wsx000/YOLOv4-LibTorch-GPU-deployment/issues/2

另外，有关 libtorch 在 ROS 中编译不通过的问题的解决，可以看这个链接：
https://github.com/pytorch/pytorch/issues/49450#issuecomment-930285845

因为后来换研究方向了，这个bug 啥的就只在这里说下，目前太懒就先不改啦（懒得重新配置环境在测试了哈哈），祝各位在 ROS 的世界里快乐学习


