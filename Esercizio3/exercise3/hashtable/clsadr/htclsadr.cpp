#include "htclsadr.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline HashTableClsAdr<Data>::HashTableClsAdr(const ulong size) {
    this->tableSize = std::pow(2, log2(size) + 1);
    this->table = new lasd::List<Data>*[tableSize];
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const MappableContainer<Data>& right) {
    this->tableSize = std::pow(2, log2(right.Size()) + 1);
    this->table = new lasd::List<Data>*[tableSize];
    InsertAll(right);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong size, const MappableContainer<Data>& right) {
    this->tableSize = std::pow(2, log2(size) + 1);
    this->table = new lasd::List<Data>*[tableSize];
    InsertAll(right);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MutableMappableContainer<Data>&& right) {
    this->tableSize = std::pow(2, log2(right.Size()) + 1);
    this->table = new lasd::List<Data>*[tableSize];
    InsertAll(std::move(right));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong size, MutableMappableContainer<Data>&& right) {
    this->tableSize = std::pow(2, log2(size) + 1);
    this->table = new lasd::List<Data>*[tableSize];
    InsertAll(std::move(right));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& right) {
    this->tableSize = right.tableSize;
    this->table = new lasd::List<Data>*[tableSize];
    for(ulong i = 0; i < tableSize; i++) {
        InsertAll(*right.table[i]);
    }
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& right) noexcept {
    std::swap(this->tableSize, right.tableSize);
    this->table = new lasd::List<Data>*[tableSize];
    for(ulong i = 0; i < tableSize; i++) {
        InsertAll(std::move(*right.table[i]));
    }
}

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data>& right) {
    Clear();
    this->tableSize = right.tableSize;
    this->table = new lasd::List<Data>*[tableSize];
    for(ulong i = 0; i < tableSize; i++) {
        InsertAll(*right.table[i]);
    }
    return *this;
}

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data> &&right) noexcept {
    Clear();
    std::swap(this->tableSize, right.tableSize);
    this->table = new lasd::List<Data>*[tableSize];
    for(ulong i = 0; i < tableSize; i++) {
        InsertAll(std::move(*right.table[i]));
    }
    return *this;
}

template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data> &right) const noexcept
{
    return true;
}

template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data &value) {
    bool result = false;
    ulong index = this->HashKey(Hashable<Data>()(value));
    if(table[index] == nullptr) {
        table[index] = new List<Data>();
    }
    result = table[index]->Insert(value);
    if(result) {
        size++;
    }
    return result;
}

template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data &&value)
{
    bool result = false;
    ulong index = this->HashKey(Hashable<Data>()(value));
    if(table[index] == nullptr) {
        table[index] = new List<Data>();
    }
    result = table[index]->Insert(std::move(value));
    if(result) {
        size++;
    }
    return result;
}

template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data &value)
{
    bool result = false;
    ulong index = this->HashKey(Hashable<Data>()(value));
    if(table[index] == nullptr) {
        return true;
    }
    result = table[index]->Remove(value);
    if(result) {
        size--;
    }
    return result;
}

template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data &value) const noexcept
{
    for(ulong i = 0; i < tableSize; i++) {
        if(table[i] != nullptr) {
            if(table[i]->Exists(value)){
                return true;
            }
        }
    }
    return false;
}

template <typename Data>
inline void HashTableClsAdr<Data>::Resize(const ulong new_size) {
    this->tableSize = std::pow(2, log2(new_size) + 1);
    this->table = new lasd::List<Data>*[tableSize];
}

template <typename Data>
void HashTableClsAdr<Data>::Clear() {
    for(uint i = 0; i < tableSize; i++) {
        delete table[i];
    }
    this->size = 0;
}
/* ************************************************************************** */
}
