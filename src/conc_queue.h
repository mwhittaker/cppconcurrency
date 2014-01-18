#ifndef CONC_QUEUE_H
#define CONC_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>

namespace conc {

template <typename T>
class queue {
public:
    explicit queue();
    explicit queue(const queue& other);
    void push(T val);
    void wait_pop(T& val);
    std::shared_ptr<T> wait_pop();
    bool try_pop(T& val);
    std::shared_ptr<T> try_pop();
    bool empty() const;

private:
    std::queue<T> data;
    mutable std::mutex m;
    std::condition_variable not_empty_cv;
};

} // namespace conc

#include "conc_queue.hpp"

#endif // CONC_QUEUE_H

