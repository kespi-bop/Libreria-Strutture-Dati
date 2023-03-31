
#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */

#include "container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TestableContainer : virtual public Container{
                          // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~TestableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  virtual TestableContainer& operator=(const TestableContainer& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual TestableContainer&& operator=(TestableContainer&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const TestableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.
  virtual bool operator!=(const TestableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  virtual bool Exists(const void* element) const noexcept = 0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

}

#endif
