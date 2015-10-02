#include "return.h"
////--------------------------------------------------------------------------
//// Return()
//// Constractor
Return::Return() {
	errorCollector = "";
}

////--------------------------------------------------------------------------
//// ~Return()
//// Destructor
Return::~Return() {

}

/////--------------------------------------------------------------------------
//// ProccessTransaction()
//// void type method:
//// process transaction: read the line, get id and check for valid customer id
//// if cusomer is valid, call helper fancation that  continue read the data
//// three parameters: string line, refrencese to a object cus_manager, 
//// references to a object inv_mang
void Return::proccessTransaction(string line, CustomerManager& cus_mang, InventoryManager& inv_mang) {

	string temp;                // hold info about line
	int customer_id;            // hold customer id
	Customer * customer = NULL; // hold pointer to the object customer

	stringstream ss;            // string reader
	ss << line;                 // insert string into reader

	ss >> customer_id;
	customer = cus_mang.getCustomer(customer_id);      // get pointer to the customer
	if (checkValidCustomer(customer, customer_id)) {   // check if customer exist
		getline(ss, temp);                             // get movie info
		readTransaction(temp, customer, inv_mang);     // procces transaction
	}
}

////--------------------------------------------------------------------------
//// readTrnasaction()
//// void type method:
//// helper fucntion for proccessTransaction. Contiue read the line. 
//// Parse  the line into small pices. Based on these pices, creates pointer 
//// to a movie and retives actual movie
//// if retrive is succefull, proccess proccessReturn()
//// three parameters: stirng info, pointer to Customer, 
//// refrenses to InventoryManager
void Return::readTransaction(string info, Customer* customer, InventoryManager& inv_mang){
	
	stringstream ss;                     // get reader 
	ss << info;                          // insert string into reader
	char movietype;                      // hold movie type
	char mediatype;                      // hold  media type
	string temp1;                        // hold movie info
	string temp2;                        // hold movie info
	string majorActor;                   // hold actor
	int _year = 0;                       // hold year
	int _month1 = 0;                     // hold month
	Movie * temp_movie = NULL;           // hold temporory pointer to the transaction movie
	Movie * customer_movie = NULL;       // hold  pointer on actual tree movie

	ss >> mediatype;                     // insert media tye                

	if (mediatype == DVD) {              // check if media type is valid
		ss >> movietype;                 // insert movie type
		switch (movietype)
		{
			// case Drama
		case 'D':
			getline(ss, temp2, ',');     // insert  director
			getline(ss, temp1, ',');     // insert title
			temp_movie = new Drama(temp1, temp2);  // allocate new object 
			customer_movie = inv_mang.retriveMovie(temp_movie, movietype);  // retrive actual pointer to movie
			proccessReturn(customer, customer_movie, temp_movie); // call helper method
			delete temp_movie;          // delete object
			temp_movie = NULL;          // NULL
			break;
			// case Comedy
		case 'F':
			getline(ss, temp2, ',');    // insert title
			getline(ss, temp1);         // hold year
			stringstream(temp1) >> _year;  // assign  year
			temp_movie = new Comedy(temp2, _year); // allocate new object 
			customer_movie = inv_mang.retriveMovie(temp_movie, movietype);  // retrive actual pointer to movie
			proccessReturn(customer, customer_movie, temp_movie); // call helper method
			delete temp_movie;          // delete object
			temp_movie = NULL;          // NULL
			break;
			// case Classics
		case 'C':
			getline(ss, temp1, ' ');     // hold space
			getline(ss, temp1, ' ');     // hold month
			stringstream(temp1) >> _month1; // assign month
			getline(ss, temp1, ' ');     // hold year
			stringstream(temp1) >> _year;   // assing year
			ss >> temp1;                 // get last name
			majorActor += temp1;
			majorActor += ' ';           // hold space between names
			ss >> temp1;                 // get first name
			majorActor += temp1;
			temp_movie = new Classics(majorActor, _month1, _year); // allocate new object
			customer_movie = inv_mang.retriveMovie(temp_movie, movietype); // retrive actual pointer to movie
			proccessReturn(customer, customer_movie, temp_movie); // call helper method
			delete temp_movie;         // delete object
			temp_movie = NULL;         // NULL
			break;
			// invalid movie type
		default:
			getline(ss, temp1);
			string a(1, movietype);
			addError("Invalid movie type: " + a + temp1); // add invalud movie type
			break;
		}
	}
	// not DVD 
	else {
		string a(1, mediatype);
		getline(ss, temp1);
		addError("Invalid  media type: " + a + temp1);	// add invalid media type
	}
}
////--------------------------------------------------------------------------
//// proccessReturn()
//// void  type method:
//// check if  cusomter can return movie of not.
//// Check if customre actualy borrow the movie. Also, add error massage 
//// if movie doesn't exist in inventory manager.
//// three parameters: pointer Customer, pointer Movie , pointer Movie.
void Return::proccessReturn(Customer* customer, Movie *customer_movie, Movie * temp_movie) {
	if (customer_movie != NULL) {   // check if retrive was succesufull
			bool sucees = customer->movieReturn(customer_movie);   // try to return
			if (!sucees) {
				addError(customer->getCustomerInfo() + "\n" + "Didn't borrow followed "  // add invalid return
					+ customer_movie->printInfoForCustomer());
			}
	}
	else {
		addError("Invalid retrive of " + temp_movie->printInfoForCustomer());                 // add invalid moive
	}
}

////-------------------------------------------------------------------------