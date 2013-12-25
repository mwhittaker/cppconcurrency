#ifndef SCOPED_THREAD_H
#define SCOPED_THREAD_H

#include <thread>

namespace conc {

/***************************************************************************//**
 * \brief This class takes ownership of a thread and joins it using RAII.
 *
 * An instance of a scoped_thread takes ownership of a thread by moving it into
 * the instance. It verifies that the thread is joinable in the contructor and
 * throws and exception if it is not. Then, it joins the thread in the
 * destructor. Copy and assignment operators have been deleted to avoid
 * erroneous copies.
 *
 * Class Invariants:
 * - t is joinable.
 * - Upon destruction of a scoped_thread object, the thread is owns will be
 *   joined.
 ******************************************************************************/
class scoped_thread {
public:
    /***********************************************************************//**
     * Constructs a scoped_thread instance with <t_>.
     *
     * If <t_> is not joinable, an std::logic_error is thrown. Otherwise, this
     * instance succesfully moves t_ into a local copy. NOTE that the thread
     * <t_> is MOVED. If you isntantiate a scoped_thread instance with an
     * lvalue, do not attempt to touch that variable again!
     *
     * <t_> will be joined by the destructor.
     *
     * \param t_ A thread to be moved into this instance.
     * \see scoped_thread::~scoped_thread()
     **************************************************************************/
    explicit scoped_thread(std::thread t_);

    /***********************************************************************//**
     * Joins the thread associated with this instance.
     **************************************************************************/
    ~scoped_thread();

    /***********************************************************************//**
     * Deleted copy constructor.
     **************************************************************************/
    scoped_thread(const scoped_thread&) = delete;

    /***********************************************************************//**
     * Deleted copy assignment operator.
     **************************************************************************/
    scoped_thread& operator=(const scoped_thread&) = delete;

private:
    /***********************************************************************//**
     * The thread managed by this instance of scoped_thread.
     *
     * This thread is guaranteed to be joinable and will be joined in the 
     * destructor of this instance.
     **************************************************************************/
    std::thread t;
};

} // namespace conc

#endif // SCOPED_THREAD_H
