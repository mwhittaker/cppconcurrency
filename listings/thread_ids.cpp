#include <iostream>
#include <thread>

int main() {
    auto print_id = []() -> void {
        std::cout << std::this_thread::get_id() << std::endl;
    };

    std::thread t(print_id);
    t.join();
    print_id();
}
