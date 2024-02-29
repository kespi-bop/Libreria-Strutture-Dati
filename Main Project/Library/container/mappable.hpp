
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
  MappableContainer& operator=(const MappableContainer& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MappableContainer& operator=(MappableContainer&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using MapFunctor = std::function<void(const Data &)>;

  virtual void Map(MapFunctor func) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void Fold(FoldFunctor func, void* acc) const override; // Override FoldableContainer member

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
  PreOrderMappableContainer& operator=(const PreOrderMappableContainer& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  PreOrderMappableContainer& operator=(PreOrderMappableContainer&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const PreOrderMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFunctor;

  virtual void PreOrderMap(MapFunctor func) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  virtual void inline Map(MapFunctor func) const { // Override MappableContainer member
    PreOrderMap(func);
  }
  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  //using typename FoldableContainer<Data>::Fold;

  virtual inline void Fold(FoldFunctor func, void* acc) const override {   // Override FoldableContainer member
      MappableContainer<Data>::Fold(func, acc);
  }; 

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderFoldableContainer)

  virtual void PreOrderFold(FoldFunctor func, void* acc) const override; // Override PreOrderFoldableContainer member

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
  virtual PostOrderMappableContainer& operator=(const PostOrderMappableContainer& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual PostOrderMappableContainer& operator=(PostOrderMappableContainer&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const PostOrderMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.
  virtual bool operator!=(const PostOrderMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFunctor;

  virtual void PostOrderMap(MapFunctor func) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  virtual void Map(MapFunctor func) const { // Override MappableContainer member
    PostOrderMap(func);
  }

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  //using typename FoldableContainer<Data>::Fold;

  virtual inline void Fold(FoldFunctor func, void* acc) const override {   // Override FoldableContainer member
      MappableContainer<Data>::Fold(func, acc);
  }; 

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderFold)

  virtual void PostOrderFold(FoldFunctor func, void* acc) const override; // Override PostOrderFold member

};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer : virtual public MappableContainer<Data>, 
                                 virtual public InOrderFoldableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~InOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  virtual InOrderMappableContainer& operator=(const InOrderMappableContainer& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual InOrderMappableContainer& operator=(InOrderMappableContainer&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const InOrderMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const InOrderMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function
  using typename MappableContainer<Data>::MapFunctor;

  virtual void InOrderMap(MapFunctor func) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)
  inline virtual void Map(MapFunctor func) const override { InOrderMap(func); } // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)
  using typename FoldableContainer<Data>::FoldFunctor;

  inline void Fold(FoldFunctor func, void* acc) const override { MappableContainer<Data>::Fold(func, acc); }; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderFoldableContainer)
  void InOrderFold(FoldFunctor func, void* acc) const override; // Override InOrderFold member

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer : virtual public MappableContainer<Data>,
                                 virtual public BreadthFoldableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~BreadthMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  virtual BreadthMappableContainer& operator=(const BreadthMappableContainer& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual BreadthMappableContainer& operator=(BreadthMappableContainer&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BreadthMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const BreadthMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function
  using typename MappableContainer<Data>::MapFunctor;

  virtual void BreadthMap(MapFunctor func) const = 0;

  /* ************************************************************************ */


  // Specific member function (inherited from MappableContainer)

  inline virtual void Map(MapFunctor func) const override { BreadthMap(func); } // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  inline void Fold(FoldFunctor func, void* acc) const override { MappableContainer<Data>::Fold(func, acc); }; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthFoldableContainer)

  void BreadthFold(FoldFunctor func, void* acc) const override; // Override BreadthFold member

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
  MutableMappableContainer& operator=(const MutableMappableContainer& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutableMappableContainer& operator=(MutableMappableContainer&& right) noexcept = delete; // Move assignment of abstract types should not be possible.


  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutableMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutableMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.

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
  MutablePreOrderMappableContainer& operator=(const MutablePreOrderMappableContainer& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutablePreOrderMappableContainer& operator=(MutablePreOrderMappableContainer&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutablePreOrderMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutablePreOrderMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  //type PreOrderMap(argument) specifiers;
  virtual void PreOrderMap(MutableMapFunctor func) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)
  
  virtual void inline Map(MutableMapFunctor func) override { PreOrderMap(func); }; // Override MutableMappableContainer member

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
  MutablePostOrderMappableContainer& operator=(const MutablePostOrderMappableContainer& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutablePostOrderMappableContainer& operator=(MutablePostOrderMappableContainer&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutablePostOrderMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutablePostOrderMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.


  /* ************************************************************************ */

  // Specific member function

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  virtual void PostOrderMap(MutableMapFunctor func) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  virtual void inline Map(MutableMapFunctor func) override { PostOrderMap(func); }; // Override MutableMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableInOrderMappableContainer : virtual public MutableMappableContainer<Data>,
                                        virtual public InOrderMappableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~MutableInOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableInOrderMappableContainer& operator=(const MutableInOrderMappableContainer& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutableInOrderMappableContainer& operator=(MutableInOrderMappableContainer&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutableInOrderMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutableInOrderMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function
  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  virtual void InOrderMap(MutableMapFunctor func) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)
  inline virtual void Map(MutableMapFunctor func) override { InOrderMap(func); }; // Override MutableMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableBreadthMappableContainer : public virtual MutableMappableContainer<Data>,
                                        public virtual BreadthMappableContainer<Data> {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~MutableBreadthMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableBreadthMappableContainer& operator=(const MutableBreadthMappableContainer& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MutableBreadthMappableContainer& operator=(MutableBreadthMappableContainer&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MutableBreadthMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MutableBreadthMappableContainer& right) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function
  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  virtual void BreadthMap(MutableMapFunctor func) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)
  inline virtual void Map(MutableMapFunctor func) override { BreadthMap(func); }; // Override MutableMappableContainer member

};

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif
