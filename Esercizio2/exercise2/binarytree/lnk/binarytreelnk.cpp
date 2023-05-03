#include "binarytreelnk.hpp"

namespace lasd {

/* ************************************************************************** */

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const MappableContainer<Data> &right) {
    size = right.Size();
    QueueVec<NodeLnk * *> coda;
    coda.Enqueue(&root);
    right.Map(
        [&coda](const Data& dat){
            NodeLnk *& cur = *coda.HeadNDequeue();
            cur = new NodeLnk(dat);
            coda.Enqueue(&cur->LChild);
            coda.Enqueue(&cur->RChild);
        }
    );
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MutableMappableContainer<Data> &&right) {
    size = right.Size();
    QueueVec<NodeLnk * *> coda;
    coda.Enqueue(&root);
    right.Map(
        [&coda](const Data& dat){
            NodeLnk *& cur = *coda.HeadNDequeue();
            cur = new NodeLnk(std::move(dat));
            coda.Enqueue(&cur->LChild);
            coda.Enqueue(&cur->RChild);
        }
    );
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk &right){
    for(BTBreadthIterator i(right); !i.Terminated(); ++i) {
        if (root==nullptr) {
            root = new NodeLnk(*i);
            size++;
        } else {
            QueueVec<BinaryTreeLnk<Data>::NodeLnk*> coda;
            coda.Enqueue(root);
            while(!coda.Empty()){
                NodeLnk* current = coda.HeadNDequeue();
                if (!(current->HasLeftChild())) {
                    current->LChild = new NodeLnk(*i);
                    size++;
                    break;
                }
                else coda.Enqueue(current->LChild);

                if (!(current->HasRightChild())){
                    current->RChild = new NodeLnk(*i);
                    size++;
                    break;
                }
                else coda.Enqueue(current->RChild);
            }
        }
    }
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk &&right) noexcept{
    std::swap(root, right.root);
    std::swap(size, right.size);
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk &right){
    Clear();
    size = right.Size();
    QueueVec<NodeLnk * *> coda;
    coda.Enqueue(&root);
    for(BTBreadthIterator i(right); !i.Terminated(); ++i) {
        NodeLnk *& cur = *coda.HeadNDequeue();
        cur = new NodeLnk(*i);
        coda.Enqueue(&cur->LChild);
        coda.Enqueue(&cur->RChild);
    }
    return *this;
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk &&right) noexcept{
    std::swap(root, right.root);
    std::swap(size, right.size);
    return *this;
}

/* ************************************************************************** */

}
