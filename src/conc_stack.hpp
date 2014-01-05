namespace conc {

const char *empty_stack::what() const throw() {
    return "empty stack";
}

template <typename T> stack<T>::stack() {}

template <typename T> 
stack<T>::stack(const stack& other) {
    std::lock_guard<std::mutex> lock(other.m);
    data = other.data;
}

template <typename T>
void stack<T>::push(T val) {
    std::lock_guard<std::mutex> lock(m);
    data.push(val);
}

template <typename T>
std::shared_ptr<T> stack<T>::pop() {
    std::lock_guard<std::mutex> lock(m);
    
    if (data.empty()) {
        throw empty_stack();
    }

    const std::shared_ptr<T> res(std::make_shared<T>(data.top()));
    data.pop();
    return res;
}

template <typename T>
void stack<T>::pop(T& val) {
    std::lock_guard<std::mutex> lock(m);

    if (data.empty()) {
        throw empty_stack();
    }

    val = data.top();
    data.pop();
}

template <typename T> 
bool stack<T>::empty() const {
    std::lock_guard<std::mutex> lock(m);
    return data.empty();
}

} // namespace conc
