
#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */

#include "container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TestableContainer : virtual public Container {

private:

protected:

public:

  // Destructor
  ~TestableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  TestableContainer& operator=(const TestableContainer& other) = delete;

  // Move assignment
  TestableContainer& operator=(TestableContainer&& other) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const TestableContainer& other) const noexcept = delete; 
  bool operator!=(const TestableContainer& other) const noexcept = delete; 

  /* ************************************************************************ */

  // Specific member function

  virtual bool Exists(const Data& valore) const noexcept = 0; 

};

/* ************************************************************************** */

}

#endif
