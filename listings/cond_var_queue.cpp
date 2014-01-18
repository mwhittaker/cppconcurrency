#include "scoped_thread.h"
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::queue<int> data_queue;
std::mutex data_mutex;
std::condition_variable data_cv;

void push() {
    for (int i = 0; i <= 20; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock<std::mutex> lock(data_mutex);
        data_queue.push(i);
        data_cv.notify_one();
    }
}

void pop() {
    bool done = false;

    while (!done) {
        std::unique_lock<std::mutex> lock(data_mutex);
        data_cv.wait(lock, []{return !data_queue.empty();});
        int i = data_queue.front();
        data_queue.pop();
        lock.unlock();

        std::cout << i << std::endl;
        if (i == 20) {
            done = true;
        }
    }
}

int main() {
    conc::scoped_thread pusher{std::thread(push)}; 
    conc::scoped_thread popper{std::thread(pop)}; 
}
