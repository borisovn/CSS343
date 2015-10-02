#include "transaction.h"

////--------------------------------------------------------------------------
//// constractor
Transaction::Transaction() {
	errorCollector = "";
}
////--------------------------------------------------------------------------
//// proccessTransaction()
//// void type  method:
/// does nothig (exist for inheretance purpose) 
void Transaction::proccessTransaction(string a, CustomerManager& b, InventoryManager& c)  {
	// do nothig
}
////--------------------------------------------------------------------------
//// checkValidCustomer()
//// bool type method:
//// check  if customer was found or not
//// check the pointer points somewhere
//// takes two parameters: Pointer to Customer customer, int id
bool Transaction::checkValidCustomer(Customer * customer, int id)  {
	if (customer == NULL) {
		ostringstream stringStream;
		stringStream << id;
		addError("Invalid  Customer ID: " + stringStream.str()); // add invalid customer id
		return false;
	}
	return true;
}

////-------------------------------------------------------------------------
//// addErrors()
//// void type method:
//// collect all errors that appears during the command reading 
void Transaction::addError(string error) {
	errorCollector += "* ";
	errorCollector += error;
	errorCollector += "\n";
}

////-------------------------------------------------------------------------
//// getErros()
//// string type method:
//// return the string of all erros that has been detected during file reading
string Transaction::getErrors() {
	return errorCollector;
}

////--------------------------------------------------------------------------