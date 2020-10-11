#pragma once
#include "Repository.h"
#include "Branch.h"
#include "Library.h"
#include "Bookshop.h"

class BranchRepository : public Repository {
	Branch** array;
public:
	BranchRepository();
	~BranchRepository();

	void Readfromfile();
	void branchwrite();
	void addbookshop();
	void addlibrary();

	void setrating();
};