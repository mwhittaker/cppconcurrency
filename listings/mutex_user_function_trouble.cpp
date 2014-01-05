#include <iostream>
#include <mutex>

class some_data {
public:
    void do_something() {
        std::cout << "do_something!" << std::endl;
    }
private:
    int i;
    std::string s;
};

class data_wrapper {
public:
    template<typename Function> 
    void process_data(Function f) {
        std::cout << "locking mutex" << std::endl;
        std::lock_guard<std::mutex> lg(m);
        f(data);
        std::cout << "unlocking mutex" << std::endl;
    }
private:
    some_data data;
    std::mutex m;
};


int main() {
    some_data *unprotected;
    data_wrapper x;

    auto malicious = [&](some_data& protected_data) {
        unprotected = &protected_data;
    };

    x.process_data(malicious);
    unprotected->do_something();
}
