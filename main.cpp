#include "person.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[]){
	Person a("George","Lucas","Ackerman Claude 1943","Chicago","Illinois","60007");
	cout << a.toString() << endl;
	cout << a.toString() << endl;
	return 0;
}

