#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <thread>
#include <mutex>

std::shared_ptr<std::vector<int>> p;
std::mutex p_m;

void square() {
    if (!p) {
        std::unique_lock<std::mutex> lock(p_m);
        if (!p) {
            p.reset(new std::vector<int>(100, 42));
        }
    }

    std::for_each(p->begin(), p->end(), [](int& i) {i *= i;});
}

std::ostream& operator<<(std::ostream& os, std::vector<int> v) {
    os << "[";
    for (auto p = v.begin(); p != v.end(); ++p) {
        os << *p << (p == v.end() - 1 ? "" : ",");
    }
    os << "]";

    return os;
}

int main() {
    std::cout << "p is " << p << std::endl;

    std::thread t1(square);
    std::thread t2(square);
    t1.join();
    t2.join();

    std::cout << "p is " << p << std::endl;
    std::cout << "*p is " << *p << std::endl;
}
