#include <iostream>
#include <string>
#include "Repository.h"
using namespace std;

void Showmenu() {
	Repository<Book> book;
	Repository<Branch> branch;
	bool menu = true; char option;
	while (menu) {
		system("cls");
		cout << "	MENU\n";
		cout << "1. Show all books;\n2. Show branches;\n3. Add new book (or poetry);\n4. Add new branch (bookshop or library);\n5. Set branch rating;\n0. Exit.\n";
		try {
			cin >> option;
			if (!isdigit(option) || option < 0) {
				throw "Not possible option. Try again.\n";
				system("pause");
			}

		}
		catch (const char* a) {
			cout << a << endl;
		}
		switch (option) {
		case '1':
			system("cls");
			book.Readbookfromfile();
			book.write();
			system("pause");
			break;
		case '2':
			system("cls");
			branch.Readbranchfromfile();
			branch.write();
			system("pause");
			break;
		case '3':
			system("cls");
			book.create();
			break;
		case '4':
			system("cls");
			branch.create();
			break;
		case '5':
			system("cls");
			branch.setrating();
			break;
		case '0':
			menu = false;
			break;
		default:
			break;
		}
	}
}