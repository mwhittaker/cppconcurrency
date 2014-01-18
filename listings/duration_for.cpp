#include <iostream>
#include <future>
#include <chrono>

int main() {
    std::chrono::seconds sec(1);
    
    auto sleep = [sec] {
        std::this_thread::sleep_for(5 * sec);
        return 43;
    };
    std::future<int> f = std::async(std::launch::async, sleep);

    std::cout << "waiting" << std::endl;
    std::future_status status;
    do {
        status = f.wait_for(sec);
        switch (status) {
            case std::future_status::deferred:
                std::cout << "deferred" << std::endl;
                break;
            case std::future_status::timeout:
                std::cout << "timed out" << std::endl;
                break;
            case std::future_status::ready:
                std::cout << "ready" << std::endl;
                break;
        }
    } while(status != std::future_status::ready);

    std::cout << "future: " << f.get() << std::endl;
}
