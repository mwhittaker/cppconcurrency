#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>

void cin_print() {
    std::string s;
    std::cin >> s;
    std::reverse(s.begin(), s.end());
    std::cout << "You typed " << s << std::endl;
} 

int main() {
    std::thread(cin_print).detach();
    std::this_thread::sleep_for(std::chrono::seconds(5));
}
