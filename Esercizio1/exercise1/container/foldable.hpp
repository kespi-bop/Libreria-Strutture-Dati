
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
  FoldableContainer& operator=(const FoldableContainer& right) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  FoldableContainer& operator=(FoldableContainer&& right) = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator==(const FoldableContainer& right)const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator!=(const FoldableContainer& right)const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  // using FoldFunctor = std::function<void(const Data &, void *)>;
  using FoldFunctor = std::function<void(const Data&, void *)>;

  // type Fold(arguments) specifiers;
  virtual void Fold(FoldFunctor, void *accumulator) noexcept = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  // type Exists(argument) specifiers; // Override TestableContainer member
  bool Exists(const Data& item) const noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderFoldableContainer : virtual public FoldableContainer<Data> {
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PreOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  PreOrderFoldableContainer& operator=(const PreOrderFoldableContainer& right) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  PreOrderFoldableContainer& operator=(PreOrderFoldableContainer&& right) = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator==(const PreOrderFoldableContainer& right)const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator!=(const PreOrderFoldableContainer& right)const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void PreOrderFold(FoldFun, void * accumulator) const noexcept = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // type Fold(arguments) specifiers; // Override FoldableContainer member
  virtual void Fold(const FoldFunctor, void * accumulator) const override {
    PreOrderFold(funct, accumulator);
  }

};

/* ************************************************************************** */

template <typename Data>
class PostOrderFoldableContainer : virtual public FoldableContainer<Data>{
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~PostOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  PostOrderFoldableContainer& operator=(const PostOrderFoldableContainer& right) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  PostOrderFoldableContainer& operator=(PostOrderFoldableContainer&& right) = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator==(const PostOrderFoldableContainer& right)const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator!=(const PostOrderFoldableContainer& right)const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void PostOrderFold(const FoldFunctor funct,void* accumulator) const noexcept = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // type Fold(arguments) specifiers; // Override FoldableContainer member
virtual void Fold(const FoldFunctor funct, void* accumultaor) const override {
  PostOrderFold(funct,accumultaor);
}

};

/* ************************************************************************** */

template <typename Data>
class InOrderFoldableContainer : virtual public FoldableContainer<Data>{
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~InOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  virtual InOrderFoldableContainer& operator=(const InOrderFoldableContainer& right) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  virtual InOrderFoldableContainer& operator=(InOrderFoldableContainer&& right) = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  virtual bool operator==(const InOrderFoldableContainer& right)const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  virtual bool operator!=(const InOrderFoldableContainer& right)const noexcept = delete;

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
class BreadthFoldableContainer : virtual public FoldableContainer<Data>{
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~BreadthFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  virtual BreadthFoldableContainer& operator=(const BreadthFoldableContainer& right) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  virtual BreadthFoldableContainer& operator=(BreadthFoldableContainer&& right) = delete; 

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  virtual bool operator==(const BreadthFoldableContainer& right)const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  virtual bool operator!=(const BreadthFoldableContainer& right)const noexcept = delete;

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
