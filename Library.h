#pragma once
#include <string>
#include "Branch.h"
using namespace std;

class Library : public Branch {
	int numberofreaders;
	int numberofbooks;
public:
	Library(string name = "", string address = "", int rating = 0, int numberofreaders = 0, int numberofbooks = 0);
	virtual void write();
};