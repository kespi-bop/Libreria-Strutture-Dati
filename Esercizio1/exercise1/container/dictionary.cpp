
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template<typename Data>
bool DictionaryContainer<Data>::InsertAll(const MappableContainer<Data>& structure){
    bool flag = true;
    structure.Map(
        [this, &flag] (const Data& item) {
            flag &= Insert(item);
        }
    );
    return flag;
}


template<typename Data>
bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& structure){
    bool flag = true;
    structure.Map(
        [this, &flag] (const Data& item) {
            flag &= Insert(std::move(item));
        }
    );
    return flag;
}


template<typename Data>
bool DictionaryContainer<Data>::RemoveAll(const MappableContainer<Data>& structure){
    bool flag = true;
    structure.Map(
        [this, &flag] (const Data& item) {
            flag &= Remove(item);
        }
    );
    return flag;
}


template<typename Data>
bool DictionaryContainer<Data>::InsertSome(const MappableContainer<Data>& structure){
    bool flag = false;
    structure.Map(
        [this, &flag] (const Data& item) {
            flag |= Insert(item);
        }
    );
    return flag;
}


template<typename Data>
bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& structure){
    bool flag = false;
    structure.Map(
        [this, &flag] (const Data& item) {
            flag |= Insert(std::move(item));
        }
    );
    return flag;
}


template<typename Data>
bool DictionaryContainer<Data>::RemoveSome(const MappableContainer<Data>& structure){
    bool flag = false;
    structure.Map(
        [this, &flag] (const Data& item) {
            flag |= Remove(item);
        }
    );
    return flag;
}

/* ************************************************************************** */

}
