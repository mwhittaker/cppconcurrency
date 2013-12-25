#include <iostream>
#include <thread>

struct background_task {
    int x_;
    background_task(int x): x_(x) {}
    void operator()() const {
        std::cout << "Hello from background_task " << x_ << std::endl;
    }
};

int main() {
    background_task b1(1);
    std::thread t1(b1);                   // explicit initialization
    std::thread t2((background_task(2))); // extra parentheses
    std::thread t3{background_task(3)};   // uniform initialization

    t1.join();
    t2.join();
    t3.join();
}
