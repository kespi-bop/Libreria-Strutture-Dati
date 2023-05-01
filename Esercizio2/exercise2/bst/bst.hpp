
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : public virtual ClearableContainer,
            public virtual DictionaryContainer<Data>,
            public virtual BinaryTree<Data>,
            public virtual BinaryTreeLnk<Data>{

private:

  // ...

protected:

  // using BinaryTreeLnk<Data>::???;

  // ...

public:

  // Default constructor
  BST() = default;

  /* ************************************************************************ */

  // Specific constructors
  BST(const MutableContainer& right); // A bst obtained from a MutableContainer
  BST(MappableMutableContainer&& right) noexcept; // A bst obtained from a MappableMutableContainer

  /* ************************************************************************ */

  // Copy constructor
  BST(const BST& right);

  // Move constructor
  BST(BST&& right) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
  BST<Data>& operator=(const BST& right);

  // Move assignment
  BST<Data>& operator=(BST&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BST& right) noexcept override;
  bool inline operator!=(const BST& right) noexcept override {
    return !(operator==(right));
  }

  /* ************************************************************************ */

  // Specific member functions

  Data& Min() const; // (concrete function must throw std::length_error when empty)
  Data MinNRemove() const; // (concrete function must throw std::length_error when empty)
  void RemoveMin() const; // (concrete function must throw std::length_error when empty)

  Data& Max() const; // (concrete function must throw std::length_error when empty)
  Data MaxNRemove() const; // (concrete function must throw std::length_error when empty)
  void RemoveMax() const; // (concrete function must throw std::length_error when empty)

  Data& Predecessor(const Data& find) const; // (concrete function must throw std::length_error when not found)
  Data PredecessorNRemove(const Data& find) const; // (concrete function must throw std::length_error when not found)
  void RemovePredecessor(const Data& find) const; // (concrete function must throw std::length_error when not found)

  Data& Successor(const Data& find) const; // (concrete function must throw std::length_error when not found)
  Data SuccessorNRemove(const Data& find) const; // (concrete function must throw std::length_error when not found)
  void RemoveSuccessor(const Data& find) const; // (concrete function must throw std::length_error when not found)

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  virtual bool Insert(const Data& value) override; // Override DictionaryContainer member (Copy of the value)
  virtual bool Insert(Data&& value) override; // Override DictionaryContainer member (Move of the value)
  virtual bool Remove(const Data& value) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  virtual bool Exists(const Data& valore) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary member functions

  // type DataNDelete(argument) specifiers;

  // type Detach(argument) specifiers;

  // type DetachMin(argument) specifiers;
  // type DetachMax(argument) specifiers;

  // type Skip2Left(argument) specifiers;
  // type Skip2Right(argument) specifiers;

  // type FindPointerToMin(argument) specifiers; // Both mutable & unmutable versions
  // type FindPointerToMax(argument) specifiers; // Both mutable & unmutable versions

  // type FindPointerTo(argument) specifiers; // Both mutable & unmutable versions

  // type FindPointerToPredecessor(argument) specifiers; // Both mutable & unmutable versions
  // type FindPointerToSuccessor(argument) specifiers; // Both mutable & unmutable versions

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
