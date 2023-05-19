#include "htclsadr.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline HashTableClsAdr<Data>::HashTableClsAdr(const ulong size) {
    tableSize = std::pow(2, log2(size) + 1);
    table = new lasd::List<Data>[tableSize];
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const MappableContainer<Data>& right) {
    tableSize = std::pow(2, log2(right.Size()) + 1);
    table = new lasd::List<Data>[tableSize];
    InsertAll(right);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong size, const MappableContainer<Data>& right) {
    tableSize = std::pow(2, log2(size) + 1);
    table = new lasd::List<Data>[tableSize];
    InsertAll(right);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MutableMappableContainer<Data>&& right) noexcept {
    tableSize = std::pow(2, log2(right.Size()) + 1);
    table = new lasd::List<Data>[tableSize];
    InsertAll(std::move(right));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong size, MutableMappableContainer<Data>&& right) noexcept {
    tableSize = std::pow(2, log2(size) + 1);
    table = new lasd::List<Data>[tableSize];
    InsertAll(std::move(right));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& right) {
    tableSize = right.tableSize;
    table = new lasd::List<Data>[tableSize];
    for(ulong i = 0; i < tableSize; i++) {
        InsertAll(right.table[i]);
    }
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& right) noexcept {
    std::swap(tableSize, right.tableSize);
    std::swap(size, right.size);
    std::swap(table, right.table);
}

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data>& right) {
    Clear();
    delete[] table;
    tableSize = right.tableSize;
    table = new lasd::List<Data>[tableSize];
    for(ulong i = 0; i < tableSize; i++) {
        InsertAll(right.table[i]);
    }
    return *this;
}

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data> &&right) noexcept {
    std::swap(tableSize, right.tableSize);
    std::swap(size, right.size);
    std::swap(table, right.table);
    return *this;
}

template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data> &right) const noexcept
{
    if(right.size != size) {
        return false;
    }
    for(ulong i = 0; i < tableSize; i++){
            bool result = true;
            table[i].Map(
                [&right, &result](const Data& dat){
                    ulong index = right.HashKey(Hashable<Data>()(dat));
                    if(!right.Exists(dat)){
                        result = false;
                        return;
                    }
                }
            );
            if(!result) {
                return false;
            }
    }
    return true;
}

template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data &value) {
    bool result = false;
    ulong index = this->HashKey(Hashable<Data>()(value));
    result = table[index].Insert(value);
    if(result) {
        size++;
    }
    return result;
}

template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data &&value)
{
    bool result = false;
    ulong index = this->HashKey(Hashable<Data>()(std::move(value)));
    result = table[index].Insert(std::move(value));
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
    result = table[index].List<Data>::Remove(value);
    if(result) {
        size--;
    }
    return result;
}

template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data &value) const noexcept {
    ulong index = this->HashKey(Hashable<Data>()(value));
    if(table[index].Exists(value)) {
        return true;
    }
    return false;
}

template <typename Data>
void HashTableClsAdr<Data>::Resize(const ulong new_size) {
    ulong newTableSize;
    if(new_size <= 8) {
        newTableSize = 8;
    } else {
        newTableSize = std::pow(2, log2(new_size) + 1); 
    }
    this->size = 0;
    List<Data>* newTable = new List<Data>[newTableSize];
    std::swap(newTable, table);
    std::swap(newTableSize, tableSize);
    for(ulong i = 0; i < newTableSize; i++){
        InsertAll(newTable[i]);
    }
    delete[] newTable;
}

template <typename Data>
void HashTableClsAdr<Data>::Clear() {
    delete[] table;
    table = new List<Data>[tableSize];
    size = 0;
}
/* ************************************************************************** */
}
