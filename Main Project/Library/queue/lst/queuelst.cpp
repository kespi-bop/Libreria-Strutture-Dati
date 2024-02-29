
namespace lasd {

/* ************************************************************************** */

template <typename Data>
const Data& QueueLst<Data>::Head() const {
    if(List<Data>::Empty()) {
        throw std::length_error("Error: QueueList->IsEmpty");
    }
    return List<Data>::Front();
}

template <typename Data>
Data& QueueLst<Data>::Head() {
    if(List<Data>::Empty()) {
        throw std::length_error("Error: QueueList->IsEmpty");
    }
    return List<Data>::Front();
}

template <typename Data>
void QueueLst<Data>::Dequeue() {
    if(List<Data>::Empty()) {
        throw std::length_error("Error: QueueList->IsEmpty");
    }
    List<Data>::RemoveFromFront();
}

template <typename Data>
Data QueueLst<Data>::HeadNDequeue() {
    if(List<Data>::Empty()) {
        throw std::length_error("Error: QueueList->IsEmpty");
    }
    return List<Data>::FrontNRemove();
}

template <typename Data>
void QueueLst<Data>::Enqueue(const Data& elem) {
    List<Data>::InsertAtBack(elem);
}

template <typename Data>
void QueueLst<Data>::Enqueue(Data&& elem) {
    List<Data>::InsertAtBack(std::move(elem));
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst& right) {
    List<Data>::operator=(right);
    return *this;
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst&& right) noexcept {
    List<Data>::operator=(std::move(right));
    return *this;
}

/* ************************************************************************** */

}
