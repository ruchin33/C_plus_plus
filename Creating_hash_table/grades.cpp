// Name: Ruchin Patel
// Loginid: ruchinpa
// CSCI 455 PA5
// Spring 2017

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

int main(int argc, char * argv[]) {

  // gets the hash table size from the command line

  int hashSize = Table::HASH_SIZE;

  Table * grades;  // Table is dynamically allocated below, so we can call
                   // different constructors depending on input from the user.

  if (argc > 1) {
    hashSize = atoi(argv[1]);  // atoi converts c-string to int

    if (hashSize < 1) {
      cout << "Command line argument (hashSize) must be a positive number" 
	   << endl;
      return 1;
    }

    grades = new Table(hashSize);

  }
  else {   // no command line args given -- use default table size
    grades = new Table();
  }


  grades->hashStats(cout);

  // add more code here
  // Reminder: use -> when calling Table methods, since grades is type Table*
  
  string input="";

  cout<<"cmd> ";
  while(input != "quit"){
  	cin>>input;
  	if(input == "help"){
  		cout<<"insert name score"<<endl<<"Insert this name and score in the grade table. If this name was already present, print a message to that effect, and don't do the insert"<<endl<<endl;
		cout<<"change name newscore"<<endl<<"Change the score for name. Print an appropriate message if this name isn't present"<<endl<<endl;
		cout<<"remove name"<<endl<<"Remove this student. If this student wasn't in the grade table, print a message to that effect"<<endl<<endl;
		cout<<"print"<<endl<<"Prints out all names and scores in the table."<<endl<<endl;
		cout<<"size"<<endl<<"Prints out the number of entries in the table."<<endl<<endl;
		cout<<"stats"<<endl<<"Prints out statistics about the hash table at this point. (Calls hashStats() method)."<<endl<<endl;
  		cout<<"quit"<<endl<<"Exits the program."<<endl<<endl;
  		cout<<"help"<<endl<<"Prints out a brief command summary."<<endl<<endl;
  	}
  	else if(input == "insert"){
  		
  		string name;
  		int score;
  		bool checker = false;
  		cin>>name>>score;
  		checker = grades->insert(name,score);
  		if(checker == false){
  			cout<<"Already present"<<endl;
  		}
  	}
  	else if(input == "stats"){
  		grades->hashStats(cout);
  	}
  	else if(input == "print"){
  		grades->printAll();
  	}
  	else if(input == "change"){
  		
  		string name;
  		int new_score;
  		int *address;
  		cin>>name>>new_score;
  		address = grades->lookup(name);
  		*address = new_score;
  		
  	}
  	else if(input == "remove"){
  		
  		string name;
  		bool checker = false;
  		cin>>name;
  		checker = grades->remove(name);
  		if(checker == false){
  			cout<<"The student specified to remove is not present in the list"<<endl;
  		}
  		
  	}
  	else if(input == "size"){
  	
  		cout<<"The total number of entries are: "<<grades->numEntries()<<endl;
  		
  	}
  	else if(input == "quit"){
  		break;
  	}
  	else{
  		cout<<"ERROR: invalid command. Type 'help' for command summary"<<endl; //not sure whether to print all the command summary or just this
  	}
  	cout<<"cmd> ";
  }
  

  return 0;
}