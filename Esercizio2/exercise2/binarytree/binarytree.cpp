#include "binarytree.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline bool BinaryTree<Data>::operator==(const BinaryTree &right) const noexcept {
  if(this.size!=right.size) {
    return false;
  }
  //finire
}

template <typename Data>
void BinaryTree<Data>::Fold(FoldFunctor func, void *acc) const {
    if(!this.Empty()) {
        PreOrderMap( 
                [&func, &acc](const Data& dat) {
                    func(dat, acc);
                }
            );
    }
}

template <typename Data>
void BinaryTree<Data>::PreOrderMap(MapFunctor func) const {
  if(!this.Empty()) {
    RecursivePreOrderMap(this.Root, func);
  }
}

template <typename Data>
void BinaryTree<Data>::PostOrderMap(MapFunctor func) const {
    if(!this.Empty()) {
        RecursivePostOrderMap(this.Root, func);
    }
}

template <typename Data>
void BinaryTree<Data>::InOrderMap(MapFunctor func) const {
    if(!this.Empty()) {
        RecursiveInOrderMap(this.Root, func);
    }
}

template <typename Data>
void BinaryTree<Data>::BreadthMap(MapFunctor func) const{
    if(!this.Empty()) {
        NotRecursiveBreadthMap(this.Root, func);
    }
}

template <typename Data>
void BinaryTree<Data>::RecursivePreOrderMap(Node node, MapFunctor func) const{
    if(node == nullptr){
        return;
    }
    func(node->Element());
    PreOrderMap(node->LChild);
    PreOrderMap(node->RChild);
}

template <typename Data>
void BinaryTree<Data>::RecursivePostOrderMap(Node node, MapFunctor func) const {
    if(node == nullptr){
        return;
    }
    PreOrderMap(node->LChild);
    PreOrderMap(node->RChild);
    func(node->Element());
}

template <typename Data>
void BinaryTree<Data>::RecursiveInOrderMap(Node node, MapFunctor func) const {
    if(node == nullptr){
        return;
    }
    RecursiveInOrderMap(node->LChild);
    func(node->Element());
    RecursiveInOrderMap(node->RChild);
}

template <typename Data>
void BinaryTree<Data>::NotRecursiveBreadthMap(Node node, MapFunctor func) const {
    lasd::QueueVec<BinaryTree<Data>::Node *> queue; //riprova con queueLst
    if(node!=nullptr) {
        queue.Enqueue(node);
    }

    while (!queue.Empty()) {
        BinaryTree<Data>::Node *currentNode = queue.HeadNDequeue();
        func(currentNode->Element());

        if(currentNode->HasLeftChild()) {
            queue.Enqueue(&currentNode->LeftChild());
        }

        if(currentNode->HasRightChild()) {
            queue.Enqueue(&currentNode->RightChild());
        }
    }
}

template <typename Data>
inline void MutableBinaryTree<Data>::PreOrderMap(MutableMapFunctor func) {
    RecursivePreOrderMap(this->Root(), func);
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MutableMapFunctor func){
    RecursivePreOrderMap(this->Root(), func);
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MutableMapFunctor func){
    RecursiveInOrderMap(this->Root(), func);
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MutableMapFunctor func){
    NotRecursiveBreadthMap(this->Root(), func);
}

template <typename Data>
void MutableBinaryTree<Data>::RecursivePreOrderMap(MutableNode node, MutableMapFunctor func) {
    if(node == nullptr){
        return;
    }
    func(node->Element());
    PreOrderMap(node->LChild);
    PreOrderMap(node->RChild);
}

template <typename Data>
void MutableBinaryTree<Data>::RecursivePostOrderMap(MutableNode node, MutableMapFunctor func){
    if(node == nullptr){
        return;
    }
    PreOrderMap(node->LChild);
    PreOrderMap(node->RChild);
    func(node->Element());
}

template <typename Data>
void MutableBinaryTree<Data>::RecursiveInOrderMap(MutableNode node, MutableMapFunctor func){
    if(node == nullptr){
        return;
    }
    RecursiveInOrderMap(node->LChild);
    func(node->Element());
    RecursiveInOrderMap(node->RChild);
}

template <typename Data>
void MutableBinaryTree<Data>::NotRecursiveBreadthMap(MutableNode node, MutableMapFunctor func){
    lasd::QueueVec<MutableBinaryTree<Data>::MutableNode *> queue; //riprova con queueLst
    if(node!=nullptr) {
        queue.Enqueue(node);
    }

    while (!queue.Empty()) {
        MutableBinaryTree<Data>::MutableNode *currentNode = queue.HeadNDequeue();
        func(currentNode->Element());

        if(currentNode->HasLeftChild()) {
            queue.Enqueue(&currentNode->LeftChild());
        }

        if(currentNode->HasRightChild()) {
            queue.Enqueue(&currentNode->RightChild());
        }
    }
}
/* ************************************************************************** */
}
