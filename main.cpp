// main.cpp
#include "person.h"
#include "DelimTextBuffer.h"
#include <iostream>

using namespace std;

const int MaxBUfferSize = 200;

int WritePerson(ostream&, Person&);

int main(int argc, char const *argv[]) {
/* WRITING */
	Person wPerson("George", "Lucas", "Ackerman Claude 1943", "Chicago", "Illinois", "60007");
	
	// Write it
	ofstream wFile;
	wFile.open (wPerson.firstname + wPerson.lastname + "_" + wPerson.zip + ".txt");
	DelimTextBuffer wBuffer('|', MaxBUfferSize);
		// Pack
	wBuffer.Pack(wPerson.firstname*, sizeof(wPerson.firstname));
	wBuffer.Pack(wPerson.lastname*, sizeof(wPerson.lastname));
	wBuffer.Pack(wPerson.city*, sizeof(wPerson.city));
	wBuffer.Pack(wPerson.address*, sizeof(wPerson.address));
	wBuffer.Pack(wPerson.state*, sizeof(wPerson.state));
	wBuffer.Pack(wPerson.zip*, sizeof(wPerson.zip));
		// End_Pack
	wBuffer.Write(wFile);
	wFile.close();
	
/* READING */
	Person rPerson;
	
	// Read it
	ifstream rFile;
	rFile.open(wPerson.firstname + wPerson.lastname + "_" + wPerson.zip + ".txt", ios_base::in);
	DelimTextBuffer rBuffer('|', MaxBUfferSize);
	rBuffer.Read(rFile);
		// Unpack
	rBuffer.Unpack(rPerson.firstname*);
	rBuffer.Unpack(rPerson.lastname*);
	rBuffer.Unpack(rPerson.city*);
	rBuffer.Unpack(rPerson.address*);
	rBuffer.Unpack(rPerson.state*);
	rBuffer.Unpack(rPerson.zip*);
		// End_Unpack
	rFile.close() ;
	
	cout << "READ: " << rPerson.toString() << endl;
	return 0;
}

