
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template<typename Data>
bool FoldableContainer<Data>::Exists(const Data& valore) const noexcept {

    bool result = false;

    Fold(
        [valore](const Data& dat, void* result){
            *((bool*)result) |= (dat == valore);
        }
    , &result
    );
    return result;

}

/* ************************************************************************** */

}
