#include <iostream>
#include <thread>

int main() {
    std::thread t([]() -> void {std::cout << "hi" << std::endl;});
    t.join();
}
