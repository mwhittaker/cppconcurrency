#include <iostream>
#include <future>

char throws_two() {
    throw 2;
}

int main() {
    std::future<char> f1 = std::async(throws_two);
    std::future<char> f2 = std::async(throws_two);
    std::packaged_task<char()> pt(throws_two);
    std::future<char> f3 = pt.get_future();
    pt();

    // catching async future
    try {
        f1.get();
    }
    catch (int e) {
        std::cerr << e << std::endl;
    }

    // waiting async future
    f2.wait();

    // catching packaged task future
    try {
        f3.get();
    }
    catch (int e) {
        std::cerr << e << std::endl;
    }
}
