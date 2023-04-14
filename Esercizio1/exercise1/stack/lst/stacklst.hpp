
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst :  virtual public Stack<Data>,
                  virtual protected List<Data> {
                  // Must extend Stack<Data>,
                  //             List<Data>

private:

  // ...

protected:

  using List<Data>::List;
  // ...

public:

  // Default constructor
  StackLst() : List<Data>::List() {;}

  /* ************************************************************************ */

  // Specific constructor
  StackLst(const MappableContainer<Data>& cont) : List<Data>::List(cont) {;} // A queue obtained from a MappableContainer
  StackLst(MappableContainer<Data>&& cont) noexcept : List<Data>::List(cont) {;}// A queue obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackLst(const StackLst& cont) : List<Data>::List(cont) { ; }

  // Move constructor
  StackLst(StackLst&& cont) noexcept : List<Data>::List(cont){ ; }

  /* ************************************************************************ */

  // Destructor
  virtual ~StackLst() {
    while(!(List<Data>::Empty())) List<Data>::RemoveFromFront();
  }

  /* ************************************************************************ */

  // Copy assignment
  StackLst<Data>& operator=(const StackLst& other);

  // Move assignment
  StackLst<Data>& operator=(StackLst&& other) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackLst& other) const noexcept { return this->List<Data>::operator==(other); }
  bool operator!=(const StackLst& other) const noexcept { return this->List<Data>::operator!=(other); }

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  const Data& Top() const override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  Data& Top() override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  void Pop() override; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  void Push(const Data& elem) override; // Override Stack member (copy of the value)
  void Push(Data&& elem) override; // Override Stack member (move of the value)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
