#ifndef PERSON_H
#define PERSON_H
#include <string>
using std::string;

class Person{
	string firstname;
	string lastname;
	string address;
	string city;
	string state;
	string zip;
public:
	Person(string, string, string, string, string, string);
	string toString();
};
#endif

