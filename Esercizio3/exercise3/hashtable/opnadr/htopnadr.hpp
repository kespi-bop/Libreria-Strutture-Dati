
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

  // ...

protected:
  using DictionaryContainer<Data>::InsertAll;
  using Container::size;
  using HashTable<Data>::tableSize;
  using HashTable<Data>::HashKey;

  Data* table = nullptr;
  std::bitset<2>* tableFlag; //4 bits = -(00) Empty/Deleted -(01) Empty/Valid(unused)
                            //          -(10) Full/Deleted -(11)Full/Valid

public:

  // Default constructor
  HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Specific constructors
  HashTableOpnAdr(const ulong size); // A hash table of a given size
  HashTableOpnAdr(const MappableContainer<Data>& right); // A hash table obtained from a MappableContainer
  HashTableOpnAdr(const ulong size, const MappableContainer<Data>& right); // A hash table of a given size obtained from a MappableContainer
  HashTableOpnAdr(MutableMappableContainer<Data>&& right) noexcept; // A hash table obtained from a MutableMappableContainer
  HashTableOpnAdr(const ulong size, MutableMappableContainer<Data>&& right) noexcept; // A hash table of a given size obtained from a MutableMappableContainer

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

  virtual void Resize(const ulong new_size); // Resize the hashtable to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  virtual void Clear() override; // Override Container member

protected:

  // Auxiliary member functions

  ulong HashKey(ulong index, const ulong key) const noexcept;
  bool Find(ulong& index, const Data& element) const noexcept;
  ulong FindEmpty(ulong& index, const Data& element) const noexcept;
  bool Remove(ulong& index, const Data& key) noexcept;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
