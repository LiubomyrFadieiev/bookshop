#pragma once

class Repository {
protected:
	static const int maxlen = 20;
	int lastindex;
	bool sync;
public:
	Repository();
	virtual void Readfromfile();
	virtual void Writetofile();
};