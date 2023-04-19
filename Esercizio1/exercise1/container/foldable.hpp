
#ifndef FOLDABLE_HPP
#define FOLDABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class FoldableContainer : virtual public TestableContainer<Data>{

private:

protected:

public:

  //Destructor
  virtual ~FoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  FoldableContainer& operator=(const FoldableContainer& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  FoldableContainer& operator=(const FoldableContainer&& right) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const FoldableContainer& right) const noexcept = delete;
  bool operator!=(const FoldableContainer& right) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using FoldFunctor = std::function<void(const Data&, void* acc)>;

  virtual void Fold(FoldFunctor func, void* acc) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  bool Exists(const Data&) const noexcept override; // Override TestableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PreOrderFoldableContainer : virtual public FoldableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~PreOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderFoldableContainer& operator=(const PreOrderFoldableContainer& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  PreOrderFoldableContainer& operator=(PreOrderFoldableContainer&& right) noexcept = delete; // Move assignment of abstract types should not be possible.


  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderFoldableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const PreOrderFoldableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void PreOrderFold(FoldFunctor func, void* acc) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  virtual void inline Fold(FoldFunctor func, void* acc) const override { // Override FoldableContainer member
    PreOrderFold(func, acc);
  }

};

/* ************************************************************************** */

template <typename Data>
class PostOrderFoldableContainer : virtual public FoldableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~PostOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderFoldableContainer& operator=(const PostOrderFoldableContainer& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  PostOrderFoldableContainer& operator=(PostOrderFoldableContainer&& right) noexcept = delete; // Move assignment of abstract types should not be possible.


  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PostOrderFoldableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const PostOrderFoldableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void PostOrderFold(FoldFunctor func, void* acc) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  virtual void inline Fold(FoldFunctor func, void* acc) const override { // Override FoldableContainer member
    PostOrderFold(func, acc);
  }  

};

/* ************************************************************************** */

template <typename Data>
class InOrderFoldableContainer : virtual public FoldableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~InOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  InOrderFoldableContainer& operator=(const InOrderFoldableContainer& other) = delete;

  // Move assignment
  InOrderFoldableContainer& operator=(InOrderFoldableContainer&& other) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const InOrderFoldableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const InOrderFoldableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.


  /* ************************************************************************ */

  // Specific member function
  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void InOrderOrderFold(FoldFunctor func, void* acc) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)
  inline virtual void Fold(FoldFunctor func, void* acc) const override { InOrderOrderFold(func, acc); }  

};

/* ************************************************************************** */

template <typename Data>
class BreadthFoldableContainer : virtual public FoldableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~BreadthFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  BreadthFoldableContainer& operator=(const BreadthFoldableContainer& other) = delete;

  // Move assignment
  BreadthFoldableContainer& operator=(BreadthFoldableContainer&& other) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BreadthFoldableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const BreadthFoldableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function
  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void BreadthFold(FoldFunctor func, void* acc) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)
  inline virtual void Fold(FoldFunctor func, void* acc) const override { BreadthFold(func, acc); }  

};

/* ************************************************************************** */

}

#include "foldable.cpp"

#endif
