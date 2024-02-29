
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
void MappableContainer<Data>::Fold(FoldFunctor func, void* acc) const {
    Map( 
        [&func, &acc](const Data& dat) {
            func(dat, acc); 
        }
    );
}

template <typename Data>
void inline PreOrderMappableContainer<Data>::PreOrderFold(FoldFunctor func, void* acc) const {
    PreOrderMap( 
        [&func, &acc](const Data& dat) {
            func(dat, acc);
        }
    );
}

template <typename Data>
void inline PostOrderMappableContainer<Data>::PostOrderFold(FoldFunctor func, void* acc) const {
    PostOrderMap(
        [&func, &acc](const Data& dat) {
            func(dat, acc);
        }
    );
}

template <typename Data>
void InOrderMappableContainer<Data>::InOrderFold(FoldFunctor func, void* acc) const { 
    InOrderMap(
        [&func, &acc](const Data& dat) {
            func(dat, acc);
        }
    );
}

template <typename Data>
void BreadthMappableContainer<Data>::BreadthFold(FoldFunctor func, void* acc) const { 
    BreadthMap(
        [&func, &acc](const Data& dat) {
            func(dat, acc);
        }
    );
}

/* ************************************************************************** */

}
