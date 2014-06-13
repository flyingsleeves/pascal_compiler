%{
/* lexan.l */

/* 
NAME:               Anthony DiRaddo
UTEID:              add459
CS USER:            quacks
ASSIGNMENT:         2
INCOMPLETE PARTS:   none

Other Comments:
Compiler throws a warning, but code outputs correct results.
*/

/* Based on stub code provided in lex1.c by:
    Gordon S. Novak Jr. and The University of Texas at Austin. */

#include <ctype.h>
#include "token.h"
#include "lexan.h"

int maketoken(int type, int which);
int install_id();
int install_fnum();
int yywrap();

/* Debug flags */
int debug_str = 0;
int debug_comments = 0;

/* If the lex yytext buffer turns out to be too small to hold comments,
   add the following lines:
 #undef YYLMAX
 #define YYLMAX 256
 */

TOKEN yylval;     /* This is the type of the lexical analyzer result */

%}

/* regular definitions */

delim    [ \t\n]
ws       {delim}+
letter   [A-Za-z]
digit    [0-9]
id       {letter}({letter}|{digit})*
string   ['](.)*[']
integer  {digit}+
fnumber  {digit}+(\.{digit}+)?(e[+\-]?{digit}+)?
com1     \{[^\}]*\}
com2     (\(\*)[^\(]*(\*\))

%%

{ws}      { /* no action and no return */ }
{com1}    { if (debug_comments) printf("[debug_comments]: %s\n", yytext); }
{com2}    { if (debug_comments) printf("[debug_comments]: %s\n", yytext); }
{string}  {return(install_string());}
{integer} {return(install_int());}
{fnumber} {return(install_fnum());}

"+"       {return(maketoken(OPERATOR, PLUS));}
"-"       {return(maketoken(OPERATOR, MINUS));}
"*"       {return(maketoken(OPERATOR, TIMES));}
"/"       {return(maketoken(OPERATOR, DIVIDE));}
":="      {return(maketoken(OPERATOR, ASSIGN));}
"="       {return(maketoken(OPERATOR, EQ));}
"<>"      {return(maketoken(OPERATOR, NE));}
"<"       {return(maketoken(OPERATOR, LT));}
"<="      {return(maketoken(OPERATOR, LE));}
">="      {return(maketoken(OPERATOR, GE));}
">"       {return(maketoken(OPERATOR, GT));}
"^"       {return(maketoken(OPERATOR, POINT));}
"."       {return(maketoken(OPERATOR, DOT));}
"and"     {return(maketoken(OPERATOR, AND));}
"or"      {return(maketoken(OPERATOR, OR));}
"not"     {return(maketoken(OPERATOR, NOT));}
"div"     {return(maketoken(OPERATOR, DIV));}
"mod"     {return(maketoken(OPERATOR, MOD));}
"in"      {return(maketoken(OPERATOR, IN));}

"array"     {return(maketoken(RESERVED, ARRAY));}
"begin"     {return(maketoken(RESERVED, BEGINBEGIN));}
"case"      {return(maketoken(RESERVED, CASE));}
"const"     {return(maketoken(RESERVED, CONST));}
"do"        {return(maketoken(RESERVED, DO));}
"downto"    {return(maketoken(RESERVED, DOWNTO));}
"else"      {return(maketoken(RESERVED, ELSE));}
"end"       {return(maketoken(RESERVED, END));}
"file"      {return(maketoken(RESERVED, FILEFILE));}
"for"       {return(maketoken(RESERVED, FOR));}
"function"  {return(maketoken(RESERVED, FUNCTION));}
"goto"      {return(maketoken(RESERVED, GOTO));}
"if"        {return(maketoken(RESERVED, IF));}
"label"     {return(maketoken(RESERVED, LABEL));}
"nil"       {return(maketoken(RESERVED, NIL));}
"of"        {return(maketoken(RESERVED, OF));}
"packed"    {return(maketoken(RESERVED, PACKED));}
"procedure" {return(maketoken(RESERVED, PROCEDURE));}
"program"   {return(maketoken(RESERVED, PROGRAM));}
"record"    {return(maketoken(RESERVED, RECORD));}
"repeat"    {return(maketoken(RESERVED, REPEAT));}
"set"       {return(maketoken(RESERVED, SET));}
"then"      {return(maketoken(RESERVED, THEN));}
"to"        {return(maketoken(RESERVED, TO));}
"type"      {return(maketoken(RESERVED, TYPE));}
"until"     {return(maketoken(RESERVED, UNTIL));}
"var"       {return(maketoken(RESERVED, VAR));}
"while"     {return(maketoken(RESERVED, WHILE));}
"with"      {return(maketoken(RESERVED, WITH));}

{id}      {return(install_id());}

","       {return(maketoken(DELIMITER, COMMA));}
";"       {return(maketoken(DELIMITER, SEMICOLON));}
":"       {return(maketoken(DELIMITER, COLON));}
"("       {return(maketoken(DELIMITER, LPAREN));}
")"       {return(maketoken(DELIMITER, RPAREN));}
"["       {return(maketoken(DELIMITER, LBRACKET));}
"]"       {return(maketoken(DELIMITER, RBRACKET));}
".."      {return(maketoken(DELIMITER, DOTDOT));}


%%

/* Note that lex always returns two values:
   1. "What is it?": a small integer such as NUMBER that indicates the
      kind of item that was found; this is the return() value.
   2. The value itself.  This is yylval, which points to a TOKEN.   */

/* Make simple tokens. */
int maketoken(int type, int which)
{
    yylval = (TOKEN) talloc(); /* Make new token, set yylval to point to it */
    yylval->tokentype = type;
    if (type == RESERVED)
        yylval->whichval = which - RESERVED_BIAS;
    else if (type == OPERATOR)
        yylval->whichval = which - OPERATOR_BIAS;
    else if (type == DELIMITER)
        yylval->whichval = which - DELIMITER_BIAS;
    else yylval->whichval = which;
    return (which);
}

int install_id()
{
    int i, c, n;
    yylval = (TOKEN) talloc(); /* Make new token, set yylval to point to it */
    yylval->tokentype = IDENTIFIERTOK;
    n = yyleng; /* number of characters */

    if (n > 15) n = 15;

    for (i = 0; i < n; i++)
    {
        c = yytext[i];
        /* if (islower(c)) c = toupper(c); */ /* to raise to upper case */
        yylval->stringval[i] = c;
    }

    yylval->stringval[n] = '\0';
    /* printf("id  %10s   n = %4d\n", yytext, n); */
    return (IDENTIFIER);
}

int install_string()
{
    int i, j, c, n;
    yylval = (TOKEN) talloc(); /* Make new token, set yylval to point to it */
    yylval->tokentype = STRINGTOK;
    n = yyleng; /* number of characters */
    j = 0; /* separate counter for strinval */

    if (n > 17) n = 17;

    for (i = 1; i < n-1; i++)
    {
        c = yytext[i];
        yylval->stringval[j++] = c;
        if (c == '\'') i++;
        if (debug_str) printf("\t[debug_str]: %c\n", c);
    }

    yylval->stringval[n] = '\0';
    /* printf("id  %10s   n = %4d\n", yytext, n); */
    return (STRING);
}

int install_int() /* Note -- you may use sscanf for this assignment. */
{
    double num;
    yylval = (TOKEN) talloc(); /* Make new token, set yylval to point to it */
    yylval->tokentype = NUMBERTOK;
    yylval->datatype = INTEGER;

    /* printf("num %10s   n = %4d\n",yytext,yyleng); */
    sscanf(yytext, "%ld", (long int *) &num);
    yylval->realval = num;
    return (NUMBER);
}

int install_fnum() /* Note -- you may use sscanf for this assignment. */
{
    float fnum;
    yylval = (TOKEN) talloc(); /* Make new token, set yylval to point to it */
    yylval->tokentype = NUMBERTOK;
    yylval->datatype = REAL;

    /* printf("num %10s   n = %4d\n",yytext,yyleng); */
    sscanf(yytext, "%f", &fnum);
    yylval->realval = fnum;
    return (NUMBER);
}

int yywrap()
{
    return (1);
} /* lex may need this. */

