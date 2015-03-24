#include "Writer.h"


Writer::Writer(std::string filename)
{
	file.open(filename.c_str());
}

void Writer::Write(std::string s)
{
	file << s;
}

Writer::~Writer()
{
	file.close();
}
