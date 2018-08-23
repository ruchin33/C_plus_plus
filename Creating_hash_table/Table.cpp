// Name: Ruchin Patel
// Loginid: ruchinpa
// CSCI 455 PA5
// Spring 2017

// Table.cpp  Table class implementation


/*
 * Modified 11/22/11 by CMB
 *   changed name of constructor formal parameter to match .h file
 */

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************


Table::Table() {
	
	buckets = new ListType[HASH_SIZE];
	hashSize = HASH_SIZE;
	for(int i=0;i<hashSize;i++){
		buckets[i] = NULL;
	}
	//entries = numEntries();
	//cout<<"in the table contructor"<<size(buckets[0])<<endl;
	//printList(buckets[0]);
	
}


Table::Table(unsigned int hSize) {
	
	buckets = new ListType[hSize];
	hashSize = hSize;
	for(int i=0;i<hashSize;i++){
		buckets[i] = NULL;
	}
	//entries = numEntries();
	//cout<<"in the table contructor"<<size(buckets[0])<<endl;
	//printList(buckets[0]);
	
}


int * Table::lookup(const string &key) {

	int *address;
	address = present(buckets[hashCode(key)],key);
  	return address;   // dummy return value for stub
}

bool Table::remove(const string &key) {
  	
  	bool checker = false;
  	checker = listRemove(buckets[hashCode(key)],key);
  	return checker;
}

bool Table::insert(const string &key, int value) {
	  
	//cout<<"here1"<<endl;                     //remove this
	//int hash_value = hashCode(key);
	//cout<<"here2"<<endl;                     //remove this
	//cout<<"hash value: "<<hash_value;       //remove this
	bool in_list = false;
	//cout<<"here3"<<endl;                     //remove this
	in_list = insertFront(buckets[hashCode(key)],key,value);
	//cout<<"here4"<<endl;                     //remove this
	return in_list;
}

int Table::numEntries() const {
	int tot_entry = 0;
	//cout<<"hash size: "<<hashSize<<endl;
	for(int i=0; i<hashSize;i++){
		//cout<<"bucket size:"<<size(buckets[i])<<endl;
		//cout<<"tot_entry:"<<tot_entry<<endl;
		int curr_buc_size = size(buckets[i]);
		//cout<<"curr_buc_size "<<i<<" :"<<curr_buc_size <<endl;
		tot_entry = tot_entry+curr_buc_size;
	}
	//cout<<"size of 0th bucket"<<size(buckets[0])<<endl;
	//printList(buckets[0]);
	//cout<<e<<endl;  //remove this
	return tot_entry;
}


void Table::printAll() const {

	for(int i=0;i<hashSize;i++){
		if(size(buckets[i]) > 0){
			printList(buckets[i]);
		}
	}

}

void Table::hashStats(ostream &out) const {

	//cout<<"hwsdajksn "<<endl;
	int non_empty = 0;
	int longest = 0;
	//cout<<"here0 "<<endl;
	for(int i=0;i<hashSize;i++){
		//cout<<"here1 "<<endl;
		if(size(buckets[i]) > 0){
			non_empty++;
		} 
		if(size(buckets[i]) > longest){
			longest = size(buckets[i]);
		}
	}
	out<<"number of buckets: "<<hashSize<<endl;
	out<<"number of entries: "<<numEntries()<<endl;
	out<<"number of non-empty buckets: "<<non_empty<<endl;
	out<<"longest chain: "<<longest<<endl;
  
}


// add definitions for your private methods here

