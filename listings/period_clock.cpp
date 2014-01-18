#include <iostream>
#include <chrono>
#include <ratio>

int main() {
    using std::chrono::system_clock;
    using std::chrono::steady_clock;
    using std::chrono::high_resolution_clock;

    std::cout << system_clock::period::num 
              << "/"
              << system_clock::period::den
              << std::endl;

    std::cout << steady_clock::period::num 
              << "/"
              << steady_clock::period::den
              << std::endl;
    
    std::cout << high_resolution_clock::period::num 
              << "/"
              << high_resolution_clock::period::den
              << std::endl;
}
