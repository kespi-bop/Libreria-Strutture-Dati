
// #ifndef MYTEST_HPP
// #define MYTEST_HPP


// #include "../container/container.hpp"
// #include "../container/testable.hpp"
// #include "../container/dictionary.hpp"
// #include "../container/foldable.hpp"
// #include "../container/mappable.hpp"
// #include "../container/linear.hpp"

// #include "../vector/vector.hpp"
// #include "../list/list.hpp"

// #include "../queue/queue.hpp"
// #include "../queue/lst/queuelst.hpp"
// #include "../queue/vec/queuevec.hpp"

// #include "../stack/stack.hpp"
// #include "../stack/lst/stacklst.hpp"
// #include "../stack/vec/stackvec.hpp"

// #include "../iterator/iterator.hpp"
// #include "../binarytree/binarytree.hpp"
// #include "../binarytree/lnk/binarytreelnk.hpp"
// #include "../binarytree/vec/binarytreevec.hpp"
// #include "../bst/bst.hpp"

// /* ************************************************************************** */

// void myTest();

// void TestEsercizio1();
// bool TestCostruttori();
// bool TestAssegnazioni();
// bool TestDictionaryFunctions();
// bool TestSort();
// bool TestQueueVec();

// void TestEsercizio2();
// bool TestBST();
// bool TestIteratori();

// /* ************************************************************************** */

// #endif


#ifndef MYTEST_HPP
#define MYTEST_HPP


#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"

#include "../iterator/iterator.hpp"
#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../bst/bst.hpp"

/* ************************************************************************** */

bool myTest();

/* ************************** ESERCIZIO 1 **************************************** */
bool TestQueueVec(lasd::QueueVec<int> s1);
bool TestStackVec(lasd::StackVec<int> s1);
bool TestQueueLst(lasd::QueueLst<int> s1);
bool TestStackLst(lasd::StackLst<int> s1);
bool TestQueueVecFromVec();
bool TestQueueVecFromLst();
bool TestQueueLstFromLst();
bool TestQueueLstFromVec();
bool TestCopyAssignementQueueVecFromVec();
bool TestCopyAssignementQueueVecFromLst();
bool TestCopyAssignementQueueLstFromLst();
bool TestCopyAssignementQueueLstFromVec();
bool TestMoveQueueVecFromVec();
bool TestMoveQueueVecFromLst();
bool TestMoveQueueLstFromLst();
bool TestMoveQueueLstFromVec();
bool TestMoveAssignementQueueVecFromVec();
bool TestMoveAssignementQueueVecFromLst();
bool TestMoveAssignementQueueLstFromLst();
bool TestMoveAssignementQueueLstFromVec();
bool TestCopyStackVecFromVec();
bool TestCopyStackVecFromLst();
bool TestCopyStackLstFromLst();
bool TestCopyStackLstFromVec();
bool TestCopyAssignementStackVecFromVec();
bool TestCopyAssignementStackVecFromLst();
bool TestCopyAssignementStackLstFromLst();
bool TestCopyAssignementStackLstFromVec();
bool TestMoveStackVecFromVec();
bool TestMoveStackVecFromLst();
bool TestMoveStackLstFromLst();
bool TestMoveStackLstFromVec();
bool TestMoveAssignementStackVecFromVec();
bool TestMoveAssignementStackVecFromLst();
bool TestMoveAssignementStackLstFromLst();
bool TestMoveAssignementStackLstFromVec();
bool TestEqualVector();
bool TestEqualList();
bool TestEqualStackVec();
bool TestEqualStackLst();
bool TestEqualQueueVec();
bool TestEqualQueueLst();
bool TestInsertCopyInDictionary();
bool TestInsertMoveInDictionary();
bool TestRemoveInDictionary();
bool TestInsertAllCopyInDictionary();
bool TestInsertAllMoveInDictionary();
bool TestInsertSomeCopyInDictionary();
bool TestInsertSomeMoveInDictionary();
bool TestRemoveAllInDictionary();
bool TestRemoveSomeInDictionary();
bool TestSortInt();
bool TestSortChar();
bool TestSortEmpty();

/* ************************** ESERCIZIO 2 **************************************** */
bool TestCompareBSTCopy();
bool TestCompareBSTMove();
bool TestCompareBTAndBSTFromLstCopy();
bool TestCompareBTAndBSTFromLstMove();
bool TestCompareBTAndBSTFromVecCopy();
bool TestCompareBTAndBSTFromVecMove();
bool TestCompareEmptyBTAndBST();
bool TestIteratorOnBT();
bool TestIteratorOnEmptyBT();
bool TestIteratorAfterMove();
bool TestMapsAndFoldOnBTLnk();
bool TestMapsAndFoldOnBTVec();
bool TestFindMinInBST();
bool TestFindMaxInBST();
bool TestOperationsWithSuccessor();
bool TestOperationsWithPredecessor();
bool TestDictionaryMethods();
bool TestBTVec();
bool TestBTVecMethods();
bool TestCompareBTVecAndBTLnk();


/* ************************************************************************** */

#endif