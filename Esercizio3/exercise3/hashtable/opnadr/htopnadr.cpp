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
    delete[] table;
    delete[] tableFlag;
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
bool HashTableOpnAdr<Data>::Insert(const Data &element) {
    if(size * 2 >= tableSize) {
        Resize(tableSize * 2);
    }
    ulong index = HashKey(Hashable<Data>()(element));
    index = FindEmpty(index, element);
    if(!tableFlag[index].all()){
        table[index] = element;
        tableFlag[index].set();
        size++;
        return !Remove(index, element); 
    }
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data &&element) {
    if(size * 2 >= tableSize) {
        Resize(tableSize * 2);
    }
    ulong index = HashKey(Hashable<Data>()(element));
    index = FindEmpty(index, element);
    if(!tableFlag[index].all()){
        std::swap(table[index],element);
        tableFlag[index].set();
        size++;
        return !Remove(index, element); 
    }
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data &element) {
    if(size < tableSize/4) {
        Resize(tableSize/2);
    }
    ulong index = HashKey(Hashable<Data>()(element));
    if(tableFlag[index].all() && table[index] == element){
        tableFlag[index].set(1,false);
        size--;
        return true;
    }
    return Remove(index, element);
}

template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data &element) const noexcept {
    ulong index = HashKey(Hashable<Data>()(element));
    return Find(index, element);
}

template <typename Data>
void HashTableOpnAdr<Data>::Resize(const ulong new_size) {
    ulong tmptableSize;
    if(new_size <= 8) {
        tmptableSize = 8;
    } else {
        tmptableSize = std::pow(2, std::floor(log2(new_size)) + 1); 
    }

    Data* tmpTable = new Data[tmptableSize];
    std::bitset<2>* tmpTableFlag = new std::bitset<2>[tmptableSize];

    this->size = 0;
    std::swap(tmptableSize, tableSize);
    std::swap(tmpTable, table);
    std::swap(tmpTableFlag, tableFlag);

    for(ulong i = 0; i < tmptableSize; i++){
        if(tmpTableFlag[i].all()) {
            Insert(tmpTable[i]);
        }
    }   
    delete[] tmpTable;
    delete[] tmpTableFlag;
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
    ulong prob_index = 0;
    ulong tmp_index = index;
    do{
        if(prob_index == tableSize-1) return false;
        if(table[tmp_index]==element && tableFlag[tmp_index].all()) {
            index=tmp_index;
            return true;
        }
        tmp_index = HashKey(index, Hashable<Data>()(element));
        prob_index++;
    }while(!tableFlag[tmp_index].none());
    return false;
}

template <typename Data>
ulong HashTableOpnAdr<Data>::FindEmpty(ulong &index, const Data &element) const noexcept
{
    ulong prob_index = 0;
    while(tableFlag[index].all() && table[index]!=element) {   
        index = HashKey(index, Hashable<Data>()(element));
        prob_index++;
    }
    return index;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(ulong &index, const Data &key) noexcept {
    ulong prob_index = 0;
    index = HashKey(index, Hashable<Data>()(key));
    prob_index++;
    if(Find(index, key)){
        tableFlag[index].set(1, false);
        size--;
        return true;
    }
    return false;
}

/* ************************************************************************** */

}
