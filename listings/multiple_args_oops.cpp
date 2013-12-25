#include <iostream>
#include <thread>
#include <cstdio>
#include <chrono>

void f(int i, const std::string& s) {
    std:: cout << i << s << std::endl;
}

void oops() {
    char buffer[1024];
    sprintf(buffer, "%i", 42);
    std::thread(f, 42, buffer).detach();
}

int main() {
    oops();
}
