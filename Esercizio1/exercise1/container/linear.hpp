
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual public MutablePreOrderMappableContainer<Data>,
                        virtual public MutablePostOrderMappableContainer<Data>{
                        // Must extend MutablePreOrderMappableContainer<Data>,
                        //             MutablePostOrderMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  LinearContainer& operator=(const LinearContainer& right) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  LinearContainer& operator=(LinearContainer&& right) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is possible
  bool operator==(LinearContainer& right) const;
  // type operator!=(argument) specifiers; // Comparison of abstract types is possible.
  bool operator!=(LinearContainer& right) const;

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data& operator[](ulong index) const = 0; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
  virtual Data& operator[](ulong index) = 0; // (mutable version; concrete function must throw std::out_of_range when out of range)

  virtual const Data& Front() const; // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual Data& Front(); // (mutable version; concrete function must throw std::length_error when empty)

  virtual const Data& Back() const; // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual Data& Back(); // (mutable version; concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderFoldableContainer)

  // type PreOrderFold(arguments) specifiers; // Override PreOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderFoldableContainer)

  // type PostOrderFold(arguments) specifiers; // Override PostOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  virtual const void Map(const MapFunctor funct) const override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  virtual const void PreOrderMap(const MapFunctor funct) override { Map(funct); }; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  virtual const void PostOrderMap(const MapFunctor funct) const override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  virtual void Map(MutableMapFunctor funct) override; // Override MutableMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePreOrderMappableContainer)

  virtual void PreOrderMap(MutableMapFunctor funct) override { return Map(funct); }; // Override MutablePreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePostOrderMappableContainer)

  virtual void PostOrderMap(MutableMapFunctor funct) override; // Override MutablePostOrderMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer : public LinearContainer<Data>{
                                // Must extend LinearContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~SortableLinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  SortableLinearContainer& operator=(const SortableLinearContainer& right) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  SortableLinearContainer& operator=(SortableLinearContainer&& right) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types is possible.
  bool operator==(SortableLinearContainer& right) const;
  // type operator!=(argument) specifiers; // Comparison of abstract types is possible.
  bool operator!=(SortableLinearContainer& right) const;

  /* ************************************************************************ */

  // Specific member function

  // type Sort() specifiers;
  virtual void Sort() noexcept = 0;

};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
