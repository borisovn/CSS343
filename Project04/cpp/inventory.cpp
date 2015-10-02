#include "inventory.h"
////--------------------------------------------------------------------------
//// Inventory()
//// Constractor
Inventory::Inventory() {
	errorCollector = "";
}

////--------------------------------------------------------------------------
//// ~Inventory()
/// Destructor
Inventory::~Inventory() {

}

////--------------------------------------------------------------------------
//// proccessTransaction()
//// void type function
//// invokes the Inventory manager to print the current
//// invetroy for all movies in the store
//// takes three parameters: sting line, CustomerMnager refrences cus_mang,
//// InventoryManager& inv_mang
void Inventory::proccessTransaction(string line, CustomerManager& cus_mang, InventoryManager& inv_mang) {
	inv_mang.displayAll();   // print all movies in the store
}

////--------------------------------------------------------------------------