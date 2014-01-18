#include "scoped_thread.h"
#include <iostream>
#include <string>
#include <future>

using std::cout;
using std::endl;
using std::string;

void f(int thread_num, std::shared_future<std::string> sf) {
    cout << "thread" << thread_num << ": " << sf.get() << endl;
}

int main() {
    auto hi = []() -> string {return "hi";};
    std::shared_future<std::string> sf = std::async(hi);
    conc::scoped_thread t1{std::thread(f, 1, sf)};
    conc::scoped_thread t2{std::thread(f, 2, sf)};
    conc::scoped_thread t3{std::thread(f, 3, sf)};
    conc::scoped_thread t4{std::thread(f, 4, sf)};
}

