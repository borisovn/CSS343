#include "movie.h"
////--------------------------------------------------------------------------
//// Movie()
//// constractor
Movie::Movie() {
	type = ' ';
	stock = 0;
	director ="";
	title = "";
	year = 0;
}

////--------------------------------------------------------------------------
//// loadString()
//// void type method:
//// helper method for constractor. 
//// Pasre the string into a smaller pieces. From these pieces
//// assign inforamtion to a current movie
//// takes one parameter: const stirng refrenseces info.
void Movie::loadString( const string& info) {
	stringstream ss;                 // string reader
	ss << info;                      // insert string info into reader
	string temp;                     //  temp string to parse the string
	getline(ss, temp, ',');          // get movie type
	type = temp[0];                  // assign movie type
	getline(ss, temp, ',');          // get stock
	stringstream ( temp ) >> stock;  // assign stock
	getline(ss, director, ',');      // assign director
	getline(ss, title, ',');         // assign title
	getline(ss, temp, ',');          // get year
	stringstream(temp) >> year;      // assign year
}

////--------------------------------------------------------------------------
//// increaseStock()
//// bool type method:
//// increase stock of current movie
//// takes one parameter: int addStock
bool Movie::increaseStock(int addToStock) {
	if (addToStock < 0) { return false; }
      stock += addToStock;
	  return true;
}

////--------------------------------------------------------------------------
//// getStock()
//// int type method:
//// returns current stock of the movie
int Movie::getStock() {
	return stock;
}

////--------------------------------------------------------------------------
//// dicreaseStock()
//// bool type method:
//// dicrease current stock of the movie
//// if stock is less or equal zero, stock will be the same
bool Movie::dicreaseStock() {
	if (stock <= 0) { return false; }
	stock--;    // dicrease sctock
	return true;
}
////--------------------------------------------------------------------------