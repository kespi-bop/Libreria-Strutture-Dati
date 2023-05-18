#include "hashtable.hpp"

namespace lasd {

/* ************************************************************************** */

template <>
class Hashable<int> {
    public:
        ulong operator()(const int & dat) const noexcept {
            return (dat * dat);
        }
};

template<>
class Hashable<std::string> {
    public:
        ulong operator()(const std::string& dat) const noexcept {
            ulong accumulator = 0;
            for(ulong i = 0; i < dat.length(); i++) {
                accumulator += dat[i] * i;
            }
            return accumulator;
        }
};

template<>
class Hashable<double> {
    public:
        ulong operator()(const double& dat) const noexcept {
            ulong intgpart = floor(dat);
            ulong fracpart = pow(2, 24) * (dat - intgpart);
            return (intgpart * fracpart);
        }
};

template <typename Data>
inline ulong HashTable<Data>::HashKey(ulong key) const noexcept {
    if(size!=0) {
        return (a * key + b) % tableSize;
    }
    else {
        return 0;
    }

}

/* ************************************************************************** */

}
