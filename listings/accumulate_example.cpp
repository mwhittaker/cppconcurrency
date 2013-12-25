#include "conc_numeric.h"
#include <iostream>
#include <vector>
#include <chrono>

int main() {
    std::vector<int> v(100000000, 1);
        
    using std::chrono::duration_cast;
    using std::chrono::nanoseconds;
    typedef std::chrono::high_resolution_clock clock;

    auto start = clock::now();
    std::cout << conc::accumulate(v.begin(), v.end(), 0) << std::endl;
    auto end = clock::now();
    std::cout << duration_cast<nanoseconds>(end-start).count()/1000000 << "ns\n";
}
