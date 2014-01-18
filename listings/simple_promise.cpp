#include <iostream>
#include <thread>
#include <future>

void promise_five(std::promise<int> p) {
    p.set_value(5);
}

int main() {
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::thread t(promise_five, std::move(p));

    std::cout << f.get() << std::endl;

    t.join();
}

