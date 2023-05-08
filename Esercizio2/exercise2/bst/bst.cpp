#include "bst.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline BST<Data>::BST(const MutableContainer &right) {
    right.Map(
        [this](const Data& value){
            Insert(value);
        }
    )
}

template <typename Data>
BST<Data>::BST(MappableMutableContainer &&right) noexcept {
        right.Map(
        [this](const Data& value){
            Insert(std::move(value));
        }
    )
}

template<typename Data>
BST<Data>::BST(const BST<Data>& right): BinaryTreeLnk<Data>::BinaryTreeLnk(right) {}

template<typename Data>
BST<Data>::BST(BST<Data>&& right) noexcept: BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(right)) {}

template <typename Data>
BST<Data>& BST<Data>::operator=(const BST<Data>& right){
  BinaryTreeLnk<Data>::operator=(right);
  return *this;
}
template <typename Data>
BST<Data>& BST<Data>::operator=(BST<Data>&& right)noexcept{
  BinaryTreeLnk<Data>::operator=(std::move(right));
  return *this;
}

template <typename Data>
bool BST<Data>::operator==(const BST &right) noexcept {
    if (size == other.Size()) {
    BTInOrderIterator<Data> IterThis(*this);
    BTInOrderIterator<Data> IterORight(right);
    for (; !IterThis.Terminated(); ++IterThis, ++IterORight) {
      if((*IterThis) != (*IterORight)) {
        return false;
      }
    }
    return true;
  }
  return false;
}

template <typename Data>
inline Data &BST<Data>::Min() const {
    if (root != nullptr) {
        return FindPointerToMin(root)->elem;
    } else {
        throw std::length_error("Error: BST isEmpty.");
    }
}

template <typename Data>
Data BST<Data>::MinNRemove() const {
    if (root != nullptr) {
        return DataNDelete(DetachMin(root));
    }
    else throw std::length_error("Error: BST isEmpty.");
}

template <typename Data>
void BST<Data>::RemoveMin() const {
    if (root != nullptr) {
        delete DetachMin(root);
    } else {
        throw std::length_error("Error: BST isEmpty.");
    }
}

template <typename Data>
Data &BST<Data>::Max() const {
    if (root != nullptr) {
    return FindPointerToMax(root)->elem;
  } else {
    throw std::length_error("Error: BST isEmpty.");
  }
}

template <typename Data>
Data BST<Data>::MaxNRemove(){
  if (root != nullptr) {
    return DataNDelete(DetachMax(root));
  } else {
    throw std::length_error("L'albero è vuoto");
  }
}

template<typename Data>
void BST<Data>::RemoveMax() {
  if (root != nullptr) {
    delete DetachMax(root);
  } else {
    throw std::length_error("Error: BST isEmpty.");
  }
}

template <typename Data>
Data &BST<Data>::Predecessor(const Data &find) const {
    NodeLnk* const* ptr =& FindPointerToPredecessor(root, find);
    if (ptr != nullptr) {
        return (*ptr)->elem;
    } else {
        throw std::length_error("Error: Predecessor not found");
    }
}

template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data &find) const {
  NodeLnk** ptr =&FindPointerToPredecessor(root, find);
  if (ptr != nullptr) {
    return DataNDelete(Detach(*ptr));
  } else {
    throw std::length_error("Error: Predecessor not found");
  }
}

template <typename Data>
void BST<Data>::RemovePredecessor(const Data &find) const {
    NodeLnk** puntatore=&FindPointerToPredecessor(root,valore);
    if (puntatore != nullptr) {
        delete Detach(*puntatore);
    } else {
        throw std::length_error("Error: Predecessor not found");
    }
}

template <typename Data>
Data &BST<Data>::Successor(const Data &find) const {
    NodeLnk* const* ptr =& FindPointerToSuccessor(root, find);
    if(ptr !=nullptr){
        return (*ptr)->elem;
    }
    else{
        throw std::length_error("Error: Successor not found");
    }
}

template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data &find) const {
    NodeLnk** ptr =& FindPointerToSuccessor(root, find);
    if (ptr != nullptr) {
        return DataNDelete(Detach(*ptr));
    } else {
        throw std::length_error("Error: Successor not found");
    }
}

template <typename Data>
void BST<Data>::RemoveSuccessor(const Data &find) const {
    NodeLnk **ptr =& FindPointerToSuccessor(root, find);
    if (ptr != nullptr) {
        delete Detach(*ptr);
    } else {
        throw std::length_error("Error: Successor not found");
    }
}

template <typename Data>
inline bool BST<Data>::Insert(const Data &value) {
    NodeLnk * & ptr = FindPointerTo(root, value); 
    if(ptr == nullptr){
    ptr = new NodeLnk(value);
    size++;
    return true;
  }
  return false;
}

template <typename Data>
bool BST<Data>::Insert(Data &&value){
    NodeLnk * & ptr = FindPointerTo(root, value); 
    if(ptr == nullptr){
    ptr = new NodeLnk(std::move(value));
    size++;
    return true;
  }
  return false;
}

template <typename Data>
bool BST<Data>::Remove(const Data &value){
  NodeLnk * & puntatore = FindPointerTo(root, dat);
  if(puntatore != nullptr){
    delete Detach(puntatore);
    return true;
  }
  return false;
}

template <typename Data>
bool BST<Data>::Exists(const Data &value) const noexcept {
  return (FindPointerTo(root,valore) !=nullptr);
}

// template <typename Data>
// void BST<Data>::Clear() {
//     if (root != nullptr) { 
//         DeleteSubTree(root); root=nullptr; 
//     }
// }

template <typename Data>
inline Data BST<Data>::DataNDelete(NodeLnk *node) {
  Data valure;
  std::swap(value, puntatore->elem);
  delete puntatore;
  return value;
}

template <typename Data>
NodeLnk *BST<Data>::Detach(NodeLnk *&node) noexcept {
    if (node != nullptr) {
        if (node->lChild == nullptr) {
            return Skip2Right(node);
        }
        else if (node->rChild == nullptr) {
            return Skip2Left(node);
        }
        else {
            NodeLnk *max = DetachMax(node->lChild);
            std::swap(node->elem, max->elem);
            return max;
        }
    }
    return nullptr;
}

template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(typename BST<Data>::NodeLnk*& node)noexcept{
  return Skip2Left(FindPointerToMax(node));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Left(typename BST<Data>::NodeLnk*& node) noexcept{
  NodeLnk* new_lChild = nullptr;
  if (node != nullptr) {
    std::swap(new_lChild, node->lChild);
    std::swap(new_lChild, node);
    size--;
  }
  return new_lChild;
}
template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(typename BST<Data>::NodeLnk*& node)noexcept{
  return Skip2Right(FindPointerToMin(node));
}
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Right(typename BST<Data>::NodeLnk*& node) noexcept{
  NodeLnk *new_rChild = nullptr;
  if (node != nullptr) {
    std::swap(new_rChild, node->rChild);
    std::swap(new_rChild, node);
    size--;
  }
  return new_rChild;
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(typename BST<Data>::NodeLnk*& Nodo) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMin(Nodo));
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(typename BST<Data>::NodeLnk*& Nodo) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMax(Nodo));
}

template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerTo(typename BST<Data>::NodeLnk* const& Nodo, Data valore) const noexcept{
  NodeLnk *const *puntatore = &Nodo;
  NodeLnk *corrente = Nodo;

  while (corrente != nullptr) {
    if (valore > corrente->elem) {
      puntatore = &corrente->rChild;
      corrente = corrente->rChild;
    } else if (valore < corrente->elem) {
      puntatore = &corrente->lChild;
      corrente = corrente->lChild;
    } else {
      break; // NOTE: Da verificare se necessario
    }
  }
  return *puntatore;
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(typename BST<Data>::NodeLnk*& Nodo, Data valore) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerTo(Nodo,valore));
}

template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToPredecessor(typename BST<Data>::NodeLnk* const& Nodo, Data valore) const noexcept{
  NodeLnk *const *predecessore = nullptr;
  NodeLnk *const *corrente = &Nodo;

  while ((*corrente) != nullptr && (*corrente)->elem != valore) {
    if ((*corrente)->elem > valore) {
      corrente = &(*corrente)->lChild;
    } else if ((*corrente)->elem < valore) {
      predecessore = corrente;
      corrente = &(*corrente)->rChild;
    }
  }
  if ((*corrente) != nullptr && (*corrente)->lChild != nullptr) {
    predecessore = &FindPointerToMax((*corrente)->lChild);
  }

  return *predecessore;
}

template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToSuccessor(typename BST<Data>::NodeLnk* const& node, Data valore) const noexcept{
  typename BST<Data>::NodeLnk *const *successor = nullptr;
  typename BST<Data>::NodeLnk *const *current = &node;

  while ((*current) != nullptr && (*current)->elem != valore) {
    if ((*current)->elem < valore) current = &(*current)->rChild;
    else if ((*current)->elem > valore) {
      successor = current;
      current = &(*current)->lChild;
    }
  }
  if ((*current) != nullptr && (*current)->rChild != nullptr) successor = &FindPointerToMin((*current)->rChild);

  return *successor;
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToPredecessor(typename BST<Data>::NodeLnk*& Nodo, Data valore) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToPredecessor(Nodo,valore));
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToSuccessor(typename BST<Data>::NodeLnk*& Nodo, Data valore) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToSuccessor(Nodo,valore));
}

/* ************************************************************************** */

}
