#include "zipped_stream.h"
#include "scoped_thread.h"
#include <iostream>
#include <thread>

void print(int i) {
    for (int j = 0; j < 1; ++j) {
        conc::zstream() << "t"
                        << "h"
                        << "r"
                        << "e"
                        << "a"
                        << "d"
                        << " "
                        << i 
                        << ":"
                        << " "
                        << "h"
                        << "e"
                        << "l"
                        << "l"
                        << "o"
                        << "!" 
                        << std::endl; 
    }
}

int main() {
    conc::scoped_thread t1{std::thread(print, 1)};
    conc::scoped_thread t2{std::thread(print, 2)};
    conc::scoped_thread t3{std::thread(print, 3)};
    conc::scoped_thread t4{std::thread(print, 4)};
    conc::scoped_thread t5{std::thread(print, 5)};
}
