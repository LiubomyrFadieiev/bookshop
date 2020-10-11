#pragma once
#include <string>
#include "Branch.h"
using namespace std;

class Bookshop : public Branch {
	int yearincome;
	int numberoftills;
public:
	Bookshop(string name = "", string address = "", int rating = 0, int yearincome = 0, int numberoftills = 0);
	virtual void write();
};