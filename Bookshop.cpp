#include <iostream>
#include "Bookshop.h"
using namespace std;

Bookshop::Bookshop(string name, string address, int rating, int yearincome, int numberoftills) : Branch(name, address, rating) {
	this->yearincome = yearincome;
	this->numberoftills = numberoftills;
}

void Bookshop::write() {
	cout << "Book shop name: " << name << "\nBook shop address: " << address << "\nRating: " << ratestar() << "\nYear income: " << yearincome << "\nNumber of cash machines: " << numberoftills << endl;
}