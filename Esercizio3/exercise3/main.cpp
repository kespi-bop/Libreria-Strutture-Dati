#include "zmytest/test.hpp"

#include "zlasdtest/test.hpp"

#include "./container/container.hpp"
#include "./container/testable.hpp"
#include "./container/dictionary.hpp"
#include "./container/foldable.hpp"
#include "./container/mappable.hpp"
#include "./container/linear.hpp"

#include "./iterator/iterator.hpp"

#include "./vector/vector.hpp"

#include "./list/list.hpp"

#include "./binarytree/binarytree.hpp"

#include "./bst/bst.hpp"


#include "./hashtable/hashtable.hpp"
#include "./hashtable/clsadr/htclsadr.hpp"
#include "./hashtable/opnadr/htopnadr.hpp"


/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

using namespace std;

int main() {

//binarytree astratto -> binarytree link -> BST -> iterator -> binarytree vec 

/*viene usato in const cast per evitare di riscrivere funzioni che esistono sia
in versione const che non const : const_cast<NodeLnk * *>(static_cast<const BST<data> *>(this)->FindPointerToSuccessor(nod, dat))
qui la funzione non costante richiama la funzione costante castandola a non costante in modo da non riscriverla 
il const cast si puo utilizzare soltanto su algoritmi che di per se non modificano dati.*/

/*
  - riportare tableSize in HashTable.hpp in protected
  - porta tablesize insertsome e insert all di htclsadr in protected
  - porta tablesize insertsome e insert all di htopnadr in protected
*/

  std::cout << "Lasd Libraries 2023" << std::endl;
  uint scelta;
  while(true)
  {
    std::cout<<"\n\n\nQuale test vuoi eseguire? Digita:\n"
                "0. esci\n"
                "1. lasdtest\n"
                "2. myTest\n";
    std::cin>>scelta;
    if(scelta == 0)
      exit(1);
    else if(scelta == 1)
      lasdtest();
    else if(scelta == 2)
      myTest();
  }
  return 0;
}