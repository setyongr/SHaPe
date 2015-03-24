#ifndef SYNMAN_CPP
#define SYNMAN_CPP
#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include"Writer.h"

class SyntaxManager
{
private:
	std::map<std::string, std::string> varString;
	std::map<std::string, int> varInt;
	std::map<std::string, bool> varBool;
	std::map<std::string, float> varFloat;

public:
	SyntaxManager();
	~SyntaxManager();
	void setString(std::string name, std::string val);
	void setInt(std::string name, int val);
	void setFloat(std::string name, float val);
	void setBool(std::string name, bool val);
	void Include(std::string name, Writer* wrtr);
	std::string strlitvalue(std::string strlit);
};
#endif