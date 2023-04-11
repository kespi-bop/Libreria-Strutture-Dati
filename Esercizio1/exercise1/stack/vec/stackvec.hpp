
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : public virtual Stack<Data>,
                 protected virtual Vector<Data>{
                  // Must extend Stack<Data>,
                  //             Vector<Data>

private:

  // ...

protected:

  using Vector<Data>::size;
  using Vector<Data>::Elements;
  ulong ActualDimension;
  // ...

public:

  // Default constructor
  StackVec() : Vector<Data>::Vector(){ Elements = new Data[8]; }

  /* ************************************************************************ */

  // Specific constructor
  StackVec(const MappableContainer<Data>& right) : Vector<Data>::Vector(right){ Elements = new Data[8]; } // A stack obtained from a MappableContainer
  StackVec(MappableContainer<Data>&& right) noexcept : Vector<Data>::Vector(right) { Elements = new Data[8]; } // A stack obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec& right) : Vector<Data>::Vector(right) { ; }

  // Move constructor
  StackVec(StackVec&& right) noexcept : Vector<Data>::Vector(right){ right.Clear(); }

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
  bool operator!=(const StackVec& right) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  virtual const Data& Top() const; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  virtual Data& Top(); // Override Stack member (non-mutable version; must throw std::length_error when empty)
  virtual void Pop(); // Override Stack member (must throw std::length_error when empty)
  virtual Data& TopNPop(); // Override Stack member (must throw std::length_error when empty)
  virtual void Push(const Data& elem); // Override Stack member (copy of the value)
  virtual void Push(Data&& elem); // Override Stack member (move of the value)
  
  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  virtual inline bool Empty() const noexcept override { return (ActualDimension == 0); }; // Override Container member

  virtual inline ulong Size() const noexcept { return ActualDimension; }; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary member functions

  virtual void Expand();
  virtual void Reduce() noexcept;

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
