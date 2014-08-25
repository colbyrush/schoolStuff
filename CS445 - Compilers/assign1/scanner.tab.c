/* A Bison parser, made by GNU Bison 3.0.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "scanner.y" /* yacc.c:339  */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "tokenStruct.h"
#include "tree.c"
#include "yyerror.cpp"
#define YYERROR_VERBOSE

  //
  extern int lineno;
  extern int yydebug;
  extern int yylex();
  extern FILE* yyin;
  static TreeNode *savedTree;
  int numErrors = 0;
  int numWarnings = 0;


#line 86 "scanner.tab.c" /* yacc.c:339  */

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "scanner.tab.h".  */
#ifndef YY_YY_SCANNER_TAB_H_INCLUDED
# define YY_YY_SCANNER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    NUMCONST = 259,
    CHARCONST = 260,
    STRINGCONST = 261,
    AND = 262,
    BREAK = 263,
    BOOL = 264,
    CHAR = 265,
    ELSE = 266,
    FALSE = 267,
    FOREACH = 268,
    IF = 269,
    IN = 270,
    INT = 271,
    OR = 272,
    NOT = 273,
    RETURN = 274,
    TRUE = 275,
    STATIC = 276,
    WHILE = 277,
    COMMA = 278,
    LBRACKET = 279,
    RBRACKET = 280,
    LPAREN = 281,
    RPAREN = 282,
    LBRACE = 283,
    RBRACE = 284,
    SEMI = 285,
    EQUIV = 286,
    NEQ = 287,
    LEQ = 288,
    LESSER = 289,
    GEQ = 290,
    GREATER = 291,
    ASSIGN = 292,
    PASSIGN = 293,
    MASSIGN = 294,
    DEC = 295,
    INC = 296,
    COLON = 297,
    PLUS = 298,
    MINUS = 299,
    DIVIDE = 300,
    MOD = 301,
    MULTI = 302
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 23 "scanner.y" /* yacc.c:355  */

   ExpType type;
   TokenData *tokenData;
   TreeNode *tNode;

#line 180 "scanner.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SCANNER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 195 "scanner.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1673

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  162
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  309

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    59,    73,    74,    78,    79,    83,    97,
     101,   112,   113,   126,   142,   158,   159,   163,   164,   165,
     169,   170,   171,   175,   176,   181,   182,   183,   187,   188,
     189,   190,   191,   192,   196,   197,   201,   214,   215,   219,
     229,   233,   248,   249,   250,   254,   255,   256,   257,   261,
     262,   263,   264,   268,   269,   270,   271,   275,   276,   277,
     281,   294,   298,   311,   312,   316,   317,   318,   322,   323,
     324,   325,   326,   327,   328,   329,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   346,   347,   348,   352,   356,
     376,   396,   416,   417,   418,   419,   420,   421,   422,   423,
     427,   447,   448,   449,   453,   473,   474,   475,   479,   480,
     481,   485,   486,   487,   488,   492,   493,   494,   495,   496,
     497,   501,   502,   503,   504,   508,   509,   514,   515,   516,
     517,   521,   522,   523,   527,   528,   529,   533,   534,   538,
     539,   543,   544,   545,   546,   550,   551,   552,   553,   554,
     558,   559,   560,   564,   565,   569,   584,   585,   589,   590,
     591,   592,   593
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUMCONST", "CHARCONST",
  "STRINGCONST", "AND", "BREAK", "BOOL", "CHAR", "ELSE", "FALSE",
  "FOREACH", "IF", "IN", "INT", "OR", "NOT", "RETURN", "TRUE", "STATIC",
  "WHILE", "COMMA", "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "LBRACE",
  "RBRACE", "SEMI", "EQUIV", "NEQ", "LEQ", "LESSER", "GEQ", "GREATER",
  "ASSIGN", "PASSIGN", "MASSIGN", "DEC", "INC", "COLON", "PLUS", "MINUS",
  "DIVIDE", "MOD", "MULTI", "$accept", "program", "declarationlist",
  "declaration", "vardeclaration", "scopedvardeclaration", "vardecllist",
  "vardeclinitialize", "vardeclid", "scopedtypespecifier", "typespecifier",
  "fundeclaration", "params", "paramlist", "paramtypelist", "paramidlist",
  "paramid", "statement", "sstatement", "compoundstmt",
  "localdeclarations", "statementlist", "expressionstmt",
  "matchedselectionstmt", "unmatchedselectionstmt", "returnstmt",
  "breakstmt", "expression", "simpleexpression", "andexpression",
  "unaryrelexpression", "relexpression", "relop", "additiveexpression",
  "sumop", "term", "mulop", "unaryexpression", "unaryop", "factor",
  "mutable", "immutable", "call", "args", "arglist", "constant", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302
};
# endif

#define YYPACT_NINF -210

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-210)))

#define YYTABLE_NINF -155

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     172,   -20,    -6,  -210,  -210,  -210,    35,   125,  -210,  -210,
      51,  -210,   730,    15,  -210,   -20,  -210,   148,    59,    25,
    -210,    -3,  1456,    84,  -210,  -210,  -210,    74,  -210,    93,
     116,   158,    58,   150,  -210,   126,   888,   583,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,   399,   444,  -210,  -210,   166,
     190,   210,  -210,  -210,   206,   189,  -210,  1278,  -210,   609,
    -210,  -210,  -210,   133,   130,   185,   194,  -210,   217,    20,
    -210,   160,   102,   217,  -210,   916,  1252,   212,  -210,   832,
     489,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,   944,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  1288,  1314,  1340,
     972,   860,  -210,   145,  1000,   242,  1626,  -210,  -210,  1549,
    -210,   232,  1028,  1549,   229,  -210,   195,  -210,  -210,  -210,
    1056,  1252,  1350,  1376,  1402,   226,  -210,   944,  1084,   944,
     944,  -210,  -210,   730,   205,   161,   255,   243,  -210,   730,
     205,   276,  -210,   272,   277,  -210,   278,   272,   279,  -210,
    1580,   190,  1626,  -210,  -210,  1518,  -210,   280,   282,  -210,
     264,  1549,  -210,   201,   245,   112,   189,   226,  -210,  1549,
     291,  1518,   297,   305,   308,   318,  1580,     1,  -210,  -210,
    -210,  1580,     6,  -210,   656,   205,  -210,   254,   260,   693,
    1603,   210,  -210,   201,   245,   112,   189,   226,  -210,  -210,
    1549,  -210,  -210,  -210,  -210,  -210,   284,   330,    16,   294,
    -210,  -210,   730,  -210,   730,   944,  -210,   944,   767,  -210,
    -210,  1112,   804,   730,  1456,  -210,  -210,   254,   313,   100,
     113,   156,  -210,   316,  -210,   317,  -210,  -210,   316,  -210,
    -210,  -210,  -210,  -210,  1487,   315,   319,   320,  -210,  1580,
      10,  1425,  -210,   309,  -210,  -210,   176,  -210,  -210,  -210,
    -210,   536,   295,  1140,  1168,   730,    87,   730,  -210,   332,
     305,   329,  1580,    26,  1580,    33,  -210,  -210,   321,   323,
     324,   325,  -210,  -210,  -210,  1112,   767,   767,   730,   298,
    1196,  1224,    52,   336,   305,   337,  1580,    79,  1580,    80,
     767,   767,  1112,   804,    87,   105,   354,    87,    87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,    26,    27,    25,     0,     0,     4,     6,
       0,     7,     0,     0,     1,     0,     3,     0,    20,     0,
      15,    17,     0,   141,   158,   159,   160,     0,   162,     0,
       0,     0,     0,     0,   161,     0,     0,     0,    66,   137,
     138,    33,    71,    54,    53,     0,     0,    55,    56,     0,
      94,   101,   105,   109,   112,   122,   128,     0,   135,     0,
     139,   146,   147,     0,     0,     0,    34,    37,     0,     0,
       9,     0,     0,     0,     8,     0,     0,     0,   144,     0,
       0,    58,    67,   119,   120,   115,   116,   118,   117,     0,
      98,    97,   125,   126,   132,   133,   131,     0,     0,     0,
       0,     0,    88,     0,     0,     0,   110,   108,   140,    87,
      85,     0,     0,   148,     0,    63,    63,    51,    52,    65,
       0,     0,     0,     0,     0,   136,   134,     0,     0,     0,
       0,    93,    92,     0,     0,    40,    45,    39,    42,     0,
       0,    20,    16,     0,     0,    22,     0,    31,     0,    14,
      19,    18,     0,   106,   102,     0,   156,     0,   153,    84,
       0,     0,    95,     0,   113,     0,   123,     0,   129,   143,
       0,   152,     0,    75,   141,     0,    72,     0,   107,   149,
      86,    74,     0,   145,     0,     0,    60,     0,     0,     0,
     103,   100,   104,   114,   111,   124,   121,   130,   127,    99,
      96,    89,    90,    91,    32,    38,     0,     0,     0,     0,
      29,    36,     0,    21,     0,     0,   151,     0,     0,   142,
     150,     0,     0,     0,    64,    59,    62,     0,     0,     0,
       0,     0,    57,     0,    43,     0,    48,    46,    44,    41,
      30,    28,   157,   155,     0,     0,     0,     0,    73,     0,
       0,     0,    76,     0,    69,    78,     0,    10,    11,    13,
      47,     0,     0,     0,     0,     0,     0,     0,    12,     0,
      75,     0,    72,     0,    74,     0,    70,    79,     0,     0,
       0,     0,    80,    68,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    83,     0,    81,     0,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -210,  -210,  -210,   362,  -210,  -210,  -176,     9,  -210,  -210,
       8,  -210,    97,  -210,   -60,  -210,   -11,   -12,  -210,  -210,
    -210,   259,  -210,   -78,  -209,  -210,  -210,   -14,   -72,   241,
     -27,  -210,   327,   -88,   -44,   -85,   -49,   -53,  -210,  -210,
     -31,  -210,  -210,   285,  -210,  -210
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,   186,    19,    20,    21,   187,
      64,    11,    65,    66,    67,   137,   138,   159,    42,    43,
     116,   184,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    97,    54,    98,    55,    99,    56,    57,    58,
      59,    60,    61,   157,   158,    62
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,   108,   160,   151,   126,   107,   124,    12,    10,   164,
     123,   229,   231,   166,   255,    10,    63,   236,   120,   111,
      13,   143,   114,   120,     3,     4,   108,   120,   222,     3,
       4,     5,   177,   223,   194,    14,     5,   265,   196,    75,
     182,   237,   -35,   120,   108,   108,   168,   -35,    73,   153,
     120,   256,    17,   286,    18,    74,   277,   282,   284,   106,
     287,    23,    24,    25,    26,   156,   108,   108,   108,   120,
      28,   198,   175,   108,   205,   162,    32,   142,    34,   300,
     211,   108,   149,    71,    36,    72,   170,   156,   278,   108,
     108,   108,   108,   108,   192,   255,   120,   120,   277,   284,
     279,   280,    39,   147,   102,    40,   303,   304,   100,   281,
     101,     3,     4,   199,   201,   202,   203,   124,     5,   103,
     123,   204,   120,    73,   188,    -2,    15,   210,     2,   -35,
     257,   135,   307,   136,     3,     4,    68,    78,    79,   179,
     248,     5,   104,   258,   253,   254,   173,   124,   174,   250,
     123,   109,   112,    23,    24,    25,    26,    94,    95,    96,
     133,   145,    28,   134,   146,   105,   144,    31,    32,   148,
      34,    68,   226,     1,    69,     2,    36,   226,    70,    73,
     110,     3,     4,   269,   206,   207,   259,   276,     5,   283,
     108,   273,   275,   227,    39,   234,   119,    40,   239,    73,
     240,   242,   241,   243,     3,     4,   268,   120,   293,   254,
     252,     5,   139,   292,     3,     4,   185,   121,   297,   299,
     141,     5,   276,   283,   140,   306,    78,    79,   179,   154,
     305,   271,   108,   108,    94,    95,    96,    83,    84,    85,
      86,    87,    88,   178,    92,    93,    94,    95,    96,    92,
      93,    78,    79,   179,   108,   228,   183,   141,   295,   108,
     108,   230,   180,   141,   -49,   117,   209,   -49,   -49,   -49,
     -49,   108,   -49,   -49,   -49,   218,   -49,   -49,   -49,   208,
     -49,   -49,   -49,   -49,   -49,   233,   -49,   136,    92,    93,
     -49,   252,   -49,   -49,   -49,   238,   270,   136,   174,   294,
      71,   174,   134,   213,   212,   217,   214,   216,   -49,   -49,
     117,   -49,   -49,   -49,   -49,   -49,   219,   -49,   -49,   -49,
     267,   -49,   -49,   -49,   220,   -49,   -49,   -49,   -49,   -49,
      78,   -49,   100,   221,   235,   -49,    68,   -49,   -49,   -49,
     207,   262,   260,   218,   285,   263,   264,   301,   288,   289,
     290,   291,   302,   -49,   -49,   117,   -49,   -49,   -49,   -49,
     -49,   191,   -49,   -49,   -49,   308,   -49,   -49,   -49,    16,
     -49,   -49,   -49,   -49,   -49,   189,   -49,     0,     0,     0,
     -49,   122,   -49,   -49,   -49,     0,   172,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -49,   -49,
     117,   -49,   -49,   -49,   -49,   -49,     0,   -49,   -49,   -49,
       0,   -49,   -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,
       0,   -49,     0,     0,     0,   -49,     0,   -49,   -49,   -49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -49,   -50,   118,   -49,   -50,   -50,   -50,
     -50,     0,   -50,   -50,   -50,     0,   -50,   -50,   -50,     0,
     -50,   -50,   -50,   -50,   -50,     0,   -50,     0,     0,     0,
     -50,     0,   -50,   -50,   -50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -50,     0,
      22,   -50,    23,    24,    25,    26,  -149,    27,     0,     0,
       0,    28,    29,    30,     0,     0,    31,    32,    33,    34,
       0,    35,     0,     0,     0,    36,     0,    37,     0,    38,
    -149,  -149,  -149,  -149,  -149,  -149,     0,     0,     0,     0,
       0,     0,  -149,    39,  -149,  -149,    40,   244,     0,    23,
      24,    25,    26,  -149,    27,     0,     0,     0,    28,   245,
     246,     0,     0,    31,    32,    33,    34,     0,   247,     0,
       0,     0,    36,     0,    37,     0,    38,  -149,  -149,  -149,
    -149,  -149,  -149,     0,     0,     0,     0,     0,     0,  -149,
      39,  -149,  -149,    40,   115,     0,   -61,   -61,   -61,   -61,
       0,   -61,   -61,   -61,     0,   -61,   -61,   -61,     0,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,     0,     0,     0,   -61,
     127,   -61,   -61,   -61,     0,     0,  -140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -140,   -61,     0,     0,
     -61,     0,  -140,     0,  -140,     0,  -140,     0,     0,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,   128,   129,   130,   131,
     132,     0,  -140,  -140,  -140,  -140,  -140,   224,     0,    23,
      24,    25,    26,     0,    27,     0,     0,     0,    28,    29,
      30,     0,     0,    31,    32,    33,    34,     0,    35,     0,
       0,     0,    36,     0,    37,   225,    38,     0,     0,     0,
       0,     0,     0,     0,   224,     0,    23,    24,    25,    26,
      39,    27,     0,    40,     0,    28,    29,    30,     0,     0,
      31,    32,    33,    34,     0,    35,     0,     0,     0,    36,
       0,    37,   232,    38,     0,     0,     0,     0,     0,     0,
       0,    22,     0,    23,    24,    25,    26,    39,    27,     0,
      40,     0,    28,    29,    30,     0,     0,    31,    32,    33,
      34,     0,    35,     0,     0,     0,    36,     0,    37,     0,
      38,     0,     0,     0,     0,     0,     0,     0,   244,     0,
      23,    24,    25,    26,    39,    27,     0,    40,     0,    28,
     245,   246,     0,     0,    31,    32,    33,    34,     0,   247,
       0,     0,     0,    36,     0,    37,     0,    38,     0,     0,
       0,     0,     0,     0,     0,   251,     0,    23,    24,    25,
      26,    39,    27,     0,    40,     0,    28,    29,    30,     0,
       0,    31,    32,    33,    34,     0,    35,     0,     0,     0,
      36,     0,    37,   155,    38,    23,    24,    25,    26,     0,
       0,     0,     0,     0,    28,     0,     0,     0,    39,    31,
      32,    40,    34,     0,     0,     0,     0,     0,    36,  -154,
       0,   171,     0,    23,    24,    25,    26,     0,     0,     0,
       0,     0,    28,     0,     0,     0,    39,    31,    32,    40,
      34,     0,     0,     0,     0,     0,    36,  -154,     0,   113,
       0,    23,    24,    25,    26,     0,     0,     0,     0,     0,
      28,     0,     0,     0,    39,    31,    32,    40,    34,     0,
       0,     0,     0,     0,    36,     0,     0,   150,     0,    23,
      24,    25,    26,     0,     0,     0,     0,     0,    28,     0,
       0,     0,    39,    31,    32,    40,    34,     0,     0,     0,
       0,     0,    36,     0,     0,   161,     0,    23,    24,    25,
      26,     0,     0,     0,     0,     0,    28,     0,     0,     0,
      39,    31,    32,    40,    34,     0,     0,     0,     0,     0,
      36,     0,     0,   169,     0,    23,    24,    25,    26,     0,
       0,     0,     0,     0,    28,     0,     0,     0,    39,    31,
      32,    40,    34,     0,     0,     0,     0,     0,    36,     0,
       0,   176,     0,    23,    24,    25,    26,     0,     0,     0,
       0,     0,    28,     0,     0,     0,    39,    31,    32,    40,
      34,     0,     0,     0,     0,     0,    36,     0,     0,   181,
       0,    23,    24,    25,    26,     0,     0,     0,     0,     0,
      28,     0,     0,     0,    39,    31,    32,    40,    34,     0,
       0,     0,     0,     0,    36,     0,     0,   190,     0,    23,
      24,    25,    26,     0,     0,     0,     0,     0,    28,     0,
       0,     0,    39,    31,    32,    40,    34,     0,     0,     0,
       0,     0,    36,     0,     0,   200,     0,    23,    24,    25,
      26,     0,     0,     0,     0,     0,    28,     0,     0,     0,
      39,    31,    32,    40,    34,     0,     0,     0,     0,     0,
      36,     0,     0,   249,     0,    23,    24,    25,    26,     0,
       0,     0,     0,     0,    28,     0,     0,     0,    39,    31,
      32,    40,    34,     0,     0,     0,     0,     0,    36,     0,
       0,   272,     0,    23,    24,    25,    26,     0,     0,     0,
       0,     0,    28,     0,     0,     0,    39,    31,    32,    40,
      34,     0,     0,     0,     0,     0,    36,     0,     0,   274,
       0,    23,    24,    25,    26,     0,     0,     0,     0,     0,
      28,     0,     0,     0,    39,    31,    32,    40,    34,     0,
       0,     0,     0,     0,    36,     0,     0,   296,     0,    23,
      24,    25,    26,     0,     0,     0,     0,     0,    28,     0,
       0,     0,    39,    31,    32,    40,    34,     0,     0,     0,
       0,     0,    36,     0,     0,   298,     0,    23,    24,    25,
      26,     0,     0,     0,     0,     0,    28,     0,     0,     0,
      39,    31,    32,    40,    34,     0,     0,     0,     0,     0,
      36,     0,     0,   152,     0,    23,    24,    25,    26,     0,
       0,     0,     0,     0,    28,     0,     0,     0,    39,     0,
      32,    40,    34,     0,     0,     0,     0,     0,    36,   125,
       0,    23,    24,    25,    26,     0,     0,     0,     0,   163,
      28,    23,    24,    25,    26,     0,    39,     0,    34,    40,
      28,     0,     0,     0,    36,     0,     0,     0,    34,     0,
       0,     0,     0,     0,    36,   165,     0,    23,    24,    25,
      26,     0,    39,     0,     0,    40,    28,     0,     0,     0,
       0,     0,    39,     0,    34,    40,     0,     0,     0,     0,
      36,   167,     0,    23,    24,    25,    26,     0,     0,     0,
       0,   193,    28,    23,    24,    25,    26,     0,    39,     0,
      34,    40,    28,     0,     0,     0,    36,     0,     0,     0,
      34,     0,     0,     0,     0,     0,    36,   195,     0,    23,
      24,    25,    26,     0,    39,     0,     0,    40,    28,     0,
       0,     0,     0,     0,    39,     0,    34,    40,     0,     0,
       0,     0,    36,   197,     0,    23,    24,    25,    26,     0,
       0,     0,     0,     0,    28,     0,     0,     0,     0,     0,
      39,     0,    34,    40,     0,     0,     0,     0,    36,     0,
       0,     0,    76,     0,     0,     0,   266,     0,     0,     0,
       0,     0,    77,     0,     0,     0,    39,     0,     0,    40,
      78,    79,    80,     0,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    76,     0,    90,    91,     0,    92,    93,
      94,    95,    96,    77,     0,     0,     0,     0,     0,     0,
       0,    78,    79,    80,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    76,     0,    90,    91,     0,    92,
      93,    94,    95,    96,    77,     0,     0,     0,     0,     0,
       0,     0,    78,    79,   261,     0,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    76,     0,    90,    91,     0,
      92,    93,    94,    95,    96,    77,     0,     0,     0,     0,
       0,   215,     0,    78,    79,   179,     0,     0,     0,    83,
      84,    85,    86,    87,    88,    89,    76,     0,    90,    91,
       0,    92,    93,    94,    95,    96,    77,     0,     0,     0,
       0,     0,     0,     0,    78,    79,   179,     0,     0,     0,
      83,    84,    85,    86,    87,    88,    89,    76,     0,    90,
      91,     0,    92,    93,    94,    95,    96,    77,     0,     0,
       0,     0,     0,     0,     0,    78,    79,   179,     0,     0,
      76,    83,    84,    85,    86,    87,    88,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,    96,    78,    79,
     179,     0,     0,     0,    83,    84,    85,    86,    87,    88,
       0,     0,     0,     0,     0,     0,    92,    93,    94,    95,
      96,    78,    79,   179,     0,     0,     0,    83,    84,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,    96
};

static const yytype_int16 yycheck[] =
{
      12,    32,    80,    75,    57,    32,    55,    27,     0,    97,
      54,   187,   188,    98,   223,     7,     1,     1,    17,    33,
      26,     1,    36,    17,     9,    10,    57,    17,    27,     9,
      10,    16,   104,    27,   122,     0,    16,    27,   123,    42,
     112,    25,    27,    17,    75,    76,    99,    27,    23,    76,
      17,   227,     1,    27,     3,    30,   265,   266,   267,     1,
      27,     3,     4,     5,     6,    79,    97,    98,    99,    17,
      12,   124,   103,   104,   134,    89,    18,    68,    20,    27,
     140,   112,    73,    24,    26,    26,   100,   101,     1,   120,
     121,   122,   123,   124,   121,   304,    17,    17,   307,   308,
      13,    14,    44,     1,    30,    47,    27,    27,    24,    22,
      26,     9,    10,   127,   128,   129,   130,   166,    16,    26,
     164,   133,    17,    23,   116,     0,     1,   139,     3,    27,
      30,     1,    27,     3,     9,    10,    23,    25,    26,    27,
     218,    16,    26,    30,   222,   223,     1,   196,     3,   221,
     194,     1,    26,     3,     4,     5,     6,    45,    46,    47,
      27,     1,    12,    30,     4,     7,    69,    17,    18,    72,
      20,    23,   184,     1,    26,     3,    26,   189,    30,    23,
      30,     9,    10,   261,    23,    24,    30,   265,    16,   267,
     221,   263,   264,   185,    44,   206,    30,    47,   209,    23,
     212,   215,   214,   217,     9,    10,    30,    17,   286,   287,
     222,    16,    27,   285,     9,    10,    21,     7,   290,   291,
       3,    16,   300,   301,    30,   303,    25,    26,    27,    17,
     302,   262,   263,   264,    45,    46,    47,    31,    32,    33,
      34,    35,    36,     1,    43,    44,    45,    46,    47,    43,
      44,    25,    26,    27,   285,     1,    27,     3,   289,   290,
     291,     1,    30,     3,     0,     1,    23,     3,     4,     5,
       6,   302,     8,     9,    10,    11,    12,    13,    14,    24,
      16,    17,    18,    19,    20,     1,    22,     3,    43,    44,
      26,   303,    28,    29,    30,     1,     1,     3,     3,     1,
      24,     3,    30,    25,    27,    23,    27,    27,    44,     0,
       1,    47,     3,     4,     5,     6,    25,     8,     9,    10,
      11,    12,    13,    14,    27,    16,    17,    18,    19,    20,
      25,    22,    24,    15,     4,    26,    23,    28,    29,    30,
      24,    26,    25,    11,    15,    26,    26,    11,    27,    26,
      26,    26,    15,    44,     0,     1,    47,     3,     4,     5,
       6,   120,     8,     9,    10,    11,    12,    13,    14,     7,
      16,    17,    18,    19,    20,   116,    22,    -1,    -1,    -1,
      26,    54,    28,    29,    30,    -1,   101,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,     0,
       1,    47,     3,     4,     5,     6,    -1,     8,     9,    10,
      -1,    12,    13,    14,    -1,    16,    17,    18,    19,    20,
      -1,    22,    -1,    -1,    -1,    26,    -1,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,     0,     1,    47,     3,     4,     5,
       6,    -1,     8,     9,    10,    -1,    12,    13,    14,    -1,
      16,    17,    18,    19,    20,    -1,    22,    -1,    -1,    -1,
      26,    -1,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
       1,    47,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    13,    14,    -1,    -1,    17,    18,    19,    20,
      -1,    22,    -1,    -1,    -1,    26,    -1,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,     1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    17,    18,    19,    20,    -1,    22,    -1,
      -1,    -1,    26,    -1,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,     1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    10,    -1,    12,    13,    14,    -1,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    26,
       1,    28,    29,    30,    -1,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    44,    -1,    -1,
      47,    -1,    23,    -1,    25,    -1,    27,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,     1,    -1,     3,
       4,     5,     6,    -1,     8,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    17,    18,    19,    20,    -1,    22,    -1,
      -1,    -1,    26,    -1,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
      44,     8,    -1,    47,    -1,    12,    13,    14,    -1,    -1,
      17,    18,    19,    20,    -1,    22,    -1,    -1,    -1,    26,
      -1,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    44,     8,    -1,
      47,    -1,    12,    13,    14,    -1,    -1,    17,    18,    19,
      20,    -1,    22,    -1,    -1,    -1,    26,    -1,    28,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,    44,     8,    -1,    47,    -1,    12,
      13,    14,    -1,    -1,    17,    18,    19,    20,    -1,    22,
      -1,    -1,    -1,    26,    -1,    28,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    44,     8,    -1,    47,    -1,    12,    13,    14,    -1,
      -1,    17,    18,    19,    20,    -1,    22,    -1,    -1,    -1,
      26,    -1,    28,     1,    30,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    44,    17,
      18,    47,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    44,    17,    18,    47,
      20,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,     1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    44,    17,    18,    47,    20,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    44,    17,    18,    47,    20,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      44,    17,    18,    47,    20,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    44,    17,
      18,    47,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    44,    17,    18,    47,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,     1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    44,    17,    18,    47,    20,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    44,    17,    18,    47,    20,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      44,    17,    18,    47,    20,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    44,    17,
      18,    47,    20,    -1,    -1,    -1,    -1,    -1,    26,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    44,    17,    18,    47,
      20,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,     1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    44,    17,    18,    47,    20,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    44,    17,    18,    47,    20,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,     1,    -1,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      44,    17,    18,    47,    20,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,     1,    -1,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    44,    -1,
      18,    47,    20,    -1,    -1,    -1,    -1,    -1,    26,     1,
      -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,     1,
      12,     3,     4,     5,     6,    -1,    44,    -1,    20,    47,
      12,    -1,    -1,    -1,    26,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    26,     1,    -1,     3,     4,     5,
       6,    -1,    44,    -1,    -1,    47,    12,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    20,    47,    -1,    -1,    -1,    -1,
      26,     1,    -1,     3,     4,     5,     6,    -1,    -1,    -1,
      -1,     1,    12,     3,     4,     5,     6,    -1,    44,    -1,
      20,    47,    12,    -1,    -1,    -1,    26,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    26,     1,    -1,     3,
       4,     5,     6,    -1,    44,    -1,    -1,    47,    12,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    20,    47,    -1,    -1,
      -1,    -1,    26,     1,    -1,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    20,    47,    -1,    -1,    -1,    -1,    26,    -1,
      -1,    -1,     7,    -1,    -1,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    44,    -1,    -1,    47,
      25,    26,    27,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,     7,    -1,    40,    41,    -1,    43,    44,
      45,    46,    47,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,     7,    -1,    40,    41,    -1,    43,
      44,    45,    46,    47,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    37,     7,    -1,    40,    41,    -1,
      43,    44,    45,    46,    47,    17,    -1,    -1,    -1,    -1,
      -1,    23,    -1,    25,    26,    27,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,     7,    -1,    40,    41,
      -1,    43,    44,    45,    46,    47,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,     7,    -1,    40,
      41,    -1,    43,    44,    45,    46,    47,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    27,    -1,    -1,
       7,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    25,    26,
      27,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    25,    26,    27,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     9,    10,    16,    49,    50,    51,    52,
      58,    59,    27,    26,     0,     1,    51,     1,     3,    54,
      55,    56,     1,     3,     4,     5,     6,     8,    12,    13,
      14,    17,    18,    19,    20,    22,    26,    28,    30,    44,
      47,    65,    66,    67,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    81,    83,    85,    86,    87,    88,
      89,    90,    93,     1,    58,    60,    61,    62,    23,    26,
      30,    24,    26,    23,    30,    42,     7,    17,    25,    26,
      27,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      40,    41,    43,    44,    45,    46,    47,    80,    82,    84,
      24,    26,    30,    26,    26,     7,     1,    78,    88,     1,
      30,    75,    26,     1,    75,     1,    68,     1,     1,    30,
      17,     7,    80,    82,    84,     1,    85,     1,    37,    38,
      39,    40,    41,    27,    30,     1,     3,    63,    64,    27,
      30,     3,    55,     1,    60,     1,     4,     1,    60,    55,
       1,    76,     1,    78,    17,     1,    75,    91,    92,    65,
      71,     1,    75,     1,    81,     1,    83,     1,    85,     1,
      75,     1,    91,     1,     3,    88,     1,    76,     1,    27,
      30,     1,    76,    27,    69,    21,    53,    57,    58,    69,
       1,    77,    78,     1,    81,     1,    83,     1,    85,    75,
       1,    75,    75,    75,    65,    62,    23,    24,    24,    23,
      65,    62,    27,    25,    27,    23,    27,    23,    11,    25,
      27,    15,    27,    27,     1,    29,    65,    58,     1,    54,
       1,    54,    29,     1,    64,     4,     1,    25,     1,    64,
      65,    65,    75,    75,     1,    13,    14,    22,    71,     1,
      76,     1,    65,    71,    71,    72,    54,    30,    30,    30,
      25,    27,    26,    26,    26,    27,    11,    11,    30,    71,
       1,    88,     1,    76,     1,    76,    71,    72,     1,    13,
      14,    22,    72,    71,    72,    15,    27,    27,    27,    26,
      26,    26,    76,    71,     1,    88,     1,    76,     1,    76,
      27,    11,    15,    27,    27,    76,    71,    27,    11
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    51,    51,    52,    52,
      53,    53,    53,    53,    54,    54,    54,    55,    55,    55,
      56,    56,    56,    57,    57,    58,    58,    58,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    61,    62,
      62,    63,    63,    63,    63,    64,    64,    64,    64,    65,
      65,    65,    65,    66,    66,    66,    66,    67,    67,    67,
      68,    68,    69,    69,    69,    70,    70,    70,    71,    71,
      71,    71,    71,    71,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    73,    73,    73,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      76,    76,    76,    76,    77,    77,    77,    77,    78,    78,
      78,    79,    79,    79,    79,    80,    80,    80,    80,    80,
      80,    81,    81,    81,    81,    82,    82,    83,    83,    83,
      83,    84,    84,    84,    85,    85,    85,    86,    86,    87,
      87,    88,    88,    88,    88,    89,    89,    89,    89,    89,
      90,    90,    90,    91,    91,    92,    92,    92,    93,    93,
      93,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     3,
       3,     3,     4,     3,     3,     1,     3,     1,     3,     3,
       1,     4,     3,     1,     2,     1,     1,     1,     6,     5,
       6,     4,     5,     3,     1,     0,     3,     1,     3,     2,
       2,     3,     1,     3,     3,     1,     3,     4,     3,     1,
       1,     2,     2,     1,     1,     1,     1,     4,     2,     4,
       2,     0,     2,     0,     2,     2,     1,     2,     7,     5,
       7,     1,     3,     5,     3,     3,     5,     7,     5,     7,
       7,     3,     3,     3,     3,     2,     3,     2,     2,     3,
       3,     3,     2,     2,     1,     3,     3,     2,     2,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     2,     1,
       2,     3,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     3,     1,     1,     3,     1,     3,
       3,     1,     1,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     4,     3,     2,     3,     1,     1,     2,     2,
       4,     4,     3,     1,     0,     3,     1,     3,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 55 "scanner.y" /* yacc.c:1646  */
    { savedTree = (yyvsp[0].tNode); }
#line 1745 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 60 "scanner.y" /* yacc.c:1646  */
    {
  TreeNode* t = (yyvsp[-1].tNode);
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      t->sibling = (yyvsp[0].tNode);
      (yyval.tNode) = (yyvsp[-1].tNode);
    }
  else
    (yyval.tNode) = (yyvsp[0].tNode);
}
#line 1762 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1768 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 74 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 1774 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 78 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1780 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 79 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1786 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 84 "scanner.y" /* yacc.c:1646  */
    { 
  TreeNode* t = (yyvsp[-1].tNode);
  while(t!=NULL)
    {
      t->expType=(yyvsp[-2].type);
      t = t->sibling;
    }
  (yyval.tNode) = (yyvsp[-1].tNode);
  (yyval.tNode)->isStatic=false;
  
  yyerrok;

}
#line 1804 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 97 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 1810 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 102 "scanner.y" /* yacc.c:1646  */
    { 
  TreeNode* t = (yyvsp[-1].tNode);
  while(t!=NULL)
    {
      t->expType=(yyvsp[-2].type);
      t = t->sibling;
    }
  (yyval.tNode) = (yyvsp[-1].tNode);
  (yyval.tNode)->isStatic=true; 
}
#line 1825 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 112 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode)=NULL; yyerrok; }
#line 1831 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 114 "scanner.y" /* yacc.c:1646  */
    { 
  TreeNode* t = (yyvsp[-1].tNode);
  while(t!=NULL)
    {
      t->expType=(yyvsp[-2].type);
      t = t->sibling;
    }
  (yyval.tNode) = (yyvsp[-1].tNode);
  (yyval.tNode)->isStatic=true;

  yyerrok;
}
#line 1848 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 127 "scanner.y" /* yacc.c:1646  */
    {
  TreeNode* t = (yyvsp[-1].tNode);
  while(t!=NULL)
    {
      t->expType=(yyvsp[-2].type);
      t = t->sibling;
    }
  (yyval.tNode) = (yyvsp[-1].tNode);
  (yyval.tNode)->isStatic=false;

  yyerrok;
}
#line 1865 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 143 "scanner.y" /* yacc.c:1646  */
    {
  TreeNode* t = (yyvsp[-2].tNode);
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      t->sibling = (yyvsp[0].tNode);
      (yyval.tNode) = (yyvsp[-2].tNode);
    }
  else
    (yyval.tNode) = (yyvsp[0].tNode);

  yyerrok; 

}
#line 1885 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 158 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1891 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 159 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 1897 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 163 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1903 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 164 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[-2].tNode); (yyval.tNode)->child[0] = (yyvsp[0].tNode); }
#line 1909 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 165 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 1915 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 169 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newDeclNode(varK,yylval.tokenData->lineno); (yyval.tNode)->attr.name=(yyvsp[0].tokenData)->idvalue; }
#line 1921 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 170 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newDeclNode(varK,yylval.tokenData->lineno); (yyval.tNode)->attr.name=(yyvsp[-3].tokenData)->idvalue; (yyval.tNode)->isArray=true; }
#line 1927 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 171 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok;}
#line 1933 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 175 "scanner.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type);}
#line 1939 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 176 "scanner.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type);}
#line 1945 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 181 "scanner.y" /* yacc.c:1646  */
    { (yyval.type) = Int; }
#line 1951 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 182 "scanner.y" /* yacc.c:1646  */
    { (yyval.type) = Bool; }
#line 1957 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 183 "scanner.y" /* yacc.c:1646  */
    { (yyval.type) = Char; }
#line 1963 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 187 "scanner.y" /* yacc.c:1646  */
    { int lineno = (yyvsp[-4].tokenData)->lineno; (yyval.tNode) = newDeclNode(funcK,lineno); (yyval.tNode)->child[0]=(yyvsp[-2].tNode); (yyval.tNode)->child[1]=(yyvsp[0].tNode); (yyval.tNode)->attr.name=(yyvsp[-4].tokenData)->idvalue; (yyval.tNode)->expType=(yyvsp[-5].type); }
#line 1969 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 188 "scanner.y" /* yacc.c:1646  */
    { int lineno = (yyvsp[-4].tokenData)->lineno; (yyval.tNode) = newDeclNode(funcK,lineno); (yyval.tNode)->child[0]=(yyvsp[-2].tNode); (yyval.tNode)->child[1]=(yyvsp[0].tNode); (yyval.tNode)->attr.name=(yyvsp[-4].tokenData)->idvalue; (yyval.tNode)->expType=Void; }
#line 1975 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 189 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 1981 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 190 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 1987 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 191 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 1993 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 192 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 1999 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 196 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2005 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 197 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 2011 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 202 "scanner.y" /* yacc.c:1646  */
    {
  TreeNode* t = (yyvsp[-2].tNode);
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      t->sibling = (yyvsp[0].tNode);
      (yyval.tNode) = (yyvsp[-2].tNode);
    }
  else
    (yyval.tNode) = (yyvsp[0].tNode);
}
#line 2028 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 214 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2034 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 215 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2040 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 220 "scanner.y" /* yacc.c:1646  */
    {
  TreeNode* t = (yyvsp[0].tNode);
  while(t!=NULL)
    {
      t->expType=(yyvsp[-1].type);
      t = t->sibling;
    }
  (yyval.tNode) = (yyvsp[0].tNode);
}
#line 2054 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 229 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2060 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 234 "scanner.y" /* yacc.c:1646  */
    {
  TreeNode* t = (yyvsp[-2].tNode);
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      t->sibling = (yyvsp[0].tNode);
      (yyval.tNode) = (yyvsp[-2].tNode);
    }
  else
    (yyval.tNode) = (yyvsp[0].tNode);
  
  yyerrok;
}
#line 2079 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 249 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2085 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 250 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2091 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 254 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newDeclNode(paramK,yylval.tokenData->lineno); (yyval.tNode)->attr.name=(yyvsp[0].tokenData)->idvalue; }
#line 2097 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 255 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newDeclNode(paramK,yylval.tokenData->lineno); (yyval.tNode)->attr.name=(yyvsp[-2].tokenData)->idvalue; (yyval.tNode)->isArray=true; }
#line 2103 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 256 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2109 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 257 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok;}
#line 2115 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 261 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2121 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 262 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2127 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 263 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = (yyvsp[-1].tNode);}
#line 2133 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 264 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = (yyvsp[-1].tNode);}
#line 2139 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 268 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2145 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 269 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2151 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 270 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2157 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 271 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2163 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 275 "scanner.y" /* yacc.c:1646  */
    { int lineno=(yyvsp[-3].tokenData)->lineno; (yyval.tNode) = newStmtNode(compoundK,lineno); (yyval.tNode)->child[0]=(yyvsp[-2].tNode); (yyval.tNode)->child[1]=(yyvsp[-1].tNode); }
#line 2169 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 276 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2175 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 277 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2181 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 282 "scanner.y" /* yacc.c:1646  */
    {
  TreeNode* t = (yyvsp[-1].tNode);
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      t->sibling = (yyvsp[0].tNode);
      (yyval.tNode) = (yyvsp[-1].tNode);
    }
  else
    (yyval.tNode) = (yyvsp[0].tNode);
}
#line 2198 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 294 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 2204 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 299 "scanner.y" /* yacc.c:1646  */
    { 
  TreeNode* t = (yyvsp[-1].tNode);
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      t->sibling = (yyvsp[0].tNode);
      (yyval.tNode) = (yyvsp[-1].tNode);
    }
  else
    (yyval.tNode) = (yyvsp[0].tNode);
}
#line 2221 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 311 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 2227 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 312 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2233 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 316 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[-1].tNode); yyerrok;}
#line 2239 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 317 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok;}
#line 2245 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 318 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2251 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 322 "scanner.y" /* yacc.c:1646  */
    { int lineno=(yyvsp[-6].tokenData)->lineno; (yyval.tNode) = newStmtNode(ifK,lineno); (yyval.tNode)->child[0]=(yyvsp[-4].tNode); (yyval.tNode)->child[1]=(yyvsp[-2].tNode); (yyval.tNode)->child[2]=(yyvsp[0].tNode); }
#line 2257 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 323 "scanner.y" /* yacc.c:1646  */
    { int lineno=(yyvsp[-4].tokenData)->lineno; (yyval.tNode) = newStmtNode(whileK,lineno); (yyval.tNode)->child[0]=(yyvsp[-2].tNode); (yyval.tNode)->child[1]=(yyvsp[0].tNode); }
#line 2263 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 324 "scanner.y" /* yacc.c:1646  */
    { int lineno=(yyvsp[-6].tokenData)->lineno; (yyval.tNode) = newStmtNode(foreachK,lineno); (yyval.tNode)->child[0]=(yyvsp[-4].tNode); (yyval.tNode)->child[1]=(yyvsp[-2].tNode); (yyval.tNode)->child[2]=(yyvsp[0].tNode); }
#line 2269 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 325 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2275 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 326 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2281 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 327 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2287 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 328 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2293 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 329 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2299 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 333 "scanner.y" /* yacc.c:1646  */
    { int lineno=(yyvsp[-4].tokenData)->lineno; (yyval.tNode) = newStmtNode(ifK,lineno); (yyval.tNode)->child[0]=(yyvsp[-2].tNode); (yyval.tNode)->child[1]=(yyvsp[0].tNode); }
#line 2305 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 334 "scanner.y" /* yacc.c:1646  */
    { int lineno=(yyvsp[-6].tokenData)->lineno; (yyval.tNode) = newStmtNode(ifK,lineno); (yyval.tNode)->child[0]=(yyvsp[-4].tNode); (yyval.tNode)->child[1]=(yyvsp[-2].tNode); (yyval.tNode)->child[2]=(yyvsp[0].tNode); }
#line 2311 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 335 "scanner.y" /* yacc.c:1646  */
    { int lineno=(yyvsp[-4].tokenData)->lineno; (yyval.tNode) = newStmtNode(whileK,lineno); (yyval.tNode)->child[0]=(yyvsp[-2].tNode); (yyval.tNode)->child[1]=(yyvsp[0].tNode); }
#line 2317 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 336 "scanner.y" /* yacc.c:1646  */
    { int lineno=(yyvsp[-6].tokenData)->lineno; (yyval.tNode) = newStmtNode(foreachK,lineno); (yyval.tNode)->child[0]=(yyvsp[-4].tNode); (yyval.tNode)->child[1]=(yyvsp[-2].tNode); (yyval.tNode)->child[2]=(yyvsp[0].tNode); }
#line 2323 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 337 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2329 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 338 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2335 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 339 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2341 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 340 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2347 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 341 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2353 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 346 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newStmtNode(returnK,yylval.tokenData->lineno); }
#line 2359 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 347 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newStmtNode(returnK,yylval.tokenData->lineno); (yyval.tNode)->child[0] = (yyvsp[-1].tNode); }
#line 2365 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 348 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2371 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 352 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newStmtNode(breakK,yylval.tokenData->lineno); }
#line 2377 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 357 "scanner.y" /* yacc.c:1646  */
    {
  TreeNode* t = (yyvsp[0].tNode);
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      (yyval.tNode) = newExpNode(assignK,yylval.tokenData->lineno);
      (yyval.tNode)->attr.op = eqK;
      (yyval.tNode)->child[0] = (yyvsp[-2].tNode);
      (yyval.tNode)->child[1] = (yyvsp[0].tNode);
    }
  else
    {
      (yyval.tNode) = newExpNode(assignK,yylval.tokenData->lineno);
      (yyval.tNode)->attr.op = eqK;
      (yyval.tNode)->child[0] = (yyvsp[-2].tNode);
      (yyval.tNode)->child[1] = (yyvsp[0].tNode);
    }
}
#line 2401 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 377 "scanner.y" /* yacc.c:1646  */
    {
  TreeNode* t = (yyvsp[0].tNode);
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      (yyval.tNode) = newExpNode(assignK,yylval.tokenData->lineno);
      (yyval.tNode)->attr.op = peqK;
      (yyval.tNode)->child[0] = (yyvsp[-2].tNode);
      (yyval.tNode)->child[1] = (yyvsp[0].tNode);
    }
   else
     {
       (yyval.tNode) = newExpNode(assignK,yylval.tokenData->lineno);
       (yyval.tNode)->attr.op = peqK;
       (yyval.tNode)->child[0] = (yyvsp[-2].tNode);
       (yyval.tNode)->child[1] = (yyvsp[0].tNode);
     }
 }
#line 2425 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 397 "scanner.y" /* yacc.c:1646  */
    {
  TreeNode* t = (yyvsp[0].tNode);
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      (yyval.tNode) = newExpNode(assignK,yylval.tokenData->lineno);
      (yyval.tNode)->attr.op = meqK;
      (yyval.tNode)->child[0] = (yyvsp[-2].tNode);
      (yyval.tNode)->child[1] = (yyvsp[0].tNode);
    }
  else
    {
      (yyval.tNode) = newExpNode(assignK,yylval.tokenData->lineno);
      (yyval.tNode)->attr.op = meqK;
      (yyval.tNode)->child[0] = (yyvsp[-2].tNode);
      (yyval.tNode)->child[1] = (yyvsp[0].tNode);
    }
 }
#line 2449 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 416 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(assignK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = ppK; (yyval.tNode)->child[0] = (yyvsp[-1].tNode); }
#line 2455 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 417 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(assignK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = mmK; (yyval.tNode)->child[0] = (yyvsp[-1].tNode); }
#line 2461 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 418 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2467 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 419 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2473 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 420 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2479 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 421 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2485 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 422 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2491 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 423 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2497 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 428 "scanner.y" /* yacc.c:1646  */
    {
  TreeNode* t = (yyvsp[-2].tNode);
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno);
      (yyval.tNode)->attr.op = orK;
      (yyval.tNode)->child[0] = (yyvsp[-2].tNode);
      (yyval.tNode)->child[1] = (yyvsp[0].tNode);
    }
  else
    {
      (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno);
      (yyval.tNode)->attr.op = orK;
      (yyval.tNode)->child[0] = (yyvsp[-2].tNode);
      (yyval.tNode)->child[1] = (yyvsp[0].tNode);
    }
}
#line 2521 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 447 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2527 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 448 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2533 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 449 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2539 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 454 "scanner.y" /* yacc.c:1646  */
    {
  TreeNode* t = (yyvsp[-2].tNode);
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno);
      (yyval.tNode)->attr.op = andK;
      (yyval.tNode)->child[0] = (yyvsp[-2].tNode);
      (yyval.tNode)->child[1] = (yyvsp[0].tNode);
    }
  else
    {
      (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno);
      (yyval.tNode)->attr.op = andK;
      (yyval.tNode)->child[0] = (yyvsp[-2].tNode);
      (yyval.tNode)->child[1] = (yyvsp[0].tNode);
    }
}
#line 2563 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 473 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2569 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 474 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2575 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 475 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2581 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 479 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = notK; (yyval.tNode)->child[0]=(yyvsp[0].tNode); }
#line 2587 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 480 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2593 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 481 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2599 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 485 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[-1].tNode); (yyval.tNode)->child[0] = (yyvsp[-2].tNode); (yyval.tNode)->child[1] = (yyvsp[0].tNode); }
#line 2605 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 486 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2611 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 487 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2617 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 488 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2623 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 492 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = lteqK; }
#line 2629 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 493 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = ltK; }
#line 2635 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 494 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = gtK; }
#line 2641 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 495 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = gteqK; }
#line 2647 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 496 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = equivK; }
#line 2653 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 497 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = neqK; }
#line 2659 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 501 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[-1].tNode); (yyval.tNode)->child[0]=(yyvsp[-2].tNode); (yyval.tNode)->child[1]=(yyvsp[0].tNode); }
#line 2665 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 502 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2671 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 503 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2677 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 504 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2683 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 508 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = plusK; }
#line 2689 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 509 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = minusK; }
#line 2695 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 514 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[-1].tNode); (yyval.tNode)->child[0] = (yyvsp[-2].tNode); (yyval.tNode)->child[1]=(yyvsp[0].tNode); }
#line 2701 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 515 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2707 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 516 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2713 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 517 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2719 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 521 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = multiK; }
#line 2725 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 522 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = divideK; }
#line 2731 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 523 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = modK; }
#line 2737 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 527 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[-1].tNode); (yyval.tNode)->child[0]=(yyvsp[0].tNode); }
#line 2743 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 528 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2749 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 529 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2755 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 533 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = UminusK; }
#line 2761 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 534 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = UmultiK; }
#line 2767 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 538 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2773 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 539 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2779 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 543 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(idK,yylval.tokenData->lineno); (yyval.tNode)->attr.name=(yyvsp[0].tokenData)->idvalue; }
#line 2785 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 544 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(idK,(yyvsp[-3].tokenData)->lineno); (yyval.tNode)->child[0] = (yyvsp[-1].tNode); (yyval.tNode)->attr.name=(yyvsp[-3].tokenData)->idvalue; (yyval.tNode)->isArray = true; }
#line 2791 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 545 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2797 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 546 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2803 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 550 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[-1].tNode); yyerrok;}
#line 2809 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 551 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2815 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 552 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); (yyval.tNode)->isConstant = true; }
#line 2821 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 553 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2827 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 554 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2833 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 558 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(callK, yylval.tokenData->lineno); (yyval.tNode)->child[0] = (yyvsp[-1].tNode); (yyval.tNode)->attr.name=(yyvsp[-3].tokenData)->idvalue;  }
#line 2839 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 559 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2845 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 560 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; }
#line 2851 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 564 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2857 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 565 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 2863 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 570 "scanner.y" /* yacc.c:1646  */
    {
  TreeNode* t = (yyvsp[-2].tNode);
  if(t!=NULL)
    {
      while(t->sibling != NULL)
        t = t->sibling;
      t->sibling = (yyvsp[0].tNode);
      (yyval.tNode) = (yyvsp[-2].tNode);
    }
  else
    (yyval.tNode) = (yyvsp[0].tNode);

  yyerrok;
}
#line 2882 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 584 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2888 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 585 "scanner.y" /* yacc.c:1646  */
    {(yyval.tNode) = NULL; yyerrok; }
#line 2894 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 589 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(constK,yylval.tokenData->lineno); (yyval.tNode)->attr.val = (yyvsp[0].tokenData)->numvalue; (yyval.tNode)->expType=Int; }
#line 2900 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 590 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(constK,yylval.tokenData->lineno); (yyval.tNode)->attr.string = (yyvsp[0].tokenData)->tokenstr; (yyval.tNode)->expType=Char; }
#line 2906 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 591 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(constK,yylval.tokenData->lineno); (yyval.tNode)->attr.string = (yyvsp[0].tokenData)->tokenstr; (yyval.tNode)->expType=Char; }
#line 2912 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 592 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(constK,yylval.tokenData->lineno); (yyval.tNode)->expType=True; }
#line 2918 "scanner.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 593 "scanner.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(constK,yylval.tokenData->lineno); }
#line 2924 "scanner.tab.c" /* yacc.c:1646  */
    break;


#line 2928 "scanner.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 596 "scanner.y" /* yacc.c:1906  */


int main(int argc, char* argv[])
{
  int c;
  extern char* optarg;
  extern int optind;
  char **inputfile;
  
  int yydebug=0;
  
  inputfile = argv + optind;
  yyin = fopen((inputfile[0]), "r");
    
  initYyerror();
  yyparse(); 
  //  printTree(savedTree);
  //  checkErr(savedTree);
  
  while((c = getopt(argc, argv, "d:")) != -1)
    {
      switch(c)
        {
        case 'd':
          yydebug=1;
          printf("YYDEBUG==%d",yydebug);
          break;
        case 'p':
          printTree(savedTree);
          break;
        case 's':
          (DEBUG_TABLE | DEBUG_PUSH);
        default:
          printf("Unknown option(s)\n");
          break;
        }
      c = getopt(argc, argv, "dps:");
    }
  
  //  if (numErrors==0) scopeAndType(savedTree)
  
  printf("Number of errors: %d\n", numErrors);
  printf("Number of warnings: %d\n", numWarnings);
  
  return 0;
  
}

