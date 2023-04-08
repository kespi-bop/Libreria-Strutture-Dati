
namespace lasd {

/* ************************************************************************** */

//Constructors

template <typename Data>
Vector<Data>::Vector(const ulong new_size) {
    size = new_size;
    Elements = new Data[size] {};
}

template <typename Data>
Vector<Data>::Vector(const MappableContainer<Data>& cont) {
    size = cont.Size();
    Elements = new Data[size] {};
    ulong index = 0;
    cont.Map(
        [this, &index](const Data& dat) {
            Elements[index++] = dat;
        }
    );
}

template <typename Data>
Vector<Data>::Vector(MutableMappableContainer<Data>&& cont) noexcept {
    size = cont.Size();
    Elements = new Data[size] {};
    ulong index = 0;
    cont.Map(
        [this, &index](const Data& dat) {
            Elements[index++] = dat;
        }
    );
    cont.~MutableMappableContainer();
}

//Destructor


/* ************************************************************************** */

//Copy constructor

template <typename Data>
Vector<Data>::Vector(const Vector<Data>& other){
    size = other.size;
    Elements = new Data[size];
    std::copy(other.Elements, other.Elements+size, Elements);
}

//Move constructor

template <typename Data>
Vector<Data>::Vector(Vector<Data>&& other) noexcept {
    std::swap(size, other.size);
    std::swap(Elements, other.Elements);
}

/* ************************************************************************** */

//Copy assignement

template <typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector& other) {
    size = other.size;
    Elements = new Data[size];
    std::copy(other.Elements, other.Elements+size, Elements);
    return *this;
}

//Move assignement

template <typename Data>
Vector<Data>& Vector<Data>::operator=(Vector&& other) noexcept {
    std::swap(size, other.size);
    std::swap(Elements, other.Elements);
    return *this;
}

/* ************************************************************************** */

//Operators

template <typename Data>
const Data& Vector<Data>::operator[](const ulong index) const {
    if (index<size) return Elements[index];
    else throw std::out_of_range("Vector: out of range index of operator[]");
}

template <typename Data>
Data& Vector<Data>::operator[](const ulong index) {
    if (index<size) return Elements[index];
    else throw std::out_of_range("Vector: out of range index of operator[]");
}

/* ************************************************************************** */

//Front and back

template <typename Data>
const Data& Vector<Data>::Front() const {
    if(size > 0)return Elements[0]; 
    else throw std::length_error("Vector: out of range index of Front()");
}

template <typename Data>
Data& Vector<Data>::Front() {
    if(size > 0)return Elements[0]; 
    else throw std::length_error("Vector: out of range index of Front()");
}

template <typename Data>
const Data& Vector<Data>::Back() const {
    if(size > 0)return Elements[size - 1]; 
    else throw std::length_error("Vector: out of range index of Back()"); 
}

template <typename Data>
Data& Vector<Data>::Back() {
    if(size > 0)return Elements[size - 1]; 
    else throw std::length_error("Vector: out of range index of Back()"); 
}

template <typename Data>
void Vector<Data>::Resize(const ulong new_size) {
    if(new_size==0){
        Clear();
    }
    else if (size!=new_size) {
        Data* ptr = new Data[new_size] {};
        ulong min_size = (size<new_size) ?  size : new_size;
        for(ulong i{0}; i<min_size; ++i) std::swap(Elements[i], ptr[i]);
        std::swap(Elements, ptr);
        size = new_size;
        delete[] ptr;
    }
}

template <typename Data>
Vector<Data>::~Vector() {
    delete[] Elements; 
    Elements=nullptr;
    size=0;
}

template <typename Data>
void Vector<Data>::Clear() {
    delete[] Elements;
    Elements=nullptr;
    size=0;
}

template <typename Data>
bool Vector<Data>::operator==(const Vector& other) const noexcept {
    bool result=true;
    if(size!=other.size) return false;
    for(ulong i=0; i<size; i++) {
        if(this->operator[](i)!=other[i]) return false;
    }
    return true;
}

template <typename Data>
bool Vector<Data>::operator!=(const Vector& other) const noexcept {
    bool result=false;
    if(size!=other.size) return true;
    for(ulong i=0; i<size; i++) if(this->operator[](i)!=other[i]) return true;
    return false;
}

//Sort

template <typename Data>
void Vector<Data>::Sort() noexcept {
    SortableLinearContainer<Data>::Quicksort(0, size - 1);
}


}
