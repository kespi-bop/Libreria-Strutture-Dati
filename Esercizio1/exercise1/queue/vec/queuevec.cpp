
namespace lasd {

/* ************************************************************************** */

template <typename Data>
const Data& QueueVec<Data>::Head() const {
    if(Empty()) throw std::length_error("QueueVec: the stack is empty in Head()");
    return Vector<Data>::operator[](head);
}

template <typename Data>
Data& QueueVec<Data>::Head() {
    if(Empty()) throw std::length_error("QueueVec: the stack is empty in Head()");
    return Vector<Data>::operator[](head);
}

template <typename Data>
void QueueVec<Data>::Dequeue() {
    if(Empty()) throw std::length_error("QueueVec: the stack is empty in Dequeue()");
    CheckNReduce();
    head=(head+1)%size;
}

template <typename Data>
Data QueueVec<Data>::HeadNDequeue() {
    if(Empty()) throw std::length_error("QueueVec: the stack is empty in HeadNDequeue()");
    CheckNReduce();
    head=(head+1)%size;
    return Vector<Data>::operator[]((head-1)%size);
}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data& elem) {
    Vector<Data>::operator[](tail) = elem;
    tail=(tail+1)%size;
    CheckNExpand();
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& elem) {
    Vector<Data>::operator[](tail) = elem;
    tail=(tail+1)%size;
    CheckNExpand();
}

template <typename Data>
void QueueVec<Data>::Clear() {
    head=tail=0;
    CheckNReduce();
}

/* ************************************************************************** */

template <typename Data>
bool QueueVec<Data>::CheckNExpand() {
    if((tail+1)%size!=head) return false;
    ulong new_size = std::round(size*const_exp_set);
    std::round(new_size);
    Data* nuovo = new Data[new_size] {};
    for(ulong i{0}; i<Size(); ++i) nuovo[i]=this->Elements[(i+head)%size];
    std::swap(this->Elements, nuovo);
    delete[] nuovo;
    tail=Size();
    head=0;
    size = new_size;
    return true;
}

template <typename Data>
bool QueueVec<Data>::CheckNReduce() {    
    if(size*const_red_check < Size() || Size()==const_init_size) return false;
    ulong new_size = (ulong)(size*const_red_set);
    std::round(new_size);
    Data* nuovo = new Data[new_size] {};
    for(ulong i{0}; i<Size(); ++i) nuovo[i]=this->Elements[(i+head)%size];
    delete[] this->Elements;
    this->Elements=nuovo;
    tail = Size();
    head=0;
    size = new_size;
    return true;
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
QueueVec<Data>::QueueVec(const QueueVec& other) : Vector<Data>::Vector(other) {
    head=other.head;
    tail=other.tail;
}

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& other) noexcept {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(size, other.size);
    std::swap(Elements, other.Elements);
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec& other) {
    this->Clear();
    Vector<Data>::Resize(other.size);
    for(ulong i{0}; i<other.Size(); i++){
        Vector<Data>::operator[](i)=other.operator[]((i+other.head)%other.size);
    }
    head=0;
    tail=other.Size();
    return *this;
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec&& other) noexcept {
    Clear();
    std::swap(Elements, other.Elements);
    std::swap(size, other.size);
    std::swap(other.head, head);
    std::swap(other.tail, tail);
    return *this;
}

template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec& other) const noexcept {
    bool result=true;
    if(Size()!=other.Size()) return false;
    for(ulong i=0; i<Size(); i++) {
        if(this->operator[]((i+head)%size)!=other[(i+other.head)%other.size]) return false;
    }
    return true;
}

template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec& other) const noexcept {
    bool result=false;
    if(Size()!=other.Size()) return true;
    for(ulong i=0; i<Size(); i++) {
        if(this->operator[]((i+head)%size)!=other[(i+other.head)%other.size]) return true;
    }
    return false;
}

}