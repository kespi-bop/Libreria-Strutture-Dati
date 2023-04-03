
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
  virtual FoldableContainer& operator=(const FoldableContainer& other) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual FoldableContainer& operator=(const FoldableContainer&& other) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const FoldableContainer& other) const noexcept = delete;
  bool operator!=(const FoldableContainer& other) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  
  using FoldFunctor = std::function<void(const Data&, void* acc)>;

  virtual void Fold(const FoldFunctor func, void* acc) const = 0;

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
  PreOrderFoldableContainer& operator=(const PreOrderFoldableContainer& other) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  PreOrderFoldableContainer& operator=(PreOrderFoldableContainer&& other) noexcept = delete; // Move assignment of abstract types should not be possible.


  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderFoldableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const PreOrderFoldableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void PreOrderFold(const FoldFunctor func, void* acc) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  virtual void Fold(const FoldFunctor func, void* acc) const override { // Override FoldableContainer member
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
  PostOrderFoldableContainer& operator=(const PostOrderFoldableContainer& other) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  PostOrderFoldableContainer& operator=(PostOrderFoldableContainer&& other) noexcept = delete; // Move assignment of abstract types should not be possible.


  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PostOrderFoldableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const PostOrderFoldableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void PostOrderFold(const FoldFunctor func, void* acc) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  virtual void Fold(const FoldFunctor func, void* acc) const override { // Override FoldableContainer member
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
