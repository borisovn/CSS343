#pragma once
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "customermanager.h"
#include "inventorymanager.h"
using namespace std;
//--------------------------  class Transaction -----------------------------------
// ADT Transcation: Class Transaction. parent  class for child classes Borrow,
// Rerurn, Inventory, Hisory. Also, records erros and adds erros into string
//
// Implementation and assumptions:
//   -- Implement as a perant class
//   -- Implement with following futures:
//      proccessTransaction() getErorrs()
//---------------------------------------------------------------------------
class Transaction {	                                                                   
public:
	Transaction();              // constractor
	virtual ~Transaction() {};  // destructor
	virtual void proccessTransaction(string, CustomerManager&, InventoryManager&); // proccess command
	string getErrors();                                                            // return arrors massages
	static const char DVD = 'D';                                                   // shared by all transactions
protected:
	bool checkValidCustomer(Customer*, int);           // check if customer is valid
	string errorCollector;                             // string that hold all type of errors during reading the commands
	void addError(string);                             // add erros from all comands mistakes	
};