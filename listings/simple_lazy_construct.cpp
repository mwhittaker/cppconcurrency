#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

std::shared_ptr<std::vector<int>> p;

void square() {
    if (!p) {
        p.reset(new std::vector<int>(10, 42));
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
    square();
    std::cout << "p is " << p << std::endl;
    std::cout << "*p is " << *p << std::endl;
}
