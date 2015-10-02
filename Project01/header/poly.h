#ifndef POLY_H
#define POLY_H
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
// Poly class: the internal representation of a polynomial as an array of 
//  integeres. Each object of class Poly contains value of the power of n
//  (non negative exponets). Power repsents  as the index of an array,
//  and value as array at the index
//  also includes additional features:
//   -- allows input and output  values of  Polyarray
//   -- allows for comparison of 2 Poly, element by element
//   -- allows for assignment of  one Poly to the another
//   -- allows to add, multiply, substarction one Poly over another
//   -- allow to set values into polyArray
///
// Implementation and assumptions:
//   -- Client input valid data type (non-negative int) 
//   -- by invalid  input contractor sets value and power to 0
//   -- PolyArray size shrinks if hiest power contains value of 0
//---------------------------------------------------------------------------
class Poly {
	// friends
	friend ostream& operator<< (ostream&, const Poly&);
	friend istream& operator>> (istream&, Poly&);

public:

	// construtors
	Poly();                             //empty default constructor
	Poly(int);                          //one parameter default constructor
	Poly(int, int);                     //two parameters default constructor
	Poly(const Poly &);                 //copy constructor
	~Poly();                            //disctructor

	//bool operators
	bool setCoeff(int, int);            //insert value to the power of n
	bool operator==(const Poly&) const; //checks if objects are the same
	bool operator!=(const Poly&) const; //checks if objects aren't the same

	//int operator
	int getCoeff(int);                  //return value of given power

	// arithmetic operators with object parameter 
	Poly operator=(const  Poly&);       //assign one polyArrray to another
	Poly operator+(const Poly&) const;  //add  two polyArrays
	Poly operator-(const Poly&) const;  //subtrack one polyArray from another
	Poly operator*(const Poly&) const;  //multiply  two polyArrays  

	// arithmetic operators with int parameter
	Poly operator+(int) const;          //add value power to polyArray
	Poly operator-(int) const;          //subtrack value from polyArray
	Poly operator*(int) const;          //multiply value on polyArray

	//assign operators with object parameter
	Poly operator+=(const Poly&);       //object plus equal object
	Poly operator-=(const Poly&);       //object minus equal object
	Poly operator*=(const Poly&);       //object multiply equal object


private:
	//helper methods
	void firstCall();                   //initialised array for constructor
	void inArray(int);                  //initialised size array(- + *)oprt.
	void toShrink();                    //shrinked array to valid max power

	//int data
	int value;                          //holds value of power n               
	int power;                          //holds size of an array
	int *polyArray;                     //polynomial array

};

#endif