#include <iostream>
#include <thread>
#include <future>

void promise_cin(std::promise<int> p) {
    int i;
    std::cin >> i;
    p.set_value(i);
}

int main() {
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::thread t(promise_cin, std::move(p));

    std::cout << "waiting for the future!" << std::endl;
    std::cout << "future: " << f.get() << std::endl;

    t.join();
}

