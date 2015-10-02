#pragma once
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "histrory.h"
#include "inventory.h"
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
using namespace std;
//--------------------------  class TransactionFactory ----------------------
// ADT TransactionFactory: TransactionFactory class uses factory method
//   pattern to create new transaction 
//
// Implementation and assumptions:
//   -- Implement as factory method
//   -- Implement with following futures:
//      static poitner to the Transaction createTransaction()
//---------------------------------------------------------------------------

class Transactionactory {
public:
	static Transaction* creatTransaction(const char&);   // create pointer to the object Movie
};