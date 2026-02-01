//
// Created by hebi on 2026/1/30.
//

#include "app.h"
#include <iostream>

#define CAMERA_WIDTH	720
#define CAMERA_HEIGHT	1280

bool app::init() {

    if (!camera.init(CAMERA_WIDTH, CAMERA_HEIGHT, 270)) {
        std::cout << "[App] Camera init failed." << std::endl;
        return false;
    }

    std::cout << "[App] Camera init success." << std::endl;
    return true;
}

void app::run() {

    // 启动摄像头采集县城
    camera.start(frameQueue);

    display.start(frameQueue);

    // 业务主线程: 从识别结果列队取条码并比对价格
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}