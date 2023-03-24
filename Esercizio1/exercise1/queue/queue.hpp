
#ifndef QUEUE_HPP
#define QUEUE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Queue {
              // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~Queue() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Head() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  // type Head() specifiers; // (mutable version; concrete function must throw std::length_error when empty)
  // type Dequeue() specifiers; // (concrete function must throw std::length_error when empty)
  // type HeadNDequeue() specifiers; // (concrete function must throw std::length_error when empty)
  // type Enqueue(argument) specifiers; // Copy of the value
  // type Enqueue(argument) specifiers; // Move of the value

};

/* ************************************************************************** */

}

#endif
