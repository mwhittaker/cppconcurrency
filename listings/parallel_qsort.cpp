#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <future>
#include <thread>

template <typename T>
std::list<T> quicksort(std::list<T> l) {
    // base case
    if (l.size() <= 1) {
        return l;
    }

    // behead l into sorted
    std::list<T> sorted;
    sorted.splice(sorted.begin(), l, l.begin());
    const T& pivot = *(sorted.begin());

    // partition l
    auto less = [&](const T& t) {return t < pivot;};
    auto split = std::partition(l.begin(), l.end(), less);
    
    // create lower
    std::list<T> lower;
    lower.splice(lower.end(), l, l.begin(), split);
    
    // recursively sort
    auto new_lower = std::async(quicksort<T>, std::move(lower));
    auto new_upper = quicksort(std::move(l));

    // combine and return
    sorted.splice(sorted.end(), new_upper);
    sorted.splice(sorted.begin(), new_lower.get());
    return sorted;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& l) {
    std::for_each(l.begin(), l.end(), [&](const T& t){os << t << " ";});
    return os;
}

int main() {
    std::list<int> il{6,3,2,9,5,8,1,4,7};
    std::list<char> cl{'g','y','s','u','q','b','o','v'};
    std::list<std::string> sl{"who", "goes", "there"};

    std::cout << quicksort(il) << std::endl;
    std::cout << quicksort(cl) << std::endl;
    std::cout << quicksort(sl) << std::endl;
}
