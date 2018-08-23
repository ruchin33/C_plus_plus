/*  Name: Ruchin Patel
 *  USC NetID: ruchinpa
 *  CS 455 Spring 2017
 *
 *  See ecListFuncs.h for specification of each function.
 */

#include <iostream>

#include <cassert>

#include "ecListFuncs.h"

using namespace std;

/**
	position: the final index of the list
	count   : keeps track of which element is being visited
	
	@return : The position of the value in the list is returned
*/
int lastIndexOf(ListType list, int val) {

  int position = -1; 	
  int count = 0;     	
  
  if(list == NULL){  	
  	return position;
  }
  
  while(list != NULL){
  	if(list->data == val){
  		position = count;
  	}
  	
  	list = list->next;
  	count ++;
  }
  
  return position;
  
}

/**
	first        : Points to the begining of the original list
	temp         : Temporary list type to traverse through the list to 
	next_node    : The next value in the list if the first value is even
	current_node : The current node of linked list whose data is even
*/

void removeFollowingEvens(ListType &list) {

	if(list == NULL){	
		return;
	}

	ListType first = list;
	ListType temp = list;
	
	while(temp->next != NULL){
		
		if(temp->data %2 == 0){
			
			ListType current_node = temp;
			ListType next_node = temp->next;
			if(next_node->data %2 == 0){
				
				if(next_node->next == NULL){
					list = next_node;
					delete list;
					temp->next = NULL;
				}
				else{
					list = temp;
					delete list->next;
					list->next = list->next->next;
					temp = current_node;
				}
				
			}
			else{
				temp = temp->next;
			}
		}
		else{
			temp = temp->next;
		}
	}
	list = first;
	
}


/**
	first_node    : points to the first node of the original linked list
	mirrored_list : The new mirrored list which is to be concantenated to the original list
*/
void mirrorList(ListType & list) {

	if(list == NULL){
		return;
	}
	
	ListType first_node = list;
	ListType mirrored_list = NULL;
	while(list->next != NULL){
		insertFront(mirrored_list,list->data);
		list = list->next;	
	}
	insertFront(mirrored_list,list->data);
	list->next = mirrored_list;
	list = first_node;
	
}



/**
	p 		   : The temporary list that points to the original list
	first_node : The first node of the linked list after rotating which would be eventually
				 set as the first node of the original list
	seperator  : The position in the list from which the list has to be rotated
*/
void rotateRight(ListType &list, int k) {
	
	if(list == NULL){
		return;
	}
	if(k<=0){
		return;
	}
	
	ListType p = list;
	ListType first_node = p;
	int list_size = 0;
	
	while(p->next != NULL){     // This loop counts the no of elements in the list
		p = p->next;
		list_size++;
	}
	if(k>=list_size){
		return;
	}
	
	p->next = first_node;
	p = list;
	int seperator = list_size - k;
	
	while(seperator>0){       // This loop takes the pointer till the seperator and rotates the entire list
		p = p->next;
		seperator--;
	}		
	
	first_node = p->next;
	p->next = NULL;
	list = first_node;	
	
}









