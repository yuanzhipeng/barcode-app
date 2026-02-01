//
// Created by hebi on 2026/1/30.
//

#ifndef BARCODE_SYSTEM_SAFEQUEUE_H
#define BARCODE_SYSTEM_SAFEQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class safeQueue {
    public:
        void push(const T& item) {
            std::lock_guard<std::mutex> lock(mtx);
            q.push(item);
            cv.notify_one();
        }

        bool pop(T& item) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [&] { return !q.empty(); });
            item = q.front();
            q.pop();
            return true;
        }

    private:
        std::queue<T> q;
        std::mutex mtx;
        std::condition_variable cv;

};


#endif //BARCODE_SYSTEM_SAFEQUEUE_H