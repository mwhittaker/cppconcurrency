#include <iostream>
#include <future>
#include <thread>
#include <chrono>

int get_five() {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 5;
}

int main() {
    std::future<int> five = std::async(get_five);
    std::cout << "patience is a virtue" << std::endl;
    std::cout << five.get() << std::endl;
}
