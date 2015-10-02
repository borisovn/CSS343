#include <iostream>
#include <fstream>
#include "storemanager.h"
using namespace std;
////-------------------------------------------------------------------------
//// main class. Checks for valid data files.
//// Invokes StoreManager to proccess data files.
int main() {
	ifstream infile1("data4movies.txt");
	if (!infile1) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	ifstream infile2("data4commands.txt");
	if (!infile2) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	ifstream infile3("data4customers.txt");
	if (!infile3) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	StoreManager store;                   // allocate store
	store.buildStore(infile1, infile3);   // proccess movies and customers
	store.commandsReader(infile2);        // proccess commanads
	return 0;
}