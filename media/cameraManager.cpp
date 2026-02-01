//
// Created by hebi on 2026/1/30.
//

#include "cameraManager.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>
extern "C" {
#include <disp.h>
#include <camera.h>
}


bool cameraManager::init(int width, int height, int rotate) {
    cam_width = width;
    cam_height = height;
    cam_rotate = rotate;


    if (rgbcamera_init(cam_width, cam_height, cam_rotate)) {
        std::cerr << "[CameraManager::init] rgbcamera_init failed!" << std::endl;
        return false;
    }

    if (disp_init(cam_width, cam_height)) {
        std::cerr << "[CameraManager] disp_init failed!" << std::endl;
        return false;
    }

    std::cout << "[CameraManager] Camera and display initialized." << std::endl;
    return true;
}

void cameraManager::start(SafeQueue<cv::Mat>& queue) {
    std::thread([this, &queue]() {
        char* buf = new char[cam_width * cam_height * 3];

        while (true) {
            if (rgbcamera_getframe(buf) == 0) {
                cv::Mat frame(cam_height, cam_width, CV_8UC3, buf);
                queue.push(frame.clone());
            }
        }
        delete[] buf;
    }).detach();
}


void CameraManager::deinit() {
    rgbcamera_exit();
    std::cout << "[CameraManager] Camera deinitialized!" << std::endl;
}