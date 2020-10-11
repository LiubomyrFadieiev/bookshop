#include <iostream>
#include "Book.h"

Book::Book(string title, string author, int pagesize, int price) {
	this->title = title;
	this->author = author;
	this->pagesize = pagesize;
	this->price = price;
}

void Book::write() {
	cout << "Title: " << title << "\nAuthor: " << author << "\nNumber of pages: " << pagesize << "\nPrice: " << price << "$\n\n";
}