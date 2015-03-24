%option outfile="lexer.cpp" header-file="lexer.hpp"
%option reentrant bison-bridge
%option noyywrap nounput noinput
%option extra-type="Writer*"

%{
#include <cstdio>
#include <iostream>
#include "Writer.h"
#include "SyntaxManager.h"
using namespace std;

#include "parser.hpp" // to get the token types that we return
%}

%x SHAPE

%%
<INITIAL>{
	[\t\n]          		;
	"@"						{BEGIN(SHAPE);}
	.						{yyextra->Write(yytext);}

}
<SHAPE>{
	"if" 					{return IF;}
	"include"				{return INCLUDE;}
	"var"					{return VARDEF;}
	L?\"(\\.|[^\\"])*\"		{yylval->sval = strdup(yytext);
							 return STRLITERAL;}
	"("						{return '(';}
	")"						{BEGIN(INITIAL);return ')';};
	.						{;}
}
%%