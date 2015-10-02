#pragma once
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "customermanager.h"
#include "inventorymanager.h"
#include "transaction.h"
using namespace std;
//--------------------------  class History ---------------------------------
// ADT Histroy: child class of Transaction.  Displays histroy for a given
//    cusomter. In other words, displays all customer transactions.
//
// Implementation and assumptions:
//   -- Implement as a child class of Transaction
//   -- Implement with following futures:
//      proccessTransaction()
//---------------------------------------------------------------------------

class History : public Transaction {
public:
	History();                       // constractor
	~History();                      // destructor
	virtual void proccessTransaction(string, CustomerManager&, InventoryManager&); // proccess tranaction
	static const char MyType = 'H';  // static indentifier for a class
};