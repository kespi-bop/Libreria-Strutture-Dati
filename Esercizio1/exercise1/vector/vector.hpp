
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : virtual public ResizableContainer,
               virtual public SortableLinearContainer<Data> {

private:

  Data* Elements;

protected:

  using Container::size;
  void Quicksort(uint p, uint r) noexcept;
  uint Partition(uint p, uint r) noexcept;

public:

  // Default constructor
  Vector() = default;
  /* ************************************************************************ */

  // Specific constructors
  Vector(const ulong new_size); // A vector with a given initial dimension
  Vector(const MappableContainer<Data>& map); // A vector obtained from a MappableContainer
  Vector(MutableMappableContainer<Data>&& Mmap); // A vector obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  Vector(const Vector& other);

  // Move constructor
  Vector(Vector&& other) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~Vector() = default; //OVVIAMENTE VA CAMBIATO

  /* ************************************************************************ */

  // Copy assignment
  Vector<Data>& operator=(const Vector& other);

  // Move assignment
  Vector<Data>& operator=(Vector&& other) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Vector& other) const noexcept;
  bool operator!=(const Vector& other) const noexcept;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override { Resize(0); }; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  void Resize(const ulong new_size) override; // Override ResizableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data & operator[](const ulong index) const override; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  Data& operator[](const ulong index) override; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  const Data& Front() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  Data& Front() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  const Data& Back() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  Data& Back() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from SortableLinearContainer)

  void Sort() noexcept override; // Override SortableLinearContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
