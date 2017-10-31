#include "DelimTextBuffer.h"
#include <string>
#include <string.h>
using std::string;
using std::stringstream;
 

int DelimTextBuffer::Unpack(char* str){
	int len = -1;
	int start = NextByte;
	for(int i = start; i < BufferSize; i++){
		if(Buffer[i] == Delim){
			len = i-start;
			break;
		}
		if(len == -1){
			return false;
		}
		NextByte += len + 1;
		if(NextByte > BufferSize){
			return false;
		}
		strncpy(str,&Buffer[start],len);
		str[len]= 0;
		return true;	   
	}
}
int DelimTextBuffer::Pack(const char* str, int size){
	short len;
	if(size >= 0){
		len = size;
	}
	else{
		len = strlen(str);
	}
	if(len > strlen(str)){
		return false;		
	}
	int start = NextByte;
	NextByte += len + 1;
	if(NextByte > MaxBytes ){
		return false;
	}
	memcpy(&Buffer[start],str,len);
	Buffer [start+len] = Delim;
	BufferSize = NextByte;
	return true; 
}
int DelimTextBuffer::Read(istream & stream){
	stream.clear();
	stream.read((char *)&BufferSize, sizeof(BufferSize));
	if (stream.fail()){
		return false;
	} 
	if (BufferSize > MaxBytes){
		return false;
	} 
	stream.read(Buffer, BufferSize);
	return stream.good();
}
int DelimTextBuffer::Write(ostream & stream)const{
	stream.write((char*)&BufferSize,sizeof(BufferSize));
	stream.write(Buffer,BufferSize);
	return stream.good();
}


