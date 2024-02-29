
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
    Elements = new Data[size];
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
    Elements = new Data[size];
    ulong index = 0;
    cont.Map(
        [this, &index](Data& dat) {
            Elements[index++] = std::move(dat);
        }
    );
}

//Destructor
template <typename Data>
Vector<Data>::~Vector() {
    delete[] Elements; 
}

/* ************************************************************************** */

//Copy constructor

template <typename Data>
Vector<Data>::Vector(const Vector<Data>& right){
    size = right.size;
    Elements = new Data[size];
    std::copy(right.Elements, right.Elements + size, Elements);
}

//Move constructor

template <typename Data>
Vector<Data>::Vector(Vector<Data>&& right) noexcept {
    std::swap(size, right.size);
    std::swap(Elements, right.Elements);
}

/* ************************************************************************** */

//Copy assignement

template <typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector& right) {
    size = right.size;
    delete[] Elements;
    Elements = new Data[size];
    std::copy(right.Elements, right.Elements + size, Elements);
    return *this;
}

//Move assignement

template <typename Data>
Vector<Data>& Vector<Data>::operator=(Vector&& right) noexcept {
    std::swap(size, right.size);
    std::swap(Elements, right.Elements);
    return *this;
}

/* ************************************************************************** */

//Operators

template <typename Data>
const Data& Vector<Data>::operator[](const ulong index) const {
    if (index<size) {
        return Elements[index];
    } else {
        throw std::out_of_range("Error: vector size " + std::to_string(size) + " -> trying access at " + std::to_string(index));
    }
}

template <typename Data>
Data& Vector<Data>::operator[](const ulong index) {
    if (index<size) {
        return Elements[index];
    } else {
        throw std::out_of_range("Error: vector size " + std::to_string(size) + " -> trying access at " + std::to_string(index));
    }
}

/* ************************************************************************** */

//Front and back

template <typename Data>
const Data& Vector<Data>::Front() const {
    if(size > 0) {
        return Elements[0]; 
    } else {
        throw std::length_error("Error: Vector is empty.");
    }
}

template <typename Data>
Data& Vector<Data>::Front() {
    if(size > 0) {
        return Elements[0];
    } else {
        throw std::length_error("Error: Vector is empty.");
    }
}

template <typename Data>
const Data& Vector<Data>::Back() const {
    if(size > 0) {
        return Elements[size - 1]; 
    } else {
        throw std::length_error("Error: Vector is empty.");
    }
}

template <typename Data>
Data& Vector<Data>::Back() {
    if(size > 0) {
        return Elements[size - 1]; 
    }
    else {
        throw std::length_error("Error: Vector is empty.");
    }
}

template <typename Data>
void Vector<Data>::Resize(const ulong new_size) {
    if(new_size == 0){
        Clear();
    } else if (size!=new_size) {
        Data* temp_vec = new Data[new_size] {};
        ulong min_size = (size<new_size) ?  size : new_size;
        for(ulong i = 0; i < min_size; i++) {
            std::swap(Elements[i], temp_vec[i]);
        }
        std::swap(Elements, temp_vec);
        size = new_size;
        delete[] temp_vec;
    }
}



template <typename Data>
void Vector<Data>::Clear() {
    delete[] Elements;
    Elements=nullptr;
    size=0;
}

template <typename Data>
bool Vector<Data>::operator==(const Vector& right) const noexcept {
    bool result=true;
    if(size!=right.size) { 
        return false;
    }
    for(ulong i=0; i<size; i++) {
        if(Elements[i]!=right.Elements[i]) {
            return false;
        }
    }
    return true;
}

template <typename Data>
bool Vector<Data>::operator!=(const Vector& right) const noexcept {
    return !(operator==(right));
}

//Sort

template <typename Data>
void Vector<Data>::Sort() noexcept {
    if(!(Empty())) {
        SortableLinearContainer<Data>::Quicksort(0, size - 1);
    }
}


}
