namespace conc {

template <typename Iterator, typename T>
T accumulate(Iterator first, Iterator last, T init) {
    const ulong length = std::distance(first, last);

    if (length == 0) {
        return init;
    }

    const ulong min_per_t = 25;
    const ulong max_ts = (length + min_per_t - 1) / min_per_t;
    const ulong hw_ts = std::thread::hardware_concurrency();
    const ulong num_ts = std::min(hw_ts != 0 ? hw_ts : 2, max_ts);
    const ulong block_size = length / num_ts;
    std::vector<T> results(num_ts);
    std::vector<std::thread> threads(num_ts - 1);

    Iterator block_start = first;
    for (ulong i = 0; i < (num_ts - 1); ++i) {
        Iterator block_end = block_start;
        std::advance(block_end, block_size);
        threads[i] = std::thread(
            details::accumulate_block<Iterator, T>(),
            block_start, block_end, std::ref(results[i])
        );
        block_start = block_end;
    }
    details::accumulate_block<Iterator, T>()
            (block_start, last, results[num_ts - 1]);

    std::for_each(threads.begin(), threads.end(),
            std::mem_fn(&std::thread::join));

    return std::accumulate(results.begin(), results.end(), init);
}


namespace details {

template <typename Iterator, typename T>
void accumulate_block<Iterator, T>::operator()(Iterator first, Iterator last,
        T& result) {
    result = std::accumulate(first, last, result); 
}

} // namespace details
} // namespace conc
