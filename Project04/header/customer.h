#pragma once
#include <string>
#include <iostream>
#include "movie.h"
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
//--------------------------  class Cusomer  --------------------------------
// ADT Customer: Customer class contains id, first, and last name. Also,
//    customer keeps track of his borrowed and returned movies.
//
// Implementation and assumptions:
//   -- Implement with  two linked lists and vector 
//   -- Implement with following futures: 
//      movieBorrow(), movieReturn() movieHistory(),
//      getMyID(), getCustomerInfo(), addTransaction()
//      returnMovie(), borrowMovie()
//---------------------------------------------------------------------------
class Customer {
public:
	
	Customer();                    // constractor
	Customer(int, string, string); // copy constrator
	~Customer();                   // destructor
	bool movieBorrow(Movie*);      // borrow movie
	bool movieReturn(Movie*);      // return movie
	
	void movieHistory();           // print customer borrow and return history
	int getMyID() const ;          // return customer ID
	string getCustomerInfo();      // return infomation about customer
private:

	bool addTransaction(const char, Movie*); // add transaction
	bool returnMovie(Movie*);      // private method to check if  return is valid
	bool borrowMovie(Movie*);      // private mehtod to borrow movie into transaction log

	int customer_ID;               // customer id
	string lastName;               // customer last name
	string FirstName;              // customer first name
	int plus_One;                  // integet for increasing movie stock
	
	// structure for customer history
	struct  List {
		List * next;        // next
		char transaction;   // transaction type (B or R)
		Movie * info;       // pointer to the movie
	};
	List * head;
	
	vector <string> print_array;    // vector for reverse history print
	
	// structure for borrow, return history
	struct TransactionLog{
		Movie * movie;         // pointer to the movie
		char transaction;      // transaction type (B or R)
		TransactionLog * next; // nexy
	};
	TransactionLog * logHead;
};
