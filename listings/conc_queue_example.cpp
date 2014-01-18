#include "scoped_thread.h"
#include "conc_queue.h"
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp> 

using boost::multiprecision::cpp_int;

namespace {
    conc::queue<cpp_int> numbers;

    std::mutex cout_mutex;

    const int hw_conc = std::thread::hardware_concurrency();
    const int num_threads = (hw_conc == 0) ? 2 : hw_conc - 1;
    const int killnum = -1;
}

std::string get_factors(cpp_int n) {
    cpp_int factor = 2;
    std::string factors = "";

    if (n < 0) {
        n *= -1;
    }

    while (factor * factor <= n) {
        if (n % factor == 0) {
            factors += boost::lexical_cast<std::string>(factor);
            factors += " ";
            n /= factor;
        }
        else {
            ++factor;
        }
    }

    if (n > 1) {
        factors += boost::lexical_cast<std::string>(n);
    }

    return factors;
}

void push() {
    cpp_int i;
    while (std::cin >> i) {
        if (killnum == i) {
            for (int j = 0; j < num_threads; ++j) {
                numbers.push(killnum);
            }
            return;
        }
        numbers.push(i);
    }
}

void pop() {
    while (true) {
        cpp_int i = *(numbers.wait_pop());
        if (killnum == i) {
            return;
        }

        std::lock_guard<std::mutex> cout_lock(cout_mutex);
        std::cout << i << ": " << get_factors(i) << std::endl;
    }
}

int main() {
    conc::scoped_thread pusher{std::thread(push)};
    
    std::vector<std::thread> poppers;
    for (int i = 0; i < num_threads; ++i) {
        poppers.push_back(std::thread(pop));
    }
    std::for_each(poppers.begin(), poppers.end(), std::mem_fn(&std::thread::join));
}
