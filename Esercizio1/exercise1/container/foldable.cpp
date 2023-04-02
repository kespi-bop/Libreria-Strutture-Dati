
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template<typename Data>
bool FoldableContainer<Data>::Exists(const Data& item) const noexcept {
    bool flag;
    this->Fold(
        [this, item, &flag](const Data& dat){
            flag |= dat==item;
        }
    , flag);
    return flag;
}

/* ************************************************************************** */

}
