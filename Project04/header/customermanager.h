#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include  "hashtable.h"
#include "customer.h"
using namespace std;
//--------------------------  class CusomerManager  -------------------------
// ADT CustomerManager: CustomerManager proccess customers: puts customers 
//    into HashTble. CustomerManager can also retrieve the customer.
//
// Implementation and assumptions:
//   -- Implement as manager class
//   -- Implement with following futures: 
//      proccessCustomer(), getCustomer()
//---------------------------------------------------------------------------
class CustomerManager {
public:

	CustomerManager();                   // constractor
	~CustomerManager();                  // destructor
	void proccessCustomer(ifstream &);   // procees file with customers
	Customer* getCustomer(int id);       // return pointer to the Customer
private:

	HashTable table;                     // HashTable
};
