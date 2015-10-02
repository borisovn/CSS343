#include "customermanager.h"

////--------------------------------------------------------------------------
//// CustomerManager()
//// Constractor
CustomerManager::CustomerManager() {

}

////--------------------------------------------------------------------------
//// ~CustomerManager()
//// desctuctor
CustomerManager::~CustomerManager() {

}

////--------------------------------------------------------------------------
//// proccessCustomer()
//// void type method:
//// Read the file and parse into a customer information
//// then, based on the inforamtion insert customer into HashTable.
//// takes one parameter: ifstream refrences file
void CustomerManager::proccessCustomer(ifstream& file) {

	// loop to read the file
	for (;;) {
		
		int id;                                              // hold id                     
		string last;                                         // hold last name
		string first;                                        // hold first name
		string temp;                                         // hold space

		getline(file, temp, ' ');                            // get id 
		stringstream(temp) >> id;                            // convert id to int 
		getline(file, last, ' ');                            // get last name
		getline(file, first);                                // get first name
		
		if (file.eof()) break;                               // no more lines of data
		
		Customer *  ptr = new Customer (id, last, first);    // allocate new customer 
		bool success = table.putCustomer(id, ptr);           // insert customer into HashTable
		 if (!success)
			 delete ptr;                                     // invalid case, not inserted 
	}
}

////--------------------------------------------------------------------------
//// getCustomer()
//// Pointer to Customer return mehtod:
//// return refrences to a pointer of the object customer, retriveing 
//// customer from hashtable
//// takes one parameter: int id
Customer*  CustomerManager::getCustomer(int id) {
	Customer *  customer = NULL;                   // poitner to a customer
	customer = table.getCustomer(id);              // rertive customer from hashtable
	return customer;                                // return customer
}

////--------------------------------------------------------------------------

