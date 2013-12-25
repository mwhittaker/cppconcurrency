#include <iostream>
#include <thread>

struct Foo {
    void bar(int i) {
        std::cout << "bar " << i << std::endl;
    }
};

int main() {
    Foo foo;
    std::thread t(&Foo::bar, &foo, 43);
    t.join();
}
