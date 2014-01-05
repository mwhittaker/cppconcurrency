#include "hierarchical_mutex.h"
#include "scoped_thread.h"
#include <iostream>
#include <thread>
#include <mutex>

conc::hierarchical_mutex high_m(1000000);
conc::hierarchical_mutex medium_m(1000);
conc::hierarchical_mutex low_m(1);

void high_f();
void medium_f();
void low_f();

void high_f() {
    std::lock_guard<conc::hierarchical_mutex> lock(high_m);
    std::cout << "high" << std::endl;
    medium_f();
}

void medium_f() {
    std::lock_guard<conc::hierarchical_mutex> lock(medium_m);
    std::cout << "medium" << std::endl;
    low_f();
}

void low_f() {
    std::lock_guard<conc::hierarchical_mutex> lock(low_m);
    std::cout << "low" << std::endl;
}

int main() {
    conc::scoped_thread high_t{std::thread(high_f)};
}
