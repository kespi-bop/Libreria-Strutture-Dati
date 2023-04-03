
#include <stdexcept>

/* ************************************************************************** */

namespace lasd { 

/* ************************************************************************** */

template<typename Data>
bool DictionaryContainer<Data>::InsertAll(const MappableContainer<Data>& vals){
    bool result = true;
    vals.Map(
        [this, &result] (const Data& dat) {
            result &= Insert(dat);
        }
    );
    return result;
}

template<typename Data>
bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& vals){
    bool result = true;
    vals.Map(
        [this, &result] (const Data& dat) {
            result &= Insert(std::move(dat));
        }
    );
    return result;
}

template<typename Data>
bool DictionaryContainer<Data>::RemoveAll(const MappableContainer<Data>& vals){
    bool result = true;
    vals.Map(
        [this, &result] (const Data& dat) {
            result &= Remove(dat);
        }
    );
    return result;
}

template<typename Data>
bool DictionaryContainer<Data>::InsertSome(const MappableContainer<Data>& vals){
    bool result = false;
    vals.Map(
        [this, &result] (const Data& dat) {
            result |= Insert(dat);
        }
    );
    return result;
}

template<typename Data>
bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& vals){
    bool result = false;
    vals.Map(
        [this, &result] (const Data& dat) {
            result |= Insert(std::move(dat));
        }
    );
    return result;
}

template<typename Data>
bool DictionaryContainer<Data>::RemoveSome(const MappableContainer<Data>& vals){
    bool result = false;
    vals.Map(
        [this, &result] (const Data& dat) {
            result |= Remove(dat);
        }
    );
    return result;
}

/* ************************************************************************** */

}
