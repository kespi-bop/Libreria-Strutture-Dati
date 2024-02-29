
namespace lasd {

/* ************************************************************************** */

// Copy constructor
template <typename Data>
StackVec<Data>::StackVec(const StackVec& right) {
    size = right.Size();
    number_elements = right.number_elements;
    Elements = new Data[size];
    std::copy(right.Elements, right.Elements+number_elements, Elements);
}

// Move constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec&& right) noexcept : Vector<Data>(std::move(right)){
    std::swap(right.number_elements, number_elements);
    right.Clear();
}

template <typename Data>
bool StackVec<Data>::operator==(const StackVec& right) const noexcept {
    bool result = true;
    if(number_elements != right.number_elements) {
        return false;
    }
    for(ulong i=0; i < number_elements; i++) {
        if(Elements[i]!=right[i]) {
            return false;
        }
    }
    return true;
}

template <typename Data>
bool StackVec<Data>::operator!=(const StackVec& right) const noexcept {
    return !(operator==(right));
}

template <typename Data>
const Data& StackVec<Data>::Top() const {
    if(Empty()) {
        throw std::length_error("Error: StackVector->is empty.");
    }
    return Elements[number_elements - 1];
}

template <typename Data>
Data& StackVec<Data>::Top() {
    if(Empty()) {
        throw std::length_error("Error: StackVector->is empty.");
    }
    return Elements[number_elements - 1];
}

template <typename Data>
void StackVec<Data>::Pop() {
    if(Empty()) {
        throw std::length_error("Error: StackVector->is empty.");
    }
    Reduce();
    --number_elements; 
}

template <typename Data>
Data StackVec<Data>::TopNPop() {
    if(Empty()) {
        throw std::length_error("Error: StackVector->is empty.");
    }
    Reduce();
    return Elements[--number_elements];
}

template <typename Data>
void StackVec<Data>::Push(const Data& elem) {
    Expand();
    Elements[number_elements++] = elem;
}

template <typename Data>
void StackVec<Data>::Push(Data&& elem) {
    Expand();
    Elements[number_elements++] = std::move(elem);
}

template <typename Data>
void StackVec<Data>::Expand() {
    if(number_elements == size * expand_check) {
        Vector<Data>::Resize(size * expand_set);
    }
        
}

template <typename Data>
void StackVec<Data>::Reduce() {
    if(number_elements <= size * reduce_check && number_elements >= initial_size_stack) {
            Vector<Data>::Resize(size * reduce_set);
    }

}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec& right) {
    Vector<Data>::operator=(right);
    number_elements = right.number_elements;
    return *this;
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec&& right) noexcept {
    Vector<Data>::operator=(std::move(right));
    std::swap(number_elements, right.number_elements);
    return *this;
}

template <typename Data>
void StackVec<Data>::Clear() {
    delete[] Elements;
    Elements = new Data[initial_size_stack];
    size = initial_size_stack;
    number_elements = 0;
}

/* ************************************************************************** */

template <typename Data>
StackVec<Data>::StackVec(const MappableContainer<Data>& cont) : Vector<Data>::Vector(cont) {
    number_elements = cont.Size();
    Expand(); 
}

template <typename Data>
StackVec<Data>::StackVec(MutableMappableContainer<Data>&& cont) noexcept : Vector<Data>::Vector(std::move(cont)){
    number_elements = cont.Size();
    Expand();
}

}