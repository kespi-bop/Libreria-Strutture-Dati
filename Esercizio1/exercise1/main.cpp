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

  lasd::Vector<std::string> c(6);



  c[0] = "Sono razzista";
  c[1] = "Forza napoli";
  c[2] = "Viva il duce";
  c[3] = "Afacc ro cazz";
  c[4] = "Bel cazzo fra";
  c[5] = "Zorro figlio di puttana";


 if(c.Exists("Zorro figlio di puttana"))
  std::cout<<"WOOOOW"<<std::endl;

  for(int i = 0; i < c.Size(); i++)
    std::cout<<c[i]<<std::endl;

  std::cout<<std::endl;
  c.Sort();

  for(int i = 0; i < c.Size(); i++)
    std::cout<<c[i]<<std::endl;

  //std::cout<<c.Back()<<std::endl;
  
  //lasdtest(); // Call in the menu of your library test!
  return 0;
}
