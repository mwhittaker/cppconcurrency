#include "scoped_thread.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <chrono>
#include <memory>
#include <thread>
#include <future>
#include <cwctype>

using std::cout;
using std::endl;

std::queue<std::packaged_task<void()>> tasks;
std::mutex tasks_mutex;
bool done;

void print() {
    while (!done) {
        std::string l;
        std::getline(std::cin, l);
        l.erase(remove_if(l.begin(), l.end(), std::iswspace), l.end());
        std::sort(l.begin(), l.end());
        std::cout << l << std::endl;
        
        std::packaged_task<void()> task;
        {
            std::lock_guard<std::mutex> tasks_lock(tasks_mutex);
            if (tasks.empty()) {
                continue;
            }
            task = std::move(tasks.front());
            tasks.pop();
        }
        task();
    }
}

int main() {
    conc::scoped_thread printer{std::thread(print)};

    tasks.push(std::packaged_task<void()>([]{cout << "task 1" << endl;}));
    tasks.push(std::packaged_task<void()>([]{cout << "hello!" << endl;}));
    tasks.push(std::packaged_task<void()>([]{done = true;}));
}
