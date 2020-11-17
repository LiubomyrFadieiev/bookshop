#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include "Poetry.h"
#include "Library.h"
#include "Bookshop.h"

template <class T>
class Repository {
protected:
	static bool ratingcheck;
	static const int maxlen = 20;
	int lastindex;
	bool sync;
	T** array;
public:
	Repository() {
		this->lastindex = -1;
		this->sync = false;
		this->array = new T * [maxlen];
	};
	~Repository() {
		for (int i = 0; i < lastindex; i++) {
			delete array[i];
		}
		delete[]array;
	};
	void Readbookfromfile() {
		if (!sync)
		{
			lastindex = -1;
			ifstream file(array[0]->filespace());
			int maxlen = 100; char delim = ',';
			char* title = new char[maxlen],
				* author = new char[maxlen],
				* pagesize = new char[maxlen],
				* price = new char[maxlen],
				* numberofpoems = new char[maxlen],
				* counter = new char[maxlen];
			if (!file) {
				cout << "The file does not found.\n";
			}
			else {
				while (!file.eof()) {
					file.get(counter, maxlen, delim);
					file.get();
					file.get(title, maxlen, delim);
					file.get();
					file.get(author, maxlen, delim);
					file.get();
					file.get(pagesize, maxlen, delim);
					file.get();
					file.getline(price, maxlen, delim);
					file.getline(numberofpoems, maxlen);
					if (atoi(counter) == 0) {
						this->array[++lastindex] = new Book(title, author, atoi(pagesize), atoi(price));
					}
					else if (atoi(counter) == 1) {
						this->array[++lastindex] = new Poetry(title, author, atoi(pagesize), atoi(price), atoi(numberofpoems));
					}
				}
			}
			file.close();
			sync = true;
			delete[]title;
			delete[]author;
			delete[]pagesize;
			delete[]price;
			delete[]numberofpoems;
			delete[]counter;
		}
	};
	void Readbranchfromfile() {
		if (!sync)
		{
			lastindex = -1;
			ifstream file(array[0]->filespace());
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
	;
	void Writetofile();
	void setrating() {
		system("cls");
		this->write();
		cout << "Choose a bookshop.\n";
		string username, shopname, fake; int newr; bool found = false;
		getline(cin, fake);
		getline(cin, username);
		cout << "You choose " << username << ".\nPlease enter your new rating.\n";
		while (true) {
			cout << "Enter rating: ";
			cin >> newr;
			if (newr < 0 || newr>5) {
				cout << "Rating number is not correct.\n";
			}
			else {
				break;
			}
		}
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
	};

	void write() {
		for (int i = 0; i <= lastindex; i++) {
			array[i]->write();
			cout << endl;
		}
	};
	void create() {
		int option; bool isBranch = false;
		cout << "Do you want to add:\n";
		if (array[0]->id == 0) { cout << "0.Book\n1.Poetry\n"; }
		else { cout << "0.Library\n1.Bookshop\n"; isBranch = true; }
		cin >> option;
		if (isBranch) { option += 2; }
		string format[] = { "title,author,number of pages,price", "title,author,number of pages,number of,price,numberofpoems", "name,address,rating,number of readers,number of books", "name,address,rating,year income,number of tills" };
		char* write = new char[150]; char* part = new char[100]; char* safe = new char[150];
		while (true) {
			cout << "\nPlease enter the information like in example:\n" << format[option] << endl << endl;
			if (isBranch) { cout << "Remember: rating can not be higher than 5 and lower than 0!\n\n"; }
			cin >> write; 
			strcpy(safe, write);
			if (isBranch) {
				part = strtok(write, ",");
				part = strtok(NULL, ",");
				part = strtok(NULL, ",");
				if (atoi(part) > 5 || atoi(part) < 0) {
					cout << "\tThe rating is not correct. Try again.\n\n";
				}
				else { break; }
			}
			else { break; }
		}
		ofstream file(array[0]->filespace(), ios::app);
		if (isBranch) { file << '\n' << option - 2 << ','; }
		else { file << '\n' << option << ','; }
		file << safe;
		if (option == 0) {
			file << ',' << 0;
		}
		if (!isBranch) { cout << "The book has been added.\n"; system("pause"); }
		else { cout << "The branch has been added.\n"; system("pause"); }
		file.close();
		this->sync = false;
	};
};