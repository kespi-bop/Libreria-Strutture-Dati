#include "htopnadr.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong size) {
    tableSize = std::pow(2, std::floor(log2(size)) + 1);
    table = new Data[tableSize];
    tableFlag = new std::bitset<2>[tableSize];
}


template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const MappableContainer<Data> &right) {
    tableSize = std::pow(2, std::floor(log2(right.size)) + 2);
    table = new Data[tableSize];
    tableFlag = new std::bitset<2>[tableSize];
    InsertAll(right);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong size, const MappableContainer<Data> &right) {
    tableSize = std::pow(2, std::floor(log2(size)) + 1);
    std::cout<<"logaritmo: "<<log2(size) + 1<<" -> ASDADASDAS: "<<tableSize;
    table = new Data[tableSize];
    tableFlag = new std::bitset<2>[tableSize];
    InsertAll(right);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MutableMappableContainer<Data> &&right) noexcept {
    tableSize = std::pow(2, std::floor(log2(right.size)) + 2);
    table = new Data[tableSize];   
    tableFlag = new std::bitset<2>[tableSize];
    InsertAll(std::move(right));
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong size, MutableMappableContainer<Data> &&right) noexcept {
    tableSize = std::pow(2, std::floor(log2(size)) + 1);
    table = new Data[tableSize];
    tableFlag = new std::bitset<2>[tableSize];
    InsertAll(std::move(right));
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr &right) {
    tableSize = right.tableSize;
    table = new Data[tableSize];
    tableFlag = new std::bitset<2>[tableSize];
    for(ulong i = 0; i < tableSize; i++) {
        if(right.tableFlag[i].all()) { //controllo che sia valido, quindi che abbia tutti i bit a 1
            Insert(right.table[i]);     
        }
    }
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr &&right) noexcept {
    std::swap(tableSize, right.tableSize);
    std::swap(table, right.table);
    std::swap(tableFlag, right.tableFlag);
    std::swap(size, right.size);
}

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr &right) {
    Clear();
    tableSize = right.tableSize;
    table = new Data[tableSize];
    tableFlag = new std::bitset<2>[tableSize];
    for(ulong i = 0; i < tableSize; i++) {
        if(right.tableFlag[i].all()) { //controllo che sia valido, quindi che abbia tutti i bit a 1
            Insert(right.table[i]);     
        }
    }
    return *this;
}

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr &&right) noexcept {
    std::swap(tableSize, right.tableSize);
    std::swap(table, right.table);
    std::swap(tableFlag, right.tableFlag);
    std::swap(size, right.size);
    return *this;
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr &right) const noexcept {
    if(size != right.Size()) {
        return false;
    }
    for(ulong i = 0; i < tableSize; i++) {
        if(tableFlag[i].all()) {
            if(!right.Exists(table[i])) {
                return false;
            }
        }
    }
    return true;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data &element)
{
    ulong index = HashKey(Hashable<Data>()(element));
    if(tableFlag[index].all()) {
        FindEmpty(index, element);
        table[index] = element;
        tableFlag[index].set();
        if(Find(index, element)) {
            tableFlag[index].set(0, false);
            return false;
        } else {
            size++;
            return true;
        }
    } else {
        table[index] = element;
        tableFlag[index].set();
        size++;
        return true;
    }
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data &&element) {
    ulong index = HashKey(Hashable<Data>()(element));
    if(tableFlag[index].all()) {
        FindEmpty(index, element);
        table[index] = element;
        tableFlag[index].set();
        if(Find(index, element)) {
            tableFlag[index].set(0, false);
            return false;
        } else {
            size++;
            return true;
        }
    } else {
        table[index] = element;
        tableFlag[index].set();
        size++;
        return true;
    }
}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data &element) {
    if(!Exists(element)) {
        return false;
    }
    ulong index = HashKey(Hashable<Data>()(element));
    if(tableFlag[index].all()){
        tableFlag[index].set(0,false);
        size--;
        return true;
    }
    else {
        Remove(index, element);
    }
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data &element) const noexcept {
    ulong index = HashKey(Hashable<Data>()(element));
    if(table[index] == element) {
        return true;
    } else {
        return Find(index, element);
    }
}

template <typename Data>
void HashTableOpnAdr<Data>::Resize(const ulong new_size) {
    ulong tmptableSize = std::pow(2, std::floor(log2(new_size)) + 1);
    Data* tmpTable = new Data[tmptableSize];
    std::bitset<2>* tmpTableFlag = new std::bitset<2>[tmptableSize];

    std::swap(tmptableSize, tableSize);
    std::swap(tmpTable, table);
    std::swap(tmpTableFlag, tableFlag);

    for(int i = 0; i < tmptableSize; i++){
        if(tmpTableFlag[i].all()) {
            Insert(tmpTable[i]);
        }
    }   
}

template <typename Data>
void HashTableOpnAdr<Data>::Clear() {
    for(ulong i = 0; i < tableSize; i++) {
        tableFlag[i].set(false);
    }
    size = 0;
}

template <typename Data>
ulong HashTableOpnAdr<Data>::HashKey(ulong index, const ulong key) const noexcept {
    return (index + 1) % tableSize;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Find(ulong &index, const Data &element) const noexcept {
    static ulong proping = 0; 
    index = HashKey(index, Hashable<Data>()(element));
    proping++;
    if(tableFlag[index].all()) {
        if(table[index] == element) {
            return true;
        }
    }
    if(proping == tableSize) {
        return false;
    }
    return Find(index, element);
}

template <typename Data>
bool HashTableOpnAdr<Data>::FindEmpty(ulong &index, const Data &element) const noexcept
{
    while(tableFlag[index].all()) {
        index = HashKey(index, Hashable<Data>()(element));
    }
    return true;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(ulong &index, const Data &key) noexcept {
    index = HashKey(index, Hashable<Data>()(key));
    if(table[index] == key) {
        tableFlag[index].set(0,false);
        size--;
        return true;
    } else {
        return Remove(index, key);
    }
}

/* ************************************************************************** */

}
