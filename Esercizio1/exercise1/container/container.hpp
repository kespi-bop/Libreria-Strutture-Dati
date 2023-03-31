
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
  virtual ~Container() = 0;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  virtual Container& operator=(const Container& right) = 0;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  virtual Container&& operator=(const Container&& right) const noexcept = 0;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  virtual bool operator== (const Container& right) const noexcept = 0;
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  vistual bool operator!=(const Container& other) const noexcept = 0;

  /* ************************************************************************ */

  // Specific member functions

  // type Empty() specifiers; // (concrete function should not throw exceptions)
  virtual inline bool Empty() const noexcept { return size == 0; };

  // type Size() specifiers; // (concrete function should not throw exceptions)
  virtual inline ulong Size() const noexcept { return size; };

};

/* ************************************************************************** */

class ClearableContainer : public virtual Container{
                            // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~ClearableContainer() specifiers
  virtual ~ClearableContainer() = 0;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  virtual ClearableContainer& operator=(const ClearableContainer& other) = 0;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  virtual ClearableContainer& operator=(const ClearableContainer&& other) const noexcept = 0;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  virtual bool operator==(const ClearableContainer& other) const noexcept = 0;
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  virtual bool operator!=(const ClearableContainer& other) const noexcept = 0; 

  /* ************************************************************************ */

  // Specific member function

  // type Clear() specifiers;
  virtual inline void Clear() noexcept { size = 0; };

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
  virtual ~ResizableContainer() = 0;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.
  virtual ResizableContainer& operator=(const ResizableContainer& other) = 0;

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.
  virtual ResizableContainer& operator=(const ResizableContainer&& other) const noexcept = 0;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  virtual bool operator==(const ResizableContainer& other) const noexcept = 0; 
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
  virtual bool operator!=(const ResizableContainer& other) const noexcept = 0; 

  /* ************************************************************************ */

  // Specific member function

  // type Resize(argument) specifiers;
  virtual inline void Resize(const int n) noexcept { size=n; }

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  virtual inline void Clear() noexcept override { Resize(0); }

};

/* ************************************************************************** */

}

#endif
