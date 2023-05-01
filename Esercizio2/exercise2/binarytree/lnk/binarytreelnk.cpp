#include "binarytreelnk.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline BinaryTreeLnk<Data>::BinaryTreeLnk(const MappableContainer<Data> &right) {
   ;
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MutableMappableContainer<Data> &&right) {
    ;//con iteratore(?)
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk &right){
    ;//con iteratore(?)
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk &&right) noexcept{
    std::swap(root, right.root);
    std::swap(size, right.size);
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk &right){
    return BinaryTreeLnk();
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk &&right) noexcept{
    return BinaryTreeLnk();
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk &right) noexcept{
    return false;
    //fare dopo
}

template <typename Data>
inline void BinaryTreeLnk<Data>::Clear() noexcept{
    delete root;
    size = 0;
}

/* ************************************************************************** */

}
