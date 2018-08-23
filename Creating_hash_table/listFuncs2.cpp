// Name: Ruchin Patel
// Loginid: ruchinpa
// CSCI 455 PA5
// Spring 2017


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
  key = theKey;
  value = theValue;
  next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
  key = theKey;
  value = theValue;
  next = n;
}




//*************************************************************************
// put the function definitions for your list functions below

/**
	returns the address of the value of a particular target if it is present
*/
int* present(const ListType &list, string target){

	Node *p = list;
	if(list == NULL){
		return NULL;
	}
	while(p != NULL){

		if(p->key == target){
			return &p->value;
		}
		p = p->next;
	}
	return NULL;
}

bool insertFront(ListType &list,string target, int val){

	Node *p = list;
	while(p != NULL){
		if(p->key == target){
			return false;
		}
		p = p->next;
	}
	
	Node *newguy = new Node(target,val);
  	newguy->next = list;
  	list = newguy;
  	return true;
}

void removeFront(ListType &list){
	if(list == NULL){
		return;
	}
	else{
		Node *p = list->next;
		delete list;
		list = p;
	}
}


void removeLast(ListType &list) {

  	if (list == NULL) {  // no elements in list
    	return;
  	}

  	if (list->next == NULL) {   // one element in list
    	delete list;
    	list = NULL;
    	return;
  	}
  	// we know here that the list has at least 2 elements
  	Node *p = list;
  	while (p->next->next != NULL) {
    	p = p->next;
  	}

  	// p currently points to second to last element

  	Node *deadGuy = p->next;
  	p->next = NULL;  // p becomes the last element in the list
  	delete deadGuy;

}

void printList(const ListType &list){

	if (list == NULL){
   		cout << "<empty>"<<endl;
  	}
	else{
		Node *p = list;
		while(p != NULL){
			cout<<p->key<<" "<<p->value<<endl;
			p = p->next;
		}
	}
}

void printFirst(const ListType &list){
	if(list == NULL){
		return;
	}
	else{
		cout<<list->key<<" "<<list->value<<endl;
	}
}


void printLast(const ListType &list) {

  if (list == NULL) {
    cout << "<empty>" << endl;
    return;
  }

  Node *p = list;
  while (p->next != NULL) {  // stop when p points to the last element in the list
    p = p->next;
  }
  cout << p->key<<" "<<p->value<<endl;
}


int size(const ListType &list){

	int count=0;
	if(list==NULL){
		return 0;
	}
	else{
		Node *p = list;
		while(p != NULL){
			count++;
			p = p->next;
		}
	}
	return count;
}


void clearList(ListType &list){

  Node *rest = list;
  while (list != NULL) {
    rest = list->next;  // rest is all but the first element
    delete list;  // reclaims one node only
    list = rest;
  }

}


void append (ListType &list, const string &key, int value)
{
  ListType p = list;

  if (list == NULL) {
    insertFront(list, key, value);
    return;
  }

  while (p->next != NULL) {
    p = p->next;
  }

  p->next = new Node(key, value);
}


bool listRemove(ListType &list, const string &target) {

  	if (list == NULL) {
    	return false;
  	}
  
  	if (list->next == NULL) {   // only one element in list
    	if(list->key == target) {
			delete list;
			list = NULL;
			return true;
		}
		else{
			return false;
		}
  	}
  
  	int count = 0;
  
  	ListType p = list;
  	ListType prev = NULL;
  
  	while(p != NULL){
  		count++;
  		if(count == 1){ 
  			if(p->key == target){
  				Node *q = p->next;
  				delete p;
  				list =  q;
  				return true;
  			}
  		}
  		else if(count != 1){
  			if(p->next == NULL){  //last element
  				if(p->key == target){
  					delete p;
  					prev->next = NULL;
  					return true;
  				}
  			}
  			else{                //any other element
  				if(p->key == target){
  					Node *q = p->next;
  					delete p;
  					prev->next = q;
  					return true;
  				}
  			}
  		}
  		else{
  			return false;
  		}
  		
  		prev = p;
    	p = p->next;
  		
  	}
  	return false;
}






