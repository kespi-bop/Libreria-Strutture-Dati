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

#include "stack/stack.hpp"
#include "stack/lst/stacklst.hpp"

using namespace std;


/* **************************************************************************


TODO
- dictionary.cpp non sono state fatte le implementazioni delle funzioni (Restituiscono true)
- foldable.hpp Verificare foldable a ricevimento
- foldable.hpp Mancano BreadthFoldableContainer e InOrderFoldableContainer
- PreOrderMap in MutableMap sarebbe PreOrderMutuableMap? 
- mappable.hpp r.395 è override? (440 è lo stesso)


************************************************************************** */


int main() {
  std::cout << "Lasd Libraries 2023" << std::endl;


  // lasd::List<int> c;
  

  // c.InsertAtBack(1);
  // c.InsertAtBack(2);
  // c.Insert(3);
 
  // std::cout<<"size: "<<c.Size()<<" lista1:"<<std::endl;
  // for(ulong i = 0; i < c.Size(); i++)
  // std::cout<<c[i]<<std::endl;

  // lasd::List<int> d(c);

  // std::cout<<"size: "<<d.Size()<<" lista2:"<<std::endl;
  // for(ulong i = 0; i < d.Size(); i++)
  // std::cout<<d[i]<<std::endl;


  // std::cout<<"ananas "<<(d==c)<<std::endl;
  // if(c == d)
  //   std::cout<<"le liste sono uguali"<<std::endl;

//  if(c.Exists("Zorro figlio di puttana"))
//   std::cout<<"WOOOOW"<<std::endl;



  // std::cout<<std::endl;

  // for(int i = 0; i < c.Size(); i++)
  //   std::cout<<c[i]<<std::endl;

  //std::cout<<c.Back()<<std::endl;
  
  lasdtest(); // Call in the menu of your library test!


  return 0;
}
