#include "thread_guard.h"
#include <thread>

namespace conc {

thread_guard::thread_guard(std::thread& t_): t(t_) {}

thread_guard::~thread_guard() {
    if (t.joinable()) {
        t.join();
    }
}

} // namespace conc
