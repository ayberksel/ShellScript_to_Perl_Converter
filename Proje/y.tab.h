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
extern YYSTYPE yylval;