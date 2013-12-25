#include <iostream>
#include <thread>

void f(int& i) {
    ++i;
}

int main() {
    int i = 0;
    std::thread t(f, std::ref(i));
    t.join();
    std::cout << i << std::endl;
}
