// main.cpp
#include "person.h"
#include "DelimTextBuffer.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Const int MaxBUfferSize = 200;

int WritePerson(ostream&, Person&);

int main(int argc, char const *argv[]) {
	// Define a Person
	Person p("George","Lucas","Ackerman Claude 1943","Chicago","Illinois","60007");
	
	// Write it
	ofstream wFile;
	wFile.open (p.firstname + p.lastname + "_" + p.zip +".txt");
	
	wFile.close();
	cout << a.toString() << endl;
	cout << a.toString() << endl;
	return 0;
}

int WritePerson(ostream& stream, Person& p) {
	char buffer [MaxBufferSize]; 
    strcpy(buffer, p.LastName); strcat(buffer, “|”);
    strcat(buffer, p.FistName); strcat(buffer, “|”);
    
    strcat(buffer,p.Zipcode); strcat(buffer, “|”);
    short length=strlen(buffer);
    stream.write (&length, sizeof(length));
    stream.write(&buffer, length)
}

