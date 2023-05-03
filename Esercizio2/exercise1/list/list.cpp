
#include "list.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
List<Data>::List(const MappableContainer<Data>& cont) {
    cont.Map(
        [this](const Data& dat) {
            InsertAtBack(dat);
        }
    );
}

template <typename Data>
List<Data>::List(MutableMappableContainer<Data>&& cont) noexcept {
    cont.Map(
        [this](Data& dat) {
            InsertAtBack(std::move(dat));
        }
    );
}

template <typename Data>
List<Data>::List(const List &right){
    for(ulong i = 0; i < right.Size(); i++){
        InsertAtBack(right[i]);
    }
}

template <typename Data>
List<Data>::List(List &&right) noexcept{
    std::swap(head, right.head);
    std::swap(size, right.size);
}

template <typename Data>
List<Data>& List<Data>::operator=(const List& right) {
    Node* nodo = right.head;
    Clear();
    right.PostOrderMap(
        [this](const Data& dat) {
            InsertAtFront(dat);
        }
    );
    return *this;
}

template <typename Data>
List<Data> &List<Data>::operator=(List &&right) noexcept
{
    std::swap(head, right.head);
    std::swap(size, right.size); 
    return *this;
}

template <typename Data>
bool List<Data>::operator==(const List &right) const noexcept
{
    if(size!=right.size) {
        return false;
    }
    
    Node* list1 = head;
    Node* list2 = right.head;

    for(ulong i = 0; i < size; i++){
        if(list1->element != list2->element) {
            return false;
        }  
        list1=list1->next;
        list2=list2->next;
    }
    return true;
}

template <typename Data>
bool List<Data>::operator!=(const List &right) const noexcept
{
    return !(operator==(right));
}

template <typename Data>
void List<Data>::InsertAtFront(const Data &element){
    Node* temp = new Node(element);
    temp->next = head;
    head = temp;
    size++;
}

template<typename Data>
void List<Data>::InsertAtFront(Data&& element) noexcept{
    Node* temp = new Node(std::move(element));
    temp->next = head;
    head = temp;
    size++;
}

template<typename Data>
void List<Data>::RemoveFromFront(){
    if(Empty()){
        throw std::length_error("Error: List->IsEmpty");
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
}

template <typename Data>
Data List<Data>::FrontNRemove() {
    if(Empty()){
        throw std::length_error("Error: List->IsEmpty");
    }
    Data elemento = head->element;
    RemoveFromFront();
    return elemento;
}


template <typename Data>
void List<Data>::InsertAtBack(const Data &element){
    Node* last_node = head;
    Node* new_node = new Node(element);

    if(!Empty()){
        while(last_node->next!=nullptr)
            last_node = last_node->next;
        last_node->next = new_node;    
    } else {
        head = new_node;
    }
    size++;
}

template <typename Data>
void List<Data>::InsertAtBack(Data &&element) noexcept{
    Node* last_node = head;
    Node* new_node = new Node(std::move(element));

    if(!Empty()){
        while(last_node->next!=nullptr)
            last_node = last_node->next;
        last_node->next = new_node;    
    } else {
        head = new_node;
    }
    size++;
}

template <typename Data>
void List<Data>::Clear(){
    while(!Empty()){
        RemoveFromFront();
    }
}

template <typename Data>
bool List<Data>::Insert(const Data &element){
    if(!(FoldableContainer<Data>::Exists(element))) 
    {
        InsertAtBack(element);
        return true;
    }
    return false;
}

template <typename Data>
bool List<Data>::Insert(Data &&element) noexcept{
    if(!(FoldableContainer<Data>::Exists(element))) 
    {
        InsertAtBack(std::move(element));
        return true;
    }
    return false;
}

template <typename Data>
bool List<Data>::Remove(const Data &element){
    Node* find = head;
    Node* prev = nullptr;

    while (find!=nullptr && find->element!=element){
        prev = find;
        find = find->next;
    }
    
    if(find!=nullptr){
        if(prev ==nullptr){
            head = find->next;
        }
        else{
            prev->next = find->next;
        }
        delete find;
        size--;
        return true;
    }
    return false;
}

template <typename Data>
const Data& List<Data>::operator[](const ulong index) const {
    if(index >= size)
        throw std::out_of_range("Error: List->IndexOutOfBounds");

    Node* temp = head;
    for(ulong i = 0; i < index; i++)
        temp = temp->next;
  
    return temp->element;
}

template <typename Data>
Data& List<Data>::operator[](const ulong index) {
    if(index>= size)  
        throw std::out_of_range("Error: List->IndexOutOfBounds");

    Node* temp = head;
    for(int i = 0; i < index; i++)
        temp = temp->next;
  
    return temp->element;
}

template <typename Data>
const Data &List<Data>::Front() const{
    if(Empty())
        throw  std::length_error("Error: List->IsEmpty");
    
    return head->element;
}

template <typename Data>
Data &List<Data>::Front(){
    if(Empty())
        throw  std::length_error("Error: List->IsEmpty");
    
    return head->element;
}

template <typename Data>
const Data &List<Data>::Back() const
{
    if(Empty())
        throw std::length_error("Error: List->IsEmpty");
    Node* temp = head;
    while(temp->next!=nullptr)
        temp = temp->next;

    return temp->element;
}

template <typename Data>
Data &List<Data>::Back()
{
    if(Empty())
        throw std::length_error("Error: List->IsEmpty");
    Node* temp = head;
    while(temp->next!=nullptr)
        temp = temp->next;

    return temp->element;
}


template <typename Data>
void List<Data>::PreOrderFold(FoldFunctor func, void *acc) const{
    AuxPreOrderFold(head, func, acc);
}

template <typename Data>
void List<Data>::AuxPreOrderFold(const Node* nodo, FoldFunctor func, void* acc) const {
    const Node* punt = nodo;
    while(punt!=nullptr){
        func(punt->element, acc);
        punt=punt->next;
    }
}

template <typename Data>
void List<Data>::PostOrderFold(FoldFunctor func, void *acc) const{
    if(!Empty())
    {
        RecursivePostOrderFold(head, func, acc);
    }
}

template <typename Data>
void List<Data>::PreOrderMap(MapFunctor func) const{
    AuxPreOrderMap(head, func);
}

template <typename Data>
void List<Data>::AuxPreOrderMap(const Node* nodo, MapFunctor func) const {
    const Node* punt = nodo;
    while(punt!=nullptr){
        func(punt->element);
        punt=punt->next;
    }
}

template <typename Data>
void List<Data>::PostOrderMap(MapFunctor func) const{;
    if(!Empty())
    {
        RecursivePostOrderMap(head, func);
    }
}

template <typename Data>
void List<Data>::PreOrderMap(MutableMapFunctor func){
    AuxPreOrderMap(head, func);
}

template <typename Data>
void List<Data>::AuxPreOrderMap(Node* nodo, MutableMapFunctor func) {
    Node* punt = nodo;
    while(punt!=nullptr){
        func(punt->element);
        punt=punt->next;
    }
}

template <typename Data>
void List<Data>::PostOrderMap(MutableMapFunctor func){
    if(!(Empty()))
    {
        RecursivePostOrderMap(head, func);
    }
}

template <typename Data>
void List<Data>::RecursivePostOrderFold(const Node *nodo, FoldFunctor func, void *acc) const
{
    if(nodo==nullptr)
        return;
        
    if(nodo->next!=nullptr) {
        RecursivePostOrderFold(nodo->next, func, acc);
    }
    func(nodo->element, acc);
}

template <typename Data>
void List<Data>::RecursivePostOrderMap(Node *nodo, MapFunctor func) const
{
    if(nodo==nullptr)
        return;

    if(nodo->next!=nullptr){
        RecursivePostOrderMap(nodo->next, func);
    }
    func(nodo->element);
}

template <typename Data>
void List<Data>::RecursivePostOrderMap(Node *nodo, MutableMapFunctor func)
{
    if(nodo==nullptr)
        return;

    if(nodo->next!=nullptr){
        RecursivePostOrderMap(nodo->next, func);
    }
    func(nodo->element);
}

/* ************************************************************************** */

}
