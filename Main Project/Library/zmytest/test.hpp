
#ifndef MYTEST_HPP
#define MYTEST_HPP


#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/foldable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../queue/queue.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../stack/stack.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../iterator/iterator.hpp"
#include "../binarytree/binarytree.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../bst/bst.hpp"
#include "../hashtable/hashtable.hpp"
#include "../hashtable/clsadr/htclsadr.hpp"
#include "../hashtable/opnadr/htopnadr.hpp"

/* ************************************************************************** */

void myTest();

void TestEsercizio1();
bool TestCostruttori();
bool TestAssegnazioni();
bool TestDictionaryFunctions();
bool TestSort();
bool TestQueueVec();

void TestEsercizio2();
bool TestBST();
bool TestIteratori();
bool TestBTVec();
bool TestBTLnk();

void TestEsercizio3();
bool TestOpenAdr();
bool TestCloseAdr();

/* ************************************************************************** */

#endif