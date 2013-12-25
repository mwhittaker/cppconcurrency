#include <iostream>
#include <thread>

int main() {
    std::thread t([]() -> void {});
    t.join();
    std::cout << "t is joinable? " << t.joinable() << std::endl;
}
