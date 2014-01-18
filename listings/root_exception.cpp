#include <iostream>
#include <stdexcept>
#include <cmath>

template <typename Integral>
double sqrt(Integral i) {
    if (i < 0) {
        throw std::out_of_range("i < 0");
    }
    return std::sqrt(i);
}

int main() {
    std::cout << "sqrt(4):  " << sqrt(4) << std::endl;
    std::cout << "sqrt(-1): " << sqrt(-1) << std::endl;
}
