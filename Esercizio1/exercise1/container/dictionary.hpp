
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
                            // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~DictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  virtual DictionaryContainer& operator=(const DictionaryContainer& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual DictionaryContainer& operator=(DictionaryContainer&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  virtual bool operator==(const DictionaryContainer& right) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  virtual bool operator!=(const DictionaryContainer& right) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Insert(argument) specifiers; // Copy of the value
  bool Insert(const Data& value) = 0;
  // type Insert(argument) specifiers; // Move of the value
  bool Insert(Data&& value) = 0;
  // type Remove(argument) specifiers;
  bool Remove(Data& value) = 0;

  // type InsertAll(argument) specifiers; // Copy of the value; From MappableContainer; True if all are inserted
  bool InsertAll(const MappableContainer<Data>& con);
  // type InsertAll(argument) specifiers; // Move of the value; From MutableMappableContainer; True if all are inserted
  bool InsertAll(const MappableContainer<Data>&& con);
  // type RemoveAll(argument) specifiers; // From MappableContainer; True if all are removed
  bool RemoveAll(const MappableContainer<Data>& con);

  // type InsertSome(argument) specifiers; // Copy of the value; From MappableContainer; True if some is inserted
  bool InsertSome(const MappableContainer<Data>& con);
  // type InsertSome(argument) specifiers; // Move of the value; From MutableMappableContainer; True if some is inserted
  bool InsertSome(const MappableContainer<Data>&& con);
  // type RemoveSome(argument) specifiers; // From MappableContainer; True if some is removed
  bool RemoveSome(const MappableContainer<Data>& con);

};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
