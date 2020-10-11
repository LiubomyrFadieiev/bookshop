#pragma once
#include "Repository.h"
#include "Book.h"
#include "Poetry.h"

class BookRepository : public Repository {
	Book** array;
public:
	BookRepository();
	~BookRepository();

	void Readfromfile();

	void bookwrite();
	void addbook();
	void addpoetry();
};