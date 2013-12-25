#include <iostream>
#include <thread>

void f() {
    std::cout << "f" << std::endl;
}

void g(int i) {
    std::cout << "g" << i << std::endl;
}

std::thread getf() {
    return std::thread(f);
}

std::thread getg() {
    std::thread t(g, 42);
    return t;
}

int main() {
    std::thread ft(getf());
    std::thread gt(getg());
    ft.join();
    gt.join();
}
