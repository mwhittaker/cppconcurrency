#ifndef CONC_NUMERIC_H
#define CONC_NUMERIC_H

#include <thread>
#include <algorithm>
#include <numeric>

namespace conc {

/***************************************************************************//**
 * Concurrent implementation of std::accumulate. 
 *
 * Computes the sum of the given value init and the elements in the range
 * [first, last). This version uses operator+ to sum up the elements.
 * Everything is done concurrently.
 ******************************************************************************/
template <typename Iterator, typename T>
T accumulate(Iterator first, Iterator last, T init);

namespace details {

/***************************************************************************//**
 * Helper functor for accumulate. 
 *
 * Invokes std::acumulate on first, last, result and stores the result to
 * result.
 *
 * \see std::accumulate()
 * \see conc::accumulate()
 ******************************************************************************/
template <typename Iterator, typename T>
struct accumulate_block {
    void operator()(Iterator first, Iterator last, T& result);
};

} // namespace details
} // namespace conc

#include "conc_numeric.hpp"

#endif // CONC_NUMERIC_H
