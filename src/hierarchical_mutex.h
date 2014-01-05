#ifndef HIERARCHICAL_MUTEX_H
#define HIERARCHICAL_MUTEX_H

#include <mutex>

namespace conc {

/***************************************************************************//**
 * A hierarchical mutex.
 *
 * Each mutex is assigned a priority. If a thread attempts to lock a
 * hierarchical mutex with a priority lower than the lowest priority mutex it
 * currently has locked, an std::logic_error is thrown. Otherwise, all lockable
 * operations are the same.
 ******************************************************************************/
class hierarchical_mutex {
public:
    /***********************************************************************//**
     * Constructs a hierarchical_mutex with the given priority.
     *
     * \param val Priority. Lower priorities mutex must be locked after higher
     * priority mutexes.
     **************************************************************************/
    explicit hierarchical_mutex(ulong val);

    /***********************************************************************//**
     * If the priority of this mutex is lower than the lowest priority mutex
     * owned by the thread, then lock occurs just as std::mutex::lock() occurs.
     * Otherwise, an std::logic_error is thrown.
     *
     * \see std::mutex::lock()
     **************************************************************************/
    void lock();
    
    /***********************************************************************//**
     * Same as std::mutex::unlock()
     *
     * \see std::mutex::unlock()
     **************************************************************************/
    void unlock();
    
    /***********************************************************************//**
     * \see conc::hierarchical_mutex::lock()
     * \see std::mutex::unlock()
     **************************************************************************/
    bool try_lock();

private:
    /***********************************************************************//**
     * The internal mutex managed by this instance.
     **************************************************************************/
    std::mutex m;
    
    /***********************************************************************//**
     * The priority associated with this instance.
     **************************************************************************/
    const ulong hier_val;
    
    /***********************************************************************//**
     * The lowest priority associated with any mutex locked at the time this
     * mutex was locked.
     **************************************************************************/
    ulong prev_hier_val;
    
    /***********************************************************************//**
     * The lowest priority of a locked mutex in this thread.
     **************************************************************************/
    static thread_local ulong this_thread_hier_val;

    /***********************************************************************//**
     * If the mutex being locked is a lower prioirty that the current thread's
     * priority, an std::logic_error is thrown. Otherwise, nothing happens.
     **************************************************************************/
    void check_hier_violation();
    
    /***********************************************************************//**
     * Updates prev_hier_val and this_thread_hier_val.
     **************************************************************************/
    void update_hier_val();
};

} // namespace conc

#endif // HIERARCHICAL_MUTEX_H
