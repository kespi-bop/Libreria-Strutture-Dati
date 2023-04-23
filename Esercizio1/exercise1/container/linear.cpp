
#include <stdexcept>
#include "linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */


template<typename Data>
const Data& LinearContainer<Data>::Front() const {
    if(!Container::Empty()) {
        return operator[](0);
    } 
    else throw std::length_error ("Error: Empty-Container!");
}

template<typename Data>
Data& LinearContainer<Data>::Front() {
    if(!Container::Empty()) {
        return operator[](0);
    } 
    else throw std::length_error ("Error: Empty-Container!");
}

template<typename Data>
const Data& LinearContainer<Data>::Back() const {
    if(!Container::Empty()) {
        return operator[](size - 1);
    }
    else throw std::length_error ("Error: Empty-Container!");
}

template<typename Data>
Data& LinearContainer<Data>::Back() {
    if(!Container::Empty()) {
        return (operator[](size - 1));
    }
    else throw std::length_error ("Error: Empty-Container!");
}

template<typename Data>
bool LinearContainer<Data>::operator==(const LinearContainer& right) const {
    bool result=true;
    if(size!=right.size){
        return false;
    }
    for(int i=0; i < size; i++) {
        if(operator[](i)!=right[i]) {
            return false;
        }
    }
    return true;
}

template<typename Data>
bool inline LinearContainer<Data>::operator!=(const LinearContainer& right) const {
    return !(operator==(right));
}

template <typename Data>
void LinearContainer<Data>::PreOrderFold(FoldFunctor func, void *acc) const
{
    for(ulong i = 0; i < size; i++){
        func(operator[](i), acc);
    }
}

template <typename Data>
void LinearContainer<Data>::PostOrderFold(FoldFunctor func, void* acc) const {
    ulong i = size;
    while (i>0){
        func(operator[](--i), acc);
    } 
}

template <typename Data>
void LinearContainer<Data>::PreOrderMap(MapFunctor func) const{
    for(ulong i = 0; i < size; i++){
        func(operator[](i));
    }
}

template <typename Data>
void LinearContainer<Data>::PostOrderMap(MapFunctor func) const{
    ulong i = size;
    while (i>0){
        func(operator[](--i));
    }  
}

template <typename Data>
void LinearContainer<Data>::PreOrderMap(MutableMapFunctor func) {
    for(ulong i = 0; i < size; i++){
        func(operator[](i));
    }
}

template <typename Data>
void LinearContainer<Data>::PostOrderMap(MutableMapFunctor func){
    ulong i = size;
    while (i>0){
        func(operator[](--i));
    } 
}

template<typename Data>
bool SortableLinearContainer<Data>::operator==(const SortableLinearContainer& right) const {
    bool result=true;

    if(size!=right.size) {
        return false;
    }

    for(int i=0; i < size; i++) {
        if(this[i]!=right[i]) {
            return false;
        }        
    }
    
    return true;
}

template<typename Data>
bool SortableLinearContainer<Data>::operator!=(const SortableLinearContainer& right) const {
    return !(operator==(right));
}

template<typename Data>
ulong SortableLinearContainer<Data>::Partition(ulong p, ulong r)noexcept {
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
void SortableLinearContainer<Data>::Quicksort(ulong p, ulong r)noexcept {
    if (p < r) {
    uint q = Partition(p, r);
    Quicksort(p, q);
    Quicksort(q + 1, r);
  }
}



/* ************************************************************************** */

}
