#include <iostream>
#include <chrono>

using std::cout;
using std::endl;
using std::chrono::duration_cast;

typedef std::chrono::milliseconds MS;
typedef std::chrono::seconds S;
typedef std::chrono::minutes M;
typedef std::chrono::hours H;

void print_times(S s) {
    cout << s.count()                   << " seconds"      << endl; 
    cout << MS(s).count()               << " milliseconds" << endl; 
    cout << duration_cast<M>(s).count() << " minutes"      << endl;
    cout << duration_cast<H>(s).count() << " hours"        << endl;
    cout <<                                                   endl;
}

int main() {
    S s(1);
    print_times(s);
    print_times(s*60);
    print_times(s*60*60);
    print_times(s*60*60*24);
    print_times(s*60*60*24*365);
}
