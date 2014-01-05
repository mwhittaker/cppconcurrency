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

        std::unique_lock<std::mutex> lock_a(lhs.m, std::defer_lock);
        std::unique_lock<std::mutex> lock_b(rhs.m, std::defer_lock);
        std::cout << "lock_a owns lock? " << lock_a.owns_lock() << std::endl;
        std::cout << "lock_b owns lock? " << lock_b.owns_lock() << std::endl;

        std::lock(lock_a, lock_b);
        std::cout << "lock_a owns lock? " << lock_a.owns_lock() << std::endl;
        std::cout << "lock_b owns lock? " << lock_b.owns_lock() << std::endl;

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
