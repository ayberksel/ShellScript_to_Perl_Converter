digit	[0-9]
letter	[A-Za-z]
%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
int linenum=1;
%}
%%
	
	/* RESERVED WORDS*/

"if"	return IFRESW;
"then"	return THENRESW;
"fi"	return FIRESW;
"elif"	return ELIFRESW;
"else"	return ELSERESW;
"-le"	return LESSTHANOREQUALTO;
"-gt"	return GREATERTHAN;
"-ge"	return GREATERTHANOREQUALTO;
"-eq"	return EQUALTO;
"-lt"	return LESSTHAN;
"echo"	return ECHORESW;
"#!/bin/sh"	return SHRESW;

	/* SYMBOLS */

"="	return ASSIGNOP;	
"+"	return PLUSSYMBOL;
"*"	return MULTIPLYSYMBOL;
"/"	return SLASHSYMBOL;
"-"	return MINUSSYMBOL;
"$"	return DOLLAR;

	/* PARANTHESIS */

"("	return OPENPARANTHESIS;	
")"	return CLOSEPARANTHESIS;
"{"	return CURLYOPENPARANTHESIS;
"}"	return CURLYCLOSEPARANTHESIS;
"["	return HARDOPENPARANTHESIS;
"]"	return HARDCLOSEPARANTHESIS;

	/* NUMBERS */

[0-9]+	{yylval.number = atoi(yytext);return INTEGER;}		

	/* IMPORTANTS */ 

{letter}({letter}|{digit})*	{yylval.string = strdup(yytext);return IDENTIFIER;}
"#"(.|\\)*	{yylval.string = strdup(yytext);return COMMENT;}
\"\\n\"	return NEWL;
\".*\"  {yylval.string = strdup(yytext);return DSTRING;}
\'.*\'  {yylval.string = strdup(yytext);return STRING;}

\n	{linenum++;}
[ \t]+
("#".*) 
. 

%%


