
namespace lasd {

/* ************************************************************************** */

template<typename Data>
void List<Data>::InsertAtFront(const Data& element){
    Node* temp = new Node(element);
    temp->next = head;
    head = temp;
    size++;
}

template<typename Data>
void List<Data>::InsertAtFront(Data&& element) noexcept{
    Node* temp = new Node(element);
    temp->next = head;
    head = temp;
    size++;
}

template<typename Data>
void List<Data>::RemoveFromFront(){  // (must throw std::length_error when empty)
    if(Empty())
        throw std::length_error("List->head is empty");

    Node* temp = head;
    head = head->next;
    delete temp;
}

template<typename Data>
Data List<Data>::FrontNRemove(){    // (must throw std::length_error when empty)
    if(Empty())
        throw std::length_error("List->head is empty");

    Node* temp = head;
    head = head->next;
    Data result = temp.element;
    delete temp;

    return result;
} 

template <typename Data>
const Data& List<Data>::operator[](const ulong index) const {
    if(index<0 || index >= size)
        throw std::out_of_range("Error: List->IndexOutOfBounds");

    Node* temp = head;
    for(int i = 0; i < index; i++)
        temp = temp->next;
  
    return temp->element;
}

template <typename Data>
Data& List<Data>::operator[](const ulong index) {
    if(index<0 || index>= size)  
        throw std::out_of_range("Error: List->IndexOutOfBounds");

    Node* temp = head;
    for(int i = 0; i < index; i++)
        temp = temp->next;
  
    return temp->element;
}

/* ************************************************************************** */

}
