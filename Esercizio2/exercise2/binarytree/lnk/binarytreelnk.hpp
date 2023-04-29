
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : public virtual MutableBinaryTree<Data>{

private:

  // ...

protected:

  using Container::size;

  struct NodeLnk : public virtual BinaryTree<Data>::MutableNode { // Must extend MutableNode

  private:

    Data element;
    NodeLnk* LChild = nullptr;
    NodeLnk* RChild = nullptr;

  protected:

    // ...

  public:

    friend class BinaryTreeLnk<Data>;

    /* ********************************************************************** */

    // Destructor
    virtual ~NodeLnk() {
      delete LChild;
      delete RChild;
    };

    /* ********************************************************************** */

    // Specific member functions

    virtual inline Data& Element() noexcept {
      return element;
    };

    virtual inline bool HasLeftChild() const noexcept override{
      return (LChild == nullptr ? false : true);
    };

    virtual inline bool HasRightChild() const noexcept override{
      return (RChild == nullptr ? false : true);
    };

    virtual inline NodeLnk& LeftChild() {
      if(this.isLeaf()) {
        throw std::out_of_range("This NodeLnk is a Leaf!(No LeftChild)");
      }
      return LChild;
    }; 

    virtual inline NodeLnk& RightChild() {
      if(this.isLeaf()) {
        throw std::out_of_range("This NodeLnk is a Leaf!(No RightChild)");
      }
      return RChild;
    };

  };

  NodeLnk* root = nullptr;

public:

  // Default constructor
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeLnk(const MappableContainer<Data>& right); // A binary tree obtained from a MappableContainer
  BinaryTreeLnk(MutableMappableContainer<Data>&& right); // A binary tree obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk& right);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk&& right) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk operator=(const BinaryTreeLnk& right);

  // Move assignment
  BinaryTreeLnk operator=(BinaryTreeLnk&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeLnk& right) noexcept override;
  bool operator!=(const BinaryTreeLnk& right) noexcept override {
    return !(operator==(right));
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)
  virtual inline const NodeLnk& Root() const override {
    if(this.Empty()) {
      throw std::length_error("Error: BinaryLnkTree->isEmpty");
    }
    return *root;
  }; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)
  virtual inline NodeLnk& Root() override {
    if(this.Empty()) {
      throw std::length_error("Error: BinaryLnkTree->isEmpty");
    }
    return *root;
  }; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() noexcept override; // Override ClearableContainer member

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
