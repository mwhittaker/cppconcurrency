#include "scoped_thread.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace conc;

void f() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "bye!" << std::endl;
}

int main() {
    scoped_thread st{std::thread(f)};
    std::cout << "hi" << std::endl;
}
