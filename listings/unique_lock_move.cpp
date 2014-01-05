#include <iostream>
#include <mutex>

std::mutex m;

std::unique_lock<std::mutex> get_lock() {
    std::unique_lock<std::mutex> lock(m);
    std::cout << "got lock" << std::endl;
    return lock;
}

int main() {
    std::unique_lock<std::mutex> lock(get_lock());
    std::cout << "main" << std::endl;
}
