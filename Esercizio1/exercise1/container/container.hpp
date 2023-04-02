
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  // ...
  ulong size = 0;

public:

  // Destructor
  // ~Container() specifiers
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  Container& operator=(const Container& right) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  Container& operator=(Container&& right) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator==(const Container& right) const noexcept = delete;
  
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator!=(const Container& right) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // type Empty() specifiers; // (concrete function should not throw exceptions)
  virtual inline bool Empty() const noexcept { return (size == 0); };

  // type Size() specifiers; // (concrete function should not throw exceptions)
  virtual inline ulong Size() const noexcept { return size; };

};

/* ************************************************************************** */

class ClearableContainer : virtual public Container{
                            // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~ClearableContainer() specifiers
  virtual ~ClearableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  ClearableContainer& operator=(const ClearableContainer& right) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  ClearableContainer& operator=(ClearableContainer&& right) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator==(const ClearableContainer& right) const noexcept = delete;

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator!=(const ClearableContainer& right) const noexcept = delete; 

  /* ************************************************************************ */

  // Specific member function

  // type Clear() specifiers;
  virtual void Clear() = 0;

};

/* ************************************************************************** */

class ResizableContainer : public ClearableContainer{
                            // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~ResizableContainer() specifiers
  virtual ~ResizableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  ResizableContainer& operator=(const ResizableContainer& right) = delete;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  ResizableContainer& operator=(ResizableContainer&& right) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator==(const ResizableContainer& right) const noexcept = delete; 

  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  bool operator!=(const ResizableContainer& right) const noexcept = delete; 

  /* ************************************************************************ */

  // Specific member function

  // type Resize(argument) specifiers;
  virtual void Resize(const ulong n) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  virtual inline void Clear() override { Resize(0); }

};

/* ************************************************************************** */

}

#endif
