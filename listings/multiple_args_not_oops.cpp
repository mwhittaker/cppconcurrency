#include <iostream>
#include <string>
#include <thread>
#include <cstdio>

void f(int i, const std::string& s) {
    std:: cout << i << s << std::endl;
}

void not_oops() {
    char buffer[1024];
    sprintf(buffer, "%i", 42);
    std::thread(f, 42, std::string(buffer)).detach();
}

int main() {
    not_oops();
}
