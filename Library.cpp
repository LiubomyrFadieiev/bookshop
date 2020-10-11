#include <iostream>
#include "Library.h"
using namespace std;

Library::Library(string name, string address, int rating, int numberofreaders, int numberofbooks) : Branch(name, address, rating) {
	this->numberofbooks = numberofbooks;
	this->numberofreaders = numberofreaders;
}

void Library::write() {
	cout << "Library name: " << name << "\nLibrary address: " << address << "\nRating: " << ratestar() << "\nNumber of books: " << numberofbooks << "\nNumber of registred readers: " << numberofreaders << endl;
}