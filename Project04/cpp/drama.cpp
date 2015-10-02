#include "drama.h"
#include <sstream>
////--------------------------------------------------------------------------
//// Drama()
//// Constractor
Drama::Drama(const string& str) {
	loadString(str);
}

////--------------------------------------------------------------------------
//// Drama()
//// Copy constractor
Drama::Drama(const string& new_title, const string& new_director) {
	title = new_title;
	director = new_director;
}

////--------------------------------------------------------------------------
//// ~Drama()
//// Destructor
Drama::~Drama() {

}

////-------------------------------------------------------------------------
//// isEqual()
//// bool type method:
//// compare current object Movie with other object Movie
//// takes one parameter: const pointer to the object Movie
bool Drama::isEqual (const Movie* rhs) const {
	const Drama* ptr_drama = (const Drama*)rhs;
	return ((title == ptr_drama->title) && (director == ptr_drama->director));
}

////-------------------------------------------------------------------------
//// isGreater()
//// bool type method:
//// compare current object Movie with other object Movie
//// takes one parameter: const pointer to the object Movie
bool Drama::isGreater(const Movie* rhs) const {
	const Drama* ptr_drama = (const Drama*)rhs;
	return ((director > ptr_drama->director) || ((director == ptr_drama->director) && (title > ptr_drama->title)));
}

////--------------------------------------------------------------------------
//// printInfo()
//// string type method:
//// compose all inforamtion about the Movie into a string
string Drama::printInfo() const {
	ostringstream stringStream;
	stringStream << setw(21) << left << director << setw(21) << left << title;
	stringStream << setw(9) << right << year << setw(8) << right << stock << endl;
	return stringStream.str();
}

////--------------------------------------------------------------------------
//// printInfoForCustomer()
//// string type method:
//// compose inforamtion about movie with spaccific 
//// format for a customer history.
string Drama::printInfoForCustomer() const {
	ostringstream stringStream;
	stringStream << " drama: "<< director << " " << title;
	stringStream << " " << year;;
	return stringStream.str();
}

////-------------------------------------------------------------------------