#pragma once
#include <string>
using namespace std;

class Branch {
protected:
	string name;
	string address;
	int rating;
public:
	Branch(string name = "", string address = "", int rating = 0);
	virtual string getname();
	virtual void write();
	virtual void setrating(int r);
	virtual int getrating();
	virtual string ratestar();
};