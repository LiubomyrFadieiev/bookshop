#pragma once
#include <string>
using namespace std;

class Branch {
protected:
	string name;
	string address;
	int rating;
public:static const int id = 1;
	Branch(string name = "", string address = "", int rating = 0);
	static const bool ratingcheck = true;
	virtual string getname();
	virtual void write();
	virtual void setrating(int r);
	virtual int getrating();
	virtual string ratestar();
	string filespace() { return "../data/branch.txt"; }
	virtual int getid(){ return id; }
};