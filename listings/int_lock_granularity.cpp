#include <iostream>
#include <mutex>

class Integer {
public:
    Integer(int data_) : data(data_) {}
    
    friend bool operator==(const Integer& lhs, const Integer& rhs) {
        return &lhs == &rhs || lhs.get_data() == rhs.get_data();
    }

private:
    int data;
    mutable std::mutex m;
    
    int get_data() const {
        std::lock_guard<std::mutex> lg(m);
        return data;
    }
};

int main() {
    Integer i1(1);
    Integer i2(2);
    Integer i3(1);

    std::cout << std::boolalpha << "i1 == i2? " << (i1 == i2) << std::endl; 
    std::cout << std::boolalpha << "i1 == i1? " << (i1 == i1) << std::endl; 
    std::cout << std::boolalpha << "i1 == i3? " << (i1 == i3) << std::endl; 
}
