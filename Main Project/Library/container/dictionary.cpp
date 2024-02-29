
#include <stdexcept>

/* ************************************************************************** */

namespace lasd { 

/* ************************************************************************** */

template<typename Data>
bool DictionaryContainer<Data>::InsertAll(const MappableContainer<Data>& cont){
    bool resultAll = true;
    cont.Map(
        [this, &resultAll] (const Data& value) {
            resultAll &= Insert(value);
        }
    );
    return resultAll;
}

template<typename Data>
bool DictionaryContainer<Data>::InsertAll(MutableMappableContainer<Data>&& cont){
    bool resultAll = true;
    cont.Map(
        [this, &resultAll] (Data& value) {
            resultAll &= Insert(std::move(value));
        }
    );
    return resultAll;
}

template<typename Data>
bool DictionaryContainer<Data>::RemoveAll(const MappableContainer<Data>& cont){
    bool resultAll = true;
    cont.Map(
        [this, &resultAll] (const Data& value) {
            resultAll &= Remove(value);
        }
    );
    return resultAll;
}

template<typename Data>
bool DictionaryContainer<Data>::InsertSome(const MappableContainer<Data>& cont){
    bool resultSome = false;
    cont.Map(
        [this, &resultSome] (const Data& value) {
            resultSome |= Insert(value);
        }
    );
    return resultSome;
}

template<typename Data>
bool DictionaryContainer<Data>::InsertSome(MutableMappableContainer<Data>&& cont){
    bool resultSome = false;
    cont.Map(
        [this, &resultSome] (Data& value) {
            resultSome |= Insert(std::move(value));
        }
    );
    return resultSome;
}

template<typename Data>
bool DictionaryContainer<Data>::RemoveSome(const MappableContainer<Data>& cont){
    bool resultSome = false;
    cont.Map(
        [this, &resultSome] (const Data& value) {
            resultSome |= Remove(value);
        }
    );
    return resultSome;
}

/* ************************************************************************** */

}
