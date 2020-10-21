#include "BookRepository.h"
#include "Book.h"
#include "Poetry.h"
#include <iostream>
#include <fstream>
using namespace std;

BookRepository::BookRepository() : Repository(){
	this->array = new Book * [maxlen];
}

void BookRepository::Readfromfile() {
	if (!sync) 
	{
		lastindex = -1;
		ifstream file("book.txt");
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
}

void BookRepository::bookwrite() {
	for (int i = 0; i <= lastindex; i++) {
		array[i]->write();
	}
}

void BookRepository::addbook() {
	ofstream file("book.txt", ios::app);
	string title, author, fake; int pagesize, price;
	if (!file) {
		cout << "The file does not found.";
	}
	else {
		getline(cin, fake);  system("cls");
		cout << "Please enter the information about book.\n";
		cout << "Title: "; getline(cin, title);
		cout << "Author: "; getline(cin, author);
		cout << "Number of pages: "; cin >> pagesize;
		cout << "Price: "; cin >> price;
		file << '\n';
		file << "0," << title << ',' << author << ',' << pagesize << ',' << price << ",0";
		cout << "The book has been added.\n"; system("pause");
	}
	file.close();
	sync = false;
}

void BookRepository::addpoetry() {
	ofstream file("book.txt", ios::app);
	string title, author, fake; int pagesize, price, numberofpoems;
	if (!file) {
		cout << "The file does not found.";
	}
	else {
		getline(cin, fake); system("cls");
		cout << "Please enter the information about book.\n";
		cout << "Title: "; getline(cin, title);
		cout << "Author: "; getline(cin, author);
		cout << "Number of pages: "; cin >> pagesize;
		cout << "Price: "; cin >> price;
		cout << "Number of poems: "; cin >> numberofpoems;
		file << '\n';
		file << "1," << title << ',' << author << ',' << pagesize << ',' << price << ',' << numberofpoems;
		cout << "The book has been added.\n"; system("pause");
	}
	file.close();
	sync = false;
}

BookRepository::~BookRepository() {
	for (int i = 0; i < lastindex; i++) {
		delete array[i];
	}
	delete[]array;
}