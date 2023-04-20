#include "zmytest/test.hpp"

#include "zlasdtest/test.hpp"

/* ************************************************************************** */

#include <iostream>


#include "container/container.hpp"
#include "container/testable.hpp"
#include "container/dictionary.hpp"
#include "container/foldable.hpp"
#include "container/mappable.hpp"
#include "container/linear.hpp"

#include "vector/vector.hpp"
#include "list/list.hpp"

#include "queue/queue.hpp"
#include "queue/lst/queuelst.hpp"
#include "queue/vec/queuevec.hpp"

#include "stack/stack.hpp"
#include "stack/lst/stacklst.hpp"
#include "stack/vec/stackvec.hpp"

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2023" << std::endl;
  lasdtest(); // Call in the menu of your library test!
  // lasd::Vector<int> vct(999);
  // for(int i = 0; i < 999; i++)
  // {
  //   vct[i] = i;
  // }

  // lasd::QueueVec<int> qvc(vct);

  // for(int i = 0; i < 999; i++)
  // {
  //   std::cout<<qvc.HeadNDequeue()<<"->";
  // }
  
  return 0;
}