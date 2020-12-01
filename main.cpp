#include <iostream>
#include "opencv2/opencv.hpp"
#include "torch/script.h"
#include "string"
#include "vector"
#include "ATen/Parallel.h"
#include "yolo.h"
#include <iomanip>
#include "chrono"

using namespace std;
using namespace std::chrono;

int main()
{
    // cout<<setiosflags(ios::fixed)<<setprecision(10);
    // int num_threads = at::get_num_interop_threads();
    // cout << "num threads:" << num_threads << endl;
    // at::set_num_threads(num_threads/2);
    // at::set_num_interop_threads(num_threads/2);
    // at::init_num_threads();
    const char* imgPath = "/home/wsx/code/YOLOv4/y4-libtorch-V1-20201120/62.jpg";
    const char* modulePath = "/home/wsx/code/YOLOv4/y4-libtorch-V1-20201120/model-traced.pt";
    // 加载模型
    YOLO yolo(modulePath);

    /*=====================================单张图片========================================*/
    // auto start = high_resolution_clock::now();
    // // 读取图片
    // cv::Mat image = cv::imread(imgPath);
    // // 前向传播并推理，输出结果为：n * (ymin, xmin, ymax, xmax, conf, class) 的数组
    // vector<vector<float>> out_boxes = yolo.detect_image(image);
    // // 记录结束时间
    // auto end = high_resolution_clock::now();
    // auto duration = duration_cast<milliseconds>(end - start);
    // cout << "inference takes：" << duration.count() << "ms" << endl;
    // yolo.draw_rectangle(out_boxes, image);
    /*===================================================================================*/

    /*=====================================视频检测========================================*/
    // 打开摄像头
    cv::VideoCapture cap(0);
    while (1)
    {
        // 读取视频帧
        cv::Mat frame;
        // 读取摄像头
        cap >> frame;
        // 记录开始时间
        auto start = high_resolution_clock::now();
        // 前向传播并推理，输出结果为：n * (ymin, xmin, ymax, xmax, conf, class) 的数组
        vector<vector<float>> out_boxes = yolo.detect_image(frame);
        // 记录结束时间
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "inference takes：" << duration.count() << "ms" << endl;

        yolo.draw_rectangle(out_boxes, frame);
    }
    cap.release();
    cv::destroyAllWindows();
    /*===================================================================================*/


    return 0;
}
