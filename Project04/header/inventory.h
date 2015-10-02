#pragma once
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "customermanager.h"
#include "inventorymanager.h"
#include "transaction.h"
using namespace std;
//--------------------------  class Inventory -------------------------------
// ADT Inventory: child class of Transaction.  Displays  all
//    comedies, dramas, and classics movies of the store.
//
// Implementation and assumptions:
//   -- Implement as a child class of Transaction
//   -- Implement with following futures:
//      proccessTransaction()
//---------------------------------------------------------------------------

class Inventory : public Transaction {
public:
	Inventory();                     // constractor
	~Inventory();                    // destructor
	virtual void proccessTransaction(string, CustomerManager&, InventoryManager&);  // proccess tranaction
	static const char MyType = 'I';  // static indentifier for a class
};