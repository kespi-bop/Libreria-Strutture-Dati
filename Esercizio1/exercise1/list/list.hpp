
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/dictionary.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List {
              // Must extend ClearableContainer,
              //             DictionaryContainer<Data>,
              //             LinearContainer<Data>

private:

  // ...

protected:

  // using Container::???;

  struct Node {

    // Data
    // ...

    /* ********************************************************************** */

    // Specific constructors
    // ...

    /* ********************************************************************** */

    // Copy constructor
    // ...

    // Move constructor
    // ...

    /* ********************************************************************** */

    // Destructor
    // ...

    /* ********************************************************************** */

    // Comparison operators
    // ...

    /* ********************************************************************** */

    // Specific member functions

    // ...

  };

  // ...

public:

  // Default constructor
  // List() specifiers;

  /* ************************************************************************ */

  // Specific constructor
  // List(argument) specifiers; // A list obtained from a MappableContainer
  // List(argument) specifiers; // A list obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  // List(argument) specifiers;

  // Move constructor
  // List(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~List() specifiers;

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

  // Specific member functions

  // type InsertAtFront(argument) specifier; // Copy of the value
  // type InsertAtFront(argument) specifier; // Move of the value
  // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
  // type FrontNRemove() specifier; // (must throw std::length_error when empty)

  // type InsertAtBack(argument) specifier; // Copy of the value
  // type InsertAtBack(argument) specifier; // Move of the value

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  // type Insert(argument) specifier; // Copy of the value
  // type Insert(argument) specifier; // Move of the value
  // type Remove(argument) specifier;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  // type operator[](argument) specifiers; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  // type Front() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  // type Front() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  // type Back() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  // type Back() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

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

protected:

  // Auxiliary member functions (for PreOrderFoldableContainer & PostOrderFoldableContainer)

  // type PreOrderFold(arguments) specifiers; // Accessory function executing from one point of the list onwards
  // type PostOrderFold(arguments) specifiers; // Accessory function executing from one point of the list onwards

  /* ************************************************************************ */

  // Auxiliary member functions (for PreOrderMappableContainer & PostOrderMappableContainer)

  // type PreOrderMap(arguments) specifiers; // Accessory function executing from one point of the list onwards
  // type PostOrderMap(arguments) specifiers; // Accessory function executing from one point of the list onward

  /* ************************************************************************ */

  // Auxiliary member functions (for MutablePreOrderMappableContainer & MutablePostOrderMappableContainer)

  // type PreOrderMap(arguments) specifiers; // Accessory function executing from one point of the list onwards
  // type PostOrderMap(arguments) specifiers; // Accessory function executing from one point of the list onward

  /* ************************************************************************ */

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
