%output  	"parser.cpp"
%defines 	"parser.hpp"
%define 	api.pure full

%lex-param   { yyscan_t scanner }
%parse-param { yyscan_t scanner } {Writer* wrt} {SyntaxManager* syn}


%code requires {
	#include "Writer.h"
	#include "SyntaxManager.h"
	#include <string>
	#ifndef YY_TYPEDEF_YY_SCANNER_T
	#define YY_TYPEDEF_YY_SCANNER_T
	typedef void *yyscan_t;
	#endif
}

%code {
	#include <cstdio>
	#include <iostream>
	#include "lexer.hpp"

	using namespace std;
	int yyerror(yyscan_t scanner, Writer* wrt, SyntaxManager* syn, const char *msg);
}


%union {
	char *sval;
}

%token IF
%token INCLUDE
%token VARDEF
%token <sval> STRLITERAL

%%
// the first rule defined is the highest-level rule, which in our
// case is just the concept of a whole "shape file":


shape:
	shape if_stmt
	|shape inc_stmt
	|shape vardef_stmt
	|if_stmt
	|inc_stmt
	|vardef_stmt
	;
if_stmt:
	IF '(' STRLITERAL ')' {wrt->Write("Begin If : " + std::string($3));}
	;
inc_stmt:
	INCLUDE '(' STRLITERAL ')' {syn->Include(std::string($3),wrt);}
	;
vardef_stmt:
	VARDEF '(' STRLITERAL ')' {wrt->Write("Begin Var Def : " + std::string($3));} 
	;
%%

int yyerror(yyscan_t scanner, Writer* wrt, SyntaxManager* syn, const char *msg) {
	cout << "Parse error!  Message: " << msg << endl;
	// might as well halt now:
	exit(-1);
}