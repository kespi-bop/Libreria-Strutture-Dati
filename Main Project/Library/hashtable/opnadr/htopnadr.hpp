
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include <bitset>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data> {

private:

  enum Flag{
    empt,
    dirty,
    valid 
  };

protected:

  using Container::size;
  using HashTable<Data>::HashKey;
  using HashTable<Data>::tableSize;

  Data* table = nullptr;
  Flag* tableFlag = nullptr;

public:

  using DictionaryContainer<Data>::InsertAll;
  using DictionaryContainer<Data>::InsertSome;
  using DictionaryContainer<Data>::RemoveAll;
  using DictionaryContainer<Data>::RemoveSome;

  // Default constructor
  HashTableOpnAdr() {
    table = new Data[tableSize] {};
    tableFlag = new Flag[tableSize] {};
  };

  /* ************************************************************************ */

  // Specific constructors
  HashTableOpnAdr(const ulong newSize); // A hash table of a given size
  HashTableOpnAdr(const MappableContainer<Data>& right); // A hash table obtained from a MappableContainer
  HashTableOpnAdr(const ulong newSize, const MappableContainer<Data>& right); // A hash table of a given size obtained from a MappableContainer
  HashTableOpnAdr(MutableMappableContainer<Data>&& right) noexcept; // A hash table obtained from a MutableMappableContainer
  HashTableOpnAdr(const ulong newSize, MutableMappableContainer<Data>&& right) noexcept; // A hash table of a given size obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HashTableOpnAdr(const HashTableOpnAdr& right);

  // Move constructor
  HashTableOpnAdr(HashTableOpnAdr&& right) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~HashTableOpnAdr() {
    delete[] table;
    delete[] tableFlag;
  };

  /* ************************************************************************ */

  // Copy assignment
  HashTableOpnAdr& operator=(const HashTableOpnAdr& right);

  // Move assignment
  HashTableOpnAdr& operator=(HashTableOpnAdr&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableOpnAdr& right) const noexcept;
  bool inline operator!=(const HashTableOpnAdr& right) const noexcept {
    return !(operator==(right));
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  virtual bool Insert(const Data& element) override; // Override DictionaryContainer member (Copy of the value)
  virtual bool Insert(Data&& element) override; // Override DictionaryContainer member (Move of the value)
  virtual bool Remove(const Data& element) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  virtual bool Exists(const Data& element) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  virtual void Resize(const ulong newSize); // Resize the hashtable to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  virtual void Clear() override; // Override Container member

protected:

  // Auxiliary member functions
  ulong HashKey(const Data& key, ulong& prob_index) const noexcept;
  bool Find(ulong& index, ulong& prob_index, const Data& element) const noexcept;
  ulong FindEmpty(const Data &element, ulong& prob_index) const noexcept;
  bool Remove(ulong& prob_index, const Data &key) noexcept;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
