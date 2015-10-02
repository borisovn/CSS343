#pragma once 
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "movie.h"
#include "BSTree.h"
#include "moviefactory.h"
//--------------------------  class InventoryManager ------------------------
// ADT InventoryManager: Read given file then sort and insert
//    movies to a spacific BSTrees (Drama,Classiscs, Comedy). 
//    Also, displays all BTrees and keep track of invalid movies. 
//
// Implementation and assumptions:
//   -- Implement as manager class
//   -- Implement with using factory pattern:
//      MovieFactory class.
//   -- Implement with following futures:
//      proccessInvetory(), retriveMovie(), displayAll()
//---------------------------------------------------------------------------

class InventoryManager {
public:
	void processInventory(ifstream &);                 // proccess invetory
	Movie * retriveMovie(Movie*, char);                // retrive movie from BSTtree
	void displayAll();
private:
	void addError(string);                             // add erros from all invalid movie
	void displayErrors() const;                        // displays all invalid movies that has been detected
	
	int count;                                         // count error massages
	string errorCollector;                             // error collector
	BinTree dramaBST;                                  // BStrees for drama movies
	BinTree classicsBST;                               // BStrees for classics movies
	BinTree comedyBST;                                 // BStrees for comedy movies
};