
namespace lasd {

/* ************************************************************************** */

// Copy constructor
template <typename Data>
StackVec<Data>::StackVec(const StackVec& other) {
    size = other.riempimento;
    riempimento=other.riempimento;
    this->Elements = new Data[riempimento];
    std::copy(other.Elements, other.Elements+riempimento, this->Elements);
    CheckNExpand();
    CheckNReduce();
}

// Move constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec&& other) noexcept {
    std::swap(other.Elements, this->Elements);
    std::swap(other.riempimento, riempimento);
    std::swap(other.size, size);
    CheckNExpand();
    CheckNReduce();
}

template <typename Data>
bool StackVec<Data>::operator==(const StackVec& other) const noexcept {
    bool result=true;
    if(riempimento!=other.riempimento) return false;
    for(ulong i=0; i<riempimento; i++) {
        if(this->operator[](i)!=other[i]) return false;
    }
    return true;
}

template <typename Data>
bool StackVec<Data>::operator!=(const StackVec& other) const noexcept {
    bool result=false;
    if(riempimento!=other.riempimento) return true;
    for(ulong i=0; i<riempimento; i++) {
        if(this->operator[](i)!=other[i]) return true;
    }
    return false;
}

template <typename Data>
const Data& StackVec<Data>::Top() const {
    if(Empty()) throw std::length_error("StackVec: the stack is empty in Top()");
    return Vector<Data>::operator[](riempimento-1);
}

template <typename Data>
Data& StackVec<Data>::Top() {
    if(Empty()) throw std::length_error("StackVec: the stack is empty in Top()");
    return Vector<Data>::operator[](riempimento-1);
}

template <typename Data>
void StackVec<Data>::Pop() {
    if(Empty()) throw std::length_error("StackVec: the stack is empty in Pop()");
    CheckNReduce();
    riempimento--;
}

template <typename Data>
Data StackVec<Data>::TopNPop() {
    if(Empty()) throw std::length_error("StackVec: the stack is empty in TopNPop()");
    CheckNReduce();
    return Vector<Data>::operator[](--riempimento);
}

template <typename Data>
void StackVec<Data>::Push(const Data& elem) {
    CheckNExpand();
    Vector<Data>::operator[](riempimento++) = elem;
}

template <typename Data>
void StackVec<Data>::Push(Data&& elem) {
    //forse prima va cancellato e poi fatto il move
    Vector<Data>::operator[](riempimento++) = std::move(elem);
    CheckNExpand();
}


template <typename Data>
bool StackVec<Data>::CheckNExpand() {
    if ((size*const_exp_check) > riempimento) return false;
    if(size<=const_init_size) Vector<Data>::Resize(const_init_size);
    Vector<Data>::Resize(size*const_exp_set);
    return true;
}

template <typename Data>
bool StackVec<Data>::CheckNReduce() {
    if(size*const_red_check <= riempimento) return false;
    if(riempimento<=const_init_size) Vector<Data>::Resize(const_init_size);
    else Vector<Data>::Resize(size*const_red_set);
    return true;
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec& other) {
    Clear();
    Vector<Data>::operator=(other);
    riempimento=other.riempimento;
    CheckNExpand();
    CheckNReduce();
    return *this;
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec&& other) noexcept {
    std::swap(size, other.size);
    std::swap(this->Elements, other.Elements);
    std::swap(riempimento, other.riempimento);
    CheckNExpand();
    CheckNReduce();
    return *this;
}

template <typename Data>
void StackVec<Data>::Clear() {
    riempimento=0;
    CheckNReduce();
}

/* ************************************************************************** */

template <typename Data>
StackVec<Data>::StackVec(){
    this->Elements = new Data[const_init_size];
    size=const_init_size;
}

template <typename Data>
StackVec<Data>::StackVec(const MappableContainer<Data>& cont) {
    size = cont.Size();
    Vector<Data>::Elements = new Data[size] {};
    ulong index = 0;
    cont.Map(
        [this, &index](const Data& dat) {
            this->Elements[index++] = dat;
        }
    );
    riempimento = cont.Size();
    CheckNExpand(); 
}

template <typename Data>
StackVec<Data>::StackVec(MappableContainer<Data>&& cont) noexcept {
    riempimento = cont.Size();
    Vector<Data>::Elements = new Data[size] {};
    ulong index = 0;
    cont.Map(
        [this, &index](Data& dat) {
            this->Elements[index++] = dat;
        }
    );
    size=cont.size();
    CheckNExpand(); 
    cont.~MappableContainer();
}

}