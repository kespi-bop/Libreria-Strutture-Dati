#ifndef MYTEST_CPP
#define MYTEST_CPP

#include <iostream>

using namespace std;

#define MAX_SIZE 200
#define MIN_SIZE 1
#define NUMERO_TEST_QV 2
#define NUMERO_TEST_SV 2
#define NUMERO_TEST_QL 2
#define NUMERO_TEST_SL 2

#define NUMERO_TEST_ITERATIVI 10

#define TEST_QV 1
#define TEST_SV 1
#define TEST_QL 1
#define TEST_SL 1

#include <random>
default_random_engine gen(random_device{}());
uniform_int_distribution<int> genSize(MIN_SIZE,MAX_SIZE);
uniform_int_distribution<int> genNum(INT32_MIN,INT32_MAX);


#include "test.hpp"

bool TestQueuevec(lasd::QueueVec<int> s2){
    bool test_result_qv = true;
    int numtest_qv = NUMERO_TEST_QV;
    ulong init_size = s2.Size();
    while(numtest_qv>0){
      lasd::QueueVec<int> s1(s2);
      int temp_size = genSize(gen);
      cout<<"\n\n****************************** INIZIO RIEMPIMENTO ******************************\n\n";  
      for(ulong i{0}; i<temp_size; i++){
        int temp_num = genNum(gen);
        s1.Enqueue(temp_num);
        cout<<temp_num<<"\t Size(): "<<s1.Size()<<"\t size: "<<endl;
      }
      cout<<"\n\n****************************** INIZIO SVUOTAMENTO ******************************\n\n";
      while(s1.Size()>0) {
        cout<<s1.HeadNDequeue()<<"\t Size(): "<<s1.Size()<<"\t size: "<<endl;
        temp_size--;
      }
      if(temp_size+init_size!=0) {
        cout<<"\ntemp: "<<temp_size<<"\tinit: "<<init_size;
        test_result_qv = false;
        cout<<"\nVettore svuotato NON correttamente\n\n";
      } else cout<<"\nVettore svuotato correttamente\n\n";
      numtest_qv--;
    }
    return test_result_qv && !numtest_qv;
}

bool TestStackvec(lasd::StackVec<int> s2){
  bool test_result_sv = true;
  int numtest_sv = NUMERO_TEST_SV;
  ulong init_size = s2.Size();
  if(TEST_SV){
    while(numtest_sv>0){
       lasd::StackVec<int> s1(s2);
      int temp_size = genSize(gen);
      cout<<"\n\n****************************** INIZIO RIEMPIMENTO ******************************\n\n";  
      for(ulong i{0}; i<temp_size; i++){
        int temp_num = genNum(gen);
        s1.Push(temp_num);
        cout<<temp_num<<"\t Size(): "<<s1.Size()<<"\t size: "<<endl;
      }
      cout<<"\n\n****************************** INIZIO SVUOTAMENTO ******************************\n\n";
      while(s1.Size()>0) {
        cout<<s1.TopNPop()<<"\t Size(): "<<s1.Size()<<"\t size: "<<endl;
        temp_size--;
      }
      if(temp_size+init_size!=0) {
        cout<<"\ntemp: "<<temp_size<<"\tinit: "<<init_size;
        test_result_sv = false;
        cout<<"\nVettore svuotato NON correttamente\n\n";
      } else cout<<"\nVettore svuotato correttamente\n\n";
      numtest_sv--;
    }
  }
  return test_result_sv && !numtest_sv;
}

bool TestQueuelst(lasd::QueueLst<int> s2){
  bool test_result_ql = true;
  int numtest_ql = NUMERO_TEST_QL;
  ulong init_size = s2.Size();
  if(TEST_QL){
    while(numtest_ql>0){
        lasd::QueueLst<int> s1(s2);
      int temp_size = genSize(gen);
      cout<<"\n\n****************************** INIZIO RIEMPIMENTO ******************************\n\n";  
      for(ulong i{0}; i<temp_size; i++){
        int temp_num = genNum(gen);
        s1.Enqueue(temp_num);
        cout<<temp_num<<"\t Size(): "<<s1.Size()<<"\t size: "<<endl;
      }
      cout<<"\n\n****************************** INIZIO SVUOTAMENTO ******************************\n\n";
      while(s1.Size()>0) {
        cout<<s1.HeadNDequeue()<<"\t Size(): "<<s1.Size()<<"\t size: "<<endl;
        temp_size--;
      }
      if(temp_size+init_size!=0) {
        cout<<"\ntemp: "<<temp_size<<"\tinit: "<<init_size;
        test_result_ql = false;
        cout<<"\nVettore svuotato NON correttamente\n\n";
      } else cout<<"\nVettore svuotato correttamente\n\n";
      numtest_ql--;
    }
  }
  return test_result_ql && !numtest_ql;
}

bool TestStacklst(lasd::StackLst<int> s2){
  bool test_result_sl = true;
  int numtest_sl = NUMERO_TEST_SL;
  ulong init_size = s2.Size();
  if(TEST_SL){
    while(numtest_sl>0){
        lasd::StackLst<int> s1(s2);
      int temp_size = genSize(gen);
      cout<<"\n\n****************************** INIZIO RIEMPIMENTO ******************************\n\n";  
      for(ulong i{0}; i<temp_size; i++){
        int temp_num = genNum(gen);
        s1.Push(temp_num);
        cout<<temp_num<<"\t Size(): "<<s1.Size()<<"\t size: "<<endl;
      }
      cout<<"\n\n****************************** INIZIO SVUOTAMENTO ******************************\n\n";
      while(s1.Size()>0) {
        cout<<s1.TopNPop()<<"\t Size(): "<<s1.Size()<<"\t size: "<<endl;
        temp_size--;
      }
      if(temp_size+init_size!=0) {
        cout<<"\ntemp: "<<temp_size<<"\tinit: "<<init_size;
        test_result_sl = false;
        cout<<"\nLista svuotata NON correttamente\n\n";
      } else cout<<"\nLista svuotata correttamente\n\n";
      numtest_sl--;
    }
  }
  return test_result_sl && !numtest_sl;
}
/* ************************************************************************** */
bool mytest(){

    bool test_result_qv = true;
    bool test_result_sv = true;
    bool test_result_sl = true;
    bool test_result_ql = true;
    
    for(int i{0}; i<NUMERO_TEST_ITERATIVI; i++){
      lasd::Vector<int> v1(genSize(gen));
      for(ulong i{0}; i<v1.Size(); i++) v1[i]=genNum(gen);
      lasd::QueueVec<int> qv1(v1);
      lasd::StackVec<int> sv1(v1);
      lasd::StackLst<int> sl1(v1);
      lasd::QueueLst<int> ql1(v1);
      test_result_qv &= TestQueuevec(move(qv1));
      test_result_sv &= TestStackvec(move(sv1));
      test_result_sl &= TestStacklst(move(sl1));
      test_result_ql &= TestQueuelst(move(ql1));
    }

    lasd::Vector<int> v1(10);
    for(ulong i{0}; i<v1.Size(); i++){
      v1[i]=i;
    }
    lasd::QueueVec<int> qv1(v1);
    lasd::QueueVec<int> qv2(qv1);

    std::cout<<"Test == : "<<(qv1==qv2)<<std::endl;
    std::cout<<"\nCODA 1 :\n";
    while(qv1.Size()>0) std::cout<<qv1.HeadNDequeue()<<"\t";
    std::cout<<"\nCODA 2 :\n";
    while(qv2.Size()>0) std::cout<<qv2.HeadNDequeue()<<"\t";




    if(TEST_QV) cout<<"RISULTATO "<<NUMERO_TEST_QV<<" TESTS SU QUEUEVEC: "<<((test_result_qv) ? "PASSATO" : "ERRATO")<<endl;
    if(TEST_SV) cout<<"RISULTATO "<<NUMERO_TEST_SV<<" TESTS SU STACKVEC: "<<((test_result_sv) ? "PASSATO" : "ERRATO")<<endl;
    if(TEST_QL) cout<<"RISULTATO "<<NUMERO_TEST_QL<<" TESTS SU QUEUELST: "<<((test_result_ql) ? "PASSATO" : "ERRATO")<<endl;
    if(TEST_SL) cout<<"RISULTATO "<<NUMERO_TEST_SL<<" TESTS SU STACKLST: "<<((test_result_sl) ? "PASSATO" : "ERRATO")<<endl;
    cout<<endl;
    return (test_result_qv && test_result_sv && test_result_ql && test_result_sl);

    return true;
}

#endif