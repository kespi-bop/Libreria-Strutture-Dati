
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  ulong operator()(const Data& element) const noexcept = 0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public ResizableContainer,
                  virtual public DictionaryContainer<Data>{

private:

protected:

  ulong tableSize = 0;
  ulong a = 3;
  ulong b = 5;

public:

  // Destructor
  virtual ~HashTable() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTable& operator=(const HashTable& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  HashTable& operator=(HashTable&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTable& right) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.
  bool inline operator!=(HashTable&& right) const noexcept {
    return !(operator==(right));
  } // Comparison of abstract hashtable is possible but not required.

protected:

  // Auxiliary member functions

  ulong HashKey(ulong key) const noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
