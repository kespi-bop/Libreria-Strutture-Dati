
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
  StackLst(MappableContainer<Data>&& cont) noexcept : List<Data>::List(std::move(cont)) {;}// A queue obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackLst(const StackLst& cont) : List<Data>::List(cont) { ; }

  // Move constructor
  StackLst(StackLst&& cont) noexcept : List<Data>::List(std::move(cont)){ ; }

  /* ************************************************************************ */

  // Destructor
  virtual ~StackLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackLst<Data>& operator=(const StackLst& right);

  // Move assignment
  StackLst<Data>& operator=(StackLst&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackLst& right) const noexcept { return this->List<Data>::operator==(right); }
  bool operator!=(const StackLst& right) const noexcept { return this->List<Data>::operator!=(right); }

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
