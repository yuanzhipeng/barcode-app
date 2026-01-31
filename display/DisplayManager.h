//
// Created by hebi on 2026/1/30.
//
#include <opencv2/opencv.hpp>
#include "../core/SafeQueue.h"

#ifndef BARCODE_SYSTEM_DISPLAYMANAGER_H
#define BARCODE_SYSTEM_DISPLAYMANAGER_H


class DisplayManager {
    public:
        void start(SafeQueue<cv::Mat>& queue);
};


#endif //BARCODE_SYSTEM_DISPLAYMANAGER_H