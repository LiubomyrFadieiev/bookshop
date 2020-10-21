#include "BranchRepository.h"
#include "Branch.h"
#include "Bookshop.h"
#include "Library.h"
#include <iostream>
#include <fstream>
using namespace std;

int ratingcheck() {
	int r;
	while (true) {
		cout << "Enter rating: ";
		cin >> r;
		if (r < 0 || r>5) {
			cout << "Rating number is not correct.\n";
		}
		else {
			break;
		}
	}
	return r;
}

BranchRepository::BranchRepository() {
	this->array = new Branch * [maxlen];
}

void BranchRepository::Readfromfile() {
	if (!sync)
	{
		lastindex = -1;
		ifstream file("branch.txt");
		int maxlen = 100;
		char* name = new char[maxlen],
			* address = new char[maxlen],
			* rating = new char[maxlen],
			* num1 = new char[maxlen],
			* num2 = new char[maxlen],
			* counter = new char[maxlen];
		char delim = ',';
		if (!file) {
			cout << "This file doesn't exist.";
		}
		else {
			while (!file.eof()) {
				file.getline(counter, maxlen, delim);
				file.getline(name, maxlen, delim);
				file.getline(address, maxlen, delim);
				file.getline(rating, maxlen, delim);
				file.getline(num1, maxlen, delim);
				file.getline(num2, maxlen);
				if (atoi(counter) == 0) {
					array[++lastindex] = new Library(name, address, atoi(rating), atoi(num1), atoi(num2));
				}
				else if (atoi(counter) == 1) {
					array[++lastindex] = new Bookshop(name, address, atoi(rating), atoi(num1), atoi(num2));
				}
			}
		}
		file.close();
		sync = true;
		delete[]name;
		delete[]address;
		delete[]rating;
		delete[]counter;
		delete[]num1;
		delete[]num2;
		sync = true;
	}
}

void BranchRepository::branchwrite() {
	for (int i = 0; i <= lastindex; i++) {
		array[i]->write();
		cout << endl;
	}
}

void BranchRepository::addlibrary() {
	ofstream file("branch.txt", ios::app);
	string name, address, fake; int rating, books, readers;
	if (!file) {
		cout << "The file does not found.";
	}
	else {
		getline(cin, fake); system("cls");
		cout << "Please enter the information about library.\n";
		cout << "Name: "; getline(cin, name);
		cout << "Address: "; getline(cin, address);
		rating = ratingcheck();
		cout << "Number of books: "; cin >> books;
		cout << "Number of readers: "; cin >> readers;
		file << '\n';
		file << "0," << name << ',' << address << ',' << rating << ',' << readers << ',' << books;
		cout << "The library has been added.\n"; system("pause");
	}
	file.close();
	sync = false;
}

void BranchRepository::addbookshop() {
	ofstream file("branch.txt", ios::app);
	string name, address, fake; int rating, income, till;
	if (!file) {
		cout << "The file does not found.";
	}
	else {
		getline(cin, fake); system("cls");
		cout << "Please enter the information about bookshop.\n";
		cout << "Name: "; getline(cin, name);
		cout << "Address: "; getline(cin, address);
		rating = ratingcheck();
		cout << "Year income: "; cin >> income;
		cout << "Number of cash mashines: "; cin >> till;
		file << '\n';
		file << "1," << name << ',' << address << ',' << rating << ',' << income << ',' << till;
		cout << "The bookshop has been added.\n"; system("pause");
	}
	file.close();
	sync = false;
}

void BranchRepository::setrating() {
	system("cls");
	this->branchwrite();
	cout << "Choose a bookshop.\n";
	string username, shopname, fake; int newr; bool found = false;
	getline(cin, fake);
	getline(cin, username);
	cout << "You choose " << username << ".\nPlease enter your new rating.\n";
	newr = ratingcheck();
	for (int i = 0; i <= lastindex; i++) {
		if (array[i]->getname() == username) {
			array[i]->setrating(newr);
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "We are not able to find this shop. Please try again.\n";
	}
	system("pause");
}

BranchRepository::~BranchRepository() {
	for (int i = 0; i < lastindex; i++) {
		delete array[i];
	}
	delete[]array;
}