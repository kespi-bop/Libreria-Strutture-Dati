
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector {
                // Must extend ResizableContainer,
                //             SortableLinearContainer<Data>

private:

  // ...

protected:

  // using Container::???;

  // ...

public:

  // Default constructor
  // Vector() specifiers;

  /* ************************************************************************ */

  // Specific constructors
  // Vector(argument) specifiers; // A vector with a given initial dimension
  // Vector(argument) specifiers; // A vector obtained from a MappableContainer
  // Vector(argument) specifiers; // A vector obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  // Vector(argument) specifiers;

  // Move constructor
  // Vector(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~Vector() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Override ResizableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  // type operator[](argument) specifiers; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  // type Front() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  // type Front() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  // type Back() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  // type Back() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from SortableLinearContainer)

  // type Sort() specifiers; // Override SortableLinearContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
