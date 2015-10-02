//file poly.cpp
//Member function definitions for class Poly
#include "poly.h"
#include <iostream>

// --------------------------------------------------------------------------
//empty default constructor
//difines size of polyArray
Poly::Poly(){
	value = 0;
	power = 0;
	firstCall();
}

// --------------------------------------------------------------------------
//one parameter default constructor
//difines size of polyArray
Poly::Poly(int input00){
	value = input00;
	power = 0;
	firstCall();
}

// --------------------------------------------------------------------------
//two parameters default constructor
//difines size of polyArray
Poly::Poly(int input00, int input01){
	value = input00;
	power = input01;
	firstCall();
}

// --------------------------------------------------------------------------
//copy constractor:
//copy array from passed object parameter
Poly::Poly(const Poly &obj){

	//reassing power
	power = obj.power;
	//assing new size for array
	polyArray = new int[power + 1];

	//loop to copy array
	for (int i = 0; i <= power; ++i){
		polyArray[i] = obj.polyArray[i];
	}

}

// --------------------------------------------------------------------------
//destractor
//destactor for class Poly
Poly::~Poly(){
	//delete array
	delete[]polyArray;
}

// --------------------------------------------------------------------------
//firstcall: creates new array of given power
//checks for valid input. Ex:  value = 0 to any power of n
//will create array size of 0
void Poly::firstCall(){


	//checking for valid input
	if (power <= -1) {
		value = 0;
		power = 0;
	}
	//allocates new array
	polyArray = new int[power + 1]();
	//assing value to appropriate index of array
	polyArray[power] = value;

}

// --------------------------------------------------------------------------
//inser method
//allocated new dynamic array
//by passing value and power
//assumption that size will not be nagative
//and value will not be zero
bool Poly::setCoeff(int num, int size) {


	//check valid size
	//if true return false
	if (size < 0) { return false; }

	//if  new size is bigger than older size
	//copy current values from array	
	//up to smaller size
	if (size >= power) {

		//alocate newarray to copy current data
		int *newArray = new int[size + 1]();

		//copying
		for (int a = 0; a < power + 1; ++a){
			newArray[a] = polyArray[a];
		}

		//assing new power
		power = size;
		//re-assing arrays
		delete[]  polyArray;
		polyArray = newArray;
		//assing value to appropriate index of array
		polyArray[power] = num;
		return true;
	}
	//if size < power
	//assing value to appropriate index of array
	else {
		polyArray[size] = num;
		return true;
	}

}

// --------------------------------------------------------------------------
//method getCoeff
//return coefficient of provided power
//return zero if invalid coeff was passed
int Poly::getCoeff(int pwr){

	//check if given pwr is more than actual power
	//or if given pwr is less than 0
	if (pwr < 0) { return 0; }
	//else return value at provided index
	return polyArray[pwr];
}

// --------------------------------------------------------------------------
//cout operator: prints the polyArray's content
ostream& operator<<(ostream &output, const Poly &obj){


	//loop that goes from end to beggining of the array
	//prints values to its power
	//don't print values of 0 of any power except x^0
	bool zero = true;
	for (int i = obj.power; i >= 0; --i){

		//allocating int that holds
		//current value at index i
		int check = obj.polyArray[i];

		//check up to power of 1 (x^n)
		if (check != 0 && (i > 1)){
			zero = false;
			if (check > 0)
				output << " +" << obj.polyArray[i] << "x^" << i;
			else
				output << ' ' << obj.polyArray[i] << "x^" << i;
		}
		//check power of 1 (x^1)
		else if (check != 0 && (i == 1)){
			zero = false;
			if (check > 0)
				output << " +" << check << "x";
			else
				output << ' ' << check << "x";
		}
		//check power of 0 (x^0)
		else if (i == 0 && (check != 0)) {
			zero = false;
			if (check > 0)
				output << " +" << check;
			else
				output << ' ' << check;

		}
		//check at 0x^0 when rest of the array is empty
		else if (i == 0 && (zero)){ output << ' ' << check; }
	}
	return output;
}

// --------------------------------------------------------------------------
//overloard operator>>
//insert client data
istream& operator>>(istream& input, Poly& obj){

	//holding values
	int inval = 0, inpow = 0;
	bool check = true;

	//loop that insert values and powers
	while (check){

		input >> inval;
		input >> inpow;
		//stop the loop if -1 and -1 was entered
		if ((inval == -1) && (inpow == -1)) { check = false; }
		else { obj.setCoeff(inval, inpow); }
	}
	return input;
}

// --------------------------------------------------------------------------
//operator=
//overload operator =
//assignt given obj array to current obj array
Poly Poly::operator=(const  Poly &obj)  {

	//check if obj is a current obj
	if (*this == obj) { return *this; }

	//empty out current array
	delete[] polyArray;
	//assing new size 
	power = obj.power;
	polyArray = new int[power + 1]();

	//copy array
	for (int i = 0; i <= power; ++i){
		polyArray[i] = obj.polyArray[i];
	}

	return *this;
}

// --------------------------------------------------------------------------
//bool operator ==
//check if two arrays are identical
//the method checks by compere powers first
//if powers > or < obj power, return false
//if bigger power contains zero, don't  count it
bool Poly::operator==(const Poly &obj) const {

	//check if power > obj.power
	if (power > obj.power) {
		//check up to smaller array
		for (int i = 0; i <= obj.power; ++i){
			if (polyArray[i] != obj.polyArray[i]){ return false; }
		}
		//check rest of array if contains valid value
		for (int i = obj.power + 1; i <= power; ++i){
			if (polyArray[i] != 0) { return false; }
		}

	}
	//check if obj.power is more than power
	else if (power < obj.power) {
		//check up to smaller array
		for (int i = 0; i <= power; ++i){
			if (polyArray[i] != obj.polyArray[i]){ return false; }
		}
		//check rest of array if contains valid value
		for (int i = power + 1; i <= obj.power; ++i){
			if (obj.polyArray[i] != 0) { return false; }
		}

	}
	//check if two powers are identical
	else if (power == obj.power) {
		for (int i = 0; i <= power; ++i) {
			if (polyArray[i] != obj.polyArray[i]) { return false; }
		}
	}

	//nothing has been found
	return true;
}

// --------------------------------------------------------------------------
// bool operator !=
// reverse of ==
bool Poly::operator!=(const Poly &obj) const {

	return !(*this == obj);
}

// --------------------------------------------------------------------------
//operator +
//adds two arrays each other
//First, find the biggest array and alloates new array of the biggest size
//Second, add  two array up to smallest size array to a new array
//Third, copy biggest size of array to a new array
//Fourth, try to shrink the new arrat if it is nessasery
Poly Poly::operator+(const Poly& obj) const {

	//return obj
	Poly filIn;

	//check if current obj is bigger than passed obj
	if (power >= obj.power) {


		//calling helper inArray method that allocates
		//empty new array with biggest size
		filIn.inArray(power);


		//fill out new array to minimum size
		for (int i = 0; i <= obj.power; ++i) {
			filIn.polyArray[i] = polyArray[i] + obj.polyArray[i];
		}

		//fill out array to max size
		for (int i = obj.power + 1; i <= power; ++i){
			filIn.polyArray[i] = polyArray[i];
		}

	}

	//check if passed obj is bigger
	//than current obj
	else if (obj.power > power) {

		//calling helper inArray method that allocates
		//empty new array with biggest size
		filIn.inArray(obj.power);

		//fil out array minimum size
		for (int i = 0; i <= power; ++i) {
			filIn.polyArray[i] = polyArray[i] + obj.polyArray[i];
		}

		//fill out array to max size
		for (int i = power + 1; i <= obj.power; ++i){
			filIn.polyArray[i] = obj.polyArray[i];
		}

	}

	//try to shrink array size if nessasery
	filIn.toShrink();

	return filIn;
}

// --------------------------------------------------------------------------
//operator*
//multiplication of two arrays
//First, finds new size of array by multiplying two powers
//Second, allocates new array size
//Third, nested for loop fill up the new array
Poly Poly::operator*(const Poly& obj) const {

	//return object
	Poly filIn;
	//find new size
	int maxSize = power + obj.power;
	//calling helper inArray method that allocates
	//empty new array with biggest size
	filIn.inArray(maxSize);

	//nested for loop to fill multiplacation array
	for (int i = 0; i <= power; ++i) {

		for (int n = 0; n <= obj.power; ++n) {
			filIn.polyArray[i + n] += polyArray[i] * obj.polyArray[n];
		}
	}

	//try to shrink array size if nessasery
	filIn.toShrink();

	return filIn;
}

// --------------------------------------------------------------------------
//operator-
//find the diference beetween two 
//First, find the biggest array and alloates new array of the biggest size
//Second, substrack two array up to smallest size array to a new array
//Third, copy biggest size of array to a new array 
//Fourth, try to shrink the new arrat if it is nessasery
Poly Poly::operator-(const Poly &obj) const {

	//return obj
	Poly filIn;

	//check if passed current obj is bigger
	//than pased obj
	if (power >= obj.power) {

		//calling helper inArray method that allocates
		//empty new array with biggest size
		filIn.inArray(power);

		//fill out array to minimum size
		for (int i = 0; i <= obj.power; ++i) {
			filIn.polyArray[i] = polyArray[i] - obj.polyArray[i];
		}

		//fill out array to max size
		for (int i = obj.power + 1; i <= power; ++i){
			filIn.polyArray[i] = polyArray[i];
		}

	}
	//check if passed obj is bigger
	//than current obj
	else if (obj.power > power) {

		//calling helper inArray method that allocates
		//empty new array with biggest size
		filIn.inArray(obj.power);


		//fil out array minimum size
		for (int i = 0; i <= power; ++i) {
			filIn.polyArray[i] = polyArray[i] - obj.polyArray[i];
		}

		//fill out array to max size wiht oposite sign
		for (int i = power + 1; i <= obj.power; ++i){
			filIn.polyArray[i] = -obj.polyArray[i];
		}

	}

	//try to shrink array size if nessasery
	filIn.toShrink();

	return filIn;
}

// --------------------------------------------------------------------------
//overload operator- 
//takes parameter as int assuming that is value of power of 0
Poly Poly::operator-(int val) const {

	Poly copyObj(*this);
	//set passed val in power of  0
	copyObj.polyArray[0] -= val;
	return copyObj;
}

// --------------------------------------------------------------------------
//overload operator+ 
//takes parameter as int assuming that is value of power of 0
Poly Poly::operator+(int val) const {

	//return obj
	Poly copyObj(*this);
	//set passed val in power of 0
	copyObj.polyArray[0] += val;
	return copyObj;
}

// --------------------------------------------------------------------------
//overload operator* 
//takes parameter as int assuming that is value of power of 0
//tries to shrink the array if nassesary
Poly Poly::operator*(int val) const {

	//return obj
	Poly copyObj(*this);
	//multiply all values by val power of 0
	for (int i = 0; i <= power; ++i){

		copyObj.polyArray[i] *= val;
	}

	return copyObj;
}

// --------------------------------------------------------------------------
//operator+=
//operator returns  assign sum of two Poly
Poly Poly::operator+=(const Poly &obj)  {

	//return obj
	*this = *this + obj;
	return *this;
}

// --------------------------------------------------------------------------
//operator-=
//operator returns  assign diffirence of two Poly
Poly Poly::operator-=(const Poly &obj)  {

	//return obj
	*this = *this - obj;
	return *this;
}

// --------------------------------------------------------------------------
//operator+=
//operator returns  assign multiplication of two Poly
Poly Poly::operator*=(const Poly &obj)  {

	//return obj
	*this = *this * obj;
	return *this;
}

// --------------------------------------------------------------------------
//private method reSize
//helps shrink array if the highier powers contains zero values
//checks if  at biggest power the value is not zero
//finds the index were power contains valid value ( != 0)
//creates new array that copy old array up to valid power
void Poly::toShrink() {

	//check if the shrink is nessasry
	if (polyArray[power] != 0) { return; }

	//shrink size of polyarray
	else {

		//ints that hold current power
		//and how much has to be shrink
		int count = 0;
		int tmpPower = power;

		//loop that finds the  nessary shrink lenght
		for (int i = power; i > 0; --i){
			if (polyArray[i] == 0) ++count;
			else  i = 0;
		}

		//allocate tempArray that will hold polyArray values
		//up to shrinked lenght 
		int tempPower = power - count;
		int * tempArray = new int[tempPower + 1]();
		for (int i = 0; i <= tempPower; ++i) {
			tempArray[i] = polyArray[i];
		}

		//allocate new power for polyArray
		//and copy values from tempArray
		power = tempPower;
		delete[] polyArray;
		polyArray = tempArray;
	}

}

// --------------------------------------------------------------------------
//inArray method
//private method that extand array size for algebretic manipulation
///faster than setCoef: no need in looping and copying elements
//because creates an empty array
//for + - * operator
void Poly::inArray(int size) {

	//delete old array
	delete[] polyArray;
	//allocated new  array size;
	polyArray = new int[size + 1]();
	power = size;
}
// --------------------------------------------------------------------------