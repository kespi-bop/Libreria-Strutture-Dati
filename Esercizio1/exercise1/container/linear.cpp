
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template<typename Data>
const Data& LinearContainer<Data>::Front() const {
    if(!Container::Empty()) 
        return this[0];
}

template<typename Data>
Data& LinearContainer<Data>::Front() {
    if(!Container::Empty()) 
        return this[0];
}

template<typename Data>
const Data& LinearContainer<Data>::Back() const {
    if(!Container::Empty()) 
        return this[size-1];
}

template<typename Data>
Data& LinearContainer<Data>::Back() {
    if(!Container::Empty()) 
        return this[size-1];
}

template<typename Data>
bool LinearContainer<Data>::operator==(LinearContainer& other) const {
    bool result=true;

    if(size!=other.size) 
        return false;

    for(int i=0; i<size; i++) 
    {
        if(this[i]!=other[i]) 
            return false; 
    }

    return true;
}

template<typename Data>
bool LinearContainer<Data>::operator!=(LinearContainer& other) const {
    bool result=false;

    if(size!=other.size) 
        return true;
    
    for(int i=0; i<size; i++) 
    {
        if(this[i]!=other[i]) 
            return true;
    }
    
    return false;
}

template <typename Data>
const void LinearContainer<Data>::Map(const MapFunctor func) const {
    for(int i=0; i<size; i++)
     func(&this[i]);
}

template <typename Data>
const void LinearContainer<Data>::PostOrderMap(const MapFunctor func) const {
    for(int i = size-1; i>=0; i--)
     func(&this[i]);
}

template <typename Data>
void LinearContainer<Data>::Map(MutableMapFunctor func) {
    for(int i=0; i<size; i++) 
        func(&this[i]);
}

template <typename Data>
void LinearContainer<Data>::PostOrderMap(MutableMapFunctor func){
    for(int i = size-1; i>=0; i--) 
        func(&this[i]);
}

template<typename Data>
bool SortableLinearContainer<Data>::operator==(SortableLinearContainer& other) const {
    bool result=true;

    if(size!=other.size) 
        return false;
    
    for(int i=0; i<size; i++) 
    {
        if(this[i]!=other[i]) 
            return false;
    }
    
    return true;
}

template<typename Data>
bool SortableLinearContainer<Data>::operator!=(SortableLinearContainer& other) const {
    bool result=false;

    if(size!=other.size) 
        return true;
    
    for(int i=0; i<size; i++)
    {
        if(this[i]!=other[i]) 
            return true;
    } 
    
    return false;
}



/* ************************************************************************** */

}
