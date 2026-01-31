//
// Created by hebi on 2026/1/30.
//

#include <opencv2/opencv.hpp>
#include "../core/SafeQueue.h"
#include <thread>

#ifndef BARCODE_SYSTEM_CAMERAMANAGER_H
#define BARCODE_SYSTEM_CAMERAMANAGER_H


class cameraManager {
    public:
        bool init(int width, int height, int rotate);
        void start(SafeQueue<cv::Mat>& queue);
        void deinit();

    private:
        int cam_width;
        int cam_height;
        int cam_rotate;
};


#endif //BARCODE_SYSTEM_CAMERAMANAGER_H