#include "scoped_thread.h"
#include <iostream>
#include <thread>
#include <future>

using conc::scoped_thread;

void promise_cin(std::promise<int> ip, std::promise<std::string> sp) {
    int i;
    std::string tmp;
    std::string s;

    std::cout << "> [num] [string]" << std::endl << "> ";
    std::cin >> i >> tmp;
    for (int j = 0; j < i; ++j) {
        s += tmp;
    } 

    ip.set_value(i);
    sp.set_value(s);
}

int main() {
    std::promise<int> ip;
    std::promise<std::string> sp;
    std::future<int> ifut = ip.get_future();
    std::future<std::string> sfut = sp.get_future();

    scoped_thread t{std::thread(promise_cin, std::move(ip), std::move(sp))};

    std::cout << "i: " << ifut.get() << std::endl;
    std::cout << "s: " << sfut.get() << std::endl;
}

