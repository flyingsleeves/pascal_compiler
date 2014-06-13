%{     /* parse.y    Pascal Parser */

/* 
NAME:               Anthony DiRaddo
UTEID:              add459
CS USER:            quacks
ASSIGNMENT:         6
INCOMPLETE PARTS:   pasrec assembly

Other Comments: n/a
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"

/* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;
int yydebug = 0;

%}

/* Order of tokens corresponds to tokendefs.c; do not change */

%token IDENTIFIER STRING NUMBER   /* token types */

%token PLUS MINUS TIMES DIVIDE    /* Operators */
%token ASSIGN EQ NE LT LE GE GT POINT DOT AND OR NOT DIV MOD IN

%token COMMA                      /* Delimiters */
%token SEMICOLON COLON LPAREN RPAREN LBRACKET RBRACKET DOTDOT

%token ARRAY BEGINBEGIN           /* Lex uses BEGIN */
%token CASE CONST DO DOWNTO ELSE END FILEFILE FOR FUNCTION GOTO IF LABEL NIL
%token OF PACKED PROCEDURE PROGRAM RECORD REPEAT SET THEN TO TYPE UNTIL
%token VAR WHILE WITH

%%

program         :  PROGRAM IDENTIFIER LPAREN identifier_list RPAREN SEMICOLON block DOT
                    { parseresult = makeprogram($2, makeprogn($3, $4), $7); }
                ;
block           :  lblock cblock tblock vblock statement        { $$ = $5; }
                ;
lblock          :  LABEL NUMBER endlabel                        { instlabel($2); }
                |  /* empty */
                ;
endlabel        :  COMMA NUMBER endlabel                        { instlabel($2); }
                |  SEMICOLON
                ;
cblock          :  CONST c_asgn_list                            { $$ = NULL; }
                |  /* empty */                                  { $$ = NULL; }
                ;
c_asgn_list     :  c_asgn_list c_asgn                           { $$ = NULL; }
                |  c_asgn                                       { $$ = NULL; }
                ;
c_asgn          :  IDENTIFIER EQ constant SEMICOLON             { instconst($1, $3); }
                ;
tblock          :  TYPE t_asgn_list                             { $$ = NULL; }
                | /* empty */
                ;
t_asgn_list     :  t_asgn_list t_asgn                           { $$ = NULL; }
                |  t_asgn                                       { $$ = NULL; }
                ;
t_asgn          :  IDENTIFIER EQ type SEMICOLON                 { insttype($1, $3); }
                ;
type            :  simple_type                                  { $$ = $1; }
                |  POINT IDENTIFIER                             { $$ = instpoint($1, $2); }
                |  ARRAY LBRACKET s_type_list RBRACKET OF type  { $$ = instarray($3, $6); }
                |  RECORD field_list END                        { $$ = instrec($1, $2); }
                ;
simple_type     :  IDENTIFIER                                   { $$ = findtype($1); }
                |  LPAREN identifier_list RPAREN                { $$ = instenum($2); }
                |  NUMBER DOTDOT NUMBER                         { $$ = instdotdot($1, $2, $3); }
                ;
s_type_list     :  simple_type COMMA s_type_list                { $$ = nconc($1, $3); }
                |  simple_type                                  { $$ = $1; }
                ;
field_list      :  field SEMICOLON field_list                   { $$ = nconc($1, $3); }
                |  field                                        { $$ = $1; }
                ;
field           :  identifier_list COLON type                   { $$ = instfields($1, $3); }
                ;
vblock          :  VAR v_asgn_list                              { $$ = NULL; }
                |  /* empty */                                  { $$ = NULL; }
                ;
v_asgn_list     :  v_asgn_list v_asgn                           { $$ = NULL; }
                |  v_asgn                                       { $$ = NULL; }
                ;
v_asgn          :  identifier_list COLON type SEMICOLON         { instvars($1, $3); }
                ;
identifier_list :  IDENTIFIER COMMA identifier_list             { $$ = cons($1, $3); }
                |  IDENTIFIER                                   
                ;
statement       :  BEGINBEGIN statement endpart                 { $$ = makepnb($1, cons($2, $3)); }
                |  NUMBER COLON statement                       { $$ = dolabel($1, $2, $3); } // TODO fix label grammar
                |  IF expr THEN statement endif                 { $$ = makeif($1, $2, $4, $5); }
                |  REPEAT statement_list UNTIL expr             { $$ = makerepeat($1, $2, $3, $4); }
                |  FOR assignment TO expr DO statement          { $$ = makefor(1, $1, $2, $3, $4, $5, $6); }
                |  FOR assignment TO expr DOWNTO statement      { $$ = makefor(-1, $1, $2, $3, $4, $5, $6); }
                |  WHILE expr DO statement                      { $$ = makewhile($1, $2, $3, $4); }
                |  IDENTIFIER LPAREN s_expr RPAREN              { $$ = makefuncall($2, $1, $3); }
                |  GOTO NUMBER                                  { $$ = dogoto($1, $2); }
                |  assignment
                ;
endpart         :  SEMICOLON statement endpart                  { $$ = cons($2, $3); }
                |  END                                          { $$ = NULL; }
                ;
statement_list  :  statement SEMICOLON statement_list           { $$ = cons($1, $3); }
                |  statement
                ;
endif           :  ELSE statement                               { $$ = $2; }
                |  /* empty */                                  { $$ = NULL; }
                ;              
assignment      :  variable ASSIGN expr                         { $$ = binop($2, $1, $3); }
                ;
expr            :  s_expr EQ s_expr                             { $$ = binop($2, $1, $3); }
                |  s_expr LT s_expr                             { $$ = binop($2, $1, $3); }
                |  s_expr GT s_expr                             { $$ = binop($2, $1, $3); }
                |  s_expr NE s_expr                             { $$ = binop($2, $1, $3); }
                |  s_expr LE s_expr                             { $$ = binop($2, $1, $3); }
                |  s_expr GE s_expr                             { $$ = binop($2, $1, $3); }
                |  s_expr IN s_expr                             { $$ = binop($2, $1, $3); }
                |  s_expr
                ;
s_expr          :  MINUS s_expr                                 { $$ = unaryop($1, $2); }
                |  s_expr PLUS term                             { $$ = binop($2, $1, $3); }
                |  s_expr MINUS term                            { $$ = binop($2, $1, $3); }
                |  s_expr OR term                               { $$ = binop($2, $1, $3); } 
                |  term  
                ;
term            :  term TIMES factor                            { $$ = binop($2, $1, $3); }
                |  term DIVIDE factor                           { $$ = binop($2, $1, $3); }
                |  term MOD factor                              { $$ = binop($2, $1, $3); }
                |  term AND factor                              { $$ = binop($2, $1, $3); }
                |  factor
                ;
factor          :  LPAREN expr RPAREN                           { $$ = $2; }
                |  variable                                     { $$ = $1; }
                |  IDENTIFIER LPAREN s_expr RPAREN              { $$ = makefuncall($2, $1, $3); }
                |  constant
                ;
variable        :  IDENTIFIER                                   { $$ = findid($1); }
                |  variable DOT IDENTIFIER                      { $$ = reducedot($1, $2, $3); }
                |  variable POINT                               { $$ = dopoint($1, $2); }
                |  variable LBRACKET s_expr_list RBRACKET       { $$ = arrayref($1, $2, $3, $4); }
                ;
s_expr_list     :  s_expr COMMA s_expr_list                     { $$ = cons($1, $3); }
                |  s_expr
                ;
constant        :  NUMBER
                |  STRING
                |  NIL                                          { $$ = fillintc($1, 0); }
                ;

%%

/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working. */

#define DEBUG            1             /* set bits here for debugging, 0 = off  */
#define DB_CONS          0             /* bit to trace cons and nconc */
#define DB_OPS           0             /* bit to trace binop and unaryop */
#define DB_MAKEIF        0             /* bit to trace makeif */
#define DB_MAKEPROGN     0             /* bit to trace makeprogn */
#define DB_PARSERES      1             /* bit to trace parseresult */

// My flags
#define DB_NUMS          0             /* converting or filling in numbers */
#define DB_CLEARTOK      0
#define DB_CONDVAR       0             /* variables and constants */
#define DB_LOOP          0            
#define DB_MAKE          0             /* makes not covered elsewhere */
#define DB_RECORD        0             /* records */
#define DB_LABEL         0
#define DB_FUNCALL       0
#define DB_FINDID        0
#define DB_FINDTYPE      0
#define DB_SUBRANGE      0
#define DB_POINTERS      0
#define DB_ARRAY         0
#define DB_AREF          0
#define DB_FIND          0
#define DB_SYMTYPE       0
#define DB_INSTALL       0              /* installs not covered elsewhere */
#define DB_MISC          0
#define DB_REFASGN       0              /* assignments to aref ops */


int labelnumber = 0;  /* sequential counter for internal label numbers */
int labeltable[100];

/* Note: you should add to the above values and insert debugging
   printouts in your routines similar to those that are shown here. */

/* set all of a token's values to NULL before
   recycling it */
TOKEN cleartok(TOKEN tok)
{
    if (DEBUG && DB_CLEARTOK)
    {
        printf("cleartok\n");
        dbugprinttok(tok);
    }

    tok->tokentype = 0;
    tok->datatype = 0;
    tok->symtype = NULL;
    tok->symentry = NULL;
    tok->operands = NULL;
    tok->link = NULL;
    tok->intval = 0;

    return tok;
}

TOKEN cons(TOKEN item, TOKEN list)           /* add item to front of list */
{ 
    if (DEBUG && DB_CONS)
    {
        printf("cons\n");
        dbugprinttok(item);
        dbugprinttok(list);
    }

    item->link = list;

    return item;
}

/* nconc concatenates two token lists, destructively, by making the last link
   of lista point to listb.
   (nconc '(a b) '(c d e))  =  (a b c d e)  */
/* nconc is useful for putting together two fieldlist groups to
   make them into a single list in a record declaration. */
TOKEN nconc(TOKEN lista, TOKEN listb)
{
    if (DEBUG && DB_CONS)
    {
        printf("nconc\n");
        printf(" LISTA:\n");
        dbugplist(lista);
        printf(" LISTB:\n");
        dbugplist(listb);
    }

    TOKEN tok = lista;
    while (lista->link != NULL)
        lista = lista->link;

    lista->link = listb;

    return tok;
}

/* reduce binary operator */
TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)
{  
    if (DEBUG && DB_OPS)
    {
        printf("binop\n");
        dbugprinttok(op);
        dbugprinttok(lhs);
        dbugprinttok(rhs);
    }

    /* Coerce operands as needed, also set the op's
        datatype to represent the value of it's result
        to more easily decide how to coerce nested
        operations. */
    op->datatype = INTEGER;

    /* If the operation is anything except an assign, then we
        should always coerce integers to float if the other
        operand is a float. If this is the case, the result
        of the op will also be a float. */
    if (op->whichval != ASSIGNOP)
    {
        if (lhs->datatype == REAL || rhs->datatype == REAL)
        {
            op->datatype = REAL;

            if (lhs->datatype != REAL)
                lhs = makefloat(lhs);
            if (rhs->datatype != REAL)
                rhs = makefloat(rhs);
        }
    }
    
    else if (lhs->tokentype == OPERATOR && lhs->whichval == AREFOP)
    {
        if (DEBUG && DB_REFASGN)
        {
            ppexpr(lhs);
            db_symtype(lhs, "binop");
            printf("lhs->symtype->datatype: %s\n", lhs->symtype->datatype->namestring);
        }
        
        if (rhs->tokentype != OPERATOR)
        {
            if (lhs->symtype->datatype->basicdt == REAL && rhs->datatype != REAL)
            {
                if (DEBUG && DB_REFASGN) printf("result should be real\n");
                rhs->datatype = REAL;
                rhs->realval = (float) rhs->intval;
            }
        }
        
        op->operands = lhs;          /* link operands to operator       */
        lhs->link = rhs;             /* link second operand to first    */
        rhs->link = NULL;            /* terminate operand list          */

        if (DEBUG && DB_REFASGN) ppexpr(op);

        return op;
    }

    /* If the operation is an ASSIGNOP then we check the type of
        the variable being assigned to, and coerce the rhs if it
        is different. */
    else
    {
        if (lhs->tokentype != OPERATOR)
            lhs = findid(lhs);

        if (lhs->datatype == INTEGER && rhs->datatype == REAL)
        {
            op->datatype = INTEGER;
            rhs = makefix(rhs);
        }

        else if (lhs->datatype == REAL && rhs->datatype == INTEGER)
        {
            op->datatype = REAL;
            rhs = makefloat(rhs);
        }
    }

    /* Result of these operands is always a boolean */
    if ((op->whichval >= 6 && op->whichval <= 11)
        || op->whichval >= 14 && op->whichval <= 16)
        op->datatype = BOOLETYPE;

    /* Link the operation together */
    op->operands = lhs;          /* link operands to operator       */
    lhs->link = rhs;             /* link second operand to first    */
    rhs->link = NULL;            /* terminate operand list          */

    return op;
}

TOKEN unaryop(TOKEN op, TOKEN lhs)
{
    if (DEBUG && DB_OPS)
    {
        printf("unaryop\n");
        dbugprinttok(op);
        dbugprinttok(lhs);
    }

    op->operands = lhs;
    op->datatype = lhs->datatype;
    lhs->link = NULL;

    return op;
}

TOKEN makeop(int opnum)
{
    if (DEBUG && DB_MAKE) printf("makeop\n");

    TOKEN tok = talloc();
    tok->tokentype = OPERATOR;
    tok->whichval = opnum;

    if (DEBUG && DB_MAKE)
    {
        printf(" result: ");
        dbugprinttok(tok);
    }

    return tok;
}

/* makefloat forces the item tok to be floating, by floating a constant
   or by inserting a FLOATOP operator */
TOKEN makefloat(TOKEN tok)
{
    if (DEBUG && DB_MAKE)
    {
        printf("makefloat\n");
        dbugprinttok(tok);
    }

    if (tok->tokentype == NUMBERTOK)
    {
        tok->datatype = REAL;
        tok->realval = (float) tok->intval;
        return tok;
    }
    if (tok->tokentype == OPERATOR)
    {
        tok->datatype = REAL;
        return tok;
    }

    TOKEN float_tok = makeop(FLOATOP);
    float_tok->operands = tok;

    return float_tok;
}

/* makefix forces the item tok to be integer, by truncating a constant
   or by inserting a FIXOP operator */
TOKEN makefix(TOKEN tok)
{
    if (DEBUG && DB_MAKE)
    {
        printf("makefix\n");
        dbugprinttok(tok);
    }

    if (tok->tokentype == NUMBERTOK)
    {
        tok->datatype = INTEGER;
        tok->intval = (int) tok->realval;
        return tok;
    }

    TOKEN fix_tok = makeop(FIXOP);
    fix_tok->operands = tok;

    return fix_tok;
}

TOKEN fillintc(TOKEN tok, int num)
{
    if (DEBUG && DB_NUMS) printf("fillintc\n");

    tok->tokentype = NUMBERTOK;
    tok->datatype = INTEGER;
    tok->intval = num;

    if (DEBUG && DB_NUMS) 
    {
        printf(" result: ");
        dbugprinttok(tok);
    }

    return tok;
}

TOKEN makeintc(int num)
{
    if (DEBUG && DB_NUMS) printf("makeintc\n");

    TOKEN tok = talloc();
    tok->tokentype = NUMBERTOK;
    tok->datatype = INTEGER;
    tok->intval = num;

    if (DEBUG && DB_NUMS) 
    {
        printf(" result: ");
        dbugprinttok(tok);
    }

    return tok;
}

TOKEN copytok (TOKEN origtok)
{
    if (DEBUG && DB_CLEARTOK)
    {
        printf("copytok\n");
        dbugprinttok(origtok);
    }

    TOKEN tok = talloc();

    tok->tokentype = origtok->tokentype;
    tok->datatype = origtok->datatype;
    tok->symtype = origtok->symtype;
    tok->symentry = origtok->symentry;
    tok->operands = origtok->operands;
    tok->link = origtok->link;
    tok->tokenval = origtok->tokenval;

    return tok;
}

TOKEN makeif(TOKEN tok, TOKEN expr, TOKEN thenpart, TOKEN elsepart)
{  
    if (DEBUG && DB_MAKEIF)
    {
        printf("makeif\n");
        printf(" IF:\n");
        dbugprintexpr(expr);
        printf(" THEN:\n");
        dbugprinttok(thenpart);
        if (elsepart != NULL) printf(" ELSE:\n");
        dbugprinttok(elsepart);
    }

    tok->tokentype = OPERATOR;  /* Make it look like an operator   */
    tok->whichval = IFOP;
    if (elsepart != NULL) elsepart->link = NULL;
    thenpart->link = elsepart;
    expr->link = thenpart;
    tok->operands = expr;

    return tok;
}

TOKEN makeprogn(TOKEN tok, TOKEN statements)
{  
    if (DEBUG && DB_MAKEPROGN)
    {
        printf("makeprogn\n");
        printf(" PROGN: \n");
        pplist(statements);
    }

    tok->tokentype = OPERATOR;
    tok->whichval = PROGNOP;
    tok->operands = statements;

    return tok;
}

/* makepnb is like makeprogn, except that if statements is already a progn,
   it just returns statements.  This is optional. */
TOKEN makepnb(TOKEN tok, TOKEN statements)
{
    if (DEBUG && DB_MAKEPROGN)
    {
        printf("makepnb\n");
        pplist(statements);
    }

    if (statements->tokentype == OPERATOR && statements->whichval == PROGNOP)
    {
        if (DEBUG && DB_MAKEPROGN) printf(" Returning statements.\n");
        return statements;
    }

    if (DEBUG && DB_MAKEPROGN)
    {
        printf(" Making PROGNOP.\n");
    }
    return makeprogn(tok, statements);
}

/* appendst makes a progn containing statements followed by more */
TOKEN appendst(TOKEN statements, TOKEN more)
{
    TOKEN tok = talloc();

    tok->tokentype = OPERATOR;
    tok->whichval = PROGNOP;

    nconc(statements, more);

    tok->operands = statements;

    return tok;
}

/* dogoto is the action for a goto statement.
   tok is a (now) unused token that is recycled. */
TOKEN dogoto(TOKEN tok, TOKEN labeltok) // TODO: why doesn't last goto statement show up in output?
{
    tok->tokentype = OPERATOR;
    tok->whichval = GOTOOP;
    tok->operands = labeltok;

    int i;
    for (i = 0; i < 100; i++)
    {
        if (labeltable[i] == labeltok->intval)
        {
            labeltok->intval = i;
            break;
        }
    }

    return tok;
}

TOKEN makelabel()
{
    if (DEBUG && DB_MAKE)
    {
        printf("makelabel\n");
        printf(" labelnumber: %d\n", labelnumber);
    }

    TOKEN tok = makeop(LABELOP);
    tok->operands = makeintc(labelnumber++);

    return tok;
}

/* dolabel is the action for a label of the form   <number>: <statement>
   tok is a (now) unused token that is recycled. */
TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement)
{
    if (DEBUG && DB_LABEL)
    {
        printf("\ndolabel starting...\n");
        dbugprinttok(labeltok);
        ppexpr(statement);
        dbugplist(statement);
    }

    TOKEN progn_tok = talloc();
    progn_tok = makeprogn(progn_tok, tok);
    
    int i;
    for (i = 0; i < 100; i++)
    {
        if (labeltable[i] == labeltok->intval)
        {
            labeltok->intval = i;
            break;
        }
    }

    tok->tokentype = OPERATOR;
    tok->whichval = LABELOP;
    tok->operands = labeltok;
    tok->link = statement;

    if (DEBUG && DB_LABEL)
    {
        ppexpr(statement->link);
        printf("now returning from dolabel\n");
    }
    return progn_tok;
}

/* instlabel installs a user label into the label table */
void  instlabel (TOKEN num)
{
    if (DEBUG && DB_LABEL)
    {
        printf("\ninstlabel starting...\n");
        dbugprinttok(num);
    }
    labeltable[labelnumber++] = num->intval;
}

/* makegoto makes a GOTO operator to go to the specified label.
   The label number is put into a number token. */
TOKEN makegoto(int label)
{
    TOKEN tok = talloc();
    TOKEN num_tok = talloc();

    tok->tokentype = OPERATOR;
    tok->whichval = GOTOOP;
    tok->operands = num_tok;

    num_tok->tokentype = NUMBERTOK;
    num_tok->datatype = INTEGER;
    num_tok->intval = label;

    return tok;
}

/* settoktype sets up the type fields of token tok.
   typ = type pointer, ent = symbol table entry of the variable  */
void  settoktype(TOKEN tok, SYMBOL typ, SYMBOL ent)
{
    tok->datatype = typ->basicdt;
    tok->symtype = typ;
    tok->symentry = ent;
}

/* install variables in symbol table */
void instvars(TOKEN idlist, TOKEN typetok)
{
    typetok = typetok;
    if (DEBUG && DB_CONDVAR)
    {
        printf("instvars\n");
        dbprsymbol(typetok->symtype);
    }

    SYMBOL sym, typesym;
    int align;
    
    typesym = typetok->symtype;
    align = alignsize(typesym);
    while (idlist != NULL)
    {
        sym = insertsym(idlist->stringval);
        sym->kind = VARSYM;
        sym->offset = wordaddress(blockoffs[blocknumber], align);
        sym->size = typesym->size;
        blockoffs[blocknumber] = sym->offset + sym->size;
        sym->datatype = typesym;
        sym->basicdt = typesym->basicdt;
        idlist = idlist->link;
    }
}

/* makefuncall makes a FUNCALL operator and links it to the fn and args.
   tok is a (now) unused token that is recycled. */
TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args)
{
    if (DEBUG && DB_FUNCALL)
    {
        printf("\nmakefuncall beginning...\n");
        db_symtype(args, "makefuncall");
        dbugprinttok(tok);
        dbugprinttok(fn);
        dbugprinttok(args);
    }
    // recycle tok into a funcall operator
    cleartok(tok);
    tok->tokentype = OPERATOR;
    tok->whichval = FUNCALLOP;
    tok->operands = fn;
    if (DEBUG && DB_FUNCALL) ppexpr(tok);

    // if the function name is "new" then we must go into a special case
    if (strcmp(fn->stringval, "new") == 0)
    {
        if (DEBUG && DB_FUNCALL) printf("\"new\" function case\n");
        fn->link = makeintc(args->symtype->datatype->datatype->size);
        TOKEN newfunc = binop(makeop(ASSIGNOP), args, tok);
        if (DEBUG && DB_FUNCALL) ppexpr(newfunc);
        return newfunc;
    }
    
    if (strcmp(fn->stringval, "writeln") == 0 && args->symtype != NULL)
    {
        if (DEBUG && DB_FUNCALL) printf("\twriteln detected: %s\n", fn->stringval);
        if (DEBUG && DB_FUNCALL) dbprsymbol(args->symtype);
        //if (DEBUG) dbprsymbol(args->symtype->datatype);
        
        if (args->symtype->kind == BASICTYPE && args->symtype->basicdt == INTEGER)
            strcpy(fn->stringval, "writelni");

        else if (strcmp(args->symtype->datatype->namestring, "real") == 0)
        {
            strcpy(fn->stringval, "writelnf");
        }
        else if (args->tokentype == OPERATOR && args->whichval == AREFOP)
        {
            if (args->operands->link->tokentype == OPERATOR && args->operands->whichval == POINTEROP)
            {
                strcpy(fn->stringval, "writelnf");
            }
        }
        else if (args->symtype->basicdt == INTEGER)
        {
            strcpy(fn->stringval, "writelni");
        }
    }

    SYMBOL sym = searchst(fn->stringval);
    if (sym->datatype == NULL)
        fn->datatype = -1;
    else
        fn->datatype = sym->datatype->basicdt;

    tok->datatype = fn->datatype;

    fn->link = args;

    return tok;
}

/* makeprogram makes the tree structures for the top-level program */
TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements)
{  
    TOKEN tok = (TOKEN) talloc();

    tok->tokentype = OPERATOR;
    tok->whichval = PROGRAMOP;
    tok->operands = cons(name, cons(args, statements));

    if (DEBUG && DB_MAKEPROGN)
    {
        printf("makeprogram\n");
        dbugprinttok(tok);
        dbugprinttok(statements);
        dbugprinttok(statements->operands);
    }

    return tok;
}

/* makewhile makes structures for a while statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement)
{
    tok->tokentype = OPERATOR;
    tok->whichval = PROGNOP;

    tokb->tokentype = OPERATOR;
    tokb->whichval = IFOP;
    tokb->operands = expr;
    expr->link = statement;

    TOKEN goto_tok = makeop(GOTOOP);

    tok->operands = makelabel();
    tok->operands->link = tokb;

    TOKEN last_stat = statement->operands;
    if (last_stat->link != NULL)
    {
        while (last_stat->link != NULL)
            last_stat = last_stat->link;
    }
    last_stat->link = goto_tok;
    goto_tok->operands = tok->operands->operands;

    return tok;
}


/* makerepeat makes structures for a repeat statement.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr)
{
    /* Smash or create necessary tokens */
    tok->tokentype = OPERATOR;
    tok->whichval = PROGNOP;

    tokb->tokentype = OPERATOR;
    tokb->whichval = IFOP;

    TOKEN goto_tok = makeop(GOTOOP);

    /* Create tree structure by pointing to correct operands/links */
    tok->operands = makelabel();
    tok->operands->link = statements;

    if (DEBUG && DB_LOOP)
    {
        printf("makerepeat\n");
        TOKEN db_stats = statements;

        dbugprinttok(statements);

        while (db_stats->link != NULL)
        {
            db_stats = db_stats->link;
            dbugprinttok(db_stats);
            dbugprinttok(db_stats->operands);
        }
    }
    
    TOKEN last_stat = statements;
    if (last_stat->link != NULL)
    {
        while (last_stat->link != NULL)
            last_stat = last_stat->link;
    }
    last_stat->link = tokb;

    tokb = makeif(tokb, expr, makeop(PROGNOP), goto_tok);
/*    tokb->operands = expr;
    tokb->operands->link = makeop(PROGNOP);
    tokb->operands->link->link = goto_tok;*/

    goto_tok->operands = tok->operands->operands;

    return tok;
}

/* makefor makes structures for a for statement.
   sign is 1 for normal loop, -1 for downto.
   asg is an assignment statement, e.g. (:= i 1)
   endexpr is the end expression
   tok, tokb and tokc are (now) unused tokens that are recycled. */
TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr, TOKEN tokc, TOKEN statement)
{
    /* Smash or create necessary tokens */

    /* Root of our structure */
    tok->tokentype = OPERATOR;
    tok->whichval = PROGNOP;
    
    /* Label that we will place just before the loop test */
    tokb->tokentype = OPERATOR;
    tokb->whichval = LABELOP;

    /* Goto that will be at the very end of the structure,
        so that we can return to the label and test again */
    tokc->tokentype = OPERATOR;
    tokc->whichval = GOTOOP;
    
    /* New operator tokens for constructing the IF test and
        the loop varaible iteration procedure */
    TOKEN if_tok = makeop(IFOP);
    TOKEN le_tok = makeop(LEOP);
    TOKEN inc_tok = makeop(ASSIGNOP);
    TOKEN plus_tok = makeop(PLUSOP);
    
    /* Start linking together the tokens of the for loop
        intermediate code representation, beginning with setting
        the initial assignment to be the operands of our newly
        created progn operator token */
    tok->operands = asg;

    /* tokb is our label */
    asg->link = tokb;

    /* Create a label just above the loop test and link
        it to the IFOP */
    tokb->operands = makeintc(labelnumber++);
    tokb->link = if_tok;

    /* Attach the testing expression to the IFOP */
    if_tok->operands = le_tok;

    /* Create a copy of the loop variable so that we can
        set new operands and link for it */
    TOKEN i_copy_tok = copytok(asg->operands);
    i_copy_tok->operands = NULL;
    i_copy_tok->link = endexpr;

    /* Set up the expression used for testing */
    le_tok->operands = i_copy_tok;
    
    if(statement->tokentype == OPERATOR && statement->whichval == PROGNOP)
        le_tok->link = statement;
    else
    {
        le_tok->link = makeop(PROGNOP);
        le_tok->link->operands = statement;
    }

    /* If the statement we were passed is a PROGNOP then we need to
        attach the end of loop procedures to the very end of its operand
        list to ensure all of its statements are run before we start a
        new iteration. If it is not a PROGNOP then we can simply attach
        to the link of the given statement. */
    if (statement->tokentype == OPERATOR && statement->whichval == PROGNOP)
        nconc(statement->operands, inc_tok);
    else
        statement->link = inc_tok;

    /* Make another copy of the loop variable */
    i_copy_tok = copytok(asg->operands);
    i_copy_tok->operands = NULL;
    i_copy_tok->link = plus_tok;

    /* Construct an i++ procedure */
    inc_tok->operands = i_copy_tok;
    inc_tok->link = tokc;
    plus_tok->operands = copytok(asg->operands);
    plus_tok->operands->link = makeintc(1);

    /* We are done with this iteration and are ready
        to return to the beginning of the loop */
    tokc->operands = tokb->operands;

    if (DEBUG && DB_LOOP)
    {
        printf("makefor\n");
        ppexpr(tok);
    }
    
    return tok;
}

/* findid finds an identifier in the symbol table, sets up symbol table
   pointers, changes a constant to its number equivalent */
TOKEN findid(TOKEN tok)
{
    if (DEBUG && DB_FINDID)
    {
        printf("findid\n");
        dbugprinttok(tok);
    }
    
    SYMBOL sym, typ;

    sym = searchst(tok->stringval);
    if (sym->kind == CONSTSYM) 
        if (sym->basicdt == INTEGER)
            return fillintc(tok, sym->constval.intnum);
        else if (sym->basicdt == REAL)
        {
            tok->tokentype = NUMBERTOK;
            tok->datatype = REAL;
            tok->realval = sym->constval.realnum;
            return tok;
        }
    typ = sym->datatype;
    
    tok->symentry = sym;
    tok->symtype = typ;
    
    if (typ->kind == BASICTYPE || typ->kind == POINTERSYM)
        tok->datatype = typ->basicdt;

    return tok;
}

/* instconst installs a constant in the symbol table */
void instconst(TOKEN idtok, TOKEN consttok)
{
    if (DEBUG && DB_CONDVAR)
    {
        printf("instconst\n");
        printf(" ID:\n");
        dbugprinttok(idtok);
        printf(" CONSTANT:\n");
        dbugprinttok(consttok);
    }

    SYMBOL sym;

    sym = insertsym(idtok->stringval);
    sym->kind = CONSTSYM;
    sym->basicdt = consttok->datatype;

    if (consttok->datatype == INTEGER)
    {
        sym->constval.intnum = consttok->intval;
    }

    else if (consttok->datatype == REAL)
    {
        sym->constval.realnum = consttok->realval;
    }

    else if (consttok->datatype == STRINGTYPE)
    {
        strcpy(sym->constval.stringconst, consttok->stringval);
    }
}

/* makesubrange makes a SUBRANGE symbol table entry, puts the pointer to it
   into tok, and returns tok. */
TOKEN makesubrange(TOKEN tok, int low, int high)
{
    SYMBOL sym = symalloc();
    strcpy(sym->namestring, "subrange");
    sym->kind = SUBRANGE;
    sym->basicdt = INTEGER;
    sym->lowbound = low;
    sym->highbound = high;
    sym->size = basicsizes[INTEGER];

    tok->symtype = sym;
    return tok;
}

/* instenum installs an enumerated subrange in the symbol table,
   e.g., type color = (red, white, blue)
   by calling makesubrange and returning the token it returns. */
TOKEN instenum(TOKEN idlist)
{
    TOKEN consttok = talloc();
    consttok->datatype = INTEGER;

    int sum = 0;
    while (idlist != NULL)
    {
        consttok->intval = sum;
        instconst(idlist, consttok);
        sum++;
        idlist = idlist->link;
    }

    TOKEN tok = talloc();
    return makesubrange(tok, 0, sum-1);
}

/* instdotdot installs a .. subrange in the symbol table.
   dottok is a (now) unused token that is recycled. */
TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok)
{
    dottok = makesubrange(dottok, lowtok->intval, hightok->intval);
    dottok->tokentype = DELIMITER;
    dottok->whichval =  DOTDOT;

    return dottok;
}

/* findtype looks up a type name in the symbol table, puts the pointer
   to its type into tok->symtype, returns tok. */
TOKEN findtype(TOKEN tok)
{
    if (DEBUG && DB_FIND)
    {
        printf("findtype\n");
        dbugprinttok(tok);
    }

    tok->symtype = searchst(tok->stringval);
    
    if (DEBUG && DB_FIND) dbprsymbol(tok->symtype);
    
    return tok;
}

int wordaddress(int n, int wordsize)
{
    return ((n + wordsize - 1) / wordsize) * wordsize;
}

/* insttype will install a type name in symbol table.
   typetok is a token containing symbol table pointers. */
void insttype(TOKEN typename, TOKEN typetok)
{
    if (DEBUG && DB_INSTALL)
    {
        printf("insttype\n");
        dbugprinttok(typename);
        dbugprinttok(typetok);
    }
    
    SYMBOL typesym = typetok->symtype;

    SYMBOL sym = searchins(typename->stringval);
    sym->kind = TYPESYM;
    sym->datatype = typesym;
    sym->size = typesym->size;
}

/* instpoint will install a pointer type in symbol table */
TOKEN instpoint(TOKEN tok, TOKEN typename)
{
    if (DEBUG && DB_POINTERS)
    {
        printf("instpoint\n");
        dbugprinttok(tok);
        dbugprinttok(typename);
    }
    
    SYMBOL sym = searchins(typename->stringval);
    SYMBOL psym = symalloc();

    psym->kind = POINTERSYM;
    psym->datatype = sym;
    psym->size = basicsizes[POINTER];

    tok->tokentype = OPERATOR;
    tok->whichval = POINTEROP;
    tok->symtype = psym;
    tok->operands = typename;

    typename->tokentype = IDENTIFIER;
    return tok;
}

/* instrec will install a record definition.  Each token in the linked list
   argstok has a pointer its type. */
TOKEN instrec(TOKEN rectok, TOKEN argstok)
{
    if (DEBUG && DB_RECORD) printf("instrec\n");
    SYMBOL recsym = symalloc();
    recsym->kind = RECORDSYM;
    recsym->datatype = argstok->symentry;

    rectok->tokentype = RESERVED;
    rectok->symtype = recsym;
    rectok->whichval = RECORD;
    rectok->operands = argstok;

    int total_size = 0;

    TOKEN temp_list = argstok;
    while(temp_list->link != NULL)
    {
        temp_list->symentry->link = temp_list->link->symentry;
        temp_list->symentry->offset = total_size;
        if (DEBUG && DB_RECORD) dbprsymbol(temp_list->symentry);//printf("%s->offset: %d\n", temp_list->symentry->namestring, total_size);
        total_size += wordaddress(temp_list->symtype->size, 8);
        
        temp_list = temp_list->link;
    }
    
    temp_list->symentry->offset = total_size;
    total_size += temp_list->symtype->size;

    recsym->size = total_size;
    return rectok;
}

/* instfields will install type in a list idlist of field name tokens:
   re, im: real    put the pointer to REAL in the RE, IM tokens.
   typetok is a token whose symtype is a symbol table pointer.
   Note that nconc() can be used to combine these lists after instrec() */
TOKEN instfields(TOKEN idlist, TOKEN typetok)
{
    
    if (DEBUG && DB_RECORD)
    {
        printf("\ninstfields begin...\n");
        db_symtype(typetok, "instfields");
        dbugplist(idlist);
        dbugprinttok(typetok);
    }
    

    TOKEN temp_list = idlist;
    SYMBOL symlist = NULL;
    SYMBOL sym;

    while(temp_list != NULL)
    {
        sym = makesym(temp_list->stringval);
        sym->datatype = typetok->symtype;
        sym->size = typetok->symtype->size;
        //printf("\n\n%d\n\n", sym->size);

        temp_list->symentry = sym;
        temp_list->symtype = typetok->symtype;
        temp_list = temp_list->link;
    }

    temp_list = idlist;

    while(temp_list->link != NULL)
    {
        temp_list->symentry->link = temp_list->link->symentry;
        temp_list = temp_list->link;
    }
    
    if (DEBUG && DB_RECORD)
    {
        printf("-> instfields returning:\n");
        dbugplist(idlist);
    }
    return idlist;
}

/* makeplus makes a + operator.
   tok (if not NULL) is a (now) unused token that is recycled. */
TOKEN makeplus(TOKEN lhs, TOKEN rhs, TOKEN tok)
{
    tok->tokentype = OPERATOR;
    tok->whichval = PLUSOP;
    return binop(tok, lhs, rhs);
}

/* addint adds integer off to expression exp, possibly using tok */
TOKEN addint(TOKEN exp, TOKEN off, TOKEN tok)
{
    TOKEN lhs = exp->operands->link;
    if (lhs->tokentype == NUMBERTOK) addoffs(exp, off);
    else exp->operands->link = binop(makeop(PLUSOP), off, lhs);
    return exp;
}

/* addoffs adds offset, off, to an aref expression, exp */
TOKEN addoffs(TOKEN exp, TOKEN off)
{
    TOKEN lhs = exp->operands->link;
    if (lhs->tokentype == NUMBERTOK)
        exp->operands->link->intval += off->intval;
    else if (lhs->tokentype == OPERATOR && lhs->whichval == PLUSOP)
        exp->operands->link->operands->intval += off->intval;
    return exp;
}

/* mulint multiplies expression exp by integer n */
TOKEN mulint(TOKEN exp, int n)
{
    TOKEN lhs = exp->operands->link;
    if (lhs->tokentype == NUMBERTOK) lhs->intval = lhs->intval * n;
    else
    {
        exp->operands->link = binop(makeop(TIMESOP), makeintc(n), lhs);
    }

    return exp;
}

/* makearef makes an array reference operation.
   off is be an integer constant token
   tok (if not NULL) is a (now) unused token that is recycled. */
TOKEN makearef(TOKEN var, TOKEN off, TOKEN tok)
{
    if (DEBUG && DB_AREF)
    {
        printf("\nmakearef begin...\n");
        db_symtype(var, "makearef");
        dbugprinttok(var);
        dbprsymbol(var->symtype);
        dbugprinttok(off);
        dbugprinttok(tok);
    }
    
    if (var->tokentype == OPERATOR && var->whichval == AREFOP)
    {
        if (DEBUG && DB_ARRAY)
        {
            printf("makearef passed an aref!\n");
            ppexpr(var);
            dbugprinttok(var);
            dbugprinttok(off);
        }
        var->operands->link->intval += off->intval;
        return var;
    }
    
    tok->tokentype = OPERATOR;
    tok->whichval = AREFOP;
    tok->operands = var;
    tok->symtype = var->symtype;
    var->link = off;

    // if (var->tokentype == OPERATOR && var->whichval == POINTEROP)
    // {
    //     tok->datatype = REAL;
    // }
    if (DEBUG && DB_AREF)
    {
        printf("makearef is returning:\n");
        ppexpr(tok);
    }
    return tok;
}

/* reducedot handles a record reference.
   dot is a (now) unused token that is recycled. */
TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field)
{
    if (DEBUG && DB_AREF)
    {
        printf("\nreducedot begin...\n");
        db_symtype(var, "reducedot");
        db_symtype(field, "reducedot");
        
        dbugprinttok(var);
        if (var->tokentype == OPERATOR) ppexpr(var); 
        
        dbugprinttok(dot);
        dbugprinttok(field);
    }
    
    SYMBOL typesym = var->symtype;

    // get the symbol representing the type of the variable
    // that was provided, and find it's RECORDSYM
    if (DEBUG && DB_AREF) printf("Searching for RECORDSYM...\n");
    while (typesym->kind != RECORDSYM)
    {
        if (DEBUG && DB_AREF)
        {
            printf("\t");
            dbprsymbol(typesym);
        }
        typesym = typesym->datatype;
    }
    
    // make pointer representing the first field of the record
    SYMBOL fieldsym = typesym->datatype;
    
    if (DEBUG && DB_AREF) printf("Searching for %s field...\n", field->stringval);
    do
    {
        if (DEBUG && DB_AREF)
        {
            printf("\t");
            dbprsymbol(fieldsym);
        }
       if (strcmp(field->stringval, fieldsym->namestring) == 0)
       {
           var->symtype = fieldsym;
           field = fillintc(field, fieldsym->offset);
           if (DEBUG && DB_AREF) printf("Match found!\n");
           break;
       }
       fieldsym = fieldsym->link;
    } while (fieldsym != NULL);
    
    if (field->tokentype != NUMBERTOK)
    {
        printf("REDUCE DOT ERROR \n");
        db_symtype(var, "reducedot");
        
        dbugprinttok(var);
        if (var->tokentype == OPERATOR) ppexpr(var); 
        
        dbugprinttok(dot);
        dbugprinttok(field);
    }
    return makearef(var, field, dot);
}

/* arrayref processes an array reference a[i]
   subs is a list of subscript expressions.
   tok and tokb are (now) unused tokens that are recycled. */
TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb)
{
    if (DEBUG && DB_ARRAY) 
    {
        printf("\narrayref begin...\n");
        db_symtype(arr, "arrayref");
        db_symtype(subs, "arrayref");
        printf("\n");
    }
    
    SYMBOL arrsym = arr->symtype;
    SYMBOL subsym = subs->symtype;
    SYMBOL arrentry = arr->symentry;
    int arrbase = arr->symentry->offset;

    if (DEBUG && DB_ARRAY)
    {
        while (arrentry != NULL)
        {
            printf("-----\narrentry: %s\n", arrentry->namestring);
            printf("size: %d\n", arrentry->size);
            arrentry = arrentry->datatype;
        }
        
        printf("\tarrbase: %d \n", arrbase);
    }
    // Make our base aref expression to build on
    tok->tokentype = OPERATOR;
    tok->whichval = AREFOP;
    tok->symtype = arrsym;
    tok->operands = arr;
    arr->link = copytok(subs);
    arr->link->link = NULL;

    // store size and type of this element
    SYMBOL dtype = arrsym->datatype;
    SYMBOL elemtype = arr->symentry->datatype->datatype;
    //do 
    //{
    if (DEBUG && DB_ARRAY)
    {   
        printf("\tarray of elements of type: %s\n", dtype->namestring);
        printf("\tfrom [%d..%d]\n", arrsym->lowbound, arrsym->highbound);
        printf("\teach of size: %d\n", dtype->size);
        if (subs->tokentype == NUMBERTOK) printf("\tindex: %d\n", subs->intval);
        else if (subs->tokentype == IDENTIFIERTOK) printf("\tindex: %s\n", subs->stringval);
        else printf("index: error\n");
    }

    if (DEBUG && DB_ARRAY) ppexpr(tok);

    tok = mulint(tok, elemtype->size);

    if (DEBUG && DB_ARRAY) ppexpr(tok);

    tok = addint(tok, makeintc(-arrsym->lowbound * elemtype->size), NULL);

    if (DEBUG && DB_ARRAY) ppexpr(tok);

    if (DEBUG && DB_ARRAY)
    {  
        printf("subs->link = %p\n", subs->link);
        printf("elemtype->datatype = %p\n", elemtype->datatype);
    }

    subs = subs->link;
    elemtype = elemtype->datatype;

    while (subs != NULL)
    {
        if (DEBUG && DB_ARRAY)
        { 
            printf("elem: ");
            printtok(subs);
            printf("\n");
            printf("size: %d\n", elemtype->size);
        }

        tok = addoffs(tok, makeintc(elemtype->size));

        elemtype = elemtype->datatype;
        subs = subs->link;
    }


    if (DEBUG && DB_ARRAY) ppexpr(tok);

    return tok;
}

/* dopoint handles a ^ operator.
   tok is a (now) unused token that is recycled. */
TOKEN dopoint(TOKEN var, TOKEN tok)
{
    if (DEBUG && DB_POINTERS)
    {
        printf("dopoint begin...\n");
        db_symtype(var, "dopoint");
        dbugprinttok(var);
        ppexpr(var);
        dbugprinttok(tok);
    }
    
    // recycle tok into a pointerop
    tok->tokentype = OPERATOR;
    tok->whichval = POINTEROP;
    
    // operator's type should equal its result's type
/*
    printf("dopoint getting type\n");
    dbprsymbol(var->symtype);
    dbprsymbol(var->symtype->datatype);
    dbprsymbol(var->symtype->datatype->datatype);
*/
    tok->symtype = var->symtype->datatype;
    
    // the pointerop uses the var as it's operand
    tok->operands = var;
    
    if (DEBUG && DB_POINTERS)
    {
        printf("dopoint is returning:\n");
        db_symtype(tok, "dopoint");
        ppexpr(tok);
    }
    return tok;
}

/* instarray installs an array declaration into the symbol table.
   bounds points to a SUBRANGE symbol table entry.
   The symbol table pointer is returned in token typetok. */
TOKEN instarray(TOKEN bounds, TOKEN typetok)
{
    if (DEBUG && DB_ARRAY) 
    {
        printf("\ninstarray begin...\n");
        db_symtype(typetok, "instarray");
        
        dbugprinttok(bounds);
        pplist(bounds);
        
        dbugprinttok(bounds);
    }
    
    SYMBOL arrsym = symalloc();
    SYMBOL bsym = bounds->symtype;
    SYMBOL typesym = typetok->symtype;

    arrsym->kind = ARRAYSYM;
    strcpy(arrsym->namestring, "array");
    arrsym->datatype = typetok->symtype;
    arrsym->size = (bsym->highbound - bsym->lowbound + 1) * typesym->size;
    arrsym->lowbound = bsym->lowbound;
    arrsym->highbound = bsym->highbound;

    if (bounds->link != NULL)
    {
        SYMBOL arrsym2 = symalloc();
        SYMBOL bsym2 = bounds->link->symtype;
        if (bsym2->kind == TYPESYM)
            bsym2 = bsym2->datatype;

        strcpy(arrsym2->namestring, "array");
        arrsym2->kind = ARRAYSYM;
        arrsym2->datatype = typetok->symtype;
        arrsym2->size = (bsym2->highbound - bsym2->lowbound + 1) * typesym->size;
        arrsym2->lowbound = bsym2->lowbound;
        arrsym2->highbound = bsym2->highbound;

        if (DEBUG && DB_ARRAY) printf("\n%d - %d\n", bsym2->lowbound, bsym2->highbound);

        arrsym->datatype = arrsym2;
        arrsym->size = (bsym->highbound - bsym->lowbound + 1) * arrsym2->size;
    }

    typetok->tokentype = RESERVED;
    typetok->whichval = ARRAY;
    typetok->symtype = arrsym;

    return typetok;
}

/* provides vision of which tokens are carrying a symtype pointer
   at the beginning (or end) of a function. */
void db_symtype(TOKEN tok, char* fn_name)
{
    if (DEBUG && DB_SYMTYPE)
    {
        printf("  (dbug) symtype -> %s: ", fn_name);
        if (tok->tokentype == NUMBERTOK) printf("%d is a number with a null symtype\n", tok->intval);
        else if (tok->symtype == NULL) printf("%s has a null symtype\n", tok->stringval);
        else if (tok->symtype->namestring == NULL) printf("%s has a null name\n", tok->stringval);
        else printf("%s is of type %s\n", tok->stringval, tok->symtype->namestring);
    }
}

yyerror(s)
  char * s;
{ 
    fputs(s,stderr); putc('\n',stderr);
}

main()
{ 
    int res;
    initsyms();
    res = yyparse();
    //printf("yyparse result = %8d\n", res);
    //printst();
    //if (DEBUG & DB_PARSERES)
    //dbugprinttok(parseresult);
    //ppexpr(parseresult);           /* Pretty-print the result tree */
    //printstlevel(1);
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
}
