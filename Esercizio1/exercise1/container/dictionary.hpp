
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "testable.hpp"
#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer : virtual public TestableContainer<Data>{


private:

protected:

public:

  // Destructor
  ~DictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  DictionaryContainer& operator=(const DictionaryContainer& other) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  DictionaryContainer& operator=(DictionaryContainer&& other) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const DictionaryContainer& other) const noexcept = delete; 
  bool operator!=(const DictionaryContainer& other) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  bool Insert(Data& val) = 0; // Copy of the value
  bool Insert(Data&& val) = 0; // Move of the value
  bool Remove(Data& val) = 0;

  bool InsertAll(const MappableContainer<Data>&); // Copy of the value; From MappableContainer; True if all are inserted
  bool InsertAll(MappableContainer<Data>&&); // Move of the value; From MutableMappableContainer; True if all are inserted
  bool RemoveAll(const MappableContainer<Data>&); // From MappableContainer; True if all are removed

  bool InsertSome(const MappableContainer<Data>&); // Copy of the value; From MappableContainer; True if some is inserted
  bool InsertSome(MappableContainer<Data>&&); // Move of the value; From MutableMappableContainer; True if some is inserted
  bool RemoveSome(const MappableContainer<Data>&); // From MappableContainer; True if some is removed

};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
