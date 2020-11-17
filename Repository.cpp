#include <iostream>
#include <fstream>
#include "Repository.h"
using namespace std;

Repository::Repository() {
	this->lastindex = -1;
	this->sync = false;
}

void Repository::Writetofile() {
	ofstream file("file.txt");
	file.close();
}