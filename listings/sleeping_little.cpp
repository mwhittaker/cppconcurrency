#include "scoped_thread.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

bool flag;
std::mutex flag_mutex;

void wait() {
    std::unique_lock<std::mutex> lock(flag_mutex);
    
    while (!flag) {
        std::cout << "unlocking mutex" << std::endl;
        lock.unlock();

        std::cout << "sleeping" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
        std::cout << "locking mutex" << std::endl;
        lock.lock();
    }

    std::cout << "done!" << std::endl;
}

void set() {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::lock_guard<std::mutex> lock(flag_mutex);
    flag = true;
}

int main() {
    conc::scoped_thread waiter{std::thread(wait)};
    conc::scoped_thread setter{std::thread(set)};
}
