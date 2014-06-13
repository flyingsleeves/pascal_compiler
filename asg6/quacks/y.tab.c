/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "parse.y"
     /* parse.y    Pascal Parser */

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



/* Line 268 of yacc.c  */
#line 101 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     STRING = 259,
     NUMBER = 260,
     PLUS = 261,
     MINUS = 262,
     TIMES = 263,
     DIVIDE = 264,
     ASSIGN = 265,
     EQ = 266,
     NE = 267,
     LT = 268,
     LE = 269,
     GE = 270,
     GT = 271,
     POINT = 272,
     DOT = 273,
     AND = 274,
     OR = 275,
     NOT = 276,
     DIV = 277,
     MOD = 278,
     IN = 279,
     COMMA = 280,
     SEMICOLON = 281,
     COLON = 282,
     LPAREN = 283,
     RPAREN = 284,
     LBRACKET = 285,
     RBRACKET = 286,
     DOTDOT = 287,
     ARRAY = 288,
     BEGINBEGIN = 289,
     CASE = 290,
     CONST = 291,
     DO = 292,
     DOWNTO = 293,
     ELSE = 294,
     END = 295,
     FILEFILE = 296,
     FOR = 297,
     FUNCTION = 298,
     GOTO = 299,
     IF = 300,
     LABEL = 301,
     NIL = 302,
     OF = 303,
     PACKED = 304,
     PROCEDURE = 305,
     PROGRAM = 306,
     RECORD = 307,
     REPEAT = 308,
     SET = 309,
     THEN = 310,
     TO = 311,
     TYPE = 312,
     UNTIL = 313,
     VAR = 314,
     WHILE = 315,
     WITH = 316
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING 259
#define NUMBER 260
#define PLUS 261
#define MINUS 262
#define TIMES 263
#define DIVIDE 264
#define ASSIGN 265
#define EQ 266
#define NE 267
#define LT 268
#define LE 269
#define GE 270
#define GT 271
#define POINT 272
#define DOT 273
#define AND 274
#define OR 275
#define NOT 276
#define DIV 277
#define MOD 278
#define IN 279
#define COMMA 280
#define SEMICOLON 281
#define COLON 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define DOTDOT 287
#define ARRAY 288
#define BEGINBEGIN 289
#define CASE 290
#define CONST 291
#define DO 292
#define DOWNTO 293
#define ELSE 294
#define END 295
#define FILEFILE 296
#define FOR 297
#define FUNCTION 298
#define GOTO 299
#define IF 300
#define LABEL 301
#define NIL 302
#define OF 303
#define PACKED 304
#define PROCEDURE 305
#define PROGRAM 306
#define RECORD 307
#define REPEAT 308
#define SET 309
#define THEN 310
#define TO 311
#define TYPE 312
#define UNTIL 313
#define VAR 314
#define WHILE 315
#define WITH 316




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 265 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   187

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNRULES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    12,    18,    22,    23,    27,    29,    32,
      33,    36,    38,    43,    46,    47,    50,    52,    57,    59,
      62,    69,    73,    75,    79,    83,    87,    89,    93,    95,
      99,   102,   103,   106,   108,   113,   117,   119,   123,   127,
     133,   138,   145,   152,   157,   162,   165,   167,   171,   173,
     177,   179,   182,   183,   187,   191,   195,   199,   203,   207,
     211,   215,   217,   220,   224,   228,   232,   234,   238,   242,
     246,   250,   252,   256,   258,   263,   265,   267,   271,   274,
     279,   283,   285,   287,   289
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    51,     3,    28,    81,    29,    26,    64,
      18,    -1,    65,    67,    70,    78,    82,    -1,    46,     5,
      66,    -1,    -1,    25,     5,    66,    -1,    26,    -1,    36,
      68,    -1,    -1,    68,    69,    -1,    69,    -1,     3,    11,
      93,    26,    -1,    57,    71,    -1,    -1,    71,    72,    -1,
      72,    -1,     3,    11,    73,    26,    -1,    74,    -1,    17,
       3,    -1,    33,    30,    75,    31,    48,    73,    -1,    52,
      76,    40,    -1,     3,    -1,    28,    81,    29,    -1,     5,
      32,     5,    -1,    74,    25,    75,    -1,    74,    -1,    77,
      26,    76,    -1,    77,    -1,    81,    27,    73,    -1,    59,
      79,    -1,    -1,    79,    80,    -1,    80,    -1,    81,    27,
      73,    26,    -1,     3,    25,    81,    -1,     3,    -1,    34,
      82,    83,    -1,     5,    27,    82,    -1,    45,    87,    55,
      82,    85,    -1,    53,    84,    58,    87,    -1,    42,    86,
      56,    87,    37,    82,    -1,    42,    86,    56,    87,    38,
      82,    -1,    60,    87,    37,    82,    -1,     3,    28,    88,
      29,    -1,    44,     5,    -1,    86,    -1,    26,    82,    83,
      -1,    40,    -1,    82,    26,    84,    -1,    82,    -1,    39,
      82,    -1,    -1,    91,    10,    87,    -1,    88,    11,    88,
      -1,    88,    13,    88,    -1,    88,    16,    88,    -1,    88,
      12,    88,    -1,    88,    14,    88,    -1,    88,    15,    88,
      -1,    88,    24,    88,    -1,    88,    -1,     7,    88,    -1,
      88,     6,    89,    -1,    88,     7,    89,    -1,    88,    20,
      89,    -1,    89,    -1,    89,     8,    90,    -1,    89,     9,
      90,    -1,    89,    23,    90,    -1,    89,    19,    90,    -1,
      90,    -1,    28,    87,    29,    -1,    91,    -1,     3,    28,
      88,    29,    -1,    93,    -1,     3,    -1,    91,    18,     3,
      -1,    91,    17,    -1,    91,    30,    92,    31,    -1,    88,
      25,    92,    -1,    88,    -1,     5,    -1,     4,    -1,    47,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    47,    47,    50,    52,    53,    55,    56,    58,    59,
      61,    62,    64,    66,    67,    69,    70,    72,    74,    75,
      76,    77,    79,    80,    81,    83,    84,    86,    87,    89,
      91,    92,    94,    95,    97,    99,   100,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   113,   114,   116,
     117,   119,   120,   122,   124,   125,   126,   127,   128,   129,
     130,   131,   133,   134,   135,   136,   137,   139,   140,   141,
     142,   143,   145,   146,   147,   148,   150,   151,   152,   153,
     155,   156,   158,   159,   160
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "NUMBER", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "ASSIGN", "EQ", "NE", "LT", "LE", "GE", "GT",
  "POINT", "DOT", "AND", "OR", "NOT", "DIV", "MOD", "IN", "COMMA",
  "SEMICOLON", "COLON", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "DOTDOT", "ARRAY", "BEGINBEGIN", "CASE", "CONST", "DO", "DOWNTO", "ELSE",
  "END", "FILEFILE", "FOR", "FUNCTION", "GOTO", "IF", "LABEL", "NIL", "OF",
  "PACKED", "PROCEDURE", "PROGRAM", "RECORD", "REPEAT", "SET", "THEN",
  "TO", "TYPE", "UNTIL", "VAR", "WHILE", "WITH", "$accept", "program",
  "block", "lblock", "endlabel", "cblock", "c_asgn_list", "c_asgn",
  "tblock", "t_asgn_list", "t_asgn", "type", "simple_type", "s_type_list",
  "field_list", "field", "vblock", "v_asgn_list", "v_asgn",
  "identifier_list", "statement", "endpart", "statement_list", "endif",
  "assignment", "expr", "s_expr", "term", "factor", "variable",
  "s_expr_list", "constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    70,    70,    71,    71,    72,    73,    73,
      73,    73,    74,    74,    74,    75,    75,    76,    76,    77,
      78,    78,    79,    79,    80,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    84,
      84,    85,    85,    86,    87,    87,    87,    87,    87,    87,
      87,    87,    88,    88,    88,    88,    88,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    91,    91,    91,    91,
      92,    92,    93,    93,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     5,     3,     0,     3,     1,     2,     0,
       2,     1,     4,     2,     0,     2,     1,     4,     1,     2,
       6,     3,     1,     3,     3,     3,     1,     3,     1,     3,
       2,     0,     2,     1,     4,     3,     1,     3,     3,     5,
       4,     6,     6,     4,     4,     2,     1,     3,     1,     3,
       1,     2,     0,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     2,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     1,     4,     1,     1,     3,     2,     4,
       3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    36,     0,     0,     0,
      35,     5,     0,     0,     9,     0,     2,     0,    14,     0,
       7,     4,     0,     8,    11,     0,    31,     0,     0,    10,
       0,    13,    16,     0,     0,     6,    83,    82,    84,     0,
       0,    15,    30,    33,     0,    76,     0,     0,     0,     0,
       0,     0,     0,     3,    46,     0,    12,    22,     0,     0,
       0,     0,     0,     0,    18,    32,     0,     0,     0,     0,
      76,     0,    45,    76,     0,     0,     0,    61,    66,    71,
      73,    75,    50,     0,     0,     0,    78,     0,     0,     0,
      19,     0,     0,     0,    28,     0,    17,     0,     0,    38,
       0,    48,    37,     0,     0,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    77,    81,     0,    24,
      23,    26,     0,    21,     0,     0,    34,    44,     0,     0,
       0,    72,    52,    63,    64,    54,    57,    55,    58,    59,
      56,    65,    60,    67,    68,    70,    69,    49,    40,    43,
       0,    79,     0,     0,    27,    29,    47,     0,     0,    74,
       0,    39,    80,    25,     0,    41,    42,    51,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    13,    14,    21,    18,    23,    24,    26,    31,
      32,    63,    64,   132,    93,    94,    34,    42,    43,    44,
      82,   102,    83,   171,    54,    76,    77,    78,    79,    80,
     128,    81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -87
static const yytype_int16 yypact[] =
{
     -39,    12,    28,     9,   -87,    37,    17,    26,    37,    25,
     -87,    14,    57,    47,    34,    10,   -87,    71,    20,    80,
     -87,   -87,    76,    71,   -87,    93,    44,    10,     6,   -87,
      78,    93,   -87,    37,     4,   -87,   -87,   -87,   -87,    83,
      77,   -87,    37,   -87,    87,    85,    89,     4,   125,   132,
      16,     4,    16,   -87,   -87,   102,   -87,   -87,   108,   143,
      37,   124,    37,   129,   -87,   -87,    77,    16,     4,   -24,
     -87,   100,   -87,   130,    16,    16,   104,   111,   134,   -87,
      15,   -87,   135,   105,   123,    16,   -87,   159,    16,   160,
     -87,   137,    19,   127,   138,   141,   -87,   144,    23,   -87,
       4,   -87,   -87,    16,    16,   101,   140,     4,    22,    22,
      16,    16,    16,    16,    16,    16,    22,    16,    22,    22,
      22,    22,     4,    16,     4,   -87,   -87,    61,   142,   -87,
     -87,   146,   145,   -87,    37,    77,   -87,   -87,   -24,    46,
      86,   -87,   133,   134,   134,   101,   101,   101,   101,   101,
     101,   134,   101,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
      16,   -87,    19,   126,   -87,   -87,   -87,     4,     4,   -87,
       4,   -87,   -87,   -87,    77,   -87,   -87,   -87,   -87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   -87,   148,   -87,   -87,   154,   -87,   -87,
     147,   -63,   -86,    18,    45,   -87,   -87,   -87,   139,    -4,
     -29,    48,    60,   -87,   136,   -44,   -13,    36,    30,   -34,
      27,   155
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      55,     7,   100,    97,    10,    53,   131,    45,    84,    46,
      36,    37,     1,    55,    55,     3,   101,    55,    69,    73,
      36,    37,    57,    74,    58,    73,    36,    37,     4,   108,
     109,   106,    86,    87,    55,    19,    20,     5,    47,    99,
       6,   125,     8,   116,    75,    88,    48,    60,    49,    50,
      75,    11,   137,    38,    98,     9,    91,    51,    95,   139,
      12,   105,    15,    38,    52,    16,    55,   108,   109,    38,
      17,   138,   165,    55,    22,   127,   131,    25,   142,   158,
      57,   116,    58,   167,   168,    27,   160,    28,    55,    40,
      55,   140,   108,   109,    59,   159,    30,   145,   146,   147,
     148,   149,   150,    33,   152,    60,   116,   108,   109,    56,
      61,   178,    85,    67,    66,   169,    68,   108,   109,    86,
      87,   116,   110,   111,   112,   113,   114,   115,    70,    62,
      95,   116,    88,    55,    55,   117,    55,    72,   175,   176,
      89,   177,   118,   119,   143,   144,    90,   127,   153,   154,
     155,   156,   151,   120,    92,    96,   103,   121,   104,   107,
     124,   122,   126,   123,   134,   129,   130,   133,   135,   141,
     136,   162,   170,   161,   174,    35,   163,    29,    41,   164,
     173,    65,   157,    39,    71,     0,   166,   172
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-87))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      34,     5,    26,    66,     8,    34,    92,     3,    52,     5,
       4,     5,    51,    47,    48,     3,    40,    51,    47,     3,
       4,     5,     3,     7,     5,     3,     4,     5,     0,     6,
       7,    75,    17,    18,    68,    25,    26,    28,    34,    68,
       3,    85,    25,    20,    28,    30,    42,    28,    44,    45,
      28,    26,    29,    47,    67,    29,    60,    53,    62,   103,
      46,    74,     5,    47,    60,    18,   100,     6,     7,    47,
      36,   100,   135,   107,     3,    88,   162,    57,   107,   123,
       3,    20,     5,    37,    38,     5,    25,    11,   122,    11,
     124,   104,     6,     7,    17,   124,     3,   110,   111,   112,
     113,   114,   115,    59,   117,    28,    20,     6,     7,    26,
      33,   174,    10,    28,    27,    29,    27,     6,     7,    17,
      18,    20,    11,    12,    13,    14,    15,    16,     3,    52,
     134,    20,    30,   167,   168,    24,   170,     5,   167,   168,
      32,   170,     8,     9,   108,   109,     3,   160,   118,   119,
     120,   121,   116,    19,    30,    26,    56,    23,    28,    55,
      37,    26,     3,    58,    26,     5,    29,    40,    27,    29,
      26,    25,    39,    31,    48,    27,    31,    23,    31,   134,
     162,    42,   122,    28,    48,    -1,   138,   160
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    63,     3,     0,    28,     3,    81,    25,    29,
      81,    26,    46,    64,    65,     5,    18,    36,    67,    25,
      26,    66,     3,    68,    69,    57,    70,     5,    11,    69,
       3,    71,    72,    59,    78,    66,     4,     5,    47,    93,
      11,    72,    79,    80,    81,     3,     5,    34,    42,    44,
      45,    53,    60,    82,    86,    91,    26,     3,     5,    17,
      28,    33,    52,    73,    74,    80,    27,    28,    27,    82,
       3,    86,     5,     3,     7,    28,    87,    88,    89,    90,
      91,    93,    82,    84,    87,    10,    17,    18,    30,    32,
       3,    81,    30,    76,    77,    81,    26,    73,    88,    82,
      26,    40,    83,    56,    28,    88,    87,    55,     6,     7,
      11,    12,    13,    14,    15,    16,    20,    24,     8,     9,
      19,    23,    26,    58,    37,    87,     3,    88,    92,     5,
      29,    74,    75,    40,    26,    27,    26,    29,    82,    87,
      88,    29,    82,    89,    89,    88,    88,    88,    88,    88,
      88,    89,    88,    90,    90,    90,    90,    84,    87,    82,
      25,    31,    25,    31,    76,    73,    83,    37,    38,    29,
      39,    85,    92,    75,    48,    82,    82,    82,    73
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 48 "parse.y"
    { parseresult = makeprogram((yyvsp[(2) - (8)]), makeprogn((yyvsp[(3) - (8)]), (yyvsp[(4) - (8)])), (yyvsp[(7) - (8)])); }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 50 "parse.y"
    { (yyval) = (yyvsp[(5) - (5)]); }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 52 "parse.y"
    { instlabel((yyvsp[(2) - (3)])); }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 55 "parse.y"
    { instlabel((yyvsp[(2) - (3)])); }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 58 "parse.y"
    { (yyval) = NULL; }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 59 "parse.y"
    { (yyval) = NULL; }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 61 "parse.y"
    { (yyval) = NULL; }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 62 "parse.y"
    { (yyval) = NULL; }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 64 "parse.y"
    { instconst((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 66 "parse.y"
    { (yyval) = NULL; }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 69 "parse.y"
    { (yyval) = NULL; }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 70 "parse.y"
    { (yyval) = NULL; }
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 72 "parse.y"
    { insttype((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 74 "parse.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 75 "parse.y"
    { (yyval) = instpoint((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 76 "parse.y"
    { (yyval) = instarray((yyvsp[(3) - (6)]), (yyvsp[(6) - (6)])); }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 77 "parse.y"
    { (yyval) = instrec((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 79 "parse.y"
    { (yyval) = findtype((yyvsp[(1) - (1)])); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 80 "parse.y"
    { (yyval) = instenum((yyvsp[(2) - (3)])); }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 81 "parse.y"
    { (yyval) = instdotdot((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 83 "parse.y"
    { (yyval) = nconc((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 84 "parse.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 86 "parse.y"
    { (yyval) = nconc((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 87 "parse.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 89 "parse.y"
    { (yyval) = instfields((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 91 "parse.y"
    { (yyval) = NULL; }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 92 "parse.y"
    { (yyval) = NULL; }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 94 "parse.y"
    { (yyval) = NULL; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 95 "parse.y"
    { (yyval) = NULL; }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 97 "parse.y"
    { instvars((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 99 "parse.y"
    { (yyval) = cons((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 102 "parse.y"
    { (yyval) = makepnb((yyvsp[(1) - (3)]), cons((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]))); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 103 "parse.y"
    { (yyval) = dolabel((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 104 "parse.y"
    { (yyval) = makeif((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]), (yyvsp[(5) - (5)])); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 105 "parse.y"
    { (yyval) = makerepeat((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 106 "parse.y"
    { (yyval) = makefor(1, (yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])); }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 107 "parse.y"
    { (yyval) = makefor(-1, (yyvsp[(1) - (6)]), (yyvsp[(2) - (6)]), (yyvsp[(3) - (6)]), (yyvsp[(4) - (6)]), (yyvsp[(5) - (6)]), (yyvsp[(6) - (6)])); }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 108 "parse.y"
    { (yyval) = makewhile((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 109 "parse.y"
    { (yyval) = makefuncall((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 110 "parse.y"
    { (yyval) = dogoto((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 113 "parse.y"
    { (yyval) = cons((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 114 "parse.y"
    { (yyval) = NULL; }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 116 "parse.y"
    { (yyval) = cons((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 119 "parse.y"
    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 120 "parse.y"
    { (yyval) = NULL; }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 122 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 124 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 125 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 126 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 127 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 128 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 129 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 130 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 133 "parse.y"
    { (yyval) = unaryop((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 134 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 135 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 136 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 139 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 140 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 141 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 142 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 145 "parse.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 146 "parse.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 147 "parse.y"
    { (yyval) = makefuncall((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); }
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 150 "parse.y"
    { (yyval) = findid((yyvsp[(1) - (1)])); }
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 151 "parse.y"
    { (yyval) = reducedot((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 152 "parse.y"
    { (yyval) = dopoint((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 153 "parse.y"
    { (yyval) = arrayref((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 155 "parse.y"
    { (yyval) = cons((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 160 "parse.y"
    { (yyval) = fillintc((yyvsp[(1) - (1)]), 0); }
    break;



/* Line 1806 of yacc.c  */
#line 2142 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 163 "parse.y"


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

