
#include <stdexcept>

/* ************************************************************************** */

namespace lasd { 

/* ************************************************************************** */

template<typename Data>
bool DictionaryContainer<Data>::InsertAll(const MappableContainer<Data>& cont){
    bool resultAll = true;
    cont.Map(
        [this, &resultAll] (const Data& dat) {
            resultAll &= Insert(dat);
        }
    );
    return resultAll;
}

template<typename Data>
bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& cont){
    bool resultAll = true;
    cont.Map(
        [this, &resultAll] (Data& dat) {
            resultAll &= Insert(std::move(dat));
        }
    );
    return resultAll;
}

template<typename Data>
bool DictionaryContainer<Data>::RemoveAll(const MappableContainer<Data>& cont){
    bool resultAll = true;
    cont.Map(
        [this, &resultAll] (const Data& dat) {
            resultAll &= Remove(dat);
        }
    );
    return resultAll;
}

template<typename Data>
bool DictionaryContainer<Data>::InsertSome(const MappableContainer<Data>& cont){
    bool resultAll = false;
    cont.Map(
        [this, &resultAll] (const Data& dat) {
            resultAll |= Insert(dat);
        }
    );
    return resultAll;
}

template<typename Data>
bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& cont){
    bool resultAll = false;
    cont.Map(
        [this, &resultAll] (Data& dat) {
            resultAll |= Insert(std::move(dat));
        }
    );
    return resultAll;
}

template<typename Data>
bool DictionaryContainer<Data>::RemoveSome(const MappableContainer<Data>& cont){
    bool resultAll = false;
    cont.Map(
        [this, &resultAll] (const Data& dat) {
            resultAll |= Remove(dat);
        }
    );
    return resultAll;
}

/* ************************************************************************** */

}
