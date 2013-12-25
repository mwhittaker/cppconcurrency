#include <iostream>
#include <thread>

struct fun {
    int& x;
    fun(int x_): x(x_) {}
    void operator()() const {
        for (int i = 0; i < 1000000; ++i) {
            ++x;
            --x;
        }
    }
};

int main() {
    int local_state = 0;
    std::thread t{fun(local_state)};
    t.detach();
}
