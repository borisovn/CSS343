#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "storemanager.h"
////--------------------------------------------------------------------------
//// buildStore()
//// void type method:
//// invokes inventory and customer manager to build data base
//// for movie and customters
//// takes two parameters: ifstream refrences movie_DB,
//// ifstream refrences customer_DB.
void StoreManager::buildStore(ifstream& movie_DB, ifstream& customer_DB) {
	inventory_object.processInventory(movie_DB);
	customer_object.proccessCustomer(customer_DB);
}

////--------------------------------------------------------------------------
//// commnadsReader()
//// void type method:
//// invokes ComandLoader  (command_object) to read commamands
//// takes one paramter: ifstream refrences commands
void StoreManager::commandsReader(ifstream& commands) {
	command_object.commandsReader(commands,customer_object,inventory_object);
}

////--------------------------------------------------------------------------