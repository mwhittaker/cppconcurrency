#include <iostream>
#include <ostream>
#include <mutex>

class X {
public:
    X(const int& i) : detail(i) {}

    friend void swap(X& lhs, X& rhs) {
        if (&lhs == &rhs) {
            return;
        }

        std::lock(lhs.m, rhs.m);
        std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock);
        std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock);
        std::swap(lhs.detail, rhs.detail);
    }

    friend std::ostream& operator<<(std::ostream& stream, const X& x) {
        stream << x.detail;
        return stream;
    }

private:
    int detail;
    std::mutex m;
};

int main() {
    int i = 0;
    int j = 42;
    X a(i);
    X b(j);

    std::cout << a << " " << b << std::endl;
    swap(a, b);
    std::cout << a << " " << b << std::endl;
}
