// DelimTextBuffer.h
#ifndef DelimTextBuffer_H
#define DelimTextBuffer_H

#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class DelimTextBuffer{
private:
	char Delim; // Delimiter caracter
	char* Buffer; // Character array to hold field values
	int BufferSize; // Current size of packed fields
	int MaxBytes; // Maximum # of characters in the buffer
	int NextByte; // Paching/unpacking position in buffer
	
public:
	DelimTextBuffer(char, int);
	int Read (istream& file);
	int Write (ostream& file) const;
	int Pack(const char* str, int size = -1 );
	int Unpack(char* str);
};

#endif
