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
	static const int id = 0;
	static const bool ratingcheck = false;
	Book(string title = "", string author = "", int pagesize = 0, int price = 0);
	virtual void write();
	string filespace() { return "../data/book.txt"; }
	virtual int getid() { return id; }
};
