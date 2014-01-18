#include <iostream>
#include <chrono>
#include <vector>
#include <thread>

using std::cout;
using std::endl;
using std::chrono::high_resolution_clock;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::duration_cast;

int main() {
    auto f = []() -> void {
        std::this_thread::sleep_for(seconds(1));
    };

    auto start = high_resolution_clock::now();
    f();
    auto stop  = high_resolution_clock::now();

    auto time = duration_cast<milliseconds>(stop - start).count();
    std::cout << time << " milliseconds" << std::endl;
}
