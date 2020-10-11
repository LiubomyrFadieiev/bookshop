#include <iostream>
#include <string>
#include "BookRepository.h"
#include "BranchRepository.h"
using namespace std;

void Showmenu() {
	BookRepository book;
	BranchRepository branch;
	bool menu = true; char option;
	while (menu) {
		system("cls");
		cout << "	MENU\n";
		cout << "1. Show all books;\n2. Add new book;\n3. Add new poetry book;\n4. Show branches;\n5. Add new library;\n6. Add new bookshop;\n7. Set branch rating;\n0. Exit.\n";
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
			book.Readfromfile();
			book.bookwrite();
			system("pause");
			break;
		case '2':
			book.addbook();
			break;
		case '3':
			book.addpoetry();
			break;
		case '4':
			system("cls");
			branch.Readfromfile();
			branch.branchwrite();
			system("pause");
			break;
		case '5':
			branch.addlibrary();
			break;
		case '6':
			branch.addbookshop();
			break;
		case '7':
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