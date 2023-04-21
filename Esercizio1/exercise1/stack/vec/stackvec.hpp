
#ifndef STACKVEC_HPP
#define STACKVEC_HPP
#define initial_size_stack 10

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : virtual public Stack<Data>,
                 virtual protected Vector<Data> {

private:

  const double expand_check = 1;
  const double expand_set = 2;
  const double reduce_check = 0.5;
  const double reduce_set = 0.75;

protected:

  using Vector<Data>::Elements;
  using Container::size;
  ulong number_elements = 0;
  
public:

  // Default constructor
  StackVec() : Vector<Data>(10) {};

  /* ************************************************************************ */

  // Specific constructor
  StackVec(const MappableContainer<Data>& cont); // A stack obtained from a MappableContainer
  StackVec(MutableMappableContainer<Data>&& cont) noexcept; // A stack obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec& right);

  // Move constructor
  StackVec(StackVec&& right) noexcept;
  
  /* ************************************************************************ */

  // Destructor
  ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackVec<Data>& operator=(const StackVec& right);

  // Move assignment
  StackVec<Data>& operator=(StackVec&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackVec& right) const noexcept;
  bool inline operator!=(const StackVec& right) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  const Data& Top() const override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  Data& Top() override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  void Pop() override; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  void Push(const Data& elem) override; // Override Stack member (copy of the value)
  void Push(Data&& elem) override; // Override Stack member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  bool Empty() const noexcept override { return number_elements==0; } // Override Container member
  // Va verificato il riempimento e non la dimensione
  ulong Size() const noexcept override { return number_elements; } // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear(); // Override ClearableContainer member

protected:

  // Auxiliary member functions

  void Expand();
  void Reduce();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif