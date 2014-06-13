/* lexanc.c */

/* 
NAME:               Anthony DiRaddo
UTEID:              add459
CS USER:            quacks
ASSIGNMENT:         1
INCOMPLETE PARTS:   none

Other Comments:
I added a 'clean' command to the makefile
'make clean' should remove all object files (*.o)
*/

/* Based on stub code provided in lex1.c by:
    Gordon S. Novak Jr. and The University of Texas at Austin. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "lexan.h"

#define MAX_UINT 2147483647;
#define MAX_FLOAT 3.402823E+38;
#define MIN_FLOAT 1.175495E-38;

static char *opp_arr[] = { " ", "+", "-", "*", "/", ":=", "=", "<>", "<", "<=",
                           ">=", ">",  "^", ".", "and", "or", "not", "div",
                           "mod", "in", "if", "goto", "progn", "label",
                           "funcall", "aref", "program", "float" };

static char del_arr[] = { ' ',',', ';', ':', '(', ')', '[', ']', '.' };

static char *res_arr[] = { " ", "array", "begin", "case", "const", "do",
                           "downto", "else", "end", "file", "for",
		           						 "function", "goto", "if", "label", "nil",
                           "of", "packed", "procedure", "program", "record",
                           "repeat", "set", "then", "to", "type",
		           						 "until", "var", "while", "with" };

/* Skip blanks and whitespace.  Expand this function to skip comments too. */
void skipblanks ()
  {
      int c;
      while ((c = peekchar()) != EOF
             && ((c == ' ' || c == 13 || c == '\n' || c == '\t' || c == '{')
             			|| (c == '(' && peek2char() == '*')))
      {
      	/* If we find a '{', skip all characters until we find a '}' */
        if (c == '{')
        {
          while ((c = peekchar()) != EOF && c != '}')
            getchar();
        }
        /* If we find a '(' (AND a '*' after that as tested for above, 
            move pointer up twice, then check if the next character is 
            a '*' AND the one after that is ')'. If not keep skipping
            characters until we find either that or an EOF. */
        if (c == '(')
        {
        	getchar();   // pointer now at '('
        	getchar();   // pointer now at '*'

        	while (((c = peekchar()) != EOF) && !(c == '*' && peek2char() == ')'))
					{
        		getchar();  // keep calling this until we find end of comment or EOF
					}

        	getchar();   // move pointer up to the '*'
        }
        getchar();
      }
    }

/* Get identifiers and reserved words */
TOKEN identifier (TOKEN tok)
  {
    int c, num_chars, i;
    num_chars = 0;    // keep track of how many chars we have read in

    /* keep getting chars if the next char is alphanumeric */
    while((c = peekchar()) != EOF 
    			&& (CHARCLASS[c] == ALPHA || CHARCLASS[c] == NUMERIC))
    {
    	c = getchar();
    	if (num_chars < 15)  // only record the first 15 characters
    		tok->stringval[num_chars] = c;
    	num_chars++;
    }

    /* check the recorded string against our reserved words array */
    for (i = 1; i <= 29; i++)
    {
    	if (strcmp(tok->stringval, res_arr[i]) == 0)
    	{
    		tok->tokentype = RESERVED;
    		tok->whichval = i;
    		return (tok);
    	}
    }

    /* if it isn't a reserved word, it might be an operator */
    for (i = 14; i <= 19; i++)
    {
    	if (strcmp(tok->stringval, opp_arr[i]) == 0)
    	{
    		tok->tokentype = OPERATOR;
    		tok->whichval = i;
    		return (tok);
    	}
    }

    /* if it isn't a reserved word or an operator, it must be
        an identifier */
    tok->tokentype = IDENTIFIERTOK;
    tok->stringval[15] = '\0';    // just to be safe
    return (tok);
  }

TOKEN getstring (TOKEN tok)
  {
  	int c, num_chars;
    num_chars = 0;

    /* Move pointer to first char in string, i.e. skip the apostrophe */
    getchar();

    while((c = peekchar()) != EOF)
    {
    	c = getchar();
    	if (c == '\'')
    	{
    		if (peekchar() == '\'')   // handle finding two apostrophes in a row
    			getchar();
    		else                      // found a single apostrophe, end of string
    			break;
    	}
    	if (num_chars < 15)    // only record first 15 chars
    		tok->stringval[num_chars] = c;
    	num_chars++;
    }

    tok->tokentype = STRINGTOK;
    tok->datatype = STRINGTYPE;
    tok->stringval[15] = '\0';    // just to be safe
  	return (tok);
  }

TOKEN special (TOKEN tok)
  {
  	int c, i;
  	c = getchar();

  	/* Check for delimiter */
  	for (i = 1; i <= 8; i++)
  	{
  		/* SPECIAL CASE: we find the ":=" operator, break loop
					and let the operator check loop catch this instead */
  		if (c == ':' && peekchar() == '=')
  			break;

			/* SPECIAL CASE: we find the "." operator, break loop
					and let the operator check loop catch this instead */
			if (c == '.' && peekchar() != '.')
				break;

  		/* SPECIAL CASE: we find the ".." delimiter, just
  				move the char pointer up one and continue as normal */
  		if (c == '.' && peekchar() == '.')
  		{
  			getchar();
  			tok->tokentype = DELIMITER;
  			tok->whichval = 8;
  			return (tok);
  		}

      /* check against delimiter array */
  		if (c == del_arr[i])
  		{
  			tok->tokentype = DELIMITER;
  			tok->whichval = i;
  			return (tok);
  		}
  	}

  	/* Check for operator */
  	for (i = 1; i <= 13; i++)
  	{
  		tok->stringval[0] = c;

  		/* Detect two-character operators */
  		if ((c == ':' || c == '<' || c == '>') && peekchar() == '=')
  		{
  			getchar();
  			tok->stringval[1] = '=';
  		}
  		else if (c == '<' && peekchar() == '>')
  		{
  			getchar();
  			tok->stringval[1] = '>';
  		}

      /* check against operator array */
  		if (strcmp(tok->stringval, opp_arr[i]) == 0)
  		{
  			tok->tokentype = OPERATOR;
  			tok->whichval = i;
  			return (tok);
  		}
  	}

    /* should never get here, but print out the value of c
        if we do, for debug purposes */
  	tok->tokentype = NUMBERTOK;
  	tok->intval = c;
  	return (tok);
  }

/* Get and convert unsigned numbers of all types. */
TOKEN number (TOKEN tok)
  { 
  	long num;
  	double fnum;
    int  c, i, charval;
    int exponent, dec_places, trailing_digits, sig_digits;   // float variables
    int found_e, e_neg, found_dot, found_nonzero, overflow; // flags

    num = 0;
    exponent = 0;
    dec_places = 0;
    trailing_digits = 0;
    sig_digits = 0;
    found_e = 0;
    e_neg = 0;
    found_dot = 0;
    found_nonzero = 0;
    overflow = 0;
    
    tok->tokentype = NUMBERTOK;
    tok->datatype = INTEGER;
    tok->intval = num;

    while ( (c = peekchar()) != EOF
            && (CHARCLASS[c] == NUMERIC || c == '.' || c == 'e')
            && !(c == '.' && peek2char() == '.'))   // stop if found '..' delimiter
    {   	
    	c = getchar();

    	/* Handle finding a decimal point in the number */
    	if (c == '.')
    	{
    		if (found_dot == 1)
    		{
    			printf("number error: more than one '.' found\n");
    			return (tok);
    		}

    		tok->datatype = REAL;
    		found_dot = 1;
    		overflow = 0;   // integer overflow no longer relevant

    		continue;
    	}

    	/* Handle finding an 'e' in the number */
    	if (c == 'e')
    	{
    		if (found_e == 1)
    		{
    			printf("number error: more than one 'e' found\n");
    			return (tok);
    		}

    		tok->datatype = REAL;
    		found_e = 1;
    		overflow = 0;   // integer overflow no longer relevant

        /* check if a sign was given after the 'e' */
    		if (peekchar() == '-')
    		{
    			e_neg = 1;
    			getchar();
    		}

    		if (peekchar() == '+')
    			getchar();

    		continue;
    	}

    	charval = (c - '0');

    	if (charval > 0)   // lets us know when to start counting significant digits
    		found_nonzero = 1;
    	
    	/* keep adding to num unless we have found and 'e' */
    	if (found_e == 1)
    	{
    		if (exponent > 1000) // semi-arbitrary limit so we dont bomb out
    			overflow = 1;
    		else
    			exponent = exponent * 10 + charval;
    	}
    	else if (tok->datatype == INTEGER && sig_digits < 10)  // allow for possibility of becoming a float
    	{
    		if (num > 214748364 || (num == 214748364 && charval > 7)) // check integer range
    			overflow = 1;

      	num = num * 10 + charval;
    	}
    	else if (tok->datatype == REAL && sig_digits < 8) // don't carry beyond 8 significant digits
    		num = num * 10 + charval;

      /* count the number of places between the significant digits and the decimal point */
    	else if (found_dot == 0 && sig_digits >= 8)
    		trailing_digits++;
    
      /* add to counters when applicable */
      if (found_dot == 1 && sig_digits < 8)
      	dec_places++;
      if (found_nonzero == 1)
      	sig_digits++;
    }

    if (tok->datatype == REAL)
    {
    	fnum = num;

    	/* Calculate final exponent */
    	if (e_neg == 1)    // flip sign of exponent if we found a '-' after the 'e'
    		exponent = -exponent;

    	exponent -= dec_places;    // subtract decimal places from exponent
    	exponent += trailing_digits;   // add trailing_digits

    	/* Adjust value (shift decimal point) of fnum based on final exponent */
    	if (exponent >= 0)   // exponent is positive
    	{
	    	for (i = 0; i < exponent; i++)
	    		fnum = fnum * 10.0;
	    }
	    else   // exponent is negative
	    {
	    	for (i = 0; i > exponent; i--)
	    		fnum = fnum / 10.0;
	    }

	    if (fnum < 1.175495E-38 || fnum > 3.402823E+38)    // check float range
	    	overflow = 1;

    	tok->realval = fnum;
    }

    if (tok->datatype == INTEGER)
    {
    	tok->intval = num;
    }
    
    if (overflow == 1)
    	printf("[number error: overflow]\n");    // print error message if out of range
    return (tok);
  }

