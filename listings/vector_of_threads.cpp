#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>

int main() {
    auto f = [](uint i) -> void {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << i << std::endl;
    };
    
    std::vector<std::thread> threads;
    for (uint i = 0; i <= 20; ++i) {
        threads.push_back(std::thread(f,i));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::for_each(threads.begin(), threads.end(),
            std::mem_fn(&std::thread::join));

    std::cout << "bye!" << std::endl;
}
