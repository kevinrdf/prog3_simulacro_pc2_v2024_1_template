#ifndef PROG3_SIMULACRO_PC2_V2024_1_REMOVE_DUPLICATES_H
#define PROG3_SIMULACRO_PC2_V2024_1_REMOVE_DUPLICATES_H

#include <iterator>
#include <algorithm>
#include <list>
#include <numeric>
#include <vector>
#include <limits>
#include <thread>
#include <future>

using namespace std;

template <typename T>
T product_of_all(const T& a, const T& b, const T& c) {
    return a * b * c;
}

template <typename Container>
auto find_max_triple_product(const Container& container) -> typename Container::value_type {
    using ValueType = typename Container::value_type;

    size_t n = container.size();
    if (n <= 3) {
        return accumulate(container.begin(), container.end(), static_cast<ValueType>(1), multiplies<>());
    }

    vector<ValueType> vec(container.begin(), container.end());

    sort(vec.begin(), vec.end());

    ValueType max_product = max(
            vec[n - 1] * vec[n - 2] * vec[n - 3],
            vec[0] * vec[1] * vec[n - 1]
    );

    return max_product;
}

template <typename T>
auto find_max_triple_product(const list<T>& container) -> T {
    size_t n = container.size();
    if (n <= 3) {
        return accumulate(container.begin(), container.end(), static_cast<T>(1), multiplies<>());
    }

    vector<T> vec(container.begin(), container.end());
    return find_max_triple_product(vec);
}

#endif //PROG3_SIMULACRO_PC2_V2024_1_REMOVE_DUPLICATES_H