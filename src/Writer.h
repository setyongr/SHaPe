#ifndef WRITER_CPP
#define WRITER_CPP
#include<iostream>
#include<string>
#include<fstream>
class Writer
{
private:
	std::ofstream file;
public:
	Writer(std::string filename);
	void Write(std::string s);
	~Writer();
};

#endif