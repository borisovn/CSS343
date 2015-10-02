#pragma once
#include <string>
#include "movie.h"
using namespace std;
//--------------------------  class Comedy --------------------------------
// ADT Comedy: child class of Movie. Comedy Movie sorts by
// title and year
//
// Implementation and assumptions:
//   -- Implement as a child class of Movie
//   -- Implement with following futures:
//      printInfo(), printInfoForCustomer(), isEqual(), isGreater()
//---------------------------------------------------------------------------
class Comedy : public Movie {
public:

	Comedy(const string&, const int&);                // copy constractor
	Comedy(const string&);                            // copy constractor
	virtual ~Comedy();                                // destructor

	static const char MyType = 'F';                   // static indentifier for a class 
	
	virtual string printInfo() const;                 // return string of full movie  info    
	virtual string printInfoForCustomer() const;      // return string ifno for customer	
protected:

	virtual bool isEqual(const Movie* rhs) const;      // operator=
	virtual bool isGreater(const Movie* rhs) const;    // operator=>

};