
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
  virtual ~DictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  DictionaryContainer& operator=(const DictionaryContainer& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  DictionaryContainer& operator=(DictionaryContainer&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const DictionaryContainer& right) const noexcept = delete; 
  bool operator!=(const DictionaryContainer& right) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Insert(const Data& value) = 0; // Copy of the value
  virtual bool Insert(Data&& value) = 0; // Move of the value
  virtual bool Remove(const Data& value) = 0;

  bool InsertAll(const MappableContainer<Data>& cont); // Copy of the value; From MappableContainer; True if all are inserted
  bool InsertAll(MutableMappableContainer<Data>&& cont); // Move of the value; From MutableMappableContainer; True if all are inserted
  bool RemoveAll(const MappableContainer<Data>& cont); // From MappableContainer; True if all are removed

  bool InsertSome(const MappableContainer<Data>& cont); // Copy of the value; From MappableContainer; True if some is inserted
  bool InsertSome(MutableMappableContainer<Data>&& cont); // Move of the value; From MutableMappableContainer; True if some is inserted
  bool RemoveSome(const MappableContainer<Data>& cont); // From MappableContainer; True if some is removed

};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
