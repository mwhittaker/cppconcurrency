#include <iostream>
#include <chrono>
#include <ctime>

template <typename Clock>
void print_now() {
    std::cout << Clock::now().time_since_epoch().count() << std::endl;
}

int main() {
    print_now<std::chrono::system_clock>();
    print_now<std::chrono::steady_clock>();
    print_now<std::chrono::high_resolution_clock>();
}
