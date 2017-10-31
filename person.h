// person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <sstream>

using std::string;

class Person {
	
public:
	string firstname;
	string lastname;
	string address;
	string city;
	string state;
	string zip;
	
	/* @param: firstname, lastname, address, city, state, zip. */
	Person(string, string, string, string, string, string);
	string toString();
};

#endif

