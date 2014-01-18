#include <iostream>
#include <future>
#include <chrono>
#include <thread>

using namespace std::chrono;

int pause() {
    std::this_thread::sleep_for(seconds(3));
    return 43;
}

int main() {
    const auto timeout = steady_clock::now() + seconds(2);
    const auto to = std::future_status::timeout;

    std::future<int> f1 = std::async(std::launch::async, pause);
    std::future<int> f2 = std::async(std::launch::async, pause);
    std::future<int> f3 = std::async(std::launch::async, pause);
    
    std::future_status s1 = f1.wait_until(timeout);
    std::future_status s2 = f2.wait_until(timeout);
    std::future_status s3 = f3.wait_until(timeout);

    if (to == s1 || to == s2 || to == s3) {
        std::cout << "someone timed out!" << std::endl;
    }
    else {
        std::cout << "future: " << f1.get() + f2.get() + f3.get() << std::endl; 
    }
}
