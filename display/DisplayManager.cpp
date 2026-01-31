//
// Created by hebi on 2026/1/30.
//

#include "DisplayManager.h"
#include <thread>
extern "C" {
#include <disp.h>
}


void DisplayManager::start(SafeQueue<cv::Mat>& queue) {
    std::thread([&]() {
        cv::Mat frame;
        while (queue.pop(frame)) {
            cv::Mat showImage;
            if (frame.channels() == 1) {
                cv::cvtColor(input_image, rgb_img, COLOR_BGR2RGB);
            } else {
                showImage = frame;
            }
            disp_commit((char*)showImage.data, showImage.cols * showImage.rows * showImage.channels());
        }
    }).detach();
}