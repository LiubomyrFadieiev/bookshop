#include <iostream>
#include "Poetry.h"

Poetry::Poetry(string title, string author, int pagesize, int price, int numberofpoems) : Book(title, author, pagesize, price) {
	this->numberofpoems = numberofpoems;
}

void Poetry::write() {
	cout << "Title: " << title << "\nAuthor: " << author << "\nNumber of pages: " << pagesize << "\nNumber of poems: " << numberofpoems << "\nPrice: " << price << "$\n\n";
}