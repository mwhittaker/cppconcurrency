#include <iostream>
#include <future>

int mult2(int i) {
    std::cout << "mult2(" << i << ")" << std::endl;
    return i * 2;
}

int main() {
    // task 1
    std::packaged_task<int(int)> task1(mult2);
    std::future<int> fut1 = task1.get_future();
    task1(3);
    std::cout << fut1.get() << std::endl;

    // task 2
    std::packaged_task<long(int)> task2(mult2);
    std::future<long> fut2 = task2.get_future();
    task2(4);
    std::cout << fut2.get() << std::endl;

    // task 3
    std::packaged_task<int(int)> task3(mult2);
    task3(5);
    std::future<int> fut3 = task3.get_future();
    std::cout << fut3.get() << std::endl;

    // task 4
    std::packaged_task<void()> task4([]{std::cout << "void" << std::endl;});
    task4();
    task4.get_future().get();
}
