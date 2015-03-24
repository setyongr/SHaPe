#include "SyntaxManager.h"

SyntaxManager::SyntaxManager()
{
}

SyntaxManager::~SyntaxManager()
{
}

void SyntaxManager::setString(std::string name, std::string val)
{
	varString[name] = val;
}

void SyntaxManager::setInt(std::string name, int val)
{
	varInt[name] = val;
}

void SyntaxManager::setFloat(std::string name, float val)
{
	varFloat[name] = val;
}

void SyntaxManager::setBool(std::string name, bool val)
{
	varBool[name] = val;
}

void SyntaxManager::Include(std::string name, Writer* wrtr)
{
	std::cout << "Include Statement Found..." <<std::endl;
	std::fstream file(strlitvalue(name).c_str());
	std::string line;
	while(std::getline(file, line))
	{
		wrtr->Write(line);
	}
	file.close();
}

std::string SyntaxManager::strlitvalue(std::string strlit){
	return strlit.substr(1, strlit.length() - 2);
}