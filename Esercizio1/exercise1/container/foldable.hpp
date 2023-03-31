
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
class FoldableContainer : public TestableContainer<Data>{
                          // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~FoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  virtual FoldableContainer& operator=(const FoldableContainer& right) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  virtual FoldableContainer& operator=(FoldableContainer&& right) = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  virtual bool operator==(const FoldableContainer& right) = 0;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  virtual bool operator!=(const FoldableContainer& right) = 0;

  /* ************************************************************************ */

  // Specific member function

  // using FoldFunctor = std::function<void(const Data &, void *)>;
  using FoldFunctor = std::function<void(const Data &, void *)>;

  // type Fold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PreOrderFoldableContainer : public FoldableContainer<Data> {
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~PreOrderFoldableContainer() specifiers

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

  // type PreOrderFold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // type Fold(arguments) specifiers; // Override FoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderFoldableContainer : public FoldableContainer<Data>{
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~PostOrderFoldableContainer() specifiers

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

  // type PostOrderFold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // type Fold(arguments) specifiers; // Override FoldableContainer member

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

  // type Fold(arguments) specifiers; // Override FoldableContainer member

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
