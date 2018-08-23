// Name: Ruchin Patel
// Loginid: ruchinpa
// CSCI 455 PA5
// Spring 2017


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  
using namespace std;

struct Node {
  string key;
  int value;

  Node *next;

  Node(const string &theKey, int theValue);

  Node(const string &theKey, int theValue, Node *n);
};



typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.


bool listRemove(ListType &list, const string &key);

int* present(const ListType &list, string target);  //done

bool insertFront(ListType &list,string target, int val);  //done

void removeFront(ListType &list); //done

void removeLast(ListType &list);

void printList(const ListType &list); //done

void printFirst(const ListType &list);

void printLast(const ListType &list);

void clearList(ListType &list); //done

int size(const ListType &list); //done

void append (ListType &list, const string &key, int value);

bool remove(ListType &list, const string &key);













// keep the following line at the end of the file
#endif