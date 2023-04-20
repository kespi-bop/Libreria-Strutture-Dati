
#ifndef MYTEST_HPP
#define MYTEST_HPP


#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"

/* ************************************************************************** */

bool mytest();

bool TestQueuevec(lasd::QueueVec<int> s1);
bool TestStackvec(lasd::StackVec<int> s1);
bool TestQueuelst(lasd::QueueLst<int> s1);
bool TestStacklst(lasd::StackLst<int> s1);

/* ************************************************************************** */

#endif