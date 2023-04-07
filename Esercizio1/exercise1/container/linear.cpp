
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */


template<typename Data>
const Data& LinearContainer<Data>::Front() const {
    if(!Container::Empty()) return this->operator[](0);
    else throw std::out_of_range ("Container vuoto");
}

template<typename Data>
Data& LinearContainer<Data>::Front() {
    if(!Container::Empty()) return this->operator[](0);
    else throw std::out_of_range ("Container vuoto");
}

template<typename Data>
const Data& LinearContainer<Data>::Back() const {
    if(!Container::Empty()) return this->operator[](size-1);
    else throw std::out_of_range ("Container vuoto");
}

template<typename Data>
Data& LinearContainer<Data>::Back() {
    if(!Container::Empty()) return (this->operator[](size-1));
    else throw std::out_of_range ("Container vuoto");
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
void LinearContainer<Data>::Map(const MapFunctor func) const {
    for(int i=0; i<size; i++) func(this->operator[](i));
}

template <typename Data>
void LinearContainer<Data>::PostOrderMap(const MapFunctor func) const {
    for(int i = size-1; i>=0; i--) func(this->operator[](i));
}

template <typename Data>
void LinearContainer<Data>::Map(MutableMapFunctor func) {
    for(int i=0; i<size; i++) func(this->operator[](i));
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
