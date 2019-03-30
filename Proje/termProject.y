%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

int ifCheck = 0; //To check if we are inside an if statement and if its 1 its if. If it equals to 2, then it is elsif.
int ifInsideIf = 0;	//To check if we are inside nested if statements.
int outOfIf = 0;	//To check if we are outside of if statement.

FILE *fout;	//So that we can output something
extern FILE *yyin;
extern int linenum;
char writeBuffer[100];
%}
%union
{
int number;	//This section is important, we define that number is int and string is char
char *string;
}
%token <number> INTEGER 	//We define tokens and <between here, we define it's type>
%token <string> STRING 
%token <string> IDENTIFIER 
%token <string> DSTRING 
%token <string> COMMENT
%type <number> expression 	//We use %type for the ones we created in yacc.
%type <string> identifier_block
%type <string> cond_block
%type <string> math_block
%token ECHORESW PLUSSYMBOL MINUSSYMBOL MULTIPLYSYMBOL IDENTIFIER INTEGER OPENPARANTHESIS CLOSEPARANTHESIS CURLYOPENPARANTHESIS CURLYCLOSEPARANTHESIS ASSIGNOP DOLLAR SLASHSYMBOL HARDOPENPARANTHESIS HARDCLOSEPARANTHESIS NEWL DSTRING STRING SHRESW COMMENT IFRESW THENRESW FIRESW LESSTHANOREQUALTO ELIFRESW ELSERESW GREATERTHAN GREATERTHANOREQUALTO EQUALTO LESSTHAN
%%

statements:
	statement statements
	|
	statement
	;

statement:
	sh_block
	|
	comment_block
	|
	expression 
	|
	if_block
	|
	elif_block
	|
	else_block
	|
	echo_block
	;

sh_block:
	SHRESW 		//In first example, there is a new line when this comes. So i printed \n
	{fprintf(fout, "\n");}
	;

comment_block:
	COMMENT		//In first example, there is 2 new lines when comment comes. So --> \n\n
	{fprintf(fout, "%s\n\n", $1);}	
	;

expression:
	INTEGER {$$ = $1;}	//An expression can be just an integer.
	|
	identifier_block ASSIGNOP expression	// a = expression or $a = expression
	{ if (ifCheck!=0) {	//Here im checking if we are inside an if. If so, we print an extra tab space.
			{fprintf(fout, "\t$%s=%d;\n", $1, $3);}
		}
	  else {
		{fprintf(fout, "$%s=%d;\n", $1, $3);}
	  }
	} 
	|	//From this point, its possible combinations shown below. (At least for the examples that are given.)
	identifier_block ASSIGNOP DOLLAR openparanthesis_block INTEGER math_block INTEGER closeparanthesis_block {fprintf(fout, "$%s=%d%s%d;\n", $1, $5, $6, $7);}
	|
	identifier_block ASSIGNOP DOLLAR openparanthesis_block identifier_block math_block openparanthesis_block identifier_block math_block INTEGER closeparanthesis_block
	{fprintf(fout, "$%s=$%s%s($%s%s%d);\n", $1, $5, $6, $8, $9, $10);}
	|
	identifier_block ASSIGNOP DOLLAR openparanthesis_block identifier_block math_block INTEGER closeparanthesis_block
	{fprintf(fout, "$%s=$%s%s%d;\n", $1, $5, $6, $7);}
	|
	identifier_block math_block INTEGER
	{ 
		if(ifCheck == 1){	//Check for inside if.
			if(ifInsideIf != 0){	//Check for nested if.
				{fprintf(fout, "\tif ($%s %s %d) {\n", $1, $2 ,$3);} 
			}
			if(ifInsideIf == 0){
				{fprintf(fout, "if ($%s %s %d) {\n", $1, $2 ,$3);}
				ifInsideIf++;
			}			
		}	//Check for elsif.
		else if(ifCheck == 2){ { fprintf(fout, "}elsif ($%s %s %d) {\n", $1, $2 ,$3);} }
	}
	|
	identifier_block ASSIGNOP DOLLAR openparanthesis_block identifier_block math_block INTEGER closeparanthesis_block math_block identifier_block closeparanthesis_block
	{ if (ifCheck!=0) {//If outside of if print else statement. Otherwise print with tab.
			{fprintf(fout, "\t$%s=($%s%s%d)%s$%s;\n", $1, $5, $6, $7, $9, $10);}
		}
	  else {
		{fprintf(fout, "$%s=($%s%s%d)%s$%s;\n", $1, $5, $6, $7, $9, $10);}
	  }
	}
	|
	identifier_block ASSIGNOP DOLLAR openparanthesis_block identifier_block math_block identifier_block closeparanthesis_block math_block openparanthesis_block identifier_block math_block identifier_block closeparanthesis_block
	{if (ifCheck!=0) {//If outside of if print else statement. Otherwise print with tab.
		{fprintf(fout, "\t$%s=($%s%s$%s)%s($%s%s$%s);\n", $1, $5, $6, $7, $9, $11, $12, $13);}
		}
	  else {
		{fprintf(fout, "$%s=($%s%s$%s)%s($%s%s$%s);\n", $1, $5, $6, $7, $9, $11, $12, $13);}
	  }
	}
	|
	identifier_block ASSIGNOP DOLLAR openparanthesis_block identifier_block math_block identifier_block closeparanthesis_block math_block openparanthesis_block identifier_block math_block INTEGER math_block openparanthesis_block identifier_block math_block identifier_block closeparanthesis_block
	{if (ifCheck!=0) {//If outside of if print else statement. Otherwise print with tab.
		fprintf(fout, "\t$%s=($%s%s$%s)%s($%s%s%d%s($%s%s$%s));\n", $1,$5,$6,$7,$9,$11,$12,$13,$14,$16,$17,$18);
		}
	  else {
		fprintf(fout, "$%s=($%s%s$%s)%s($%s%s%d%s($%s%s$%s));\n", $1,$5,$6,$7,$9,$11,$12,$13,$14,$16,$17,$18);
	  }
	}
	|
	identifier_block math_block identifier_block//Another possible expression.
	{ if (ifCheck!=0) {//If outside of if print else statement. Otherwise print with tab.
			{fprintf(fout, "\t$%s=%s;\n", $1, $3);}
		}
	  else {
		{fprintf(fout, "$%s=%s;\n", $1, $3);}
	  }
	}
	;

math_block://Math symbols
	MULTIPLYSYMBOL {$$ = "*";}
	|
	PLUSSYMBOL {$$ = "+";}
	|
	MINUSSYMBOL {$$ = "-";}
	|
	SLASHSYMBOL {$$ = "/";}
	|
	LESSTHANOREQUALTO {$$ = "<=";}
	|
	GREATERTHAN {$$ = ">";}
	|
	GREATERTHANOREQUALTO {$$ = ">=";}
	|
	EQUALTO {$$ = "==";}
	|
	LESSTHAN {$$ = "<";}
	;

openparanthesis_block://We use it this way because there can be too many open paranthesis. Its the recursive way so we can read them all.
	OPENPARANTHESIS openparanthesis_block
	|
	OPENPARANTHESIS
	;

closeparanthesis_block://We use it this way because there can be too many close paranthesis. Its the recursive way so we can read them all.
	CLOSEPARANTHESIS closeparanthesis_block
	|
	CLOSEPARANTHESIS
	;

if_block:
	cond_block HARDOPENPARANTHESIS expression HARDCLOSEPARANTHESIS THENRESW statements FIRESW
	{
		if(outOfIf == 0){ //If nested, print with tab.
			{fprintf(fout, "\t}\n"); outOfIf = 1;}
		}
		else{
			{fprintf(fout, "}\n"); outOfIf = 1;}
		}		
	}
	;
	
elif_block:
	cond_block HARDOPENPARANTHESIS expression HARDCLOSEPARANTHESIS THENRESW statements
	;
	
else_block:
	cond_block statements FIRESW
	{fprintf(fout, "}\n");}
	;

cond_block:
	IFRESW {ifCheck = 1; $$ = "if";}
	|
	ELIFRESW {ifCheck = 2; $$ = "elsif";}
	|
	ELSERESW { fprintf(fout, "}else {\n"); ifCheck = 3; $$ = "else";}
	;

echo_block:
	ECHORESW identifier_block	//Its same again. Check if inside if, nested? And print with tab.
	{
		if(ifCheck != 0){
			if(ifInsideIf != 0 && outOfIf == 0){
				{fprintf(fout, "\t\tprint $%s . \"\\n\";\n", $2);}
			}
			else{{fprintf(fout, "\tprint $%s . \"\\n\";\n", $2);}}
		}
		else{
			{fprintf(fout, "print $%s . \"\\n\";\n", $2);}
		}
	}
	|
	ECHORESW DSTRING {
		if(ifCheck != 0){
			{fprintf(fout, "\tprint %s . \"\\n\";\n", $2);}
		}
		else{
			{fprintf(fout, "print %s . \"\\n\";\n", $2);}
		}
	}
	|
	ECHORESW DOLLAR openparanthesis_block identifier_block math_block identifier_block closeparanthesis_block{
		if(ifCheck != 0){
			{fprintf(fout, "\tprint $%s%s$%s . \"\\n\";\n", $4, $5, $6);}
		}
		else{
			{fprintf(fout, "print $%s%s$%s . \"\\n\";\n", $4, $5, $6);}
		}
	}
	|
	ECHORESW STRING{
		if(ifCheck != 0){
			if(ifInsideIf != 0 && outOfIf == 0){
				{fprintf(fout, "\t\tprint %s . \"\\n\";\n", $2);}
			}
			else{{fprintf(fout, "\tprint %s . \"\\n\";\n", $2);}}
		}
		else{
			{fprintf(fout, "print %s . \"\\n\";\n", $2);}
		}
	}
	;

identifier_block:	//Identifier can be two ways. Direct or with dollar sign.
	IDENTIFIER {$$ = $1;}
	|
	DOLLAR IDENTIFIER {$$ = $2;}
	;


%%
void yyerror(char *s){
	fprintf(stderr,"Error at line: %d\n",linenum);	//Print the error line if any.
}
int yywrap(){
	return 1;
}
int main(int argc, char *argv[])
{
    /* Call the lexer, then quit. */
    yyin=fopen(argv[1],"r");
    fout = fopen(argv[2],"w");
    yyparse();
    fclose(yyin);
    fclose(fout);
    return 0;
}
