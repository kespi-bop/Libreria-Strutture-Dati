
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer {
                        // Must extend MutablePreOrderMappableContainer<Data>,
                        //             MutablePostOrderMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~LinearContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is possible.

  /* ************************************************************************ */

  // Specific member functions

  // type operator[](argument) specifiers; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
  // type operator[](argument) specifiers; // (mutable version; concrete function must throw std::out_of_range when out of range)

  // type Front() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  // type Front() specifiers; // (mutable version; concrete function must throw std::length_error when empty)

  // type Back() specifiers; // (non-mutable version; concrete function must throw std::length_error when empty)
  // type Back() specifiers; // (mutable version; concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderFoldableContainer)

  // type PreOrderFold(arguments) specifiers; // Override PreOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderFoldableContainer)

  // type PostOrderFold(arguments) specifiers; // Override PostOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFunctor;

  // type Map(argument) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // type Map(argument) specifiers; // Override MutableMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePreOrderMappableContainer)

  // type PreOrderMap(argument) specifiers; // Override MutablePreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePostOrderMappableContainer)

  // type PostOrderMap(argument) specifiers; // Override MutablePostOrderMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer {
                                // Must extend LinearContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~SortableLinearContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types is possible.

  /* ************************************************************************ */

  // Specific member function

  // type Sort() specifiers;

};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
