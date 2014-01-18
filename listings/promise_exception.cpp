#include <iostream>
#include <exception>
#include <stdexcept>
#include <future>

int main() {
    std::promise<char> p1;
    std::promise<char> p2;
    std::future<char>  f1 = p1.get_future();
    std::future<char>  f2 = p2.get_future();
    
    auto future_catch = [](std::future<char> f) {
        try {
            std::cout << f.get() << std::endl;
        }
        catch (int i) {
            std::cerr << i << std::endl;
        }
    };

    // current exception
    try {
        throw 2; 
    }
    catch (...) {
        p1.set_exception(std::current_exception());
    }

    // make_exception_ptr
    p2.set_exception(std::make_exception_ptr(2));

    // catch exceptions
    future_catch(std::move(f1));
    future_catch(std::move(f2));
}
