namespace conc {

template <typename T> queue<T>::queue() {}

template <typename T>
queue<T>::queue(const queue& other) {
    std::lock_guard<std::mutex> lock(other.m);
    data = other.data;
}

template <typename T>
void queue<T>::push(T val) {
    std::lock_guard<std::mutex> lock(m);
    data.push(val);
    not_empty_cv.notify_one();
}

template <typename T>
void queue<T>::wait_pop(T& val) {
    std::unique_lock<std::mutex> lock(m);
    not_empty_cv.wait(lock, [this]{return !data.empty();});
    val = data.front();
    data.pop();
}

template <typename T>
std::shared_ptr<T> queue<T>::wait_pop() {
    std::unique_lock<std::mutex> lock(m);
    not_empty_cv.wait(lock, [this]{return !data.empty();});
    std::shared_ptr<T> popped(std::make_shared<T>(data.front()));
    data.pop();
    return popped;
}

template <typename T>
bool queue<T>::try_pop(T& val) {
    std::lock_guard<std::mutex> lock(m);
    
    if (data.empty()) {
        return false;
    }

    val = data.front();
    data.pop();
    return true;
}

template <typename T>
std::shared_ptr<T> queue<T>::try_pop() {
    std::lock_guard<std::mutex> lock(m);

    if (data.empty()) {
        return nullptr;
    }

    std::shared_ptr<T> popped(std::make_shared<T>(data.front()));
    data.pop();
    return popped;
}

template <typename T>
bool queue<T>::empty() const {
    std::lock_guard<std::mutex> lock(m);
    return data.empty();
}

} // namespace conc
