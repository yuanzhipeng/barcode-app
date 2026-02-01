//
// Created by hebi on 2026/1/30.
//

#include "displayManager.h"
#include <thread>
#include <opencv2/opencv.hpp>
extern "C" {
#include <disp.h>
}


void displayManager::start(safeQueue<cv::Mat>& queue) {
    std::thread([&queue]() {
        cv::Mat frame;
        while (queue.pop(frame)) {
            cv::Mat showImage;
            if (frame.channels() == 1) {
                cv::cvtColor(frame, showImage, COLOR_BGR2RGB);
            } else {
                showImage = frame;
            }
            disp_commit((char*)showImage.data, showImage.cols * showImage.rows * showImage.channels());
        }
    }).detach();
}