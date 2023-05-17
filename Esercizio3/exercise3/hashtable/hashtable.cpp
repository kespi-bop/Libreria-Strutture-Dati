#include "hashtable.hpp"

namespace lasd {

/* ************************************************************************** */

template <>
inline ulong Hashable<std::string>::operator()(std::string element) const noexcept {
    ulong accumulator = 0;
    for(ulong i = 0; i < element.length(); i++) {
        accumulator += element[i] * i;
    }
    return accumulator;
}

template <>
inline ulong Hashable<int>::operator()(int element) const noexcept {
    return element + 1;
}

template <>
inline ulong Hashable<double>::operator()(double element) const noexcept {
    return element + 1;
}

template <typename Data>
inline ulong HashTable<Data>::HashKey(ulong key) {
    if(size!=0) {
        return (a * key + b) % this->size;
    }
    else {
        return 0;
    }

}

/* ************************************************************************** */

}
