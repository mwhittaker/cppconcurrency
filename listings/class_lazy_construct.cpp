#include "scoped_thread.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <thread>
#include <mutex>

using namespace std;

class lunchline {
public:
    lunchline(): entre("salisbury steak") {}

    lunchline(const std::string& entre_): entre(entre_) {}

    std::string front() {
        std::call_once(flag, &lunchline::init, this);
        return menu.front();
    }

    std::string back() {
        std::call_once(flag, &lunchline::init, this);
        return menu.back();
    }

private:
    std::vector<std::string> menu; 
    std::string entre;
    std::once_flag flag;

    void init() {
        menu = std::vector<std::string>(100, entre);
    }
};

int main() {
    lunchline ll;
    conc::scoped_thread t1{thread([&]() {cout << ll.front() << endl;})};
    conc::scoped_thread t2{thread([&]() {cout << ll.back() << endl;})};
}
