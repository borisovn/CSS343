#include "comedy.h"
////--------------------------------------------------------------------------
//// Comedy()
//// Constractor
Comedy::Comedy(const string& str) {
	loadString(str);
}

////--------------------------------------------------------------------------
//// Comedy()
//// Copy constractor
Comedy::Comedy(const string& new_title, const int& new_year) {
	title = new_title;
	year = new_year;
}

////--------------------------------------------------------------------------
//// ~Comedy()
//// Destructor
Comedy::~Comedy() {

}

////-------------------------------------------------------------------------
//// isEqual()
//// bool type method:
//// compare current object Movie with other object Movie
//// takes one parameter: const pointer to the object Movie
bool Comedy::isEqual(const Movie* rhs) const {
	const Comedy* ptr_comedy = (const Comedy*)rhs;
	return ((title == ptr_comedy->title) && (year == ptr_comedy->year));
}
////-------------------------------------------------------------------------
//// isGreater()
//// bool type method:
//// compare current object Movie with other object Movie
//// takes one parameter: const pointer to the object Movie
bool Comedy::isGreater(const Movie* rhs) const {
	const Comedy* ptr_comedy = (const Comedy*)rhs;
	return ((title > ptr_comedy->title) || ((title == ptr_comedy->title) && (year > ptr_comedy->year)));
}
////--------------------------------------------------------------------------
//// printInfo()
//// string type method:
//// compose all inforamtion about the Movie into a string
string Comedy::printInfo() const {
	ostringstream stringStream;
	stringStream  << setw(33) <<left << title << setw(1) << right << year 
		<< setw(20) << left << director << setw(20) << left << stock << endl;
	return stringStream.str();
}

////--------------------------------------------------------------------------
//// printInfoForCustomer()
//// string type method:
//// compose inforamtion about movie with spaccific 
//// format for a customer history.
string Comedy::printInfoForCustomer() const {
	ostringstream stringStream;
	stringStream << " comedy: "<< title << " " << director
		<< " " << year;;
	return stringStream.str();
}

////-------------------------------------------------------------------------