
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../container/container.hpp"
#include "../../container/foldable.hpp"
#include "../../container/mappable.hpp"
#include "../../container/linear.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data>,
                      virtual protected Vector<Data> {

private:

  // ...

protected:

  // ...
  struct NodeVec : virtual MutableBinaryTree<Data>::MutableNode{ // Must extend MutableNode

  friend class BinaryTreeVec<Data>;

  private:

  protected:

  public:

    BinaryTreeVec<Data>* bt = nullptr;
    int index;

    // Specific constructor
    NodeVec() {
      bt = nullptr;
      index = 0;
    };
    NodeVec(const Data &dat, int i, BinaryTreeVec<Data>* bt);
    NodeVec(Data&& dat, int i, BinaryTreeVec<Data>* bt);

    // Destructor
    inline virtual ~NodeVec() = default;

    // Copy assignment
    inline NodeVec& operator=(const NodeVec& right) { 
      bt = right.bt;
      index = right.index;
      return *this;
    };

    // Move assignment
    inline NodeVec& operator=(NodeVec&& right) noexcept { 
      std::swap(bt, right.bt);
      std::swap(index = right.index); 
      return *this;
    };

    // Specific member functions
    inline virtual Data& Element() noexcept override { 
      return bt->Elements[index]; 
    }
    inline virtual const Data& Element() const noexcept override { 
      return bt->Elements[index]; 
    }

    virtual bool HasLeftChild() const noexcept override;
    virtual bool HasRightChild() const noexcept override;

    virtual NodeVec& LeftChild() override;
    virtual const NodeVec& LeftChild() const override;

    virtual NodeVec& RightChild() override;
    virtual const NodeVec& RightChild() const override;
  };

  using Container::size;
  using Vector<Data>::Elements;
  NodeVec* Nodes = nullptr;

public:

  using BinaryTree<Data>::Map;
using BinaryTree<Data>::PreOrderMap;
using BinaryTree<Data>::PostOrderMap;
  // Default constructor
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const MappableContainer<Data>& right);   // A binary tree obtained from a MappableContainer
  BinaryTreeVec(MutableMappableContainer<Data>&& right) noexcept;   // A binary tree obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec<Data>& right);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec<Data>&& right) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeVec(){
    delete[] Nodes;
    Nodes = nullptr;
  }

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec& operator=(const BinaryTreeVec& right);

  // Move assignment
  BinaryTreeVec& operator=(BinaryTreeVec&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BinaryTreeVec& right) const noexcept { 
    return Vector<Data>::operator==(right); 
  };
  inline bool operator!=(const BinaryTreeVec& right) const noexcept { 
    return Vector<Data>::operator!=(right); 
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  virtual const NodeVec& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  virtual NodeVec& Root() override; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual inline void Clear() override {
    Vector<Data>::Clear();
    delete[] Nodes;
    Nodes = nullptr;
  }; // Override ClearableContainer member

  /* ************************************************************************ */

  using typename MappableContainer<Data>::MapFunctor;
  using typename MutableMappableContainer<Data>::MutableMapFunctor;
  using typename FoldableContainer<Data>::FoldFunctor;

  // Specific member functions (inherited from BreadthFoldableContainer)

  void BreadthFold(FoldFunctor func, void* acc) const override{
    Vector<Data>::PreOrderFold(func, acc);
  }; // Override BreadthFoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)

  void BreadthMap(MapFunctor func) const override{
    Vector<Data>::PreOrderMap(func);
  }; // Override BreadthMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableBreadthMappableContainer)

  void BreadthMap(MutableMapFunctor func) override {
    Vector<Data>::PreOrderMap(func);
  }; // Override MutableBreadthMappableContainer member


  //Gestione del Diamond Problem ereditando da vector
  void Fold(FoldFunctor func, void* acc) const override{
    BinaryTree<Data>::Fold(func, acc);
  }

  void PreOrderFold(FoldFunctor func, void* acc) const override{
    BinaryTree<Data>::PreOrderFold(func, acc);
  }

  void PostOrderFold(FoldFunctor func, void* acc) const override{
    BinaryTree<Data>::PostOrderFold(func, acc);
  }

  void PreOrderMap(MapFunctor func) const override{
    BinaryTree<Data>::PreOrderMap(func);
  }

  void PreOrderMap(MutableMapFunctor func) override{
    MutableBinaryTree<Data>::PreOrderMap(func);
  }  

  void PostOrderMap(MapFunctor func) const override{
    BinaryTree<Data>::PostOrderMap(func);
  }

  void PostOrderMap(MutableMapFunctor func) override{
    MutableBinaryTree<Data>::PostOrderMap(func);
  }

  void Map(MapFunctor func) const override{
    BinaryTree<Data>::Map(func); 
  }

  void Map(MutableMapFunctor func) override{
    MutableBinaryTree<Data>::Map(func); 
  }

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
