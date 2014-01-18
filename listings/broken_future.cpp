#include <iostream>
#include <future>

int main() {
    std::future<int> f1;
    std::future<int> f2;
    
    {
        std::promise<int> p;
        std::packaged_task<int()> t([]{return 1;});
        f1 = p.get_future();
        f2 = t.get_future();
    }

    try {
        std::cout << f1.get() << std::endl;
    } 
    catch (const std::future_error&) {
        std::cerr << "broken promise :(" << std::endl;
    }

    try {
        std::cout << f2.get() << std::endl;
    } 
    catch (const std::future_error&) {
        std::cerr << "broken promise :(" << std::endl;
    }
}
