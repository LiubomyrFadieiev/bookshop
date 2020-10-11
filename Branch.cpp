#include <iostream>
#include "Branch.h"
using namespace std;

string Branch::ratestar() {
	string ratestar = "";
	for (int i = 0; i < rating; i++) {
		ratestar = ratestar + "*";
	}
	return ratestar;
}

Branch::Branch(string name, string address, int rating) {
	this->name = name;
	this->address = address;
	this->rating = rating;
}

int Branch::getrating() {
	return this->rating;
}

string Branch::getname() {
	return this->name;
}

void Branch::setrating(int r) {
	this->rating = r;
}

void Branch::write() {
	cout << "Branch name: " << name << "\nBranch address: " << address << "\nBranch rating: " << ratestar() << "\n\n";
}