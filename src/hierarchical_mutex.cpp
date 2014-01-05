#include "hierarchical_mutex.h"
#include <climits>

namespace conc {

thread_local ulong hierarchical_mutex::this_thread_hier_val(ULONG_MAX);

hierarchical_mutex::hierarchical_mutex(ulong val) :
        hier_val(val),
        prev_hier_val(0)
{}

void hierarchical_mutex::lock() {
    check_hier_violation();
    m.lock();
    update_hier_val();
}

void hierarchical_mutex::unlock() {
    this_thread_hier_val = prev_hier_val;
    m.unlock();
}

bool hierarchical_mutex::try_lock() {
    check_hier_violation();
    if (!m.try_lock()) {
        return false;
    }
    update_hier_val();
    return true;
}

void hierarchical_mutex::check_hier_violation() {
    if (this_thread_hier_val <= hier_val) {
        throw std::logic_error("mutex hierarchy violated");
    }
}

void hierarchical_mutex::update_hier_val() {
    prev_hier_val = this_thread_hier_val;
    this_thread_hier_val = hier_val;
}

} // namespace conc
