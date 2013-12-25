#ifndef THREAD_GUARD_H
#define THREAD_GUARD_H

#include <thread>

namespace conc {

/***************************************************************************//**
 * \brief This class uses RAII to join a thread.
 *
 * A thread_guard instance is instantiated with an <std::thread>.
 * When the instance goes out of scope, the destructor will join the thread if
 * it is joinable. Otherwise, it does nothing.
 *
 * RAII is a powerful way to guarantee a thread is joined even in the face of
 * exceptional circumstances. Other means of joining despite exceptions, like
 * try-catch blocks, are more verbose and more prone to bugs.
 ******************************************************************************/
class thread_guard {
public:
    /***********************************************************************//**
     * Constructs a thread_guard instance from <t_>. 
     *
     * <t_> will be joined when this thread_guard instance goes out of scope,
     * if possible. 
     *
     * \param t_ A thread to be joined by the destructor.
     * \see thread_guard::~thread_guard()
     **************************************************************************/ 
    explicit thread_guard(std::thread& t_);
    
    /***********************************************************************//**
     * Joins the thread associated with this thread_guard instance.
     *
     * If <t.joinable()> is true, <t> is joined. Otherwise, nothing happens.
     **************************************************************************/ 
    ~thread_guard();
    
    /***********************************************************************//**
     * Deleted copy constructor.
     **************************************************************************/
    thread_guard(const thread_guard&) = delete;
    
    /***********************************************************************//**
     * Deleted copy assignment operator.
     **************************************************************************/
    thread_guard& operator=(const thread_guard&) = delete;
private:
    /***********************************************************************//**
     * The thread managed by this instance of thread_guard. The thread will be
     * joined by the destructor if possible.
     **************************************************************************/ 
    std::thread& t;
};

} // namespace conc

#endif // THREAD_GUARD_H
