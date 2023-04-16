#ifndef CONTAINER_HPP
#define CONTAINER_HPP

typedef unsigned long int ulong;

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

protected:

  ulong size = 0;

public:

  // Destructor
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignmen
  Container& operator=(const Container& right) = delete;

  // Move assignment
  Container& operator=(Container&& right) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Container& right) const noexcept = delete; 
  bool operator!=(const Container& right) const noexcept = delete; 

  /* ************************************************************************ */

  // Specific member functions
  virtual inline bool Empty() const noexcept {
    return (size == 0); 
  };

  virtual inline ulong Size() const noexcept { 
    return size; 
  };

};

/* ************************************************************************** */

class ClearableContainer : public virtual Container {

private:

protected:

public:

  // Destructor
  virtual ~ClearableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ClearableContainer& operator=(const ClearableContainer& right) = delete;

  // Move assignment
  ClearableContainer& operator=(ClearableContainer&& right) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ClearableContainer& right) const noexcept = delete; 
  bool operator!=(const ClearableContainer& right) const noexcept = delete; 

  /* ************************************************************************ */

  // Specific member function

  virtual void Clear() = 0;

};

/* ************************************************************************** */

class ResizableContainer : public virtual ClearableContainer {

private:

protected:

public:

  // Destructor
  virtual ~ResizableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ResizableContainer& operator=(const ResizableContainer& right) = delete;

  // Move assignment
  ResizableContainer& operator=(ResizableContainer&& right) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ResizableContainer& right) const noexcept = delete; 
  bool operator!=(const ResizableContainer& right) const noexcept = delete; 

  /* ************************************************************************ */

  // Specific member function

  virtual void Resize(const ulong new_dimension) = 0;
 
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)
  virtual inline void Clear() override { 
    Resize(0); 
  }

};

/* ************************************************************************** */

}

#endif
