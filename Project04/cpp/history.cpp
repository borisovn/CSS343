#include "histrory.h"
////--------------------------------------------------------------------------
//// History()
//// Constractor
History::History() {
	errorCollector = "";
}

////--------------------------------------------------------------------------
//// ~History()
//// Destructor
History::~History() {

}

////--------------------------------------------------------------------------
//// proccessTransaction()
//// void type method:
//// read the line. From the line gets customer ID
//// tries to retrive the customer, if customer exist - 
//// prints customer hsitory
//// takes three parameter: sting line, CustomerManager refrences cus_mang,
//// InventoryManager refrences inv_mang
void History::proccessTransaction(string line, CustomerManager& cus_mang, InventoryManager& inv_mang) {

	int customer_id;            // hold customer id
	Customer * customer = NULL; // hold pointer to the object customer

	stringstream ss;            // string reader
	ss << line;                 // insert string into reader

	ss >> customer_id;
	customer = cus_mang.getCustomer(customer_id);     // get pointer to the customer
	if (checkValidCustomer(customer, customer_id)) {  // check if customer exist
		customer->movieHistory();                     // print customer history
	}
}