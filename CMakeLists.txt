cmake_minimum_required(VERSION 3.1)
project(test1)

# set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH "/usr/local/lib;/home/wsx/LibTorch/libtorch150cpu/libtorch;/home/wsx/LibTorch/libtorch150cpu/torchvision060/torchvision")
set(CMAKE_BUILD_TYPE "Release")
# set(WITH_TIFF "ON")  # opencv
# set(BUILD_TIFF "ON")  # opencv
# set(CMAKE_BUILD_TYPE "Debug")

find_package(Torch REQUIRED)
find_package(OpenCV REQUIRED)
find_package(TorchVision REQUIRED)

if(NOT Torch_FOUND)
    message(FATAL_ERROR "Pytorch not found!")
endif(NOT Torch_FOUND)

if(NOT OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV not found!")
endif(NOT OpenCV_FOUND)


add_executable(yolov4 main.cpp utils.cpp utils.h yolo.cpp yolo.h)
target_link_libraries(yolov4 PUBLIC ${TORCH_LIBRARIES} ${OpenCV_LIBS} TorchVision::TorchVision)
set_property(TARGET yolov4 PROPERTY CXX_STANDARD 14)


# add_executable(test1 ./test/test.cpp)
# target_link_libraries(test1 PUBLIC ${TORCH_LIBRARIES} ${OpenCV_LIBS} TorchVision::TorchVision)
# set_property(TARGET test1 PROPERTY CXX_STANDARD 14)
