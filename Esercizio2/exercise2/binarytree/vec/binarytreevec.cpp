
namespace lasd {

/* ************************************************************************** */

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data &dat, int i, BinaryTreeVec<Data>* bt) {
    this->bt = bt;
    this->i=i;
    bt->Elements[i]=dat;  
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data&& dat, int i, BinaryTreeVec<Data>* bt) {
    this->bt = bt;
    this->i=i;
    std::swap(bt->Elements[i], dat);  
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept
{
    return (Index()*2+1<(bt->Nodes).Size()) && ((bt->Nodes)[Index()*2+1] != nullptr);
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    return Index()*2+2<(bt->Nodes).Size() && (bt->Nodes)[Index()*2+2] != nullptr;
}

template <typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if(HasLeftChild()) return *(bt->Nodes).operator[](Index()*2+1);
    else throw std::out_of_range("BinaryTreeVec<Data>::NodeVec::LeftChild(): Not found!");
}

template <typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if(HasRightChild()) return *(bt->Nodes).operator[](Index()*2+2);//[Index()*2+2];
    else throw std::out_of_range("BinaryTreeVec<Data>::NodeVec::RightChild(): Not found!");
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if(HasLeftChild()) return *(bt->Nodes).operator[](Index()*2+1);
    else throw std::out_of_range("BinaryTreeVec<Data>::NodeVec::LeftChild(): Not found!");
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() {
    if(HasRightChild()) return *(bt->Nodes).operator[](Index()*2+2);
    else throw std::out_of_range("BinaryTreeVec<Data>::NodeVec::RightChild(): Not found!");
}

/* ************************************************************************** */

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const MappableContainer<Data>& right) {
    this->Resize(right.Size());
    Nodes.Resize(right.Size());
    int i = 0;
    this->size = right.Size();
    right.Map(
        [this, &i](const Data& dat){
            this->Nodes[i] = new NodeVec(dat, i, this);
            i++;
        }
    );

}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MutableMappableContainer<Data> &&right) noexcept {
    this->Resize(right.Size());
    Nodes.Resize(right.Size());
    int i = 0;
    std::swap(this->size, right.size);
    right.Map(
        [this, &i](const Data& dat){
            this->Nodes[i] = new NodeVec(std::move(dat), i, this);
            i++;
        }
    );
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data> &right) {
    Elements = right.Elements;
    Nodes = right.Nodes;
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data> &&right) noexcept {
    std::swap(Elements, right.Elements);
    std::swap(Nodes, right.Nodes);
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec& right) {
    Clear();
    Elements = right.Elements;
    Nodes=right.Nodes;
    return *this;
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec &&right) noexcept {
    Clear();
    Elements = std::move(right.Elements);
    Nodes = std::move(right.Nodes);
    return *this;
}

template <typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const {
    if(!this->Empty()) return *Nodes[0];
    else throw std::length_error("BinaryTreeVec<Data>::Root(): Empty tree");
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() {
    if(!this->Empty()) return *Nodes[0];
    else throw std::length_error("BinaryTreeVec<Data>::Root(): Empty tree");
}

/* ************************************************************************** */

}
