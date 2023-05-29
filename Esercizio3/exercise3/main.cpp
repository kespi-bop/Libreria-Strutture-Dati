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

  // lasd::Vector<int> a(8);
  // a[0] = 5;
  // a[1] = 1792;
  // a[2] = -123;
  // a[3] = -1;
  // a[4] = -2;
  // a[5] = -4;
  // a[6] = -5;
  // a[7] = -6;
  

  // lasd::HashTableOpnAdr<int> b(1,a);
  // b.Exists(16) ? std::cout<<"ESISTE 16" : std::cout<<"16 NON ESISTE";
  // std::cout<<std::endl;
  // b.Exists(1792) ? std::cout<<"ESISTE 1792" : std::cout<<"1792 NON ESISTE";
  // std::cout<<std::endl;
  // b.Exists(5) ? std::cout<<"ESISTE 5" : std::cout<<"5 NON ESISTE";
  // std::cout<<std::endl;
  // b.Exists(-123) ? std::cout<<"ESISTE -123" : std::cout<<"-123 NON ESISTE";
  // std::cout<<std::endl;
  // b.Exists(-1) ? std::cout<<"ESISTE -1" : std::cout<<"-1 NON ESISTE";
  // std::cout<<std::endl;
  // b.Exists(1) ? std::cout<<"ESISTE 1" : std::cout<<"1 NON ESISTE";
  // std::cout<<std::endl;
  // b.Exists(-2) ? std::cout<<"ESISTE -2" : std::cout<<"-2 NON ESISTE";
  // std::cout<<std::endl;
  // b.Exists(-4) ? std::cout<<"ESISTE -4" : std::cout<<"-4 NON ESISTE";
  // std::cout<<std::endl;
  // b.Exists(-5) ? std::cout<<"ESISTE -5" : std::cout<<"-5 NON ESISTE";
  // std::cout<<std::endl;
  // b.Exists(-6) ? std::cout<<"ESISTE -6" : std::cout<<"-6 NON ESISTE";
  // std::cout<<std::endl;
  // b.Exists(5) ? std::cout<<"ESISTE 5" : std::cout<<"5 NON ESISTE";

  return 0;
}