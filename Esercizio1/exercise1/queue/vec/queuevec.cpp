
namespace lasd {

/* ************************************************************************** */

template <typename Data>
const Data& QueueVec<Data>::Head() const {
    if(Empty()) {
        throw std::length_error("QueueVec: the stack is empty in Head()");
    }
    return Elements[head];
}

template <typename Data>
Data& QueueVec<Data>::Head() {
    if(Empty()) {
        throw std::length_error("QueueVec: the stack is empty in Head()");
    }
    return Elements[head];
}

template <typename Data>
void QueueVec<Data>::Dequeue() {
    if(Empty()) {
        throw std::length_error("QueueVec: the stack is empty in Dequeue()");
    }
    CheckNReduce();
    head = (head + 1) % size;
}

template <typename Data>
Data QueueVec<Data>::HeadNDequeue() {
    if(Empty()) {
        throw std::length_error("QueueVec: the stack is empty in HeadNDequeue()");
    }
    CheckNReduce();
    head = (head + 1) % size;
    return Elements[((head - 1) % size)];
}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data& elem) {
    CheckNExpand();
    Elements[tail] = elem;
    tail = (tail + 1) % size;
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& elem) {
    CheckNExpand();
    Elements[tail] = std::move(elem);
    tail = (tail + 1) % size;
}

template <typename Data>
void QueueVec<Data>::Clear() {
    head = tail = 0;
    CheckNReduce();
}

/* ************************************************************************** */

template <typename Data>
void QueueVec<Data>::CheckNExpand() {
    if((tail + 1) % size == head) {
        ulong new_size = (ulong)(size * const_exp_set);
        Data* nuovo = new Data[new_size] {};
        for(ulong i = 0; i < size; ++i) {
            nuovo[i] = Elements[(i + head) % size];
        }
        std::swap(Elements, nuovo);
        delete[] nuovo;
        tail = Size();
        head = 0;
        size = new_size;
    }
}

template <typename Data>
void QueueVec<Data>::CheckNReduce() {    
    if(Size() <= size * const_red_check ) {
        ulong new_size = (ulong)(size * const_red_set);
        std::round(new_size);
        Data* nuovo = new Data[new_size] {};
        for(ulong i = 0; i < Size(); ++i) {
            nuovo[i] = Elements[(i+head)%size];
        }
        delete[] Elements;
        Elements=nuovo;
        tail = Size();
        head=0;
        size = new_size;
        std::cout<<size<<"->";
    }
}

template <typename Data>
QueueVec<Data>::QueueVec() {
    Vector<Data>::Resize(const_init_size);
}

template <typename Data>
QueueVec<Data>::QueueVec(const MappableContainer<Data>& cont) {
    size = cont.Size()+1;
    Vector<Data>::Elements = new Data[size] {};
    ulong index = 0;
    cont.Map(
        [this, &index](const Data& dat) {
            this->Elements[index++] = dat;
        }
    );
    tail = cont.Size();
    head = 0;
}

template <typename Data>
QueueVec<Data>::QueueVec(MappableContainer<Data>&& cont) noexcept {
    Vector<Data>::Elements = new Data[size] {};
    ulong index = 0;
    cont.Map(
        [this, &index](Data& dat) {
            this->Elements[index++] = dat;
        }
    );
    swap(size, cont.size);
    size++;
    tail = size;
    head = 0;
}

template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec& right) : Vector<Data>::Vector(right) {
    head=right.head;
    tail=right.tail;
}

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& right) noexcept {
    std::swap(head, right.head);
    std::swap(tail, right.tail);
    std::swap(size, right.size);
    std::swap(Elements, right.Elements);
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec& right) {
    this->Clear();
    Vector<Data>::Resize(right.size);
    for(ulong i{0}; i<right.Size(); i++){
        Vector<Data>::operator[](i)=right.operator[]((i+right.head)%right.size);
    }
    head=0;
    tail=right.Size();
    return *this;
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec&& right) noexcept {
    Clear();
    std::swap(Elements, right.Elements);
    std::swap(size, right.size);
    std::swap(right.head, head);
    std::swap(right.tail, tail);
    return *this;
}

template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec& right) const noexcept {
    bool result=true;
    if(Size()!=right.Size()) return false;
    for(ulong i=0; i<Size(); i++) {
        if(this->operator[]((i+head)%size)!=right[(i+right.head)%right.size]) return false;
    }
    return true;
}

template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec& right) const noexcept {
    bool result=false;
    if(Size()!=right.Size()) return true;
    for(ulong i=0; i<Size(); i++) {
        if(this->operator[]((i+head)%size)!=right[(i+right.head)%right.size]) return true;
    }
    return false;
}

}