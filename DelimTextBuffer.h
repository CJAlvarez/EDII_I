#ifndef DelimTextBuffer_H
#define DelimTextBuffer_H
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
using std::string;
using std::stringstream;

class DelimTextBuffer{
	
public:
	DelimTextBuffer(char Delim = '|', int maxBytes = 1000);
	int Read (istream & file);
	int Write (ostream & file)const;
	int Pack(const char* str, int size = -1 );
	int Unpack(char* str);
private:
	char Delim; //delimiter caracter
	char* Buffer; //character array to hold field values
	int BufferSize; //current size of packed fields
	int MaxBytes; //maximum # of characters in the buffer
	int NextByte;//paching/unpacking position in buffer
};
#endif
