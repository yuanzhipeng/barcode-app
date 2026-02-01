//
// Created by hebi on 2026/1/30.
//

#ifndef BARCODE_SYSTEM_APP_H
#define BARCODE_SYSTEM_APP_H


#include <opencv2/opencv.hpp>
#include "CameraManager.h"
#include "DisplayManager.h"
#include "SafeQueue.h"

class App {
    public:
        // 初始化摄像头、队列等
        bool init();
        // 启动线程&业务主循环
        void run();


    private:
        CameraManager camera;   // 摄像头采集
        DisplayManager display;
        SafeQueue<cv::Mat> frameQueue;  //图像帧队列，线程安全
};


#endif //BARCODE_SYSTEM_APP_H