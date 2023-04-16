
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

/* ************************************************************************** */

}
