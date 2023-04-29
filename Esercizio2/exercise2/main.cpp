#include "zmytest/test.hpp"

#include "zlasdtest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */


int main() {

//binarytree concreto -> binarytree link -> BST -> iterator -> binarytree vec 

/*viene usato in const cast per evitare di riscrivere funzioni che esistono sia
in versione const che non const : const_cast<NodeLnk * *>(static_cast<const BST<data> *>(this)->FindPointerToSuccessor(nod, dat))
qui la funzione non costante richiama la funzione costante castandola a non costante in modo da non riscriverla 
il const cast si puo utilizzare soltanto su algoritmi che di per se non modificano dati.*/

//diminuzione di size solo in skip2left e skip2right

//modularizzare il piu possibile

  std::cout << "Lasd Libraries 2023" << std::endl;
  uint scelta;
  while(true)
  {
    std::cout<<"\nQuale test vuoi eseguire? Digita:\n"
                "0. esci\n"
                "1. lasdtest\n"
                "2. myTest\n";
    std::cin>>scelta;
    if(scelta == 0)
      exit(1);
    else if(scelta == 1)
      lasdtest();
    else if(scelta == 2);
      //myTest();
    else  
      continue;
  }

  return 0;
}