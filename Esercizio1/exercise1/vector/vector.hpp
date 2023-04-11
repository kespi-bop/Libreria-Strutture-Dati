
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

protected:

  using Container::size;
  Data* Elements = nullptr;

public:

  // Default constructor
  Vector() = default;

  /* ************************************************************************ */

  // Specific constructors
  Vector(const ulong new_size); // A vector with a given initial dimension
  Vector(const MappableContainer<Data>& MCont); // A vector obtained from a MappableContainer
  Vector(MutableMappableContainer<Data>&& MuMaCont) noexcept; // A vector obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  Vector(const Vector& right);

  // Move constructor
  Vector(Vector&& right) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~Vector();

  /* ************************************************************************ */

  // Copy assignment
  Vector& operator=(const Vector& right);

  // Move assignment
  Vector& operator=(Vector&& right) noexcept;

    /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const Vector& right) const noexcept;
  virtual bool operator!=(const Vector& right) const noexcept;

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  void Resize(const ulong new_size) override; // Override ResizableContainer member

  void Clear() override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data & operator[](const ulong index) const override; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  Data& operator[](const ulong index) override; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  const Data& Front() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  Data& Front() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  const Data& Back() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  Data& Back() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  void Sort() noexcept override; // Override SortableLinearContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
