#include "scoped_thread.h"
#include <thread>

namespace conc {

scoped_thread::scoped_thread(std::thread t_): t(std::move(t_)) {
    if (!t.joinable()) {
        throw std::logic_error("scoped_thread constructed from non-joinable");
    }
}
scoped_thread::~scoped_thread() {
    t.join();
}

} // namespace conc
