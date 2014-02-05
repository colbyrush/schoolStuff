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
#line 1 "parser.y" /* yacc.c:339  */

    #include <iostream>
    #include <stdlib.h>
    #include <stdio.h>
    #include "tokenStruct.h"
    #include "tree.c"
    #include "analyze.c"
    #include "mystrings.h"
    #include "yyerror.h"
    #include "codegen.cpp"

  extern int yylex();
  extern int yydebug;
  extern FILE* yyin;
  FILE *code;

  extern SymTab* tab;

  static TreeNode *savedTree;
  static TreeNode *input = (TreeNode*) malloc(sizeof(TreeNode));

  extern int numerrors;
  extern int numwarnings;

  bool stat = false;

  char* lasttokenscanned;
  int globallineno;

    #define YYERROR_VERBOSE

    #ifndef  prepro
    #define  prepro

  void preProcess()
  {

    //input preprocess
    //static TreeNode *input = (TreeNode*) malloc(sizeof(TreeNode));
    //outputc->sibling=input;
    input->attr.name=(char*)"input";
    input->lineno=-1;
    input->nodekind=DeclK;
    input->kind.decl=funcK;
    input->expType=Int;
    input->isPre=true;
    input->pnum=0;


    //output preprocess
    static TreeNode *output = (TreeNode*) malloc(sizeof(TreeNode));
    input->sibling=output;
    output->attr.name=(char*)"output";
    output->lineno=-1;
    output->nodekind=DeclK;
    output->kind.decl=funcK;
    output->expType=Void;
    output->isPre=true;
    output->pnum=1;
    static TreeNode *outputN = (TreeNode*) malloc(sizeof(TreeNode));
    output->child[0] = outputN;
    outputN->lineno=-1;
    outputN->nodekind=DeclK;
    outputN->kind.decl=paramK;
    outputN->isPre=true;
    outputN->expType=Int;



    //inputb preprocess
    static TreeNode *inputb = (TreeNode*) malloc(sizeof(TreeNode));
    output->sibling=inputb;
    inputb->attr.name=(char*)"inputb";
    inputb->lineno=-1;
    inputb->nodekind=DeclK;
    inputb->kind.decl=funcK;
    inputb->expType=Bool;
    inputb->isPre=true;
    inputb->pnum=2;


    //outputb preprocess
    static TreeNode *outputb = (TreeNode*) malloc(sizeof(TreeNode));
    inputb->sibling=outputb;
    outputb->attr.name=(char*)"outputb";
    outputb->lineno=-1;
    outputb->nodekind=DeclK;
    outputb->kind.decl=funcK;
    outputb->expType=Void;
    outputb->isPre=true;
    outputb->pnum=3;
    static TreeNode *outputbN = (TreeNode*) malloc(sizeof(TreeNode));
    outputb->child[0] = outputbN;
    outputbN->lineno=-1;
    outputbN->nodekind=DeclK;
    outputbN->kind.decl=paramK;
    outputbN->isPre=true;
    outputbN->expType=Bool;


    //inputc preprocess
    static TreeNode *inputc = (TreeNode*) malloc(sizeof(TreeNode));
    outputb->sibling=inputc;
    inputc->attr.name=(char*)"inputc";
    inputc->lineno=-1;
    inputc->nodekind=DeclK;
    inputc->kind.decl=funcK;
    inputc->expType=Char;
    inputc->isPre=true;
    inputc->pnum=4;


    //outputc preprocess
    static TreeNode *outputc = (TreeNode*) malloc(sizeof(TreeNode));
    inputc->sibling=outputc;
    outputc->attr.name=(char*)"outputc";
    outputc->lineno=-1;
    outputc->nodekind=DeclK;
    outputc->kind.decl=funcK;
    outputc->expType=Void;
    outputc->isPre=true;
    outputc->pnum=5;
    static TreeNode *outputcN = (TreeNode*) malloc(sizeof(TreeNode));
    outputc->child[0] = outputcN;
    outputcN->lineno=-1;
    outputcN->nodekind=DeclK;
    outputcN->kind.decl=paramK;
    outputcN->isPre=true;
    outputcN->expType=Char;


    //outnl preprocess
    static TreeNode *outnl = (TreeNode*) malloc(sizeof(TreeNode));
    outputc->sibling=outnl;
    outnl->attr.name=(char*)"outnl";
    outnl->lineno=-1;
    outnl->nodekind=DeclK;
    outnl->kind.decl=funcK;
    outnl->expType=Void;
    outnl->isPre=true;
    outnl->pnum=6;
    outnl->sibling=savedTree;


  }
    #endif


  using namespace std;


  

#line 220 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
#line 156 "parser.y" /* yacc.c:355  */

   ExpType type;
   TokenData *tokenData;
   TreeNode *tNode;

#line 314 "parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 329 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   460

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  211

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
       0,   187,   187,   190,   202,   203,   206,   207,   213,   222,
     225,   239,   242,   254,   255,   258,   259,   260,   261,   264,
     265,   266,   267,   270,   271,   274,   275,   276,   281,   282,
     283,   284,   285,   286,   289,   290,   293,   305,   306,   309,
     317,   320,   332,   333,   334,   337,   338,   339,   340,   344,
     345,   346,   347,   350,   351,   352,   353,   356,   357,   358,
     361,   372,   375,   386,   387,   390,   391,   392,   395,   396,
     397,   398,   401,   402,   403,   404,   407,   408,   411,   417,
     423,   429,   435,   436,   437,   440,   447,   450,   457,   460,
     461,   464,   465,   468,   469,   470,   471,   472,   473,   476,
     477,   480,   481,   484,   485,   488,   489,   490,   493,   494,
     497,   498,   501,   502,   505,   506,   509,   510,   511,   514,
     517,   518,   521,   532,   536,   547,   550,   551,   552,   553,
     554
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
  "unaryrelexpression", "relexpression", "relop", "sumexpression", "sumop",
  "term", "mulop", "unaryexpression", "unaryop", "factor", "mutable",
  "immutable", "call", "args", "arglist", "constant", YY_NULL
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

#define YYPACT_NINF -174

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-174)))

#define YYTABLE_NINF -62

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     420,    -6,    26,  -174,  -174,  -174,    61,   234,  -174,  -174,
     107,  -174,   366,    77,  -174,    -6,  -174,    71,   105,    52,
    -174,    28,    11,   115,  -174,  -174,  -174,    58,  -174,    72,
      90,   399,   394,  -174,   121,   399,   255,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,   165,   210,  -174,  -174,    91,   142,
     146,  -174,  -174,   416,   110,  -174,    59,  -174,   160,  -174,
    -174,  -174,    -9,   147,   137,   162,  -174,   179,   168,   136,
    -174,   399,    95,   406,   179,  -174,    25,  -174,  -174,   399,
     399,  -174,   173,   399,  -174,  -174,  -174,   187,   399,   194,
    -174,    39,  -174,  -174,  -174,   399,   399,  -174,  -174,  -174,
    -174,  -174,  -174,  -174,  -174,    59,    59,  -174,  -174,  -174,
      59,  -174,   399,   399,   399,  -174,  -174,   366,    64,    60,
     203,   208,  -174,   366,    64,    -8,   209,  -174,   200,   211,
     215,   142,  -174,   220,   211,   219,  -174,  -174,   142,   222,
    -174,   221,   226,   227,   237,    -3,  -174,    -2,  -174,   292,
      64,  -174,   185,  -174,   329,   146,  -174,   163,   110,  -174,
    -174,  -174,  -174,  -174,  -174,   201,   228,    10,   202,  -174,
    -174,  -174,   366,  -174,   366,  -174,  -174,   399,   399,   366,
     366,    11,  -174,  -174,  -174,   166,    79,  -174,   231,  -174,
    -174,  -174,  -174,   231,  -174,  -174,  -174,  -174,    19,  -174,
     114,  -174,  -174,  -174,  -174,   366,   366,  -174,  -174,  -174,
    -174
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,    26,    27,    25,     0,     0,     4,     6,
       0,     7,     0,     0,     1,     0,     3,     0,    19,     0,
      13,    15,     0,   114,   126,   127,   128,     0,   130,     0,
       0,     0,     0,   129,     0,     0,     0,    66,   110,   111,
      33,    71,    54,    53,     0,     0,    55,    56,     0,    84,
      86,    88,    90,    92,   100,   104,     0,   109,   113,   112,
     117,   118,     0,     0,     0,    34,    37,     0,     0,     0,
       9,     0,     0,     0,     0,     8,     0,    58,    67,     0,
     121,    78,     0,     0,    89,   113,    76,     0,     0,     0,
      63,    63,    51,    52,    65,     0,     0,    97,    98,    93,
      94,    96,    95,   101,   102,     0,     0,   106,   107,   105,
       0,   108,     0,     0,     0,    83,    82,     0,     0,    40,
      45,    39,    42,     0,     0,     0,    19,    14,     0,     0,
       0,    17,    22,     0,    31,     0,    12,    18,    16,     0,
     123,     0,   120,   114,     0,     0,    77,     0,   116,     0,
       0,    60,     0,    24,     0,    85,    87,    91,    99,   103,
      79,    80,    81,    32,    38,     0,     0,     0,     0,    29,
      36,    21,     0,    20,     0,   115,   119,     0,     0,     0,
       0,    64,    59,    62,    23,     0,     0,    57,     0,    43,
      47,    48,    46,    44,    41,    30,    28,   122,     0,    72,
       0,    69,    74,    11,    10,     0,     0,    70,    75,    68,
      73
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -174,  -174,  -174,   259,  -174,  -174,   118,    33,  -174,  -174,
       1,  -174,   -50,  -174,   -74,  -174,   -30,   -12,  -174,  -174,
    -174,   171,  -174,  -173,  -167,  -174,  -174,   -23,   -66,   177,
     -28,  -174,  -174,   174,  -174,   172,  -174,   -52,  -174,  -174,
     -29,  -174,  -174,  -174,  -174,  -174
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,     9,   151,    19,    20,    21,   152,
      63,    11,    64,    65,    66,   121,   122,   183,    41,    42,
      91,   149,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,   105,    53,   106,    54,   110,    55,    56,    57,
      58,    59,    60,   141,   142,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    10,    85,    84,   111,   131,   200,   201,    10,    87,
     138,   191,    89,   202,    95,    95,    68,   145,   117,   130,
      12,   118,   147,   135,   179,   180,   137,    85,    23,    24,
      25,    26,   207,   209,    71,   192,    95,    28,   208,   210,
      77,    78,    85,    31,   164,    33,   205,    85,     3,     4,
     170,    35,    13,   144,    85,     5,   139,   140,   159,    85,
     150,    14,    23,    24,    25,    26,    85,    85,   156,    38,
      76,    28,    39,     3,     4,    74,    85,    85,    62,    33,
       5,    85,    75,   165,   166,    35,     3,     4,    81,   160,
     161,   162,   153,     5,    67,    68,   132,    69,    82,   133,
     127,    70,    74,    38,   -35,   163,    39,   136,    17,   204,
      18,   169,   198,    71,   -49,    92,    83,   -49,   -49,   -49,
     -49,    94,   -49,   -49,   -49,   206,   -49,   -49,   -49,    72,
     -49,    73,   -49,   -49,   -49,   189,   -49,   129,   194,    79,
     -49,    80,   -49,   -49,   -49,     3,     4,    88,   119,    85,
     120,   184,     5,    96,   197,   107,   108,   109,   -49,    95,
     195,   -49,   196,   -35,   123,   -49,    92,   199,   -49,   -49,
     -49,   -49,   128,   -49,   -49,   -49,   143,   -49,   -49,   -49,
     125,   -49,   126,   -49,   -49,   -49,   185,   -49,   126,    67,
      68,   -49,   124,   -49,   -49,   -49,   203,   112,   113,   114,
     115,   116,   188,   193,   120,   120,   103,   104,    71,   -49,
     -50,    93,   -49,   -50,   -50,   -50,   -50,   146,   -50,   -50,
     -50,   148,   -50,   -50,   -50,   171,   -50,   167,   -50,   -50,
     -50,   168,   -50,    72,    -2,    15,   -50,     2,   -50,   -50,
     -50,   118,   172,     3,     4,   173,   174,   175,   176,   177,
       5,    79,   178,   190,   -50,   166,    90,   -50,   -61,   -61,
     -61,   -61,   154,   -61,   -61,   -61,    16,   -61,   -61,   -61,
     186,   -61,   155,   -61,   -61,   -61,   -61,   -61,   158,   157,
       0,   -61,     0,   -61,   -61,   -61,     0,     0,     0,     0,
       0,     0,     0,   181,     0,    23,    24,    25,    26,   -61,
      27,     0,   -61,     0,    28,    29,    30,     0,     0,     0,
      31,    32,    33,     0,    34,     0,     0,     0,    35,     0,
      36,   182,    37,     0,     0,     0,     0,     0,     0,     0,
     181,     0,    23,    24,    25,    26,    38,    27,     0,    39,
       0,    28,    29,    30,     0,     0,     0,    31,    32,    33,
       0,    34,     0,     0,     0,    35,     0,    36,   187,    37,
       0,     0,     0,     0,     0,     0,     0,    22,     0,    23,
      24,    25,    26,    38,    27,     0,    39,     0,    28,    29,
      30,     0,     0,     0,    31,    32,    33,     0,    34,     0,
       0,     0,    35,     0,    36,     0,    37,    23,    24,    25,
      26,     0,    23,    24,    25,    26,    28,   134,     0,     0,
      38,    28,    31,    39,    33,     3,     4,    31,     0,    33,
      35,     1,     5,     2,    86,    35,     0,     0,     0,     3,
       4,     0,     0,   -35,     0,     0,     5,     0,    38,     0,
       0,    39,     0,    38,     0,     0,    39,    97,    98,    99,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   103,
     104
};

static const yytype_int16 yycheck[] =
{
      12,     0,    31,    31,    56,    71,   179,   180,     7,    32,
      76,     1,    35,   180,    17,    17,    24,    83,    27,    69,
      26,    30,    88,    73,    27,    27,     1,    56,     3,     4,
       5,     6,   205,   206,    42,    25,    17,    12,   205,   206,
      29,    30,    71,    18,   118,    20,    27,    76,     9,    10,
     124,    26,    26,    82,    83,    16,    79,    80,   110,    88,
      21,     0,     3,     4,     5,     6,    95,    96,    96,    44,
      42,    12,    47,     9,    10,    23,   105,   106,     1,    20,
      16,   110,    30,    23,    24,    26,     9,    10,    30,   112,
     113,   114,    91,    16,    23,    24,     1,    26,    26,     4,
      67,    30,    23,    44,    27,   117,    47,    74,     1,    30,
       3,   123,   178,    42,     0,     1,    26,     3,     4,     5,
       6,    30,     8,     9,    10,    11,    12,    13,    14,    24,
      16,    26,    18,    19,    20,   165,    22,     1,   168,    24,
      26,    26,    28,    29,    30,     9,    10,    26,     1,   178,
       3,   150,    16,     7,   177,    45,    46,    47,    44,    17,
     172,    47,   174,    27,    27,     0,     1,   179,     3,     4,
       5,     6,     4,     8,     9,    10,     3,    12,    13,    14,
       1,    16,     3,    18,    19,    20,     1,    22,     3,    23,
      24,    26,    30,    28,    29,    30,    30,    37,    38,    39,
      40,    41,     1,     1,     3,     3,    43,    44,    42,    44,
       0,     1,    47,     3,     4,     5,     6,    30,     8,     9,
      10,    27,    12,    13,    14,    25,    16,    24,    18,    19,
      20,    23,    22,    24,     0,     1,    26,     3,    28,    29,
      30,    30,    27,     9,    10,    25,    27,    25,    27,    23,
      16,    24,    15,    25,    44,    24,     1,    47,     3,     4,
       5,     6,    91,     8,     9,    10,     7,    12,    13,    14,
     152,    16,    95,    18,    19,    20,    21,    22,   106,   105,
      -1,    26,    -1,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,    44,
       8,    -1,    47,    -1,    12,    13,    14,    -1,    -1,    -1,
      18,    19,    20,    -1,    22,    -1,    -1,    -1,    26,    -1,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,    44,     8,    -1,    47,
      -1,    12,    13,    14,    -1,    -1,    -1,    18,    19,    20,
      -1,    22,    -1,    -1,    -1,    26,    -1,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,    44,     8,    -1,    47,    -1,    12,    13,
      14,    -1,    -1,    -1,    18,    19,    20,    -1,    22,    -1,
      -1,    -1,    26,    -1,    28,    -1,    30,     3,     4,     5,
       6,    -1,     3,     4,     5,     6,    12,     1,    -1,    -1,
      44,    12,    18,    47,    20,     9,    10,    18,    -1,    20,
      26,     1,    16,     3,    30,    26,    -1,    -1,    -1,     9,
      10,    -1,    -1,    27,    -1,    -1,    16,    -1,    44,    -1,
      -1,    47,    -1,    44,    -1,    -1,    47,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     9,    10,    16,    49,    50,    51,    52,
      58,    59,    26,    26,     0,     1,    51,     1,     3,    54,
      55,    56,     1,     3,     4,     5,     6,     8,    12,    13,
      14,    18,    19,    20,    22,    26,    28,    30,    44,    47,
      65,    66,    67,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    81,    83,    85,    86,    87,    88,    89,
      90,    93,     1,    58,    60,    61,    62,    23,    24,    26,
      30,    42,    24,    26,    23,    30,    42,    29,    30,    24,
      26,    30,    26,    26,    78,    88,    30,    75,    26,    75,
       1,    68,     1,     1,    30,    17,     7,    31,    32,    33,
      34,    35,    36,    43,    44,    80,    82,    45,    46,    47,
      84,    85,    37,    38,    39,    40,    41,    27,    30,     1,
       3,    63,    64,    27,    30,     1,     3,    55,     4,     1,
      60,    76,     1,     4,     1,    60,    55,     1,    76,    75,
      75,    91,    92,     3,    88,    76,    30,    76,    27,    69,
      21,    53,    57,    58,    69,    77,    78,    81,    83,    85,
      75,    75,    75,    65,    62,    23,    24,    24,    23,    65,
      62,    25,    27,    25,    27,    25,    27,    23,    15,    27,
      27,     1,    29,    65,    58,     1,    54,    29,     1,    64,
      25,     1,    25,     1,    64,    65,    65,    75,    76,    65,
      71,    71,    72,    30,    30,    27,    11,    71,    72,    71,
      72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    54,    55,    55,    55,    55,    56,
      56,    56,    56,    57,    57,    58,    58,    58,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    61,    62,
      62,    63,    63,    63,    63,    64,    64,    64,    64,    65,
      65,    65,    65,    66,    66,    66,    66,    67,    67,    67,
      68,    68,    69,    69,    69,    70,    70,    70,    71,    71,
      71,    71,    72,    72,    72,    72,    73,    73,    74,    75,
      75,    75,    75,    75,    75,    76,    76,    77,    77,    78,
      78,    79,    79,    80,    80,    80,    80,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    84,    85,    85,
      86,    86,    87,    87,    88,    88,    89,    89,    89,    90,
      91,    91,    92,    92,    92,    92,    93,    93,    93,    93,
      93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     1,     3,     1,     3,     3,     3,     1,
       4,     4,     3,     2,     1,     1,     1,     1,     6,     5,
       6,     4,     5,     3,     1,     0,     3,     1,     3,     2,
       2,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       1,     2,     2,     1,     1,     1,     1,     4,     2,     4,
       2,     0,     2,     0,     2,     2,     1,     2,     7,     5,
       7,     1,     5,     7,     5,     7,     2,     3,     2,     3,
       3,     3,     2,     2,     1,     3,     1,     3,     1,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     4,     3,     1,     1,     4,
       1,     0,     3,     1,     3,     1,     1,     1,     1,     1,
       1
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
#line 187 "parser.y" /* yacc.c:1646  */
    { savedTree = (yyvsp[0].tNode); }
#line 1601 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 190 "parser.y" /* yacc.c:1646  */
    { TreeNode* t = (yyvsp[-1].tNode);
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
#line 1617 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 202 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1623 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 203 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 1629 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 206 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1641 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 213 "parser.y" /* yacc.c:1646  */
    { TreeNode* t = (yyvsp[-1].tNode);
   while(t!=NULL)
     {
       t->expType=(yyvsp[-2].type);
       t = t->sibling;
     }
   (yyval.tNode) = (yyvsp[-1].tNode);
   yyerrok;
 }
#line 1655 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode)=NULL; yyerrok; }
#line 1661 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 225 "parser.y" /* yacc.c:1646  */
    { TreeNode* t = (yyvsp[-1].tNode);
   while(t!=NULL)
     {
       t->expType=(yyvsp[-2].type);
       t = t->sibling;
     }
   (yyval.tNode) = (yyvsp[-1].tNode);
   if(stat)
     {
       (yyval.tNode)->isStatic=true; 
       stat=false;
     }
   yyerrok;
 }
#line 1680 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 239 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode)=NULL; yyerrok; }
#line 1686 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 242 "parser.y" /* yacc.c:1646  */
    { TreeNode* t = (yyvsp[-2].tNode);
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
#line 1703 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 254 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1709 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 255 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 1715 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 258 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1721 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 259 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[-2].tNode); (yyval.tNode)->child[0] = (yyvsp[0].tNode); (yyval.tNode)->expType=(yyvsp[0].tNode)->expType; }
#line 1727 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 260 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 1733 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 261 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 1739 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 264 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newDeclNode(varK,yylval.tokenData->lineno); (yyval.tNode)->attr.name=(yyvsp[0].tokenData)->idvalue; }
#line 1745 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 265 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newDeclNode(varK,yylval.tokenData->lineno); (yyval.tNode)->attr.name=(yyvsp[-3].tokenData)->idvalue; (yyval.tNode)->isArray=true; (yyval.tNode)->size=(yyvsp[-1].tokenData)->numvalue; }
#line 1751 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 266 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 1757 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 267 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 1763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 270 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); stat = true; }
#line 1769 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 271 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type); }
#line 1775 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = Int; }
#line 1781 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 275 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = Bool; }
#line 1787 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 276 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = Char; }
#line 1793 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 281 "parser.y" /* yacc.c:1646  */
    { int lineno = (yyvsp[-4].tokenData)->lineno; (yyval.tNode) = newDeclNode(funcK,lineno); (yyval.tNode)->child[0]=(yyvsp[-2].tNode); (yyval.tNode)->child[1]=(yyvsp[0].tNode); (yyval.tNode)->attr.name=(yyvsp[-4].tokenData)->idvalue; (yyval.tNode)->expType=(yyvsp[-5].type); }
#line 1799 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 282 "parser.y" /* yacc.c:1646  */
    { int lineno = (yyvsp[-4].tokenData)->lineno; (yyval.tNode) = newDeclNode(funcK,lineno); (yyval.tNode)->child[0]=(yyvsp[-2].tNode); (yyval.tNode)->child[1]=(yyvsp[0].tNode); (yyval.tNode)->attr.name=(yyvsp[-4].tokenData)->idvalue; (yyval.tNode)->expType=Void; }
#line 1805 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 283 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 1811 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 284 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 1817 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 285 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 1823 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 286 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 1829 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 289 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1835 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 290 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 1841 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 293 "parser.y" /* yacc.c:1646  */
    { TreeNode* t = (yyvsp[-2].tNode);
   if(t!=NULL)
     {
       while(t->sibling != NULL)
         t = t->sibling;
       t->sibling = (yyvsp[0].tNode);
       (yyval.tNode) = (yyvsp[-2].tNode);
     }
   else
     (yyval.tNode) = (yyvsp[0].tNode);
   //yyerrok;
 }
#line 1858 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 305 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1864 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 306 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 1870 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 309 "parser.y" /* yacc.c:1646  */
    { TreeNode* t = (yyvsp[0].tNode);
   while(t!=NULL)
     {
       t->expType=(yyvsp[-1].type);
       t = t->sibling;
     }
   (yyval.tNode) = (yyvsp[0].tNode);
 }
#line 1883 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 317 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 1889 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 320 "parser.y" /* yacc.c:1646  */
    { TreeNode* t = (yyvsp[-2].tNode);
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
#line 1906 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 332 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1912 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 333 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 1918 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 334 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 1924 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 337 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newDeclNode(paramK,yylval.tokenData->lineno); (yyval.tNode)->attr.name=(yyvsp[0].tokenData)->idvalue; }
#line 1930 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 338 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newDeclNode(paramK,yylval.tokenData->lineno); (yyval.tNode)->attr.name=(yyvsp[-2].tokenData)->idvalue; (yyval.tNode)->isArray=true; }
#line 1936 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 339 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 1942 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 340 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 1948 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 344 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1954 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 345 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1960 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 346 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[-1].tNode); }
#line 1966 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 347 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[-1].tNode); }
#line 1972 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 350 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1978 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 351 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1984 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 352 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1990 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 353 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 1996 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 356 "parser.y" /* yacc.c:1646  */
    { yyerrok; int lineno=(yyvsp[-3].tokenData)->lineno; (yyval.tNode) = newStmtNode(compoundK,lineno); (yyval.tNode)->child[0]=(yyvsp[-2].tNode); (yyval.tNode)->child[1]=(yyvsp[-1].tNode); }
#line 2002 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 357 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 2008 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 358 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 2014 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 361 "parser.y" /* yacc.c:1646  */
    { TreeNode* t = (yyvsp[-1].tNode);
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
#line 2030 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 372 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 2036 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 375 "parser.y" /* yacc.c:1646  */
    { TreeNode* t = (yyvsp[-1].tNode);
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
#line 2052 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 386 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 2058 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 387 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 2064 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 390 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[-1].tNode); yyerrok; }
#line 2070 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 391 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 2076 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 392 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; yyerrok; }
#line 2082 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 395 "parser.y" /* yacc.c:1646  */
    { int lineno=(yyvsp[-6].tokenData)->lineno; (yyval.tNode) = newStmtNode(ifK,lineno); (yyval.tNode)->child[0]=(yyvsp[-4].tNode); (yyval.tNode)->child[1]=(yyvsp[-2].tNode); (yyval.tNode)->child[2]=(yyvsp[0].tNode); }
#line 2088 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 396 "parser.y" /* yacc.c:1646  */
    { int lineno=(yyvsp[-4].tokenData)->lineno; (yyval.tNode) = newStmtNode(whileK,lineno); (yyval.tNode)->child[0]=(yyvsp[-2].tNode); (yyval.tNode)->child[1]=(yyvsp[0].tNode); }
#line 2094 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 397 "parser.y" /* yacc.c:1646  */
    { int lineno=(yyvsp[-6].tokenData)->lineno; (yyval.tNode) = newStmtNode(foreachK,lineno); (yyval.tNode)->child[0]=(yyvsp[-4].tNode); (yyval.tNode)->child[1]=(yyvsp[-2].tNode); (yyval.tNode)->child[2]=(yyvsp[0].tNode); }
#line 2100 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 398 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2106 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 401 "parser.y" /* yacc.c:1646  */
    { int lineno=(yyvsp[-4].tokenData)->lineno; (yyval.tNode) = newStmtNode(ifK,lineno); (yyval.tNode)->child[0]=(yyvsp[-2].tNode); (yyval.tNode)->child[1]=(yyvsp[0].tNode); }
#line 2112 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 402 "parser.y" /* yacc.c:1646  */
    { int lineno=(yyvsp[-6].tokenData)->lineno; (yyval.tNode) = newStmtNode(ifK,lineno); (yyval.tNode)->child[0]=(yyvsp[-4].tNode); (yyval.tNode)->child[1]=(yyvsp[-2].tNode); (yyval.tNode)->child[2]=(yyvsp[0].tNode); }
#line 2118 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 403 "parser.y" /* yacc.c:1646  */
    { int lineno=(yyvsp[-4].tokenData)->lineno; (yyval.tNode) = newStmtNode(whileK,lineno); (yyval.tNode)->child[0]=(yyvsp[-2].tNode); (yyval.tNode)->child[1]=(yyvsp[0].tNode); }
#line 2124 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 404 "parser.y" /* yacc.c:1646  */
    { int lineno=(yyvsp[-6].tokenData)->lineno; (yyval.tNode) = newStmtNode(foreachK,lineno); (yyval.tNode)->child[0]=(yyvsp[-4].tNode); (yyval.tNode)->child[1]=(yyvsp[-2].tNode); (yyval.tNode)->child[2]=(yyvsp[0].tNode); }
#line 2130 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 407 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newStmtNode(returnK,yylval.tokenData->lineno); }
#line 2136 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 408 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newStmtNode(returnK,yylval.tokenData->lineno); (yyval.tNode)->child[0] = (yyvsp[-1].tNode); }
#line 2142 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 411 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newStmtNode(breakK,yylval.tokenData->lineno); }
#line 2148 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 417 "parser.y" /* yacc.c:1646  */
    {
  (yyval.tNode) = newExpNode(assignK,yylval.tokenData->lineno);
  (yyval.tNode)->attr.op = eqK;
  (yyval.tNode)->child[0] = (yyvsp[-2].tNode);
  (yyval.tNode)->child[1] = (yyvsp[0].tNode);
 }
#line 2159 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 423 "parser.y" /* yacc.c:1646  */
    {
  (yyval.tNode) = newExpNode(assignK,yylval.tokenData->lineno);
  (yyval.tNode)->attr.op = peqK;
  (yyval.tNode)->child[0] = (yyvsp[-2].tNode);
  (yyval.tNode)->child[1] = (yyvsp[0].tNode);
 }
#line 2170 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 429 "parser.y" /* yacc.c:1646  */
    {
  (yyval.tNode) = newExpNode(assignK,yylval.tokenData->lineno);
  (yyval.tNode)->attr.op = meqK;
  (yyval.tNode)->child[0] = (yyvsp[-2].tNode);
  (yyval.tNode)->child[1] = (yyvsp[0].tNode);
 }
#line 2181 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 435 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(assignK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = ppK; (yyval.tNode)->child[0] = (yyvsp[-1].tNode); }
#line 2187 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 436 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(assignK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = mmK; (yyval.tNode)->child[0] = (yyvsp[-1].tNode); }
#line 2193 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 437 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2199 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 440 "parser.y" /* yacc.c:1646  */
    {
  (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno);
  (yyval.tNode)->attr.op = orK;
  (yyval.tNode)->child[0] = (yyvsp[-2].tNode);
  (yyval.tNode)->child[1] = (yyvsp[0].tNode);
  (yyval.tNode)->isConstant = (yyvsp[-2].tNode)->isConstant & (yyvsp[0].tNode)->isConstant;
 }
#line 2211 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 447 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); (yyval.tNode)->isConstant = (yyvsp[0].tNode)->isConstant; }
#line 2217 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 450 "parser.y" /* yacc.c:1646  */
    {
  (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno);
  (yyval.tNode)->attr.op = andK;
  (yyval.tNode)->child[0] = (yyvsp[-2].tNode);
  (yyval.tNode)->child[1] = (yyvsp[0].tNode);
  (yyval.tNode)->isConstant = (yyvsp[-2].tNode)->isConstant & (yyvsp[0].tNode)->isConstant;
 }
#line 2229 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 457 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); (yyval.tNode)->isConstant = (yyvsp[0].tNode)->isConstant; }
#line 2235 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 460 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = notK; (yyval.tNode)->child[0]=(yyvsp[0].tNode); (yyval.tNode)->isConstant = (yyvsp[0].tNode)->isConstant; }
#line 2241 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 461 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); (yyval.tNode)->isConstant = (yyvsp[0].tNode)->isConstant; }
#line 2247 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 464 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[-1].tNode); (yyval.tNode)->child[0] = (yyvsp[-2].tNode); (yyval.tNode)->child[1] = (yyvsp[0].tNode); (yyval.tNode)->isConstant = (yyvsp[-2].tNode)->isConstant & (yyvsp[0].tNode)->isConstant; }
#line 2253 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 465 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); (yyval.tNode)->isConstant = (yyvsp[0].tNode)->isConstant; }
#line 2259 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 468 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = lteqK; }
#line 2265 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 469 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = ltK; }
#line 2271 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 470 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = gtK; }
#line 2277 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 471 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = gteqK; }
#line 2283 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 472 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = equivK; }
#line 2289 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 473 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = neqK; }
#line 2295 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 476 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[-1].tNode); (yyval.tNode)->child[0]=(yyvsp[-2].tNode); (yyval.tNode)->child[1]=(yyvsp[0].tNode); (yyval.tNode)->isConstant = (yyvsp[-2].tNode)->isConstant & (yyvsp[0].tNode)->isConstant; }
#line 2301 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 477 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); (yyval.tNode)->isConstant=(yyvsp[0].tNode)->isConstant; }
#line 2307 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 480 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = plusK; }
#line 2313 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 481 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = minusK; }
#line 2319 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 484 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[-1].tNode); (yyval.tNode)->child[0] = (yyvsp[-2].tNode); (yyval.tNode)->child[1]=(yyvsp[0].tNode); (yyval.tNode)->isConstant = (yyvsp[-2].tNode)->isConstant & (yyvsp[0].tNode)->isConstant; }
#line 2325 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 485 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); (yyval.tNode)->isConstant = (yyvsp[0].tNode)->isConstant; }
#line 2331 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 488 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = multiK; }
#line 2337 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 489 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = divideK; }
#line 2343 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 490 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = modK; }
#line 2349 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 493 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[-1].tNode); (yyval.tNode)->child[0]=(yyvsp[0].tNode); (yyval.tNode)->isConstant = (yyvsp[0].tNode)->isConstant; }
#line 2355 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 494 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2361 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 497 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = UminusK; }
#line 2367 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 498 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(opK,yylval.tokenData->lineno); (yyval.tNode)->attr.op = UmultiK; }
#line 2373 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 501 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2379 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 502 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2385 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 505 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(idK,yylval.tokenData->lineno); (yyval.tNode)->attr.name=(yyvsp[0].tokenData)->idvalue; }
#line 2391 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 506 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(idK,(yyvsp[-3].tokenData)->lineno); (yyval.tNode)->child[0] = (yyvsp[-1].tNode); (yyval.tNode)->attr.name=(yyvsp[-3].tokenData)->idvalue; (yyval.tNode)->isArray=true; }
#line 2397 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 509 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[-1].tNode); }
#line 2403 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 510 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2409 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 511 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); (yyval.tNode)->isConstant = true; }
#line 2415 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 514 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(callK, yylval.tokenData->lineno); (yyval.tNode)->child[0] = (yyvsp[-1].tNode); (yyval.tNode)->attr.name=(yyvsp[-3].tokenData)->idvalue;  }
#line 2421 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 517 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2427 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 518 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = NULL; }
#line 2433 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 521 "parser.y" /* yacc.c:1646  */
    { TreeNode* t = (yyvsp[-2].tNode);
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
#line 2449 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 532 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2455 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 536 "parser.y" /* yacc.c:1646  */
    { TreeNode* t = (yyvsp[-2].tNode);
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
#line 2471 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 547 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = (yyvsp[0].tNode); }
#line 2477 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 550 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(constK,yylval.tokenData->lineno); (yyval.tNode)->attr.val = (yyvsp[0].tokenData)->numvalue; (yyval.tNode)->expType=Int; (yyval.tNode)->isConstant=true; }
#line 2483 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 551 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(constK,yylval.tokenData->lineno); (yyval.tNode)->attr.string = (yyvsp[0].tokenData)->tokenstr; (yyval.tNode)->expType=Char; (yyval.tNode)->isConstant=true; }
#line 2489 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 552 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(constK,yylval.tokenData->lineno); (yyval.tNode)->attr.string = (yyvsp[0].tokenData)->tokenstr; (yyval.tNode)->expType=Char; (yyval.tNode)->isConstant=true; }
#line 2495 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 553 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(constK,yylval.tokenData->lineno); (yyval.tNode)->expType=Bool; (yyval.tNode)->attr.bval=true; (yyval.tNode)->isConstant=true; }
#line 2501 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 554 "parser.y" /* yacc.c:1646  */
    { (yyval.tNode) = newExpNode(constK,yylval.tokenData->lineno); (yyval.tNode)->expType=Bool; (yyval.tNode)->attr.bval=false; (yyval.tNode)->isConstant=true; }
#line 2507 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2511 "parser.tab.c" /* yacc.c:1646  */
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
#line 557 "parser.y" /* yacc.c:1906  */


int main(int argc, char* argv[])
{
  int c;
  extern char* optarg;
  extern int optind;
  char **inputfile;
  yydebug=0;

  int printTreeFlag = 0;
  int symbolTracing = 0;

  //yyin = fopen(argv[1], "r");
  //outputfile = fopen("output.txt", "w");

  while((c = getopt(argc, argv, "dps:")) != EOF)
    {
      switch(c)
        {
        case 'd':
          yydebug=1;
          printf("YYDEBUG==%d",yydebug);
          break;
        case 'p':
          printTreeFlag = 1;
          break;
        case 's':
          symbolTracing = 1;
          break;
        default:
          printf("Unknown option(s)\n");
          break;
        }
      c = getopt(argc, argv, "d:p:s");
    }
  inputfile = argv + optind;
  yyin = fopen((inputfile[0]), "r");


  yyparse();
    
  if(printTreeFlag)
    printTree(savedTree);

  //set the preprocess to savedTree
  preProcess();
  savedTree = output;

  checkNode(savedTree);

  if(symbolTracing)
    tab->print();

  printf("Number of Warnings: %d\n", numwarnings);
  printf("Number of Errors: %d\n", numerrors);
  

  //derpNode(savedTree);

  //checkNode(savedTree);

  //printf("Number of Errors: %d\n", numerrors);
  //printf("Number of Warnings: %d\n", numwarnings);

  return 0;
}
