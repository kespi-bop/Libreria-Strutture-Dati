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
  //lasdtest(); // Call in the menu of your library test!
  lasd::QueueVec<int> qvc;
  for(int i = 0; i < 999; i++)
  {
    qvc.Enqueue(i);
  }

  for(int i = 0; i < 999; i++)
  {
    qvc.HeadNDequeue();
  }

    
  
  return 0;
}