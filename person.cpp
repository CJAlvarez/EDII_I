// person.cpp
#include "person.h"

using std::string;
using std::stringstream;

Person::Person(string firstname, string lastname, string address, string city, string state, string zip) {
	this -> firstname = firstname;
	this -> lastname = lastname;
	this -> address = address;
	this -> city = city;
	this -> state = state;
	this -> zip = zip;
}

string Person::toString(){
	stringstream ss;
	ss << "Name: " << firstname << " Address: " << address;
	return ss.str();
}
