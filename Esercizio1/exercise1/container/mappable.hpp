
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "foldable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MappableContainer : virtual public FoldableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~MappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MappableContainer& operator=(const MappableContainer& other) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MappableContainer& operator=(MappableContainer&& other) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MappableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MappableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using MapFunctor = std::function<void(const Data &)>;

  virtual const void Map(const MapFunctor func) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  //using typename FoldableContainer<Data>::Fold;

  virtual void Fold(const FoldFunctor func, void* acc) const = 0; // Override FoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer : virtual public PreOrderFoldableContainer<Data>,
                                  virtual public MappableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~PreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderMappableContainer& operator=(const PreOrderMappableContainer& other) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  PreOrderMappableContainer& operator=(PreOrderMappableContainer&& other) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderMappableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const PreOrderMappableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFunctor;

  virtual const void PreOrderMap(const MapFunctor func) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  virtual const void Map(const MapFunctor func) const { // Override MappableContainer member
    PreOrderMap(func);
  }
  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  //using typename FoldableContainer<Data>::Fold;

  virtual void Fold(const FoldFunctor func, void* acc) const = 0; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderFoldableContainer)

  //using typename PreOrderFoldableContainer<Data>::PreOrderFold;

  virtual void PreOrderFold(const FoldFunctor func, void* acc) const = 0; // Override PreOrderFoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer : virtual public PostOrderFoldableContainer<Data>,
                                  virtual public MappableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~PostOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  virtual PostOrderMappableContainer& operator=(const PostOrderMappableContainer& other) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual PostOrderMappableContainer& operator=(PostOrderMappableContainer&& other) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const PostOrderMappableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.
  virtual bool operator!=(const PostOrderMappableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFunctor;

  virtual const void PostOrderMap(const MapFunctor func) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  virtual const void Map(const MapFunctor func) const { // Override MappableContainer member
    PostOrderMap(func);
  }

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  //using typename FoldableContainer<Data>::Fold;

  virtual void Fold(const FoldFunctor func, void* acc) const = 0; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderFold)

  //using typename PostOrderFoldableContainer<Data>::PostOrderFold;

  virtual void PostOrderFold(const FoldFunctor func, void* acc) const = 0; // Override PostOrderFold member

};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer {
                                  // Must extend MappableContainer<Data>,
                                  //             InOrderFoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~InOrderMappableContainer() specifiers

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

  // using typename MappableContainer<Data>::MapFunctor;

  // type InOrderMap(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderFoldableContainer)

  // type InOrderFold(arguments) specifiers; // Override InOrderFoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer {
                                  // Must extend MappableContainer<Data>,
                                  //             BreadthFoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthMappableContainer() specifiers

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

  // using typename MappableContainer<Data>::MapFunctor;

  // type BreadthMap(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthFoldableContainer)

  // type BreadthFold(arguments) specifiers; // Override BreadthFoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableMappableContainer : virtual public MappableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~MutableMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableMappableContainer& operator=(const MutableMappableContainer& other) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutableMappableContainer& operator=(MutableMappableContainer&& other) noexcept = delete; // Move assignment of abstract types should not be possible.


  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutableMappableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutableMappableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using MutableMapFunctor = std::function<void(Data &)>;

  virtual void Map(MutableMapFunctor func) = 0;

};

/* ************************************************************************** */

template <typename Data>
class MutablePreOrderMappableContainer : virtual public MutableMappableContainer<Data>,
                                          virtual public PreOrderMappableContainer<Data> {

private:

protected:

public:

  // Destructor
  virtual ~MutablePreOrderMappableContainer() = default;

  /* ************************************************************************ */

  
  // Copy assignment
  MutablePreOrderMappableContainer& operator=(const MutablePreOrderMappableContainer& other) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutablePreOrderMappableContainer& operator=(MutablePreOrderMappableContainer&& other) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutablePreOrderMappableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutablePreOrderMappableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  //type PreOrderMap(argument) specifiers;
  virtual void PreOrderMap(MutableMapFunctor func) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // type Map(argument) specifiers; // Override MutableMappableContainer member
  virtual void Map(MutableMapFunctor func) = 0;

};

/* ************************************************************************** */

template <typename Data>
class MutablePostOrderMappableContainer : virtual public MutableMappableContainer<Data>,
                                          virtual public PostOrderMappableContainer<Data> {
private:

protected:

public:

  // Destructor
  virtual ~MutablePostOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutablePostOrderMappableContainer& operator=(const MutablePostOrderMappableContainer& other) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutablePostOrderMappableContainer& operator=(MutablePostOrderMappableContainer&& other) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutablePostOrderMappableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutablePostOrderMappableContainer& other) const noexcept = delete; // Comparison of abstract types might not be possible.


  /* ************************************************************************ */

  // Specific member function

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  virtual void PostOrderMap(MutableMapFunctor func) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  virtual void Map(MutableMapFunctor func) = 0; // Override MutableMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableInOrderMappableContainer {
                                        // Must extend MutableMappableContainer<Data>,
                                        //             InOrderMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~MutableInOrderMappableContainer() specifiers

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

  // using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // type InOrderMap(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // type Map(argument) specifiers; // Override MutableMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableBreadthMappableContainer {
                                        // Must extend MutableMappableContainer<Data>,
                                        //             BreadthMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~MutableBreadthMappableContainer() specifiers

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

  // using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // type BreadthMap(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // type Map(argument) specifiers; // Override MutableMappableContainer member

};

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif
