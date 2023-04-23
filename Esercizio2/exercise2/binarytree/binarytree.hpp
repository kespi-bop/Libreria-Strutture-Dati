
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
#include "../queue/vec/queuevec.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree {
                    // Must extend PreOrderMappableContainer<Data>,
                    //             PostOrderMappableContainer<Data>,
                    //             InOrderMappableContainer<Data>,
                    //             BreadthMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  struct Node {

  protected:

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.
    // type operator!=(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.

  public:

    // friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    // ~Node() specifiers

    /* ********************************************************************** */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types should not be possible.

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types should not be possible.

    /* ********************************************************************** */

    // Specific member functions

    // type Element() specifiers; // Immutable access to the element (concrete function should not throw exceptions)

    // type IsLeaf() specifiers; // (concrete function should not throw exceptions)
    // type HasLeftChild() specifiers; // (concrete function should not throw exceptions)
    // type HasRightChild() specifiers; // (concrete function should not throw exceptions)

    // type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    // type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTree() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract binary tree is possible.
  // type operator!=(argument) specifiers; // Comparison of abstract binary tree is possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Root() specifiers; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFunctor;

  // type Map(arguments) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  // type PreOrderMap(arguments) specifiers; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  // type PostOrderMap(arguments) specifiers; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderMappableContainer)

  // type InOrderMap(arguments) specifiers; // Override InOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member

protected:

  // Auxiliary member function (for PreOrderMappableContainer)

  // type PreOrderMap(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for PostOrderMappableContainer)

  // type PostOrderMap(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for InOrderMappableContainer)

  // type InOrderMap(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for BreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Accessory function executing from one node of the tree

};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree {
                          // Must extend ClearableContainer,
                          //             BinaryTree<Data>,
                          //             MutablePreOrderMappableContainer<Data>,
                          //             MutablePostOrderMappableContainer<Data>,
                          //             MutableInOrderMappableContainer<Data>,
                          //             MutableBreadthMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  struct MutableNode {
                        // Must extend Node

    // friend class MutableBinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    // ~MutableNode() specifiers

    /* ********************************************************************** */

    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types should not be possible.

    // Move assignment
    // type operator=(argument); // Move assignment of abstract types should not be possible.

    /* ********************************************************************** */

    // Specific member functions

    // type Element() specifiers; // Mutable access to the element (concrete function should not throw exceptions)

    // type LeftChild() specifiers; // (concrete function must throw std::out_of_range when not existent)
    // type RightChild() specifiers; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */

  // Destructor
  // ~MutableBinaryTree() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Root() specifiers; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // type Map(arguments) specifiers; // Override MutableMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePreOrderMappableContainer)

  // type PreOrderMap(arguments) specifiers; // Override MutablePreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePostOrderMappableContainer)

  // type PostOrderMap(arguments) specifiers; // Override MutablePostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutableInOrderMappableContainer)

  // type InOrderMap(arguments) specifiers; // Override MutableInOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Override MutableBreadthMappableContainer member

protected:

  // Auxiliary member function (for MutablePreOrderMappableContainer)

  // type PreOrderMap(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for MutablePostOrderMappableContainer)

  // type PostOrderMap(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for MutableInOrderMappableContainer)

  // type InOrderMap(arguments) specifiers; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member function (for MutableBreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Accessory function executing from one node of the tree

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator {
                           // Must extend ForwardIterator<Data>,
                           //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTPreOrderIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderIterator(argument) specifiers;

  // Move constructor
  // BTPreOrderIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderIterator() specifiers;

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

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator {
                                  // Must extend MutableIterator<Data>,
                                  //             BTPreOrderIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTPreOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTPreOrderMutableIterator(argument) specifiers;

  // Move constructor
  // BTPreOrderMutableIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTPreOrderMutableIterator() specifiers;

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

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator {
                            // Must extend ForwardIterator<Data>,
                            //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTPostOrderIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderIterator(argument) specifiers;

  // Move constructor
  // BTPostOrderIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderIterator() specifiers;

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

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderMutableIterator {
                                  // Must extend MutableIterator<Data>,
                                  //             BTPostOrderIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTPostOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderMutableIterator(argument) specifiers;

  // Move constructor
  // BTPostOrderMutableIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderMutableIterator() specifiers;

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

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator {
                          // Must extend ForwardIterator<Data>,
                          //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTInOrderIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderIterator(argument) specifiers;

  // Move constructor
  // BTInOrderIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderIterator() specifiers;

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

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderMutableIterator {
                                  // Must extend MutableIterator<Data>,
                                  //             BTInOrderIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTInOrderMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderMutableIterator(argument) specifiers;

  // Move constructor
  // BTInOrderMutableIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderMutableIterator() specifiers;

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

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator {
                          // Must extend ForwardIterator<Data>,
                          //             ResettableIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTBreadthIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthIterator(argument) specifiers;

  // Move constructor
  // BTBreadthIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthIterator() specifiers;

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

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  // type Reset() specifiers; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthMutableIterator {
                                  // Must extend MutableIterator<Data>,
                                  //             BTBreadthIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTBreadthMutableIterator(argument) specifiers; // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthMutableIterator(argument) specifiers;

  // Move constructor
  // BTBreadthMutableIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthMutableIterator() specifiers;

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

  // Specific member functions (inherited from MutableIterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
