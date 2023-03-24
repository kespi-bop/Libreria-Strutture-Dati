
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst {
                  // Must extend Queue<Data>,
                  //             List<Data>

private:

  // ...

protected:

  // using List<Data>::???;

  // ...

public:

  // Default constructor
  // QueueLst() specifier;

  /* ************************************************************************ */

  // Specific constructor
  // QueueLst(argument) specifiers; // A queue obtained from a MappableContainer
  // QueueLst(argument) specifiers; // A queue obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  // QueueLst(argument);

  // Move constructor
  // QueueLst(argument);

  /* ************************************************************************ */

  // Destructor
  // ~QueueLst() specifier;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);

  // Move assignment
  // type operator=(argument);

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  // type Head() specifiers; // Override Queue member (mutable version; must throw std::length_error when empty)
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
