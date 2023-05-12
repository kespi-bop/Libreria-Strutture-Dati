// #ifndef MYTEST_CPP
// #define MYTEST_CPP

// #include <iostream>
// #include <random>

// #define DimensioneContainer 10

// using namespace std;

// default_random_engine gen(random_device{}());
// uniform_int_distribution<int> RandomNumber(0, 100);

// #include "test.hpp"

// /* ************************************************************************** */

// void myTest(){
//   int scelta;
//   cout<<"\n\n\nQuale test vuoi eseguire? \n";
//   cout<<"Esercizio1 : (premi 1) \n";
//   cout<<"Esercizio2 : (premi 2) \n";
//   cin>>scelta;

//   if(scelta == 1) TestEsercizio1();
//   else if(scelta == 2) TestEsercizio2();
// }

// bool TestCostruttori()
// {
//     bool TestCostruttoriErrori = true;

//     cout<<"\n\n***************TEST DEI COSTRUTTORI: \n";
    
//     cout<<"\nTestCostruttore Vec->QueueVec(Copy): ";
//     lasd::Vector<int> vc1(DimensioneContainer);
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       vc1[i] = i;
//     }
//     lasd::QueueVec<int> qv1(vc1);
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       if(vc1[i] != qv1.HeadNDequeue()) {
//           cout<<"ERRORE!";
//           TestCostruttoriErrori &= false;
//           break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }
    
//     cout<<"\nTestCostruttore Vec->QueueVec(Move): ";
//     lasd::QueueVec<int> qv2(move(vc1));
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       if(vc1[i] != qv2.HeadNDequeue()) {
//         cout<<"ERRORE!\n";
//         TestCostruttoriErrori &= false;
//         break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }


//     cout<<"\nTestCostruttore QueueVec->QueueVec(copy): ";
//     lasd::QueueVec<int> qv3;
//     for(uint i = 0; i < DimensioneContainer; i ++) {
//       qv3.Enqueue(i);
//     }
//     lasd::QueueVec<int> qv4(qv3);
//     if(qv4 == qv3) {
//       cout<<"CORRETTO!\n";
//     } else {
//       cout<<"ERRORE!\n";
//       TestCostruttoriErrori &= false;
//     }
  
//     cout<<"\nTestCostruttore QueueVec->QueueVec(move): ";
//     lasd::QueueVec<int> qv5(move(qv4));
//     if(qv4.Empty()) {
//       cout<<"CORRETTO!\n";
//     } else {
//       cout<<"ERRORE!\n";
//       TestCostruttoriErrori &= false;
//     }


//     cout<<"\nTestCostruttore List->QueueVec(Copy): ";
//     lasd::List<int> lst1;
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       lst1.Insert(i);
//     }
//     lasd::QueueVec<int> qv6(lst1);
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       if(lst1[i] != qv6.HeadNDequeue()) {
//           cout<<"ERRORE!";
//           TestCostruttoriErrori &= false;
//           break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }
    
//     cout<<"\nTestCostruttore List->QueueVec(Move): ";
//     lasd::QueueVec<int> qv7(move(lst1));
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       if(lst1[i] != qv7.HeadNDequeue()) {
//         cout<<"ERRORE!\n";
//         TestCostruttoriErrori &= false;
//         break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }


//     cout<<"\nTestCostruttore Vec->StackVec(Copy): ";
//     lasd::Vector<int> vc2(DimensioneContainer);
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       vc2[i] = i;
//     }
//     lasd::StackVec<int> stk1(vc2);
//     for(int i = DimensioneContainer - 1; i >= 0; i--) {
//       if(vc2[i] != stk1.TopNPop()) {
//           cout<<"ERRORE!\n";
//           TestCostruttoriErrori &= false;
//           break;
//       }
//       if(i == 0) {
//         cout<<"CORRETTO!\n";
//       }
//     }
    
//     cout<<"\nTestCostruttore Vec->StackVec(Move): ";
//     lasd::StackVec<int> stk2(move(vc2));
//     for(int i = DimensioneContainer - 1; i >= 0; i--) {
//       if(vc2[i] != stk2.TopNPop()) {
//           cout<<"ERRORE!\n";
//           TestCostruttoriErrori &= false;
//           break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }
    

//     cout<<"\nTestCostruttore StackVec->StackVec(copy): ";
//     lasd::StackVec<int> stk3;
//     for(uint i = 0; i < DimensioneContainer; i ++) {
//       stk3.Push(i);
//     }
//     lasd::StackVec<int> stk4(stk3);
//     if(stk4 == stk3) {
//       cout<<"CORRETTO!\n";
//     } else {
//       cout<<"ERRORE!\n";
//       TestCostruttoriErrori &= false;
//     }
    
//     cout<<"\nTestCostruttore StackVec->StackVec(move): ";
//     lasd::StackVec<int> stk5(move(stk4));
//     if(stk4.Empty()) {
//       cout<<"CORRETTO!\n";
//     } else {
//       cout<<"ERRORE!\n";
//       TestCostruttoriErrori &= false;
//     }

    
//     cout<<"\nTestCostruttore List->StackVec(Copy): ";
//     lasd::List<int> lst2;
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       lst2.Insert(i);
//     }
//     lasd::StackVec<int> stk6(lst2);
//     for(int i = DimensioneContainer - 1; i >= 0; i--) {
//       if(lst2[i] != stk6.TopNPop()) {
//           cout<<"ERRORE!\n";
//           TestCostruttoriErrori &= false;
//           break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }
    
//     cout<<"\nTestCostruttore List->StackVec(Move): ";
//     lasd::StackVec<int> stk7(move(lst2));
//     for(int i = DimensioneContainer - 1; i >= 0; i--) {
//       if(lst2[i] != stk7.TopNPop()) {
//           cout<<"ERRORE!\n";
//           TestCostruttoriErrori &= false;
//           break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }


//     cout<<"\nTestCostruttore List->QueueLst(copy): ";
//     lasd::QueueLst<int> qlst1(lst2);
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       if(lst2[i] != qlst1.HeadNDequeue()) {
//         cout<<"ERRORE!\n";
//         TestCostruttoriErrori &= false;
//         break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }

//     cout<<"\nTestCostruttore List->QueueLst(move): ";
//     lasd::QueueLst<int> qlst2(move(lst2));
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       if(lst2[i] != qlst2.HeadNDequeue()) {
//         cout<<"ERRORE!\n";
//         TestCostruttoriErrori &= false;
//         break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }

//     cout<<"\nTestCostruttore QueueLst->QueueLst(copy): ";
//     lasd::QueueLst<int> qlst3;
//     for(int i = 0; i < DimensioneContainer; i++) {
//       qlst3.Enqueue(i);
//     }
//     lasd::QueueLst<int> qlst4(qlst3);
//     if(qlst3 == qlst4) {
//       cout<<"CORRETTO!\n";
//     } else {
//       cout<<"ERRORE!\n";
//       TestCostruttoriErrori &= false;
//     }

//     cout<<"\nTestCostruttore QueueLst->QueueLst(move): ";
//     lasd::QueueLst<int> qlst5(move(qlst4));
//     if(qlst4.Empty()) {
//       cout<<"CORRETTO!\n";
//     } else {
//       cout<<"ERRORE!\n";
//       TestCostruttoriErrori &= false;
//     }

//     cout<<"\nTestCostruttore Vec->QueueLst(copy): ";
//     lasd::QueueLst<int> qlst6(vc2);
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       if(vc2[i] != qlst6.HeadNDequeue()) {
//         cout<<"ERRORE!\n";
//         TestCostruttoriErrori &= false;
//         break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//         TestCostruttoriErrori |= false;
//       }
//     }

//     cout<<"\nTestCostruttore Vec->QueueLst(move): ";
//     lasd::QueueLst<int> qlst7(move(vc2));
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       if(vc2[i] != qlst7.HeadNDequeue()) {
//         cout<<"ERRORE!\n";
//         TestCostruttoriErrori &= false;
//         break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//         TestCostruttoriErrori |= false;
//       }
//     }

//     cout<<"\nTestCostruttore List->StackLst(copy): ";
//     lasd::StackLst<int> stclst1(lst2);    
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       if(lst2[i] != stclst1.TopNPop()) {
//           cout<<"ERRORE!\n";
//           TestCostruttoriErrori &= false;
//           break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }


//     cout<<"\nTestCostruttore List->StackLst(move): ";
//     lasd::StackLst<int> stclst2(move(lst2));    
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       if(lst2[i] != stclst2.TopNPop()) {
//           cout<<"ERRORE!\n";
//           TestCostruttoriErrori &= false;
//           break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }

//     cout<<"\nTestCostruttore StackLst->StackLst(copy): ";
//     lasd::StackLst<int> stclst3(stclst2);    
//     if(stclst2 == stclst3) {
//       cout<<"CORRETTO!\n";
//     } else {
//       cout<<"ERRORE!\n";
//       TestCostruttoriErrori &= false;
//     }

//     cout<<"\nTestCostruttore StackLst->StackLst(move): ";
//     lasd::StackLst<int> stclst4(move(stclst3));    
//     if(stclst3.Empty()) {
//       cout<<"CORRETTO!\n";
//     } else {
//       cout<<"ERRORE!\n";
//       TestCostruttoriErrori &= false;
//     }

//     cout<<"\nTestCostruttore Vec->StackLst(copy): ";
//     lasd::StackLst<int> stclst5(vc2);    
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       if(vc2[i] != stclst5.TopNPop()) {
//           cout<<"ERRORE!\n";
//           TestCostruttoriErrori &= false;
//           break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }

//     cout<<"\nTestCostruttore Vec->StackLst(move): ";
//     lasd::StackLst<int> stclst6(move(vc2));    
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       if(vc2[i] != stclst6.TopNPop()) {
//           cout<<"ERRORE!\n";
//           TestCostruttoriErrori &= false;
//           break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }
    
//     cout<<"\nTestCostruttore Vec->List(copy): ";
//     lasd::List<int> list1(vc2);    
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       if(vc2[i] != list1[i]) {
//           cout<<"ERRORE!\n";
//           TestCostruttoriErrori &= false;
//           break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }

//     cout<<"\nTestCostruttore Vec->List(move): ";
//     lasd::List<int> list2(move(vc2));    
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       if(vc2[i] != list2[i]) {
//           cout<<"ERRORE!\n";
//           TestCostruttoriErrori &= false;
//           break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }

//     cout<<"\nTestCostruttore List->Vec(copy): ";
//     lasd::Vector<int> vector1(list1);    
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       if(vector1[i] != list1[i]) {
//           cout<<"ERRORE!\n";
//           TestCostruttoriErrori &= false;
//           break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }

//     cout<<"\nTestCostruttore List->Vec(move): ";
//     lasd::Vector<int> vector2(move(list1));    
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       if(vector2[i] != list1[i]) {
//           cout<<"ERRORE!\n";
//           TestCostruttoriErrori &= false;
//           break;
//       }
//       if(i == DimensioneContainer - 1) {
//         cout<<"CORRETTO!\n";
//       }
//     }

//     return TestCostruttoriErrori;
// }

// bool TestAssegnazioni()
// {
//     bool TestAssergnazioniErrori = true;

//     cout<<"\n\n***************TEST DELLE ASSEGNAZIONI: \n";

//     cout<<"\nTestAssegnazione QueueVec->QueueVec(copy): ";
//     lasd::QueueVec<int> qvc1;
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       qvc1.Enqueue(i);
//     }
//     lasd::QueueVec<int> qvc2;
//     qvc2 = qvc1;
//     if(qvc1 == qvc2) {
//       cout<<"CORRETTO!\n";
//     } else {
//       cout<<"ERRORE!\n";
//       TestAssergnazioniErrori &= false;
//     }

//     cout<<"\nTestAssegnazione QueueVec->QueueVec(move): ";
//     lasd::QueueVec<int> qvc3;
//     qvc3 = move(qvc2);
//     if(qvc3 == qvc1 && qvc2.Empty()) {
//       cout<<"CORRETTO!\n";
//     } else {
//       cout<<"ERRORE!\n";
//       TestAssergnazioniErrori &= false;
//     }

//     cout<<"\nTestAssegnazione StackVec->StackVec(copy): ";
//     lasd::StackVec<int> stck1;
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       stck1.Push(i);
//     }
//     lasd::StackVec<int> stck2;
//     stck2 = stck1;
//     if(stck1 == stck2) {
//       cout<<"CORRETTO!\n";
//     } else {
//       cout<<"ERRORE!\n";
//       TestAssergnazioniErrori &= false;
//     }

//     cout<<"\nTestAssegnazione StackVec->StackVec(move): ";
//     lasd::StackVec<int> stck3;
//     stck3 = move(stck2);
//     if(stck3 == stck1 && stck2.Empty()) {
//       cout<<"CORRETTO!\n";
//     } else {
//       cout<<"ERRORE!\n";
//       TestAssergnazioniErrori &= false;
//     }

//     cout<<"\nTestAssegnazione QueueLst->QueueLst(copy): ";
//     lasd::QueueLst<int> qlst1;
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       qlst1.Enqueue(i);
//     }
//     lasd::QueueLst<int> qlst2;
//     qlst2 = qlst1;
//     if(qlst1 == qlst2) {
//       cout<<"CORRETTO!\n";
//     } else {
//       cout<<"ERRORE!\n";
//       TestAssergnazioniErrori &= false;
//     }

//     cout<<"\nTestAssegnazione QueueVec->QueueVec(move): ";
//     lasd::QueueLst<int> qlst3;
//     qlst3 = move(qlst2);
//     if(qlst3 == qlst1 && qlst2.Empty()) {
//       cout<<"CORRETTO!\n";
//     } else {
//       cout<<"ERRORE!\n";
//       TestAssergnazioniErrori &= false;
//     }


//     cout<<"\nTestAssegnazione StackLst->StackLst(copy): ";
//     lasd::StackLst<int> stcklst1;
//     for(uint i = 0; i < DimensioneContainer; i++) {
//       stcklst1.Push(i);
//     }
//     lasd::StackLst<int> stcklst2;
//     stcklst2 = stcklst1;
//     if(stcklst1 == stcklst2) {
//       cout<<"CORRETTO!\n";
//     } else {
//       cout<<"ERRORE!\n";
//       TestAssergnazioniErrori &= false;
//     }

//     cout<<"\nTestAssegnazione StackLst->StackLst(move): ";
//     lasd::StackLst<int> stcklst3;
//     stcklst3 = move(stcklst2);
//     if(stcklst3 == stcklst1 && stcklst2.Empty()) {
//       cout<<"CORRETTO!\n";
//     } else {
//       cout<<"ERRORE!\n";
//       TestAssergnazioniErrori &= false;
//     }

//     return TestAssergnazioniErrori;
// }

// bool TestDictionaryFunctions()
// { 
//   bool TestDictionaryErrori = true;

//   cout<<"\n\n***************TEST DELLE FUNZIONI DEI DICTIONARY: \n";

//   lasd::Vector<int> v1(3);
//   v1[0]=1; v1[1]=2; v1[2]=3;

//   lasd::Vector<int> v2(3);
//   v2[0]=6; v2[1]=7; v2[2]=8;

//   lasd::List<int> l1;
//   l1.InsertAtBack(3); l1.InsertAtBack(4); l1.InsertAtBack(5);

//   cout<<"\nTestDictionary InsertAll(copy): ";
//   bool test1 = l1.InsertAll(v1);
//   bool test2 = l1.InsertAll(v2);
//   if(test1 || !(test2)) {
//     cout<<"ERRORE!\n";
//     TestDictionaryErrori &= false;
//   } else {
//     cout<<"CORRETTO!\n";
//   }

//   cout<<"\nTestDictionary InsertAll(move): ";
//   lasd::List<int> l2;
//   l2.InsertAtBack(3); l2.InsertAtBack(4); l2.InsertAtBack(5);
//   test1 = l2.InsertAll(move(v1));
//   test2 = l2.InsertAll(move(v2));
//   if(test1 || !(test2)) {
//     cout<<"ERRORE!\n";
//     TestDictionaryErrori &= false;
//   } else {
//     cout<<"CORRETTO!\n";
//   }

//   lasd::Vector<int> v3(3);
//   v3[0]=1; v3[1]=2; v3[2]=3;

//   lasd::Vector<int> v4(3);
//   v4[0]=3; v4[1]=4; v4[2]=5;

//   cout<<"\nTestDictionary InsertSome(copy): ";
//   lasd::List<int> l3;
//   l3.InsertAtBack(3); l3.InsertAtBack(4); l3.InsertAtBack(5);
//   bool test3 = l3.InsertSome(v3);
//   bool test4 = l3.InsertSome(v4);
//   if(!(test3) || test4) {
//     cout<<"ERRORE!\n";
//     TestDictionaryErrori &= false;
//   } else {
//     cout<<"CORRETTO!\n";
//   }

//   cout<<"\nTestDictionary InsertSome(move): ";
//   lasd::List<int> l4;
//   l4.InsertAtBack(3); l4.InsertAtBack(4); l4.InsertAtBack(5);
//   test3 = l4.InsertSome(move(v3));
//   test4 = l4.InsertSome(move(v4));
//   if(!(test3) || test4) {
//     cout<<"ERRORE!\n";
//     TestDictionaryErrori &= false;
//   } else {
//     cout<<"CORRETTO!\n";
//   }

//   lasd::Vector<int> v5(3);
//   v5[0]=1; v5[1]=2; v5[2]=3;

//   lasd::Vector<int> v6(3);
//   v6[0]=4; v6[1]=5; v6[2]=6;

//   cout<<"\nTestDictionary RemoveAll: ";
//   lasd::List<int> l5;
//   l5.InsertAtBack(3); l5.InsertAtBack(4); l5.InsertAtBack(5);
//   l5.InsertAtBack(6); l5.InsertAtBack(7);
//   bool test5 = l5.RemoveAll(v5);
//   bool test6 = l5.RemoveAll(v6);
//   if(test5 || !(test6)) {
//     cout<<"ERRORE!\n";
//     TestDictionaryErrori &= false;
//   } else {
//     cout<<"CORRETTO!\n";
//   }


//   cout<<"\nTestDictionary RemoveSome: ";
//   lasd::Vector<int> v7(3);
//   v7[0]=1; v7[1]=2; v7[2]=3;

//   lasd::Vector<int> v8(3);
//   v8[0]=6; v8[1]=7; v8[2]=8;

//   lasd::List<int> l6;
//   l6.InsertAtBack(3); l6.InsertAtBack(4); l6.InsertAtBack(5);
//   bool test7=l6.RemoveSome(v7);
//   bool test8=l6.RemoveSome(v8);
//   if(!(test7) || test8) {
//     cout<<"ERRORE!\n";
//     TestDictionaryErrori &= false;
//   } else {
//     cout<<"CORRETTO!\n";
//   }

//   return TestDictionaryErrori;
// }

// bool TestSort()
// {
//   cout<<"\n\n***************TEST DI SORTING: \n";

//   cout<<"\nTestSort SortingInt: ";
//   bool TestSortInt = true;
//   lasd::Vector<int> v1(DimensioneContainer);
//   for(int i = 0; i < v1.Size(); i++){
//     v1[i] = RandomNumber(gen);
//   }
//   v1.Sort();
//   for(int i = 1; i < v1.Size(); i++){
//     TestSortInt &= (v1[i-1] <= v1[i]);
//   }
//   if(TestSortInt) {
//     cout<<"CORRETTO!\n";
//   } else {
//     cout<<"ERRORE!\n";
//   }



//   cout<<"\nTestSort SortingEmptyVector(borderline case): ";
//   bool TestSortEmpty = true;
//   lasd::Vector<int> v2(0);
//   v2.Sort();
//   for(int i = 1; i<v2.Size(); i++) {
//     TestSortEmpty &= (v2[i-1]<=v2[i]);
//   } 
//   if(TestSortEmpty) {
//     cout<<"CORRETTO!\n";
//   } else {
//     cout<<"ERRORE!\n";
//   }
    

//   return (TestSortInt && TestSortEmpty);
// }

// bool TestQueueVec()
// {
//   bool TestQueueVec = true;
//   cout<<"\n***************TEST DI QUEUEVEC: \n";
//   cout<<"\nTestSort QueueVec: \n";
//   lasd::QueueVec<int> queue;

//   queue.Enqueue(5);
//   cout<<"Testa '"<<queue.Head()<<"': ";
//   int value = queue.HeadNDequeue();
//   if(value == 5) {
//     cout<<"CORRETTO!\n";
//   } else {
//     cout<<"ERRORE!\n";
//     TestQueueVec = false;
//   }

//   queue.Enqueue(1);
//   queue.Enqueue(3);
//   cout<<"Testa '"<<queue.Head()<<"': ";
//   value = queue.HeadNDequeue();
//   if(value == 1) {
//     cout<<"CORRETTO!\n";
//   } else {
//     cout<<"ERRORE!\n";
//     TestQueueVec = false;
//   }

//   queue.Enqueue(2);
//   queue.Enqueue(4);
//   cout<<"Testa '"<<queue.Head()<<"': ";
//   value = queue.HeadNDequeue();
//   if(value == 3) {
//     cout<<"CORRETTO!\n";
//   } else {
//     cout<<"ERRORE!\n";
//     TestQueueVec = false;
//   }

//   queue.Enqueue(1);
//   queue.Enqueue(7);
//   cout<<"Testa '"<<queue.Head()<<"': ";
//   value = queue.HeadNDequeue();
//   if(value == 2) {
//     cout<<"CORRETTO!\n";
//   } else {
//     cout<<"ERRORE!\n";
//     TestQueueVec = false;
//   }

//   queue.Enqueue(2);
//   queue.Enqueue(2);
//   cout<<"Testa '"<<queue.Head()<<"': ";
//   value = queue.HeadNDequeue();
//   if(value == 4) {
//     cout<<"CORRETTO!\n";
//   } else {
//     cout<<"ERRORE!\n";
//     TestQueueVec = false;
//   }

//   queue.Enqueue(6);
//   cout<<"Testa '"<<queue.Head()<<"': ";
//   value = queue.HeadNDequeue();
//   if(value == 1) {
//     cout<<"CORRETTO!\n";
//   } else {
//     cout<<"ERRORE!\n";
//     TestQueueVec = false;
//   }

//   queue.Enqueue(8);
//   cout<<"Testa '"<<queue.Head()<<"': ";
//   value = queue.HeadNDequeue();
//   if(value == 7) {
//     cout<<"CORRETTO!\n";
//   } else {
//     cout<<"ERRORE!\n";
//     TestQueueVec = false;
//   }

//   queue.Enqueue(1);
//   queue.Enqueue(4);

//   cout<<"Testa '"<<queue.Head()<<"': ";
//   value = queue.HeadNDequeue();
//   if(value == 2) {
//     cout<<"CORRETTO!\n";
//   } else {
//     cout<<"ERRORE!\n";
//     TestQueueVec = false;
//   }

//   cout<<"Testa '"<<queue.Head()<<"': ";
//   value = queue.HeadNDequeue();
//   if(value == 2) {
//     cout<<"CORRETTO!\n";
//   } else {
//     cout<<"ERRORE!\n";
//     TestQueueVec = false;
//   }

//   cout<<"Testa '"<<queue.Head()<<"': ";
//   value = queue.HeadNDequeue();
//   if(value == 6) {
//     cout<<"CORRETTO!\n";
//   } else {
//     cout<<"ERRORE!\n";
//     TestQueueVec = false;
//   }

//   cout<<"Testa '"<<queue.Head()<<"': ";
//   value = queue.HeadNDequeue();
//   if(value == 8) {
//     cout<<"CORRETTO!\n";
//   } else {
//     cout<<"ERRORE!\n";
//     TestQueueVec = false;
//   }

//   return TestQueueVec;
// }

// bool TestIteratori() {
//   bool testIteratori = true;
//   int lines = 1;
//   cout<<"\n\nBegin of (BST into) Iterator Test: "<<endl;

//   lasd::BinaryTreeLnk<int> btlnk;
//   lasd::BTInOrderIterator<int> inOrderBST(btlnk);
//   if(inOrderBST.Terminated()) {
//     cout<<lines++<<" Iterator is terminated: Correct!"<<endl;
//   } else {
//     cout<<lines++<<"Iterator is not terminated: Error!"<<endl;
//     testIteratori &= false;
//   }
//   lasd::BTInOrderIterator<int> inOrderBSTmove(std::move(btlnk));
//   if(inOrderBST.Terminated()) {
//     cout<<lines++<<" Iterator is terminated: Correct!"<<endl;
//   } else {
//     cout<<lines++<<" Iterator is not terminated: Error!"<<endl;
//     testIteratori &= false;
//   }

//   lasd::List<int> lst;
//   for(int i=0; i<6; i++)
//       lst.InsertAtBack(i);
//   lasd::BinaryTreeLnk<int> btLnk(lst);

//   cout<<"MAP:"<<endl;
//   cout<<"Expected: 0->1->3->4->2->5->"<<endl;
//   cout<<"Map ottenuta: ";
//   btLnk.Map(
//     [](int& dat){
//       cout<<dat<<"->";
//     }
//   );
//   cout<<endl<<endl;

//   cout<<"PRE_ORDER_MAP:"<<endl;
//   cout<<"Expected: 0->1->3->4->2->5->"<<endl;
//   cout<<"PreOrderMap ottenuto: ";
//   btLnk.PreOrderMap(
//     [](int& dat){
//       cout<<dat<<"->";
//     }
//   );
//   lasd::BTPreOrderIterator<int> itrPre(btLnk);
//   cout<<"\nPreOrderIterator: ";
//   while(!(itrPre.Terminated())){
//     cout<<*itrPre<<"->";
//     ++itrPre;
//   }
//   cout<<endl<<endl;

//   cout<<"POST_ORDER_MAP:"<<endl;
//   cout<<"Expected: 3->4->1->5->2->0->"<<endl;
//   cout<<"PostOrderMap: ";
//   btLnk.PostOrderMap(
//     [](int& dat){
//       cout<<dat<<"->";
//     }
//   );
//   lasd::BTPostOrderIterator<int> itrPost(btLnk);
//   cout<<"\nPostOrderIterator: ";
//   while(!(itrPost.Terminated())){
//     cout<<*itrPost<<"->";
//     ++itrPost;
//   }
//   cout<<endl<<endl;

//   cout<<"IN_ORDER_MAP:"<<endl;
//   cout<<"Expected: 3->1->4->0->5->2->"<<endl;
//   cout<<"InOrderMap: ";
//   btLnk.InOrderMap(
//     [](int& dat){
//       cout<<dat<<"->";
//     }
//   );
//   lasd::BTInOrderIterator<int> itrIn(btLnk);
//   cout<<"\nInOrderIterator: ";
//   while(!(itrIn.Terminated())){
//     cout<<*itrIn<<"->";
//     ++itrIn;
//   }
//   cout<<endl<<endl;

//   cout<<"BREADTH_ORDER_MAP:"<<endl;
//   cout<<"Expected: 0->1->2->3->4->5->"<<endl;
//   cout<<"BreadthMap: ";
//   btLnk.BreadthMap(
//     [](int& dat){
//       cout<<dat<<"->";
//     }
//   );
//   lasd::BTBreadthIterator<int> itrBreadth(btLnk);
//   cout<<"\nBreadthOrderIterator: ";
//   while(!(itrBreadth.Terminated())){
//     cout<<*itrBreadth<<"->";
//     ++itrBreadth;
//   }
//   cout<<endl<<endl;


//   return testIteratori;
// }

// bool TestBST()
// {
//   bool testBST = true;
//   int lines = 1;
//   cout<<"\n\nBegin of BST Test: "<<endl;

//   lasd::Vector<int> vec1;
//   lasd::BST<int> bst1(vec1);
//   bst1.Insert(1);
//   if(bst1.Max() == 1) {
//     cout<<lines++<<" Max is (obtained Max)'"<<bst1.Max()<<"': Correct!"<<endl;
//   } else {
//     cout<<lines++<<" Max is (obtained Min)'"<<bst1.Max()<<": Error!"<<endl;
//     testBST &= false;
//   }

//   lasd::Vector<int> vec2(5);
//   for(int i = 0; i < 5; i ++) {
//     vec2[i] = RandomNumber(gen);
//   }
//   bst1.Clear();
//   bst1.InsertAll(vec2);
//   int ExstactedValue = bst1.MaxNRemove();
//   while(!bst1.Empty()) {
//     if(bst1.Max() > ExstactedValue) {
//       break;
//       cout<<lines++<<" Previous ExtractedMax '"<<ExstactedValue<<"' > Actual ExtractedMax '"<<bst1.Max()<<"': Error!"<<endl;
//       testBST &= false;
//     } else {
//       cout<<lines++<<" Previous ExtractedMax '"<<ExstactedValue<<"' < Actual ExtractedMax '"<<bst1.Max()<<"': Correct!"<<endl;
//     }  
//     ExstactedValue = bst1.MaxNRemove();
//   }

//   lasd::BST<int> bst2;
//   if(bst1 == bst2) {
//     cout<<lines++<<" Two empty BST are equal: Correct!"<<endl;
//   } else {
//     cout<<lines++<<" Two empty BST are NOT equal: Error!"<<endl;
//     testBST &= false;
//   }

//   lasd::BST<int> bst3(vec2);
//   bst1 = bst3;
//   if(bst1 == bst3) {
//     cout<<lines++<<" BST and its BST copy assignament are equal: Correct!"<<endl;  
//   } else {
//     cout<<lines++<<" BST and its BST copy assignament are NOT equal: Error!"<<endl;
//     testBST&= false;
//   }
//   bst2 = std::move(bst3);
//   if(bst2 != bst3) {
//     cout<<lines++<<" BST and its BST move assignament are NOT equal: Correct!"<<endl;
//   } else {
//     cout<<lines++<<" BST and its BST move assignament are equal: Erroe!"<<endl;
//     testBST &= false;
//   }
//   if(bst3.Empty()) {
//     cout<<lines++<<" Moved BST is now Empty: Correct!"<<endl;
//   } else {
//     cout<<lines++<<" Moved BST is NOT Empty: Error!"<<endl;
//     testBST &= false;
//   }
//   if(bst1 == bst2) {
//     cout<<lines++<<" BST1 and BST2 are equal: Correct!"<<endl;
//   } else {
//     cout<<lines++<<" BST1 and BST2 are equal: Error!"<<endl;
//     testBST &= false;
//   }

//   lasd::List<std::string> lst1;
//   lst1.Insert("a");
//   for(int i = 0; i < 3; i++) {
//     lst1.InsertAtFront("a" + lst1.Front());
//   }
//   lasd::BST<std::string> bst4(std::move(lst1));
//   if(bst4.Min().length() < bst4.Max().length()){
//     cout<<lines++<<" Lenght min '"<<bst4.Min()<<"' < lenght max '"<<bst4.Max()<<"': Correct!"<<endl;
//   } else {
//     cout<<lines++<<" Lenght min '"<<bst4.Min()<<"' > lenght max '"<<bst4.Max()<<"': Error!"<<endl;
//     testBST &= false;
//   }
//   if(bst4.Predecessor("aa") == "a") {
//     cout<<lines++<<" 'aa' predecessor is '"<<bst4.Predecessor("aa")<<"': Correct!"<<endl;
//   } else {
//     cout<<lines++<<" 'aa' predecessor is '"<<bst4.Predecessor("aa")<<"': Error!"<<endl;
//     testBST &= false;
//   }
//   if(bst4.Successor("aaa") == "aaaa") {
//     cout<<lines++<<" 'aaa' successor is '"<<bst4.SuccessorNRemove("aaa")<<"': Correct!"<<endl;
//   } else {
//     cout<<lines++<<" 'aaa' successor is '"<<bst4.SuccessorNRemove("aaa")<<"': Error!"<<endl;
//     testBST &= false;
//   }
//   if(!bst4.Exists("aaaa")) {
//     cout<<lines++<<" 'aaa' successor has been successfully deleted!: Correct!"<<endl; 
//   } else {
//     cout<<lines++<<" 'aaa' successore has NOT been deleted!: Error!"<<endl;
//   }
//   bst4.Clear();
//   if(bst4.Empty()) {
//     cout<<lines++<<" BST has been successfully cleared!: Correct!"<<endl; 
//   } else {
//     cout<<lines++<<" BST has NOT been cleared!: Error!"<<endl;
//   }

//   return testBST;
// }


// void TestEsercizio1(){
//   cout<<(TestCostruttori()? "\nPASSATO\n" : "\nNON Passato\n");
//   cout<<(TestAssegnazioni()? "\nPASSATO\n" : "\nNON Passato\n");
//   cout<<(TestDictionaryFunctions()? "\nPASSATO\n" : "\nNON Passato\n");
//   cout<<(TestSort()? "\nPASSATO\n\n" : "\nNON Passato\n\n");
//   cout<<(TestQueueVec()? "\nPASSATO\n\n" : "\nNON Passato\n\n");
// }

// void TestEsercizio2(){
//   bool testBST = TestBST();
//   cout<<"BST Test: ", testBST ? cout<<"Passed!\n" : cout<<"NOT passed!\n";
//   bool testIteratori = TestIteratori();
//   cout<<"(BST into) Iterator Test: ", testIteratori ? cout<<"Passed!\n" : cout<<"NOT passed!\n";

// }


// #endif

#ifndef MYTEST_CPP
#define MYTEST_CPP

#include <iostream>
#include <random>

using namespace std;

#define MAX_SIZE 200
#define SMALL_MAX_SIZE 20
#define MIN_SIZE_0 0
#define MIN_SIZE_1 1

#define NUMERO_TEST_QV 1
#define NUMERO_TEST_SV 1
#define NUMERO_TEST_QL 1
#define NUMERO_TEST_SL 1
#define NUMERO_TEST_ITERATIVI 2

static int static_test_index = 0;

default_random_engine gen(random_device{}());
uniform_int_distribution<int> genSize(MIN_SIZE_0,MAX_SIZE);
uniform_int_distribution<int> genSmallSize(MIN_SIZE_1,SMALL_MAX_SIZE);
uniform_int_distribution<int> genNum(INT32_MIN,INT32_MAX);
uniform_int_distribution<int> genSmallNum(0,SMALL_MAX_SIZE);

#include "test.hpp"

/* ************************************************************************** */
/* ************************** FUNZIONI  ACCESSORIE ************************** */
/* ************************************************************************** */

template <typename Data>
void FoldAdd(const Data& dat, void* acc) {
  *((Data*) acc) += dat;
}

template <typename Data>
void FoldSumAndMultyplyPerPosition(const Data& dat, void* acc) {
  *((Data*) acc) += (dat*static_test_index++);
}


/* ************************************************************************** */
/* ************************** FUNZIONI ESERCIZIO 1 ************************** */
/* ************************************************************************** */

bool TestQueueVec(lasd::QueueVec<int> s2){
    bool test_result_qv = true;
    int numtest_qv = NUMERO_TEST_QV;
    ulong init_size = s2.Size();
    while(numtest_qv>0){
      lasd::QueueVec<int> s1(s2);
      int temp_size = genSize(gen);
      cout<<"\n\n****************************** INIZIO RIEMPIMENTO ******************************\n\n";  
      for(ulong i=0; i<temp_size; i++){
          int temp_num = genNum(gen);
          s1.Enqueue(temp_num);
          cout<<temp_num<<"\t Size(): "<<s1.Size()<<endl;//"\t size: "<<s1.size<<endl;
      }
      cout<<"\n\n****************************** INIZIO SVUOTAMENTO ******************************\n\n";
      while(s1.Size()>0) {
          cout<<s1.HeadNDequeue()<<"\t Size(): "<<s1.Size()<<endl;//"\t size: "<<s1.size<<endl;
          temp_size--;
      }
      if(temp_size+init_size!=0) {
          cout<<"\ntemp: "<<temp_size<<"\tinit: "<<init_size;
          test_result_qv = false;
          cout<<"\nVettore svuotato NON correttamente\n\n";
      } else
          cout<<"\nVettore svuotato correttamente\n\n";
      numtest_qv--;
    }
    return test_result_qv && !numtest_qv;
}

bool TestStackVec(lasd::StackVec<int> s2){
  bool test_result_sv = true;
  int numtest_sv = NUMERO_TEST_SV;
  ulong init_size = s2.Size();
  while(numtest_sv>0){
    lasd::StackVec<int> s1(s2);
    int temp_size = genSize(gen);
    cout<<"\n\n****************************** INIZIO RIEMPIMENTO ******************************\n\n";  
    for(ulong i=0; i<temp_size; i++){
      int temp_num = genNum(gen);
      s1.Push(temp_num);
      cout<<temp_num<<"\t Size(): "<<s1.Size()<<endl;//"\t size: "<<s1.size<<endl;
    }
    cout<<"\n\n****************************** INIZIO SVUOTAMENTO ******************************\n\n";
    while(s1.Size()>0) {
      cout<<s1.TopNPop()<<"\t Size(): "<<s1.Size()<<endl;//"\t size: "<<s1.size<<endl;
      temp_size--;
    }
    if(temp_size+init_size!=0) {
      cout<<"\ntemp: "<<temp_size<<"\tinit: "<<init_size;
      test_result_sv = false;
      cout<<"\nVettore svuotato NON correttamente\n\n";
    } else
        cout<<"\nVettore svuotato correttamente\n\n";
    numtest_sv--;
  }
  return test_result_sv && !numtest_sv;
}

bool TestQueueLst(lasd::QueueLst<int> s2){
  bool test_result_ql = true;
  int numtest_ql = NUMERO_TEST_QL;
  ulong init_size = s2.Size();
  while(numtest_ql>0){
    lasd::QueueLst<int> s1(s2);
    int temp_size = genSize(gen);
    cout<<"\n\n****************************** INIZIO RIEMPIMENTO ******************************\n\n";  
    for(ulong i=0; i<temp_size; i++){
      int temp_num = genNum(gen);
      s1.Enqueue(temp_num);
      cout<<temp_num<<"\t Size(): "<<s1.Size()<<endl;//"\t size: "<<s1.size<<endl;
    }
    cout<<"\n\n****************************** INIZIO SVUOTAMENTO ******************************\n\n";
    while(s1.Size()>0) {
      cout<<s1.HeadNDequeue()<<"\t Size(): "<<s1.Size()<<endl;//"\t size: "<<endls1.size<<endl;
      temp_size--;
    }
    if(temp_size+init_size!=0) {
      cout<<"\ntemp: "<<temp_size<<"\tinit: "<<init_size;
      test_result_ql = false;
      cout<<"\nVettore svuotato NON correttamente\n\n";
    } else
        cout<<"\nVettore svuotato correttamente\n\n";
    numtest_ql--;
  }
  return test_result_ql && !numtest_ql;
}

bool TestStackLst(lasd::StackLst<int> s2){
  bool test_result_sl = true;
  int numtest_sl = NUMERO_TEST_SL;
  ulong init_size = s2.Size();
  while(numtest_sl>0){
    lasd::StackLst<int> s1(s2);
    int temp_size = genSize(gen);
    cout<<"\n\n****************************** INIZIO RIEMPIMENTO ******************************\n\n";  
    for(ulong i=0; i<temp_size; i++){
      int temp_num = genNum(gen);
      s1.Push(temp_num);
      cout<<temp_num<<"\t Size(): "<<s1.Size()<<endl;//"\t size: "<<s1.size<<endl;
    }
    cout<<"\n\n****************************** INIZIO SVUOTAMENTO ******************************\n\n";
    while(s1.Size()>0) {
      cout<<s1.TopNPop()<<"\t Size(): "<<s1.Size()<<endl;//"\t size: "<<s1.size<<endl;
      temp_size--;
    }
    if(temp_size+init_size!=0) {
      cout<<"\ntemp: "<<temp_size<<"\tinit: "<<init_size;
      test_result_sl = false;
      cout<<"\nLista svuotata NON correttamente\n\n";
    } else
        cout<<"\nLista svuotata correttamente\n\n";
    numtest_sl--;
  }
  return test_result_sl && !numtest_sl;
}


/* ************************************************************************** */

bool TestCopyQueueVecFromVec(){
  bool correct=true;
  lasd::Vector<int> v1(genSmallSize(gen));
  for(int i=0; i<v1.Size(); i++){
    int temp_num = genSmallNum(gen);
    v1[i]=temp_num;
  }
  lasd::QueueVec<int> qv1(v1);
  lasd::QueueVec<int> qv2(qv1);

  if(qv1!=qv2)
    correct=false;
  while(qv1.Size()>0)
    cout<<qv1.HeadNDequeue()<<"\t";
  cout<<endl;
  while(qv2.Size()>0)
    cout<<qv2.HeadNDequeue()<<"\t";
  cout<<endl;
  if(qv1!=qv2)
    correct=false;
  cout<<endl;
  return correct;
}

bool TestCopyQueueVecFromLst(){
  bool correct=true;
  lasd::List<int> l1;
  int temp_size = genSmallSize(gen);
  for(int i=0; i<(temp_size*2); i++){
    int temp_num1 = genSmallNum(gen);
    l1.InsertAtBack(temp_num1);
    int temp_num2 = genSmallNum(gen);
    l1.InsertAtFront(temp_num2);
  }
  lasd::QueueVec<int> qv3(l1);
  lasd::QueueVec<int> qv4(qv3);

  if(qv3!=qv4)
    correct=false;
  while(qv3.Size()>0)
    cout<<qv3.HeadNDequeue()<<"\t";
  cout<<endl;
  while(qv4.Size()>0)
    cout<<qv4.HeadNDequeue()<<"\t";
  cout<<endl;
  if(qv3!=qv4)
    correct=false;
  cout<<endl;
  return correct;
}


bool TestCopyQueueLstFromLst(){
  bool correct=true;
  lasd::List<int> l2;
  int temp_size = genSmallSize(gen);
  for(int i=0; i<(temp_size*2); i++){
    int temp_num1 = genSmallNum(gen);
    l2.InsertAtBack(temp_num1);
    int temp_num2 = genSmallNum(gen);
    l2.InsertAtFront(temp_num2);
  }
  lasd::QueueLst<int> ql1(l2);
  lasd::QueueLst<int> ql2(ql1);
  
  if(ql1!=ql2)
    correct=false;
  while(ql1.Size()>0)
    cout<<ql1.HeadNDequeue()<<"\t";
  cout<<endl;
  while(ql2.Size()>0)
    cout<<ql2.HeadNDequeue()<<"\t";
  cout<<endl;
  if(ql1!=ql2)
    correct=false;
  cout<<endl;
  return correct;
}


bool TestCopyQueueLstFromVec(){
  bool correct=true;
  lasd::Vector<int> v2(genSmallSize(gen));
  for(int i=0; i<v2.Size(); i++){
    int temp_num = genSmallNum(gen);
    v2[i]=temp_num;
  }
  lasd::QueueLst<int> ql3(v2);
  lasd::QueueLst<int> ql4(ql3);

  if(ql3!=ql4)
    correct=false;
  while(ql3.Size()>0)
    cout<<ql3.HeadNDequeue()<<"\t";
  cout<<endl;
  while(ql4.Size()>0)
    cout<<ql4.HeadNDequeue()<<"\t";
  cout<<endl;
  if(ql3!=ql4)
    correct=false;
  cout<<endl;
  return correct;
}

/* ************************************************************************** */

bool TestCopyAssignementQueueVecFromVec(){
  bool correct=true;
  lasd::Vector<int> v1(genSmallSize(gen));
  for(int i=0; i<v1.Size(); i++){
    int temp_num = genSmallNum(gen);
    v1[i]=temp_num;
  }
  lasd::QueueVec<int> qv1(v1);
  lasd::QueueVec<int> qv2;
  qv2=qv1;

  if(qv1!=qv2)
    correct=false;
  while(qv1.Size()>0)
    cout<<qv1.HeadNDequeue()<<"\t";
  cout<<endl;
  while(qv2.Size()>0)
    cout<<qv2.HeadNDequeue()<<"\t";
  cout<<endl;
  if(qv1!=qv2)
    correct=false;
  cout<<endl;
  return correct;
}

bool TestCopyAssignementQueueVecFromLst(){
  bool correct=true;
  lasd::List<int> l1;
  int temp_size = genSmallSize(gen);
  for(int i=0; i<(temp_size*2); i++){
    int temp_num1 = genSmallNum(gen);
    l1.InsertAtBack(temp_num1);
    int temp_num2 = genSmallNum(gen);
    l1.InsertAtFront(temp_num2);
  }
  lasd::QueueVec<int> qv3(l1);
  lasd::QueueVec<int> qv4;
  qv4=qv3;

  if(qv3!=qv4)
    correct=false;
  while(qv3.Size()>0)
    cout<<qv3.HeadNDequeue()<<"\t";
  cout<<endl;
  while(qv4.Size()>0)
    cout<<qv4.HeadNDequeue()<<"\t";
  cout<<endl;
  if(qv3!=qv4)
    correct=false;
  cout<<endl;
  return correct;
}


bool TestCopyAssignementQueueLstFromLst(){
  bool correct=true;
  lasd::List<int> l2;
  int temp_size = genSmallSize(gen);
  for(int i=0; i<(temp_size*2); i++){
    int temp_num1 = genSmallNum(gen);
    l2.InsertAtBack(temp_num1);
    int temp_num2 = genSmallNum(gen);
    l2.InsertAtFront(temp_num2);
  }
  lasd::QueueLst<int> ql1(l2);
  lasd::QueueLst<int> ql2;
  ql2=ql1;
  
  if(ql1!=ql2)
    correct=false;
  while(ql1.Size()>0)
    cout<<ql1.HeadNDequeue()<<"\t";
  cout<<endl;
  while(ql2.Size()>0)
    cout<<ql2.HeadNDequeue()<<"\t";
  cout<<endl;
  if(ql1!=ql2)
    correct=false;
  cout<<endl;
  return correct;
}


bool TestCopyAssignementQueueLstFromVec(){
  bool correct=true;
  lasd::Vector<int> v2(genSmallSize(gen));
  for(int i=0; i<v2.Size(); i++){
    int temp_num = genSmallNum(gen);
    v2[i]=temp_num;
  }
  lasd::QueueLst<int> ql3(v2);
  lasd::QueueLst<int> ql4;
  ql4=ql3;

  if(ql3!=ql4)
    correct=false;
  while(ql3.Size()>0)
    cout<<ql3.HeadNDequeue()<<"\t";
  cout<<endl;
  while(ql4.Size()>0)
    cout<<ql4.HeadNDequeue()<<"\t";
  cout<<endl;
  if(ql3!=ql4)
    correct=false;
  cout<<endl;
  return correct;
}

/* ************************************************************************** */

bool TestMoveQueueVecFromVec(){
  bool correct=true;
  lasd::Vector<int> v1(genSmallSize(gen));
  for(int i=0; i<v1.Size(); i++){
    int temp_num = genSmallNum(gen);
    v1[i]=temp_num;
  }
  lasd::QueueVec<int> qv1(move(v1));
  lasd::QueueVec<int> qv2(move(qv1));

  if(!(qv1.Empty()))
    correct=false;
  if(v1.Empty())
    correct=false;
  cout<<"v1 Empty? "<<v1.Empty()<<endl;
  cout<<"qv1 Empty? "<<qv1.Empty()<<endl;
  cout<<"qv2 Empty? "<<qv2.Empty()<<endl;
  while(qv2.Size()>0)
    cout<<qv2.HeadNDequeue()<<"\t";
  cout<<endl;
  if(!(qv2.Empty()))
    correct=false;
  cout<<endl;
  return correct;
}

bool TestMoveQueueVecFromLst(){
  bool correct=true;
  lasd::List<int> l1;
  int temp_size = genSmallSize(gen);
  for(int i=0; i<(temp_size*2); i++){
    int temp_num1 = genSmallNum(gen);
    l1.InsertAtBack(temp_num1);
    int temp_num2 = genSmallNum(gen);
    l1.InsertAtFront(temp_num2);
  }
  lasd::QueueVec<int> qv3(move(l1));
  lasd::QueueVec<int> qv4(move(qv3));

  if(!(qv3.Empty()))
    correct=false;
  if(l1.Empty())
    correct=false;
  cout<<"11 Empty? "<<l1.Empty()<<endl;
  cout<<"qv3 Empty? "<<qv3.Empty()<<endl;
  cout<<"qv4 Empty? "<<qv4.Empty()<<endl;
  while(qv4.Size()>0)
    cout<<qv4.HeadNDequeue()<<"\t";
  cout<<endl;
  if(!(qv4.Empty()))
    correct=false;
  cout<<endl;
  return correct;
}


bool TestMoveQueueLstFromLst(){
  bool correct=true;
  lasd::List<int> l2;
  int temp_size = genSmallSize(gen);
  for(int i=0; i<(temp_size*2); i++){
    int temp_num1 = genSmallNum(gen);
    l2.InsertAtBack(temp_num1);
    int temp_num2 = genSmallNum(gen);
    l2.InsertAtFront(temp_num2);
  }
  lasd::QueueLst<int> ql1(move(l2));
  lasd::QueueLst<int> ql2(move(ql1));
  
  if(!(ql1.Empty()))
    correct=false;
  if(l2.Empty())
    correct=false;
  cout<<"l2 Empty? "<<l2.Empty()<<endl;
  cout<<"ql1 Empty? "<<ql1.Empty()<<endl;
  cout<<"ql2 Empty? "<<ql2.Empty()<<endl;
  while(ql2.Size()>0)
    cout<<ql2.HeadNDequeue()<<"\t";
  cout<<endl;
  if(!(ql2.Empty()))
    correct=false;
  cout<<endl;
  return correct;
}


bool TestMoveQueueLstFromVec(){
  bool correct=true;
  lasd::Vector<int> v2(genSmallSize(gen));
  for(int i=0; i<v2.Size(); i++){
    int temp_num = genSmallNum(gen);
    v2[i]=temp_num;
  }
  lasd::QueueVec<int> ql3(move(v2));
  lasd::QueueVec<int> ql4(move(ql3));

  if(!(ql3.Empty()))
    correct=false;
  if(v2.Empty())
    correct=false;
  cout<<"v2 Empty? "<<v2.Empty()<<endl;
  cout<<"ql3 Empty? "<<ql3.Empty()<<endl;
  cout<<"ql4 Empty? "<<ql4.Empty()<<endl;
  while(ql4.Size()>0)
    cout<<ql4.HeadNDequeue()<<"\t";
  cout<<endl;
  if(!(ql4.Empty()))
    correct=false;
  cout<<endl;
  return correct;
}

/* ************************************************************************** */

bool TestMoveAssignementQueueVecFromVec(){
  bool correct=true;
  lasd::Vector<int> v1(genSmallSize(gen));
  for(int i=0; i<v1.Size(); i++){
    int temp_num = genSmallNum(gen);
    v1[i]=temp_num;
  }
  lasd::QueueVec<int> qv1(move(v1));
  lasd::QueueVec<int> qv2;
  qv2=move(qv1);

  if(!(qv1.Empty()))
    correct=false;
  if(v1.Empty())
    correct=false;
  cout<<"v1 Empty? "<<v1.Empty()<<endl;
  cout<<"qv1 Empty? "<<qv1.Empty()<<endl;
  cout<<"qv2 Empty? "<<qv2.Empty()<<endl;
  while(qv2.Size()>0)
    cout<<qv2.HeadNDequeue()<<"\t";
  cout<<endl;
  if(!(qv2.Empty()))
    correct=false;
  cout<<endl;
  return correct;
}

bool TestMoveAssignementQueueVecFromLst(){
  bool correct=true;
  lasd::List<int> l1;
  int temp_size = genSmallSize(gen);
  for(int i=0; i<(temp_size*2); i++){
    int temp_num1 = genSmallNum(gen);
    l1.InsertAtBack(temp_num1);
    int temp_num2 = genSmallNum(gen);
    l1.InsertAtFront(temp_num2);
  }
  lasd::QueueVec<int> qv3(move(l1));
  lasd::QueueVec<int> qv4;
  qv4=move(qv3);

  if(!(qv3.Empty()))
    correct=false;
  if(l1.Empty())
    correct=false;
  cout<<"l1 Empty? "<<l1.Empty()<<endl;
  cout<<"qv3 Empty? "<<qv3.Empty()<<endl;
  cout<<"qv4 Empty? "<<qv4.Empty()<<endl;
  while(qv4.Size()>0)
    cout<<qv4.HeadNDequeue()<<"\t";
  cout<<endl;
  if(!(qv4.Empty()))
    correct=false;
  cout<<endl;
  return correct;
}


bool TestMoveAssignementQueueLstFromLst(){
  bool correct=true;
  lasd::List<int> l2;
  int temp_size = genSmallSize(gen);
  for(int i=0; i<(temp_size*2); i++){
    int temp_num1 = genSmallNum(gen);
    l2.InsertAtBack(temp_num1);
    int temp_num2 = genSmallNum(gen);
    l2.InsertAtFront(temp_num2);
  }
  lasd::QueueLst<int> ql1(move(l2));
  lasd::QueueLst<int> ql2;
  ql2=move(ql1);
  
  if(!(ql1.Empty()))
    correct=false;
  if(l2.Empty())
    correct=false;
  cout<<"l2 Empty? "<<l2.Empty()<<endl;
  cout<<"ql1 Empty? "<<ql1.Empty()<<endl;
  cout<<"ql2 Empty? "<<ql2.Empty()<<endl;
  while(ql2.Size()>0)
    cout<<ql2.HeadNDequeue()<<"\t";
  cout<<endl;
  if(!(ql2.Empty()))
    correct=false;
  cout<<endl;
  return correct;
}


bool TestMoveAssignementQueueLstFromVec(){
  bool correct=true;
  lasd::Vector<int> v2(genSmallSize(gen));
  for(int i=0; i<v2.Size(); i++){
    int temp_num = genSmallNum(gen);
    v2[i]=temp_num;
  }
  lasd::QueueVec<int> ql3(move(v2));
  lasd::QueueVec<int> ql4;
  ql4=move(ql3);

  if(!(ql3.Empty()))
    correct=false;
  if(v2.Empty())
    correct=false;
  cout<<"v2 Empty? "<<v2.Empty()<<endl;
  cout<<"ql3 Empty? "<<ql3.Empty()<<endl;
  cout<<"ql4 Empty? "<<ql4.Empty()<<endl;
  while(ql4.Size()>0)
    cout<<ql4.HeadNDequeue()<<"\t";
  cout<<endl;
  if(!(ql4.Empty()))
    correct=false;
  cout<<endl;
  return correct;
}

/* ************************************************************************** */

bool TestCopyStackVecFromVec(){
  bool correct=true;
  lasd::Vector<int> v1(genSmallSize(gen));
  for(int i=0; i<v1.Size(); i++){
    int temp_num = genSmallNum(gen);
    v1[i]=temp_num;
  }
  lasd::StackVec<int> sv1(v1);
  lasd::StackVec<int> sv2(sv1);

  if(sv1!=sv2)
    correct=false;
  while(sv1.Size()>0)
    cout<<sv1.TopNPop()<<"\t";
  cout<<endl;
  while(sv2.Size()>0)
    cout<<sv2.TopNPop()<<"\t";
  cout<<endl;
  if(sv1!=sv2)
    correct=false;
  cout<<endl;
  return correct;
}

bool TestCopyStackVecFromLst(){
  bool correct=true;
  lasd::List<int> l1;
  int temp_size = genSmallSize(gen);
  for(int i=0; i<(temp_size*2); i++){
    int temp_num1 = genSmallNum(gen);
    l1.InsertAtBack(temp_num1);
    int temp_num2 = genSmallNum(gen);
    l1.InsertAtFront(temp_num2);
  }
  lasd::StackVec<int> sv3(l1);
  lasd::StackVec<int> sv4(sv3);

  if(sv3!=sv4)
    correct=false;
  while(sv3.Size()>0)
    cout<<sv3.TopNPop()<<"\t";
  cout<<endl;
  while(sv4.Size()>0)
    cout<<sv4.TopNPop()<<"\t";
  cout<<endl;
  if(sv3!=sv4)
    correct=false;
  cout<<endl;
  return correct;
}


bool TestCopyStackLstFromLst(){
  bool correct=true;
  lasd::List<int> l2;
  int temp_size = genSmallSize(gen);
  for(int i=0; i<(temp_size*2); i++){
    int temp_num1 = genSmallNum(gen);
    l2.InsertAtBack(temp_num1);
    int temp_num2 = genSmallNum(gen);
    l2.InsertAtFront(temp_num2);
  }
  lasd::StackLst<int> sl1(l2);
  lasd::StackLst<int> sl2(sl1);
  
  if(sl1!=sl2)
    correct=false;
  while(sl1.Size()>0)
    cout<<sl1.TopNPop()<<"\t";
  cout<<endl;
  while(sl2.Size()>0)
    cout<<sl2.TopNPop()<<"\t";
  cout<<endl;
  if(sl1!=sl2)
    correct=false;
  cout<<endl;
  return correct;
}


bool TestCopyStackLstFromVec(){
  bool correct=true;
  lasd::Vector<int> v2(genSmallSize(gen));
  for(int i=0; i<v2.Size(); i++){
    int temp_num = genSmallNum(gen);
    v2[i]=temp_num;
  }
  lasd::StackLst<int> sl3(v2);
  lasd::StackLst<int> sl4(sl3);

  if(sl3!=sl4)
    correct=false;
  while(sl3.Size()>0)
    cout<<sl3.TopNPop()<<"\t";
  cout<<endl;
  while(sl4.Size()>0)
    cout<<sl4.TopNPop()<<"\t";
  cout<<endl;
  if(sl3!=sl4)
    correct=false;
  cout<<endl;
  return correct;
}

/* ************************************************************************** */

bool TestCopyAssignementStackVecFromVec(){
  bool correct=true;
  lasd::Vector<int> v1(genSmallSize(gen));
  for(int i=0; i<v1.Size(); i++){
    int temp_num = genSmallNum(gen);
    v1[i]=temp_num;
  }
  lasd::StackVec<int> sv1(v1);
  lasd::StackVec<int> sv2;
  sv2=sv1;

  if(sv1!=sv2)
    correct=false;
  while(sv1.Size()>0)
    cout<<sv1.TopNPop()<<"\t";
  cout<<endl;
  while(sv2.Size()>0)
    cout<<sv2.TopNPop()<<"\t";
  cout<<endl;
  if(sv1!=sv2)
    correct=false;
  cout<<endl;
  return correct;
}

bool TestCopyAssignementStackVecFromLst(){
  bool correct=true;
  lasd::List<int> l1;
  int temp_size = genSmallSize(gen);
  for(int i=0; i<(temp_size*2); i++){
    int temp_num1 = genSmallNum(gen);
    l1.InsertAtBack(temp_num1);
    int temp_num2 = genSmallNum(gen);
    l1.InsertAtFront(temp_num2);
  }
  lasd::StackVec<int> sv3(l1);
  lasd::StackVec<int> sv4;
  sv4=sv3;

  if(sv3!=sv4)
    correct=false;
  while(sv3.Size()>0)
    cout<<sv3.TopNPop()<<"\t";
  cout<<endl;
  while(sv4.Size()>0)
    cout<<sv4.TopNPop()<<"\t";
  cout<<endl;
  if(sv3!=sv4)
    correct=false;
  cout<<endl;
  return correct;
}


bool TestCopyAssignementStackLstFromLst(){
  bool correct=true;
  lasd::List<int> l2;
  int temp_size = genSmallSize(gen);
  for(int i=0; i<(temp_size*2); i++){
    int temp_num1 = genSmallNum(gen);
    l2.InsertAtBack(temp_num1);
    int temp_num2 = genSmallNum(gen);
    l2.InsertAtFront(temp_num2);
  }
  lasd::StackLst<int> sl1(l2);
  lasd::StackLst<int> sl2;
  sl2=sl1;
  
  if(sl1!=sl2)
    correct=false;
  while(sl1.Size()>0)
    cout<<sl1.TopNPop()<<"\t";
  cout<<endl;
  while(sl2.Size()>0)
    cout<<sl2.TopNPop()<<"\t";
  cout<<endl;
  if(sl1!=sl2)
    correct=false;
  cout<<endl;
  return correct;
}


bool TestCopyAssignementStackLstFromVec(){
  bool correct=true;
  lasd::Vector<int> v2(genSmallSize(gen));
  for(int i=0; i<v2.Size(); i++){
    int temp_num = genSmallNum(gen);
    v2[i]=temp_num;
  }
  lasd::StackLst<int> sl3(v2);
  lasd::StackLst<int> sl4;
  sl4=sl3;

  if(sl3!=sl4)
    correct=false;
  while(sl3.Size()>0)
    cout<<sl3.TopNPop()<<"\t";
  cout<<endl;
  while(sl4.Size()>0)
    cout<<sl4.TopNPop()<<"\t";
  cout<<endl;
  if(sl3!=sl4)
    correct=false;
  cout<<endl;
  return correct;
}

/* ************************************************************************** */

bool TestMoveStackVecFromVec(){
  bool correct=true;
  lasd::Vector<int> v1(genSmallSize(gen));
  for(int i=0; i<v1.Size(); i++){
    int temp_num = genSmallNum(gen);
    v1[i]=temp_num;
  }
  lasd::StackVec<int> sv1(move(v1));
  lasd::StackVec<int> sv2(move(sv1));

  if(!(sv1.Empty()))
    correct=false;
  if(v1.Empty())
    correct=false;
  cout<<"v1 Empty? "<<v1.Empty()<<endl;
  cout<<"sv1 Empty? "<<sv1.Empty()<<endl;
  cout<<"sv2 Empty? "<<sv2.Empty()<<endl;
  while(sv2.Size()>0)
    cout<<sv2.TopNPop()<<"\t";
  cout<<endl;
  if(!(sv2.Empty()))
    correct=false;
  cout<<endl;
  return correct;
}

bool TestMoveStackVecFromLst(){
  bool correct=true;
  lasd::List<int> l1;
  int temp_size = genSmallSize(gen);
  for(int i=0; i<(temp_size*2); i++){
    int temp_num1 = genSmallNum(gen);
    l1.InsertAtBack(temp_num1);
    int temp_num2 = genSmallNum(gen);
    l1.InsertAtFront(temp_num2);
  }
  lasd::StackVec<int> sv3(move(l1));
  lasd::StackVec<int> sv4(move(sv3));

  if(!(sv3.Empty()))
    correct=false;
  if(l1.Empty())
    correct=false;
  cout<<"11 Empty? "<<l1.Empty()<<endl;
  cout<<"sv3 Empty? "<<sv3.Empty()<<endl;
  cout<<"sv4 Empty? "<<sv4.Empty()<<endl;
  while(sv4.Size()>0)
    cout<<sv4.TopNPop()<<"\t";
  cout<<endl;
  if(!(sv4.Empty()))
    correct=false;
  cout<<endl;
  return correct;
}


bool TestMoveStackLstFromLst(){
  bool correct=true;
  lasd::List<int> l2;
  int temp_size = genSmallSize(gen);
  for(int i=0; i<(temp_size*2); i++){
    int temp_num1 = genSmallNum(gen);
    l2.InsertAtBack(temp_num1);
    int temp_num2 = genSmallNum(gen);
    l2.InsertAtFront(temp_num2);
  }
  lasd::StackLst<int> sl1(move(l2));
  lasd::StackLst<int> sl2(move(sl1));
  
  if(!(sl1.Empty()))
    correct=false;
  if(l2.Empty())
    correct=false;
  cout<<"l2 Empty? "<<l2.Empty()<<endl;
  cout<<"sl1 Empty? "<<sl1.Empty()<<endl;
  cout<<"sl2 Empty? "<<sl2.Empty()<<endl;
  while(sl2.Size()>0)
    cout<<sl2.TopNPop()<<"\t";
  cout<<endl;
  if(!(sl2.Empty()))
    correct=false;
  cout<<endl;
  return correct;
}


bool TestMoveStackLstFromVec(){
  bool correct=true;
  lasd::Vector<int> v2(genSmallSize(gen));
  for(int i=0; i<v2.Size(); i++){
    int temp_num = genSmallNum(gen);
    v2[i]=temp_num;
  }
  lasd::StackLst<int> sl3(move(v2));
  lasd::StackLst<int> sl4(move(sl3));

  if(!(sl3.Empty()))
    correct=false;
  if(v2.Empty())
    correct=false;
  cout<<"v2 Empty? "<<v2.Empty()<<endl;
  cout<<"sl3 Empty? "<<sl3.Empty()<<endl;
  cout<<"sl4 Empty? "<<sl4.Empty()<<endl;
  while(sl4.Size()>0)
    cout<<sl4.TopNPop()<<"\t";
  cout<<endl;
  if(!(sl4.Empty()))
    correct=false;
  cout<<endl;
  return correct;
}

/* ************************************************************************** */

bool TestMoveAssignementStackVecFromVec(){
  bool correct=true;
  lasd::Vector<int> v1(genSmallSize(gen));
  for(int i=0; i<v1.Size(); i++){
    int temp_num = genSmallNum(gen);
    v1[i]=temp_num;
  }
  lasd::StackVec<int> sv1(move(v1));
  lasd::StackVec<int> sv2;
  sv2=move(sv1);

  if(!(sv1.Empty()))
    correct=false;
  if(v1.Empty())
    correct=false;
  cout<<"v1 Empty? "<<v1.Empty()<<endl;
  cout<<"sv1 Empty? "<<sv1.Empty()<<endl;
  cout<<"sv2 Empty? "<<sv2.Empty()<<endl;
  while(sv2.Size()>0)
    cout<<sv2.TopNPop()<<"\t";
  cout<<endl;
  if(!(sv2.Empty()))
    correct=false;
  cout<<endl;
  return correct;
}

bool TestMoveAssignementStackVecFromLst(){
  bool correct=true;
  lasd::List<int> l1;
  int temp_size = genSmallSize(gen);
  for(int i=0; i<(temp_size*2); i++){
    int temp_num1 = genSmallNum(gen);
    l1.InsertAtBack(temp_num1);
    int temp_num2 = genSmallNum(gen);
    l1.InsertAtFront(temp_num2);
  }
  lasd::StackVec<int> sv3(move(l1));
  lasd::StackVec<int> sv4;
  sv4=move(sv3);

  if(!(sv3.Empty()))
    correct=false;
  if(l1.Empty())
    correct=false;
  cout<<"l1 Empty? "<<l1.Empty()<<endl;
  cout<<"sv3 Empty? "<<sv3.Empty()<<endl;
  cout<<"sv4 Empty? "<<sv4.Empty()<<endl;
  while(sv4.Size()>0)
    cout<<sv4.TopNPop()<<"\t";
  cout<<endl;
  if(!(sv4.Empty()))
    correct=false;
  cout<<endl;
  return correct;
}


bool TestMoveAssignementStackLstFromLst(){
  bool correct=true;
  lasd::List<int> l2;
  int temp_size = genSmallSize(gen);
  for(int i=0; i<(temp_size*2); i++){
    int temp_num1 = genSmallNum(gen);
    l2.InsertAtBack(temp_num1);
    int temp_num2 = genSmallNum(gen);
    l2.InsertAtFront(temp_num2);
  }
  lasd::StackLst<int> sl1(move(l2));
  lasd::StackLst<int> sl2;
  sl2=move(sl1);
  
  if(!(sl1.Empty()))
    correct=false;
  if(sl2.Empty())
    correct=false;
  cout<<"l2 Empty? "<<l2.Empty()<<endl;
  cout<<"sl1 Empty? "<<sl1.Empty()<<endl;
  cout<<"sl2 Empty? "<<sl2.Empty()<<endl;
  while(sl2.Size()>0)
    cout<<sl2.TopNPop()<<"\t";
  cout<<endl;
  if(!(sl2.Empty()))
    correct=false;
  cout<<endl;
  return correct;
}


bool TestMoveAssignementStackLstFromVec(){
  bool correct=true;
  lasd::Vector<int> v2(genSmallSize(gen));
  for(int i=0; i<v2.Size(); i++){
    int temp_num = genSmallNum(gen);
    v2[i]=temp_num;
  }
  lasd::StackLst<int> sl3;
  sl3=move(v2);
  lasd::StackLst<int> sl4;
  sl4=move(sl3);

  if(!(sl3.Empty()))
    correct=false;
  if(v2.Empty())
    correct=false;
  cout<<"v2 Empty? "<<v2.Empty()<<endl;
  cout<<"sl3 Empty? "<<sl3.Empty()<<endl;
  cout<<"sl4 Empty? "<<sl4.Empty()<<endl;
  while(sl4.Size()>0)
    cout<<sl4.TopNPop()<<"\t";
  cout<<endl;
  if(!(sl4.Empty()))
    correct=false;
  cout<<endl;
  return correct;
}

/* ************************************************************************** */

bool TestEqualVector(){
    bool correct=true;
    int temp_size = genSize(gen)+1;
    lasd::Vector<int> v1(temp_size);
    lasd::Vector<int> v2(temp_size);
    for(int i=0; i<temp_size; i++) v2[i]=v1[i]=genNum(gen);
    correct&=(v1==v2);
    v1[genSize(gen)%temp_size]=genNum(gen);
    correct&=!(v1==v2);
    v1.Clear();
    v2.Clear();
    correct&=(v1==v2);
    return correct;
}

bool TestEqualList(){
    bool correct=true;
    int temp_size = genSize(gen)+1;
    lasd::List<int> l1;
    lasd::List<int> l2;
    for(int i=0; i<temp_size; i++){
        int temp_num = genNum(gen);
        l1.InsertAtBack(temp_num);
        l2.InsertAtBack(temp_num);
    } 
    correct&=(l1==l2);
    l1[genSize(gen)%temp_size]=genNum(gen);
    correct&=(l1!=l2);
    l1.Clear();
    l2.Clear();
    correct&=(l1==l2);
    return correct;
}

bool TestEqualStackVec(){
    bool correct=true;
    int temp_size = genSize(gen)+1;
    lasd::StackVec<int> s1;
    lasd::StackVec<int> s2;
    for(int i=0; i<temp_size; i++){
        int temp_num = genNum(gen);
        s1.Push(temp_num);
        s2.Push(temp_num);
    } 
    correct&=(s1==s2);
    s2.Pop();
    s2.Push(genNum(gen));
    correct&=(s1!=s2);
    s1.Clear();
    s2.Clear();
    correct&=(s1==s2);
    return correct;
}

bool TestEqualStackLst(){
    bool correct=true;
    int temp_size = genSize(gen)+1;
    lasd::StackLst<int> s1;
    lasd::StackLst<int> s2;
    for(int i=0; i<temp_size; i++) {
        int temp_num = genNum(gen);
        s1.Push(temp_num);
        s2.Push(temp_num);
    } 
    correct&=(s1==s2);
    s2.Pop();
    s2.Push(genNum(gen));
    correct&=(s1!=s2);
    s1.Clear();
    s2.Clear();
    correct&=(s1==s2);
    return correct;
}

bool TestEqualQueueVec(){
    bool correct=true;
    int temp_size = genSize(gen)+1;
    lasd::QueueVec<int> s1;
    lasd::QueueVec<int> s2;
    for(int i=0; i<temp_size; i++) {
        int temp_num = genNum(gen);
        s1.Enqueue(temp_num);
        s2.Enqueue(temp_num);
    } 
    correct&=(s1==s2);
    s2.Dequeue();
    s2.Enqueue(genNum(gen));
    correct&=(s1!=s2);
    s1.Clear();
    s2.Clear();
    correct&=(s1==s2);
    return correct;
}

bool TestEqualQueueLst(){
    bool correct=true;
    int temp_size = genSize(gen)+1;
    lasd::QueueLst<int> s1;
    lasd::QueueLst<int> s2;
    for(int i=0; i<temp_size; i++) {
        int temp_num = genNum(gen);
        s1.Enqueue(temp_num);
        s2.Enqueue(temp_num);
    } 
    correct&=(s1==s2);
    s2.Dequeue();
    s2.Enqueue(genNum(gen));
    correct&=(s1!=s2);
    s1.Clear();
    s2.Clear();
    correct&=(s1==s2);
    return correct;
}

/* ************************************************************************** */


bool TestInsertCopyInDictionary(){
  bool inserted=false;
  bool isThere=false;

  int temp_num1=genSmallNum(gen);
  cout<<"numero creato= "<<temp_num1<<endl;

  lasd::List<int> l1;
  for(int i=0; i<genSmallSize(gen); i++){
    int temp_num2=genSmallNum(gen);
    l1.InsertAtFront(temp_num2);
  }

  for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
    if(l1[i]==temp_num1)
      isThere=true;
  }
  cout<<endl;

  if(l1.Insert(temp_num1)){
    inserted=true;
    cout<<"Elemento inserito!"<<endl;
    for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
    }
    cout<<endl;
    if (isThere==true)
      return false;
  }
  else
    cout<<"Elemento NON inserito!"<<endl;
  
  return true;
}

bool TestInsertMoveInDictionary(){
  bool inserted=false;
  bool isThere=false;

  int temp_num1=genSmallNum(gen);
  cout<<"numero creato= "<<temp_num1<<endl;

  lasd::List<int> l1;
  for(int i=0; i<genSmallSize(gen); i++){
    int temp_num2=genSmallNum(gen);
    l1.InsertAtFront(temp_num2);
  }

  for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
    if(l1[i]==temp_num1)
      isThere=true;
  }
  cout<<endl;

  if(l1.Insert(move(temp_num1))){
    inserted=true;
    cout<<"Elemento inserito!"<<endl;
    for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
    }
    cout<<endl;
    if (isThere==true)
      return false;
  }
  else
    cout<<"Elemento NON inserito!"<<endl;
  
  return true;
}


bool TestRemoveInDictionary(){
  bool result=true;
  bool isThere=false;

  int temp_num1=genSmallNum(gen);
  cout<<"numero creato= "<<temp_num1<<endl;

  lasd::List<int> l1;
  for(int i=0; i<genSmallSize(gen); i++){
    int temp_num2=genSmallNum(gen);
    l1.InsertAtFront(temp_num2);
  }

  for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
    if(l1[i]==temp_num1)
      isThere=true;
  }
  cout<<endl;

  if(l1.Remove(temp_num1)){
    result=true;
    cout<<"Elemento rimosso!"<<endl;
    for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
    }
    cout<<endl;
    if (isThere==false)
      return false;
  }
  else
    cout<<"Elemento NON rimosso!"<<endl;
  
  return true;
}



bool TestInsertAllCopyInDictionary(){
  bool result=false;

  lasd::Vector<int> v1(3);
  v1[0]=1;
  v1[1]=2;
  v1[2]=3;

  lasd::Vector<int> v2(3);
  v2[0]=6;
  v2[1]=7;
  v2[2]=8;

  lasd::List<int> l1;
  l1.InsertAtBack(3);
  l1.InsertAtBack(4);
  l1.InsertAtBack(5);

  cout<<"vector 1: ";
  for(int i=0; i<v1.Size(); i++){
    cout<<v1[i]<<"-";
  }
  cout<<endl;
  cout<<"vector 2: ";
  for(int i=0; i<v2.Size(); i++){
    cout<<v2[i]<<"-";
  }
  cout<<endl;
  cout<<"List: ";
  for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
  }
  cout<<endl;

  bool test1=l1.InsertAll(v1);
  bool test2=l1.InsertAll(v2);
  if(!(test1) && test2)
    result=true;
  cout<<"List: ";
  for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
  }
  cout<<endl;
  cout<<endl;

  return result;
}

bool TestInsertAllMoveInDictionary(){
  bool result=false;

  lasd::Vector<int> v1(3);
  v1[0]=1;
  v1[1]=2;
  v1[2]=3;

  lasd::Vector<int> v2(3);
  v2[0]=6;
  v2[1]=7;
  v2[2]=8;

  lasd::List<int> l1;
  l1.InsertAtBack(3);
  l1.InsertAtBack(4);
  l1.InsertAtBack(5);

  cout<<"vector 1: ";
  for(int i=0; i<v1.Size(); i++){
    cout<<v1[i]<<"-";
  }
  cout<<endl;
  cout<<"vector 2: ";
  for(int i=0; i<v2.Size(); i++){
    cout<<v2[i]<<"-";
  }
  cout<<endl;
  cout<<"List: ";
  for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
  }
  cout<<endl;

  bool test1=l1.InsertAll(move(v1));
  bool test2=l1.InsertAll(move(v2));
  if(!(test1) && test2)
    result=true;
  cout<<"List: ";
  for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
  }
  cout<<endl;
  cout<<endl;

  return result;
}

bool TestInsertSomeCopyInDictionary(){
  bool result=false;

  lasd::Vector<int> v1(3);
  v1[0]=1;
  v1[1]=2;
  v1[2]=3;

  lasd::Vector<int> v2(3);
  v2[0]=3;
  v2[1]=4;
  v2[2]=5;

  lasd::List<int> l1;
  l1.InsertAtBack(3);
  l1.InsertAtBack(4);
  l1.InsertAtBack(5);

  cout<<"vector 1: ";
  for(int i=0; i<v1.Size(); i++){
    cout<<v1[i]<<"-";
  }
  cout<<endl;
  cout<<"vector 2: ";
  for(int i=0; i<v2.Size(); i++){
    cout<<v2[i]<<"-";
  }
  cout<<endl;
  cout<<"List: ";
  for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
  }
  cout<<endl;

  bool test1=l1.InsertSome(v1);
  bool test2=l1.InsertSome(v2);
  if(test1 && !(test2))
    result=true;
  cout<<"List: ";
  for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
  }
  cout<<endl;
  cout<<endl;

  return result;
}

bool TestInsertSomeMoveInDictionary(){
  bool result=false;

  lasd::Vector<int> v1(3);
  v1[0]=1;
  v1[1]=2;
  v1[2]=3;

  lasd::Vector<int> v2(3);
  v2[0]=3;
  v2[1]=4;
  v2[2]=5;

  lasd::List<int> l1;
  l1.InsertAtBack(3);
  l1.InsertAtBack(4);
  l1.InsertAtBack(5);

  cout<<"vector 1: ";
  for(int i=0; i<v1.Size(); i++){
    cout<<v1[i]<<"-";
  }
  cout<<endl;
  cout<<"vector 2: ";
  for(int i=0; i<v2.Size(); i++){
    cout<<v2[i]<<"-";
  }
  cout<<endl;
  cout<<"List: ";
  for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
  }
  cout<<endl;

  bool test1=l1.InsertSome(move(v1));
  bool test2=l1.InsertSome(move(v2));
  if(test1 && !(test2))
    result=true;
  cout<<"List: ";
  for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
  }
  cout<<endl;
  cout<<endl;

  return result;
}


bool TestRemoveAllInDictionary(){
  bool result=false;

  lasd::Vector<int> v1(3);
  v1[0]=1;
  v1[1]=2;
  v1[2]=3;

  lasd::Vector<int> v2(3);
  v2[0]=4;
  v2[1]=5;
  v2[2]=6;

  lasd::List<int> l1;
  l1.InsertAtBack(3);
  l1.InsertAtBack(4);
  l1.InsertAtBack(5);
  l1.InsertAtBack(6);
  l1.InsertAtBack(7);

  cout<<"vector 1: ";
  for(int i=0; i<v1.Size(); i++){
    cout<<v1[i]<<"-";
  }
  cout<<endl;
  cout<<"vector 2: ";
  for(int i=0; i<v2.Size(); i++){
    cout<<v2[i]<<"-";
  }
  cout<<endl;
  cout<<"List: ";
  for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
  }
  cout<<endl;

  bool test1=l1.RemoveAll(v1);
  bool test2=l1.RemoveAll(v2);
  if(!(test1) && test2)
    result=true;
  cout<<"List: ";
  for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
  }
  cout<<endl;
  cout<<endl;

  return result;
}


bool TestRemoveSomeInDictionary(){
  bool result=false;
  lasd::Vector<int> v1(3);
  v1[0]=1;
  v1[1]=2;
  v1[2]=3;

  lasd::Vector<int> v2(3);
  v2[0]=6;
  v2[1]=7;
  v2[2]=8;

  lasd::List<int> l1;
  l1.InsertAtBack(3);
  l1.InsertAtBack(4);
  l1.InsertAtBack(5);

  cout<<"vector 1: ";
  for(int i=0; i<v1.Size(); i++){
    cout<<v1[i]<<"-";
  }
  cout<<endl;
  cout<<"vector 2: ";
  for(int i=0; i<v2.Size(); i++){
    cout<<v2[i]<<"-";
  }
  cout<<endl;
  cout<<"List: ";
  for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
  }
  cout<<endl;

  bool test1=l1.RemoveSome(v1);
  bool test2=l1.RemoveSome(v2);
  if(test1 && !(test2))
    result=true;
  cout<<"List: ";
  for(int i=0; i<l1.Size(); i++){
    cout<<l1[i]<<"->";
  }
  cout<<endl;
  cout<<endl;

  return result;
}

/* ************************************************************************** */

bool TestSortInt(){
  bool result=true;
  lasd::Vector<int> v1(genSize(gen)+1);
  for(int i=0; i<v1.Size(); i++){
    v1[i]=genNum(gen);
  }
  v1.Sort();
  for(int i=1; i<v1.Size(); i++)
    result&=(v1[i-1]<=v1[i]);

  return result;
}

bool TestSortChar(){
  bool result=true;
  lasd::Vector<int> v1(genSize(gen)+1);
  for(int i=0; i<v1.Size(); i++){
    v1[i]=(char)genSmallNum(gen);
  }
  v1.Sort();
  for(int i=1; i<v1.Size(); i++)
    result&=(v1[i-1]<=v1[i]);

  return result;
}

bool TestSortEmpty(){
  bool result=true;
  lasd::Vector<int> v1(0);
  v1.Sort();
  for(int i=1; i<v1.Size(); i++)
    result&=(v1[i-1]<=v1[i]);

  return result;
}


/* ************************************************************************** */
/* ************************** FUNZIONI ESERCIZIO 2 ************************** */
/* ************************************************************************** */

bool TestCompareBSTCopy(){
  bool result=true;
  int generated_size = genSize(gen);
  int generated_val;
  lasd::Vector<int> vec(generated_size);
  lasd::BST<int> BST1;
  for(int i=0; i<generated_size; i++){
    generated_val = genNum(gen);
    vec[i]=generated_val;
    BST1.Insert(generated_val);
  }
  lasd::BST<int> BST2(vec);
  lasd::BST<int> BST3(BST1);
  lasd::BST<int> BST4;
  BST4 = BST1;

  if(BST1!=BST2){
    result=false;
    cout<<"Costruttore da MutableMappableContainer errato"<<endl;
  }
  if(BST1!=BST3){
    result=false;
    cout<<"Costruttore da BST errato"<<endl;
  }
  if(BST1!=BST4){
    result=false;
    cout<<"Operatore di assegnazione errato"<<endl;
  }

  return result;
}

bool TestCompareBSTMove(){
  bool result=true;
  int generated_size = genSize(gen);
  int generated_val;
  lasd::Vector<int> vec(generated_size);
  lasd::BST<int> BST1;
  for(int i=0; i<generated_size; i++){
    generated_val = genNum(gen);
    vec[i]=generated_val;
    BST1.Insert(generated_val);
  }
  lasd::BST<int> BST2(std::move(vec));

  if(BST1!=BST2){
    result=false;
    cout<<"Costruttore move da MutableMappableContainer errato"<<endl;
  }

  lasd::BST<int> BST3(std::move(BST1));

  if(BST2!=BST3){
    result=false;
    cout<<"Costruttore move da BST errato"<<endl;
  }

  if(!(BST1.Empty())){
    result=false;
    cout<<"Il move constructor di BST non ha cancellato other"<<endl;
  }

  lasd::BST<int> BST4;
  BST4 = std::move(BST2);

  if(BST3!=BST4){
    result=false;
    cout<<"Operatore di assegnazione move errato"<<endl;
  }

  if(!(BST2.Empty())){
    result=false;
    cout<<"L'operatore di assegnazione move di BST non ha cancellato other"<<endl;
  }

  return result;
}

bool TestCompareBTAndBSTFromLstCopy(){
  bool result=true;

  lasd::List<int> l1;
  int temp_size = genSize(gen)+2;
  for(int i=0; i<temp_size; i++){
      int temp_val = genNum(gen);
      l1.Insert(temp_val);
  }
  lasd::BST<int> BST1(l1);
  lasd::BST<int> BST2(l1);
  lasd::BinaryTreeLnk<int> BTL(l1);
  lasd::BinaryTreeVec<int> BTV(l1);

  if(BST1!=BST2)
    result=false;
  if(BST1.lasd::BinaryTree<int>::operator==(BTL))
    result=false;
  if(BST1.lasd::BinaryTree<int>::operator==(BTV))
    result=false;
  if(BST2.Size()>=2){
    BST2.MinNRemove();
    BST2.MaxNRemove();
  }
  if(BST1==BST2)
    result=false;
  
  lasd::List<int> staticList;
  lasd::BST<int> staticBST;
  
  staticList.InsertAtFront(2);
  staticList.InsertAtFront(1);
  staticList.InsertAtFront(3);

  staticBST.InsertAll(staticList);
  lasd::BinaryTreeLnk<int> staticBTL(staticList);
  lasd::BinaryTreeVec<int> staticBTV(staticList);

  if(staticBST.lasd::BinaryTree<int>::operator!=(staticBTL))
    result=false;
  if(staticBST.lasd::BinaryTree<int>::operator!=(staticBTV))
    result=false;
  if(!staticBST.Remove(2))
    result=false;
  if(staticBST.lasd::BinaryTree<int>::operator==(staticBTL))
    result=false;
  if(staticBST.lasd::BinaryTree<int>::operator==(staticBTV))
    result=false;

  return result;
}

bool TestCompareBTAndBSTFromLstMove(){
  bool result=true;

  lasd::List<int> l1;
  int temp_size = genSize(gen)+2;
  for(int i=0; i<temp_size; i++){
      int temp_val = genNum(gen);
      l1.Insert(temp_val);
  }
  lasd::BST<int> BST1(std::move(l1));
  lasd::BST<int> BST2(std::move(l1));
  lasd::BinaryTreeLnk<int> BTL(std::move(l1));
  lasd::BinaryTreeVec<int> BTV(std::move(l1));

  if(BST1!=BST2)
    result=false;
  if(BST1.lasd::BinaryTree<int>::operator==(BTL))
    result=false;
  if(BST1.lasd::BinaryTree<int>::operator==(BTV))
    result=false;
  if(BST2.Size()>=2){
    BST2.MinNRemove();
    BST2.MaxNRemove();
  }
  if(BST1==BST2)
    result=false;
  
  lasd::List<int> staticList;
  lasd::BST<int> staticBST;
  
  staticList.InsertAtFront(2);
  staticList.InsertAtFront(1);
  staticList.InsertAtFront(3);

  staticBST.InsertAll(staticList);
  lasd::BinaryTreeLnk<int> staticBTL(std::move(staticList));
  lasd::BinaryTreeVec<int> staticBTV(std::move(staticList));

  if(staticBST.lasd::BinaryTree<int>::operator!=(staticBTL))
    result=false;
  if(staticBST.lasd::BinaryTree<int>::operator!=(staticBTV))
    result=false;
  if(!staticBST.Remove(2))
    result=false;
  if(staticBST.lasd::BinaryTree<int>::operator==(staticBTL))
    result=false;
  if(staticBST.lasd::BinaryTree<int>::operator==(staticBTV))
    result=false;

  return result;
}

bool TestCompareBTAndBSTFromVecCopy(){
  bool result=true;

  int temp_size = genSize(gen)+2;
  lasd::Vector<int> v1(temp_size);
  for(int i=0; i<temp_size; i++){
      int temp_val = genNum(gen);
      v1[i]=temp_val;
  }
  lasd::BST<int> BST1(v1);
  lasd::BST<int> BST2(v1);
  lasd::BinaryTreeLnk<int> BTL(v1);
  lasd::BinaryTreeVec<int> BTV(v1);

  if(BST1!=BST2)
    result=false;
  if(BST1.lasd::BinaryTree<int>::operator==(BTL))
    result=false;
  if(BST1.lasd::BinaryTree<int>::operator==(BTV))
    result=false;
  if(BST2.Size()>=2){
    BST2.MinNRemove();
    BST2.MaxNRemove();
  }
  if(BST1==BST2)
    result=false;
  
  lasd::Vector<int> staticVector(3);
  lasd::BST<int> staticBST;
  
  staticVector[0]=2;
  staticVector[1]=1;
  staticVector[2]=3;

  staticBST.InsertAll(staticVector);
  lasd::BinaryTreeLnk<int> staticBTL(staticVector);
  lasd::BinaryTreeVec<int> staticBTV(staticVector);

  if(staticBST.lasd::BinaryTree<int>::operator!=(staticBTL))
    result=false;
  if(staticBST.lasd::BinaryTree<int>::operator!=(staticBTV))
    result=false;
  if(!staticBST.Remove(2))
    result=false;
  if(staticBST.lasd::BinaryTree<int>::operator==(staticBTL))
    result=false;
  if(staticBST.lasd::BinaryTree<int>::operator==(staticBTV))
    result=false;

  return result;
}

bool TestCompareBTAndBSTFromVecMove(){
  bool result=true;
  
  int temp_size = genSize(gen)+2;
  lasd::Vector<int> v1(temp_size);
  for(int i=0; i<temp_size; i++){
      int temp_val = genNum(gen);
      v1[i]=temp_val;
  }
  lasd::BST<int> BST1(std::move(v1));
  lasd::BST<int> BST2(std::move(v1));
  lasd::BinaryTreeLnk<int> BTL(std::move(v1));
  lasd::BinaryTreeVec<int> BTV(std::move(v1));

  if(BST1!=BST2)
    result=false;
  if(BST1.lasd::BinaryTree<int>::operator==(BTL))
    result=false;
  if(BST1.lasd::BinaryTree<int>::operator==(BTV))
    result=false;
  if(BST2.Size()>=2){
    BST2.MinNRemove();
    BST2.MaxNRemove();
  }
  if(BST1==BST2)
    result=false;
  
  lasd::Vector<int> staticVector(3);
  lasd::BST<int> staticBST;
  
  staticVector[0]=2;
  staticVector[1]=1;
  staticVector[2]=3;

  staticBST.InsertAll(staticVector);
  lasd::BinaryTreeLnk<int> staticBTL(std::move(staticVector));
  lasd::BinaryTreeVec<int> staticBTV(std::move(staticVector));

  if(staticBST.lasd::BinaryTree<int>::operator!=(staticBTL))
    result=false;
  if(staticBST.lasd::BinaryTree<int>::operator!=(staticBTV))
    result=false;
  if(!staticBST.Remove(2))
    result=false;
  if(staticBST.lasd::BinaryTree<int>::operator==(staticBTL))
    result=false;
  if(staticBST.lasd::BinaryTree<int>::operator==(staticBTV))
    result=false;

  return result;
}

bool TestCompareEmptyBTAndBST(){
  bool result=true;
  lasd::Vector<int> vec(0);

  lasd::BST<int> BST1;
  lasd::BST<int> BST2(vec);
  lasd::BST<int> BST3(BST1);
  lasd::BST<int> BST4;
  BST4 = BST1;

  lasd::BinaryTreeLnk<int> BT1;
  lasd::BinaryTreeLnk<int> BT2(vec);
  lasd::BinaryTreeLnk<int> BT3(BT1);
  lasd::BinaryTreeLnk<int> BT4;
  BT4 = BT1;

  if(BST1!=BST2){
    result=false;
    cout<<"Costruttore di BST da MutableMappableContainer errato"<<endl;
  }
  if(BST1!=BST3){
    result=false;
    cout<<"Costruttore di BST da BST errato"<<endl;
  }
  if(BST1!=BST4){
    result=false;
    cout<<"Operatore di assegnazione di BST errato"<<endl;
  }

  if(BT1!=BT2){
    result=false;
    cout<<"Costruttore di BT da MutableMappableContainer errato"<<endl;
  }
  if(BT1!=BT3){
    result=false;
    cout<<"Costruttore di BT da BST errato"<<endl;
  }
  if(BT1!=BT4){
    result=false;
    cout<<"Operatore di assegnazione di BT errato"<<endl;
  }

  lasd::BST<int>BST5(BT1);
  lasd::BST<int>BST6;
  BST6 = BT1;
  if(BST5!=BST1){
    result=false;
    cout<<"Costruttore di BST da BT vuoto errato"<<endl;
  }
  if(BST6!=BST1){
    result=false;
    cout<<"Assegnazione di BT a BST vuoto errato"<<endl;
  }


  lasd::BST<int> move_BST1;
  lasd::BST<int> move_BST2(std::move(vec));

  if(move_BST1!=move_BST2){
    result=false;
    cout<<"Costruttore di BST da MutableMappableContainer errato"<<endl;
  }

  lasd::BST<int> move_BST3(std::move(move_BST1));
  
  if(move_BST2!=move_BST3){
    result=false;
    cout<<"Costruttore di BST da BST errato"<<endl;
  }

  lasd::BST<int> move_BST4;
  move_BST4 = std::move(move_BST2);
  
  if(move_BST3!=move_BST4){
    result=false;
    cout<<"Operatore di assegnazione di BST errato"<<endl;
  }

  if(!(move_BST1.Empty())){
    result=false;
    cout<<"Il move constructor di BST non ha cancellato other"<<endl;
  }
  if(!(move_BST2.Empty())){
    result=false;
    cout<<"L'assegnazione con move di BST non ha cancellato other"<<endl;
  }

  lasd::BinaryTreeLnk<int> move_BT1;
  lasd::BinaryTreeLnk<int> move_BT2(std::move(vec));

  if(move_BT1!=move_BT2){
    result=false;
    cout<<"Costruttore di BT da MutableMappableContainer errato"<<endl;
  }

  lasd::BinaryTreeLnk<int> move_BT3(std::move(move_BT1));

  if(move_BT2!=move_BT3){
    result=false;
    cout<<"Costruttore di BT da BST errato"<<endl;
  }

  lasd::BinaryTreeLnk<int> move_BT4;
  move_BT4 = std::move(move_BT1);

  if(move_BT3!=move_BT4){
    result=false;
    cout<<"Operatore di assegnazione di BT errato"<<endl;
  }

  if(!(move_BT1.Empty())){
    result=false;
    cout<<"Il move constructor di BT non ha cancellato other"<<endl;
  }
  if(!(move_BT2.Empty())){
    result=false;
    cout<<"L'assegnazione con move di BT non ha cancellato other"<<endl;
  }

  lasd::BST<int>move_BST5(std::move(move_BT3));
  lasd::BST<int>move_BST6;
  move_BST6 = std::move(move_BT4);
  lasd::BST<int>move_BST7;

  if(move_BST5!=move_BST7){
    result=false;
    cout<<"Costruttore con move di BST da BT vuoto errato"<<endl;
  }
  if(move_BST6!=move_BST7){
    result=false;
    cout<<"Assegnazione con move di BT a BST vuoto errato"<<endl;
  }

  return result;
}

/* ************************************************************************** */

bool TestIteratorOnBT(){
  bool result=true;

  // cotruttori vari e assegnazioni

  lasd::Vector<int> vec(3);
  vec[0]=1;
  vec[1]=2;
  vec[2]=3;

  lasd::BinaryTreeLnk<int> BT(vec);

  lasd::BTPreOrderIterator pre_i(BT);
  lasd::BTPostOrderIterator post_i(BT);
  lasd::BTInOrderIterator inOrder_i(BT);
  lasd::BTBreadthIterator breadth_i(BT);

  cout<<"pre: ";
  for(; !(pre_i.Terminated()); pre_i.operator++())
    cout<<pre_i.operator*()<<"-";
  cout<<endl;
  pre_i.Reset();
  cout<<"post: ";
  for(; !(post_i.Terminated()); post_i.operator++())
    cout<<post_i.operator*()<<"-";
  cout<<endl;
  post_i.Reset();
  cout<<"inOrder: ";
  for(; !(inOrder_i.Terminated()); inOrder_i.operator++())
    cout<<inOrder_i.operator*()<<"-";
  cout<<endl;
  inOrder_i.Reset();
  cout<<"breadth: ";
  for(; !(breadth_i.Terminated()); breadth_i.operator++())
    cout<<breadth_i.operator*()<<"-";
  cout<<endl;
  breadth_i.Reset();
  
  lasd::BTPreOrderMutableIterator pre_mut_i(BT);
  lasd::BTPostOrderMutableIterator post_mut_i(BT);
  lasd::BTInOrderMutableIterator inOrder_mut_i(BT);
  lasd::BTBreadthMutableIterator breadth_mut_i(BT);

  lasd::BTPreOrderMutableIterator pre_mut_i_cop(pre_mut_i);
  lasd::BTPostOrderMutableIterator post_mut_i_cop(post_mut_i);
  lasd::BTInOrderMutableIterator inOrder_mut_i_cop(inOrder_mut_i);
  lasd::BTBreadthMutableIterator breadth_mut_i_cop(breadth_mut_i);

  lasd::BTPreOrderMutableIterator pre_mut_i_mov(std::move(pre_mut_i));
  lasd::BTPostOrderMutableIterator post_mut_i_mov(std::move(post_mut_i));
  lasd::BTInOrderMutableIterator inOrder_mut_i_mov(std::move(inOrder_mut_i));
  lasd::BTBreadthMutableIterator breadth_mut_i_mov(std::move(breadth_mut_i));

  lasd::BTPreOrderIterator pre_i_as(BT);
  pre_i_as = pre_i;
  lasd::BTPostOrderIterator post_i_as(BT);
  post_i_as = post_i;
  lasd::BTInOrderIterator inOrder_i_as(BT);
  inOrder_i_as = inOrder_i;
  lasd::BTBreadthIterator breadth_i_as(BT);
  breadth_i_as = breadth_i;
  
  lasd::BTPreOrderMutableIterator pre_mut_i_as_mov(BT);
  pre_mut_i_as_mov = std::move(pre_mut_i_cop);
  lasd::BTPostOrderMutableIterator post_mut_i_as_mov(BT);
  post_mut_i_as_mov = std::move(post_mut_i_cop);
  lasd::BTInOrderMutableIterator inOrder_mut_i_as_mov(BT);
  inOrder_mut_i_as_mov = std::move(inOrder_mut_i_cop);
  lasd::BTBreadthMutableIterator breadth_mut_i_as_mov(BT);
  breadth_mut_i_as_mov = std::move(breadth_mut_i_cop);

  int val;

  // operazioni su iterator

  if(pre_i_as.Terminated())
    result=false;
  try{
    val = pre_i_as.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=1)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  try{
    pre_i_as.operator++();
    val = pre_i_as.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=2)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator++()"<<endl;
  }
  pre_i_as.Reset();
  try{
    pre_i_as.operator*();
    val = pre_i_as.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=1)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  if(pre_i_as.Terminated())
    result=false;
  if(!(pre_i_as.operator==(pre_i_as)))
    result=false;
  if(pre_i_as.operator!=(pre_i_as))
    result=false;
  try{
    pre_i_as.operator++();
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator++()"<<endl;
  }


  if(post_i_as.Terminated())
    result=false;
  try{
    val = post_i_as.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=2)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  try{
    post_i_as.operator++();
    val = post_i_as.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=3)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator++()"<<endl;
  }
  post_i_as.Reset();
  try{
    post_i_as.operator*();
    val = post_i_as.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=2)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  if(post_i_as.Terminated())
    result=false;
  if(!(post_i_as.operator==(post_i_as)))
    result=false;
  if(post_i_as.operator!=(post_i_as))
    result=false;
  try{
    post_i_as.operator++();
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator++()"<<endl;
  }


  if(inOrder_i_as.Terminated())
    result=false;
  try{
    val = inOrder_i_as.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=2)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  try{
    inOrder_i_as.operator++();
    val = inOrder_i_as.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=1)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator++()"<<endl;
  }
  inOrder_i_as.Reset();
  try{
    inOrder_i_as.operator*();
    val = inOrder_i_as.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=2)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  if(inOrder_i_as.Terminated())
    result=false;
  if(!(inOrder_i_as.operator==(inOrder_i_as)))
    result=false;
  if(inOrder_i_as.operator!=(inOrder_i_as))
    result=false;
  try{
    inOrder_i_as.operator++();
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator++()"<<endl;
  }


  if(breadth_i_as.Terminated())
    result=false;
  try{
    val = breadth_i_as.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=1)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  try{
    breadth_i_as.operator++();
    val = breadth_i_as.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=2)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator++()"<<endl;
  }
  breadth_i_as.Reset();
  try{
    breadth_i_as.operator*();
    val = breadth_i_as.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=1)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  if(breadth_i_as.Terminated())
    result=false;
  if(!(breadth_i_as.operator==(breadth_i_as)))
    result=false;
  if(breadth_i_as.operator!=(breadth_i_as))
    result=false;
  try{
    breadth_i_as.operator++();
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator++()"<<endl;
  }

  // operazioni su mutable iterator

  cout<<"pre: ";
  for(; !(pre_mut_i_as_mov.Terminated()); pre_mut_i_as_mov.operator++())
    cout<<pre_mut_i_as_mov.operator*()<<"-";
  cout<<endl;
  pre_mut_i_as_mov.Reset();
  cout<<"post: ";
  for(; !(post_mut_i_as_mov.Terminated()); post_mut_i_as_mov.operator++())
    cout<<post_mut_i_as_mov.operator*()<<"-";
  cout<<endl;
  post_mut_i_as_mov.Reset();
  cout<<"inOrder: ";
  for(; !(inOrder_mut_i_as_mov.Terminated()); inOrder_mut_i_as_mov.operator++())
    cout<<inOrder_mut_i_as_mov.operator*()<<"-";
  cout<<endl;
  inOrder_mut_i_as_mov.Reset();
  cout<<"breadth: ";
  for(; !(breadth_mut_i_as_mov.Terminated()); breadth_mut_i_as_mov.operator++())
    cout<<breadth_mut_i_as_mov.operator*()<<"-";
  cout<<endl;
  breadth_mut_i_as_mov.Reset();


  if(pre_mut_i_as_mov.Terminated())
    result=false;
  try{
    val = pre_mut_i_as_mov.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=1)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  try{
    pre_mut_i_as_mov.operator++();
    val = pre_mut_i_as_mov.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=2)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator++()"<<endl;
  }
  pre_mut_i_as_mov.Reset();
  try{
    pre_mut_i_as_mov.operator*();
    val = pre_mut_i_as_mov.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=1)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  if(pre_mut_i_as_mov.Terminated())
    result=false;
  if(!(pre_mut_i_as_mov.operator==(pre_mut_i_as_mov)))
    result=false;
  if(pre_mut_i_as_mov.operator!=(pre_mut_i_as_mov))
    result=false;
  try{
    pre_mut_i_as_mov.operator++();
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator++()"<<endl;
  }


  if(post_mut_i_as_mov.Terminated())
    result=false;
  try{
    val = post_mut_i_as_mov.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=2)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  try{
    post_mut_i_as_mov.operator++();
    val = post_mut_i_as_mov.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=3)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator++()"<<endl;
  }
  post_mut_i_as_mov.Reset();
  try{
    post_mut_i_as_mov.operator*();
    val = post_mut_i_as_mov.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=2)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  if(post_mut_i_as_mov.Terminated())
    result=false;
  if(!(post_mut_i_as_mov.operator==(post_mut_i_as_mov)))
    result=false;
  if(post_mut_i_as_mov.operator!=(post_mut_i_as_mov))
    result=false;
  try{
    post_mut_i_as_mov.operator++();
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator++()"<<endl;
  }


  if(inOrder_mut_i_as_mov.Terminated())
    result=false;
  try{
    val = inOrder_mut_i_as_mov.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=2)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  try{
    inOrder_mut_i_as_mov.operator++();
    val = inOrder_mut_i_as_mov.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=1)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator++()"<<endl;
  }
  inOrder_mut_i_as_mov.Reset();
  try{
    inOrder_mut_i_as_mov.operator*();
    val = inOrder_mut_i_as_mov.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=2)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  if(inOrder_mut_i_as_mov.Terminated())
    result=false;
  if(!(inOrder_mut_i_as_mov.operator==(inOrder_mut_i_as_mov)))
    result=false;
  if(inOrder_mut_i_as_mov.operator!=(inOrder_mut_i_as_mov))
    result=false;
  try{
    inOrder_mut_i_as_mov.operator++();
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator++()"<<endl;
  }


  if(breadth_mut_i_as_mov.Terminated())
    result=false;
  try{
    val = breadth_mut_i_as_mov.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=1)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  try{
    breadth_mut_i_as_mov.operator++();
    val = breadth_mut_i_as_mov.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=2)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator++()"<<endl;
  }
  breadth_mut_i_as_mov.Reset();
  try{
    breadth_mut_i_as_mov.operator*();
    val = breadth_mut_i_as_mov.operator*();
    cout<<"val: "<<val<<endl;
    if(val!=1)
      result=false;
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  if(breadth_mut_i_as_mov.Terminated())
    result=false;
  if(!(breadth_mut_i_as_mov.operator==(breadth_mut_i_as_mov)))
    result=false;
  if(breadth_mut_i_as_mov.operator!=(breadth_mut_i_as_mov))
    result=false;
  try{
    breadth_mut_i_as_mov.operator++();
  }
  catch(std::out_of_range our){
    result=false;
    cout<<"catchata out_of_range in operator++()"<<endl;
  }

  return result;
}


bool TestIteratorOnEmptyBT(){
  bool result=true;

  // cotruttori vari e assegnazioni

  lasd::BinaryTreeLnk<int> BT;
  lasd::BTPreOrderIterator pre_i(BT);
  lasd::BTPostOrderIterator post_i(BT);
  lasd::BTInOrderIterator inOrder_i(BT);
  lasd::BTBreadthIterator breadth_i(BT);
  
  lasd::BTPreOrderMutableIterator pre_mut_i(BT);
  lasd::BTPostOrderMutableIterator post_mut_i(BT);
  lasd::BTInOrderMutableIterator inOrder_mut_i(BT);
  lasd::BTBreadthMutableIterator breadth_mut_i(BT);

  lasd::BTPreOrderIterator pre_i_mov_bt(std::move(BT));
  lasd::BTPostOrderIterator post_i_mov_bt(std::move(BT));
  lasd::BTInOrderIterator inOrder_i_mov_bt(std::move(BT));
  lasd::BTBreadthIterator breadth_i_mov_bt(std::move(BT));

  lasd::BTPreOrderIterator pre_i_cop(pre_i);
  lasd::BTPostOrderIterator post_i_cop(post_i);
  lasd::BTInOrderIterator inOrder_i_cop(inOrder_i);
  lasd::BTBreadthIterator breadth_i_cop(breadth_i);

  lasd::BTPreOrderMutableIterator pre_mut_i_cop(pre_mut_i);
  lasd::BTPostOrderMutableIterator post_mut_i_cop(post_mut_i);
  lasd::BTInOrderMutableIterator inOrder_mut_i_cop(inOrder_mut_i);
  lasd::BTBreadthMutableIterator breadth_mut_i_cop(breadth_mut_i);

  lasd::BTPreOrderIterator pre_i_mov(std::move(pre_i));
  lasd::BTPostOrderIterator post_i_mov(std::move(post_i));
  lasd::BTInOrderIterator inOrder_i_mov(std::move(inOrder_i));
  lasd::BTBreadthIterator breadth_i_mov(std::move(breadth_i));

  lasd::BTPreOrderMutableIterator pre_mut_i_mov(std::move(pre_mut_i));
  lasd::BTPostOrderMutableIterator post_mut_i_mov(std::move(post_mut_i));
  lasd::BTInOrderMutableIterator inOrder_mut_i_mov(std::move(inOrder_mut_i));
  lasd::BTBreadthMutableIterator breadth_mut_i_mov(std::move(breadth_mut_i));

  lasd::BTPreOrderIterator pre_i_as(BT);
  pre_i_as = pre_i;
  lasd::BTPostOrderIterator post_i_as(BT);
  post_i_as = post_i;
  lasd::BTInOrderIterator inOrder_i_as(BT);
  inOrder_i_as = inOrder_i;
  lasd::BTBreadthIterator breadth_i_as(BT);
  breadth_i_as = breadth_i;
  
  lasd::BTPreOrderMutableIterator pre_mut_i_as(BT);
  pre_mut_i_as = pre_mut_i;
  lasd::BTPostOrderMutableIterator post_mut_i_as(BT);
  post_mut_i_as = post_mut_i;
  lasd::BTInOrderMutableIterator inOrder_mut_i_as(BT);
  inOrder_mut_i_as = inOrder_mut_i;
  lasd::BTBreadthMutableIterator breadth_mut_i_as(BT);
  breadth_mut_i_as = breadth_mut_i;

  lasd::BTPreOrderIterator pre_i_as_mov(BT);
  pre_i_as_mov = std::move(pre_i);
  lasd::BTPostOrderIterator post_i_as_mov(BT);
  post_i_as_mov = std::move(post_i);
  lasd::BTInOrderIterator inOrder_i_as_mov(BT);
  inOrder_i_as_mov = std::move(inOrder_i);
  lasd::BTBreadthIterator breadth_i_as_mov(BT);
  breadth_i_as_mov = std::move(breadth_i);
  
  lasd::BTPreOrderMutableIterator pre_mut_i_as_mov(BT);
  pre_mut_i_as_mov = std::move(pre_mut_i);
  lasd::BTPostOrderMutableIterator post_mut_i_as_mov(BT);
  post_mut_i_as_mov = std::move(post_mut_i);
  lasd::BTInOrderMutableIterator inOrder_mut_i_as_mov(BT);
  inOrder_mut_i_as_mov = std::move(inOrder_mut_i);
  lasd::BTBreadthMutableIterator breadth_mut_i_as_mov(BT);
  breadth_mut_i_as_mov = std::move(breadth_mut_i);

  // operazioni su iterator vuoto

  if(!(pre_i_as.Terminated()))
    result=false;
  pre_i_as.Reset();
  if(!(pre_i_as.Terminated()))
    result=false;
  try{
    pre_i_as.operator*();
  }
  catch(std::out_of_range our){
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  if(!(pre_i_as.operator==(pre_i_as)))
    result=false;
  if(pre_i_as.operator!=(pre_i_as))
    result=false;
  try{
    pre_i_as.operator++();
  }
  catch(std::out_of_range our){
    cout<<"catchata out_of_range in operator++()"<<endl;
  }


  if(!(post_i_as.Terminated()))
    result=false;
  post_i_as.Reset();
  if(!(post_i_as.Terminated()))
    result=false;
  try{
    post_i_as.operator*();
  }
  catch(std::out_of_range our){
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  if(!(post_i_as.operator==(post_i_as)))
    result=false;
  if(post_i_as.operator!=(post_i_as))
    result=false;
  try{
    post_i_as.operator++();
  }
  catch(std::out_of_range our){
    cout<<"catchata out_of_range in operator++()"<<endl;
  }


  if(!(inOrder_i_as.Terminated()))
    result=false;
  inOrder_i_as.Reset();
  if(!(inOrder_i_as.Terminated()))
    result=false;
  try{
    inOrder_i_as.operator*();
  }
  catch(std::out_of_range our){
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  if(!(inOrder_i_as.operator==(inOrder_i_as)))
    result=false;
  if(inOrder_i_as.operator!=(inOrder_i_as))
    result=false;
  try{
    inOrder_i_as.operator++();
  }
  catch(std::out_of_range our){
    cout<<"catchata out_of_range in operator++()"<<endl;
  }


  if(!(breadth_i_as.Terminated()))
    result=false;
  breadth_i_as.Reset();
  if(!(breadth_i_as.Terminated()))
    result=false;
  try{
    breadth_i_as.operator*();
  }
  catch(std::out_of_range our){
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  if(!(breadth_i_as.operator==(breadth_i_as)))
    result=false;
  if(breadth_i_as.operator!=(breadth_i_as))
    result=false;
  try{
    breadth_i_as.operator++();
  }
  catch(std::out_of_range our){
    cout<<"catchata out_of_range in operator++()"<<endl;
  }

  // operazioni su mutable iterator vuoto

  if(!(pre_mut_i_as_mov.Terminated()))
    result=false;
  pre_mut_i_as_mov.Reset();
  if(!(pre_mut_i_as_mov.Terminated()))
    result=false;
  try{
    pre_mut_i_as_mov.operator*();
  }
  catch(std::out_of_range our){
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  if(!(pre_mut_i_as_mov.operator==(pre_mut_i_as_mov)))
    result=false;
  if(pre_mut_i_as_mov.operator!=(pre_mut_i_as_mov))
    result=false;
  try{
    pre_mut_i_as_mov.operator++();
  }
  catch(std::out_of_range our){
    cout<<"catchata out_of_range in operator++()"<<endl;
  }


  if(!(post_mut_i_as_mov.Terminated()))
    result=false;
  post_mut_i_as_mov.Reset();
  if(!(post_mut_i_as_mov.Terminated()))
    result=false;
  try{
    post_mut_i_as_mov.operator*();
  }
  catch(std::out_of_range our){
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  if(!(post_mut_i_as_mov.operator==(post_mut_i_as_mov)))
    result=false;
  if(post_mut_i_as_mov.operator!=(post_mut_i_as_mov))
    result=false;
  try{
    post_mut_i_as_mov.operator++();
  }
  catch(std::out_of_range our){
    cout<<"catchata out_of_range in operator++()"<<endl;
  }


  if(!(inOrder_mut_i_as_mov.Terminated()))
    result=false;
  inOrder_mut_i_as_mov.Reset();
  if(!(inOrder_mut_i_as_mov.Terminated()))
    result=false;
  try{
    inOrder_mut_i_as_mov.operator*();
  }
  catch(std::out_of_range our){
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  if(!(inOrder_mut_i_as_mov.operator==(inOrder_mut_i_as_mov)))
    result=false;
  if(inOrder_mut_i_as_mov.operator!=(inOrder_mut_i_as_mov))
    result=false;
  try{
    inOrder_mut_i_as_mov.operator++();
  }
  catch(std::out_of_range our){
    cout<<"catchata out_of_range in operator++()"<<endl;
  }


  if(!(breadth_mut_i_as_mov.Terminated()))
    result=false;
  breadth_mut_i_as_mov.Reset();
  if(!(breadth_mut_i_as_mov.Terminated()))
    result=false;
  try{
    breadth_mut_i_as_mov.operator*();
  }
  catch(std::out_of_range our){
    cout<<"catchata out_of_range in operator*()"<<endl;
  }
  if(!(breadth_mut_i_as_mov.operator==(breadth_mut_i_as_mov)))
    result=false;
  if(breadth_mut_i_as_mov.operator!=(breadth_mut_i_as_mov))
    result=false;
  try{
    breadth_mut_i_as_mov.operator++();
  }
  catch(std::out_of_range our){
    cout<<"catchata out_of_range in operator++()"<<endl;
  }

  return result;
}


bool TestIteratorAfterMove(){
  bool result=true;

  result = false;

  lasd::Vector<int> vec(6);
  for(int i=0; i<6; i++)
      vec[i]=i;

  lasd::BinaryTreeVec<int> btVec2(vec);
  lasd::BinaryTreeVec<int> btVec3;

  btVec3=std::move(btVec2);

  lasd::BTPreOrderIterator<int> itr(btVec3);
  while(!(itr.Terminated())){
    cout<<"ciao bro "<<*itr;
    ++itr;
  }

  result = true;

  return result;
}

/* ************************************************************************** */

bool TestMapsAndFoldOnBTLnk(){
  bool result=true;

  lasd::List<int> lst;
  for(int i=0; i<6; i++)
      lst.InsertAtBack(i);

  lasd::BinaryTreeLnk<int> btLnk(lst);

  cout<<"Atteso con Map: 0->1->3->4->2->5->"<<endl;
  cout<<"Stampa con Map: ";
  btLnk.Map(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  int acc=0;
  btLnk.Fold(&FoldAdd<int>, &acc);
  cout<<"\nValore di acc atteso con Fold: 15 - Valore ottenuto: "<<acc<<endl;
  if(acc!=15)
    result=false;
  cout<<endl<<endl;


  cout<<"Atteso con PreOrderMap: 0->1->3->4->2->5->"<<endl;
  cout<<"Stampa con PreOrderMap: ";
  btLnk.PreOrderMap(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  cout<<endl;
  lasd::BTPreOrderIterator<int> itrPre(btLnk);
  cout<<"Stampa PreOrder con iteratore: ";
  while(!(itrPre.Terminated())){
    cout<<*itrPre<<"->";
    ++itrPre;
  }

  static_test_index = 0;
  acc = 0;
  btLnk.PreOrderFold(&FoldSumAndMultyplyPerPosition<int>, &acc);
  cout<<"\nValore di acc atteso con PreOrderFold: 52 - Valore ottenuto: "<<acc<<endl;
  if(acc!=52)
    result=false;
  static_test_index = 0;
  cout<<endl<<endl;


  cout<<"Atteso con PostOrderMap: 3->4->1->5->2->0->"<<endl;
  cout<<"Stampa con PostOrderMap: ";
  btLnk.PostOrderMap(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  cout<<endl;
  lasd::BTPostOrderIterator<int> itrPost(btLnk);
  cout<<"Stampa PostOrder con iteratore: ";
  while(!(itrPost.Terminated())){
    cout<<*itrPost<<"->";
    ++itrPost;
  }

  static_test_index = 0;
  acc = 0;
  btLnk.PostOrderFold(&FoldSumAndMultyplyPerPosition<int>, &acc);
  cout<<"\nValore di acc atteso con PostOrderFold: 29 - Valore ottenuto: "<<acc<<endl;
  if(acc!=29)
    result=false;
  static_test_index = 0;
  cout<<endl<<endl;


  cout<<"Atteso con InOrderMap: 3->1->4->0->5->2->"<<endl;
  cout<<"Stampa con InOrderMap: ";
  btLnk.InOrderMap(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  cout<<endl;
  lasd::BTInOrderIterator<int> itrIn(btLnk);
  cout<<"Stampa InOrder con iteratore: ";
  while(!(itrIn.Terminated())){
    cout<<*itrIn<<"->";
    ++itrIn;
  }
  
  static_test_index = 0;
  acc = 0;
  btLnk.InOrderFold(&FoldSumAndMultyplyPerPosition<int>, &acc);
  cout<<"\nValore di acc atteso con InOrderFold: 39 - Valore ottenuto: "<<acc<<endl;
  if(acc!=39)
    result=false;
  static_test_index = 0;
  cout<<endl<<endl;

  cout<<"Atteso con BreadthMap: 0->1->2->3->4->5->"<<endl;
  cout<<"Stampa con BreadthMap: ";
  btLnk.BreadthMap(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  cout<<endl;
  lasd::BTBreadthIterator<int> itrBreadth(btLnk);
  cout<<"Stampa BreadthOrder con iteratore: ";
  while(!(itrBreadth.Terminated())){
    cout<<*itrBreadth<<"->";
    ++itrBreadth;
  }

  static_test_index = 0;
  acc = 0;
  btLnk.BreadthFold(&FoldSumAndMultyplyPerPosition<int>, &acc);
  cout<<"\nValore di acc atteso con BreadthFold: 55 - Valore ottenuto: "<<acc<<endl;
  if(acc!=55)
    result=false;
  static_test_index = 0;
  cout<<endl<<endl;
  
  return result;
}


bool TestMapsAndFoldOnBTVec(){
  bool result=true;

  lasd::Vector<int> vec(6);
  for(int i=0; i<6; i++)
      vec[i]=i;

  lasd::BinaryTreeVec<int> btVec(vec);

  cout<<"Atteso con Map: 0->1->3->4->2->5->"<<endl;
  cout<<"Stampa con Map: ";
  btVec.Map(
    [](int& dat){
      cout<<dat<<"->";
    }
  );

  int acc=0;
  btVec.Fold(&FoldAdd<int>, &acc);
  cout<<"\nValore di acc atteso con Fold: 15 - Valore ottenuto: "<<acc<<endl;
  if(acc!=15)
    result=false;
  cout<<endl<<endl;


  cout<<"Atteso con PreOrderMap: 0->1->3->4->2->5->"<<endl;
  cout<<"Stampa con PreOrderMap: ";
  btVec.PreOrderMap(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  cout<<endl;
  lasd::BTPreOrderIterator<int> itrPre(btVec);
  cout<<"Stampa PreOrder con iteratore: ";
  while(!(itrPre.Terminated())){
    cout<<*itrPre<<"->";
    ++itrPre;
  }

  static_test_index = 0;
  acc = 0;
  btVec.PreOrderFold(&FoldSumAndMultyplyPerPosition<int>, &acc);
  cout<<"\nValore di acc atteso con PreOrderFold: 52 - Valore ottenuto: "<<acc<<endl;
  if(acc!=52)
    result=false;
  static_test_index = 0;
  cout<<endl<<endl;


  cout<<"Atteso con PostOrderMap: 3->4->1->5->2->0->"<<endl;
  cout<<"Stampa con PostOrderMap: ";
  btVec.PostOrderMap(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  cout<<endl;
  lasd::BTPostOrderIterator<int> itrPost(btVec);
  cout<<"Stampa PostOrder con iteratore: ";
  while(!(itrPost.Terminated())){
    cout<<*itrPost<<"->";
    ++itrPost;
  }
  
  static_test_index = 0;
  acc = 0;
  btVec.PostOrderFold(&FoldSumAndMultyplyPerPosition<int>, &acc);
  cout<<"\nValore di acc atteso con PostOrderFold: 29 - Valore ottenuto: "<<acc<<endl;
  if(acc!=29)
    result=false;
  static_test_index = 0;
  cout<<endl<<endl;


  cout<<"Atteso con InOrderMap: 3->1->4->0->5->2->"<<endl;
  cout<<"Stampa con InOrderMap: ";
  btVec.InOrderMap(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  cout<<endl;
  lasd::BTInOrderIterator<int> itrIn(btVec);
  cout<<"Stampa InOrder con iteratore: ";
  while(!(itrIn.Terminated())){
    cout<<*itrIn<<"->";
    ++itrIn;
  }
  
  static_test_index = 0;
  acc = 0;
  btVec.InOrderFold(&FoldSumAndMultyplyPerPosition<int>, &acc);
  cout<<"\nValore di acc atteso con InOrderFold: 39 - Valore ottenuto: "<<acc<<endl;
  if(acc!=39)
    result=false;
  static_test_index = 0;
  cout<<endl<<endl;


  cout<<"Atteso con BreadthMap: 0->1->2->3->4->5->"<<endl;
  cout<<"Stampa con BreadthMap: ";
  btVec.BreadthMap(
    [](int& dat){
      cout<<dat<<"->";
    }
  );
  cout<<endl;
  lasd::BTBreadthIterator<int> itrBreadth(btVec);
  cout<<"Stampa BreadthOrder con iteratore: ";
  while(!(itrBreadth.Terminated())){
    cout<<*itrBreadth<<"->";
    ++itrBreadth;
  }
  
  static_test_index = 0;
  acc = 0;
  btVec.BreadthFold(&FoldSumAndMultyplyPerPosition<int>, &acc);
  cout<<"\nValore di acc atteso con BreadthFold: 55 - Valore ottenuto: "<<acc<<endl;
  if(acc!=55)
    result=false;
  static_test_index = 0;
  cout<<endl<<endl;
  
  return result;
}

/* ************************************************************************** */

bool TestFindMinInBST(){
  bool result=true;
  int generated_size = genSize(gen)+1;
  int generated_val;
  lasd::Vector<int> vec(generated_size);
  lasd::BST<int> BST;
  for(int i=0; i<generated_size; i++){
    generated_val = genNum(gen);
    vec[i]=generated_val;
    BST.Insert(generated_val);
  }

  int minVec=vec[0];
  for(int i=0; i<generated_size; i++){
    if(vec[i]<minVec)
      minVec=vec[i];
  }
  cout<<"minVec: "<<minVec<<endl;

  int minBST = BST.Min();
  cout<<"minBST: "<<minBST<<endl;

  if(minVec!=minBST)
    result = false;

  return result;
}

bool TestFindMaxInBST(){
  bool result=true;
  int generated_size = genSize(gen)+1;
  int generated_val;
  lasd::Vector<int> vec(generated_size);
  lasd::BST<int> BST;
  for(int i=0; i<generated_size; i++){
    generated_val = genNum(gen);
    vec[i]=generated_val;
    BST.Insert(generated_val);
  }

  int maxVec=vec[0];
  for(int i=0; i<generated_size; i++){
    if(vec[i]>maxVec)
      maxVec=vec[i];
  }
  cout<<"maxVec: "<<maxVec<<endl;

  int maxBST = BST.Max();
  cout<<"maxBST: "<<maxBST<<endl;

  if(maxVec!=maxBST)
    result = false;


  return result;
}

bool TestOperationsWithSuccessor(){
  bool result=true;
  
  return result;
}

bool TestOperationsWithPredecessor(){
  bool result=true;
  
  return result;
}

bool TestDictionaryMethods(){
  bool result=true;

  lasd::List<int> list;
  int temp_size = genSize(gen)+1;
  for(int i=0; i<temp_size; i++){
      int temp_val = genNum(gen);
      list.Insert(temp_val);
  }
  lasd::BST<int> BST1(list);
  lasd::BST<int> BST2(list);

  if(BST1!=BST2)
    result = false;

  if(BST1.Empty())
    result = false;

  if(BST1.Size()>2){
    if(BST1.Max()!=BST1.MaxNRemove())
      result = false;
    if(BST1.Min()!=BST1.MinNRemove())
      result = false;

    BST1.Insert(10);
    if(!(BST1.Exists(10)))
      result = false;
    if(!(BST1.Remove(10)))
      result = false;
  }

  BST1.Insert(10);
  BST1.Clear();
  if(!BST1.Empty())
    result = false;
  if(BST1==BST2)
    result = false;

  lasd::Vector<int> vec1(6);
  for(int i=0; i<6; i++)
    vec1[0]=i;
  lasd::Vector<int> vec2(2);
  vec2[0]=8;
  vec2[1]=9;

  BST1.Insert(3);
  if(BST1.InsertAll(vec1))
    result=false;
  if(!(BST1.InsertAll(vec2)))
    result=false;
  BST1.Remove(3);
  // BST1.BinaryTree<int>::Map(
  //   [](int& dat){
  //     cout<<dat<<"-";
  //   }
  // );
  if(!(BST1.InsertSome(vec1)))
    result=false;

  if(!(BST1.RemoveAll(vec1)))
    result=false;
  if(!(BST1.RemoveSome(vec2)))
    result=false;
  BST1.InsertAll(vec2);
  BST1.Remove(9);
  if(!(BST1.RemoveSome(vec2)))
    result=false;
  BST1.InsertAll(vec2);
  BST1.Remove(9);
  if(BST1.RemoveAll(vec2))
    result=false;
  
  return result;
}

/* ************************************************************************** */

bool TestBTVec(){
  bool result=true;

  int temp_size = genSize(gen)+1;
  lasd::Vector<int> vec(temp_size);
  for(int i=0; i<temp_size; i++){
      int temp_val = genNum(gen);
      vec[i]=temp_val;
  } 
  lasd::BinaryTreeVec<int> btv1(vec);
  lasd::BinaryTreeVec<int> btv2(vec);
  vec[genSize(gen)%temp_size]=genNum(gen);
  vec[genSize(gen)%temp_size]=genNum(gen);
  vec[genSize(gen)%temp_size]=genNum(gen);
  lasd::BinaryTreeVec<int> btv3(vec);
  lasd::BinaryTreeVec<int> btv4;
  btv4 = btv1;
  if(btv1!=btv4)
    result=false;
  if(btv1!=btv2)
    result=false;
  if(btv1==btv3)
    result=false;
  btv2.Clear();
  if(btv1==btv2)
    result=false;
  btv1.Clear();
  if(btv1!=btv2)
    result=false;


  lasd::BinaryTreeVec<int> mbtv0(std::move(vec));
  lasd::BinaryTreeVec<int> mbtv1(std::move(vec));
  lasd::BinaryTreeVec<int> mbtv2(std::move(vec));
  vec[genSize(gen)%temp_size]=genNum(gen);
  vec[genSize(gen)%temp_size]=genNum(gen);
  vec[genSize(gen)%temp_size]=genNum(gen);
  lasd::BinaryTreeVec<int> mbtv3(std::move(vec));
  lasd::BinaryTreeVec<int> mbtv4;
  mbtv4 = std::move(mbtv0);
  if(!(mbtv0.Empty()))
    result=false;
  if(mbtv1!=mbtv4)
    result=false;
  if(mbtv1!=mbtv2)
    result=false;
  if(mbtv1==mbtv3)
    result=false;
  mbtv2.Clear();
  if(mbtv1==mbtv2)
    result=false;
  mbtv1.Clear();
  if(mbtv1!=mbtv2)
    result=false;

  return result;
}


bool TestBTVecMethods(){
  bool result=true;

  lasd::Vector<int> vec(10);
  for(int i=0; i<10; i++)
      vec[i]=i;

  lasd::BinaryTreeVec<int> btVec1(vec);
  lasd::BinaryTreeVec<int> btVec2(vec);

  if(btVec1.Root().Element()!=0)
    result = false;
  if(btVec1.Root().LeftChild().Element()!=1)
    result = false;
  if(btVec1.Root().RightChild().Element()!=2)
    result = false;

  if(btVec1!=btVec2)
    result = false;
  btVec1.Root().LeftChild().Element()=15;
  if(btVec1==btVec2)
    result = false;
  btVec2.Root().LeftChild().Element()=15;
  if(btVec1!=btVec2)
    result = false;

  cout<<"left child before map: "<<btVec1.Root().LeftChild().Element()<<endl;

  lasd::BinaryTreeVec<int> btVec3;
  btVec3=btVec1;
  lasd::BinaryTreeVec<int> btVec4(btVec1);
  
  btVec1.Map(
    [](int& dat){
      dat+=dat;
    }
  );

  if(btVec1==btVec2)
    result = false;

  cout<<"left child after map: "<<btVec1.Root().LeftChild().Element()<<endl;
  if(btVec1.Root().LeftChild().Element()!=30)
    result = false;
  cout<<"left child btVec3 after map: "<<btVec3.Root().LeftChild().Element()<<endl;
  if(btVec3.Root().LeftChild().Element()!=15)
    result = false;
  cout<<"left child btVec4 after map: "<<btVec4.Root().LeftChild().Element()<<endl;
  if(btVec4.Root().LeftChild().Element()!=15)
    result = false;

  return result;
}


bool TestCompareBTVecAndBTLnk(){
  bool result=true;

  int temp_size = genSize(gen)+1;
  lasd::Vector<int> vec(temp_size);
  for(int i=0; i<temp_size; i++){
      int temp_val = genNum(gen);
      vec[i]=temp_val;
  } 

  lasd::BinaryTreeVec<int> btVec(vec);
  lasd::BinaryTreeLnk<int> btLnk(vec);
  lasd::BinaryTreeVec<int> btVec2(btLnk);
  lasd::BinaryTreeLnk<int> btLnk2(btVec);
  
  if(btVec.lasd::BinaryTree<int>::operator!=(btLnk))
    result=false;
  btVec.Clear();
  if(btVec.lasd::BinaryTree<int>::operator==(btLnk))
    result=false;
  btLnk.Clear();
  if(btVec.lasd::BinaryTree<int>::operator!=(btLnk))
    result=false;

  if(btVec2.lasd::BinaryTree<int>::operator!=(btLnk2))
    result=false;
  btVec2.Clear();
  if(btVec2.lasd::BinaryTree<int>::operator==(btLnk2))
    result=false;
  btLnk2.Clear();
  if(btVec2.lasd::BinaryTree<int>::operator!=(btLnk2))
    result=false;
  

  lasd::BinaryTreeVec<int> mbtVec(std::move(vec));
  lasd::BinaryTreeLnk<int> mbtLnk(std::move(vec));
  lasd::BinaryTreeVec<int> mbtVec2(std::move(mbtLnk));
  lasd::BinaryTreeLnk<int> mbtLnk2(std::move(mbtVec));
  
  if(mbtVec.lasd::BinaryTree<int>::operator!=(mbtLnk))
    result=false;
  mbtVec.Clear();
  if(mbtVec.lasd::BinaryTree<int>::operator==(mbtLnk))
    result=false;
  mbtLnk.Clear();
  if(mbtVec.lasd::BinaryTree<int>::operator!=(mbtLnk))
    result=false;

  if(mbtVec2.lasd::BinaryTree<int>::operator!=(mbtLnk2))
    result=false;
  mbtVec2.Clear();
  if(mbtVec2.lasd::BinaryTree<int>::operator==(mbtLnk2))
    result=false;
  mbtLnk2.Clear();
  if(mbtVec2.lasd::BinaryTree<int>::operator!=(mbtLnk2))
    result=false;

  return result;
}

/* ************************************************************************** */


bool myTest(){

/* ********************************* INIZIO ESERCIZIO 1 ***************************************** */

    bool test_result_qv = true;
    bool test_result_sv = true;
    bool test_result_sl = true;
    bool test_result_ql = true;
    bool test_copy_qv_from_vec = true;
    bool test_copy_qv_from_lst = true;
    bool test_copy_ql_from_lst = true;
    bool test_copy_ql_from_vec = true;
    bool test_copy_assignement_qv_from_vec = true;
    bool test_copy_assignement_qv_from_lst = true;
    bool test_copy_assignement_ql_from_lst = true;
    bool test_copy_assignement_ql_from_vec = true;
    bool test_move_qv_from_vec = true;
    bool test_move_qv_from_lst = true;
    bool test_move_ql_from_lst = true;
    bool test_move_ql_from_vec = true;
    bool test_move_assignement_qv_from_vec = true;
    bool test_move_assignement_qv_from_lst = true;
    bool test_move_assignement_ql_from_lst = true;
    bool test_move_assignement_ql_from_vec = true;
    bool test_copy_sv_from_vec = true;
    bool test_copy_sv_from_lst = true;
    bool test_copy_sl_from_lst = true;
    bool test_copy_sl_from_vec = true;
    bool test_copy_assignement_sv_from_vec = true;
    bool test_copy_assignement_sv_from_lst = true;
    bool test_copy_assignement_sl_from_lst = true;
    bool test_copy_assignement_sl_from_vec = true;
    bool test_move_sv_from_vec = true;
    bool test_move_sv_from_lst = true;
    bool test_move_sl_from_lst = true;
    bool test_move_sl_from_vec = true;
    bool test_move_assignement_sv_from_vec = true;
    bool test_move_assignement_sv_from_lst = true;
    bool test_move_assignement_sl_from_lst = true;
    bool test_move_assignement_sl_from_vec = true;

    bool test_equal_vec = true;
    bool test_equal_lst = true;
    bool test_equal_sv = true;
    bool test_equal_sl = true;
    bool test_equal_qv = true;
    bool test_equal_ql = true;

    bool test_insert_copy = true;
    bool test_insert_move = true;
    bool test_remove = true;
    bool test_insert_all_copy = true;
    bool test_insert_all_move = true;
    bool test_insert_some_copy = true;
    bool test_insert_some_move = true;
    bool test_remove_all = true;
    bool test_remove_some = true;

    bool test_sort_int = true;
    bool test_sort_char = true;
    bool test_sort_empty = true;
    
    for(int i=0; i<NUMERO_TEST_ITERATIVI; i++){
      lasd::Vector<int> v1(genSize(gen));
      for(ulong i=0; i<v1.Size(); i++)
        v1[i]=genNum(gen);
      lasd::QueueVec<int> qv1(v1);
      lasd::StackVec<int> sv1(v1);
      lasd::StackLst<int> sl1(v1);
      lasd::QueueLst<int> ql1(v1);
      test_result_qv &= TestQueueVec(qv1);
      test_result_sv &= TestStackVec(sv1);
      test_result_sl &= TestStackLst(sl1);
      test_result_ql &= TestQueueLst(ql1);
    }

    cout<<"\n\n*********** OUTPUTS DI DEBUG ESERCIZIO 1: ***********\n"<<endl;


    test_copy_qv_from_vec = TestCopyQueueVecFromVec();
    test_copy_qv_from_lst = TestCopyQueueVecFromLst();
    test_copy_ql_from_lst = TestCopyQueueLstFromLst();
    test_copy_ql_from_vec = TestCopyQueueLstFromVec();

    test_copy_assignement_qv_from_vec = TestCopyAssignementQueueVecFromVec();
    test_copy_assignement_qv_from_lst = TestCopyAssignementQueueVecFromLst();
    test_copy_assignement_ql_from_lst = TestCopyAssignementQueueLstFromLst();
    test_copy_assignement_ql_from_vec = TestCopyAssignementQueueLstFromVec();

    test_move_qv_from_vec = TestMoveQueueVecFromVec();
    test_move_qv_from_lst = TestMoveQueueVecFromLst();
    test_move_ql_from_lst = TestMoveQueueLstFromLst();
    test_move_ql_from_vec = TestMoveQueueLstFromVec();

    test_move_assignement_qv_from_vec = TestMoveAssignementQueueVecFromVec();
    test_move_assignement_qv_from_lst = TestMoveAssignementQueueVecFromLst();
    test_move_assignement_ql_from_lst = TestMoveAssignementQueueLstFromLst();
    test_move_assignement_ql_from_vec = TestMoveAssignementQueueLstFromVec();

    test_copy_sv_from_vec = TestCopyStackVecFromVec();
    test_copy_sv_from_lst = TestCopyStackVecFromLst();
    test_copy_sl_from_lst = TestCopyStackLstFromLst();
    test_copy_sl_from_vec = TestCopyStackLstFromVec();

    test_copy_assignement_sv_from_vec = TestCopyAssignementStackVecFromVec();
    test_copy_assignement_sv_from_lst = TestCopyAssignementStackVecFromLst();
    test_copy_assignement_sl_from_lst = TestCopyAssignementStackLstFromLst();
    test_copy_assignement_sl_from_vec = TestCopyAssignementStackLstFromVec();

    test_move_sv_from_vec = TestMoveStackVecFromVec();
    test_move_sv_from_lst = TestMoveStackVecFromLst();
    test_move_sl_from_lst = TestMoveStackLstFromLst();
    test_move_sl_from_vec = TestMoveStackLstFromVec();

    test_move_assignement_sv_from_vec = TestMoveAssignementStackVecFromVec();
    test_move_assignement_sv_from_lst = TestMoveAssignementStackVecFromLst();
    test_move_assignement_sl_from_lst = TestMoveAssignementStackLstFromLst();
    test_move_assignement_sl_from_vec = TestMoveAssignementStackLstFromVec();

    test_equal_vec = TestEqualVector();
    test_equal_lst = TestEqualList();
    test_equal_sv = TestEqualStackVec();
    test_equal_sl = TestEqualStackLst();
    test_equal_qv = TestEqualQueueVec();
    test_equal_ql = TestEqualQueueLst();
    
    test_insert_copy = TestInsertCopyInDictionary();
    test_insert_move = TestInsertMoveInDictionary();
    test_remove = TestRemoveInDictionary();
    test_insert_all_copy = TestInsertAllCopyInDictionary();
    test_insert_all_move = TestInsertAllMoveInDictionary();
    test_insert_some_copy = TestInsertSomeCopyInDictionary();
    test_insert_some_move = TestInsertSomeMoveInDictionary();
    test_remove = TestRemoveAllInDictionary();
    test_remove = TestRemoveSomeInDictionary();

    test_sort_int = TestSortInt();
    test_sort_char = TestSortChar();
    test_sort_empty = TestSortEmpty();


  /* ******************** OUTPUTS ******************** */
    cout<<"\n\n*********** RISULTATI DEI TEST SULL'ESERCIZIO 1: ***********"<<endl;

    cout<<"COSTRUTTORI COPY:"<<endl;
    cout<<"Creazione, modifica e confronto di QueueVec da Vector e da un'altra QueueVec: "<<((test_copy_qv_from_vec) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di QueueVec da List e da un'altra QueueVec: "<<((test_copy_qv_from_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di QueueLst da List e da un'altra QueueLst: "<<((test_copy_ql_from_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di QueueLst da Vector e da un'altra QueueLst: "<<((test_copy_ql_from_vec) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di StackVec da Vector e da un'altra StackVec: "<<((test_copy_sv_from_vec) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di StackVec da List e da un'altra StackVec: "<<((test_copy_sv_from_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di StackLst da List e da un'altra StackLst: "<<((test_copy_sl_from_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di StackLst da Vector e da un'altra StackLst: "<<((test_copy_sl_from_vec) ? "Corretto" : "Errore")<<endl;
    cout<<endl;
    cout<<"ASSEGNAZIONI COPY:"<<endl;
    cout<<"Assegnazione, modifica e confronto di QueueVec creata da Vector ad un'altra QueueVec: "<<((test_copy_assignement_qv_from_vec) ? "Corretto" : "Errore")<<endl;
    cout<<"Assegnazione, modifica e confronto di QueueVec creata da List ad un'altra QueueVec: "<<((test_copy_assignement_qv_from_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Assegnazione, modifica e confronto di QueueLst creata da List ad un'altra QueueLst: "<<((test_copy_assignement_ql_from_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Assegnazione, modifica e confronto di QueueLst creata da Vector ad un'altra QueueLst: "<<((test_copy_assignement_ql_from_vec) ? "Corretto" : "Errore")<<endl;
    cout<<"Assegnazione, modifica e confronto di StackVec creata da Vector ad un'altra StackVec: "<<((test_copy_assignement_sv_from_vec) ? "Corretto" : "Errore")<<endl;
    cout<<"Assegnazione, modifica e confronto di StackVec creata da List ad un'altra StackVec: "<<((test_copy_assignement_sv_from_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Assegnazione, modifica e confronto di StackLst creata da List ad un'altra StackLst: "<<((test_copy_assignement_sl_from_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Assegnazione, modifica e confronto di StackLst creata da Vector ad un'altra StackLst: "<<((test_copy_assignement_sl_from_vec) ? "Corretto" : "Errore")<<endl;
    cout<<endl;
    cout<<"COSTRUTTORI MOVE:"<<endl;
    cout<<"Creazione, modifica e confronto di QueueVec da Vector e da un'altra QueueVec: "<<((test_move_qv_from_vec) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di QueueVec da List e da un'altra QueueVec: "<<((test_move_qv_from_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di QueueLst da List e da un'altra QueueLst: "<<((test_move_ql_from_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di QueueLst da Vector e da un'altra QueueLst: "<<((test_move_ql_from_vec) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di StackVec da Vector e da un'altra StackVec: "<<((test_move_sv_from_vec) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di StackVec da List e da un'altra StackVec: "<<((test_move_sv_from_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di StackLst da List e da un'altra StackLst: "<<((test_move_sl_from_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di StackLst da Vector e da un'altra StackLst: "<<((test_move_sl_from_vec) ? "Corretto" : "Errore")<<endl;
    cout<<endl;
    cout<<"ASSEGNAZIONI MOVE:"<<endl;
    cout<<"Assegnazione, modifica e confronto di QueueVec creata da Vector ad un'altra QueueVec: "<<((test_move_assignement_qv_from_vec) ? "Corretto" : "Errore")<<endl;
    cout<<"Assegnazione, modifica e confronto di QueueVec creata da List ad un'altra QueueVec: "<<((test_move_assignement_qv_from_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Assegnazione, modifica e confronto di QueueLst creata da List ad un'altra QueueLst: "<<((test_move_assignement_ql_from_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Assegnazione, modifica e confronto di QueueLst creata da Vector ad un'altra QueueLst: "<<((test_move_assignement_ql_from_vec) ? "Corretto" : "Errore")<<endl;
    cout<<"Assegnazione, modifica e confronto di StackVec creata da Vector ad StackVec: "<<((test_move_assignement_sv_from_vec) ? "Corretto" : "Errore")<<endl;
    cout<<"Assegnazione, modifica e confronto di StackVec creata da List ad un'altra StackVec: "<<((test_move_assignement_sv_from_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Assegnazione, modifica e confronto di StackLst creata da List ad un'altra StackLst: "<<((test_move_assignement_sl_from_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Assegnazione, modifica e confronto di StackLst creata da Vector ad un'altra StackLst: "<<((test_move_assignement_sl_from_vec) ? "Corretto" : "Errore")<<endl;
    cout<<endl;

    cout<<"COMPARSION:"<<endl;
    cout<<"Confronto tra due Vector: "<<((test_equal_vec) ? "Corretto" : "Errore")<<endl;
    cout<<"Confronto tra due List: "<<((test_equal_lst) ? "Corretto" : "Errore")<<endl;
    cout<<"Confronto tra due StackVec: "<<((test_equal_sv) ? "Corretto" : "Errore")<<endl;
    cout<<"Confronto tra due StackLst: "<<((test_equal_sl) ? "Corretto" : "Errore")<<endl;
    cout<<"Confronto tra due QueueVec: "<<((test_equal_qv) ? "Corretto" : "Errore")<<endl;
    cout<<"Confronto tra due QueueLst: "<<((test_equal_ql) ? "Corretto" : "Errore")<<endl;
    cout<<endl;

    cout<<"DICTIONARY:"<<endl;
    cout<<"Inserimento di un elemento in un dizionario (copy): "<<((test_insert_copy) ? "Corretto" : "Errore")<<endl;
    cout<<"Inserimento di un elemento in un dizionario (move): "<<((test_insert_move) ? "Corretto" : "Errore")<<endl;
    cout<<"Rimozione di un elemento in un dizionario: "<<((test_remove) ? "Corretto" : "Errore")<<endl;
    cout<<"Inserimento di tutti gli elementi in un dizionario (copy): "<<((test_insert_all_copy) ? "Corretto" : "Errore")<<endl;
    cout<<"Inserimento di tutti gli elementi in un dizionario (move): "<<((test_insert_all_move) ? "Corretto" : "Errore")<<endl;
    cout<<"Inserimento di alcuni elementi in un dizionario (copy): "<<((test_insert_some_copy) ? "Corretto" : "Errore")<<endl;
    cout<<"Inserimento di alcuni elementi in un dizionario (move): "<<((test_insert_some_move) ? "Corretto" : "Errore")<<endl;
    cout<<"Rimozione di tutti gli elementi in un dizionario: "<<((test_remove_all) ? "Corretto" : "Errore")<<endl;
    cout<<"Rimozione di alcuni elementi in un dizionario: "<<((test_remove_some) ? "Corretto" : "Errore")<<endl;
    cout<<endl;

    cout<<"SORT:"<<endl;
    cout<<"Sort di un vettore di interi: "<<((test_sort_int) ? "Corretto" : "Errore")<<endl;
    cout<<"Sort di un vettore di char: "<<((test_sort_char) ? "Corretto" : "Errore")<<endl;
    cout<<"Sort di un vettore vuoto: "<<((test_sort_empty) ? "Corretto" : "Errore")<<endl;
    cout<<endl;

    cout<<"RIEMPIMENTO E SVUOTAMENTO:"<<endl;
    cout<<"Risultato "<<NUMERO_TEST_QV<<" test di confronto, riempimento e svuotamento su QueueVec "<<((test_result_qv) ? "Corretto" : "Errore")<<endl;
    cout<<"Risultato "<<NUMERO_TEST_SV<<" test di confronto, riempimento e svuotamento su StackVec: "<<((test_result_sv) ? "Corretto" : "Errore")<<endl;
    cout<<"Risultato "<<NUMERO_TEST_QL<<" test di confronto, riempimento e svuotamento su QueueLst: "<<((test_result_ql) ? "Corretto" : "Errore")<<endl;
    cout<<"Risultato "<<NUMERO_TEST_SL<<" test di confronto, riempimento e svuotamento su StackLst: "<<((test_result_sl) ? "Corretto" : "Errore")<<endl;
    cout<<endl;

    bool test_exercise1 = (test_copy_qv_from_vec && test_copy_qv_from_lst &&
            test_copy_ql_from_lst && test_copy_ql_from_vec &&
            test_copy_assignement_qv_from_vec && test_copy_assignement_qv_from_lst &&
            test_copy_assignement_ql_from_lst && test_copy_assignement_ql_from_vec &&
            test_move_qv_from_vec && test_move_qv_from_lst && 
            test_move_ql_from_lst && test_move_ql_from_vec && 
            test_move_assignement_qv_from_vec && test_move_assignement_qv_from_lst && 
            test_move_assignement_ql_from_lst && test_move_assignement_ql_from_vec && 
            test_copy_sv_from_vec && test_copy_sv_from_lst && 
            test_copy_sl_from_lst && test_copy_sl_from_vec && 
            test_copy_assignement_sv_from_vec && test_copy_assignement_sv_from_lst && 
            test_copy_assignement_sl_from_lst && test_copy_assignement_sl_from_vec && 
            test_move_sv_from_vec && test_move_sv_from_lst && 
            test_move_sl_from_lst && test_move_sl_from_vec && 
            test_move_assignement_sv_from_vec && test_move_assignement_sv_from_lst && 
            test_move_assignement_sl_from_lst && test_move_assignement_sl_from_vec && 
            test_equal_vec && test_equal_lst && 
            test_equal_sv && test_equal_sl && 
            test_equal_qv && test_equal_ql && 
            test_insert_copy && test_insert_move && 
            test_remove && test_insert_all_copy && 
            test_insert_all_move && test_insert_some_copy &&
            test_insert_some_move && test_remove && 
            test_remove && test_result_qv && 
            test_result_sv && test_result_ql && 
            test_result_sl && test_sort_int && 
            test_sort_char && test_sort_empty
            );
/* ********************************* FINE ESERCIZIO 1 ***************************************** */



/* ********************************* INIZIO ESERCIZIO 2 ***************************************** */

    bool test_compare_BST_copy = true;
    bool test_compare_BST_move = true;
    bool test_compare_BT_and_BST_from_lst_copy = true;
    bool test_compare_BT_and_BST_from_lst_move = true;
    bool test_compare_BT_and_BST_from_vec_copy = true;
    bool test_compare_BT_and_BST_from_vec_move = true;
    bool test_compare_empty_BT_and_BST = true;

    bool test_iterator_on_BT = true;
    bool test_iterator_on_empty_BT = true;
    bool test_iterator_after_move = true;

    bool test_maps_and_fold_on_BTLnk = true;
    bool test_maps_and_fold_on_BTVec = true;

    bool test_find_min_in_BST = true;
    bool test_find_max_in_BST = true;
    bool test_operations_with_successor = true;
    bool test_operations_with_predecessor = true;
    bool test_dictionary_methods = true;

    bool test_BT_Vec = true;
    bool test_BT_Vec_methods = true;
    bool test_compare_BTVec_And_BTLnk = true;

    cout<<"\n\n*********** OUTPUTS DI DEBUG ESERCIZIO 2: ***********\n"<<endl;

    test_compare_BST_copy = TestCompareBSTCopy();
    test_compare_BST_move = TestCompareBSTMove();
    test_compare_BT_and_BST_from_lst_copy = TestCompareBTAndBSTFromLstCopy();
    test_compare_BT_and_BST_from_lst_move = TestCompareBTAndBSTFromLstMove();
    test_compare_BT_and_BST_from_vec_copy = TestCompareBTAndBSTFromVecCopy();
    test_compare_BT_and_BST_from_vec_move = TestCompareBTAndBSTFromVecMove();
    test_compare_empty_BT_and_BST = TestCompareEmptyBTAndBST();

    test_iterator_on_BT = TestIteratorOnBT();
    test_iterator_on_empty_BT = TestIteratorOnEmptyBT();
    test_iterator_after_move = TestIteratorAfterMove();

    test_maps_and_fold_on_BTLnk = TestMapsAndFoldOnBTLnk();
    test_maps_and_fold_on_BTVec = TestMapsAndFoldOnBTVec();

    test_find_min_in_BST = TestFindMinInBST();
    test_find_max_in_BST = TestFindMaxInBST();
    test_operations_with_successor = TestOperationsWithSuccessor();
    test_operations_with_predecessor = TestOperationsWithPredecessor();
    test_dictionary_methods = TestDictionaryMethods();

    test_BT_Vec = TestBTVec();
    test_BT_Vec_methods = TestBTVecMethods();
    test_compare_BTVec_And_BTLnk = TestCompareBTVecAndBTLnk();


  /* ******************** OUTPUTS ******************** */
    cout<<"\n\n*********** RISULTATI DEI TEST SULL'ESERCIZIO 2: ***********"<<endl;
    
    cout<<"BT AND BST COMPARSION:"<<endl;
    cout<<"Creazione, modifica e confronto di BST da copy: "<<((test_compare_BST_copy) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di BST da move: "<<((test_compare_BST_move) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di BT e BST da copy di una lista: "<<((test_compare_BT_and_BST_from_lst_copy) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di BT e BST da move di una lista: "<<((test_compare_BT_and_BST_from_lst_move) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di BT e BST da copy di un vettore: "<<((test_compare_BT_and_BST_from_vec_copy) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, modifica e confronto di BT e BST da move di un vettore: "<<((test_compare_BT_and_BST_from_vec_move) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione e confronto di BT e BST vuoti: "<<((test_compare_empty_BT_and_BST) ? "Corretto" : "Errore")<<endl;
    cout<<endl;
    cout<<"ITERATORS:"<<endl;
    cout<<"Creazione, copia, assegnazione e confronto di Iteratori su BT: "<<((test_iterator_on_BT) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione, copia, assegnazione e confronto di Iteratori su BT vuoti: "<<((test_iterator_on_empty_BT) ? "Corretto" : "Errore")<<endl;
    cout<<"Creazione ed utilizzo di Iteratori in seguito a funzioni di move: "<<((test_iterator_after_move) ? "Corretto" : "Errore")<<endl;
    cout<<endl;
    cout<<"MAPS AND FOLD:"<<endl;
    cout<<"Test di funzioni di Map e di Fold su BTLnk: "<<((test_maps_and_fold_on_BTLnk) ? "Corretto" : "Errore")<<endl;
    cout<<"Test di funzioni di Map e di Fold su BTVec: "<<((test_maps_and_fold_on_BTVec) ? "Corretto" : "Errore")<<endl;
    cout<<endl;
    cout<<"RESEARCH ON BST:"<<endl;
    cout<<"Ricerca randomica del min su un BST: "<<((test_find_min_in_BST) ? "Corretto" : "Errore")<<endl;
    cout<<"Ricerca randomica del max su un BST: "<<((test_find_max_in_BST) ? "Corretto" : "Errore")<<endl;
    // cout<<"Operazioni sul successore in un BST: "<<((test_operations_with_successor) ? "Corretto" : "Errore")<<endl;
    // cout<<"Operazioni sul predecessore in un BST: "<<((test_operations_with_predecessor) ? "Corretto" : "Errore")<<endl;
    cout<<"Operazioni di dizionario in un BST: "<<((test_dictionary_methods) ? "Corretto" : "Errore")<<endl;
    cout<<endl;
    cout<<"BT VECTOR:"<<endl;
    cout<<"Creazione, modifica e confronti di BTVec: "<<((test_BT_Vec) ? "Corretto" : "Errore")<<endl;
    cout<<"Operazioni eseguibili su BTVec: "<<((test_BT_Vec_methods) ? "Corretto" : "Errore")<<endl;
    cout<<"Confronti tra BTVec e BTLnk: "<<((test_compare_BTVec_And_BTLnk) ? "Corretto" : "Errore")<<endl;
    cout<<endl;
    

    bool test_exercise2 = (test_compare_BST_copy && test_compare_BST_move && 
    test_compare_BT_and_BST_from_lst_copy && test_compare_BT_and_BST_from_lst_move && 
    test_compare_BT_and_BST_from_vec_copy && test_compare_BT_and_BST_from_vec_move && 
    test_compare_empty_BT_and_BST && test_iterator_on_empty_BT && test_iterator_on_BT && 
    test_iterator_after_move && test_maps_and_fold_on_BTLnk && test_maps_and_fold_on_BTVec && 
    test_find_min_in_BST && test_find_max_in_BST && 
    test_operations_with_successor && test_operations_with_predecessor && 
    test_dictionary_methods && test_BT_Vec && test_BT_Vec_methods && 
    test_compare_BTVec_And_BTLnk);


/* ********************************* FINE ESERCIZIO 2 ***************************************** */

/* ********************************* OUTPUTS FINALI ***************************************** */

    bool total_test = (test_exercise1 && test_exercise2);

    cout<<"RISULTATO TEST:"<<endl;
    cout<<"Esercizio 1: "<<((test_exercise1) ? "Superato" : "Contiene errori")<<endl;
    cout<<"Esercizio 2: "<<((test_exercise2) ? "Superato" : "Contiene errori")<<endl;
    cout<<"Non sono stati trovati errori: "<<((total_test) ? "True" : "False")<<endl;
    cout<<endl;

            

    return true;
}

#endif