#include <iostream>
#include <fstream>
#include "Repository.h"
using namespace std;

Repository::Repository() {
	this->lastindex = -1;
	this->sync = false;
}

void Repository::Readfromfile() {
	ifstream file("file.txt");
	file.close();
}

void Repository::Writetofile() {
	ofstream file("file.txt");
	file.close();
}