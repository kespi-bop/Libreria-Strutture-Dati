#ifndef CONTAINER_HPP
#define CONTAINER_HPP

typedef unsigned long int ulong;

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

protected:

  ulong size = 0; //Dimensione della struttura

public:

  // Destructor
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignmen
  Container& operator=(const Container& other) = delete;

  // Move assignment
  Container& operator=(Container&& other) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const Container& other) const noexcept = delete; 
  virtual bool operator!=(const Container& other) const noexcept = delete; 

  /* ************************************************************************ */

  // Specific member functions
  virtual inline bool Empty() const noexcept { return size==0; };

  virtual inline ulong Size() const noexcept { return size; };

};

/* ************************************************************************** */

class ClearableContainer : public virtual Container {

private:

protected:

public:

  // Destructor
  virtual ~ClearableContainer() = default; //Forse mancano gli specifiers

  /* ************************************************************************ */

  // Copy assignment
  ClearableContainer& operator=(const ClearableContainer& other) = delete;

  // Move assignment
  ClearableContainer& operator=(ClearableContainer&& other) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ClearableContainer& other) const noexcept = delete; 
  bool operator!=(const ClearableContainer& other) const noexcept = delete; 

  /* ************************************************************************ */

  // Specific member function

  virtual inline void Clear() = 0;

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
  ResizableContainer& operator=(const ResizableContainer& other) = delete;

  // Move assignment
  ResizableContainer& operator=(ResizableContainer&& other) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ResizableContainer& other) const noexcept = delete; 
  bool operator!=(const ResizableContainer& other) const noexcept = delete; 

  /* ************************************************************************ */

  // Specific member function

  virtual void Resize(const ulong n) = 0;
 
  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)
  virtual inline void Clear() override { Resize(0); }

};

/* ************************************************************************** */

}

#endif
