
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Stack : virtual public ClearableContainer {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~Stack() = default;

  /* ************************************************************************ */

  // Copy assignment
  Stack& operator=(const Stack& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  Stack& operator=(Stack&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Stack& right) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const Stack& right) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data& Top() const = 0; // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual Data& Top() = 0; // (mutable version; concrete function must throw std::length_error when empty)
  virtual void Pop() = 0; // (concrete function must throw std::length_error when empty)
  virtual Data TopNPop() = 0; // (concrete function must throw std::length_error when empty)
  virtual void Push(const Data& elem) = 0; // Copy of the value
  virtual void Push(Data&& elem) = 0; // Move of the value

};

/* ************************************************************************** */

}

#endif
