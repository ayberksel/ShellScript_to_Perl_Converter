all: yacc lex
	cc lex.yy.c y.tab.c -o termProject

yacc: termProject.y
	yacc -d termProject.y

lex: termProject.l
	lex termProject.l


