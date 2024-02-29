
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP
#define initial_size_queue 10

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

#include <cmath>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : virtual public Queue<Data>,
                 virtual protected Vector<Data> {

private:

protected:

  using Container::size;
  using Vector<Data>::Elements;
  ulong head = 0;
  ulong tail = 0;
  

  const double expand_check = 1;
  const double expand_set = 2;
  const double reduce_check = 0.5;
  const double reduce_set = 0.75;

public:

  // Default constructor
  QueueVec();

  /* ************************************************************************ */

  // Specific constructor
  QueueVec(const MappableContainer<Data>& cont); // A queue obtained from a MappableContainer
  QueueVec(MutableMappableContainer<Data>&& cont) noexcept; // A queue obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  QueueVec(const QueueVec& right);

  // Move constructor
  QueueVec(QueueVec&& right) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~QueueVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueVec<Data>& operator=(const QueueVec& right);

  // Move assignment
  QueueVec<Data>& operator=(QueueVec&& right) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueVec& right) const noexcept;
  bool operator!=(const QueueVec& right) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  const Data& Head() const override; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  Data& Head() override; // Override Queue member (mutable version; must throw std::length_error when empty)
  void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
  void Enqueue(const Data& elem) override; // Override Queue member (copy of the value)
  void Enqueue(Data&& elem) override; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  bool Empty() const noexcept override { return head == tail; } // Override Container member

  ulong Size() const noexcept override; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary member functions

  void Expand();
  void Reduce();

 // void ResizeVec(ulong head, ulong tail);

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif