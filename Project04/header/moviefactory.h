#pragma once
#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classics.h"
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
using namespace std;
//--------------------------  class MovieFactory ----------------------------
// ADT MovieFactory: MovieFactory class uses factory method pattern to create
//        new moive form input string
//
// Implementation and assumptions:
//   -- Implement as factory method
//   -- Implement with following futures:
//      static poitner to the Movie createMovie()
//---------------------------------------------------------------------------
class MovieFactory {	
public:
	static Movie* createMovie(const string&); // create pointer to the object Movie
};