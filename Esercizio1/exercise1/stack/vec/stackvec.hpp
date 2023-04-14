
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

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

  const double const_exp_check = 0.75;
  const double const_exp_set = 1.5;
  const double const_red_check = 0.5;
  const double const_red_set = 0.75;
  const ulong const_init_size = 5;

protected:

  using Vector<Data>::Elements;
  

public:

  ulong riempimento = 0;
  using Container::size;

  // Default constructor
  StackVec();
    

  /* ************************************************************************ */

  // Specific constructor
  StackVec(const MappableContainer<Data>& cont); // A stack obtained from a MappableContainer
  StackVec(MappableContainer<Data>&& cont) noexcept; // A stack obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec& other);

  // Move constructor
  StackVec(StackVec&& other) noexcept;
  
  /* ************************************************************************ */

  // Destructor
  ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackVec<Data>& operator=(const StackVec& other);

  // Move assignment
  StackVec<Data>& operator=(StackVec&& other) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackVec& other) const noexcept;
  bool operator!=(const StackVec& other) const noexcept;

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

  bool Empty() const noexcept override { return riempimento==0; } // Override Container member
  // Va verificato il riempimento e non la dimensione
  ulong Size() const noexcept override { return riempimento; } // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear(); // Override ClearableContainer member

protected:

  // Auxiliary member functions

  void CheckNExpand();
  void CheckNReduce();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif