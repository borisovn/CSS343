#pragma once
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "customermanager.h"
#include "inventorymanager.h"
#include "transaction.h"
using namespace std;
//--------------------------  class Borrow ----------------------------------
// ADT Borrow: child class of Transaction. Borrowed movie for customer
// and update the inventoryMager
//
// Implementation and assumptions:
//   -- Implement as a child class of Transaction
//   -- Implement with following futures:
//      proccessTransaction, borrowMovie, readTransaction
//---------------------------------------------------------------------------
class Borrow : public Transaction {
public:
	
	Borrow();                 // constractor
	~Borrow();                // destructor
	static const char MyType = 'B';                                                // static indentifier for a class
	virtual void proccessTransaction(string, CustomerManager&, InventoryManager&); // proccess Transaction
protected:

	void borrowMovie(Customer*, Movie*, Movie*);   // borrowed movie for customer 
	void readTransaction(string info, Customer* customer, InventoryManager& inv_mang); // helper method for proccesTranscation
};