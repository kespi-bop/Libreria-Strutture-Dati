
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
class InOrderFoldableContainer {
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~InOrderFoldableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type InOrderFold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // MODIFICATO PER ERRORE
  // virtual void Fold(const FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class BreadthFoldableContainer {
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthFoldableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type BreadthFold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // type Fold(arguments) specifiers; // Override FoldableContainer member

};

/* ************************************************************************** */

}

#include "foldable.cpp"

#endif
