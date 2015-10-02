#pragma once 
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "customer.h"
using namespace std;
// class hashtable
// chain model hashtable
// assumption: do not allowed duplicate customer (identical id)
// customer base up to 25 
//--------------------------  class HashTable  ------------------------------
// ADT HushTable: HashTable class: HashTable (chain model) data stucture
//      that holds customers. Proviedes easy access to a customer by (id)
//
// Implementation and assumptions:
//   -- Implement as  closed HashTable (chain model) by using linked list
//       at each index of the table
//   -- Implement with following futures: 
//      getCustomer(), putCustomers()
//   -- Assumption: HashTble assumed only 25 customer in the Table
//---------------------------------------------------------------------------
class HashTable {
	static const int SIZE = 50; // twice size of customer base
	static const int Hash = 52;          // number for hashing
public:
	HashTable();   // constractor
	~HashTable();  // descturctor
	Customer * getCustomer(int);       // return pointer  to the object customer
	bool putCustomer(int, Customer *); // insert customer into hashtable
private:
	void makeEmpty();  // helper method to distructor
	void buildTable(); // helper method for constractor
	
	struct HashList;   // structure for linkned list at hashtable index
	struct HashEntry   // hashtable  structure
	{
		HashList * head;
	};

	struct HashList   // linked list that attached to index of table
	{
		Customer * data;   //  hold customer
		int key;           // hold ID  (key)
		HashList * next;   // next
	};

	HashEntry table[SIZE];   // hastable array
};