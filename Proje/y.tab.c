/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "termProject.y"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

int ifCheck = 0; /*To check if we are inside an if statement and if its 1 its if. If it equals to 2, then it is elsif.*/
int ifInsideIf = 0;	/*To check if we are inside nested if statements.*/
int outOfIf = 0;	/*To check if we are outside of if statement.*/

FILE *fout;	/*So that we can output something*/
extern FILE *yyin;
extern int linenum;
char writeBuffer[100];
#line 16 "termProject.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
int number;	/*This section is important, we define that number is int and string is char*/
char *string;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 48 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INTEGER 257
#define STRING 258
#define IDENTIFIER 259
#define DSTRING 260
#define COMMENT 261
#define ECHORESW 262
#define PLUSSYMBOL 263
#define MINUSSYMBOL 264
#define MULTIPLYSYMBOL 265
#define OPENPARANTHESIS 266
#define CLOSEPARANTHESIS 267
#define CURLYOPENPARANTHESIS 268
#define CURLYCLOSEPARANTHESIS 269
#define ASSIGNOP 270
#define DOLLAR 271
#define SLASHSYMBOL 272
#define HARDOPENPARANTHESIS 273
#define HARDCLOSEPARANTHESIS 274
#define NEWL 275
#define SHRESW 276
#define IFRESW 277
#define THENRESW 278
#define FIRESW 279
#define LESSTHANOREQUALTO 280
#define ELIFRESW 281
#define ELSERESW 282
#define GREATERTHAN 283
#define GREATERTHANOREQUALTO 284
#define EQUALTO 285
#define LESSTHAN 286
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    5,    5,    5,    5,    5,    5,    5,    6,
    7,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    4,    4,    4,    4,    4,    4,    4,    4,    4,
   12,   12,   13,   13,    8,    9,   10,    3,    3,    3,
   11,   11,   11,   11,    2,    2,
};
static const YYINT yylen[] = {                            2,
    2,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    3,    8,   11,    8,    3,   11,   14,   19,
    3,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    2,    1,    2,    1,    7,    6,    3,    1,    1,    1,
    2,    2,    7,    2,    1,    2,
};
static const YYINT yydefred[] = {                         0,
   12,   45,   11,    0,    0,   10,   38,   39,   40,    0,
    5,    0,    0,    0,    3,    4,    6,    7,    8,    9,
   44,   42,    0,   41,   46,   23,   24,   22,    0,   25,
   26,   27,   28,   29,   30,    0,    0,    0,    1,    0,
    0,    0,   13,   17,   21,    0,   37,   31,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   43,    0,    0,    0,    0,   35,   33,   14,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   18,    0,   15,
    0,    0,    0,    0,   19,    0,    0,    0,    0,   20,
};
static const YYINT yydgoto[] = {                         10,
   11,   12,   13,   36,   14,   15,   16,   17,   18,   19,
   20,   41,   61,
};
static const YYINT yysindex[] = {                      -248,
    0,    0,    0, -241, -253,    0,    0,    0,    0,    0,
    0, -168, -188, -248,    0,    0,    0,    0,    0,    0,
    0,    0, -156,    0,    0,    0,    0,    0, -255,    0,
    0,    0,    0,    0,    0, -195, -148, -267,    0, -240,
 -244, -156,    0,    0,    0, -252,    0,    0, -158, -138,
 -243, -244, -158, -158, -248, -228, -213, -214, -224, -228,
    0, -228, -228, -228, -244,    0,    0,    0, -158, -158,
 -158, -244, -240, -201, -228, -244, -228,    0, -158,    0,
 -128, -158, -228, -240,    0, -244, -158, -244, -228,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   10,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -127,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   38,    1,
    0,    0,    0,    0,    0,    0,    0,    0,   31,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                        -6,
   22,   -4,    0,  -29,    0,    0,    0,    0,    0,    0,
    0,  -37,    3,
};
#define YYTABLESIZE 320
static const YYINT yytable[] = {                         24,
   34,    1,   48,    2,   50,   25,   38,   39,    1,    2,
    2,   47,    3,    4,    2,   42,   21,    2,   22,   52,
   65,   51,    5,   57,   58,   40,    5,    6,    7,   23,
   16,   45,    8,    9,   55,   76,   49,   36,   60,   72,
   73,   74,   63,   62,    2,   54,   86,   56,   59,   81,
   43,   40,   84,   64,   66,   77,    5,   88,   46,    0,
   71,   44,   67,    2,   68,   69,   70,   75,    1,    0,
    2,   79,    3,    4,    0,    5,   83,   78,    0,   80,
    0,   87,    5,   89,   37,   85,    0,    6,    7,    0,
    0,   90,    8,    9,   26,   27,   28,    0,    0,    0,
    0,   29,   25,   30,   26,   27,   28,    0,    1,   40,
    2,   31,    0,   30,   32,   33,   34,   35,   53,    0,
    2,   31,    5,    0,   32,   33,   34,   35,   82,   32,
    2,   32,    5,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    5,   32,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   34,    0,   34,
    0,   34,   34,   34,   34,   34,    0,    0,    0,    0,
    0,   34,   34,    0,   34,    0,   34,   34,    0,   34,
   34,   34,   34,   34,   34,   34,   34,   16,    2,   16,
    0,   16,   16,    0,   36,    0,   36,    0,   36,   36,
    0,   16,    0,    0,   16,    0,   16,   16,   36,   16,
    0,   16,   16,   36,   36,    0,    0,    0,   36,   36,
};
static const YYINT yycheck[] = {                          4,
    0,  257,   40,  259,   42,  259,   13,   14,  257,    0,
  259,  279,  261,  262,  259,  271,  258,  259,  260,   49,
   58,  274,  271,   53,   54,  266,  271,  276,  277,  271,
    0,   36,  281,  282,  278,   73,   41,    0,  267,   69,
   70,   71,  257,  257,  259,   50,   84,   52,   55,   79,
   29,  266,   82,   58,  279,  257,  271,   87,   37,   -1,
   65,  257,   60,  259,   62,   63,   64,   72,  257,   -1,
  259,   76,  261,  262,   -1,  271,   81,   75,   -1,   77,
   -1,   86,  271,   88,  273,   83,   -1,  276,  277,   -1,
   -1,   89,  281,  282,  263,  264,  265,   -1,   -1,   -1,
   -1,  270,  259,  272,  263,  264,  265,   -1,  257,  266,
  259,  280,   -1,  272,  283,  284,  285,  286,  257,   -1,
  259,  280,  271,   -1,  283,  284,  285,  286,  257,  257,
  259,  259,  271,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  271,  271,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,  259,
   -1,  261,  262,  263,  264,  265,   -1,   -1,   -1,   -1,
   -1,  271,  272,   -1,  274,   -1,  276,  277,   -1,  279,
  280,  281,  282,  283,  284,  285,  286,  257,  279,  259,
   -1,  261,  262,   -1,  257,   -1,  259,   -1,  261,  262,
   -1,  271,   -1,   -1,  274,   -1,  276,  277,  271,  279,
   -1,  281,  282,  276,  277,   -1,   -1,   -1,  281,  282,
};
#define YYFINAL 10
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 286
#define YYUNDFTOKEN 302
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INTEGER","STRING","IDENTIFIER",
"DSTRING","COMMENT","ECHORESW","PLUSSYMBOL","MINUSSYMBOL","MULTIPLYSYMBOL",
"OPENPARANTHESIS","CLOSEPARANTHESIS","CURLYOPENPARANTHESIS",
"CURLYCLOSEPARANTHESIS","ASSIGNOP","DOLLAR","SLASHSYMBOL","HARDOPENPARANTHESIS",
"HARDCLOSEPARANTHESIS","NEWL","SHRESW","IFRESW","THENRESW","FIRESW",
"LESSTHANOREQUALTO","ELIFRESW","ELSERESW","GREATERTHAN","GREATERTHANOREQUALTO",
"EQUALTO","LESSTHAN",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : statements",
"statements : statement statements",
"statements : statement",
"statement : sh_block",
"statement : comment_block",
"statement : expression",
"statement : if_block",
"statement : elif_block",
"statement : else_block",
"statement : echo_block",
"sh_block : SHRESW",
"comment_block : COMMENT",
"expression : INTEGER",
"expression : identifier_block ASSIGNOP expression",
"expression : identifier_block ASSIGNOP DOLLAR openparanthesis_block INTEGER math_block INTEGER closeparanthesis_block",
"expression : identifier_block ASSIGNOP DOLLAR openparanthesis_block identifier_block math_block openparanthesis_block identifier_block math_block INTEGER closeparanthesis_block",
"expression : identifier_block ASSIGNOP DOLLAR openparanthesis_block identifier_block math_block INTEGER closeparanthesis_block",
"expression : identifier_block math_block INTEGER",
"expression : identifier_block ASSIGNOP DOLLAR openparanthesis_block identifier_block math_block INTEGER closeparanthesis_block math_block identifier_block closeparanthesis_block",
"expression : identifier_block ASSIGNOP DOLLAR openparanthesis_block identifier_block math_block identifier_block closeparanthesis_block math_block openparanthesis_block identifier_block math_block identifier_block closeparanthesis_block",
"expression : identifier_block ASSIGNOP DOLLAR openparanthesis_block identifier_block math_block identifier_block closeparanthesis_block math_block openparanthesis_block identifier_block math_block INTEGER math_block openparanthesis_block identifier_block math_block identifier_block closeparanthesis_block",
"expression : identifier_block math_block identifier_block",
"math_block : MULTIPLYSYMBOL",
"math_block : PLUSSYMBOL",
"math_block : MINUSSYMBOL",
"math_block : SLASHSYMBOL",
"math_block : LESSTHANOREQUALTO",
"math_block : GREATERTHAN",
"math_block : GREATERTHANOREQUALTO",
"math_block : EQUALTO",
"math_block : LESSTHAN",
"openparanthesis_block : OPENPARANTHESIS openparanthesis_block",
"openparanthesis_block : OPENPARANTHESIS",
"closeparanthesis_block : CLOSEPARANTHESIS closeparanthesis_block",
"closeparanthesis_block : CLOSEPARANTHESIS",
"if_block : cond_block HARDOPENPARANTHESIS expression HARDCLOSEPARANTHESIS THENRESW statements FIRESW",
"elif_block : cond_block HARDOPENPARANTHESIS expression HARDCLOSEPARANTHESIS THENRESW statements",
"else_block : cond_block statements FIRESW",
"cond_block : IFRESW",
"cond_block : ELIFRESW",
"cond_block : ELSERESW",
"echo_block : ECHORESW identifier_block",
"echo_block : ECHORESW DSTRING",
"echo_block : ECHORESW DOLLAR openparanthesis_block identifier_block math_block identifier_block closeparanthesis_block",
"echo_block : ECHORESW STRING",
"identifier_block : IDENTIFIER",
"identifier_block : DOLLAR IDENTIFIER",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 250 "termProject.y"
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
#line 363 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 10:
#line 57 "termProject.y"
	{fprintf(fout, "\n");}
break;
case 11:
#line 62 "termProject.y"
	{fprintf(fout, "%s\n\n", yystack.l_mark[0].string);}
break;
case 12:
#line 66 "termProject.y"
	{yyval.number = yystack.l_mark[0].number;}
break;
case 13:
#line 69 "termProject.y"
	{ if (ifCheck!=0) {	/*Here im checking if we are inside an if. If so, we print an extra tab space.*/
			{fprintf(fout, "\t$%s=%d;\n", yystack.l_mark[-2].string, yystack.l_mark[0].number);}
		}
	  else {
		{fprintf(fout, "$%s=%d;\n", yystack.l_mark[-2].string, yystack.l_mark[0].number);}
	  }
	}
break;
case 14:
#line 77 "termProject.y"
	{fprintf(fout, "$%s=%d%s%d;\n", yystack.l_mark[-7].string, yystack.l_mark[-3].number, yystack.l_mark[-2].string, yystack.l_mark[-1].number);}
break;
case 15:
#line 80 "termProject.y"
	{fprintf(fout, "$%s=$%s%s($%s%s%d);\n", yystack.l_mark[-10].string, yystack.l_mark[-6].string, yystack.l_mark[-5].string, yystack.l_mark[-3].string, yystack.l_mark[-2].string, yystack.l_mark[-1].number);}
break;
case 16:
#line 83 "termProject.y"
	{fprintf(fout, "$%s=$%s%s%d;\n", yystack.l_mark[-7].string, yystack.l_mark[-3].string, yystack.l_mark[-2].string, yystack.l_mark[-1].number);}
break;
case 17:
#line 86 "termProject.y"
	{ 
		if(ifCheck == 1){	/*Check for inside if.*/
			if(ifInsideIf != 0){	/*Check for nested if.*/
				{fprintf(fout, "\tif ($%s %s %d) {\n", yystack.l_mark[-2].string, yystack.l_mark[-1].string ,yystack.l_mark[0].number);} 
			}
			if(ifInsideIf == 0){
				{fprintf(fout, "if ($%s %s %d) {\n", yystack.l_mark[-2].string, yystack.l_mark[-1].string ,yystack.l_mark[0].number);}
				ifInsideIf++;
			}			
		}	/*Check for elsif.*/
		else if(ifCheck == 2){ { fprintf(fout, "}elsif ($%s %s %d) {\n", yystack.l_mark[-2].string, yystack.l_mark[-1].string ,yystack.l_mark[0].number);} }
	}
break;
case 18:
#line 100 "termProject.y"
	{ if (ifCheck!=0) {/*If outside of if print else statement. Otherwise print with tab.*/
			{fprintf(fout, "\t$%s=($%s%s%d)%s$%s;\n", yystack.l_mark[-10].string, yystack.l_mark[-6].string, yystack.l_mark[-5].string, yystack.l_mark[-4].number, yystack.l_mark[-2].string, yystack.l_mark[-1].string);}
		}
	  else {
		{fprintf(fout, "$%s=($%s%s%d)%s$%s;\n", yystack.l_mark[-10].string, yystack.l_mark[-6].string, yystack.l_mark[-5].string, yystack.l_mark[-4].number, yystack.l_mark[-2].string, yystack.l_mark[-1].string);}
	  }
	}
break;
case 19:
#line 109 "termProject.y"
	{if (ifCheck!=0) {/*If outside of if print else statement. Otherwise print with tab.*/
		{fprintf(fout, "\t$%s=($%s%s$%s)%s($%s%s$%s);\n", yystack.l_mark[-13].string, yystack.l_mark[-9].string, yystack.l_mark[-8].string, yystack.l_mark[-7].string, yystack.l_mark[-5].string, yystack.l_mark[-3].string, yystack.l_mark[-2].string, yystack.l_mark[-1].string);}
		}
	  else {
		{fprintf(fout, "$%s=($%s%s$%s)%s($%s%s$%s);\n", yystack.l_mark[-13].string, yystack.l_mark[-9].string, yystack.l_mark[-8].string, yystack.l_mark[-7].string, yystack.l_mark[-5].string, yystack.l_mark[-3].string, yystack.l_mark[-2].string, yystack.l_mark[-1].string);}
	  }
	}
break;
case 20:
#line 118 "termProject.y"
	{if (ifCheck!=0) {/*If outside of if print else statement. Otherwise print with tab.*/
		fprintf(fout, "\t$%s=($%s%s$%s)%s($%s%s%d%s($%s%s$%s));\n", yystack.l_mark[-18].string,yystack.l_mark[-14].string,yystack.l_mark[-13].string,yystack.l_mark[-12].string,yystack.l_mark[-10].string,yystack.l_mark[-8].string,yystack.l_mark[-7].string,yystack.l_mark[-6].number,yystack.l_mark[-5].string,yystack.l_mark[-3].string,yystack.l_mark[-2].string,yystack.l_mark[-1].string);
		}
	  else {
		fprintf(fout, "$%s=($%s%s$%s)%s($%s%s%d%s($%s%s$%s));\n", yystack.l_mark[-18].string,yystack.l_mark[-14].string,yystack.l_mark[-13].string,yystack.l_mark[-12].string,yystack.l_mark[-10].string,yystack.l_mark[-8].string,yystack.l_mark[-7].string,yystack.l_mark[-6].number,yystack.l_mark[-5].string,yystack.l_mark[-3].string,yystack.l_mark[-2].string,yystack.l_mark[-1].string);
	  }
	}
break;
case 21:
#line 127 "termProject.y"
	{ if (ifCheck!=0) {/*If outside of if print else statement. Otherwise print with tab.*/
			{fprintf(fout, "\t$%s=%s;\n", yystack.l_mark[-2].string, yystack.l_mark[0].string);}
		}
	  else {
		{fprintf(fout, "$%s=%s;\n", yystack.l_mark[-2].string, yystack.l_mark[0].string);}
	  }
	}
break;
case 22:
#line 137 "termProject.y"
	{yyval.string = "*";}
break;
case 23:
#line 139 "termProject.y"
	{yyval.string = "+";}
break;
case 24:
#line 141 "termProject.y"
	{yyval.string = "-";}
break;
case 25:
#line 143 "termProject.y"
	{yyval.string = "/";}
break;
case 26:
#line 145 "termProject.y"
	{yyval.string = "<=";}
break;
case 27:
#line 147 "termProject.y"
	{yyval.string = ">";}
break;
case 28:
#line 149 "termProject.y"
	{yyval.string = ">=";}
break;
case 29:
#line 151 "termProject.y"
	{yyval.string = "==";}
break;
case 30:
#line 153 "termProject.y"
	{yyval.string = "<";}
break;
case 35:
#line 170 "termProject.y"
	{
		if(outOfIf == 0){ /*If nested, print with tab.*/
			{fprintf(fout, "\t}\n"); outOfIf = 1;}
		}
		else{
			{fprintf(fout, "}\n"); outOfIf = 1;}
		}		
	}
break;
case 37:
#line 186 "termProject.y"
	{fprintf(fout, "}\n");}
break;
case 38:
#line 190 "termProject.y"
	{ifCheck = 1; yyval.string = "if";}
break;
case 39:
#line 192 "termProject.y"
	{ifCheck = 2; yyval.string = "elsif";}
break;
case 40:
#line 194 "termProject.y"
	{ fprintf(fout, "}else {\n"); ifCheck = 3; yyval.string = "else";}
break;
case 41:
#line 199 "termProject.y"
	{
		if(ifCheck != 0){
			if(ifInsideIf != 0 && outOfIf == 0){
				{fprintf(fout, "\t\tprint $%s . \"\\n\";\n", yystack.l_mark[0].string);}
			}
			else{{fprintf(fout, "\tprint $%s . \"\\n\";\n", yystack.l_mark[0].string);}}
		}
		else{
			{fprintf(fout, "print $%s . \"\\n\";\n", yystack.l_mark[0].string);}
		}
	}
break;
case 42:
#line 211 "termProject.y"
	{
		if(ifCheck != 0){
			{fprintf(fout, "\tprint %s . \"\\n\";\n", yystack.l_mark[0].string);}
		}
		else{
			{fprintf(fout, "print %s . \"\\n\";\n", yystack.l_mark[0].string);}
		}
	}
break;
case 43:
#line 220 "termProject.y"
	{
		if(ifCheck != 0){
			{fprintf(fout, "\tprint $%s%s$%s . \"\\n\";\n", yystack.l_mark[-3].string, yystack.l_mark[-2].string, yystack.l_mark[-1].string);}
		}
		else{
			{fprintf(fout, "print $%s%s$%s . \"\\n\";\n", yystack.l_mark[-3].string, yystack.l_mark[-2].string, yystack.l_mark[-1].string);}
		}
	}
break;
case 44:
#line 229 "termProject.y"
	{
		if(ifCheck != 0){
			if(ifInsideIf != 0 && outOfIf == 0){
				{fprintf(fout, "\t\tprint %s . \"\\n\";\n", yystack.l_mark[0].string);}
			}
			else{{fprintf(fout, "\tprint %s . \"\\n\";\n", yystack.l_mark[0].string);}}
		}
		else{
			{fprintf(fout, "print %s . \"\\n\";\n", yystack.l_mark[0].string);}
		}
	}
break;
case 45:
#line 243 "termProject.y"
	{yyval.string = yystack.l_mark[0].string;}
break;
case 46:
#line 245 "termProject.y"
	{yyval.string = yystack.l_mark[0].string;}
break;
#line 775 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
