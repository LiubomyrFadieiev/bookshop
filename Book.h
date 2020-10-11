#pragma once
#include <string>
using namespace std;

class Book {
protected:
	string title;
	string author;
	int pagesize;
	int price;
public:
	Book(string title = "", string author = "", int pagesize = 0, int price = 0);
	virtual void write();
};
