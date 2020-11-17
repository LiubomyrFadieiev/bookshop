#pragma once
#include <string>
#include "Book.h"
using namespace std;

class Poetry : public Book {
	static const int id = 1;
	int numberofpoems;
public:
	Poetry(string title = "", string author = "", int pagesize = 0, int price = 0, int numberofpoems = 0);
	virtual void write();
	int getid() { return id; }
};