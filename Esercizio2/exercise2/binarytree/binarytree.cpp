#include "binarytree.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline bool BinaryTree<Data>::operator==(const BinaryTree &right) const noexcept {
    if(this->size!=right.size) return false;
    BTPreOrderIterator i(*this);
    BTPreOrderIterator j(*this);
    while(!(i.Terminated() || j.Terminated())){
        if(*i!=*j) return false;
        ++i; ++j;
    }
    return true;
}

template <typename Data>
void BinaryTree<Data>::Fold(FoldFunctor func, void *acc) const {
    for(BTPreOrderIterator i(*this); !(i.Terminated()); ++i) func(*i, acc);
    // if(!this.Empty()) {
    //     PreOrderMap( 
    //             [&func, &acc](const Data& dat) {
    //                 func(dat, acc);
    //             }
    //         );
    // }
}

template <typename Data>
void BinaryTree<Data>::PreOrderMap(MapFunctor func) const {
//   if(!this.Empty()) {
//     RecursivePreOrderMap(this.Root, func);
//   }
    for(BTPreOrderIterator i(*this); !(i.Terminated()); ++i) func(*i);
}

template <typename Data>
void BinaryTree<Data>::PostOrderMap(MapFunctor func) const {
    // if(!this.Empty()) {
    //     RecursivePostOrderMap(this.Root, func);
    // }
    for(BTPostOrderIterator i(*this); !(i.Terminated()); ++i) func(*i);
}

template <typename Data>
void BinaryTree<Data>::InOrderMap(MapFunctor func) const {
    // if(!this.Empty()) {
    //     RecursiveInOrderMap(this.Root, func);
    // }
    for(BTInOrderIterator i(*this); !(i.Terminated()); ++i) func(*i);
}

template <typename Data>
void BinaryTree<Data>::BreadthMap(MapFunctor func) const{
    // if(!this.Empty()) {
    //     NotRecursiveBreadthMap(this.Root, func);
    // }
    for(BTBreadthIterator i(*this); !(i.Terminated()); ++i) func(*i);
}

// template <typename Data>
// void BinaryTree<Data>::RecursivePreOrderMap(Node* node, MapFunctor func) const{
//     if(node == nullptr){
//         return;
//     }
//     func(node->Element());
//     RecursivePreOrderMap(node->LChild, func);
//     RecursivePreOrderMap(node->RChild, func);
// }

// template <typename Data>
// void BinaryTree<Data>::RecursivePostOrderMap(Node* node, MapFunctor func) const {
//     if(node == nullptr){
//         return;
//     }
//     RecursivePostOrderMap(node->LChild, func);
//     RecursivePostOrderMap(node->RChild, func);
//     func(node->Element());
// }

// template <typename Data>
// void BinaryTree<Data>::RecursiveInOrderMap(Node* node, MapFunctor func) const {
//     if(node == nullptr){
//         return;
//     }
//     RecursiveInOrderMap(node->LChild);
//     func(node->Element());
//     RecursiveInOrderMap(node->RChild);
// }

// template <typename Data>
// void BinaryTree<Data>::NotRecursiveBreadthMap(Node* node, MapFunctor func) const {
//     lasd::QueueVec<BinaryTree<Data>::Node *> queue; //riprova con queueLst
//     if(node!=nullptr) {
//         queue.Enqueue(node);
//     }

//     while (!queue.Empty()) {
//         BinaryTree<Data>::Node *currentNode = queue.HeadNDequeue();
//         func(currentNode->Element());

//         if(currentNode->HasLeftChild()) {
//             queue.Enqueue(&currentNode->LeftChild());
//         }

//         if(currentNode->HasRightChild()) {
//             queue.Enqueue(&currentNode->RightChild());
//         }
//     }
// }


template <typename Data>
inline void MutableBinaryTree<Data>::PreOrderMap(MutableMapFunctor func) {
    // RecursivePreOrderMap(this->Root(), func);
    for(BTPreOrderMutableIterator<Data> i(*this); !(i.Terminated()); ++i) func(*i);
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MutableMapFunctor func){
    // RecursivePreOrderMap(this->Root(), func);
for(BTPostOrderMutableIterator<Data> i(*this); !(i.Terminated()); ++i) func(*i);
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MutableMapFunctor func){
    // RecursiveInOrderMap(this->Root(), func);
for(BTInOrderMutableIterator i(*this); !(i.Terminated()); ++i) func(*i);
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MutableMapFunctor func){
    // NotRecursiveBreadthMap(this->Root(), func);
for(BTBreadthMutableIterator i(*this); !(i.Terminated()); ++i) func(*i);
}

template <typename Data>
void MutableBinaryTree<Data>::RecursivePreOrderMap(MutableNode* node, MutableMapFunctor func) {
    if(node == nullptr){
        return;
    }
    func(node->Element());
    RecursivePreOrderMap(node->LChild, func);
    RecursivePreOrderMap(node->RChild, func);
}

template <typename Data>
void MutableBinaryTree<Data>::RecursivePostOrderMap(MutableNode* node, MutableMapFunctor func){
    if(node == nullptr){
        return;
    }
    RecursivePostOrderMap(node->LChild, func);
    RecursivePostOrderMap(node->RChild, func);
    func(node->Element());
}

template <typename Data>
void MutableBinaryTree<Data>::RecursiveInOrderMap(MutableNode* node, MutableMapFunctor func){
    if(node == nullptr){
        return;
    }
    RecursiveInOrderMap(node->LChild, func);
    func(node->Element());
    RecursiveInOrderMap(node->RChild, func);
}

template <typename Data>
void MutableBinaryTree<Data>::NotRecursiveBreadthMap(MutableNode* node, MutableMapFunctor func){
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

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& right) {
    root = current = &right.Root();
}


template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator &right) {
    stack(right.stack);
    root = current = right.current;
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator&& right) noexcept : stack(std::move(right.stack)) {
    std::swap(root, right.root);
    std::swap(current, right.current); 
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator& right) {
    // if(this == &right) return *this; penso mai messo, ma andrebbe messo ovunque
    current=right.current;
    root=right.root;
    stack=right.stack;
    return *this;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator&& right) noexcept {
    std::swap(current, right.current);
    std::swap(root, right.root);
    std::swap(stack, right.stack); //NOTE: si può fare? secondo me sì perché abbiamo fatto l'operatore && in stack
    return *this;
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator &right) const noexcept {
    return (current==right.current && stack==right.stack);
}

template <typename Data>
const Data& BTPreOrderIterator<Data>::operator*() const {
    if(Terminated()) throw std::out_of_range("Iterator is terminated."); else return current->Element();
}

template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept {
    return (current==nullptr);
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {
    if(!Terminated()){
        if(current->HasLeftChild()){
            if(current->HasRightChild()) stack.Push(&current->RightChild());
            current=&(current->LeftChild());
        }else if(current->HasRightChild()) { 
            current=&(current->RightChild());
        } else if (!stack.Empty()) {
            current=stack.TopNPop();
        } else {
            current=nullptr;
        }
    } else {
        throw std::out_of_range("Out of range iterator");
    }
    return *this;
}

template <typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept {
    current=root;
}

/* ************************************************************************** */

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& right){
    root = (right.Empty()) ? nullptr : &right.Root();
    current=DeepestLeftLeaf(root);
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& right) {
    stack(right.stack);
    root=right.Root();
    current=right.current;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& right) noexcept : stack(std::move(right.stack)) {
    std::swap(current, right.current);
    std::swap(root, right.root); 
}

template <typename Data>
const Data& BTPostOrderIterator<Data>::operator*() const {
    if(Terminated()) throw std::out_of_range("Iterator is terminated."); else return current->Element();
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept {
    return (current==nullptr);
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++(){
    if(!(stack.Empty())){
        if (stack.Top()->HasRightChild() && !(&(stack.Top()->RightChild()) == current)) {
            current = &(stack.Top()->RightChild());
            current = DeepestLeftLeaf(current);
        } else {
            current = stack.TopNPop();
        }
    } else current = nullptr;

    return *this;
}

template <typename Data>
const typename BinaryTree<Data>::Node* BTPostOrderIterator<Data>::DeepestLeftLeaf(const typename BinaryTree<Data>::Node* actual){
    if(actual!=nullptr){
        while(actual->HasLeftChild()){
            stack.Push(actual);
            actual = &(actual->LeftChild());
        }
        if(actual->HasRightChild()){
            stack.Push(actual);
            actual = &(actual->RightChild());
            actual = DeepestLeftLeaf(actual);
        }
    }
    return actual;
}


template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    current=DeepestLeftLeaf(root);
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& right) {
    current=right.current;
    root=right.root;
    stack=right.stack;
    return *this;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator&& right) noexcept {
    std::swap(current, right.current);
    std::swap(root, right.root);
    std::swap(stack, right.stack); //NOTE: si può fare? secondo me sì perché abbiamo fatto l'operatore && in stack
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator &right) const noexcept {
    return (current==right.current && stack==right.stack);
}

/* ************************************************************************** */

template <typename Data>
const typename BinaryTree<Data>::Node *BTInOrderIterator<Data>::Min(const typename BinaryTree<Data>::Node* actual) {
    if(actual->HasLeftChild()){   //NOTE: bisogna controllare che current sia diverso da nullptr?
        stack.Push(actual);
        actual=Min(&(actual->LeftChild()));
    }
    return actual;
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data> &right) {
    root=&right.Root();
    current=Min(root);
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator& right) {
    stack(right.stack);
    root=&right.Root();
    current=right.current;
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator&& right) noexcept : stack(std::move(right.stack)) {
    std::swap(current, right.current);
    std::swap(root, right.root); 
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator& right) {
    current=right.current;
    root=right.root;
    stack=right.stack;
    return *this;
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator&& right) noexcept {
    std::swap(current, right.current);
    std::swap(root, right.root);
    std::swap(stack, right.stack);
    return *this;
}

template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator &right) const noexcept {
    return (current==right.current && stack==right.stack);
}

template <typename Data>
const Data& BTInOrderIterator<Data>::operator*() const {
    if(Terminated()) throw std::out_of_range("Iterator is terminated."); else return current->Element();
}

template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept {
    return (current==nullptr);
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    // NOTE: Codice copiato
    if (stack.Empty()) {
        current = stack.TopNPop();
        if (current->HasRightChild()) {
            stack.Push(&(current->RightChild()));
            Min((&(current->RightChild())));
        }
    } else current = nullptr;

    return *this;
}

template <typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    current=Min(root);
}

/* ************************************************************************** */

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& right) {
    root = current = &right.Root();
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator &right) {
    stack(right.stack);
    root = current = right.current;
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator&& right) noexcept : queue(std::move(right.queue)) {
    std::swap(root, right.root);
    std::swap(current, right.current); 
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator& right) {
    current=right.current;
    root=right.root;
    queue=right.queue;
    return *this;
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator&& right) noexcept {
    std::swap(current, right.current);
    std::swap(root, right.root);
    std::swap(queue, right.queue);
    return *this;
}

template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator &right) const noexcept {
    return (current==right.current && queue==right.queue);
}

template <typename Data>
const Data& BTBreadthIterator<Data>::operator*() const {
    if(Terminated()) throw std::out_of_range("Iterator is terminated."); else return current->Element();
}

template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept {
    return (current==nullptr);
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    if (current != nullptr) {
        if (current->HasLeftChild()) queue.Enqueue(&(current->LeftChild())); 
        if (current->HasRightChild()) queue.Enqueue(&(current->RightChild()));
        
        if (!queue.Empty()) current = queue.HeadNDequeue();
        else current = nullptr;
    }
    return *this;
}

template <typename Data>
void BTBreadthIterator<Data>::Reset() noexcept {
    current=root;
}
/* ************************************************************************** */
}
