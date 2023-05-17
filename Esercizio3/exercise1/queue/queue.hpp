
#ifndef QUEUE_HPP
#define QUEUE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Queue : virtual public ClearableContainer {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~Queue() = default;

  /* ************************************************************************ */

  // Copy assignment
  Queue<Data>& operator=(const Queue& right) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  Queue<Data>& operator=(Queue&& right) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const Queue& right) const noexcept = delete; // Comparison of abstract types might not be possible.
  virtual bool operator!=(const Queue& right) const noexcept = delete;  // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data& Head() const = 0; // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual Data& Head() = 0; // (mutable version; concrete function must throw std::length_error when empty)
  virtual void Dequeue() = 0; // (concrete function must throw std::length_error when empty)
  virtual Data HeadNDequeue() = 0; // (concrete function must throw std::length_error when empty)
  virtual void Enqueue(const Data& element) = 0; // Copy of the value
  virtual void Enqueue(Data&& element) = 0; // Move of the value

};

/* ************************************************************************** */

}

#endif
