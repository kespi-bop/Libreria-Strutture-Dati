
namespace lasd {

/* ************************************************************************** */

template <typename Data>
const Data& QueueLst<Data>::Head() const {
    return List<Data>::Front();
}

template <typename Data>
Data& QueueLst<Data>::Head() {
    return List<Data>::Front();
}

template <typename Data>
void QueueLst<Data>::Dequeue() {
    List<Data>::RemoveFromFront();
}

template <typename Data>
Data& QueueLst<Data>::HeadNDequeue() {
    Data* tmp = new Data(Head());
    Dequeue();
    return *tmp;
}

template <typename Data>
void QueueLst<Data>::Enqueue(const Data& elem) {
    List<Data>::InsertAtBack(elem);
}

template <typename Data>
void QueueLst<Data>::Enqueue(Data&& elem) {
    List<Data>::InsertAtBack(elem);
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst& other) {
    this->List<Data>::operator=(other);
    return *this;
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst&& other) noexcept {
    this->List<Data>::operator=(other);
    return *this;
}

/* ************************************************************************** */

}
