#ifndef MYTEST_CPP
#define MYTEST_CPP

#include <iostream>
#include <random>

#define DimensioneContainer 10

using namespace std;

default_random_engine gen(random_device{}());
uniform_int_distribution<int> RandomNumber(0, 100);

#include "test.hpp"

/* ************************************************************************** */

void myTest(){
  int scelta;
  cout<<"\n\n\nQuale test vuoi eseguire? \n";
  cout<<"Esercizio1 : (premi 1) \n";
  cout<<"Esercizio2 : (premi 2) \n";
  cout<<"Esercizio3 : (premi 3) \n";
  cin>>scelta;

  if(scelta == 1) TestEsercizio1();
  else if(scelta == 2) TestEsercizio2();
  else if(scelta == 3) TestEsercizio3();
}

bool TestCostruttori()
{
    bool TestCostruttoriErrori = true;

    cout<<"\n\n***************TEST DEI COSTRUTTORI: \n";
    
    cout<<"\nTestCostruttore Vec->QueueVec(Copy): ";
    lasd::Vector<int> vc1(DimensioneContainer);
    for(uint i = 0; i < DimensioneContainer; i++) {
      vc1[i] = i;
    }
    lasd::QueueVec<int> qv1(vc1);
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vc1[i] != qv1.HeadNDequeue()) {
          cout<<"ERRORE!";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }
    
    cout<<"\nTestCostruttore Vec->QueueVec(Move): ";
    lasd::QueueVec<int> qv2(move(vc1));
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vc1[i] != qv2.HeadNDequeue()) {
        cout<<"ERRORE!\n";
        TestCostruttoriErrori &= false;
        break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }


    cout<<"\nTestCostruttore QueueVec->QueueVec(copy): ";
    lasd::QueueVec<int> qv3;
    for(uint i = 0; i < DimensioneContainer; i ++) {
      qv3.Enqueue(i);
    }
    lasd::QueueVec<int> qv4(qv3);
    if(qv4 == qv3) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestCostruttoriErrori &= false;
    }
  
    cout<<"\nTestCostruttore QueueVec->QueueVec(move): ";
    lasd::QueueVec<int> qv5(move(qv4));
    if(qv4.Empty()) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestCostruttoriErrori &= false;
    }


    cout<<"\nTestCostruttore List->QueueVec(Copy): ";
    lasd::List<int> lst1;
    for(uint i = 0; i < DimensioneContainer; i++) {
      lst1.Insert(i);
    }
    lasd::QueueVec<int> qv6(lst1);
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(lst1[i] != qv6.HeadNDequeue()) {
          cout<<"ERRORE!";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }
    
    cout<<"\nTestCostruttore List->QueueVec(Move): ";
    lasd::QueueVec<int> qv7(move(lst1));
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(lst1[i] != qv7.HeadNDequeue()) {
        cout<<"ERRORE!\n";
        TestCostruttoriErrori &= false;
        break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }


    cout<<"\nTestCostruttore Vec->StackVec(Copy): ";
    lasd::Vector<int> vc2(DimensioneContainer);
    for(uint i = 0; i < DimensioneContainer; i++) {
      vc2[i] = i;
    }
    lasd::StackVec<int> stk1(vc2);
    for(int i = DimensioneContainer - 1; i >= 0; i--) {
      if(vc2[i] != stk1.TopNPop()) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == 0) {
        cout<<"CORRETTO!\n";
      }
    }
    
    cout<<"\nTestCostruttore Vec->StackVec(Move): ";
    lasd::StackVec<int> stk2(move(vc2));
    for(int i = DimensioneContainer - 1; i >= 0; i--) {
      if(vc2[i] != stk2.TopNPop()) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }
    

    cout<<"\nTestCostruttore StackVec->StackVec(copy): ";
    lasd::StackVec<int> stk3;
    for(uint i = 0; i < DimensioneContainer; i ++) {
      stk3.Push(i);
    }
    lasd::StackVec<int> stk4(stk3);
    if(stk4 == stk3) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestCostruttoriErrori &= false;
    }
    
    cout<<"\nTestCostruttore StackVec->StackVec(move): ";
    lasd::StackVec<int> stk5(move(stk4));
    if(stk4.Empty()) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestCostruttoriErrori &= false;
    }

    
    cout<<"\nTestCostruttore List->StackVec(Copy): ";
    lasd::List<int> lst2;
    for(uint i = 0; i < DimensioneContainer; i++) {
      lst2.Insert(i);
    }
    lasd::StackVec<int> stk6(lst2);
    for(int i = DimensioneContainer - 1; i >= 0; i--) {
      if(lst2[i] != stk6.TopNPop()) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }
    
    cout<<"\nTestCostruttore List->StackVec(Move): ";
    lasd::StackVec<int> stk7(move(lst2));
    for(int i = DimensioneContainer - 1; i >= 0; i--) {
      if(lst2[i] != stk7.TopNPop()) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }


    cout<<"\nTestCostruttore List->QueueLst(copy): ";
    lasd::QueueLst<int> qlst1(lst2);
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(lst2[i] != qlst1.HeadNDequeue()) {
        cout<<"ERRORE!\n";
        TestCostruttoriErrori &= false;
        break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }

    cout<<"\nTestCostruttore List->QueueLst(move): ";
    lasd::QueueLst<int> qlst2(move(lst2));
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(lst2[i] != qlst2.HeadNDequeue()) {
        cout<<"ERRORE!\n";
        TestCostruttoriErrori &= false;
        break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }

    cout<<"\nTestCostruttore QueueLst->QueueLst(copy): ";
    lasd::QueueLst<int> qlst3;
    for(int i = 0; i < DimensioneContainer; i++) {
      qlst3.Enqueue(i);
    }
    lasd::QueueLst<int> qlst4(qlst3);
    if(qlst3 == qlst4) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestCostruttoriErrori &= false;
    }

    cout<<"\nTestCostruttore QueueLst->QueueLst(move): ";
    lasd::QueueLst<int> qlst5(move(qlst4));
    if(qlst4.Empty()) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestCostruttoriErrori &= false;
    }

    cout<<"\nTestCostruttore Vec->QueueLst(copy): ";
    lasd::QueueLst<int> qlst6(vc2);
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vc2[i] != qlst6.HeadNDequeue()) {
        cout<<"ERRORE!\n";
        TestCostruttoriErrori &= false;
        break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
        TestCostruttoriErrori |= false;
      }
    }

    cout<<"\nTestCostruttore Vec->QueueLst(move): ";
    lasd::QueueLst<int> qlst7(move(vc2));
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vc2[i] != qlst7.HeadNDequeue()) {
        cout<<"ERRORE!\n";
        TestCostruttoriErrori &= false;
        break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
        TestCostruttoriErrori |= false;
      }
    }

    cout<<"\nTestCostruttore List->StackLst(copy): ";
    lasd::StackLst<int> stclst1(lst2);    
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(lst2[i] != stclst1.TopNPop()) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }


    cout<<"\nTestCostruttore List->StackLst(move): ";
    lasd::StackLst<int> stclst2(move(lst2));    
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(lst2[i] != stclst2.TopNPop()) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }

    cout<<"\nTestCostruttore StackLst->StackLst(copy): ";
    lasd::StackLst<int> stclst3(stclst2);    
    if(stclst2 == stclst3) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestCostruttoriErrori &= false;
    }

    cout<<"\nTestCostruttore StackLst->StackLst(move): ";
    lasd::StackLst<int> stclst4(move(stclst3));    
    if(stclst3.Empty()) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestCostruttoriErrori &= false;
    }

    cout<<"\nTestCostruttore Vec->StackLst(copy): ";
    lasd::StackLst<int> stclst5(vc2);    
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vc2[i] != stclst5.TopNPop()) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }

    cout<<"\nTestCostruttore Vec->StackLst(move): ";
    lasd::StackLst<int> stclst6(move(vc2));    
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vc2[i] != stclst6.TopNPop()) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }
    
    cout<<"\nTestCostruttore Vec->List(copy): ";
    lasd::List<int> list1(vc2);    
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vc2[i] != list1[i]) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }

    cout<<"\nTestCostruttore Vec->List(move): ";
    lasd::List<int> list2(move(vc2));    
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vc2[i] != list2[i]) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }

    cout<<"\nTestCostruttore List->Vec(copy): ";
    lasd::Vector<int> vector1(list1);    
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vector1[i] != list1[i]) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }

    cout<<"\nTestCostruttore List->Vec(move): ";
    lasd::Vector<int> vector2(move(list1));    
    for(uint i = 0; i < DimensioneContainer; i++) {
      if(vector2[i] != list1[i]) {
          cout<<"ERRORE!\n";
          TestCostruttoriErrori &= false;
          break;
      }
      if(i == DimensioneContainer - 1) {
        cout<<"CORRETTO!\n";
      }
    }

    return TestCostruttoriErrori;
}

bool TestAssegnazioni()
{
    bool TestAssergnazioniErrori = true;

    cout<<"\n\n***************TEST DELLE ASSEGNAZIONI: \n";

    cout<<"\nTestAssegnazione QueueVec->QueueVec(copy): ";
    lasd::QueueVec<int> qvc1;
    for(uint i = 0; i < DimensioneContainer; i++) {
      qvc1.Enqueue(i);
    }
    lasd::QueueVec<int> qvc2;
    qvc2 = qvc1;
    if(qvc1 == qvc2) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestAssergnazioniErrori &= false;
    }

    cout<<"\nTestAssegnazione QueueVec->QueueVec(move): ";
    lasd::QueueVec<int> qvc3;
    qvc3 = move(qvc2);
    if(qvc3 == qvc1 && qvc2.Empty()) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestAssergnazioniErrori &= false;
    }

    cout<<"\nTestAssegnazione StackVec->StackVec(copy): ";
    lasd::StackVec<int> stck1;
    for(uint i = 0; i < DimensioneContainer; i++) {
      stck1.Push(i);
    }
    lasd::StackVec<int> stck2;
    stck2 = stck1;
    if(stck1 == stck2) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestAssergnazioniErrori &= false;
    }

    cout<<"\nTestAssegnazione StackVec->StackVec(move): ";
    lasd::StackVec<int> stck3;
    stck3 = move(stck2);
    if(stck3 == stck1 && stck2.Empty()) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestAssergnazioniErrori &= false;
    }

    cout<<"\nTestAssegnazione QueueLst->QueueLst(copy): ";
    lasd::QueueLst<int> qlst1;
    for(uint i = 0; i < DimensioneContainer; i++) {
      qlst1.Enqueue(i);
    }
    lasd::QueueLst<int> qlst2;
    qlst2 = qlst1;
    if(qlst1 == qlst2) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestAssergnazioniErrori &= false;
    }

    cout<<"\nTestAssegnazione QueueVec->QueueVec(move): ";
    lasd::QueueLst<int> qlst3;
    qlst3 = move(qlst2);
    if(qlst3 == qlst1 && qlst2.Empty()) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestAssergnazioniErrori &= false;
    }


    cout<<"\nTestAssegnazione StackLst->StackLst(copy): ";
    lasd::StackLst<int> stcklst1;
    for(uint i = 0; i < DimensioneContainer; i++) {
      stcklst1.Push(i);
    }
    lasd::StackLst<int> stcklst2;
    stcklst2 = stcklst1;
    if(stcklst1 == stcklst2) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestAssergnazioniErrori &= false;
    }

    cout<<"\nTestAssegnazione StackLst->StackLst(move): ";
    lasd::StackLst<int> stcklst3;
    stcklst3 = move(stcklst2);
    if(stcklst3 == stcklst1 && stcklst2.Empty()) {
      cout<<"CORRETTO!\n";
    } else {
      cout<<"ERRORE!\n";
      TestAssergnazioniErrori &= false;
    }

    return TestAssergnazioniErrori;
}

bool TestDictionaryFunctions()
{ 
  bool TestDictionaryErrori = true;

  cout<<"\n\n***************TEST DELLE FUNZIONI DEI DICTIONARY: \n";

  lasd::Vector<int> v1(3);
  v1[0]=1; v1[1]=2; v1[2]=3;

  lasd::Vector<int> v2(3);
  v2[0]=6; v2[1]=7; v2[2]=8;

  lasd::List<int> l1;
  l1.InsertAtBack(3); l1.InsertAtBack(4); l1.InsertAtBack(5);

  cout<<"\nTestDictionary InsertAll(copy): ";
  bool test1 = l1.InsertAll(v1);
  bool test2 = l1.InsertAll(v2);
  if(test1 || !(test2)) {
    cout<<"ERRORE!\n";
    TestDictionaryErrori &= false;
  } else {
    cout<<"CORRETTO!\n";
  }

  cout<<"\nTestDictionary InsertAll(move): ";
  lasd::List<int> l2;
  l2.InsertAtBack(3); l2.InsertAtBack(4); l2.InsertAtBack(5);
  test1 = l2.InsertAll(move(v1));
  test2 = l2.InsertAll(move(v2));
  if(test1 || !(test2)) {
    cout<<"ERRORE!\n";
    TestDictionaryErrori &= false;
  } else {
    cout<<"CORRETTO!\n";
  }

  lasd::Vector<int> v3(3);
  v3[0]=1; v3[1]=2; v3[2]=3;

  lasd::Vector<int> v4(3);
  v4[0]=3; v4[1]=4; v4[2]=5;

  cout<<"\nTestDictionary InsertSome(copy): ";
  lasd::List<int> l3;
  l3.InsertAtBack(3); l3.InsertAtBack(4); l3.InsertAtBack(5);
  bool test3 = l3.InsertSome(v3);
  bool test4 = l3.InsertSome(v4);
  if(!(test3) || test4) {
    cout<<"ERRORE!\n";
    TestDictionaryErrori &= false;
  } else {
    cout<<"CORRETTO!\n";
  }

  cout<<"\nTestDictionary InsertSome(move): ";
  lasd::List<int> l4;
  l4.InsertAtBack(3); l4.InsertAtBack(4); l4.InsertAtBack(5);
  test3 = l4.InsertSome(move(v3));
  test4 = l4.InsertSome(move(v4));
  if(!(test3) || test4) {
    cout<<"ERRORE!\n";
    TestDictionaryErrori &= false;
  } else {
    cout<<"CORRETTO!\n";
  }

  lasd::Vector<int> v5(3);
  v5[0]=1; v5[1]=2; v5[2]=3;

  lasd::Vector<int> v6(3);
  v6[0]=4; v6[1]=5; v6[2]=6;

  cout<<"\nTestDictionary RemoveAll: ";
  lasd::List<int> l5;
  l5.InsertAtBack(3); l5.InsertAtBack(4); l5.InsertAtBack(5);
  l5.InsertAtBack(6); l5.InsertAtBack(7);
  bool test5 = l5.RemoveAll(v5);
  bool test6 = l5.RemoveAll(v6);
  if(test5 || !(test6)) {
    cout<<"ERRORE!\n";
    TestDictionaryErrori &= false;
  } else {
    cout<<"CORRETTO!\n";
  }


  cout<<"\nTestDictionary RemoveSome: ";
  lasd::Vector<int> v7(3);
  v7[0]=1; v7[1]=2; v7[2]=3;

  lasd::Vector<int> v8(3);
  v8[0]=6; v8[1]=7; v8[2]=8;

  lasd::List<int> l6;
  l6.InsertAtBack(3); l6.InsertAtBack(4); l6.InsertAtBack(5);
  bool test7=l6.RemoveSome(v7);
  bool test8=l6.RemoveSome(v8);
  if(!(test7) || test8) {
    cout<<"ERRORE!\n";
    TestDictionaryErrori &= false;
  } else {
    cout<<"CORRETTO!\n";
  }

  return TestDictionaryErrori;
}

bool TestSort()
{
  cout<<"\n\n***************TEST DI SORTING: \n";

  cout<<"\nTestSort SortingInt: ";
  bool TestSortInt = true;
  lasd::Vector<int> v1(DimensioneContainer);
  for(int i = 0; i < v1.Size(); i++){
    v1[i] = RandomNumber(gen);
  }
  v1.Sort();
  for(int i = 1; i < v1.Size(); i++){
    TestSortInt &= (v1[i-1] <= v1[i]);
  }
  if(TestSortInt) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
  }



  cout<<"\nTestSort SortingEmptyVector(borderline case): ";
  bool TestSortEmpty = true;
  lasd::Vector<int> v2(0);
  v2.Sort();
  for(int i = 1; i<v2.Size(); i++) {
    TestSortEmpty &= (v2[i-1]<=v2[i]);
  } 
  if(TestSortEmpty) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
  }
    

  return (TestSortInt && TestSortEmpty);
}

bool TestQueueVec()
{
  bool TestQueueVec = true;
  cout<<"\n***************TEST DI QUEUEVEC: \n";
  cout<<"\nTestSort QueueVec: \n";
  lasd::QueueVec<int> queue;

  queue.Enqueue(5);
  cout<<"Testa '"<<queue.Head()<<"': ";
  int value = queue.HeadNDequeue();
  if(value == 5) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  queue.Enqueue(1);
  queue.Enqueue(3);
  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 1) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  queue.Enqueue(2);
  queue.Enqueue(4);
  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 3) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  queue.Enqueue(1);
  queue.Enqueue(7);
  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 2) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  queue.Enqueue(2);
  queue.Enqueue(2);
  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 4) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  queue.Enqueue(6);
  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 1) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  queue.Enqueue(8);
  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 7) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  queue.Enqueue(1);
  queue.Enqueue(4);

  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 2) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 2) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 6) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  cout<<"Testa '"<<queue.Head()<<"': ";
  value = queue.HeadNDequeue();
  if(value == 8) {
    cout<<"CORRETTO!\n";
  } else {
    cout<<"ERRORE!\n";
    TestQueueVec = false;
  }

  return TestQueueVec;
}

bool TestIteratori() {
  bool testIteratori = true;
  int lines = 1;
  cout<<"\n\nBegin of (BST into) Iterator Test: "<<endl;

  lasd::BinaryTreeLnk<int> btlnk;
  lasd::BTInOrderIterator<int> inOrderBSTlnk(btlnk);
  if(inOrderBSTlnk.Terminated()) {
    cout<<lines++<<" Iterator is terminated: Correct!"<<endl;
  } else {
    cout<<lines++<<"Iterator is not terminated: Error!"<<endl;
    testIteratori &= false;
  }
  lasd::BTInOrderIterator<int> inOrderBSTmovelnk(std::move(btlnk));
  if(inOrderBSTmovelnk.Terminated()) {
    cout<<lines++<<" Iterator is terminated: Correct!"<<endl;
  } else {
    cout<<lines++<<" Iterator is not terminated: Error!"<<endl;
    testIteratori &= false;
  }

  lasd::BinaryTreeVec<int> btvec;
  lasd::BTInOrderIterator<int> inOrderBSTvec(btvec);
  if(inOrderBSTvec.Terminated()) {
    cout<<lines++<<" Iterator is terminated: Correct!"<<endl;
  } else {
    cout<<lines++<<"Iterator is not terminated: Error!"<<endl;
    testIteratori &= false;
  }
  lasd::BTInOrderIterator<int> inOrderBSTmovevec(std::move(btvec));
  if(inOrderBSTmovevec.Terminated()) {
    cout<<lines++<<" Iterator is terminated: Correct!"<<endl;
  } else {
    cout<<lines++<<" Iterator is not terminated: Error!"<<endl;
    testIteratori &= false;
  }

  lasd::List<int> lst;
  for(int i=0; i<6; i++) {
        lst.InsertAtBack(i);
  }

  lasd::BinaryTreeLnk<int> btLnk(lst);

  cout<<"MAP:"<<endl;
  cout<<"Expected: 0->1->3->4->2->5->"<<endl;
  cout<<"Map ottenuta: ";
  btLnk.Map(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  cout<<endl;

  cout<<"PRE_ORDER_MAP:"<<endl;
  cout<<"Expected: 0->1->3->4->2->5->"<<endl;
  cout<<"PreOrderMap: ";
  btLnk.PreOrderMap(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  lasd::BTPreOrderIterator<int> itrPre(btLnk);
  cout<<"\nPreOrderIterator: ";
  while(!(itrPre.Terminated())){
    cout<<*itrPre<<"->";
    ++itrPre;
  }
  cout<<endl;

  cout<<"POST_ORDER_MAP:"<<endl;
  cout<<"Expected: 3->4->1->5->2->0->"<<endl;
  cout<<"PostOrderMap: ";
  btLnk.PostOrderMap(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  lasd::BTPostOrderIterator<int> itrPost(btLnk);
  cout<<"\nPostOrderIterator: ";
  while(!(itrPost.Terminated())){
    cout<<*itrPost<<"->";
    ++itrPost;
  }
  cout<<endl;

  cout<<"IN_ORDER_MAP:"<<endl;
  cout<<"Expected: 3->1->4->0->5->2->"<<endl;
  cout<<"InOrderMap: ";
  btLnk.InOrderMap(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  lasd::BTInOrderIterator<int> itrIn(btLnk);
  cout<<"\nInOrderIterator: ";
  while(!(itrIn.Terminated())){
    cout<<*itrIn<<"->";
    ++itrIn;
  }
  cout<<endl;

  cout<<"BREADTH_ORDER_MAP:"<<endl;
  cout<<"Expected: 0->1->2->3->4->5->"<<endl;
  cout<<"BreadthMap: ";
  btLnk.BreadthMap(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  lasd::BTBreadthIterator<int> itrBreadth(btLnk);
  cout<<"\nBreadthOrderIterator: ";
  while(!(itrBreadth.Terminated())){
    cout<<*itrBreadth<<"->";
    ++itrBreadth;
  }
  cout<<endl;

  lasd::Vector<int> vec(RandomNumber(gen) + 1);
  for(int i = 0; i < vec.Size(); i++) {
    vec[i] = RandomNumber(gen);
  }
  vec.Sort();
  lasd::BinaryTreeVec<int> btvec1(vec);
  lasd::BTBreadthIterator<int> breadthIterVec(btvec1);
  int next = 0;
  while(!breadthIterVec.Terminated()){
    int previous = *breadthIterVec;
    if(!(++breadthIterVec).Terminated()){
      next = *breadthIterVec;
    }
    if(previous <= next) {
      testIteratori &= true;
    } else {
      testIteratori &= false;
      cout<<lines++<<" BTBredthIterator NON costruito correttamente da BTVec: Error!"<<endl;
      break;
    }
  }
  if(testIteratori == true) {
    cout<<lines++<<" BTBredthIterator costruito correttamente da BTVec: Correct!"<<endl;    
  }
  breadthIterVec.Reset();
  if(*breadthIterVec == vec[0]) {
    cout<<lines++<<" L'iteratore è stato resettato correttamente: Correct!"<<endl;
  } else {
    cout<<lines++<<" L'iteratore NON è stato resettato correttamente: Error!"<<endl;
    testIteratori &= false;
  }
  lasd::BinaryTreeLnk<int> btlnk1;
  lasd::BTInOrderIterator<int> postOrderBSTlnk(btlnk1);
  if(postOrderBSTlnk.Terminated()) {
    cout<<lines++<<" Iterator is terminated: Correct!"<<endl;
  } else {
    cout<<lines++<<"Iterator is not terminated: Error!"<<endl;
    testIteratori &= false;
  }
  lasd::BTInOrderIterator<int> postOrderBSTmovelnk(std::move(btlnk));
  if(postOrderBSTlnk.Terminated()) {
    cout<<lines++<<" Iterator is terminated: Correct!"<<endl;
  } else {
    cout<<lines++<<" Iterator is not terminated: Error!"<<endl;
    testIteratori &= false;
  }

  return testIteratori;
}

bool TestBTVec()
{
  bool testBTVec = true;
  int lines = 1;
  cout<<"\n\nBegin of BTVec Test: "<<endl;
  lasd::List<int>lst;
  for(int i = 0; i < RandomNumber(gen) + 1; i++){
    lst.Insert(RandomNumber(gen));
  }
  lasd::BinaryTreeVec<int>btvec1(lst);
  lasd::BinaryTreeVec<int>btvec2(std::move(lst));
  if(btvec1 == btvec2) {
    cout<<lines++<<" Two BtVec are equals: Correct!"<<endl;
  } else {
    cout<<lines++<<" Two BtVec are NOT equals: Error!"<<endl;
    testBTVec &= false;   
  }
  btvec2.Clear();
  btvec1 = btvec2;
  if(btvec1.Empty()) {
    cout<<lines++<<" BTVec1 is now Empty: Correct!"<<endl;
  } else {
    cout<<lines++<<" BTVec1 is NOT Empty: Error!"<<endl;
    testBTVec &= false;   
  }
  if(btvec1 == btvec2) {
    cout<<lines++<<" Two BtVec are equals: Correct!"<<endl;
  } else {
    cout<<lines++<<" Two BtVec are NOT equals: Error!"<<endl;
    testBTVec &= false;   
  }
  lasd::List<double> vec;
  lasd::BinaryTreeVec<double> btvec3;
  btvec3 = std::move(vec);
  try{
    btvec3.Root();
  } catch (std::length_error) {
    cout<<lines++<<" leng_error called BTVec is Empty, doesn't have root: Correct!"<<endl; 
  } catch (std::exception) {
    cout<<lines++<<" Wrong exception called: Error!"<<endl; 
    testBTVec &= false;     
  }
  lasd::Vector<double> vec1(RandomNumber(gen) + 1);
  for(int i = 0; i < vec1.Size() - 1; i++){
    vec1[i] = RandomNumber(gen);
  }
  //creo una ripetizione
  vec1[0]++;
  vec1[vec1.Size() - 1] = vec1[0];
  lasd::BinaryTreeLnk<double> btlnk1(vec1);
  lasd::BinaryTreeVec<double> btvec4(btlnk1);
  double accumulator1 = 0;
  cout<<" Printing new BTLnk :";
  btlnk1.Map(
    [&accumulator1](double dat){
      cout<<dat<<"->";
      accumulator1 += dat;
    }
  );
  cout<<"\n BTLnk's all value sum is: "<<accumulator1<<endl;

  double accumulator2 = 0;
  cout<<" Printing new BTVec :";
  btvec4.Map(
    [&accumulator2](double dat){
      cout<<dat<<"->";
      accumulator2 += dat;
    }
  );
  cout<<"\n BTVec(BTLnk)'s all value sum is: "<<accumulator2<<endl;
  if(accumulator1 == accumulator2) {
    cout<<lines++<<" BTVec & BTLnk are equals: Correct!"<<endl;    
  } else {
    cout<<lines++<<" BTVec & BTLnk are NOT equals: Error!"<<endl;   
    testBTVec &= false;     
  }

  lasd::BST<double> BST1(btvec4);
  double accumulator3 = 0;
  cout<<" Printing new BST :";
  BST1.Map(
    [&accumulator3](double dat){
      cout<<dat<<"->";
      accumulator3 += dat;
    }
  );
  cout<<"\n BST's all value sum is: "<<accumulator3<<endl;
  if(accumulator2 != accumulator3) {
    cout<<lines++<<" BST & (BTLnk & BTVec) are NOT equals: Correct!"<<endl;    
  } else {
    cout<<lines++<<" BST & (BTLnk & BTVec) are equals: Error!"<<endl;
    testBTVec &= false;           
  }

  lasd::Vector<int> vec3(RandomNumber(gen) + 1);
  for(int i = 0; i < vec3.Size(); i++){
    vec3[i] = RandomNumber(gen);
  }
  lasd::Vector<int> vec4(vec3);
  lasd::BinaryTreeLnk<int> btlnk5(std::move(vec3));
  lasd::BinaryTreeVec<int> btvec5(std::move(vec4));
  if(btlnk5.lasd::BinaryTree<int>::operator==(btvec5)){
    cout<<lines++<<" btlnk and bvec(move assignament from the same vector) are equals: Correct!"<<endl;    
  } else {
    cout<<lines++<<" btlnk and bvec(move assignament from the same vector) are NOT equals: Error!"<<endl;       
  }
  lasd::BinaryTreeLnk<int> btlnk6(std::move(btlnk5));
  lasd::BinaryTreeVec<int> btvec6(std::move(btvec5));  
  if(btlnk6.lasd::BinaryTree<int>::operator==(btvec6)){
    cout<<lines++<<" btlnk(from move(btvec)) and btvec are equals: Correct!"<<endl;    
  } else {
    cout<<lines++<<" btlnk(from move(btvec)) and btvec are NOT equals: Error!"<<endl;       
  }

  lasd::List<int>lista;
  lista.Insert(RandomNumber(gen));
  lista.Insert(RandomNumber(gen));

  lasd::BinaryTreeVec<int>btvec7(std::move(lista));
  lasd::List<int>list(btvec7);
  for(int i=0; i< list.Size();i++) {
    cout<<lines++<<" extracted value from List(BTLnk): "<<list[i]<<" Correct!"<<endl;
  }

  lasd::List<int> list1;
  for(int i = 0; i < (RandomNumber(gen)%10) + 5; i++) {
    list1.Insert(RandomNumber(gen));
  }
  cout<<lines++<<" MAP LISTA:"; 
  list1.Map(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  lasd::BinaryTreeVec<int> bintvec(list1);
  cout<<"\n"<<lines++<<" MAP:";
  bintvec.Map(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" PREORDERMAP:"; 
  bintvec.PreOrderMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" POSTORDERMAP:"; 
  bintvec.PostOrderMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" INORDERMAP:"; 
  bintvec.InOrderMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" BREADTHORDERMAP:"; 
  bintvec.BreadthMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );


  return testBTVec;
}

bool TestBTLnk()
{
  bool testBTLnk= true;
  int lines = 1;
  cout<<"\n\nBegin of BTLnk Test: "<<endl;
  lasd::List<int>lst;
  for(int i = 0; i < RandomNumber(gen) + 1; i++){
    lst.Insert(RandomNumber(gen));
  }
  lasd::BinaryTreeLnk<int>btlnk1(lst);
  lasd::BinaryTreeLnk<int>btlnk2(std::move(lst));
  if(btlnk1 == btlnk2) {
    cout<<lines++<<" Two BtLnk are equals: Correct!"<<endl;
  } else {
    cout<<lines++<<" Two BtLnk are NOT equals: Error!"<<endl;
    testBTLnk &= false;   
  }
  btlnk2.Clear();
  btlnk1 = btlnk2;
  if(btlnk1.Empty()) {
    cout<<lines++<<" BtLnk1 is now Empty: Correct!"<<endl;
  } else {
    cout<<lines++<<" BtLnk1 is NOT Empty: Error!"<<endl;
    testBTLnk &= false;   
  }
  if(btlnk1 == btlnk2) {
    cout<<lines++<<" Two BtLnk are equals: Correct!"<<endl;
  } else {
    cout<<lines++<<" Two BtLnk are NOT equals: Error!"<<endl;
    testBTLnk &= false;   
  }
  lasd::List<double> vec;
  lasd::BinaryTreeLnk<double> btlnk3;
  btlnk3 = vec;
  try{
    btlnk3.Root();
  } catch (std::length_error) {
    cout<<lines++<<" leng_error called BTLnk is Empty, doesn't have root: Correct!"<<endl; 
  } catch (std::exception) {
    cout<<lines++<<" Wrong exception called: Error!"<<endl; 
    testBTLnk &= false;     
  }
  lasd::Vector<double> vec1(RandomNumber(gen) + 1);
  for(int i = 0; i < vec1.Size() - 1; i++){
    vec1[i] = RandomNumber(gen);
  }
  //creo una ripetizione
  vec1[0]++;
  vec1[vec1.Size() - 1] = vec1[0];
  lasd::BinaryTreeLnk<double> btlnk4(std::move(vec1));
  lasd::BinaryTreeVec<double> btvec1(btlnk4);
  double accumulator1 = 0;
  cout<<" Printing new BTLnk :";
  btlnk4.Map(
    [&accumulator1](double dat){
      cout<<dat<<"->";
      accumulator1 += dat;
    }
  );
  cout<<"\n BTLnk's all value sum is: "<<accumulator1<<endl;

  double accumulator2 = 0;
  cout<<" Printing new BTVec :";
  btvec1.Map(
    [&accumulator2](double dat){
      cout<<dat<<"->";
      accumulator2 += dat;
    }
  );
  cout<<"\n BTVec(BTLnk)'s all value sum is: "<<accumulator2<<endl;
  if(accumulator1 == accumulator2) {
    cout<<lines++<<" BTVec & BTLnk are equals: Correct!"<<endl;    
  } else {
    cout<<lines++<<" BTVec & BTLnk are NOT equals: Error!"<<endl;   
    testBTLnk &= false;     
  }

  lasd::BST<double> BST1(std::move(btlnk4));
  double accumulator3 = 0;
  cout<<" Printing new BST :";
  BST1.Map(
    [&accumulator3](double dat){
      cout<<dat<<"->";
      accumulator3 += dat;
    }
  );
  cout<<"\n BST's all value sum is: "<<accumulator3<<endl;
  if(accumulator2 != accumulator3) {
    cout<<lines++<<" BST & (BTLnk & BTVec) are NOT equals: Correct!"<<endl;    
  } else {
    cout<<lines++<<" BST & (BTLnk & BTVec) are equals: Error!"<<endl;
    testBTLnk &= false;           
  }

  lasd::Vector<int> vec3(RandomNumber(gen) + 1);
  for(int i = 0; i < vec3.Size(); i++){
    vec3[i] = RandomNumber(gen);
  }
  lasd::BinaryTreeLnk<int> btlnk5(vec3);
  lasd::BinaryTreeVec<int> btvec2(vec3);
  lasd::BinaryTreeLnk<int> btlnk6(btlnk5);
  lasd::BinaryTreeVec<int> btvec3(btvec2);  
  if(btlnk5.lasd::BinaryTree<int>::operator==(btvec2)){
    cout<<lines++<<" btlnk and bvec(copy assignament from the same vector) are equals: Correct!"<<endl;    
  } else {
    cout<<lines++<<" btlnk and bvec(copy assignament from the same vector) are NOT equals: Error!"<<endl;       
  }
  if(btlnk6.lasd::BinaryTree<int>::operator==(btvec3)){
    cout<<lines++<<" btlnk(from btvec) and btvec are equals: Correct!"<<endl;    
  } else {
    cout<<lines++<<" btlnk(from btvec) and btvec are NOT equals: Error!"<<endl;       
  }

  lasd::Vector<int>vector(2);
  vector[0] = RandomNumber(gen);
  vector[1] = RandomNumber(gen);
  lasd::BinaryTreeLnk<int>btlnk7(std::move(vector));
  lasd::List<int>lista(btlnk7);
  for(int i=0; i< lista.Size();i++) {
    cout<<lines++<<" extracted value from List(BTLnk): "<<lista[i]<<" Correct!"<<endl;
  }
  lasd::Vector<int>vettore(std::move(btlnk7));
  for(int i=0; i< vettore.Size();i++) {
    cout<<lines++<<" extracted value from Vector(BTLnk): "<<vettore[i]<<" Correct!"<<endl;
  }

  lasd::Vector<int> vettore1((RandomNumber(gen)%10) + 5);
  for(int i = 0; i < vettore1.Size(); i++) {
    vettore1[i] = RandomNumber(gen);
  }
  cout<<lines++<<" MAP VETTORE:"; 
  vettore1.Map(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  lasd::BinaryTreeLnk<int> bintrelnk(std::move(vettore1));
  cout<<"\n"<<lines++<<" MAP:";
  bintrelnk.Map(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" PREORDERMAP:"; 
  bintrelnk.PreOrderMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" POSTORDERMAP:"; 
  bintrelnk.PostOrderMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" INORDERMAP:"; 
  bintrelnk.InOrderMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" BREADTHORDERMAP:"; 
  bintrelnk.BreadthMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );

  return testBTLnk;
}

bool TestBST()
{
  bool testBST = true;
  int lines = 1;
  cout<<"\n\nBegin of BST Test: "<<endl;

  lasd::Vector<int> vec1;
  lasd::BST<int> bst1(vec1);
  bst1.Insert(1);
  if(bst1.Max() == 1) {
    cout<<lines++<<" Max is (obtained Max)'"<<bst1.Max()<<"': Correct!"<<endl;
  } else {
    cout<<lines++<<" Max is (obtained Min)'"<<bst1.Max()<<": Error!"<<endl;
    testBST &= false;
  }

  lasd::Vector<int> vec2(RandomNumber(gen) + 1);
  for(int i = 0; i < vec2.Size(); i ++) {
    vec2[i] = RandomNumber(gen);
  }
  bst1.Clear();
  bst1.InsertAll(vec2);
  int ExstactedValue = bst1.MaxNRemove();
  while(!bst1.Empty()) {
    if(bst1.Max() > ExstactedValue) {
      break;
      cout<<lines++<<" Previous ExtractedMax '"<<ExstactedValue<<"' > Actual ExtractedMax '"<<bst1.Max()<<"': Error!"<<endl;
      testBST &= false;
    } else {
      cout<<lines++<<" Previous ExtractedMax '"<<ExstactedValue<<"' < Actual ExtractedMax '"<<bst1.Max()<<"': Correct!"<<endl;
    }  
    ExstactedValue = bst1.MaxNRemove();
  }

  lasd::BST<int> bst2;
  if(bst1 == bst2) {
    cout<<lines++<<" Two empty BST are equal: Correct!"<<endl;
  } else {
    cout<<lines++<<" Two empty BST are NOT equal: Error!"<<endl;
    testBST &= false;
  }

  lasd::BST<int> bst3(vec2);
  bst1 = bst3;
  if(bst1 == bst3) {
    cout<<lines++<<" BST and its BST copy assignament are equal: Correct!"<<endl;  
  } else {
    cout<<lines++<<" BST and its BST copy assignament are NOT equal: Error!"<<endl;
    testBST&= false;
  }
  bst2 = std::move(bst3);
  if(bst2 != bst3) {
    cout<<lines++<<" BST and its BST move assignament are NOT equal: Correct!"<<endl;
  } else {
    cout<<lines++<<" BST and its BST move assignament are equal: Erroe!"<<endl;
    testBST &= false;
  }
  if(bst3.Empty()) {
    cout<<lines++<<" Moved BST is now Empty: Correct!"<<endl;
  } else {
    cout<<lines++<<" Moved BST is NOT Empty: Error!"<<endl;
    testBST &= false;
  }
  if(bst1 == bst2) {
    cout<<lines++<<" BST1 and BST2 are equal: Correct!"<<endl;
  } else {
    cout<<lines++<<" BST1 and BST2 are equal: Error!"<<endl;
    testBST &= false;
  }

  lasd::List<std::string> lst1;
  lst1.Insert("a");
  for(int i = 0; i < 3; i++) {
    lst1.InsertAtFront("a" + lst1.Front());
  }
  lasd::BST<std::string> bst4(std::move(lst1));
  if(bst4.Min().length() < bst4.Max().length()){
    cout<<lines++<<" Lenght min '"<<bst4.Min()<<"' < lenght max '"<<bst4.Max()<<"': Correct!"<<endl;
  } else {
    cout<<lines++<<" Lenght min '"<<bst4.Min()<<"' > lenght max '"<<bst4.Max()<<"': Error!"<<endl;
    testBST &= false;
  }
  if(bst4.Predecessor("aa") == "a") {
    cout<<lines++<<" 'aa' predecessor is '"<<bst4.Predecessor("aa")<<"': Correct!"<<endl;
  } else {
    cout<<lines++<<" 'aa' predecessor is '"<<bst4.Predecessor("aa")<<"': Error!"<<endl;
    testBST &= false;
  }
  if(bst4.Successor("aaa") == "aaaa") {
    cout<<lines++<<" 'aaa' successor is '"<<bst4.SuccessorNRemove("aaa")<<"': Correct!"<<endl;
  } else {
    cout<<lines++<<" 'aaa' successor is '"<<bst4.SuccessorNRemove("aaa")<<"': Error!"<<endl;
    testBST &= false;
  }
  if(!bst4.Exists("aaaa")) {
    cout<<lines++<<" 'aaa' successor has been successfully deleted!: Correct!"<<endl; 
  } else {
    cout<<lines++<<" 'aaa' successore has NOT been deleted!: Error!"<<endl;
  }
  bst4.Clear();
  if(bst4.Empty()) {
    cout<<lines++<<" BST has been successfully cleared!: Correct!"<<endl; 
  } else {
    cout<<lines++<<" BST has NOT been cleared!: Error!"<<endl;
  }
  
  lasd::Vector<int> vec3(RandomNumber(gen) + 3);
  for(int i = 0; i < vec3.Size(); i++) {
    vec3[i] = RandomNumber(gen);
  }
  lasd::BST<int> bst5(vec3);
  cout<<"   Print BST with Random Values: \n";
  cout<<"   ";
  bst5.Map(
    [](const int& dat){
        cout<<dat<<"->";
    }
  );
  cout<<endl;
  if(bst5.Root().Element() == vec3[0]) {
    cout<<lines++<<" extracted BST Root is '"<<bst5.Root().Element()<<"'(expected '"<<vec3[0]<<"'): Correct!\n";
  } else {
    cout<<lines++<<" extracted BST Root is '"<<bst5.Root().Element()<<"'(expected '"<<vec3[0]<<"'): Error!\n";
    testBST &= false;   
  }
  vec3.Sort();
  if(vec3[0] == bst5.Min()) {
    cout<<lines++<<" extracted BST Min is '"<<bst5.Min()<<"'(expected '"<<vec3[0]<<"'): Correct!\n";
  } else {
    cout<<lines++<<" extracted BST Min is '"<<bst5.Min()<<"'(expected '"<<vec3[0]<<"'): Error!\n";
    testBST &= false;
  }
  if(bst5.Min() == bst5.Predecessor(bst5.Successor(bst5.Min()))){
    cout<<lines++<<" predecessor of Successor's Min is'"<<bst5.Predecessor(bst5.Successor(bst5.Min()))<<"'(expected '"<<bst5.Min()<<"'): Correct!\n";
  } else {
    cout<<lines++<<" predecessor of Successor's Min is'"<<bst5.Predecessor(bst5.Successor(bst5.Min()))<<"'(expected '"<<bst5.Min()<<"'): Error!\n";
    testBST &= false;
  }
  if(vec3[vec3.Size() - 1] == bst5.Max()) {
    cout<<lines++<<" extracted BST Max is '"<<bst5.Max()<<"'(expected '"<<vec3[vec3.Size() - 1]<<"'): Correct!\n";
  } else {
    cout<<lines++<<" extracted BST Max is '"<<bst5.Max()<<"'(expected '"<<vec3[vec3.Size() - 1]<<"'): Error!\n";
    testBST &= false;
  }
  if(bst5.Max() == bst5.Successor(bst5.Predecessor(bst5.Max()))){
    cout<<lines++<<" successor of Predecessor's Min is'"<<bst5.Successor(bst5.Predecessor(bst5.Max()))<<"'(expected '"<<bst5.Max()<<"'): Correct!\n";
  } else {
    cout<<lines++<<" successor of Predecessor's Min is'"<<bst5.Successor(bst5.Predecessor(bst5.Max()))<<"'(expected '"<<bst5.Max()<<"'): Error!\n";
    testBST &= false;
  }
  bst5.Clear();
  try{
    bst5.Root();
  } catch (std::length_error) {
    cout<<lines++<<" leng_error called BST is Empty, doesn't have root: Correct!"<<endl; 
  } catch (std::exception) {
    cout<<lines++<<" Wrong exception called: Error!"<<endl; 
    testBST &= false;     
  }
  if(bst5.Insert(5)){
    cout<<lines++<<" Inserted value 5: Correct!"<<endl;
  }else {
    cout<<lines++<<" Not inserted value 5: Error!"<<endl;
    testBST &= false;
  }
  if(bst5.Insert(7)) {
    cout<<lines++<<" Inserted value 7: Correct!"<<endl;
  }else {
    cout<<lines++<<" Not inserted value 7: Error!"<<endl;
    testBST &= false;
  }
  try {
    bst5.Successor(8);   
  } catch (std::length_error) {
    cout<<lines++<<" leng_error, value '8' doesnt' exists in BST: Correct!"<<endl;
  } catch (std::exception) {
    cout<<lines++<<" exception, value '8' doesnt' exists in BST: Error!"<<endl;
    testBST &= false;
  }
  if(bst5.Successor(6) == 7) {
    cout<<lines++<<" '6' successor is '7': Correct!"<<endl;
  } else {
    cout<<lines++<<" '6' is not '7': Error!"<<endl;
    testBST &= false;   
  }

  lasd::Vector<int>vettore(bst5);
  for(int i=0; i< vettore.Size();i++) {
    cout<<lines++<<" extracted value from Vector(BST): "<<vettore[i]<<endl;
  }
  lasd::List<int>lista(bst5);
  for(int i=0; i< lista.Size();i++) {
    cout<<lines++<<" extracted value from List(BST): "<<lista[i]<<endl;
  }

  lasd::Vector<int> vettore1((RandomNumber(gen)%10) + 5);
  for(int i = 0; i < vettore1.Size(); i++) {
    vettore1[i] = RandomNumber(gen);
  }
  cout<<lines++<<" MAP VETTORE:"; 
  vettore1.Map(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  lasd::BST<int> binserTree(std::move(vettore1));
  cout<<lines++<<" MAP:";
  binserTree.Map(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" PREORDERMAP:"; 
  binserTree.PreOrderMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" POSTORDERMAP:"; 
  binserTree.PostOrderMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" INORDERMAP:"; 
  binserTree.InOrderMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );
  cout<<"\n"<<lines++<<" BREADTHORDERMAP:"; 
  binserTree.BreadthMap(
    [](int dat){
      cout<<"->"<<dat;
    }
  );


  return testBST;
}


void TestEsercizio1(){
  cout<<(TestCostruttori()? "\nPASSATO\n" : "\nNON Passato\n");
  cout<<(TestAssegnazioni()? "\nPASSATO\n" : "\nNON Passato\n");
  cout<<(TestDictionaryFunctions()? "\nPASSATO\n" : "\nNON Passato\n");
  cout<<(TestSort()? "\nPASSATO\n\n" : "\nNON Passato\n\n");
  cout<<(TestQueueVec()? "\nPASSATO\n\n" : "\nNON Passato\n\n");
}

void TestEsercizio2(){
  bool testBST = TestBST();
  cout<<"\nBST Test: ", testBST ? cout<<"Passed!\n" : cout<<"NOT passed!\n";
  bool testIteratori = TestIteratori();
  cout<<"Iterator Test: ", testIteratori ? cout<<"Passed!\n" : cout<<"NOT passed!\n";
  bool testBTVec = TestBTVec();
  cout<<"\nBTVec Test: ", testBTVec ? cout<<"Passed!\n" : cout<<"NOT passed!\n";
  bool testBTLnk = TestBTLnk();
  cout<<"\nBTLnk Test: ", testBTVec ? cout<<"Passed!\n" : cout<<"NOT passed!\n"; 
  if(testBST && testIteratori && testBTVec && testBTLnk){
    cout<<"\nMyTest Esercizio2 : Passato!";
  } else {
    cout<<"\nMyTest Esercizio2 : NON Passato!";   
  }
}

void TestEsercizio3() {
  bool testOpenAdr = TestOpenAdr();
  cout<<"OpenAdr Test: ", testOpenAdr ? cout<<"Passed!\n" : cout<<"NOT passed!\n";
  bool testCloseAdr = TestCloseAdr();
  cout<<"\nClosedAdr Test: ", testCloseAdr ? cout<<"Passed!\n" : cout<<"NOT passed!\n";
  if(testOpenAdr && testCloseAdr){
    cout<<"\nMyTest Esercizio3 : Passato!";
  } else {
    cout<<"\nMyTest Esercizio3 : NON Passato!";   
  }
}

bool TestOpenAdr() {

    cout<<"\n\nBegin of HTOpenAdr Test: "<<endl;

    bool testOpenAdr = true;
    int lines = 1;

    lasd::Vector<int> vec1(8);
    vec1[0] = 5; vec1[1] = 1792; vec1[2] = -123; vec1[3] = -1;
    vec1[4] = -2; vec1[5] = -4; vec1[6] = -5; vec1[7] = -6;
    

    lasd::HashTableOpnAdr<int> htOpn1(1,vec1);
    if(!htOpn1.Exists(16)) {
        std::cout<<lines++<<" 16 does NOT Exists: Correct!"<<endl;
    } else {
        std::cout<<lines++<<" 16 does Exists: Error!"<<endl;
        testOpenAdr = false;
    }
    if(htOpn1.Exists(1792)) {
        std::cout<<lines++<<" 1792 does Exists: Correct!"<<endl;
    } else {
        std::cout<<lines++<<" 1792 does NOT Exists: Error!"<<endl;
        testOpenAdr = false;
    }
    if(htOpn1.Exists(5)) {
        std::cout<<lines++<<" 5 does Exists: Correct!"<<endl;
    } else {
        std::cout<<lines++<<" 5 does NOT Exists: Error!"<<endl;
        testOpenAdr = false;
    }
    if(htOpn1.Exists(-123)) {
        std::cout<<lines++<<" -123 does Exists: Correct!"<<endl;
    } else {
        std::cout<<lines++<<" -123 does NOT Exists: Error!"<<endl;
        testOpenAdr = false;
    }
    if(htOpn1.Exists(-1)) {
        std::cout<<lines++<<" -1 does Exists: Correct!"<<endl;
    } else {
        std::cout<<lines++<<" -1 does NOT Exists: Error!"<<endl;
        testOpenAdr = false;
    }
    if(!htOpn1.Exists(1)) {
        std::cout<<lines++<<" 1 does NOT Exists: Correct!"<<endl;
    } else {
        std::cout<<lines++<<" 1 does Exists: Error!"<<endl;
        testOpenAdr = false;
    }
    if(htOpn1.Exists(-2)) {
        std::cout<<lines++<<" -2 does Exists: Correct!"<<endl;
    } else {
        std::cout<<lines++<<" -2 does NOT Exists: Error!"<<endl;
        testOpenAdr = false;
    }
    if(htOpn1.Exists(-4)) {
        std::cout<<lines++<<" -4 does Exists: Correct!"<<endl;
    } else {
        std::cout<<lines++<<" -4 does NOT Exists: Error!"<<endl;
        testOpenAdr = false;
    }
    if(htOpn1.Exists(-5)) {
        std::cout<<lines++<<" -5 does Exists: Correct!"<<endl;
    } else {
        std::cout<<lines++<<" -5 does NOT Exists: Error!"<<endl;
        testOpenAdr = false;
    }
    if(htOpn1.Exists(-6)) {
        std::cout<<lines++<<" -6 does Exists: Correct!"<<endl;
    } else {
        std::cout<<lines++<<" -6 does NOT Exists: Error!"<<endl;
        testOpenAdr = false;
    }
    if(htOpn1.Exists(5)) {
        std::cout<<lines++<<" 5 does Exists: Correct!"<<endl;
    } else {
        std::cout<<lines++<<" 5 does NOT Exists: Error!"<<endl;
        testOpenAdr = false;
    }
    if(htOpn1.Remove(5)) {
        cout<<lines++<<" 5 element has been correctly removed: Correct!"<<endl;
    } else {
        cout<<lines++<<" 5 element has not been removed: Error!"<<endl;
        testOpenAdr = false;
    }
    if(!htOpn1.Exists(5)) {
        std::cout<<lines++<<" 5 does NOT Exists: Correct!"<<endl;
    } else {
        std::cout<<lines++<<" 5 does Exists: Error!"<<endl;
        testOpenAdr = false;
    }
    htOpn1.Clear();
    bool flagClear = true;
    for(int i = 0; i < vec1.Size(); i++) {
        if(htOpn1.Exists(vec1[i])) {
            flagClear &= false;
            testOpenAdr = false;
            cout<<lines++<<" "<<vec1[i]<<" does Exists: Error!"<<endl;
        } else {
            cout<<lines++<<" "<<vec1[i]<<" does NOT Exists: Correct!"<<endl;
        }
    }
    if(flagClear) {
        cout<<lines++<<" htOpn has been correctly Cleared: Correct!"<<endl;
    } else {
        cout<<lines++<<" htOpn has NOT been correctly Cleared: Error!"<<endl;
    }

    lasd::List<double> lst1;
    for(int i = 0; i < RandomNumber(gen); i++) {
        lst1.Insert(RandomNumber(gen));
    }

    lasd::List<double> lst2(lst1);
    lasd::Vector<double> vec2(lst2);

    lasd::HashTableOpnAdr<double> htOpn2(std::move(lst1));
    lasd::HashTableOpnAdr<double> htOpn3(std::move(lst2));
    if(htOpn2 == htOpn3) {
        cout<<lines++<<" htOpn2 and htOpn3 are equals: Correct!"<<endl;
    } else {
        cout<<lines++<<" htOpn2 and htOpn3 are NOT equals: Error!"<<endl;
        testOpenAdr = false;
    }
    htOpn2.Clear();
    if(htOpn2.Empty()) {
        cout<<lines++<<" htOpn2 has been Cleared: Correct!"<<endl;
    } else {
        cout<<lines++<<" htOpn2 has NOT been Cleared: Error!"<<endl;
        testOpenAdr = false;
    }
    htOpn2 = std::move(htOpn3);
    if(htOpn3.Empty()) {
        cout<<lines++<<" htOpn3 has been Swapped: Correct!"<<endl;
    } else {
        cout<<lines++<<" htOpn3 has NOT been Swapped: Error!"<<endl;
        testOpenAdr = false;
    }    
    if(!htOpn2.Empty()) {
        cout<<lines++<<" htOpn2 is NOT empty now: Correct!"<<endl;
    } else {
        cout<<lines++<<" htOpn2 is empty now: Error!"<<endl;
        testOpenAdr = false;
    }
    if(htOpn2.RemoveSome(vec2) && htOpn2.Empty()) {
        cout<<lines++<<" all htOpn2 Elements have been removed: Correct!"<<endl;
    } else {
        cout<<lines++<<" all htOpn2 Elements have NOT been removed: Error!"<<endl;
        testOpenAdr = false;
    }

    lasd::HashTableOpnAdr<int> htOpn4(0);
    htOpn4.Clear();
    if(htOpn4.Empty()) {
        cout<<lines++<<" htOpn4 is empty now: Correct!"<<endl;
    } else {
        cout<<lines++<<" htOpn4 is NOT empty now: Error!"<<endl;
        testOpenAdr = false;
    }
    for(ulong i = 0; i < RandomNumber(gen) * RandomNumber(gen) + 1; i++) {
        int RandomValue = RandomNumber(gen);
        if(htOpn4.Insert(RandomValue)) {
            cout<<" Inserted value: "<<RandomValue<<endl;
        }
        if(htOpn4.Remove(RandomValue)) {
            cout<<" Removed value: "<<RandomValue<<endl;
        }
    }
    if(htOpn4.Empty()) {
        cout<<lines++<<" htOpn4 is already empty: Correct!"<<endl;
    } else {
        cout<<lines++<<" htOpn4 is NO more empty: Error!"<<endl;
        testOpenAdr = false;
    }

    lasd::List<int> lst3;
    for(ulong i = 0; i < RandomNumber(gen) + 1; i++) {
        lst3.Insert(RandomNumber(gen));
    }
    lasd::HashTableOpnAdr<int> htOpn5(31, std::move(lst3));
    lasd::Vector<int> vec3(101);
    for(int i = 0; i <= 100; i++) {
        vec3[i] = i;
    };
    htOpn5.RemoveSome(vec3);
    if(htOpn5.Empty()){
        cout<<lines++<<" (removeSome vec3) every htOpn5 element has been correctly removed: Correct!"<<endl;
    } else {
        cout<<lines++<<" (removeSome vec3) every htOpn5 element has been correctly removed: Error!"<<endl;
        testOpenAdr = false;
    }
    htOpn5.Clear();
    htOpn5.Resize(0);
    htOpn5.Clear();
    htOpn5.Clear();
    lasd::Vector<int> vec4;
    if(!htOpn5.RemoveSome(vec4)) {
        cout<<lines++<<" NO elements have been removed: Correct!"<<endl;
    } else {
        cout<<lines++<<" some elements have been removed: Error!"<<endl;
        testOpenAdr = false;
    }
    if(htOpn4 == htOpn5) {
        cout<<lines++<<" the two empty htOpn are equal: Correct!"<<endl;
    } else {
        cout<<lines++<<" the two empty htOpn are NOT equal: error!"<<endl;
        testOpenAdr = false;
    }
    if(!htOpn5.Remove(5)) {
        cout<<lines++<<" an empty htOpn doesn't remove elements: Correct!"<<endl;
    } else {
        cout<<lines++<<" an empty htOpn remove elements: Error!"<<endl;
        testOpenAdr = false;
    }

    lasd::HashTableOpnAdr<int> htOpn6;
    ulong dimension = RandomNumber(gen) * RandomNumber(gen) + 1;
    for(ulong i = 0; i < dimension; i++) {
        htOpn6.Insert(RandomNumber(gen) * RandomNumber(gen) * RandomNumber(gen));
    }
    int sizeBefore = htOpn6.Size();
    cout<<" size before Resizing: "<<sizeBefore<<endl;
    htOpn6.Resize(dimension/5);
    int sizeAfter = htOpn6.Size();
    cout<<" size after Resizing: "<<sizeAfter<<endl;
    if(sizeBefore == sizeAfter) {
        cout<<lines++<<" size before and after resizing/5 are equals: Correct!"<<endl;
    } else {
        cout<<lines++<<" size before and after resizing/5 are NOT equals: Error!"<<endl;
        testOpenAdr = false;
    }
    lasd::List<int> lst4;
    int InsertedElement;
    cout<< "Creating a List without repetitions: "<<endl;
    for(ulong i = 0; i < RandomNumber(gen) * RandomNumber(gen) + 1; i++) {
        InsertedElement = RandomNumber(gen) * RandomNumber(gen); 
        if(!lst4.Exists(InsertedElement)) {
            lst4.Insert(InsertedElement);       //inserisco senza duplicati nella lista
        }  
    }
    htOpn6.Clear();
    if(htOpn6.InsertAll(lst4)) {
        cout<<lines++<<" every element from a List has been inserted: Correct!"<<endl;
    } else {
        cout<<lines++<<" some elements from a List have NOT been inserted: Error!"<<endl;
        testOpenAdr = false;
    }
    lasd::HashTableOpnAdr<int> htOpn7;
    htOpn7 = htOpn6;
    if(!htOpn7.InsertSome(lst4)) {
        cout<<lines++<<" NO elements have been inserted: Correct!"<<endl;
    } else {
        cout<<lines++<<" some elements have been inserted: Error!"<<endl;
        testOpenAdr = false;      
    }
    htOpn7 = std::move(htOpn6);
    if(htOpn6 == htOpn7) {
        cout<<lines++<<" htOpn and its(equal) move assignament are equals: Correct!"<<endl;
    } else {
        cout<<lines++<<" htOpn and its(equal) move assignament are different: Error!"<<endl;
        testOpenAdr = false;     
    }
    htOpn7.Clear();
    htOpn7 = std::move(htOpn6);
    if(htOpn6 != htOpn7) {
        cout<<lines++<<" htOpn and its(equal) move assignament are different: Correct!"<<endl;
    } else {
        cout<<lines++<<" htOpn and its(equal) move assignament are equals: Error!"<<endl;
        testOpenAdr = false;     
    }
    if(htOpn6.Empty()) {
        cout<<lines++<<" moved htOpn is empty: Correct!"<<endl;
    } else {
        cout<<lines++<<" moved htOpn is not empty: Error!"<<endl;
    }

    return testOpenAdr;
}

bool TestCloseAdr() {
    bool testCloseAdr = true;
    int lines = 1;


    return testCloseAdr;
}

#endif

// #ifndef MYTEST_CPP
// #define MYTEST_CPP

// #include <iostream>
// #include <random>
// #include <stack>
// #include <queue>


// #include "../container/mappable.hpp"

// #include "test.hpp"

// using namespace std;



// int MIN_SIZE = 0;
// int MAX_SIZE = 100;
// int MIN_NUM = INT16_MIN;
// int MAX_NUM = INT16_MAX;
// int ITERAZIONI = 1;

// bool output;

// default_random_engine gen(random_device{}());
// uniform_int_distribution<int> genSize(MIN_SIZE,MAX_SIZE);
// uniform_int_distribution<int> genNum(MIN_NUM,MAX_NUM);

// /*


//     L'UTILIZZO DELLE FUNZIONI E' AL TERMINE DELLA LORO DEFINIZIONE


// */

// bool TestAssVector() {
//     lasd::Vector<int> s1(genSize(gen));
//     for(ulong i=0; i<s1.Size(); i++) s1[i]=genNum(gen);
//     lasd::Vector<int> s2(genSize(gen));
//     for(ulong i=0; i<s2.Size(); i++) s2[i]=genNum(gen);
//     s1=s2;
//     return (s1==s2);
// }

// bool TestAssList() {
//     int temp_size1 = genSize(gen);
//     int temp_size2 = genSize(gen);
//     lasd::List<int> s1;
//     for(int i=0; i<temp_size1; i++) s1.Insert(genNum(gen));
//     lasd::List<int> s2;
//     for(int i=0; i<temp_size2; i++) s2.Insert(genNum(gen));
//     s1=s2;
//     return (s1==s2);
// }

// bool TestAssStackLst() {
//     int temp_size1 = genSize(gen);
//     int temp_size2 = genSize(gen);
//     lasd::StackLst<int> s1;
//     for(int i=0; i<temp_size1; i++) s1.Push(genNum(gen));
//     lasd::StackLst<int> s2;
//     for(int i=0; i<temp_size2; i++) s2.Push(genNum(gen));
//     s1=s2;
//     return (s1==s2);
// }

// bool TestAssStackVec() {
//     int temp_size1 = genSize(gen);
//     int temp_size2 = genSize(gen);
//     lasd::StackVec<int> s1;
//     for(int i=0; i<temp_size1; i++) s1.Push(genNum(gen));
//     lasd::StackVec<int> s2;
//     for(int i=0; i<temp_size2; i++) s2.Push(genNum(gen));
//     s1=s2;
//     return (s1==s2);
// }

// bool TestAssQueueLst() {
//     int temp_size1 = genSize(gen);
//     int temp_size2 = genSize(gen);
//     lasd::QueueLst<int> s1;
//     for(int i=0; i<temp_size1; i++) s1.Enqueue(genNum(gen));
//     lasd::QueueLst<int> s2;
//     for(int i=0; i<temp_size2; i++) s2.Enqueue(genNum(gen));
//     s1=s2;
//     return (s1==s2);
// }

// bool TestAssQueueVec() {
//     int temp_size1 = genSize(gen);
//     int temp_size2 = genSize(gen);
//     lasd::QueueVec<int> s1;
//     for(int i=0; i<temp_size1; i++) s1.Enqueue(genNum(gen));
//     lasd::QueueVec<int> s2;
//     for(int i=0; i<temp_size2; i++) s2.Enqueue(genNum(gen));
//     s1=s2;
//     return (s1==s2);
// }

// bool TestEqualLinear(){
//     bool correct=true;
//     int temp_size = genSize(gen)+1;
//     lasd::Vector<int> v(temp_size);
//     lasd::List<int> l;
//     for(int i=0; i<temp_size; i++){
//         int temp_num = genNum(gen);
//         v[i]=temp_num;
//         l.InsertAtBack(temp_num);
//     }
//     correct&=(v.LinearContainer<int>::operator==(l));
//     v[genSize(gen)%temp_size]=genNum(gen);
//     correct&=(v.LinearContainer<int>::operator!=(l));
//     v.Clear();
//     l.Clear();
//     correct&=(v.LinearContainer<int>::operator==(l));
//     return correct;
// }

// bool TestEqualVector(){
//     bool correct=true;
//     int temp_size = genSize(gen)+1;
//     lasd::Vector<int> v1(temp_size);
//     lasd::Vector<int> v2(temp_size);
//     for(int i=0; i<temp_size; i++) v2[i]=v1[i]=genNum(gen);
//     correct&=(v1==v2);
//     v1[genSize(gen)%temp_size]=genNum(gen);
//     correct&=!(v1==v2);
//     v1.Clear();
//     correct&=(v1!=v2);
//     v2.Clear();
//     correct&=(v1==v2);
//     return correct;
// }

// bool TestEqualList(){
//     bool correct=true;
//     int temp_size = genSize(gen)+1;
//     lasd::List<int> l1;
//     lasd::List<int> l2;
//     for(int i=0; i<temp_size; i++){
//         int temp_num = genNum(gen);
//         l1.InsertAtFront(temp_num);
//         l2.InsertAtFront(temp_num);
//     } 
//     correct&=(l1==l2);
//     l1[genSize(gen)%temp_size]=genNum(gen);
//     correct&=(l1!=l2);
//     l1.Clear();
//     correct&=(l1!=l2);
//     l2.Clear();
//     correct&=(l1==l2);
//     return correct;
// }

// bool TestEqualStackVec(){
//     bool correct=true;
//     int temp_size = genSize(gen)+1;
//     lasd::StackVec<int> s1;
//     lasd::StackVec<int> s2;
//     for(int i=0; i<temp_size; i++){
//         int temp_num = genNum(gen);
//         s1.Push(temp_num);
//         s2.Push(temp_num);
//     } 
//     correct&=(s1==s2);
//     s2.Clear();
//     correct&=(s1!=s2);
//     s1.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestEqualStackLst(){
//     bool correct=true;
//     int temp_size = genSize(gen)+1;
//     lasd::StackLst<int> s1;
//     lasd::StackLst<int> s2;
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         s1.Push(temp_num);
//         s2.Push(temp_num);
//     } 
//     correct&=(s1==s2);
//     s2.Pop();
//     s2.Push(genNum(gen));
//     correct&=(s1!=s2);
//     s1.Clear();
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestEqualQueueVec(){
//     bool correct=true;
//     int temp_size = genSize(gen)+1;
//     lasd::QueueVec<int> s1;
//     lasd::QueueVec<int> s2;
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         s1.Enqueue(temp_num);
//         s2.Enqueue(temp_num);
//     } 
//     correct&=(s1==s2);
//     s2.Dequeue();
//     s2.Enqueue(genNum(gen));
//     correct&=(s1!=s2);
//     s1.Clear();
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestEqualQueueLst(){
//     bool correct=true;
//     int temp_size = genSize(gen)+1;
//     lasd::QueueLst<int> s1;
//     lasd::QueueLst<int> s2;
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         s1.Enqueue(temp_num);
//         s2.Enqueue(temp_num);
//     } 
//     correct&=(s1==s2);
//     s2.Dequeue();
//     s2.Enqueue(genNum(gen));
//     correct&=(s1!=s2);
//     s1.Clear();
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool CCVec(){
//     if(output) cout<<"\n**********TEST CCVec**********\n";
//     bool correct=true;
//     lasd::Vector<int> s1(genSize(gen));
//     for(ulong i=0; i<s1.Size(); i++) s1[i]=genNum(gen);
//     lasd::Vector<int> s2(s1);
//     if(output){
//         cout<<"Vettore1: ";
//         for(ulong i{0}; i<s1.Size(); i++) cout<<s1[i]<<"\t";
//         cout<<endl;
//         cout<<"Vettore2: ";
//         for(ulong i{0}; i<s2.Size(); i++) cout<<s2[i]<<"\t";
//         cout<<endl;
//     }
//     correct&=(s1==s2);
//     s1.Clear();
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool MCVec(){
//     if(output) cout<<"\n**********TEST MCVec**********\n";
//     bool correct=true;
//     lasd::Vector<int> s1(genSize(gen));
//     for(ulong i=0; i<s1.Size(); i++) s1[i]=genNum(gen);
//     lasd::Vector<int> s3(s1);
//     lasd::Vector<int> s2(move(s1));
//     if(output){
//         cout<<"Vettore1: ";
//         for(ulong i{0}; i<s1.Size(); i++) cout<<s1[i]<<"\t";
//         cout<<endl;
//         cout<<"Vettore2: ";
//         for(ulong i{0}; i<s2.Size(); i++) cout<<s2[i]<<"\t";
//         cout<<endl;
//     }
//     correct&=s1.Empty();
//     correct&=(s2==s3);
//     s1.Clear();
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestaLista(lasd::List<int>& s){
//     ulong init_size = s.Size();
//     int temp_size = genSize(gen);
//     for(int i{0}; i<temp_size; i++){ s.InsertAtFront(genNum(gen)); }
//     while(s.Size()>0) { s.RemoveFromFront(); temp_size--; }
//     if(temp_size+init_size!=0) {
//         cout<<"\ntemp: "<<temp_size<<"\tinit: "<<init_size;
//         cout<<"\nVettore svuotato NON correttamente\n\n";
//     }
//     return temp_size+init_size==0;
// }

// bool TestaLista(lasd::List<int>&& s){
//     ulong init_size = s.Size();
//     int temp_size = genSize(gen);
//     for(int i{0}; i<temp_size; i++){ s.InsertAtFront(genNum(gen)); }
//     while(s.Size()>0) { s.RemoveFromFront(); temp_size--; }
//     if(temp_size+init_size!=0) {
//         cout<<"\ntemp: "<<temp_size<<"\tinit: "<<init_size;
//         cout<<"\nVettore svuotato NON correttamente\n\n";
//     }
//     return temp_size+init_size==0;
// }

// bool CCLst(){
//     if(output) cout<<"\n**********TEST CCLst**********\n";
//     bool correct=true;
//     lasd::List<int> s1;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) s1.InsertAtFront(genNum(gen)); 
//     lasd::List<int> s2(s1);
//     if(output){
//         cout<<"Lista1: ";
//         for(ulong i{0}; i<s1.Size(); i++) cout<<s1[i]<<"\t";
//         cout<<endl;
//         cout<<"Lista2: ";
//         for(ulong i{0}; i<s2.Size(); i++) cout<<s2[i]<<"\t";
//         cout<<endl;
//     }
//     correct&=(s1==s2);
//     correct&=TestaLista(s2);
//     correct&=TestaLista(s1);
//     s1.Clear();
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool MCLst(){
//     if(output) cout<<"\n**********TEST MCLst**********\n";
//     bool correct=true;
//     lasd::List<int> s1;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) s1.InsertAtFront(genNum(gen)); 
//     lasd::List<int> s3(s1);
//     lasd::List<int> s2(move(s1));
//     correct&=(s1.Empty());
//     correct&=(s3==s2);
//     if(output){
//         cout<<"Lista1: ";
//         for(ulong i{0}; i<s1.Size(); i++) cout<<s1[i]<<"\t";
//         cout<<endl;
//         cout<<"Lista2: ";
//         for(ulong i{0}; i<s2.Size(); i++) cout<<s2[i]<<"\t";
//         cout<<endl;
//     }
//     correct&=TestaLista(move(s2));
//     s1.Clear();
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool CCStackVec(){
//     if(output) cout<<"\n**********TEST CCStackVec**********\n";
//     bool correct=true;
//     lasd::StackVec<int> s1;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) s1.Push(genNum(gen));
//     lasd::StackVec<int> s2(s1);
//     correct&=(s1==s2);
//     if(output){
//         cout<<"StackVec1: ";
//         while(s1.Size()>0) cout<<s1.TopNPop()<<"\t";
//         cout<<endl;
//         cout<<"StackVec2: ";
//         while(s2.Size()>0)  cout<<s2.TopNPop()<<"\t";
//         cout<<endl;
//     }
//     correct&=(s1==s2);
//     s1.Clear();
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool MCStackVec(){
//     if(output) cout<<"\n**********TEST MCStackVec**********\n";
//     bool correct=true;
//     lasd::StackVec<int> s1;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) s1.Push(genNum(gen));
//     lasd::StackVec<int> s3(s1);
//     lasd::StackVec<int> s2(move(s1));
//     correct&=(s3==s2);
//     correct&=(s1.Empty());
//     if(output){
//         cout<<"StackVec1: ";
//         while(s1.Size()>0) cout<<s1.TopNPop()<<"\t";
//         cout<<endl;
//         cout<<"StackVec2: ";
//         while(s2.Size()>0)  cout<<s2.TopNPop()<<"\t";
//         cout<<endl;
//     }
//     s1.Clear();
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool CCStackLst(){
//     if(output) cout<<"\n**********TEST CCStackLst**********\n";
//     bool correct=true;
//     lasd::StackLst<int> s1;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) s1.Push(genNum(gen));
//     lasd::StackLst<int> s2(s1);
//     correct&=(s1==s2);
//     if(output){
//         cout<<"StackLst1: ";
//         while(s1.Size()>0) cout<<s1.TopNPop()<<"\t";
//         cout<<endl;
//         cout<<"StackLst2: ";
//         while(s2.Size()>0)  cout<<s2.TopNPop()<<"\t";
//         cout<<endl;
//     }
//     s1.Clear();
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool MCStackLst(){
//     if(output) cout<<"\n**********TEST MCStackLst**********\n";
//     bool correct=true;
//     lasd::StackLst<int> s1;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) s1.Push(genNum(gen));
//     lasd::StackLst<int> s3(s1);
//     lasd::StackLst<int> s2(move(s1));
//     correct&=(s1.Empty());
//     correct&=(s2==s3);
//     if(output){
//         cout<<"StackLst: ";
//         while(s1.Size()>0) cout<<s1.TopNPop()<<"\t";
//         cout<<endl;
//         cout<<"StackLst: ";
//         while(s2.Size()>0)  cout<<s2.TopNPop()<<"\t";
//         cout<<endl;
//     }
//     s1.Clear();
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool CCQueueLst(){
//     if(output) cout<<"\n**********TEST CCQueueLst**********\n";
//     bool correct=true;
//     lasd::QueueLst<int> s1;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) s1.Enqueue(genNum(gen));
//     lasd::QueueLst<int> s2(s1);
//     correct&=(s1==s2);
//     if(output){
//         cout<<"QueueLst1: ";
//         while(s1.Size()>0) cout<<s1.HeadNDequeue()<<"\t";
//         cout<<endl;
//         cout<<"QueueLst2: ";
//         while(s2.Size()>0)  cout<<s2.HeadNDequeue()<<"\t";
//         cout<<endl;
//     }
//     s1.Clear();
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool MCQueueLst(){
//     if(output) cout<<"\n**********TEST MCQueueLst**********\n";
//     bool correct=true;
//     lasd::QueueLst<int> s1;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) s1.Enqueue(genNum(gen));
//     lasd::QueueLst<int> s3(s1);
//     lasd::QueueLst<int> s2(move(s1));
//     correct&=(s2==s3);
//     correct&=(s1.Empty());
//     if(output){
//         cout<<"QueueLst1: ";
//         while(s1.Size()>0) cout<<s1.HeadNDequeue()<<"\t";
//         cout<<endl;
//         cout<<"QueueLst2: ";
//         while(s2.Size()>0)  cout<<s2.HeadNDequeue()<<"\t";
//         cout<<endl;
//     }
//     s1.Clear();
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool CCQueueVec(){
//     if(output) cout<<"\n**********TEST CCQueueVec**********\n";
//     bool correct=true;
//     lasd::QueueLst<int> s1;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) s1.Enqueue(genNum(gen));
//     lasd::QueueLst<int> s2(s1);
//     correct&=(s1==s2);
//     if(output){
//         cout<<"QueueLst1: ";
//         while(s1.Size()>0) cout<<s1.HeadNDequeue()<<"\t";
//         cout<<endl;
//         cout<<"QueueLst2: ";
//         while(s2.Size()>0)  cout<<s2.HeadNDequeue()<<"\t";
//         cout<<endl;
//     }
//     s1.Clear();
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool MCQueueVec(){
//     if(output) cout<<"\n**********TEST MCQueueVec**********\n";
//     bool correct=true;
//     lasd::QueueVec<int> s1;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) s1.Enqueue(genNum(gen));
//     lasd::QueueVec<int> s3(s1);
//     lasd::QueueVec<int> s2(move(s1));
//     correct&=(s2==s3);
//     correct&=(s1.Empty());
//     if(output){
//         cout<<"QueueLst1: ";
//         while(s1.Size()>0) cout<<s1.HeadNDequeue()<<"\t";
//         cout<<endl;
//         cout<<"QueueLst2: ";
//         while(s2.Size()>0)  cout<<s2.HeadNDequeue()<<"\t";
//         cout<<endl;
//     } 
//     s1.Clear();
//     correct&=(s1.Empty());
//     s2.Clear();
//     correct&=(s2.Empty());
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestSCVecFromList() {
//     if(output) cout<<"\n**********TEST SCVecFromList**********\n";
//     bool correct = true;
//     lasd::List<int> l;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) l.InsertAtFront(genNum(gen));
//     lasd::Vector<int> v(l);
//     for(ulong i{0}; i<v.Size(); i++) correct&=(v[i]==l[i]);
//     return correct;
// }

// bool TestSCListFromVector(){
//     if(output) cout<<"\n**********TEST SCListFromVector**********\n";
//     bool correct = true;
//     lasd::Vector<int> v(genSize(gen));
//     for(ulong i=0; i<v.Size(); i++) v[i] = genNum(gen);
//     lasd::List<int> l(v);
//     for(ulong i{0}; i<v.Size(); i++) correct&=(v[i]==l[i]);
//     return correct;
// }

// bool TestSCStackVecFromList() {
//     if(output) cout<<"\n**********TEST SCStackVecFromList**********\n";
//     bool correct = true;
//     lasd::List<int> l;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) l.InsertAtFront(genNum(gen));
//     lasd::StackVec<int> v(l);
//     for(long i = l.Size()-1; i>=0; i--) correct&=(v.TopNPop()==l[i]);
//     return correct;
// }

// bool TestSCStackVecFromVector(){
//     if(output) cout<<"\n**********TEST SCStackVecFromVector**********\n";
//     bool correct = true;
//     lasd::Vector<int> v(genSize(gen));
//     for(ulong i=0; i<v.Size(); i++) v[i] = genNum(gen);
//     lasd::StackVec<int> l(v);
//     for(long i = v.Size()-1; i>=0; i--) correct&=(l.TopNPop()==v[i]);
//     return correct;
// }

// bool TestSCStackLstFromList() {
//     if(output) cout<<"\n**********TEST SCStackLstFromList**********\n";
//     bool correct = true;
//     lasd::List<int> l;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) l.InsertAtFront(genNum(gen));
//     lasd::StackLst<int> v(l);
//     for(ulong i{0}; i<v.Size(); i++) correct&=(v.TopNPop()==l[i]);
//     return correct;
// }

// bool TestSCStackLstFromVector(){
//     if(output) cout<<"\n**********TEST SCStackLstFromVector**********\n";
//     bool correct = true;
//     lasd::Vector<int> v(genSize(gen));
//     for(ulong i=0; i<v.Size(); i++) v[i] = genNum(gen);
//     lasd::StackLst<int> l(v);
//     for(ulong i{0}; i<v.Size(); i++) correct&=(l.TopNPop()==v[i]);
//     return correct;
// }

// bool TestSCQueueVecFromList() {
//     if(output) cout<<"\n**********TEST SCQueueVecFromList**********\n";
//     bool correct = true;
//     lasd::List<int> l;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) l.InsertAtFront(genNum(gen));
//     lasd::QueueVec<int> v(l);
//     for(ulong i{0}; i<v.Size(); i++) correct&=(v.HeadNDequeue()==l[i]);
//     return correct;
// }

// bool TestSCQueueVecFromVector(){
//     if(output) cout<<"\n**********TEST SCQueueVecFromVector**********\n";
//     bool correct = true;
//     lasd::Vector<int> v(genSize(gen));
//     for(ulong i=0; i<v.Size(); i++) v[i] = genNum(gen);
//     lasd::QueueVec<int> l(v);
//     for(ulong i{0}; i<v.Size(); i++) correct&=(l.HeadNDequeue()==v[i]);
//     return correct;
// }

// bool TestSCQueueLstFromList() {
//     if(output) cout<<"\n**********TEST SCQueueLstFromList**********\n";
//     bool correct = true;
//     lasd::List<int> l;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) l.InsertAtFront(genNum(gen));
//     lasd::QueueLst<int> v(l);
//     for(ulong i{0}; i<v.Size(); i++) correct&=(v.HeadNDequeue()==l[i]);
//     return correct;
// }

// bool TestSCQueueLstFromVector(){
//     if(output) cout<<"\n**********TEST SCQueueLstFromVector**********\n";
//     bool correct = true;
//     lasd::Vector<int> v(genSize(gen));
//     for(ulong i=0; i<v.Size(); i++) v[i] = genNum(gen);
//     lasd::QueueLst<int> l(v);
//     for(ulong i{0}; i<v.Size(); i++) correct&=(l.HeadNDequeue()==v[i]);
//     return correct;
// }

// bool TestMSCVecFromList() {
//     if(output) cout<<"\n**********TEST MSCVecFromList**********\n";
//     bool correct = true;
//     lasd::List<int> l;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) l.InsertAtFront(genNum(gen));
//     lasd::Vector<int> v1(l);
//     lasd::Vector<int> v2(move(l));
//     for(ulong i{0}; i<v1.Size(); i++) correct&=(v1[i]==v2[i]);
//     return correct;
// }

// bool TestMSCListFromVector(){
//     if(output) cout<<"\n**********TEST MSCListFromVector**********\n";
//     bool correct = true;
//     lasd::Vector<int> v(genSize(gen));
//     for(ulong i=0; i<v.Size(); i++) v[i] = genNum(gen);
//     lasd::List<int> l1(v);
//     lasd::List<int> l2(move(v));
//     for(ulong i{0}; i<l1.Size(); i++) correct&=(l1[i]==l2[i]);
//     return correct;
// }

// bool TestMSCStackVecFromList() {
//     if(output) cout<<"\n**********TEST MSCStackVecFromList**********\n";
//     bool correct = true;
//     lasd::List<int> l;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) l.InsertAtFront(genNum(gen));
//     lasd::StackVec<int> v1(l);
//     lasd::StackVec<int> v2(move(l));
//     while(v2.Size()>0) correct&=(v1.TopNPop()==v2.TopNPop());
//     return correct;
// }

// bool TestMSCStackVecFromVector(){
//     if(output) cout<<"\n**********TEST MSCStackVecFromVector**********\n";
//     bool correct = true;
//     lasd::Vector<int> v(genSize(gen));
//     for(ulong i=0; i<v.Size(); i++) v[i] = genNum(gen);
//     lasd::StackVec<int> l1(v);
//     lasd::StackVec<int> l2(move(v));
//     while(l2.Size()>0) correct&=(l1.TopNPop()==l2.TopNPop());
//     return correct;
// }

// bool TestMSCStackLstFromList() {
//     if(output) cout<<"\n**********TEST MSCStackLstFromList**********\n";
//     bool correct = true;
//     lasd::List<int> l;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) l.InsertAtFront(genNum(gen));
//     lasd::StackVec<int> v1(l);
//     lasd::StackVec<int> v2(move(l));
//     while(v2.Size()>0) correct&=(v1.TopNPop()==v2.TopNPop());
//     return correct;
// }

// bool TestMSCStackLstFromVector(){
//     if(output) cout<<"\n**********TEST MSCStackLstFromVector**********\n";
//     bool correct = true;
//     lasd::Vector<int> v(genSize(gen));
//     for(ulong i=0; i<v.Size(); i++) v[i] = genNum(gen);
//     lasd::StackLst<int> l1(v);
//     lasd::StackLst<int> l2(move(v));
//     while(l2.Size()>0) correct&=(l1.TopNPop()==l2.TopNPop());
//     return correct;
// }

// bool TestMSCQueueVecFromList() {
//     if(output) cout<<"\n**********TEST MSCQueueVecFromList**********\n";
//     bool correct = true;
//     lasd::List<int> l;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) l.InsertAtFront(genNum(gen));
//     lasd::QueueVec<int> v1(l);
//     lasd::QueueVec<int> v2(move(l));
//     while(v2.Size()>0) correct&=(v1.HeadNDequeue()==v2.HeadNDequeue());
//     return correct;
// }

// bool TestMSCQueueVecFromVector(){
//     if(output) cout<<"\n**********TEST MSCQueueVecFromVector**********\n";
//     bool correct = true;
//     lasd::Vector<int> v(genSize(gen));
//     for(ulong i=0; i<v.Size(); i++) v[i] = genNum(gen);
//     lasd::QueueVec<int> l1(v);
//     lasd::QueueVec<int> l2(move(v));
//     while(l2.Size()>0) correct&=(l1.HeadNDequeue()==l2.HeadNDequeue());
//     return correct;
// }

// bool TestMSCQueueLstFromList() {
//     if(output) cout<<"\n**********TEST MSCQueueLstFromList**********\n";
//     bool correct = true;
//     lasd::List<int> l;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) l.InsertAtFront(genNum(gen));
//     lasd::QueueVec<int> v1(l);
//     lasd::QueueVec<int> v2(move(l));
//     while(v2.Size()>0) correct&=(v1.HeadNDequeue()==v2.HeadNDequeue());
//     return correct;
// }

// bool TestMSCQueueLstFromVector(){
//     if(output) cout<<"\n**********TEST MSCQueueLstFromVector**********\n";
//     bool correct = true;
//     lasd::Vector<int> v(genSize(gen));
//     for(ulong i=0; i<v.Size(); i++) v[i] = genNum(gen);
//     lasd::QueueLst<int> l1(v);
//     lasd::QueueLst<int> l2(move(v));
//     while(l2.Size()>0) correct&=(l1.HeadNDequeue()==l2.HeadNDequeue());
//     return correct;
// }

// bool TestStackVSSTD(){
//     if(output) cout<<"\n**********TEST StackVSSTD**********\n";
//     bool correct = true;
//     int temp_size = genSize(gen);
//     std::stack<int> stdStack;
//     lasd::StackVec<int> lasdStackVec;
//     lasd::StackLst<int> lasdStackLst;
//     for(int i{0}; i<temp_size; i++){
//         int temp_num = genNum(gen);
//         stdStack.push(temp_num);
//         lasdStackVec.Push(temp_num);
//         lasdStackLst.Push(temp_num);
//     }
//     correct&=((stdStack.size()==lasdStackLst.Size()) && (stdStack.size()==lasdStackVec.Size()));
//     if(output) cout<<"STDSize: "<<stdStack.size()<<"\tlasdVecSize: "<<lasdStackVec.Size()<<"\tlasdLst: "<<lasdStackLst.Size()<<endl;
//     for(int i{0}; i<temp_size; i++){
//         if(output) cout<<"\n"<<i<<"\tSTD: "<<stdStack.top()<<"\tlasdVec: "<<lasdStackVec.Top()<<"\tlasdLst: "<<lasdStackLst.Top();
//         correct&=((stdStack.top()==lasdStackLst.Top()) && (stdStack.top()==lasdStackVec.Top()));
//         stdStack.pop();
//         lasdStackVec.Pop();
//         lasdStackLst.Pop();
//     }
//     return correct;
// }

// bool TestQueueVSSTD(){
//     if(output) cout<<"\n**********TEST QueueVSSTD**********\n";
//     bool correct = true;
//     int temp_size = genSize(gen);
//     std::queue<int> stdQueue;
//     lasd::QueueVec<int> lasdQueueVec;
//     lasd::QueueLst<int> lasdQueueLst;
//     for(int i{0}; i<temp_size; i++){
//         int temp_num = genNum(gen);
//         stdQueue.push(temp_num);
//         lasdQueueVec.Enqueue(temp_num);
//         lasdQueueLst.Enqueue(temp_num);
//     }
//     correct&=((stdQueue.size()==lasdQueueLst.Size()) && (stdQueue.size()==lasdQueueVec.Size()));
//     if(output) cout<<"STDSize: "<<stdQueue.size()<<"\tlasdVecSize: "<<lasdQueueVec.Size()<<"\tlasdLst: "<<lasdQueueLst.Size()<<endl;
//     for(int i{0}; i<temp_size; i++){
//         if(output) cout<<"\n"<<i<<"\tSTD: "<<stdQueue.front()<<"\tlasdVec: "<<lasdQueueVec.Head()<<"\tlasdLst: "<<lasdQueueLst.Head();
//         correct&=((stdQueue.front()==lasdQueueLst.Head()) && (stdQueue.front()==lasdQueueVec.Head()));
//         stdQueue.pop();
//         lasdQueueVec.Dequeue();
//         lasdQueueLst.Dequeue();
//     }
//     return correct;
// }

// bool TestSortVec(){
//     if(output) cout<<"\n**********TEST SortVec**********\n";
//     bool correct = true;
//     lasd::Vector<int> v(genSize(gen));
//     for(ulong i{0}; i<v.Size(); i++) v[i]=genNum(gen);
//     if(output){
//         cout<<"\nVettore non ordinato: ";
//         for(ulong i{0}; i<v.Size(); i++) cout<<v[i]<<"\t";
//         cout<<endl;
//     }
//     v.Sort();
//     if(output){
//         cout<<"\nVettore ordinato: ";
//         for(ulong i{0}; i<v.Size(); i++) cout<<v[i]<<"\t";
//         cout<<endl;
//     }
//     for(ulong i{1}; i<v.Size();i++) correct&=(v[i]>=v[i-1]);
//     return correct;
// }

// bool davtest_ex1(){

//     MIN_SIZE = 0;
//     MAX_SIZE = 100;
//     MIN_NUM = INT16_MIN;
//     MAX_NUM = INT16_MAX;

//     cout<<"\n\n*********** CONFIGURAZIONE DEI TEST: ***********"<<endl;
//     cout<<"Necessiti degli output di debug?"<<endl;
//     cout<<"1. Voglio visualizzare gli output di debug. (La dimensione delle strutture sara' ridotta)."<<endl;
//     cout<<"2. No, voglio proseguire senza visualizzare gli output di debug."<<endl;
//     cout<<"Inserisci l'opzione: ";
//     int choose = -1;
//     while(choose!=1 && choose!=2) cin>>choose;
//     output = (choose==1);
//     cout<<"\nChe tipo di test vuoi eseguire?"<<endl;
//     cout<<"1. Test su casi limite (La dimensione massima delle strutture sara' impostata ad 1 in modo da forzare interazioni tra strutture vuote)"<<endl;
//     cout<<"2. Test generale (L'esecuzione puo' apparire rallentata)"<<endl;
//     cout<<"Inserisci l'opzione: ";
//     choose = -1;
//     while(choose!=1 && choose!=2) cin>>choose;
//     if(choose==1){
//         MAX_SIZE = 1;
//     }else{
//         MAX_SIZE = (output) ? 20 : 100;
//     }
//     uniform_int_distribution<int> select_genSize(MIN_SIZE,MAX_SIZE);
//     genSize = select_genSize;
//     cout<<"\nL'output sara' sospeso per velocizzare l'esecuzione se i test devono essere ripetuti piu' di 50 volte.";
//     cout<<"\nInserisci il numero di iterazioni del test (consigliato 50): ";
//     choose = -1;
//     while(choose<0) cin>>choose;

//     ITERAZIONI = choose;
//     if(ITERAZIONI>50) output=false;
//     bool total = true;

//     while(ITERAZIONI>0){

//         //VS STD
//         bool StackVSSTD = false;
//         bool QueueVSSTD = false;

//         //Sort
//         bool testSort = false;

//         //Operator==
//         bool testEqualLinear = false;
//         bool testEqualVector = false;
//         bool testEqualList = false;
//         bool testEqualStackLst = false;
//         bool testEqualStackVec = false;
//         bool testEqualQueueLst = false;
//         bool testEqualQueueVec = false;

//         //Assignement
//         bool testAssVector = false;
//         bool testAssList = false;
//         bool testAssStackLst = false;
//         bool testAssStackVec = false;
//         bool testAssQueueLst = false;
//         bool testAssQueueVec = false;

//         //Constructor
//         bool testCCVec = false;
//         bool testMCVec = false;
//         bool testCCList = false;
//         bool testMCList = false;
//         bool testCCStackVec = false;
//         bool testMCStackVec = false;
//         bool testCCStackLst = false;
//         bool testMCStackLst = false;
//         bool testCCQueueLst = false;
//         bool testMCQueueLst = false;
//         bool testCCQueueVec = false;
//         bool testMCQueueVec = false;

//         //Specific constructor (Non mutable)
//         bool testSCVecFromList = false;
//         bool testSCListFromVector = false;
//         bool testSCStackVecFromList = false;
//         bool testSCStackVecFromVector = false;
//         bool testSCStackLstFromList = false;
//         bool testSCStackLstFromVector = false;
//         bool testSCQueueVecFromList = false;
//         bool testSCQueueVecFromVector = false;
//         bool testSCQueueLstFromList = false;
//         bool testSCQueueLstFromVector = false;

//         //Specific constructor (Mutable)
//         bool testMSCVecFromList = false;
//         bool testMSCListFromVector = false;
//         bool testMSCStackVecFromList = false;
//         bool testMSCStackVecFromVector = false;
//         bool testMSCStackLstFromList = false;
//         bool testMSCStackLstFromVector = false;
//         bool testMSCQueueVecFromList = false;
//         bool testMSCQueueVecFromVector = false;
//         bool testMSCQueueLstFromList = false;
//         bool testMSCQueueLstFromVector = false;

//         if(!output) cout<<"\nComparison with STD...";
//         try { StackVSSTD = TestStackVSSTD(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { QueueVSSTD = TestQueueVSSTD(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         if(!output) cout<<"\nTesting sort...";
//         try { testSort = TestSortVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         if(!output) cout<<"\nTesting comparison operators...";
//         try { testEqualLinear = TestEqualLinear(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testEqualVector = TestEqualVector(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testEqualList = TestEqualList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testEqualStackLst = TestEqualList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testEqualStackVec = TestEqualStackVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testEqualQueueLst = TestEqualQueueLst(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testEqualQueueVec = TestEqualQueueVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         if(!output) cout<<"\nTesting assignment operators...";
//         try { testAssVector = TestAssVector(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testAssList = TestAssList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testAssStackLst = TestAssList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testAssStackVec = TestAssStackVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testAssQueueLst = TestAssQueueLst(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testAssQueueVec = TestAssQueueVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         if(!output) cout<<"\nTesting constructors...";
//         try { testCCVec = CCVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testCCList = CCLst(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testCCStackVec = CCStackVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testCCStackLst = CCStackLst(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testCCQueueLst = CCQueueLst(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testCCQueueVec = CCQueueVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
        
//         if(!output) cout<<"\nTesting move constructors...";
//         try { testMCVec = MCVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMCList = MCLst(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMCStackVec = MCStackVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMCStackLst = MCStackLst(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMCQueueLst = MCQueueLst(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMCQueueVec = MCQueueVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         if(!output) cout<<"\nTesting non-mutable specific constructors...";
//         try { testSCVecFromList = TestSCVecFromList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCListFromVector = TestSCListFromVector(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCStackVecFromList = TestSCStackVecFromList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCStackVecFromVector = TestSCStackVecFromVector(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCStackLstFromList = TestSCStackLstFromList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCStackLstFromVector = TestSCStackLstFromVector(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCQueueVecFromList = TestSCQueueVecFromList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCQueueVecFromVector = TestSCQueueVecFromVector(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCQueueLstFromList = TestSCQueueLstFromList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCQueueLstFromVector = TestSCQueueLstFromVector(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         if(!output) cout<<"\nTesting mutable specific constructors...";
//         try { testMSCVecFromList = TestMSCVecFromList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCListFromVector = TestMSCListFromVector(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCStackVecFromList = TestMSCStackVecFromList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCStackVecFromVector = TestMSCStackVecFromVector(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCStackLstFromList = TestMSCStackLstFromList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCStackLstFromVector = TestMSCStackLstFromVector(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCQueueVecFromList = TestMSCQueueVecFromList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCQueueVecFromVector = TestMSCQueueVecFromVector(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCQueueLstFromList = TestMSCQueueLstFromList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCQueueLstFromVector = TestMSCQueueLstFromVector(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }


//         if(output) {
//             cout<<"\n\n*********** RESULTS ***********"<<endl;
//             cout<<"\nCOMPARISION WITH STD:"<<endl;
//             cout<<"lasd::StackVec == lasd::StackLst == std::Stack: "<<((StackVSSTD) ? "Corretto" : "Errore")<<endl;
//             cout<<"lasd::QueueVec == lasd::QueueLst == std::Queue: "<<((QueueVSSTD) ? "Corretto" : "Errore")<<endl;

//             cout<<"\nSORT:"<<endl;
//             cout<<"Vector: "<<((testSort) ? "Corretto" : "Errore")<<endl;

//             cout<<"\nCOMPARISION OPERATORS:"<<endl;
//             cout<<"Linear == Linear: "<<((testEqualLinear) ? "Corretto" : "Errore")<<endl;
//             cout<<"Vector == Vector: "<<((testEqualVector) ? "Corretto" : "Errore")<<endl;
//             cout<<"List == List: "<<((testEqualList) ? "Corretto" : "Errore")<<endl;
//             cout<<"StackLst == Stacklst: "<<((testEqualStackLst) ? "Corretto" : "Errore")<<endl;
//             cout<<"StackVec == StackVec: "<<((testEqualStackVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"QueueVec == QueueVec: "<<((testEqualQueueLst) ? "Corretto" : "Errore")<<endl;
//             cout<<"QueueLst == QueueLst: "<<((testEqualQueueVec) ? "Corretto" : "Errore")<<endl;

//             cout<<"\nASSIGNAMENT OPERATORS:"<<endl;
//             cout<<"Vector = Vector: "<<((testAssVector) ? "Corretto" : "Errore")<<endl;
//             cout<<"List = List: "<<((testAssList) ? "Corretto" : "Errore")<<endl;
//             cout<<"StackLst = Stacklst: "<<((testAssStackLst) ? "Corretto" : "Errore")<<endl;
//             cout<<"StackVec = StackVec: "<<((testAssStackVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"QueueVec = QueueVec: "<<((testAssQueueLst) ? "Corretto" : "Errore")<<endl;
//             cout<<"QueueLst = QueueLst: "<<((testAssQueueVec) ? "Corretto" : "Errore")<<endl;

//             cout<<"\nCOPY CONSTRUCTORS: "<<endl;
//             cout<<"Vector(Vector): "<<((testCCVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"List(List): "<<((testCCList) ? "Corretto" : "Errore")<<endl;
//             cout<<"StackVec(StackVec): "<<((testCCStackVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"StackLst(StackLst): "<<((testCCStackLst) ? "Corretto" : "Errore")<<endl;
//             cout<<"QueueLst(QueueLst): "<<((testCCQueueLst) ? "Corretto" : "Errore")<<endl;
//             cout<<"QueueVec(QueueVec): "<<((testCCQueueVec) ? "Corretto" : "Errore")<<endl;

//             cout<<"\nMOVE CONSTRUCTORS: "<<endl;
//             cout<<"Vector(move(Vector)): "<<((testMCVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"List(move(List)): "<<((testMCList) ? "Corretto" : "Errore")<<endl;
//             cout<<"StackVec(move(StackVec)): "<<((testMCStackVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"StackLst(move(StackLst)): "<<((testMCStackLst) ? "Corretto" : "Errore")<<endl;
//             cout<<"QueueLst(move(QueueLst)): "<<((testMCQueueLst) ? "Corretto" : "Errore")<<endl;
//             cout<<"QueueVec(move(QueueVec)): "<<((testMCQueueVec) ? "Corretto" : "Errore")<<endl;
            
//             cout<<"\nSPECIFIC NON-MUTABLE SPECIFIC CONSTRUCTORS: "<<endl;
//             cout<<"Vector(List): "<<((testSCVecFromList) ? "Corretto" : "Errore")<<endl;
//             cout<<"List(Vector): "<<((testSCListFromVector) ? "Corretto" : "Errore")<<endl;
//             cout<<"StackVec(Vector): "<<((testSCStackVecFromVector) ? "Corretto" : "Errore")<<endl;
//             cout<<"StackVec(List): "<<((testSCStackVecFromList) ? "Corretto" : "Errore")<<endl;
//             cout<<"StackLst(Vector): "<<((testSCStackLstFromVector) ? "Corretto" : "Errore")<<endl;
//             cout<<"StackLst(List): "<<((testSCStackLstFromList) ? "Corretto" : "Errore")<<endl;
//             cout<<"QueueLst(Vector): "<<((testSCQueueLstFromVector) ? "Corretto" : "Errore")<<endl;
//             cout<<"QueueLst(List): "<<((testSCQueueLstFromList) ? "Corretto" : "Errore")<<endl;
//             cout<<"QueueVec(Vector): "<<((testSCQueueVecFromVector) ? "Corretto" : "Errore")<<endl;
//             cout<<"QueueVec(List): "<<((testSCQueueVecFromList) ? "Corretto" : "Errore")<<endl;

//             cout<<"\nSPECIFIC MUTABLE SPECIFIC CONSTRUCTORS: "<<endl;
//             cout<<"Vector(List): "<<((testMSCVecFromList) ? "Corretto" : "Errore")<<endl;
//             cout<<"List(Vector): "<<((testMSCListFromVector) ? "Corretto" : "Errore")<<endl;
//             cout<<"StackVec(Vector): "<<((testMSCStackVecFromVector) ? "Corretto" : "Errore")<<endl;
//             cout<<"StackVec(List): "<<((testMSCStackVecFromList) ? "Corretto" : "Errore")<<endl;
//             cout<<"StackLst(Vector): "<<((testMSCStackLstFromVector) ? "Corretto" : "Errore")<<endl;
//             cout<<"StackLst(List): "<<((testMSCStackLstFromList) ? "Corretto" : "Errore")<<endl;
//             cout<<"QueueLst(Vector): "<<((testMSCQueueLstFromVector) ? "Corretto" : "Errore")<<endl;
//             cout<<"QueueLst(List): "<<((testMSCQueueLstFromList) ? "Corretto" : "Errore")<<endl;
//             cout<<"QueueVec(Vector): "<<((testMSCQueueVecFromVector) ? "Corretto" : "Errore")<<endl;
//             cout<<"QueueVec(List): "<<((testMSCQueueVecFromList) ? "Corretto" : "Errore")<<endl;
//         }

//         if (StackVSSTD && QueueVSSTD && testSort && testEqualLinear && testEqualVector && testEqualList && testEqualStackLst 
//             && testEqualStackVec && testEqualQueueLst && testEqualQueueVec && testAssVector && testAssList && testAssStackLst 
//             && testAssStackVec && testAssQueueLst && testAssQueueVec && testCCVec && testMCVec && testCCList && testMCList 
//             && testCCStackVec && testMCStackVec && testCCStackLst && testMCStackLst && testCCQueueLst && testMCQueueLst 
//             && testCCQueueVec && testMCQueueVec && testSCVecFromList && testSCListFromVector && testSCStackVecFromList 
//             && testSCStackVecFromVector && testSCStackLstFromList && testSCStackLstFromVector && testSCQueueVecFromList 
//             && testSCQueueVecFromVector && testSCQueueLstFromList && testSCQueueLstFromVector && testMSCVecFromList 
//             && testMSCListFromVector && testMSCStackVecFromList && testMSCStackVecFromVector && testMSCStackLstFromList 
//             && testMSCStackLstFromVector && testMSCQueueVecFromList && testMSCQueueVecFromVector && testMSCQueueLstFromList 
//             && testMSCQueueLstFromVector
//         )
//         {
//             total&=true;
//         } else {
//             total&=false;
//         }

//         if(!total) break;

//         ITERAZIONI--;
//     }

//     if(total==true){
//         cout<<"\nTUTTI I TEST SONO STATI SUPERATI!! :D ";
//     }else{
//         cout<<"\nCi sono test che non sono stati superati :(";
//     }

//     cout<<endl;

//     return true;
// }


// /************************************************************************************************



//  *          INIZIO TEST SU BT



// *************************************************************************************************/



// bool TestEqualBT(){
//     if(output) cout<<"\n**********TEST TestEqualBT**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen)+1;
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++){
//         int temp_num = genNum(gen);
//         v1[i]=temp_num;
//     } 
//     lasd::BinaryTreeLnk<int> s1(v1);
//     lasd::BinaryTreeVec<int> s2(v1);
//     if(output) { 
//         cout<<"\nS1: ";
//         s1.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     if(output) { 
//         cout<<"\nS2: ";
//         s2.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     correct&=(s1.BinaryTree<int>::operator==(s2));
//     v1[genSize(gen)%temp_size]=genNum(gen);
//     lasd::BinaryTreeVec<int> s3(v1);
//     correct&=(s1.BinaryTree<int>::operator!=(s3));
//     s1.Clear();
//     s2.Clear();
//     correct&=(s1.BinaryTree<int>::operator==(s2));
//     return correct;
// }

// bool TestEqualBTLnk(){
//     if(output) cout<<"\n**********TEST TestEqualBTLnk**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen)+1;
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++){
//         int temp_num = genNum(gen);
//         v1[i]=temp_num;
//     } 
//     lasd::BinaryTreeLnk<int> s1(v1);
//     lasd::BinaryTreeLnk<int> s2(v1);
//     v1[genSize(gen)%temp_size]=genNum(gen);
//     lasd::BinaryTreeLnk<int> s3(v1);
//     if(output) { 
//         cout<<"\nS1: ";
//         s1.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     if(output) { 
//         cout<<"\nS2: ";
//         s2.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     if(output) { 
//         cout<<"\nS2: ";
//         s3.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     correct&=(s1==s2);
//     correct&=(s1!=s3);
//     s2.Clear();
//     correct&=(s1!=s2);
//     s1.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestEqualBTVec(){
//     if(output) cout<<"\n**********TEST TestEqualBTVec**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen)+1;
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++){
//         int temp_num = genNum(gen);
//         v1[i]=temp_num;
//     } 
//     lasd::BinaryTreeVec<int> s1(v1);
//     lasd::BinaryTreeVec<int> s2(v1);
//     v1[genSize(gen)%temp_size]=genNum(gen);
//     lasd::BinaryTreeVec<int> s3(v1);
//     if(output) { 
//         cout<<"\nS1: ";
//         s1.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     if(output) { 
//         cout<<"\nS2: ";
//         s2.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//         if(output) { 
//         cout<<"\nS1: ";
//         s1.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     if(output) { 
//         cout<<"\nS3: ";
//         s2.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     correct&=(s1==s2);
//     correct&=(s1!=s3);
//     s2.Clear();
//     correct&=(s1!=s2);
//     s1.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestEqualBST(){
//     if(output) cout<<"\n**********TEST TestEqualBST**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen)+1;
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++){
//         int temp_num = genNum(gen);
//         v1[i]=temp_num;
//     } 
//     lasd::BST<int> s1(v1);
//     lasd::BST<int> s2(v1);
//     v1[genSize(gen)%temp_size]=genNum(gen);
//     lasd::BST<int> s3(v1);
//     correct&=(s1==s2);
//     correct&=(s1!=s3);
//     s2.Clear();
//     correct&=(s1!=s2);
//     s1.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestAssBTVec(){
//     if(output) cout<<"\n**********TEST TestAssBTVec**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++) v1[i]=genNum(gen);
//     lasd::BinaryTreeVec<int> s1(v1);
//     lasd::BinaryTreeVec<int> s2;
//     s2 = s1;
//     if(output) { 
//         cout<<"\nS1: ";
//         s1.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     if(output) { 
//         cout<<"\nS2: ";
//         s2.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     correct&=(s1==s2);
//     s2.Clear();
//     s1.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestAssBTLnk(){
//     if(output) cout<<"\n**********TEST TestAssBTLnk**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++) v1[i]=genNum(gen);
//     lasd::BinaryTreeLnk<int> s1(v1);
//     lasd::BinaryTreeLnk<int> s2;
//     s2 = s1;
//     if(output) { 
//         cout<<"\nS1: ";
//         s1.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     if(output) { 
//         cout<<"\nS2: ";
//         s2.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     correct&=(s1==s2);
//     s2.Clear();
//     s1.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestAssBST(){
//     if(output) cout<<"\n**********TEST TestAssBST**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++) v1[i]=genNum(gen);
//     lasd::BST<int> s1(v1);
//     lasd::BST<int> s2;
//     s2 = s1;
//     correct&=(s1==s2);
//     s2.Clear();
//     s1.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestMAssBTVec(){
//     if(output) cout<<"\n**********TEST TestMAssBTVec**********\n";
//     bool correct=true;
//     int temp_size1 = genSize(gen)+1;
//     int temp_size2 = genSize(gen)+1;
//     lasd::Vector<int> v1(temp_size1);
//     lasd::Vector<int> v2(temp_size2);
//     for(int i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     for(int i=0; i<v2.Size(); i++) v2[i]=genNum(gen);
//     lasd::BinaryTreeVec<int> s1(v1);
//     int r1 = s1.Root().Element();
//     if(output) { 
//         cout<<"\nS1: ";
//         s1.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     lasd::BinaryTreeVec<int> s2(v2);
//     if(output) { 
//         cout<<"\nS2: ";
//         s2.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     int r2 = s2.Root().Element();

//     if(output) cout<<"\ns1.root(): "<<r1<<"\ts2.Root(): "<<r2;
//     lasd::BinaryTreeVec<int> s3(v1);
//     lasd::BinaryTreeVec<int> s4(v2);
//     lasd::BinaryTreeVec<int> s5;
//     s2 = move(s1);
//     if(output) cout<<"\ns1.root(): "<<s1.Root().Element()<<"\ts2.Root(): "<<s2.Root().Element()<<"\n";
//     correct&= (s2.Root().Element() == r1);
//     correct&=(s1==s4);
//     s1.Map(
//         [](int& dat){
//             dat+=dat;
//         }
//     );
//     correct&=(s1!=s4);
//     correct&=(s2==s3);
//     s1 = move(s5);
//     correct&=(s1.Empty());
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestMAssBTLnk(){
//     if(output) cout<<"\n**********TEST TestMAssBTLnk**********\n";
//     bool correct=true;
//     int temp_size1 = genSize(gen)+1;
//     int temp_size2 = genSize(gen)+1;
//     lasd::Vector<int> v1(temp_size1);
//     lasd::Vector<int> v2(temp_size2);
//     for(int i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     for(int i=0; i<v2.Size(); i++) v2[i]=genNum(gen);
//     lasd::BinaryTreeLnk<int> s1(v1);
//     if(output) { 
//         cout<<"\nV1: ";
//         v1.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     if(output) { 
//         cout<<"\nV2: ";
//         v2.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     int r1 = s1.Root().Element();
//     lasd::BinaryTreeLnk<int> s2(v2);
//     int r2 = s2.Root().Element();
//     lasd::BinaryTreeLnk<int> s3(v1);
//     lasd::BinaryTreeLnk<int> s4(v2);
//     lasd::BinaryTreeLnk<int> s5;
//     s2 = move(s1);
//     if(output) { 
//         cout<<"\nS1: ";
//         s1.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     if(output) { 
//         cout<<"\nS2: ";
//         s2.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     correct&= (s2.Root().Element() == r1);
//     correct&=(s1==s4);
//     s1.Map(
//         [](int& dat){
//             dat+=dat;
//         }
//     );
//     correct&=(s1!=s4);
//     correct&=(s2==s3);
//     s1 = move(s5);
//     correct&=(s1.Empty());
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestMAssBST(){
//     if(output) cout<<"\n**********TEST TestMAssBST**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++){
//         v1[i]=genNum(gen);
//     }
//     lasd::BST<int> s1(v1);
//     lasd::BST<int> s2;
//     s2 = move(s1);
//     correct&=(s1.Empty());
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool CCBTLnk(){
//     if(output) cout<<"\n**********TEST CCBTLnk**********\n";
//     bool correct=true;
//     lasd::Vector<int> v1(genSize(gen));
//     for(ulong i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     lasd::BinaryTreeLnk<int> s1(v1);
//     lasd::BinaryTreeLnk<int> s2(s1);
//     if(output) { 
//         cout<<"\nS1: ";
//         s1.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     if(output) { 
//         cout<<"\nS2: ";
//         s2.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     correct&=(s1==s2);
//     s1.Clear();
//     correct&=(s1.Empty());
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool CCBTVec(){
//     if(output) cout<<"\n**********TEST CCBTVec**********\n";
//     bool correct=true;
//     lasd::Vector<int> v1(genSize(gen));
//     for(ulong i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     lasd::BinaryTreeVec<int> s1(v1);
//     lasd::BinaryTreeVec<int> s2(s1);
//     correct&=(s1==s2);
//     if(output) { 
//         cout<<"\nS1: ";
//         s1.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     if(output) { 
//         cout<<"\nS2: ";
//         s2.Map( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     s1.Clear();
//     correct&=(s1.Empty());
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool CCBST(){
//     if(output) cout<<"\n**********TEST CCBST**********\n";
//     bool correct=true;
//     lasd::Vector<int> v1(genSize(gen));
//     for(ulong i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     lasd::BST<int> s1(v1);
//     lasd::BST<int> s2(s1);
//     correct&=(s1==s2);
//     s1.Clear();
//     correct&=(s1.Empty());
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool MCBTLnk(){
//     if(output) cout<<"\n**********TEST MCBTLnk**********\n";
//     bool correct=true;
//     int temp_size1 = genSize(gen);
//     lasd::Vector<int> v1(temp_size1);
//     for(int i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     lasd::BinaryTreeLnk<int> s1(v1);
//     lasd::BinaryTreeLnk<int> s2(v1);
//     lasd::BinaryTreeLnk<int> s3(move(s1));
//     correct&=(s1.Empty());
//     correct&=(s2==s3);
//     s3.Clear();
//     correct&=(s3.Empty());
//     s2.Clear();
//     correct&=(s3==s2);
//     return correct;
// }

// bool MCBTVec(){
//     if(output) cout<<"\n**********TEST MCBTVec**********\n";
//     bool correct=true;
//     int temp_size1 = genSize(gen);
//     lasd::Vector<int> v1(temp_size1);
//     for(int i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     lasd::BinaryTreeVec<int> s1(v1);
//     lasd::BinaryTreeVec<int> s2(v1);
//     lasd::BinaryTreeVec<int> s3(move(s1));
//     correct&=(s1.Empty());
//     correct&=(s2==s3);
//     s3.Clear();
//     correct&=(s3.Empty());
//     s2.Clear();
//     correct&=(s3==s2);
//     return correct;
// }

// bool MCBST(){
//     if(output) cout<<"\n**********TEST MCBST**********\n";
//     bool correct=true;
//     lasd::Vector<int> v1(genSize(gen));
//     for(int i=0; i<v1.Size(); i++)v1[i]=genNum(gen);
//     lasd::BST<int> s1(v1);
//     lasd::BST<int> s2(move(s1));
//     lasd::BST<int> s3(v1);
//     correct&=(s1.Empty());
//     correct&=(s2==s3);
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool MSCBTVecVec(){
//     if(output) cout<<"\n**********TEST MSCBTVecVec**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::Vector<int> l1(temp_size);
//     lasd::Vector<int> l2(temp_size);
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         l1[i]=temp_num;
//         l2[i]=temp_num;
//     }
//     lasd::BinaryTreeVec<int> s1(move(l1));
//     lasd::BTBreadthIterator<int> itr(s1);
//     l2.PreOrderMap(
//         [&correct, &itr](const int& dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     return correct;
// }


// bool MSCBTVecLst(){
//     if(output) cout<<"\n**********TEST MSCBTVecLst**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     lasd::List<int> l2;
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         l1.Insert(temp_num);
//         l2.Insert(temp_num);
//     }
//     lasd::BinaryTreeVec<int> s1(move(l1));
//     lasd::BTBreadthIterator<int> itr(s1);
//     l2.PreOrderMap(
//         [&correct, &itr](const int& dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     return correct;
// }

// bool MSCBTLnkVec(){
//     if(output) cout<<"\n**********TEST MSCBTLnkVec**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::Vector<int> l1(temp_size);
//     lasd::Vector<int> l2(temp_size);
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         l1[i]=temp_num;
//         l2[i]=temp_num;
//     }
//     lasd::BinaryTreeLnk<int> s1(move(l1));
//     lasd::BTBreadthIterator<int> itr(s1);
//     l2.PreOrderMap(
//         [&correct, &itr](const int& dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     return correct;
// }

// bool MSCBTLnkLst(){
//     if(output) cout<<"\n**********TEST MSCBTLnkLst**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     lasd::List<int> l2;
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         l1.Insert(temp_num);
//         l2.Insert(temp_num);
//     }
//     lasd::BinaryTreeLnk<int> s1(move(l1));
//     lasd::BTBreadthIterator<int> itr(s1);
//     l2.PreOrderMap(
//         [&correct, &itr](const int& dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     return correct;
// }

// bool MSCBSTVec(){
//     if(output) cout<<"\n**********TEST MSCBSTVec**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::Vector<int> l1(temp_size);
//     lasd::Vector<int> l2(temp_size);
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         l1[i]=temp_num;
//         l2[i]=temp_num;
//     }
//     lasd::BST<int> s1(move(l1));
//     l2.PreOrderMap(
//         [&correct, &s1](const int& dat){
//             correct&=s1.Exists(dat);
//         }
//     );
//     return correct;
// }

// bool MSCBSTLst(){
//     if(output) cout<<"\n**********TEST MSCBSTLst**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     lasd::List<int> l2;
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         l1.Insert(temp_num);
//         l2.Insert(temp_num);
//     }
//     lasd::BST<int> s1(move(l1));
//     l2.PostOrderMap(
//         [&correct, &s1](const int& dat){
//             correct&=s1.Exists(dat);
//         }
//     );
//     return correct;
// }

// template <typename Data>
// bool SCBTLnk(const lasd::MappableContainer<Data>* cont){
//     const lasd::BinaryTreeLnk<int> s1(*cont);
//     bool correct=true;
//     lasd::BTBreadthIterator<int> itr(s1);
//     (*cont).Map(
//         [&correct, &itr](const Data& dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     return correct;
// }

// bool SCBTLnkVec(){
//     if(output) cout<<"\n**********TEST SCBTLnkVec**********\n";
//     bool correct=true;
//     lasd::Vector<int> s1(genSize(gen));
//     for(int i=0; i<s1.Size(); i++)s1[i]=genNum(gen);
//     const lasd::Vector<int>s2(s1);
//     correct&=(SCBTLnk(&s1));
//     return correct;
// }

// bool SCBTLnkLst(){
//     if(output) cout<<"\n**********TEST SCBTLnkLst**********\n";
//     bool correct=true;
//     lasd::List<int> s1;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) s1.Insert(genNum(gen));
//     const lasd::List<int>s2(s1);
//     correct&=SCBTLnk(&s2);
//     return correct;
// }

// template <typename Data>
// bool SCBTVec(const lasd::MappableContainer<Data>* cont){
//     const lasd::BinaryTreeVec<int> s1(*cont);
//     bool correct=true;
//     lasd::BTBreadthIterator<int> itr(s1);
//     (*cont).Map(
//         [&correct, &itr](const Data& dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     return correct;
// }

// bool SCBTVecVec(){
//     if(output) cout<<"\n**********TEST SCBTVecVec**********\n";
//     bool correct=true;
//     lasd::Vector<int> s1(genSize(gen));
//     for(int i=0; i<s1.Size(); i++)s1[i]=genNum(gen);
//     const lasd::Vector<int>s2(s1);
//     correct&=(SCBTVec(&s2));
//     return correct;
// }

// bool SCBTVecLst(){
//     if(output) cout<<"\n**********TEST SCBTVecLst**********\n";
//     bool correct=true;
//     lasd::List<int> s1;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) s1.Insert(genNum(gen));
//     const lasd::List<int>s2(s1);
//     correct&=SCBTVec(&s2);
//     return correct;
// }

// template <typename Data>
// bool SCBST(const lasd::MappableContainer<Data>* cont){
//     const lasd::BST<int> s1(*cont);
//     bool correct=true;
//     (*cont).Map(
//         [&correct, &s1](const Data& dat){
//             correct&=s1.Exists(dat);
//         }
//     );
//     return correct;
// }

// bool SCBSTVec(){
//     if(output) cout<<"\n**********TEST SCBSTVec**********\n";
//     bool correct=true;
//     lasd::Vector<int> s1(genSize(gen));
//     for(int i=0; i<s1.Size(); i++) s1[i]=genNum(gen);
//     const lasd::Vector<int>s2(s1);
//     correct&=(SCBST(&s2));
//     return correct;
// }

// bool SCBSTLst(){
//     if(output) cout<<"\n**********TEST SCBSTLst**********\n";
//     bool correct=true;
//     lasd::List<int> s1;
//     int temp_size = genSize(gen);
//     for(int i=0; i<temp_size; i++) s1.Insert(genNum(gen));
//     const lasd::List<int>s2(s1);
//     correct&=SCBST(&s2);
//     return correct;
// }

// bool TestBSTMax(){
//     if(output) cout<<"\n**********TEST TestBSTMax**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::Vector<int> v1(temp_size);
//     lasd::List<int> l1;
//     for(int i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     v1.Sort();
//     for(int i{0}; i<v1.Size(); i++) l1.Insert(v1[i]);
//     temp_size = l1.Size();
//     lasd::BST<int> bst(l1);
//     if(output) { 
//         cout<<"\nSorted list1: ";
//         l1.PostOrderMap( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     temp_size--;
//     if(output) cout<<"\nBST: ";
//     while(!(bst.Empty())){
//         if(output) cout<<"\t"<<bst.Max();
//         correct&=(bst.MaxNRemove()==l1[temp_size--]);
//     }
//     return correct;
// }

// bool TestBSTMin(){
//     if(output) cout<<"\n**********TEST TestBSTMin**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::Vector<int> v1(temp_size);
//     lasd::List<int> l1;
//     for(int i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     v1.Sort();
//     for(int i{0}; i<v1.Size(); i++) l1.Insert(v1[i]);
//     temp_size = l1.Size();
//     lasd::BST<int> bst(l1);
//     if(output) { 
//         cout<<"\nSorted list1: ";
//         l1.PostOrderMap( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     int cursor=0 ;
//     if(output) cout<<"\nBST: ";
//     while(!(bst.Empty())){
//         if(output) cout<<"\t"<<bst.Min();
//         correct&=(bst.MinNRemove()==l1[cursor++]);
//     }
//     return correct;
// }

// bool TestBSTPred(){
//     if(output) cout<<"\n**********TEST TestBSTPred**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::Vector<int> v1(temp_size);
//     lasd::List<int> l1;
//     for(int i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     v1.Sort();
//     for(int i{0}; i<v1.Size(); i++) l1.Insert(v1[i]);
//     temp_size = l1.Size();
//     lasd::BST<int> bst(l1);
//     if(output) { 
//         cout<<"\nSorted list1: ";
//         l1.PostOrderMap( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     temp_size--;
//     if(bst.Size()>3) correct&= ((bst.Predecessor(bst.Min()+1))==bst.Min());
//     if(bst.Size()>3) correct&= (bst.Successor(bst.Predecessor(bst.Max()))==bst.Max());
//     if(output) cout<<"\nBST: ";
//     while(bst.Size()>1){
//         if(output) cout<<"\t"<<bst.Predecessor(l1[temp_size]);
//         correct&=(bst.PredecessorNRemove(l1[temp_size])==l1[temp_size-1]);
//         temp_size--;
//     }
//     return correct;
// }

// bool TestBSTSucc(){
//     if(output) cout<<"\n**********TEST TestBSTSucc**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::Vector<int> v1(temp_size);
//     lasd::List<int> l1;
//     for(int i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     v1.Sort();
//     for(int i{0}; i<v1.Size(); i++) l1.Insert(v1[i]);
//     temp_size = l1.Size();
//     lasd::BST<int> bst(l1);
//     if(output) { 
//         cout<<"\nSorted list1: ";
//         l1.PostOrderMap( [](int& dat){ cout<<"\t"<<dat; } );
//     }
//     if(bst.Size()>3) correct&= (bst.Successor((bst.Max()-1))==bst.Max());
//     if(bst.Size()>3) correct&= (bst.Predecessor(bst.Successor(bst.Min()))==bst.Min());
//     if(output) cout<<"\nBST: ";
//     int cursor = 0;
//     while(bst.Size()>1){
//         if(output) cout<<"\t"<<bst.Successor(l1[cursor]);
//         correct&=(bst.SuccessorNRemove(l1[cursor])==l1[cursor+1]);
//         cursor++;
//     }
//     return correct;
// }

// void MapPrint(int value){
//   cout<<"\t"<<value;
// }

// bool TestMapsBTLnk(){
//     cout<<"\n**********TEST TestMapsBTLnk**********\n";
//     lasd::Vector<int> v1(genSize(gen));
//     for(int i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     cout<<"\nVettore: ";
//     v1.PreOrderMap(MapPrint);
//     lasd::BinaryTreeLnk<int> bt(v1);
//     cout<<"\nBTLnk:\n";
//     cout<<"\nPreOrderMap: ";
//     bt.PreOrderMap(MapPrint);
//     cout<<"\nPostOrderMap: ";
//     bt.PostOrderMap(MapPrint);
//     cout<<"\nInOrderMap: ";
//     bt.InOrderMap(MapPrint);
//     cout<<"\nBreadthMap: ";
//     bt.BreadthMap(MapPrint);
//     cout<<endl<<"Si prega di verificare l'esattezza delle map e comunicarne il risultato:\n1. Le map sono corrette\n2. Una o piu' map non sono corrette.\nInserisci l'opzione: ";
//     int choose = -1;
//     while(choose!=1 && choose!=2) cin>>choose;
//     return (choose==1);
// }

// bool TestMapsBTVec(){
//     cout<<"\n**********TEST TestMapsBTVec**********\n";
//     lasd::Vector<int> v1(genSize(gen));
//     for(int i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     cout<<"\nVettore: ";
//     v1.PreOrderMap(MapPrint);
//     lasd::BinaryTreeVec<int> bt(v1);
//     cout<<"\nBTVec:\n";
//     cout<<"\nPreOrderMap: ";
//     bt.PreOrderMap(MapPrint);
//     cout<<"\nPostOrderMap: ";
//     bt.PostOrderMap(MapPrint);
//     cout<<"\nInOrderMap: ";
//     bt.InOrderMap(MapPrint);
//     cout<<"\nBreadthMap: ";
//     bt.BreadthMap(MapPrint);
//     cout<<endl<<"Si prega di verificare l'esattezza delle map e comunicarne il risultato:\n1. Le map sono corrette.\n2. Una o piu' map non sono corrette.\nInserisci l'opzione: ";
//     int choose = -1;
//     while(choose!=1 && choose!=2) cin>>choose;
//     return (choose==1);
// }

// bool TestMapsBST(){
//     cout<<"\n**********TEST TestMapsBST**********\n";
//     lasd::Vector<int> v1(genSize(gen));
//     for(int i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     cout<<"\nVettore: ";
//     v1.PreOrderMap(MapPrint);
//     const lasd::BST<int> bt(v1);
//     cout<<"\nBST:\n";
//     cout<<"\nPreOrderMap: ";
//     bt.PreOrderMap(MapPrint);
//     cout<<"\nPostOrderMap: ";
//     bt.PostOrderMap(MapPrint);
//     cout<<"\nInOrderMap: ";
//     bt.InOrderMap(MapPrint);
//     cout<<"\nBreadthMap: ";
//     bt.BreadthMap(MapPrint);
//     cout<<endl<<"Si prega di verificare l'esattezza delle map e comunicarne il risultato:\n1. Le map sono corrette.\n2. Una o piu' map non sono corrette.\nInserisci l'opzione: ";
//     int choose = -1;
//     while(choose!=1 && choose!=2) cin>>choose;
//     return (choose==1);
// }

// bool TestInsertRemoveBST(){
//     bool correct = true;
//     lasd::Vector<int> v1(genSize(gen));
//     for(int i{0}; i<v1.Size(); i++) v1[i]=genNum(gen);
//     lasd::BST<int> bst(v1);
//     int actual_size = bst.Size();
//     for(int i{0}; i<v1.Size(); i++){
//         if(genNum(gen)%2==0) if(bst.Insert(genNum(gen))) actual_size++;
//         else {
//             while(!(bst.Remove(genNum(gen)))) ;
//             actual_size--;
//         }
//     }
//     correct&=(actual_size==bst.Size());
//     bst.Clear();
//     correct&=(!(bst.Remove(genNum(gen))));
//     correct&=(bst.Insert(genNum(gen)));
//     return correct;
// }

// bool TestPreOrdItrLnk(){
//     if(output)cout<<"\n**********TEST TestPreOrdItrLnk**********\n";
//     bool correct = true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     for(int i{0}; i<temp_size; i++) l1.Insert(genNum(gen));
//     temp_size = l1.Size();
//     lasd::BinaryTreeLnk<int> bt(l1);
//     lasd::BTPreOrderIterator<int> itr(bt);
//     bt.PreOrderMap(
//         [&itr, &correct](const int dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     itr.Reset();
//     bt.PreOrderMap(
//         [&itr, &correct](const int dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     try{ *itr; correct=false; } catch (const std::out_of_range& e) { correct&=true; }
//     try{ ++itr; correct=false; } catch (const std::out_of_range& e) { correct&=true; }
//     return correct;
// }

// bool TestPostOrdItrLnk(){
//     if(output)cout<<"\n**********TEST TestPostOrdItrLnk**********\n";
//     bool correct = true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     for(int i{0}; i<temp_size; i++) l1.Insert(genNum(gen));
//     temp_size = l1.Size();
//     lasd::BinaryTreeLnk<int> bt(l1);
//     lasd::BTPostOrderIterator<int> itr(bt);
//     bt.PostOrderMap(
//         [&itr, &correct](const int dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     itr.Reset();
//     bt.PostOrderMap(
//         [&itr, &correct](const int dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     try{ *itr; correct=false; } catch (const std::out_of_range& e) { correct&=true; }
//     try{ ++itr; correct=false; } catch (const std::out_of_range& e) { correct&=true; }
//     return correct;
// }

// bool TestInOrdItrLnk(){
//     if(output)cout<<"\n**********TEST TestInOrdItrLnk**********\n";
//     bool correct = true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     for(int i{0}; i<temp_size; i++) l1.Insert(genNum(gen));
//     temp_size = l1.Size();
//     lasd::BinaryTreeLnk<int> bt(l1);
//     lasd::BTInOrderIterator<int> itr(bt);
//     bt.InOrderMap(
//         [&itr, &correct](const int dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     itr.Reset();
//     bt.InOrderMap(
//         [&itr, &correct](const int dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     try{ *itr; correct=false; } catch (const std::out_of_range& e) { correct&=true; }
//     try{ ++itr; correct=false; } catch (const std::out_of_range& e) { correct&=true; }
//     return correct;
// }

// bool TestBreadthItrLnk(){
//     if(output)cout<<"\n**********TEST TestBreadthItrLnk**********\n";
//     bool correct = true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     for(int i{0}; i<temp_size; i++) l1.Insert(genNum(gen));
//     temp_size = l1.Size();
//     lasd::BinaryTreeLnk<int> bt(l1);
//     lasd::BTBreadthIterator<int> itr(bt);
//     bt.BreadthMap(
//         [&itr, &correct](const int dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     itr.Reset();
//     bt.BreadthMap(
//         [&itr, &correct](const int dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     try{ *itr; correct=false; } catch (const std::out_of_range& e) { correct&=true; }
//     try{ ++itr; correct=false; } catch (const std::out_of_range& e) { correct&=true; }
//     return correct;
// }

// bool TestPreOrdItrVec(){
//     if(output)cout<<"\n**********TEST TestPreOrdItrVec**********\n";
//     bool correct = true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     for(int i{0}; i<temp_size; i++) l1.Insert(genNum(gen));
//     temp_size = l1.Size();
//     lasd::BinaryTreeVec<int> bt(l1);
//     lasd::BTPreOrderIterator<int> itr(bt);
//     bt.PreOrderMap(
//         [&itr, &correct](const int dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     itr.Reset();
//     bt.PreOrderMap(
//         [&itr, &correct](const int dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     try{ *itr; correct=false; } catch (const std::out_of_range& e) { correct&=true; }
//     try{ ++itr; correct=false; } catch (const std::out_of_range& e) { correct&=true; }
//     return correct;
// }

// bool TestPostOrdItrVec(){
//     if(output)cout<<"\n**********TEST TestPostOrdItrVec**********\n";
//     bool correct = true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     for(int i{0}; i<temp_size; i++) l1.Insert(genNum(gen));
//     temp_size = l1.Size();
//     lasd::BinaryTreeVec<int> bt(l1);
//     lasd::BTPostOrderIterator<int> itr(bt);
//     bt.PostOrderMap(
//         [&itr, &correct](const int dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     itr.Reset();
//     bt.PostOrderMap(
//         [&itr, &correct](const int dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     try{ *itr; correct=false; } catch (const std::out_of_range& e) { correct&=true; }
//     try{ ++itr; correct=false; } catch (const std::out_of_range& e) { correct&=true; }
//     return correct;
// }

// bool TestInOrdItrVec(){
//     if(output)cout<<"\n**********TEST TestInOrdItrVec**********\n";
//     bool correct = true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     for(int i{0}; i<temp_size; i++) l1.Insert(genNum(gen));
//     temp_size = l1.Size();
//     lasd::BinaryTreeVec<int> bt(l1);
//     lasd::BTInOrderIterator<int> itr(bt);
//     bt.InOrderMap(
//         [&itr, &correct](const int dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     itr.Reset();
//     bt.InOrderMap(
//         [&itr, &correct](const int dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     try{ *itr; correct=false; } catch (const std::out_of_range& e) { correct&=true; }
//     try{ ++itr; correct=false; } catch (const std::out_of_range& e) { correct&=true; }
//     return correct;
// }

// bool TestBreadthItrVec(){
//     if(output)cout<<"\n**********TEST TestBreadthItrVec**********\n";
//     bool correct = true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     for(int i{0}; i<temp_size; i++) l1.Insert(genNum(gen));
//     temp_size = l1.Size();
//     lasd::BinaryTreeVec<int> bt(l1);
//     lasd::BTBreadthIterator<int> itr(bt);
//     bt.BreadthMap(
//         [&itr, &correct](const int dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     itr.Reset();
//     bt.BreadthMap(
//         [&itr, &correct](const int dat){
//             correct&= ((*itr)==dat);
//             ++itr;
//         }
//     );
//     try{ *itr; correct=false; } catch (const std::out_of_range& e) { correct&=true; }
//     try{ ++itr; correct=false; } catch (const std::out_of_range& e) { correct&=true; }
//     return correct;
// }

// bool davtest_ex2(){

//     MIN_SIZE = 0;
//     MAX_SIZE = 100;
//     MIN_NUM = INT16_MIN;
//     MAX_NUM = INT16_MAX;

//     cout<<"\n\n*********** CONFIGURAZIONE DEI TEST: ***********"<<endl;
//     cout<<"Necessiti degli output di debug?"<<endl;
//     cout<<"1. Voglio visualizzare gli output di debug. (La dimensione delle strutture sara' ridotta)."<<endl;
//     cout<<"2. No, voglio proseguire senza visualizzare gli output di debug. (Consigliato)"<<endl;
//     cout<<"Inserisci l'opzione: ";
//     int choose = -1;
//     while(choose!=1 && choose!=2) cin>>choose;
//     output = (choose==1);
//     cout<<"\nChe tipo di test vuoi eseguire?"<<endl;
//     cout<<"1. Test su casi limite (La dimensione massima delle strutture sara' impostata ad 1 in modo da forzare interazioni tra strutture vuote)"<<endl;
//     cout<<"2. Test generale (L'esecuzione puo' apparire rallentata)"<<endl;
//     cout<<"Inserisci l'opzione: ";
//     choose = -1;
//     while(choose!=1 && choose!=2) cin>>choose;
//     if(choose==1){
//         MAX_SIZE = 1;
//     }else{
//         MAX_SIZE = (output) ? 20 : 100;
//     }
//     uniform_int_distribution<int> select_genSize(MIN_SIZE,MAX_SIZE); genSize = select_genSize;
//     uniform_int_distribution<int> select_genNum(MIN_NUM,MAX_NUM); genNum = select_genNum;

//     cout<<"\nL'output sara' sospeso per velocizzare l'esecuzione se i test devono essere ripetuti piu' di 50 volte.";
//     cout<<"\nInserisci il numero di iterazioni del test (consigliato 20): ";
//     choose = -1;
//     while(choose<0) cin>>choose;

//     ITERAZIONI = choose;
//     if(ITERAZIONI>50) output=false;
//     bool total = true;

//     // while(false){
//     while(ITERAZIONI>0){
        
//         //Operator==
//         bool testEqualBT = false;
//         bool testEqualBTVec = false;
//         bool testEqualBTLnk = false;
//         bool testEqualBST = false;

//         //Assignement
//         bool testAssBTVec = false;
//         bool testAssBTLnk = false;
//         bool testAssBST = false;
//         bool testMAssBTVec = false;
//         bool testMAssBTLnk = false;
//         bool testMAssBST = false;

//         //Constructor
//         bool testCCBTLnk = false;
//         bool testMCBTLnk = false;
//         bool testCCBTVec = false;
//         bool testMCBTVec = false;
//         bool testCCBST = false;
//         bool testMCBST = false;

//         //Specific constructor (Non mutable)
//         bool testSCBTLnkVec = false;
//         bool testSCBTLnkLst = false;
//         bool testSCBTVecVec = false;
//         bool testSCBTVecLst = false;
//         bool testSCBSTVec = false;
//         bool testSCBSTLst = false;

//         //Specific constructor (Mutable)
//         bool testMSCBTLnkVec = false;
//         bool testMSCBTLnkLst = false;
//         bool testMSCBTVecVec = false;
//         bool testMSCBTVecLst = false;
//         bool testMSCBSTVec = false;
//         bool testMSCBSTLst = false;

//         //Specific functions
//         bool testBSTMax = false;
//         bool testBSTMin = false;
//         bool testBSTSucc = false;
//         bool testBSTPred = false;
//         bool testInsertRemoveBST = false;

//         //Iterators
//         bool testPreOrdItrLnk = false;
//         bool testPostOrdItrLnk = false;
//         bool testInOrdItrLnk = false;
//         bool testBreadthItrLnk = false;
//         bool testPreOrdItrVec = false;
//         bool testPostOrdItrVec = false;
//         bool testInOrdItrVec = false;
//         bool testBreadthItrVec = false;

//         if(!output) cout<<"\nTesting comparison operators...";
//         try { testEqualBT = TestEqualBT(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testEqualBTVec = TestEqualBTVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testEqualBTLnk = TestEqualBTLnk(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testEqualBST = TestEqualBST(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         if(!output) cout<<"\nTesting assignment operators...";
//         try { testAssBTVec = TestAssBTVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testAssBTLnk = TestAssBTLnk(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testAssBST = TestAssBST(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         if(!output) cout<<"\nTesting move assignment operators...";
//         try { testMAssBTVec = TestMAssBTVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMAssBTLnk = TestMAssBTLnk(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMAssBST = TestMAssBST(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         if(!output) cout<<"\nTesting constructors...";
//         try { testCCBTLnk = CCBTLnk(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testCCBTVec = CCBTVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testCCBST = CCBST(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
        
//         if(!output) cout<<"\nTesting move constructors...";
//         try { testMCBTLnk = MCBTLnk(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMCBTVec = MCBTVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMCBST = MCBST(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         if(!output) cout<<"\nTesting non-mutable specific constructors...";
//         try { testSCBTLnkVec = SCBTLnkVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCBTLnkLst = SCBTLnkLst(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCBTVecVec = SCBTVecVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCBTVecLst = SCBTVecLst(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCBSTVec = SCBSTVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCBSTLst = SCBSTLst(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         if(!output) cout<<"\nTesting mutable specific constructors...";
//         try { testMSCBTLnkVec = MSCBTLnkVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCBTLnkLst = MSCBTLnkLst(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCBTVecVec = MSCBTVecVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCBTVecLst = MSCBTVecLst(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCBSTVec = MSCBSTVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCBSTLst = MSCBSTLst(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         if(!output) cout<<"\nTesting BST specific functions...";
//         try { testBSTMax = TestBSTMax(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testBSTMin = TestBSTMin(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testBSTPred = TestBSTPred(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testBSTSucc = TestBSTSucc(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testInsertRemoveBST = TestInsertRemoveBST(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         if(!output) cout<<"\nTesting iterators...";
//         try { testPreOrdItrLnk = TestPreOrdItrLnk(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testPostOrdItrLnk = TestPostOrdItrLnk(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testInOrdItrLnk = TestInOrdItrLnk(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testBreadthItrLnk = TestBreadthItrLnk(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testPreOrdItrVec = TestPreOrdItrVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testPostOrdItrVec = TestPostOrdItrVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testInOrdItrVec = TestInOrdItrVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testBreadthItrVec = TestBreadthItrVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         if(output) {
//             cout<<"\n\n*********** RESULTS ***********"<<endl;

//             cout<<"\nCOMPARISION OPERATORS:"<<endl;
//             cout<<"BinaryTree == BinaryTree: "<<((testEqualBT) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinaryTreeLnk == BTLnk: "<<((testEqualBTLnk) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinaryTreeVec == BinaryTreeVec: "<<((testEqualBTVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinarySearchTree == BinarySearchTree: "<<((testEqualBST) ? "Corretto" : "Errore")<<endl;

//             cout<<"\nASSIGNAMENT OPERATORS:"<<endl;
//             cout<<"BinaryTreeLnk = BinaryTreeLnk: "<<((testAssBTLnk) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinaryTreeVec = BinaryTreeVec: "<<((testAssBTVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinarySearchTree = BinarySearchTree: "<<((testAssBST) ? "Corretto" : "Errore")<<endl;

//             cout<<"\nMOVE ASSIGNAMENT OPERATORS:"<<endl;
//             cout<<"BinaryTreeLnk = move(BinaryTreeLnk): "<<((testMAssBTLnk) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinaryTreeVec = move(BinaryTreeVec): "<<((testMAssBTVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinarySearchTree = move(BinarySearchTree): "<<((testMAssBST) ? "Corretto" : "Errore")<<endl;

//             cout<<"\nCOPY CONSTRUCTORS: "<<endl;
//             cout<<"BinaryTreeLnk(BinaryTreeLnk): "<<((testCCBTLnk) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinaryTreeVec(BinaryTreeVec): "<<((testCCBTVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinarySearchTree(BinarySearchTree): "<<((testCCBST) ? "Corretto" : "Errore")<<endl;

//             cout<<"\nMOVE CONSTRUCTORS: "<<endl;
//             cout<<"BinaryTreeLnk(move(BinaryTreeLnk)): "<<((testMCBTLnk) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinaryTreeVec(move(BinaryTreeVec)): "<<((testMCBTVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinarySearchTree(move(BinarySearchTree)): "<<((testMCBST) ? "Corretto" : "Errore")<<endl;
            
//             cout<<"\nSPECIFIC NON-MUTABLE SPECIFIC CONSTRUCTORS: "<<endl;
//             cout<<"BinaryTreeLnk(Vector): "<<((testSCBTLnkVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinaryTreeLnk(List): "<<((testSCBTLnkLst) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinaryTreeVec(Vector): "<<((testSCBTVecVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinaryTreeVec(List): "<<((testSCBTVecLst) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinarySearchTree(Vector): "<<((testSCBSTVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinarySearchTree(List): "<<((testSCBSTVec) ? "Corretto" : "Errore")<<endl;

//             cout<<"\nSPECIFIC MUTABLE SPECIFIC CONSTRUCTORS: "<<endl;
//             cout<<"BinaryTreeLnk(Vector): "<<((testMSCBTLnkVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinaryTreeLnk(List): "<<((testMSCBTLnkLst) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinaryTreeVec(Vector): "<<((testMSCBTVecVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinaryTreeVec(List): "<<((testMSCBTVecLst) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinarySearchTree(Vector): "<<((testMSCBSTVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"BinarySearchTree(List): "<<((testMSCBSTVec) ? "Corretto" : "Errore")<<endl;

//             cout<<"\nBST SPECIFIC FUNCTIONS: "<<endl;
//             cout<<"BST.Max(): "<<((testBSTMax) ? "Corretto" : "Errore")<<endl;
//             cout<<"BST.Min(): "<<((testBSTMin) ? "Corretto" : "Errore")<<endl;
//             cout<<"BST.Predecessor(): "<<((testBSTPred) ? "Corretto" : "Errore")<<endl;
//             cout<<"BST.Successor(): "<<((testBSTSucc) ? "Corretto" : "Errore")<<endl;
//             cout<<"BST.Insert/Remove(): "<<((testInsertRemoveBST) ? "Corretto" : "Errore")<<endl;

//             cout<<"\nITERATORS: "<<endl;
//             cout<<"PreOrderIterator(BTLnk): "<<((testPreOrdItrLnk) ? "Corretto" : "Errore")<<endl;
//             cout<<"PostOrderIterator(BTLnk): "<<((testPostOrdItrLnk) ? "Corretto" : "Errore")<<endl;
//             cout<<"InOrderIterator(BTLnk): "<<((testInOrdItrLnk) ? "Corretto" : "Errore")<<endl;
//             cout<<"BreadthIterator(BTLnk): "<<((testBreadthItrLnk) ? "Corretto" : "Errore")<<endl;
//             cout<<"PreOrderIterator(BTVec): "<<((testPreOrdItrVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"PostOrderIterator(BTVec): "<<((testPostOrdItrVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"InOrderIterator(BTVec): "<<((testInOrdItrVec) ? "Corretto" : "Errore")<<endl;
//             cout<<"BreadthIterator(BTVec): "<<((testBreadthItrVec) ? "Corretto" : "Errore")<<endl;
//         }

//         if (testEqualBT && testEqualBTVec && testEqualBTLnk && testEqualBST && testAssBTVec &&
//             testAssBTLnk && testAssBST && testMAssBTVec && testMAssBTLnk && testMAssBST &&
//             testCCBTLnk && testMCBTLnk && testCCBTVec && testMCBTVec && testCCBST && testMCBST &&
//             testSCBTLnkVec && testSCBTLnkLst && testSCBTVecVec && testSCBTVecLst && testSCBSTVec &&
//             testSCBSTLst && testMSCBTLnkVec && testMSCBTLnkLst && testMSCBTVecVec && testMSCBTVecLst &&
//             testMSCBSTVec && testMSCBSTLst && testBSTMax && testBSTPred && testBSTSucc && testPreOrdItrLnk &&
//             testPostOrdItrLnk && testInOrdItrLnk && testBreadthItrLnk && testPreOrdItrVec &&
//             testPostOrdItrVec && testInOrdItrVec && testBreadthItrVec && testInsertRemoveBST)
//         {
//             total&=true;
//         } else {
//             total&=false;
//         }

//         if(!total) break;

//         if(ITERAZIONI==1){
//             //Maps
//             bool testMapsBTVec = true;
//             bool testMapsBTLnk = true;
//             bool testMapsBST = true;
//             cout<<"\n\n*********** SEZIONE DI TEST STATICI ***********";
//             cout<<"\nVuoi eseguire dei test per la verifica delle map? Sara' necessaria l'attenzione dell'utente."<<endl;
//             cout<<"1. Voglio procedere con il test."<<endl;
//             cout<<"2. No, voglio proseguire senza eseguire i test (Risulteranno superati)."<<endl;
//             cout<<"Inserisci l'opzione: ";
//             choose = -1;
//             while(choose!=1 && choose!=2) cin>>choose;
//             if(choose==1){
//                 MAX_SIZE = 10;
//                 MIN_SIZE = 6;
//                 MIN_NUM = -9;
//                 MAX_NUM = 9;
//                 uniform_int_distribution<int> select_genSize(MIN_SIZE,MAX_SIZE); genSize = select_genSize;
//                 uniform_int_distribution<int> select_genNum(MIN_NUM,MAX_NUM); genNum = select_genNum;
//                 try { testMapsBTLnk = TestMapsBTLnk(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//                 try { testMapsBTVec = TestMapsBTVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//                 try { testMapsBST = TestMapsBST(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//             }
//             total&= (testMapsBTVec && testMapsBTLnk && testMapsBST);
//         }

//         ITERAZIONI--;
//     }

//     if(total){
//         cout<<"\nTUTTI I TEST SONO STATI SUPERATI!! :D ";
//     }else{
//         cout<<"\nCi sono test che non sono stati superati :(";
//     }

//     cout<<endl;

//     return true;
// }



// /************************************************************************************************



//  *          INIZIO TEST SULLE HT



// *************************************************************************************************/

// bool StressTestOpen(){                   // Un test probabilmente inutile ma divertente
//     bool correct=true;
//     int num = 65535;
//     lasd::HashTableOpnAdr<int> s1;
//     cout<<endl;
//     for(int i{0}; i<num; i++){

//         if(i%10000==0) std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.." << std::flush;    // Ahahahahahahaha thread?? ahahahahhaa
        
//         if(i%10000==5000) std::cout << "\b\b\b\b\b\b\b\b\b\bLoading..." << std::flush;

//         if(!s1.Size()>1000){
//             int in = genSize(gen);
//             lasd::List<int> l1;
//             for(int j{0}; j<in; j++) l1.Insert(genNum(gen));
//             l1.Map(
//                 [&correct, &s1](const int& dat){
//                     correct&= s1.Exists(dat);
//                 }
//             );
//         }
        
//         int out = genSize(gen);
//         lasd::List<int> l2;
//         for(int j{0}; j<out; j++) l2.Insert(genNum(gen));
//         l2.Map(
//             [&correct, &s1](const int& dat){
//                 correct&= (!s1.Exists(dat));
//             }
//         );
//     }
//     return correct;
// }

// bool StressTestClose(){    // Un test probabilmente inutile ma divertente
//     bool correct=true;
//     int num = 65535;
//     lasd::HashTableClsAdr<int> s1;
//     cout<<endl;
//     for(int i{0}; i<num; i++){

//         if(i%10000==0) std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.." << std::flush;    // Ahahahahahahaha thread?? ahahahahhaa
        
//         if(i%10000==5000) std::cout << "\b\b\b\b\b\b\b\b\b\bLoading..." << std::flush;

//         if(!s1.Size()>1000){
//             int in = genSize(gen);
//             lasd::List<int> l1;
//             for(int j{0}; j<in; j++) l1.Insert(genNum(gen));
//             l1.Map(
//                 [&correct, &s1](const int& dat){
//                     correct&= s1.Exists(dat);
//                 }
//             );
//         }
        
//         int out = genSize(gen);
//         lasd::List<int> l2;
//         for(int j{0}; j<out; j++) l2.Insert(genNum(gen));
//         l2.Map(
//             [&correct, &s1](const int& dat){
//                 correct&= (!s1.Exists(dat));
//             }
//         );
//     }
//     return correct;
// }

// bool TestEqualHTOpen(){
//     if(output) cout<<"\n**********TEST TestEqualHTOpen**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen)+1;
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++){
//         int temp_num = genNum(gen);
//         v1[i]=temp_num;
//     } 
//     lasd::HashTableOpnAdr<int> s1(v1);
//     lasd::HashTableOpnAdr<int> s2(v1);
//     v1[genSize(gen)%temp_size]=genNum(gen);
//     lasd::HashTableOpnAdr<int> s3(v1);
//     if(output) { 
//         cout<<"\nS1: ";
        
//     }
//     if(output) { 
//         cout<<"\nS2: ";
        
//     }
//         if(output) { 
//         cout<<"\nS1: ";
        
//     }
//     if(output) { 
//         cout<<"\nS3: ";
        
//     }
//     correct&=(s1==s2);
//     correct&=(s1!=s3);
//     s2.Clear();
//     s2.Resize(0);
//     correct&=(s1!=s2);
//     s1.Clear();
//     s1.Resize(0);
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestEqualHTClose(){
//     if(output) cout<<"\n**********TEST TestEqualHTClose**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen)+1;
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++){
//         int temp_num = genNum(gen);
//         v1[i]=temp_num;
//     } 
//     lasd::HashTableClsAdr<int> s1(v1);
//     lasd::HashTableClsAdr<int> s2(v1);
//     v1[genSize(gen)%temp_size]=genNum(gen);
//     lasd::HashTableClsAdr<int> s3(v1);
//     if(output) { 
//         cout<<"\nS1: ";
        
//     }
//     if(output) { 
//         cout<<"\nS2: ";
        
//     }
//         if(output) { 
//         cout<<"\nS1: ";
        
//     }
//     if(output) { 
//         cout<<"\nS3: ";
        
//     }
//     correct&=(s1==s2);
//     correct&=(s1!=s3);
//     s2.Clear();
//     s2.Resize(0);
//     correct&=(s1!=s2);
//     s1.Clear();
//     s1.Resize(0);
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestAssHTOpen(){
//     if(output) cout<<"\n**********TEST TestAssHTOpen**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++) v1[i]=genNum(gen);
//     lasd::HashTableOpnAdr<int> s1(v1);
//     lasd::HashTableOpnAdr<int> s2(v1);
//     s2 = s1;
//     if(output) { 
//         cout<<"\nS1: ";
        
//     }
//     if(output) { 
//         cout<<"\nS2: ";
        
//     }
//     correct&=(s1==s2);
//     s2.Clear();
//     s1.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestAssHTClose(){
//     if(output) cout<<"\n**********TEST TestAssHTClose**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++) v1[i]=genNum(gen);
//     lasd::HashTableClsAdr<int> s1(v1);
//     lasd::HashTableClsAdr<int> s2;
//     s2 = s1;
//     if(output) { 
//         cout<<"\nS1: ";
        
//     }
//     if(output) { 
//         cout<<"\nS2: ";
        
//     }
//     correct&=(s1==s2);
//     s2.Clear();
//     s1.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestMAssHTOpen(){
//     if(output) cout<<"\n**********TEST TestMAssHTOpen**********\n";
//     bool correct=true;
//     int temp_size1 = genSize(gen)+1;
//     int temp_size2 = genSize(gen)+1;
//     lasd::Vector<int> v1(temp_size1);
//     lasd::Vector<int> v2(temp_size2);
//     for(int i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     for(int i=0; i<v2.Size(); i++) v2[i]=genNum(gen);
//     lasd::HashTableOpnAdr<int> s1(v1);
//     if(output) { 
//         cout<<"\nS1: ";
        
//     }
//     lasd::HashTableOpnAdr<int> s2(v2);
//     if(output) { 
//         cout<<"\nS2: ";
        
//     }
//     lasd::HashTableOpnAdr<int> s3(v1);
//     lasd::HashTableOpnAdr<int> s4(v2);
//     lasd::HashTableOpnAdr<int> s5;
//     s2 = move(s1);
//     correct&=(s1==s4);
//     s1.Insert(genNum(gen));
//     correct&=(s1!=s4);
//     correct&=(s2==s3);
//     s1 = move(s5);
//     correct&=(s1.Empty());
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestMAssHTClose(){
//     if(output) cout<<"\n**********TEST TestMAssHTClose**********\n";
//     bool correct=true;
//     int temp_size1 = genSize(gen)+1;
//     int temp_size2 = genSize(gen)+1;
//     lasd::Vector<int> v1(temp_size1);
//     lasd::Vector<int> v2(temp_size2);
//     for(int i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     for(int i=0; i<v2.Size(); i++) v2[i]=genNum(gen);
//     lasd::HashTableClsAdr<int> s1(v1);
//     if(output) { 
//         cout<<"\nS1: ";
        
//     }
//     lasd::HashTableClsAdr<int> s2(v2);
//     if(output) { 
//         cout<<"\nS2: ";
        
//     }
//     lasd::HashTableClsAdr<int> s3(v1);
//     lasd::HashTableClsAdr<int> s4(v2);
//     lasd::HashTableClsAdr<int> s5;
//     s2 = move(s1);
//     correct&=(s1==s4);
//     s1.Insert(genNum(gen));
//     correct&=(s1!=s4);
//     correct&=(s2==s3);
//     s1 = move(s5);
//     correct&=(s1.Empty());
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestCCHTOpen(){
//     if(output) cout<<"\n**********TEST TestCCHTOpen**********\n";
//     bool correct=true;
//     lasd::Vector<int> v1(genSize(gen));
//     for(ulong i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     lasd::HashTableOpnAdr<int> s1(v1);
//     lasd::HashTableOpnAdr<int> s2(s1);
//     if(output) { 
//         cout<<"\nS1: ";
        
//     }
//     if(output) { 
//         cout<<"\nS2: ";
        
//     }
//     correct&=(s1==s2);
//     s1.Clear();
//     correct&=(s1.Empty());
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestCCHTClose(){
//     if(output) cout<<"\n**********TEST TestCCHTClose**********\n";
//     bool correct=true;
//     lasd::Vector<int> v1(genSize(gen));
//     for(ulong i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     lasd::HashTableClsAdr<int> s1(v1);
//     lasd::HashTableClsAdr<int> s2(s1);
//     if(output) { 
//         cout<<"\nS1: ";
        
//     }
//     if(output) { 
//         cout<<"\nS2: ";
        
//     }
//     correct&=(s1==s2);
//     s1.Clear();
//     correct&=(s1.Empty());
//     s2.Clear();
//     correct&=(s1==s2);
//     return correct;
// }

// bool TestMCHTOpen(){
//     if(output) cout<<"\n**********TEST TestMCHTOpen**********\n";
//     bool correct=true;
//     int temp_size1 = genSize(gen);
//     lasd::Vector<int> v1(temp_size1);
//     for(int i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     lasd::HashTableOpnAdr<int> s1(v1);
//     lasd::HashTableOpnAdr<int> s2(v1);
//     lasd::HashTableOpnAdr<int> s3(move(s1));
//     correct&=(s1.Empty());
//     correct&=(s2==s3);
//     s3.Clear();
//     correct&=(s3.Empty());
//     s2.Clear();
//     correct&=(s3==s2);
//     return correct;
// }

// bool TestMCHTClose(){
//     if(output) cout<<"\n**********TEST TestMCHTClose**********\n";
//     bool correct=true;
//     int temp_size1 = genSize(gen);
//     lasd::Vector<int> v1(temp_size1);
//     for(int i=0; i<v1.Size(); i++) v1[i]=genNum(gen);
//     lasd::HashTableClsAdr<int> s1(v1);
//     lasd::HashTableClsAdr<int> s2(v1);
//     lasd::HashTableClsAdr<int> s3(move(s1));
//     correct&=(s1.Empty());
//     correct&=(s2==s3);
//     s3.Clear();
//     correct&=(s3.Empty());
//     s2.Clear();
//     correct&=(s3==s2);
//     return correct;
// }

// bool TestSCSizeHTOpen(){
//     if(output) cout<<"\n**********TEST TestSCSizeHTOpen**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         v1[i]=temp_num;
//         l1.Insert(temp_num);
//     }
//     lasd::HashTableOpnAdr<int> s1(genSize(gen));
//     for(int i{0}; i<v1.Size(); i++){
//         s1.Insert(v1[i]);
//     }
//     correct&=(s1.Size()==l1.Size());
//     l1.Map(
//         [&correct, &s1](const int& dat){
//             correct&= s1.Exists(dat);
//         }
//     );
//     return correct;
// }

// bool TestSCSizeHTClose(){
//     if(output) cout<<"\n**********TEST TestSCSizeHTClose**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         v1[i]=temp_num;
//         l1.Insert(temp_num);
//     };
//     lasd::HashTableClsAdr<int> s1(genSize(gen));
//     for(int i{0}; i<v1.Size(); i++){
//         s1.Insert(v1[i]);
//     }
//     correct&=(s1.Size()==l1.Size());
//     l1.Map(
//         [&correct, &s1](const int& dat){
//             correct&= s1.Exists(dat);
//         }
//     );
//     return correct;
// }

// bool TestSCHTOpenList(){
//     if(output) cout<<"\n**********TEST TestSCHTOpenList**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         v1[i]=temp_num;
//         l1.Insert(temp_num);
//     };
//     lasd::HashTableOpnAdr<int> s1(l1);
//     for(int i{0}; i<v1.Size(); i++){
//         correct&=(!(s1.Insert(v1[i])));
//     }
//     correct&=(s1.Size()==l1.Size());
//     l1.Map(
//         [&correct, &s1](const int& dat){
//             correct&= s1.Exists(dat);
//         }
//     );
//     return correct;
// }

// bool TestSCHTCloseList(){
//     if(output) cout<<"\n**********TEST TestSCHTCloseList**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         v1[i]=temp_num;
//         l1.Insert(temp_num);
//     };
//     lasd::HashTableClsAdr<int> s1(l1);
//     for(int i{0}; i<v1.Size(); i++){
//         correct&=(!(s1.Insert(v1[i])));
//     }
//     correct&=(s1.Size()==l1.Size());
//     l1.Map(
//         [&correct, &s1](const int& dat){
//             correct&= s1.Exists(dat);
//         }
//     );
//     return correct;
// }

// bool TestSCHTOpenVec(){
//     if(output) cout<<"\n**********TEST TestSCHTOpenVec**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         v1[i]=temp_num;
//         l1.Insert(temp_num);
//     };
//     lasd::HashTableOpnAdr<int> s1(v1);
//     for(int i{0}; i<v1.Size(); i++){
//         correct&=(!(s1.Insert(v1[i])));
//     }
//     correct&=(s1.Size()==l1.Size());
//     l1.Map(
//         [&correct, &s1](const int& dat){
//             correct&= s1.Exists(dat);
//         }
//     );
//     return correct;
// }

// bool TestSCHTCloseVec(){
//     if(output) cout<<"\n**********TEST TestSCHTCloseVec**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         v1[i]=temp_num;
//         l1.Insert(temp_num);
//     };
//     lasd::HashTableClsAdr<int> s1(v1);
//     for(int i{0}; i<v1.Size(); i++){
//         correct&=(!(s1.Insert(v1[i])));
//     }
//     correct&=(s1.Size()==l1.Size());
//     l1.Map(
//         [&correct, &s1](const int& dat){
//             correct&= s1.Exists(dat);
//         }
//     );
//     return correct;
// }

// bool TestMSCHTCloseVec(){
//     if(output) cout<<"\n**********TEST TestMSCHTCloseVec**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         v1[i]=temp_num;
//         l1.Insert(temp_num);
//     };
//     lasd::HashTableClsAdr<int> s1(move(v1));
//     for(int i{0}; i<l1.Size(); i++){
//         correct&=(!(s1.Insert(l1[i])));
//     }
//     correct&=(s1.Size()==l1.Size());
//     l1.Map(
//         [&correct, &s1](const int& dat){
//             correct&= s1.Exists(dat);
//         }
//     );
//     return correct;
// }

// bool TestMSCHTOpenVec(){
//     if(output) cout<<"\n**********TEST TestMSCHTOpenVec**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     lasd::Vector<int> v1(temp_size);
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         v1[i]=temp_num;
//         l1.Insert(temp_num);
//     };
//     lasd::HashTableOpnAdr<int> s1(move(v1));
//     for(int i{0}; i<l1.Size(); i++){
//         correct&=(!(s1.Insert(l1[i])));
//     }
//     correct&=(s1.Size()==l1.Size());
//     l1.Map(
//         [&correct, &s1](const int& dat){
//             correct&= s1.Exists(dat);
//         }
//     );
//     return correct;
// }

// bool TestMSCHTCloseList(){
//     if(output) cout<<"\n**********TEST TestMSCHTCloseList**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     lasd::List<int> v1;
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         v1.InsertAtBack(temp_num);
//         l1.Insert(temp_num);
//     };
//     lasd::HashTableClsAdr<int> s1(move(v1));
//     for(int i{0}; i<l1.Size(); i++){
//         correct&=(!(s1.Insert(l1[i])));
//     }
//     correct&=(s1.Size()==l1.Size());
//     l1.Map(
//         [&correct, &s1](const int& dat){
//             correct&= s1.Exists(dat);
//         }
//     );
//     return correct;
// }

// bool TestMSCHTOpenList(){
//     if(output) cout<<"\n**********TEST TestMSCHTOpenList**********\n";
//     bool correct=true;
//     int temp_size = genSize(gen);
//     lasd::List<int> l1;
//     lasd::List<int> v1;
//     for(int i=0; i<temp_size; i++) {
//         int temp_num = genNum(gen);
//         v1.InsertAtBack(temp_num);
//         l1.Insert(temp_num);
//     };
//     lasd::HashTableOpnAdr<int> s1(move(v1));
//     for(int i{0}; i<l1.Size(); i++){
//         correct&=(!(l1.Insert(l1[i])));
//     }
//     correct&=(s1.Size()==l1.Size());
//     l1.Map(
//         [&correct, &s1](const int& dat){
//             correct&= s1.Exists(dat);
//         }
//     );
//     return correct;
// }

// bool davtest_ex3(){

//     MIN_SIZE = 0;
//     MAX_SIZE = 500;
//     MIN_NUM = INT16_MIN;
//     MAX_NUM = INT16_MAX;

//     cout<<"\n\n*********** CONFIGURAZIONE DEI TEST: ***********"<<endl;
//     cout<<"Necessiti degli output di debug?"<<endl;
//     cout<<"1. Voglio visualizzare gli output di debug. (La dimensione delle strutture sara' ridotta)."<<endl;
//     cout<<"2. No, voglio proseguire senza visualizzare gli output di debug. (Consigliato)"<<endl;
//     cout<<"Inserisci l'opzione: ";
//     int choose = -1;
//     while(choose!=1 && choose!=2) cin>>choose;
//     output = (choose==1);
//     MAX_SIZE = (output) ? 20 : MAX_SIZE;
//     uniform_int_distribution<int> select_genSize(MIN_SIZE,MAX_SIZE); genSize = select_genSize;
//     uniform_int_distribution<int> select_genNum(MIN_NUM,MAX_NUM); genNum = select_genNum;

//     cout<<"\nVuoi eseguire uno stress test sulle Exists() (L'esecuzione puo' apparire rallentata)?"<<endl;
//     cout<<"1. Voglio eseguire lo stress test."<<endl;
//     cout<<"2. No voglio proseguire velocemente."<<endl;
//     cout<<"Inserisci l'opzione: ";
//     choose = -1;
//     while(choose!=1 && choose!=2) cin>>choose;
//     bool wantStressTest = (choose==1);
//     bool total = true;

//     int ITERAZIONI = 2;
        
//     while(ITERAZIONI!=0) {
        
//         cout<<"\n\n*********** TESTING "<<((ITERAZIONI==1) ? "LIMIT" : "GENERAL")<<" CASES ***********"<<endl;

//         //Operator==
//         bool testEqualHTOpen = false;
//         bool testEqualHTClose = false;

//         //Assignement
//         bool testAssHTOpen = false;
//         bool testAssHTClose = false;
//         bool testMAssHTOpen = false;
//         bool testMAssHTClose = false;

//         //Constructor
//         bool testCCHTOpen = false;
//         bool testMCHTOpen = false;
//         bool testCCHTClose = false;
//         bool testMCHTClose = false;

//         //Specific constructor (Non mutable)
//         bool testSCSizeHTOpen = false;
//         bool testSCSizeHTClose = false;
//         bool testSCHTOpenList = false;
//         bool testSCHTCloseList = false;
//         bool testSCHTOpenVec = false;
//         bool testSCHTCloseVec = false;

//         //Specific constructor (Mutable)
//         bool testMSCHTOpenList = false;
//         bool testMSCHTCloseList = false;
//         bool testMSCHTOpenVec = false;
//         bool testMSCHTCloseVec = false;

//         //Specific functions
//         bool stressTestOnExistsOpen = false;
//         bool stressTestOnExistsClose = false;
//         bool testResizeHTOpen = false;
//         bool testResizeHTClose = false;


//         cout<<"\nTesting "<<((ITERAZIONI==1) ? "limit" : "")<<" comparison operators...";
//         try { testEqualHTOpen = TestEqualHTOpen(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testEqualHTClose = TestEqualHTClose(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         cout<<"\nTesting "<<((ITERAZIONI==1) ? "limit" : "")<<" assignment operators...";
//         try { testAssHTOpen = TestAssHTOpen(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testAssHTClose = TestAssHTClose(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         cout<<"\nTesting "<<((ITERAZIONI==1) ? "limit" : "")<<" move assignment operators...";
//         try { testMAssHTOpen = TestMAssHTOpen(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMAssHTClose = TestMAssHTClose(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         cout<<"\nTesting "<<((ITERAZIONI==1) ? "limit" : "")<<" constructors...";
//         try { testCCHTOpen = TestCCHTOpen(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testCCHTClose = TestCCHTClose(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         cout<<"\nTesting "<<((ITERAZIONI==1) ? "limit" : "")<<" move constructors...";
//         try { testMCHTOpen = TestMCHTOpen(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMCHTClose = TestMCHTClose(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
        
//         cout<<"\nTesting "<<((ITERAZIONI==1) ? "limit" : "")<<" non-mutable specific constructors..";
//         try { testSCSizeHTOpen = TestSCSizeHTOpen(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCSizeHTClose = TestSCSizeHTClose(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCHTOpenList = TestSCHTOpenList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCHTCloseList = TestSCHTCloseList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCHTOpenVec = TestSCHTOpenVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testSCHTCloseVec = TestSCHTCloseVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         cout<<"\nTesting "<<((ITERAZIONI==1) ? "limit" : "")<<" mutable specific constructors...";
//         try { testMSCHTOpenList = TestMSCHTOpenList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCHTCloseList = TestMSCHTCloseList(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCHTOpenVec = TestMSCHTOpenVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         try { testMSCHTCloseVec = TestMSCHTCloseVec(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }

//         if(wantStressTest){

//             if(ITERAZIONI==2){
//                 uniform_int_distribution<int> select2_genSize(0,100); genSize = select2_genSize;
//                 uniform_int_distribution<int> select2_genNum(0,1000); genNum = select2_genNum;
//             }

//             cout<<"\nTesting "<<((ITERAZIONI==1) ? "limit" : "")<<" exists...";
//             try { stressTestOnExistsOpen = StressTestOpen(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//             try { stressTestOnExistsClose = StressTestClose(); } catch (const std::exception& e) { std::cerr<<e.what()<<endl; }
//         } else {
//             stressTestOnExistsOpen = stressTestOnExistsClose = true;
//         }

//         uniform_int_distribution<int> select3_genSize(0,1); genSize = select3_genSize;

//         cout<<"\n\n*********** RESULTS ***********"<<endl;

//         cout<<"\nCOMPARISION OPERATORS:"<<endl;
//         cout<<"HashTableOpnAdr == HashTableOpnAdr: "<<((testEqualHTOpen) ? "Corretto" : "Errore")<<endl;
//         cout<<"HashTableClsAdr == HashTableClsAdr: "<<((testEqualHTClose) ? "Corretto" : "Errore")<<endl;

//         cout<<"\nASSIGNAMENT OPERATORS:"<<endl;
//         cout<<"HashTableOpnAdr = HashTableOpnAdr: "<<((testAssHTOpen) ? "Corretto" : "Errore")<<endl;
//         cout<<"HashTableClsAdr = HashTableClsAdr: "<<((testAssHTClose) ? "Corretto" : "Errore")<<endl;

//         cout<<"\nMOVE ASSIGNAMENT OPERATORS:"<<endl;
//         cout<<"HashTableOpnAdr = move(HashTableOpnAdr): "<<((testMAssHTOpen) ? "Corretto" : "Errore")<<endl;
//         cout<<"HashTableClsAdr = move(HashTableClsAdr): "<<((testMAssHTClose) ? "Corretto" : "Errore")<<endl;

//         cout<<"\nCOPY CONSTRUCTORS: "<<endl;
//         cout<<"HashTableOpnAdr(HashTableOpnAdr): "<<((testCCHTOpen) ? "Corretto" : "Errore")<<endl;
//         cout<<"HashTableClsAdr(HashTableClsAdr): "<<((testCCHTClose) ? "Corretto" : "Errore")<<endl;

//         cout<<"\nMOVE CONSTRUCTORS: "<<endl;
//         cout<<"HashTableOpnAdr(move(HashTableOpnAdr)): "<<((testMCHTOpen) ? "Corretto" : "Errore")<<endl;
//         cout<<"HashTableClsAdr(move(HashTableClsAdr)): "<<((testMCHTClose) ? "Corretto" : "Errore")<<endl;

//         cout<<"\nSPECIFIC NON-MUTABLE SPECIFIC CONSTRUCTORS: "<<endl;
//         cout<<"HashTableOpnAdr(size): "<<((testSCSizeHTOpen) ? "Corretto" : "Errore")<<endl;
//         cout<<"HashTableClsAdr(size): "<<((testSCSizeHTClose) ? "Corretto" : "Errore")<<endl;
//         cout<<"HashTableOpnAdr(Vector): "<<((testSCHTOpenVec) ? "Corretto" : "Errore")<<endl;
//         cout<<"HashTableOpnAdr(List): "<<((testSCHTOpenList) ? "Corretto" : "Errore")<<endl;
//         cout<<"HashTableClsAdr(Vector): "<<((testSCHTCloseVec) ? "Corretto" : "Errore")<<endl;
//         cout<<"HashTableClsAdr(List): "<<((testSCHTCloseList) ? "Corretto" : "Errore")<<endl;

//         cout<<"\nSPECIFIC MUTABLE SPECIFIC CONSTRUCTORS: "<<endl;
//         cout<<"HashTableOpnAdr(Vector): "<<((testMSCHTOpenVec) ? "Corretto" : "Errore")<<endl;
//         cout<<"HashTableOpnAdr(List): "<<((testMSCHTOpenList) ? "Corretto" : "Errore")<<endl;
//         cout<<"HashTableClsAdr(Vector): "<<((testMSCHTCloseVec) ? "Corretto" : "Errore")<<endl;
//         cout<<"HashTableClsAdr(List): "<<((testMSCHTCloseList) ? "Corretto" : "Errore")<<endl;

//         cout<<"\nSTRESS TEST ON EXISTS: "<<endl;
//         cout<<"HashTableOpnAdr: "<<((stressTestOnExistsOpen) ? "Corretto" : "Errore")<<endl;
//         cout<<"HashTableClsAdr: "<<((stressTestOnExistsClose) ? "Corretto" : "Errore")<<endl;


//         if (testEqualHTOpen &&
//             testEqualHTClose &&
//             testAssHTOpen &&
//             testAssHTClose &&
//             testMAssHTOpen &&
//             testMAssHTClose &&
//             testCCHTOpen &&
//             testMCHTOpen &&
//             testCCHTClose &&
//             testMCHTClose &&
//             testSCSizeHTOpen &&
//             testSCSizeHTClose &&
//             testSCHTOpenList &&
//             testSCHTCloseList &&
//             testSCHTOpenVec &&
//             testSCHTCloseVec &&
//             testMSCHTOpenList &&
//             testMSCHTCloseList &&
//             testMSCHTOpenVec &&
//             testMSCHTCloseVec &&
//             stressTestOnExistsOpen &&
//             stressTestOnExistsClose
//             // testResizeHTOpen &&
//             // testResizeHTClose
//             )
//         {
//             total &= true;
//         } else {
//             total &= false;
//         }

//         ITERAZIONI--;

//     }

//     if(total){
//         cout<<"\nTUTTI I TEST SONO STATI SUPERATI!! :D ";
//     }else{
//         cout<<"\nCi sono test che non sono stati superati :(";
//     }

//     cout<<endl;

//     return true;
// }

// #endif