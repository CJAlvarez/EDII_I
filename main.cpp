// main.cpp
#include "person.h"
#include "DelimTextBuffer.h"
#include <iostream>

using namespace std;

const int MaxBUfferSize = 200;

int WritePerson(ostream&, Person&);

int main(int argc, char const *argv[]) {
	// Define a Person
	Person p("George","Lucas","Ackerman Claude 1943","Chicago","Illinois","60007");
	
	// Write it
	ofstream wFile;
	wFile.open (p.firstname + p.lastname + "_" + p.zip + ".txt");
	DelimTextBuffer wBuffer('|', MaxBUfferSize);
		// Pack
	wBuffer.Write(wFile);
	wFile.close();
	
	// Read it
	ifstream rFile;
	rFile.open(p.firstname + p.lastname + "_" + p.zip + ".txt", ios_base::in);
	DelimTextBuffer rBuffer('|', MaxBUfferSize);
	wBuffer.Read(rFile);
		// Unpack
	rFile.close() ;
	return 0;
}

