#include "conc_stack.h"
#include "scoped_thread.h"
#include <iostream>
#include <thread>

int main() {
    conc::stack<int> s;
    for (int i = 0; i <= 1000000; ++i) {
        s.push(i);
    }

    auto f = [](conc::stack<int>& s) -> void {
        while (!s.empty()) {
            s.pop(); // an exception can still be thrown
        }
    };

    conc::scoped_thread st1{std::thread(f, std::ref(s))};
    conc::scoped_thread st2{std::thread(f, std::ref(s))};
}
