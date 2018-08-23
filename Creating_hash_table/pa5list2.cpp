// Name:
// loginid:
// CS 455 PA5

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {

  string s1="";
  int val=0;
  
  ListType theList = NULL;
  printList(theList);
  cout<<"The size of the linked list is:"<<size(theList)<<endl;
  bool a1 = insertFront(theList,"ruchin",1);
  bool a2 = insertFront(theList,"Disha",2);
  bool a3 = insertFront(theList,"love",5);
  bool a4 = insertFront(theList,"yeh",7);
  bool a5 = insertFront(theList,"whhh",1);
  bool a6 = insertFront(theList,"Disha",2);
  printList(theList);
  cout<<"The size of the linked list is:"<<size(theList)<<endl;
  int *address;
  address = present(theList,"ruchin");
  if(address != NULL){
  	cout<<*address<<endl;
  }
  address = present(theList,"yeh");
  if(address != NULL){
  	cout<<*address<<endl;
  }
  address = present(theList,"yehkoko");
  if(address != NULL){
  	cout<<*address<<endl;
  }
  
  printFirst(theList);
  printLast(theList);
  cout<<"The size of the linked list is:"<<size(theList)<<endl<<endl;
  
  removeFront(theList);
  removeLast(theList);
  printFirst(theList);
  printLast(theList);
  cout<<"The size of the linked list is:"<<size(theList)<<endl<<endl;
  
  printList(theList);
  cout<<"The size of the linked list is:"<<size(theList)<<endl<<endl;
  
  removeLast(theList);
  removeLast(theList);
  removeLast(theList);
  removeLast(theList);
  cout<<"The size of the linked list is:"<<size(theList)<<endl<<endl;
  
  
  bool a7 = insertFront(theList,"abc",1);
  bool a8 = insertFront(theList,"def",2);
  bool a9 = insertFront(theList,"ghi",5);
  bool a10 = insertFront(theList,"jkl",7);
  bool a11 = insertFront(theList,"mno",1);
  bool a12 = insertFront(theList,"pqr",2);
  printList(theList);
  cout<<"The size of the linked list is:"<<size(theList)<<endl<<endl;
  
  bool a13 = listRemove(theList,"ghi");
  printList(theList);
  cout<<"The size of the linked list is:"<<size(theList)<<endl<<endl;
  bool a14 = listRemove(theList,"ruchin");
  printList(theList);
  cout<<"The size of the linked list is:"<<size(theList)<<endl<<endl;
  bool a15 = listRemove(theList,"def");
  printList(theList);
  cout<<"The size of the linked list is:"<<size(theList)<<endl<<endl;
  bool a16 = listRemove(theList,"abc");
  printList(theList);
  cout<<"The size of the linked list is:"<<size(theList)<<endl<<endl;
  bool a17 = listRemove(theList,"jkl");
  printList(theList);
  cout<<"The size of the linked list is:"<<size(theList)<<endl<<endl;
  bool a18 = listRemove(theList,"mno");
  printList(theList);
  cout<<"The size of the linked list is:"<<size(theList)<<endl<<endl;
  bool a19 = listRemove(theList,"pqr");
  printList(theList);
  cout<<"The size of the linked list is:"<<size(theList)<<endl<<endl;
  
  
  removeFront(theList);
  printList(theList);
  cout<<"The size of the linked list is:"<<size(theList)<<endl<<endl;
  removeLast(theList);
  printList(theList);
  cout<<"The size of the linked list is:"<<size(theList)<<endl<<endl;
  return 0;
}