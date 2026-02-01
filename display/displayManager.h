//
// Created by hebi on 2026/1/30.
//
#include <opencv2/opencv.hpp>
#include "safeQueue.h"

#ifndef BARCODE_SYSTEM_DISPLAYMANAGER_H
#define BARCODE_SYSTEM_DISPLAYMANAGER_H


class displayManager {
    public:
        void start(safeQueue<cv::Mat>& queue);
};


#endif //BARCODE_SYSTEM_DISPLAYMANAGER_H