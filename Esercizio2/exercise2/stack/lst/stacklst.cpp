
namespace lasd {

/* ************************************************************************** */

template <typename Data>
const Data& StackLst<Data>::Top() const {
    if(List<Data>::Empty()) {
        throw std::length_error("Error: StackList->IsEmpty");
    }
    return List<Data>::Front();
}

template <typename Data>
Data& StackLst<Data>::Top() {
    if(List<Data>::Empty()) {
        throw std::length_error("Error: StackList->IsEmpty");
    }
    return List<Data>::Front();
}

template <typename Data>
void StackLst<Data>::Pop() {
    if(List<Data>::Empty()) {
        throw std::length_error("Error: StackList->IsEmpty");
    }
    return List<Data>::RemoveFromFront();
}

template <typename Data>
Data StackLst<Data>::TopNPop() {
    if(List<Data>::Empty()) {
        throw std::length_error("Error: StackList->IsEmpty");
    }
    return List<Data>::FrontNRemove();
}

template <typename Data>
void StackLst<Data>::Push(const Data& elem) {
    List<Data>::InsertAtFront(elem);
}

template <typename Data>
void StackLst<Data>::Push(Data&& elem) {
    List<Data>::InsertAtFront(std::move(elem));
}

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst& right) {
    List<Data>::operator=(right);
    return *this;
}

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst&& right) noexcept {
    List<Data>::operator=(std::move(right));
    return *this;
}

/* ************************************************************************** */

}