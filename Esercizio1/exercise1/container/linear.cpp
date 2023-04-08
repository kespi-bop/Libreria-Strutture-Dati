
#include <stdexcept>
#include "linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */


template<typename Data>
const Data& LinearContainer<Data>::Front() const {
    if(!Container::Empty()) return this->operator[](0);
    else throw std::length_error ("Container vuoto");
}

template<typename Data>
Data& LinearContainer<Data>::Front() {
    if(!Container::Empty()) return this->operator[](0);
    else throw std::length_error ("Container vuoto");
}

template<typename Data>
const Data& LinearContainer<Data>::Back() const {
    if(!Container::Empty()) return this->operator[](size-1);
    else throw std::length_error ("Container vuoto");
}

template<typename Data>
Data& LinearContainer<Data>::Back() {
    if(!Container::Empty()) return (this->operator[](size-1));
    else throw std::length_error ("Container vuoto");
}

template<typename Data>
bool LinearContainer<Data>::operator==(LinearContainer& other) const {
    bool result=true;
    if(size!=other.size) return false;
    for(int i=0; i<size; i++) if(this[i]!=other[i]) return false;
    return true;
}

template<typename Data>
bool LinearContainer<Data>::operator!=(LinearContainer& other) const {
    bool result=false;
    if(size!=other.size) return true;
    for(int i=0; i<size; i++) if(this[i]!=other[i]) return true;
    return false;
}

template <typename Data>
void LinearContainer<Data>::PreOrderFold(const FoldFunctor func, void* acc) const {
    for(ulong i = 0; i<size; i++) func(this->operator[](i), acc);
}

template <typename Data>
void LinearContainer<Data>::PostOrderFold(const FoldFunctor func, void* acc) const {
    ulong i = size;
    while (i>0) func(this->operator[](--i), acc);
}

template <typename Data>
void LinearContainer<Data>::PreOrderMap(const MapFunctor func) const {
    for(ulong i=0; i<size; i++) func(this->operator[](i));
}

template <typename Data>
void LinearContainer<Data>::PostOrderMap(const MapFunctor func) const
{
    for(int i = size-1; i>=0; i--) func(this->operator[](i));
}

template <typename Data>
void LinearContainer<Data>::PreOrderMap(MutableMapFunctor func) {
    for(ulong i=0; i<size; i++) func(this->operator[](i));
}

template <typename Data>
void LinearContainer<Data>::PostOrderMap(MutableMapFunctor func){
    for(int i = size-1; i>=0; i--) func(this->operator[](i));
}

template<typename Data>
bool SortableLinearContainer<Data>::operator==(SortableLinearContainer& other) const {
    bool result=true;
    if(size!=other.size) return false;
    
    for(int i=0; i<size; i++) if(this[i]!=other[i]) return false;
    
    return true;
}

template<typename Data>
bool SortableLinearContainer<Data>::operator!=(SortableLinearContainer& other) const {
    bool result=false;
    if(size!=other.size) return true;
    
    for(int i=0; i<size; i++) if(this[i]!=other[i]) return true;
    
    return false;
}

template<typename Data>
ulong SortableLinearContainer<Data>::Partition(ulong p, ulong r)noexcept{
    Data x = this->operator[](p);
    uint i = p - 1;
    uint j = r + 1;
    
    do {
        do { j--; } while ( x < this->operator[](j) );
        do { i++; } while ( this->operator[](i) < x );
        if (i < j) { std::swap(this->operator[](i), this->operator[](j)); }
    } while (i < j);

    return j;
}


template<typename Data>
void SortableLinearContainer<Data>::Quicksort(ulong p, ulong r)noexcept{
    if (p < r) {
    uint q = Partition(p, r);
    Quicksort(p, q);
    Quicksort(q + 1, r);
  }
}



/* ************************************************************************** */

}
