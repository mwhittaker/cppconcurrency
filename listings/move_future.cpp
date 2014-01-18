#include <iostream>
#include <string>
#include <future>

struct Cat {
    void meow(int times, std::string mew) {
        for (int i = 0; i < times; ++i) {
            std::cout << mew << std::endl;
        }
    }

    std::string catify(const std::string& phrase) {
        return "meow " + phrase;
    }

    friend std::ostream& operator<<(std::ostream& os, const Cat&) {
        os << "cat";
        return os;
    }
};

struct Dog {
    double operator() (double treats) {
        return treats * 2;
    }
};

struct mover {
    mover() {}
    mover(mover&&) {}
    mover(const mover&) = delete;
    mover& operator=(mover&& m) {return m;}
    mover& operator=(const mover&) = delete;

    void operator()(){}
};

Cat adopt(Cat&) {
    return Cat();
}

int main() {
    Cat c;
    auto f1 = std::async(&Cat::meow, &c, 2, "meow"); // (&c)->meow(2, "meow")
    auto f2 = std::async(&Cat::catify, c, "purrr");  // c_copy.catify("purrr") 
    auto f3 = std::async(adopt, std::ref(c));        // adopt(c); 

    Dog d;
    auto f4 = std::async(Dog(), 3.1415962); // moved_d(3.1...)
    auto f5 = std::async(std::ref(d), 1.0); // d(1.0)

    auto f6 = std::async(mover()); // moved_tmp()

    f1.get();
    std::cout << f2.get() << std::endl;
    std::cout << f3.get() << std::endl;
    std::cout << f4.get() << std::endl;
    std::cout << f5.get() << std::endl;
    f6.get();
}
