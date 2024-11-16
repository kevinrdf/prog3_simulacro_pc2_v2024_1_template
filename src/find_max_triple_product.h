#ifndef PROG3_SIMULACRO_PC2_V2024_1_FIND_MAX_TRIPLE_PRODUCT_H
#define PROG3_SIMULACRO_PC2_V2024_1_FIND_MAX_TRIPLE_PRODUCT_H

#include <iterator>
#include <unordered_set>
#include <algorithm>

using namespace std;

template <typename ForwardIt>
ForwardIt remove_duplicates(ForwardIt first, ForwardIt last) {
    unordered_set<typename iterator_traits<ForwardIt>::value_type> seen;
    return remove_if(first, last, [&seen](const auto& value) {
        return !seen.insert(value).second;
    });
}

template <typename ForwardIt, typename BinaryPredicate>
ForwardIt remove_duplicates_if(ForwardIt first, ForwardIt last, BinaryPredicate pred) {
    for (ForwardIt it = first; it != last; ++it) {
        last = remove_if(next(it), last, [&](const auto& value) {
            return pred(*it, value);
        });
    }
    return last;
}

#endif //PROG3_SIMULACRO_PC2_V2024_1_FIND_MAX_TRIPLE_PRODUCT_H