
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

  struct NodeLnk : virtual public MutableBinaryTree<Data>::MutableNode {  // Must extend MutableNode

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
      if(LChild!=nullptr) { 
        delete LChild; 
        LChild=nullptr; 
      } 
      if(RChild!=nullptr) { 
        delete RChild; 
        RChild=nullptr; 
      } 
    }

    /* ********************************************************************** */

    // Specific member functions

    NodeLnk(const Data& newElem) : element(newElem) {;}
    NodeLnk(Data&& newElem) noexcept : element(std::move(newElem)) {;}

    virtual bool inline IsLeaf() const noexcept override { return (!(HasLeftChild() || HasRightChild())); };

    virtual inline Data& Element() noexcept override {
      return element;
    };

    virtual const inline Data& Element() const noexcept override {
      return element;
    };

    virtual bool inline HasLeftChild() const noexcept override{
      return (LChild == nullptr ? false : true);
    };

    virtual bool inline HasRightChild() const noexcept override{
      return (RChild == nullptr ? false : true);
    };

    virtual inline NodeLnk& LeftChild() override {
      if(IsLeaf()) {
        throw std::out_of_range("This NodeLnk is a Leaf!(No LeftChild)");
      }
      return *LChild;
    }; 

    virtual const inline NodeLnk& LeftChild() const override {
      if(IsLeaf()) {
        throw std::out_of_range("This NodeLnk is a Leaf!(No LeftChild)");
      }
      return *LChild;
    }; 

    virtual inline NodeLnk& RightChild() override {
      if(IsLeaf()) {
        throw std::out_of_range("This NodeLnk is a Leaf!(No RightChild)");
      }
      return *RChild;
    };

    virtual const inline NodeLnk& RightChild() const override {
      if(IsLeaf()) {
        throw std::out_of_range("This NodeLnk is a Leaf!(No RightChild)");
      }
      return *RChild;
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
  virtual ~BinaryTreeLnk() {
    delete root;
  }

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk<Data>& operator=(const BinaryTreeLnk& right);

  // Move assignment
  BinaryTreeLnk<Data>& operator=(BinaryTreeLnk&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  virtual inline bool operator==(const BinaryTreeLnk& right) const noexcept { 
    return BinaryTree<Data>::operator==(right); 
  };
  virtual inline bool operator!=(const BinaryTreeLnk& right) const noexcept { 
    return BinaryTree<Data>::operator!=(right); 
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)
  virtual inline const NodeLnk& Root() const override {
    if(this->Empty()) {
      throw std::length_error("Error: BinaryLnkTree->isEmpty");
    }
    return *root;
  }; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)
  virtual inline NodeLnk& Root() override {
    if(this->Empty()) {
      throw std::length_error("Error: BinaryLnkTree->isEmpty");
    }
    return *root;
  }; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual inline void Clear() override { 
    if (root != nullptr) { 
      delete root; 
      root=nullptr; 
    } 
    size = 0; 
  }; // Override ClearableContainer member

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
