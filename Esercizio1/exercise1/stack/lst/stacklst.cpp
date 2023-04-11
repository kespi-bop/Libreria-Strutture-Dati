
namespace lasd {

/* ************************************************************************** */

template <typename Data>
const Data& StackLst<Data>::Top() const {
    if(List<Data>::Empty()) throw std::length_error("StackLst: the stack is empty in Top()");
    return List<Data>::Front();
}

template <typename Data>
Data& StackLst<Data>::Top() {
    if(List<Data>::Empty()) throw std::length_error("StackLst: the stack is empty in Top()");
    return List<Data>::Front();
}

template <typename Data>
void StackLst<Data>::Pop() {
    if(List<Data>::Empty()) throw std::length_error("StackLst: the stack is empty in Pop()");
    return List<Data>::RemoveFromFront();
}

template <typename Data>
Data& StackLst<Data>::TopNPop() {
    if(List<Data>::Empty()) throw std::length_error("StackLst: the stack is empty in TopNPop()");
    return List<Data>::FrontNRemove();
}

template <typename Data>
void StackLst<Data>::Push(const Data& elem) {
    List<Data>::InsertAtFront(elem);
}

template <typename Data>
void StackLst<Data>::Push(Data&& elem) {
    List<Data>::InsertAtFront(elem);
}

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst& other) {
    this->List<Data>::operator=(other);
    return *this;
}

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst&& other) noexcept {
    this->List<Data>::operator=(other);
    return *this;
}

/* ************************************************************************** */

}