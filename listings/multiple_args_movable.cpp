#include <iostream>
#include <thread>
#include <memory>

void foo(std::unique_ptr<int> ip) {
    (*ip)++;
    std::cout << *ip << std::endl;
}

int main() {
    std::thread t1(foo, std::unique_ptr<int>(new int(42)));

    std::unique_ptr<int> ip(new int(0));
    std::thread t2(foo, std::move(ip));

    t1.join();
    t2.join();
}
