
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

    BinaryTreeVec<Data>* bt = nullptr;
    int i;

  protected:

    const ulong Index() const { return i; };

  public:

    virtual ~NodeVec() {
      delete bt;
    };
    NodeVec(const Data &dat, int i, BinaryTreeVec<Data>* bt);
    NodeVec(Data&& dat, int i, BinaryTreeVec<Data>* bt);

    virtual bool HasLeftChild() const noexcept override;
    virtual bool HasRightChild() const noexcept override;

    virtual NodeVec& RightChild() override;
    virtual const NodeVec& RightChild() const override;

    virtual NodeVec& LeftChild() override;
    virtual const NodeVec& LeftChild() const override;


    virtual inline Data& Element() noexcept override { return bt->Elements[Index()]; }
    virtual inline const Data& Element() const noexcept override { return bt->Elements[Index()]; }

  };

  using Container::size;
  using Vector<Data>::Elements;
  Vector<NodeVec*> Nodes = Vector<NodeVec*>(0);

public:

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
  virtual ~BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec& operator=(const BinaryTreeVec& right);

  // Move assignment
  BinaryTreeVec& operator=(BinaryTreeVec&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const BinaryTreeVec& right) const noexcept { 
    return Vector<Data>::operator==(right.Elements); 
  };
  inline bool operator!=(const BinaryTreeVec& right) const noexcept { 
    return Vector<Data>::operator!=(right.Elements); 
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
    Nodes.Clear();
  }; // Override ClearableContainer member (throw std::length_error when empty)

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




  //Gestione del Diamond Problem
  void Fold(FoldFunctor func, void* acc) const override{
    BinaryTree<Data>::Fold(func, acc);
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
