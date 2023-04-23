
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec {
                      // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  // ...

  struct NodeVec { // Must extend MutableNode

  private:

    // ...

  protected:

    // ...

  public:

    // ...

  };

public:

  // Default constructor
  // BinaryTreeVec() specifiers;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a MappableContainer
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  // BinaryTreeVec(argument) specifiers;

  // Move constructor
  // BinaryTreeVec(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BinaryTreeVec() specifiers;

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

  // Specific member functions (inherited from BinaryTree)

  // type Root() specifiers; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  // type Root() specifiers; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthFoldableContainer)

  // type BreadthFold(arguments) specifiers; // Override BreadthFoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Override BreadthMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableBreadthMappableContainer)

  // type BreadthMap(arguments) specifiers; // Override MutableBreadthMappableContainer member

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
