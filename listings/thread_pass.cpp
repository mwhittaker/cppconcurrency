#include <iostream>
#include <thread>

void join(std::thread t) {
    t.join();
}

int main() {
    join(std::thread([]() -> void {std::cout << "hi" << std::endl;}));
    std::thread t([]() -> void {std::cout << "bye" << std::endl;});
    join(std::move(t));
}
