#include "classics.h"
#include <sstream>
////--------------------------------------------------------------------------
//// Classics()
//// constractor
Classics::Classics(const string& str) {
	loadString(str);
}

////--------------------------------------------------------------------------
//// Classics()
//// copy constractor
Classics::Classics(const string& actor, const int& _month, const int& _year) {
	majorActor = actor;
	month = _month;
	year = _year;
}

////--------------------------------------------------------------------------
//// ~Classics()
//// Destructor
Classics::~Classics() {
}

////-------------------------------------------------------------------------
//// isEqual()
//// bool type method:
//// compare current object Movie with other object Movie
//// takes one parameter: const pointer to the object Movie
bool Classics::isEqual(const Movie* rhs) const {
	const Classics*  ptr_classic = (const Classics*)rhs;
	return ((majorActor == ptr_classic->majorActor) && (year == ptr_classic->year) && (month == ptr_classic->month));
}

////-------------------------------------------------------------------------
//// isGreater()
//// bool type method:
//// compare current object Movie with other object Movie
//// takes one parameter: const pointer to the object Movie
bool Classics::isGreater(const Movie* rhs) const {
	const Classics*  ptr_classic = (const Classics*)rhs;
	return ((year > ptr_classic->year) || ((year == ptr_classic->year) && (month > ptr_classic->month)) 
		|| ((year == ptr_classic->year) && (month == ptr_classic->month) && (majorActor > ptr_classic->majorActor)));
}

////--------------------------------------------------------------------------
//// loadString()
//// void type method:
//// helper method for constractor. 
//// Pasre the string into a smaller pieces. From these pieces
//// assign inforamtion to a current movie
//// takes one parameter: const stirng refrenseces info.
void Classics::loadString(const string& info) {
	stringstream ss;
	ss << info;                 
	string temp;                 // hold sub string from info string
	getline(ss, temp, ',');      // get type of movie (char)
	type = temp[0];
	getline(ss, temp, ',');      // get stock number (int)
	stringstream(temp) >> stock;
	getline(ss, director, ',');  // get director string
	getline(ss, title, ',');     // get title string
	ss >> temp;                  // add second name to first name
	majorActor += temp;
	majorActor += ' ';
	ss >> temp;                 // add second name to first name
	majorActor += temp;
	ss >> month;                // add month
	ss >> year;                 // add month
}

////--------------------------------------------------------------------------
//// printInfo()
//// string type method:
//// compose all inforamtion about the Movie into a string
string  Classics::printInfo() const {
	ostringstream stringStream;
	stringStream << " "  << setw(7) <<left  << month << setw(6) << left << year <<
		setw(18) << left << majorActor << setw(23) << left <<
		 title << setw(17) << left <<  director << setw(5) << left<< stock << endl;
	return  stringStream.str();
	
}

////--------------------------------------------------------------------------
//// printInfoForCustomer()
//// string type method:
//// compose inforamtion about movie with spaccific 
//// format for a customer history.
string Classics::printInfoForCustomer() const {
	ostringstream stringStream;
	stringStream << " classic: " << month << " " << year << ' ' << majorActor  << title <<  director;
	return  stringStream.str();
}

////-------------------------------------------------------------------------

