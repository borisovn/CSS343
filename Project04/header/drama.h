#pragma once
#include <string>
#include "movie.h"
#include <iostream>
#include <fstream>
using namespace std;
//--------------------------  class Drama --------------------------------
// ADT Drama: child class of Movie. Dramma Movie sorts
// by director and title.
//
// Implementation and assumptions:
//   -- Implement as a child class of Movie
//   -- Implement with following futures:
//      printInfo(), printInfoForCustomer(), isEqual(), isGreater()
//---------------------------------------------------------------------------
class Drama : public Movie {
public:

	Drama(const string&);                          // copy constractor
	Drama(const string&, const string&);           // copy constractor
	virtual ~Drama();                              // destructor

	static const char MyType = 'D';                // static indentifier for a class 
	
	virtual string printInfo() const;              // return string of full movie  info
	virtual string printInfoForCustomer() const;   // return string ifno for customer
protected:

	virtual bool isEqual(const Movie* rhs) const;  // operator=
	virtual bool isGreater(const Movie* rhs) const;// operator=>

};