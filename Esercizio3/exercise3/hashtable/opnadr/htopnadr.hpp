
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
// #include ...

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : virtual public HashTable<Data> {
                        // Must extend HashTable<Data>

private:

  // ...

protected:

  // using HashTable<Data>::???;

  // ...

public:

  // Default constructor
  HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Specific constructors
  HashTableOpnAdr(ulong size); // A hash table of a given size
  HashTableOpnAdr(const MappableContainer<Data>& right); // A hash table obtained from a MappableContainer
  HashTableOpnAdr(ulong size, const MappableContainer<Data>& right); // A hash table of a given size obtained from a MappableContainer
  HashTableOpnAdr(MutableMappableContainer<Data>&& right) noexcept; // A hash table obtained from a MutableMappableContainer
  HashTableOpnAdr(ulong size, MutableMappableContainer<Data>&& right); // A hash table of a given size obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HashTableOpnAdr(const HashTableOpnAdr& right);

  // Move constructor
  HashTableOpnAdr(HashTableOpnAdr&& right) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTableOpnAdr& operator=(const HashTableOpnAdr& right);

  // Move assignment
  HashTableOpnAdr& operator=(HashTableOpnAdr&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(HashTableOpnAdr& right) const noexcept;
  bool operator!=(HashTableOpnAdr& right) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data& element) override; // Override DictionaryContainer member (Copy of the value)
  bool Insert(Data&& element) override; // Override DictionaryContainer member (Move of the value)
  bool Remove(const Data& element) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data& element) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  virtual void Resize(const ulong new_size) override; // Resize the hashtable to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  virtual void Clear() override; // Override Container member

protected:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
  // type Find(argument) specifiers;
  // type FindEmpty(argument) specifiers;
  // type Remove(argument) specifiers;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
