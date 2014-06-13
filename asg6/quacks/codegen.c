/* codgen.c - Generate Assembly Code for x86 */

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
#include "symtab.h"
#include "genasm.h"
#include "codegen.h"

void genc(TOKEN code);

/* Set DEBUGGEN to 1 for debug printouts of code generation */
#define DEBUGGEN 0

int nextlabel;    /* Next available label number */
int stkframesize;   /* total stack frame size */

int regtable[4] = {0};
int fregtable[16] = {0};
int jumptable[] = {JE, JNE, JL, JLE, JGE, JG};

/* Top-level entry for code generator.
   pcode    = pointer to code:  (program foo (output) (progn ...))
   varsize  = size of local storage in bytes
   maxlabel = maximum label number used so far

Add this line to the end of your main program:
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
The generated code is printed out; use a text editor to extract it for
your .s file.
         */

void gencode(TOKEN pcode, int varsize, int maxlabel)
{
    TOKEN name, code;
    name = pcode->operands;
    code = name->link->link;
    nextlabel = maxlabel + 1;
    stkframesize = asmentry(name->stringval,varsize);
    genc(code);
    asmexit(name->stringval);
}

/* Trivial version: always returns RBASE + 0 */
/* Get a register.   */
/* Need a type parameter or two versions for INTEGER or REAL */
int getreg(int kind)
{
    int i = 0;

    if (kind == WORD)
    {
        for (i = 0; i <= (RMAX-RBASE); i++)
        {
            //printf("getreg[i] = %d\n", regtable[i]);
            if (regtable[i] == 0)
            {
                regtable[i] = 1;
                //printf("returning %d\n", i);
                return i;
            }
        }
        printf("ERROR: ran out of int registers...\n");
    }

    if (kind == FLOAT)
    {
        for (i = 0; i <= (FMAX-FBASE); i++)
        {
            if (fregtable[i] == 0)
            {
                fregtable[i] = 1;
                //printf("returning %d\n", i + 8);
                return i + 8;
            }
        }
        printf("ERROR: ran out of float registers...\n");
    }
}

void clearreg()
{
    int i = 0;
    for (i = 0; i <= (RMAX-RBASE); i++)
        regtable[i] = 0;

    for (i = 0; i <= (FMAX-FBASE); i++)
        fregtable[i] = 0;
}

void unused(int reg)
{
    if (reg < 8)
        regtable[reg] = 0;
    else
        fregtable[reg - 8] = 0;
}

void used(int reg)
{
    if (reg < 8)
        regtable[reg] = 1;
    else
        fregtable[reg - 8] = 1;
}

int savereg()
{
    int i = 0;
    int sum = 0;
    for (i = 0; i <= (FMAX-FBASE); i++)
    {
        if (fregtable[i] == 1)
        {
            asmsttemp(i + 8);
            fregtable[i] = 0;
            sum++;
        }
    }
    return sum;
}

void restorereg(int num)
{
    int i = 0;
    for (i = 0; i < num; i++)
        asmldtemp(getreg(FLOAT));
}

int funcallin(TOKEN code)
{
    if (code->tokentype == OPERATOR
        && code->whichval == FUNCALLOP)
        return 1;
    else
        return 0;
}

int genbinop(int op, TOKEN lhs, TOKEN rhs)
{
    int reg = genarith(lhs);
    int reg2 = genarith(rhs);
    if (funcallin(lhs) && funcallin(rhs))
        reg = FBASE+1;
    if (reg > 7 || reg2 > 7)
        op += 9;
    asmrr(op, reg2, reg);
    unused(reg2);
    return reg;
}

int moveop(TOKEN code)
{
    //dbugprinttok(code);
    if (code->tokentype == IDENTIFIERTOK)
        return MOVQ;
    if (code->datatype == INTEGER)
        return MOVL;
    else
        return MOVSD;
}

/* Trivial version */
/* Generate code for arithmetic expression, return a register number */
int genarith(TOKEN code)
{
    TOKEN tok;
    SYMBOL sym;
    int num, offs, used_regs;
    float fnum;
    int reg = 0;
    int reg2 = 0;
    if (DEBUGGEN) 
    {
        printf("genarith\n");
        dbugprinttok(code); 
    };

    switch ( code->tokentype )
    { 
        case NUMBERTOK:
           switch (code->datatype)
            { 
                case INTEGER:
                    num = code->intval;
                    reg = getreg(WORD);
                    if ( num >= MINIMMEDIATE && num <= MAXIMMEDIATE )
                    {
                        asmimmed(MOVL, num, reg);
                    }
                    break;

                case REAL:
                    reg = getreg(FLOAT);
                    fnum = code->realval;
                    makeflit(fnum, nextlabel);
                    asmldflit(MOVSD, nextlabel, reg);
                    nextlabel++;
                    break;
            }
            break;

            case IDENTIFIERTOK:
                offs = code->symentry->offset - stkframesize;
                sym = code->symentry;
                if (sym->datatype != NULL)
                {
                    if (sym->datatype->datatype != NULL)
                    {
                        if (sym->datatype->datatype->kind == POINTERSYM)
                            reg = getreg(WORD);
                            asmld(MOVQ, offs, reg, code->stringval);
                            break;
                    }
                }
                switch (code->datatype)
                {
                    case INTEGER:
                        reg = getreg(WORD);
                        asmld(MOVL, offs, reg, code->stringval);
                        break;

                    case REAL:
                        reg = getreg(FLOAT);
                        asmld(MOVSD, offs, reg, code->stringval);
                        break;
                }
                break;
            
            case OPERATOR:
                switch (code->whichval)
                {
                    case PLUSOP:
                        tok = code->operands;
                        reg = genbinop(ADDL, tok, tok->link);
                        break;

                    case MINUSOP:
                        tok = code->operands;

                        if (code->operands->link == NULL)
                        {
                            reg = genarith(tok);
                            reg2 = getreg(FLOAT);
                            asmfneg(reg, reg2);
                            unused(reg2);
                        }

                        else
                            reg = genbinop(SUBL, tok, tok->link);

                        break;

                    case TIMESOP:
                        tok = code->operands;
                        reg = genbinop(IMULL, tok, tok->link);
                        break;

                    case DIVIDEOP:
                        tok = code->operands;
                        reg = genbinop(DIVL, tok, tok->link);
                        break;

                    case EQOP:
                    case NEOP:
                    case LTOP:
                    case LEOP:
                    case GEOP:
                    case GTOP:
                        reg = genarith(code->operands);
                        reg2 = genarith(code->operands->link);
                        asmrr(CMPL, reg2, reg);
                        unused(reg);
                        unused(reg2);
                        break;

                    case FLOATOP:
                        reg = genarith(code->operands);
                        reg2 = getreg(FLOAT);
                        asmfloat(reg, reg2);
                        unused(reg);
                        return reg2;
                        break;

                    case FIXOP:
                        reg = genarith(code->operands);
                        reg2 = getreg(WORD);
                        asmfix(reg, reg2);
                        unused(reg);
                        return reg2;
                        break;

                    case FUNCALLOP:
                        tok = code->operands;
                        used_regs = savereg();

                        reg = genarith(code->operands->link);
                        
                        if ((strcmp(tok->stringval, "new") == 0) && reg != EDI)
                        {
                            asmrr(MOVL, reg, EDI);
                            unused(reg);
                        }

                        asmcall(code->operands->stringval);
                        restorereg(used_regs);
                        break;

                    case GOTOOP:
                        asmjump(JMP, code->operands->intval);
                        break;

                    case AREFOP:
                        printf("genarith arefop\n");
                        reg = genarith(code->operands);

                        if (code->operands->link->tokentype == NUMBERTOK)
                        {
                            asmstr(MOVL, EAX, code->operands->link->intval, ECX, "^. ");
                        }
                        else
                            reg2 = genarith(code->operands->link);

                        break;

                    case POINTEROP:
                        offs = 0;
                        //dbugprinttok(code->operands);
                        //dbprsymbol(code->operands->symentry);

                        if (code->operands->symentry != NULL)
                            offs = code->operands->symentry->offset - stkframesize;

                        asmld(MOVQ, offs, getreg(WORD), code->operands->stringval);
                        break;

                }
                break;

            case STRINGTOK:
                makeblit(code->stringval, nextlabel);
                asmlitarg(nextlabel, EDI);
                nextlabel++;
                break;
    }
    
    return reg;
}


/* Generate code for a Statement from an intermediate-code form */
void genc(TOKEN code)
{  
    TOKEN tok, lhs, rhs;
    int reg, offs, op;
    int lbl_then, lbl_else;
    SYMBOL sym;
    
    if (DEBUGGEN)
    {
        printf("genc\n");
        dbugprinttok(code);
    }
    
    if ( code->tokentype != OPERATOR )
    { 
        printf("Bad code token");
        dbugprinttok(code);
    }

    clearreg();
    
    switch ( code->whichval )
    {   
        case PROGNOP:
            tok = code->operands;
            while ( tok != NULL )
            {  
                genc(tok);
                tok = tok->link;
            }
            break;
        
        case ASSIGNOP:                   /* Trivial version: handles I := e */
            lhs = code->operands;
            rhs = lhs->link;
            reg = genarith(rhs);              /* generate rhs into a register */

            if (lhs->tokentype == IDENTIFIERTOK)
            {
                sym = lhs->symentry;              /* assumes lhs is a simple var  */
                offs = sym->offset - stkframesize; /* net offset of the var   */
            
                op = MOVL;

                if (reg < 8)
                {
                    if (sym->datatype != NULL && sym->datatype->datatype != NULL)
                    {
                        if (sym->datatype->datatype->kind == POINTERSYM)
                            op = MOVQ;
                    }

                    asmst(op, reg, offs, lhs->stringval);
                    unused(reg);
                }    
                    
                else
                {
                    asmst(MOVSD, reg, offs, lhs->stringval);
                    unused(reg);
                }
            }

            else
            {
                //printf("genc arefop\n");
                reg = genarith(lhs->operands);

                if (lhs->operands->link->tokentype == NUMBERTOK)
                {
                    if (moveop(rhs) == MOVSD)
                        asmstr(MOVSD, XMM0, lhs->operands->link->intval, reg, "^. ");
                    else
                    {
                        asmstr(moveop(rhs), EAX, lhs->operands->link->intval, ECX, "^. ");
                        unused(EAX);
                    }
                }
                else
                    genarith(lhs->operands->link);

                break;
            }

            break;

        case GOTOOP:
            asmjump(JMP, code->operands->intval);
            break;

        case LABELOP:
            asmlabel(code->operands->intval);
            break;

        case IFOP:
            tok = code->operands;
            lhs = tok->operands;
            rhs = lhs->link;
            
            reg = genarith(tok);

            lbl_then = nextlabel++;
            lbl_else = nextlabel++;

            asmjump(jumptable[tok->whichval-6], lbl_then);
            
            if (tok->link->link != NULL)
            {
                genc(tok->link->link);
                tok->link->link = NULL;
            }

            asmjump(JMP, lbl_else);

            asmlabel(lbl_then);
            genc(tok->link);

            asmlabel(lbl_else);
            break;

        case FUNCALLOP:
            tok = code->operands;

            reg = genarith(tok->link);
            if ((strcmp(tok->stringval, "new") == 0) && reg != EDI)
            {
                asmrr(MOVL, reg, EDI);
                unused(reg);
            }
            asmcall(tok->stringval);
            break;
    }
}
