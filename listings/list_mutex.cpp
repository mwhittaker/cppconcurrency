#include "scoped_thread.h"
#include <iostream>
#include <algorithm>
#include <list>
#include <thread>
#include <mutex>

std::list<int> l;
std::mutex l_mutex;

void add_to_list(int v) {
    std::lock_guard<std::mutex> guard(l_mutex);
    std::cout << "adding " << v << std::endl;
    l.push_back(v);
}

bool list_contains(int v) {
    std::lock_guard<std::mutex> guard(l_mutex);
    return std::find(l.begin(), l.end(), v) != l.end();
}

int main() {
    auto add = []() -> void {
        for (int i = 0; i < 100; ++i) {
            add_to_list(i);
        }
    };
    conc::scoped_thread st{std::thread(add)};

    for (int i = 90; i < 100; ++i) {
        std::cout << "l has " << i << "? " << list_contains(i) << std::endl; 
    }
}
