#include <cstdio>
#include <iostream>
#include "parser.hpp"
#include "lexer.hpp"
#include "Writer.h"
#include "SyntaxManager.h"

using namespace std;
int main(int, char**) {
	//Declare the Syntax Manager
	SyntaxManager sm;
	Writer writer("test.html");
	yyscan_t scanner;
  	if (yylex_init(&scanner)) exit(1);
  	yyset_extra(&writer, scanner);
	// open a file handle to a particular file:
	FILE *myfile = fopen("test.shp", "r");
	// make sure it is valid:
	if (!myfile) {
		cout << "I can't open a.snazzle.file!" << endl;
		return -1;
	}
	// set flex to read from it instead of defaulting to STDIN:
	
	yyset_in(myfile, scanner);
	// parse through the input until there is no more:
	yyparse(scanner, &writer, &sm);
	yylex_destroy(scanner);
}
