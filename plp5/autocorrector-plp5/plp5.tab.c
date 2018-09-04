/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 19 "plp5.y" /* yacc.c:339  */

	/*-----------------------------------
	|        Declaraciones en C++        |
	------------------------------------*/
	#include <stdio.h>
	#include <stdlib.h>
	#include <string>
	#include <cstring>
	#include <iostream>
	#include <vector>
	#include <sstream>
	#include "comun.h"
	#include <stack>

	using namespace std;

	extern int ncol, nlin, findefichero;

	extern int yylex();
	extern char *yytext;
	extern FILE *yyin;

	int yyerror(char *s);
	void msgError(int nerror,int nlin,int ncol,const char *s);

	const int ENTERO = 1;
	const int REAL = 2;
	const int LOGIC = 3;
	const int TABLA = 4;

	const int MAXMEMORY = 16384;
    const int MAXMEMORYDATA = 16000;
	const int posInit = MAXMEMORYDATA;
	int posActual = posInit;
	int memoryData = 0;

	typedef struct{
		string nombre;
		int tipo;
		int pos;
	}Simbolo;

	struct TablaSimbolos{
		vector<Simbolo> simbolos;
	};

	struct Tipo{
		int tipo;
		int tam;
		int t_base;
	};

	struct TablaTipos{
		vector<Tipo> tipos;
	};

	TablaTipos tt;
	TablaSimbolos ts;
	int etiquetas;

	int NuevoTemporal();
	bool anyadirS(string nombre, int tipo, int tam);
	bool buscarS(Simbolo& simbolo, string nombre);
	int tamT(int tipo);
	int anyadirT(int tam, int t_base);
	int buscarT(int tipo);
	void borrarTemp();
	bool esArray(int tipo);
	int getEtiqueta();
	void init();
	void printMemoryInfo();
	void printTablaTipos();


#line 141 "plp5.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "plp5.tab.h".  */
#ifndef YY_YY_PLP5_TAB_H_INCLUDED
# define YY_YY_PLP5_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    algoritmo = 258,
    falgoritmo = 259,
    var = 260,
    fvar = 261,
    entero = 262,
    real = 263,
    logico = 264,
    tabla = 265,
    de = 266,
    escribe = 267,
    lee = 268,
    si = 269,
    entonces = 270,
    sino = 271,
    mientras = 272,
    hacer = 273,
    blq = 274,
    fblq = 275,
    cierto = 276,
    falso = 277,
    id = 278,
    nentero = 279,
    nreal = 280,
    coma = 281,
    pyc = 282,
    dospto = 283,
    pari = 284,
    pard = 285,
    oprel = 286,
    opas = 287,
    opmd = 288,
    opasig = 289,
    cori = 290,
    cord = 291,
    ybool = 292,
    obool = 293,
    nobool = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PLP5_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 232 "plp5.tab.c" /* yacc.c:358  */

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   89

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  92

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    98,    98,    98,   108,   109,   112,   115,   115,   125,
     126,   129,   129,   138,   141,   142,   143,   144,   144,   153,
     154,   157,   183,   242,   256,   275,   294,   338,   341,   341,
     358,   361,   361,   378,   381,   440,   443,   491,   492,   495,
     546,   549,   561,   570,   579,   584,   601,   609,   619,   635,
     635
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "algoritmo", "falgoritmo", "var", "fvar",
  "entero", "real", "logico", "tabla", "de", "escribe", "lee", "si",
  "entonces", "sino", "mientras", "hacer", "blq", "fblq", "cierto",
  "falso", "id", "nentero", "nreal", "coma", "pyc", "dospto", "pari",
  "pard", "oprel", "opas", "opmd", "opasig", "cori", "cord", "ybool",
  "obool", "nobool", "$accept", "S", "$@1", "SDec", "Dec", "DVar", "@2",
  "MDVar", "LId", "@3", "Tipo", "$@4", "SInstr", "Instr", "Expr", "$@5",
  "Econj", "$@6", "Ecomp", "Esimple", "Term", "Factor", "Ref", "$@7", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -48

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      10,   -17,    15,     1,   -48,   -48,    31,    53,    34,   -48,
     -48,   -48,   -48,    44,    53,    11,    20,    46,    20,    20,
      34,   -48,     3,   -48,    30,   -48,    53,    48,    47,   -48,
     -48,   -48,   -48,    20,    -2,    -2,    33,    36,   -48,    35,
      39,   -48,    40,    40,    -7,   -12,     8,   -48,    34,    20,
     -48,    63,   -48,   -48,   -48,    -5,    39,   -48,   -48,   -48,
      20,    -2,    -2,    34,    34,   -48,   -48,    33,    20,    53,
      50,   -48,    20,    20,    49,    39,   -48,    62,   -48,   -22,
     -48,    56,    55,    36,   -48,    34,   -48,   -48,   -48,   -48,
      50,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     2,     5,     0,     0,     4,
      14,    15,    16,     0,    10,     0,     0,     0,     0,     0,
       0,    48,     0,    20,     0,    17,    10,     0,     0,    46,
      47,    42,    43,     0,     0,     0,    21,    30,    33,    35,
      37,    40,    41,    22,     0,     0,     0,     3,     0,     0,
      49,     0,     9,     6,     7,     0,    38,    45,    28,    31,
       0,     0,     0,     0,     0,    27,    19,    26,     0,     0,
      13,    44,     0,     0,    34,    36,    39,    23,    25,     0,
      18,     0,     0,    29,    32,     0,    50,    11,     8,    24,
      13,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,   -48,   -48,   -48,    73,   -48,    57,    -6,   -48,
      16,   -48,    66,   -47,   -15,   -48,    17,   -48,    14,   -10,
     -32,   -30,    -8,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     6,     8,     9,    26,    70,    27,    82,    90,
      15,    51,    22,    23,    36,    72,    37,    73,    38,    39,
      40,    41,    42,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      24,    66,    56,    44,    45,    57,    64,    47,    63,    43,
      61,     3,    24,     1,    86,     4,    77,    78,    55,    29,
      30,    21,    31,    32,     5,    71,    58,    33,    65,    75,
      48,    58,    76,    58,    67,    48,     7,    35,    89,    28,
      24,    29,    30,    21,    31,    32,    16,    17,    18,    33,
      74,    19,    34,    20,    53,    24,    24,    21,    79,    35,
      10,    11,    12,    13,    49,    50,    60,    61,    25,    21,
      54,    58,    62,    59,    69,    50,    81,    24,    85,    87,
      14,    61,    88,    52,    91,    80,    46,    84,     0,    83
};

static const yytype_int8 yycheck[] =
{
       8,    48,    34,    18,    19,    35,    18,     4,    15,    17,
      32,    28,    20,     3,    36,     0,    63,    64,    33,    21,
      22,    23,    24,    25,    23,    30,    38,    29,    20,    61,
      27,    38,    62,    38,    49,    27,     5,    39,    85,    28,
      48,    21,    22,    23,    24,    25,    12,    13,    14,    29,
      60,    17,    32,    19,     6,    63,    64,    23,    68,    39,
       7,     8,     9,    10,    34,    35,    31,    32,    24,    23,
      23,    38,    33,    37,    11,    35,    26,    85,    16,    23,
       7,    32,    27,    26,    90,    69,    20,    73,    -1,    72
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    41,    28,     0,    23,    42,     5,    43,    44,
       7,     8,     9,    10,    45,    50,    12,    13,    14,    17,
      19,    23,    52,    53,    62,    24,    45,    47,    28,    21,
      22,    24,    25,    29,    32,    39,    54,    56,    58,    59,
      60,    61,    62,    62,    54,    54,    52,     4,    27,    34,
      35,    51,    47,     6,    23,    54,    60,    61,    38,    37,
      31,    32,    33,    15,    18,    20,    53,    54,    63,    11,
      46,    30,    55,    57,    59,    60,    61,    53,    53,    59,
      50,    26,    48,    56,    58,    16,    36,    23,    27,    53,
      49,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    42,    41,    43,    43,    44,    46,    45,    47,
      47,    49,    48,    48,    50,    50,    50,    51,    50,    52,
      52,    53,    53,    53,    53,    53,    53,    53,    55,    54,
      54,    57,    56,    56,    58,    58,    59,    59,    59,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    62,    63,
      62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     1,     0,     4,     0,     6,     2,
       0,     0,     4,     0,     1,     1,     1,     0,     5,     3,
       1,     2,     2,     4,     6,     4,     3,     3,     0,     4,
       1,     0,     4,     1,     3,     1,     3,     1,     2,     3,
       1,     1,     1,     1,     3,     2,     1,     1,     1,     0,
       5
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
#line 98 "plp5.y" /* yacc.c:1661  */
    { init(); }
#line 1372 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 98 "plp5.y" /* yacc.c:1661  */
    {	
																	int tk = yylex();
																	if(tk!=0){ 
																		yyerror("");
																	} 
																	//printTablaTipos();
																	cout << "\n" << (yyvsp[-1]).cod << "halt\n";
																	//printMemoryInfo();
																}
#line 1386 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 109 "plp5.y" /* yacc.c:1661  */
    { (yyval).cod = ""; }
#line 1392 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 115 "plp5.y" /* yacc.c:1661  */
    { 	
									if(anyadirS((yyvsp[0]).lexema,(yyvsp[-2]).tipo, (yyvsp[-2]).tam)){
										(yyval).tipo = (yyvsp[-2]).tipo;
										(yyval).tam = (yyvsp[-2]).tam;
									}else{
										msgError(ERRYADECL, (yyvsp[0]).nlin, (yyvsp[0]).ncol, (yyvsp[0]).lexema.c_str());
									}
								}
#line 1405 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 126 "plp5.y" /* yacc.c:1661  */
    { (yyval).cod = ""; }
#line 1411 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 129 "plp5.y" /* yacc.c:1661  */
    {	
							if(anyadirS((yyvsp[0]).lexema,(yyvsp[-2]).tipo, (yyvsp[-2]).tam)){
								(yyval).tipo = (yyvsp[-2]).tipo;
								(yyval).tam = (yyvsp[-2]).tam;
							}else{
								msgError(ERRYADECL, (yyvsp[0]).nlin, (yyvsp[0]).ncol, (yyvsp[0]).lexema.c_str());
							}
							
					  	}
#line 1425 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 138 "plp5.y" /* yacc.c:1661  */
    { (yyval).cod = ""; }
#line 1431 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 141 "plp5.y" /* yacc.c:1661  */
    { (yyval).tipo = ENTERO; (yyval).tam = 1; }
#line 1437 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 142 "plp5.y" /* yacc.c:1661  */
    { (yyval).tipo = REAL; (yyval).tam = 1; }
#line 1443 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 143 "plp5.y" /* yacc.c:1661  */
    { (yyval).tipo = LOGIC; (yyval).tam = 1; }
#line 1449 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 144 "plp5.y" /* yacc.c:1661  */
    { 	if( atoi((yyvsp[0]).lexema.c_str()) < 1){
									msgError(ERRDIM, (yyvsp[0]).nlin, (yyvsp[0]).ncol, (yyvsp[0]).lexema.c_str());
								} 
							}
#line 1458 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 147 "plp5.y" /* yacc.c:1661  */
    {	
											(yyval).tipo = anyadirT(atoi((yyvsp[-3]).lexema.c_str()), (yyvsp[0]).tipo);
											(yyval).tam = atoi((yyvsp[-3]).lexema.c_str())*(yyvsp[0]).tam;
										}
#line 1467 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 153 "plp5.y" /* yacc.c:1661  */
    { (yyval).cod = (yyvsp[-2]).cod+"\n"+(yyvsp[0]).cod; }
#line 1473 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 154 "plp5.y" /* yacc.c:1661  */
    { (yyval).cod = (yyvsp[0]).cod; }
#line 1479 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 157 "plp5.y" /* yacc.c:1661  */
    {	
								stringstream ss;
								if((yyvsp[0]).tipo == ENTERO){
									ss << (yyvsp[0]).cod << "wri " << (yyvsp[0]).dir << "\nwrl\n";
									(yyval).cod = ss.str();
								}else if((yyvsp[0]).tipo == REAL){
									ss << (yyvsp[0]).cod << "wrr " << (yyvsp[0]).dir << "\nwrl\n";
									(yyval).cod = ss.str();
								}else{
									int tmp = NuevoTemporal();
									int e1, e2;
									e1 = getEtiqueta();
									e2 = getEtiqueta();
									ss << (yyvsp[0]).cod;
									ss << "mov " << (yyvsp[0]).dir << " A\n";
									ss << "jz L" << e1 << "\n";
									ss << "mov #99 " << (yyvsp[0]).dir << "\n";
									ss << "jmp L" << e2 << "\n";
									ss << "L" << e1 << "\n";
									ss << "mov #102 " << (yyvsp[0]).dir << "\n";
									ss << "L" << e2 << "\n";
									ss << "wrc " << (yyvsp[0]).dir << "\nwrl\n";
									(yyval).cod = ss.str();
								}
								borrarTemp();
							}
#line 1510 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 183 "plp5.y" /* yacc.c:1661  */
    {	
							stringstream ss;

							if((yyvsp[0]).tipo == ENTERO){
								int tmp = NuevoTemporal();

								if((yyvsp[0]).is_array){
									ss << (yyvsp[0]).cod;
								}else{
									ss << "mov #" << (yyvsp[0]).dir_base << " " << (yyvsp[0]).dir << "\n";
								}

								ss << "rdi " << tmp << "\n";
								ss << "mov " << (yyvsp[0]).dir << " A\n";
								ss << "mov " << tmp << " @A\n";
								ss << "wrl\n";
								(yyval).cod = ss.str();
							}else if((yyvsp[0]).tipo == REAL){
								int tmp = NuevoTemporal();

								if((yyvsp[0]).is_array){
									ss << (yyvsp[0]).cod;
								}else{
									ss << "mov #" << (yyvsp[0]).dir_base << " " << (yyvsp[0]).dir << "\n";
								}

								ss << "rdr " << tmp << "\n";
								ss << "mov " << (yyvsp[0]).dir << " A\n";
								ss << "mov " << tmp << " @A\n";
								ss << "wrl\n";
								(yyval).cod = ss.str();
							}else{
								int tmp = NuevoTemporal();
								int e1, e2;
								e1 = getEtiqueta();
								e2 = getEtiqueta();

								if((yyvsp[0]).is_array){
									ss << (yyvsp[0]).cod;
								}else{
									ss << "mov #" << (yyvsp[0]).dir_base << " " << (yyvsp[0]).dir << "\n";
								}

								ss << "rdc " << tmp << "\n";
								ss << "mov " << tmp << "A\n";
								ss << "subi #99\n";
								ss << "jz L" << e1 << "\n";
								ss << "mov " << (yyvsp[0]).dir << " A\n";
								ss << "mov #0 @A\n";
								ss << "jmp L" << e2 << "\n";
								ss <<  "L" << e1 << "\n";
								ss << "mov " << (yyvsp[0]).dir << " A\n";
								ss << "mov #1 @A\n";
								ss << "L" << e2 << "\n";
								ss << "wrl\n";
								(yyval).cod = ss.str();
							}
							borrarTemp();
						}
#line 1574 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 242 "plp5.y" /* yacc.c:1661  */
    {
											if((yyvsp[-2]).tipo!=LOGIC){
												msgError(ERR_EXP_LOG, (yyvsp[-3]).nlin, (yyvsp[-3]).ncol, (yyvsp[-3]).lexema.c_str());
											}else{
												stringstream ss;
												int e1 = getEtiqueta();
												ss << (yyvsp[-2]).cod << "mov " << (yyvsp[-2]).dir << " A\n";
												ss << "jz L" << e1 << "\n";
												ss << (yyvsp[0]).cod;
												ss << "L" << e1 << "\n";
												(yyval).cod = ss.str();
												borrarTemp();
											}
										}
#line 1593 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 256 "plp5.y" /* yacc.c:1661  */
    {
													if((yyvsp[-4]).tipo!=LOGIC){
														msgError(ERR_EXP_LOG, (yyvsp[-4]).nlin, (yyvsp[-4]).ncol, (yyvsp[-4]).lexema.c_str());
													}else{
														stringstream ss;
														int e1, e2;
														e1 = getEtiqueta();
														e2 = getEtiqueta();
														ss << (yyvsp[-4]).cod << "mov " << (yyvsp[-4]).dir << " A\n";
														ss << "jz L" << e1 << "\n";
														ss << (yyvsp[-2]).cod;
														ss << "jmp L" << e2 << "\n";
														ss << "L" << e1 << "\n";
														ss << (yyvsp[0]).cod;
														ss << "\nL" << e2 << "\n";
														(yyval).cod = ss.str();
														borrarTemp();
													}
												}
#line 1617 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 275 "plp5.y" /* yacc.c:1661  */
    {
											if((yyvsp[-2]).tipo!=LOGIC){
												msgError(ERR_EXP_LOG, (yyvsp[-2]).nlin, (yyvsp[-2]).ncol, (yyvsp[-2]).lexema.c_str());
											}else{
												stringstream ss;
												int e1, e2;
												e1 = getEtiqueta();
												e2 = getEtiqueta();
												ss << "L" << e1 << "\n";
												ss << (yyvsp[-2]).cod;
												ss << "mov " << (yyvsp[-2]).dir << " A\n";
												ss << "jz L" << e2 << "\n";
												ss << (yyvsp[0]).cod;
												ss << "jmp L" << e1 << "\n";
												ss << "L" << e2 << "\n";
												(yyval).cod = ss.str();
												borrarTemp();
											}
										}
#line 1641 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 294 "plp5.y" /* yacc.c:1661  */
    { 
								if(esArray((yyvsp[-2]).tipo)){
									msgError(ERRFALTAN, (yyvsp[-1]).nlin, ((yyvsp[-1]).ncol-(yyvsp[-2]).lexema.size()-1), (yyvsp[-2]).lexema.c_str());
								}
                                if((yyvsp[-2]).tipo == LOGIC && (yyvsp[0]).tipo != LOGIC){
									msgError(ERR_EXDER_LOG, (yyvsp[-1]).nlin, (yyvsp[-1]).ncol, (yyvsp[-1]).lexema.c_str());
								}
                                if((yyvsp[-2]).tipo != LOGIC && (yyvsp[0]).tipo == LOGIC){
									msgError(ERR_EXDER_RE, (yyvsp[-1]).nlin, (yyvsp[-1]).ncol, (yyvsp[-1]).lexema.c_str());
								}
								
								stringstream ss;
								int Seof = tamT((yyvsp[-2]).tipo);
								if((yyvsp[-2]).tipo == ENTERO && (yyvsp[0]).tipo == ENTERO){
                                    ss << (yyvsp[-2]).cod << (yyvsp[0]).cod;
                                    ss << "mov " << (yyvsp[-2]).dir << " A\n";
                                    ss << "muli #" << Seof;
                                    ss << "\naddi #" << (yyvsp[-2]).dir_base;
                                    ss << "\nmov " << (yyvsp[0]).dir << " @A\n";
                                    (yyval).cod = ss.str();
                                }else if((yyvsp[-2]).tipo == REAL && (yyvsp[0]).tipo == ENTERO){
                                    int tmp = NuevoTemporal();
                                    ss << (yyvsp[-2]).cod << (yyvsp[0]).cod;
                                    ss << "mov " << (yyvsp[0]).dir << " A\n";
                                    ss << "itor\n";
                                    ss << "mov A " << tmp << "\n";
                                    ss << "mov " << (yyvsp[-2]).dir << " A\n";
                                    ss << "muli #" << Seof;
                                    ss << "\naddi #" << (yyvsp[-2]).dir_base;
                                    ss << "\nmov " << tmp << " @A\n";
                                    (yyval).cod = ss.str();
                                }else if((yyvsp[-2]).tipo == ENTERO && (yyvsp[0]).tipo == REAL){
                                    msgError(ERR_EXDER_ENT, (yyvsp[-1]).nlin, (yyvsp[-1]).ncol, (yyvsp[-1]).lexema.c_str());
                                }else { 
                                    ss << (yyvsp[-2]).cod << (yyvsp[0]).cod;
                                    ss << "mov " << (yyvsp[-2]).dir << " A\n";
                                    ss << "muli #" << Seof;
                                    ss << "\naddi #" << (yyvsp[-2]).dir_base;
                                    ss << "\nmov " << (yyvsp[0]).dir << " @A\n";
                                    (yyval).cod = ss.str();
                                }
								
								borrarTemp();
							  }
#line 1690 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 338 "plp5.y" /* yacc.c:1661  */
    { (yyval).cod = (yyvsp[-1]).cod; borrarTemp(); }
#line 1696 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 341 "plp5.y" /* yacc.c:1661  */
    {	if((yyvsp[-1]).tipo!=LOGIC){
								msgError(ERR_EXIZQ_LOG, (yyvsp[0]).nlin, (yyvsp[0]).ncol, (yyvsp[0]).lexema.c_str());
							}
						}
#line 1705 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 344 "plp5.y" /* yacc.c:1661  */
    { 
										if((yyvsp[0]).tipo!=LOGIC){
											msgError(ERR_EXDER_LOG  , (yyvsp[-2]).nlin, (yyvsp[-2]).ncol, (yyvsp[-2]).lexema.c_str());
										}
										stringstream ss;
										int tmp = NuevoTemporal();
										ss << (yyvsp[-3]).cod << (yyvsp[0]).cod;
										ss << "mov " << (yyvsp[-3]).dir << " A\n";
										ss << "ori " << (yyvsp[0]).dir;
										ss << "\nmov A " << tmp << "\n";
										(yyval).cod = ss.str();
										(yyval).dir = tmp;
										(yyval).tipo = LOGIC;
									}
#line 1724 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 358 "plp5.y" /* yacc.c:1661  */
    { (yyval).tipo = (yyvsp[0]).tipo; (yyval).cod = (yyvsp[0]).cod; (yyval).dir = (yyvsp[0]).dir; }
#line 1730 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 361 "plp5.y" /* yacc.c:1661  */
    {	if((yyvsp[-1]).tipo!=LOGIC){
									msgError(ERR_EXIZQ_LOG, (yyvsp[0]).nlin, (yyvsp[0]).ncol, (yyvsp[0]).lexema.c_str());
								}
							}
#line 1739 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 364 "plp5.y" /* yacc.c:1661  */
    {
										if((yyvsp[0]).tipo!=LOGIC){
											msgError(ERR_EXDER_LOG, (yyvsp[-2]).nlin, (yyvsp[-2]).ncol, (yyvsp[-2]).lexema.c_str());
										}
										stringstream ss;
										int tmp = NuevoTemporal();
										ss << (yyvsp[-3]).cod << (yyvsp[0]).cod;
										ss << "mov " << (yyvsp[-3]).dir << " A\n";
										ss << "andi " << (yyvsp[0]).dir;
										ss << "\nmov A " << tmp << "\n";
										(yyval).cod = ss.str();
										(yyval).dir = tmp;
										(yyval).tipo = LOGIC;
									}
#line 1758 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 378 "plp5.y" /* yacc.c:1661  */
    { (yyval).tipo = (yyvsp[0]).tipo; (yyval).cod = (yyvsp[0]).cod; (yyval).dir = (yyvsp[0]).dir; }
#line 1764 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 381 "plp5.y" /* yacc.c:1661  */
    {
										if((yyvsp[-2]).tipo!=ENTERO && (yyvsp[-2]).tipo!=REAL){
											msgError(ERR_EXIZQ_RE, (yyvsp[-1]).nlin, (yyvsp[-1]).ncol, (yyvsp[-1]).lexema.c_str());
										}
										if((yyvsp[0]).tipo!=ENTERO && (yyvsp[0]).tipo!=REAL){
											msgError(ERR_EXDER_RE, (yyvsp[-1]).nlin, (yyvsp[-1]).ncol, (yyvsp[-1]).lexema.c_str());
										}
										
										stringstream ss;
										string op;

										if((yyvsp[-1]).lexema == "="){
											op = "eql";
										}else if((yyvsp[-1]).lexema == "<>"){
											op = "neq";
										}else if((yyvsp[-1]).lexema == "<"){
											op = "lss";
										}else if((yyvsp[-1]).lexema == "<="){
											op = "leq";
										}else if((yyvsp[-1]).lexema == ">"){
											op = "gtr";
										}else {
											op = "geq";
										}

										int tmp = NuevoTemporal();
										(yyval).dir = tmp;
										(yyval).tipo = LOGIC;

										if((yyvsp[-2]).tipo == ENTERO && (yyvsp[0]).tipo == ENTERO){
											ss << (yyvsp[-2]).cod << (yyvsp[0]).cod;
											ss << "mov " << (yyvsp[-2]).dir << " A\n";
											ss << op << "i " << (yyvsp[0]).dir;
											ss << "\nmov A " << tmp << "\n";
											(yyval).cod = ss.str();
										}else if((yyvsp[-2]).tipo == REAL && (yyvsp[0]).tipo == ENTERO){
											ss << (yyvsp[-2]).cod << (yyvsp[0]).cod;
											ss << "mov " << (yyvsp[0]).dir << " A\n";
											ss << "itor\n";
											ss << "mov A " << (yyvsp[0]).dir << "\n"; 
											ss << "mov " << (yyvsp[-2]).dir << " A\n"; 
											ss << op << "r " << (yyvsp[0]).dir;
											ss << "\nmov A " << tmp << "\n";
											(yyval).cod = ss.str();
										}else if((yyvsp[-2]).tipo == ENTERO && (yyvsp[0]).tipo == REAL){
											ss << (yyvsp[-2]).cod << (yyvsp[0]).cod;
											ss << "mov " << (yyvsp[-2]).dir << " A\n";
											ss << "itor\n";
											ss << op << "r " << (yyvsp[0]).dir;
											ss << "\nmov A " << tmp << "\n";
											(yyval).cod = ss.str();
										}else{
											ss << (yyvsp[-2]).cod << (yyvsp[0]).cod;
											ss << "mov " << (yyvsp[-2]).dir << " A\n";
											ss << op << "r " << (yyvsp[0]).dir;
											ss << "\nmov A " << tmp << "\n";
											(yyval).cod = ss.str();
										}
									}
#line 1828 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 440 "plp5.y" /* yacc.c:1661  */
    { (yyval).tipo = (yyvsp[0]).tipo; (yyval).cod = (yyvsp[0]).cod; (yyval).dir = (yyvsp[0]).dir; }
#line 1834 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 443 "plp5.y" /* yacc.c:1661  */
    {	
									if((yyvsp[-2]).tipo==LOGIC){
										msgError(ERR_EXIZQ_RE,(yyvsp[-1]).nlin,(yyvsp[-1]).ncol,(yyvsp[-1]).lexema.c_str());
									}
                                	if((yyvsp[0]).tipo==LOGIC){
										msgError(ERR_EXDER_RE,(yyvsp[-1]).nlin,(yyvsp[-1]).ncol,(yyvsp[-1]).lexema.c_str());
									}

									int tmp = NuevoTemporal();
									string op = (yyvsp[-1]).lexema == "+" ? "add" : "sub";
									(yyval).dir = tmp;
									stringstream ss;
									
									if((yyvsp[-2]).tipo == ENTERO && (yyvsp[0]).tipo == ENTERO){
										ss << (yyvsp[-2]).cod << (yyvsp[0]).cod;
										ss << "mov " << (yyvsp[-2]).dir << " A\n";
										ss << op << "i " << (yyvsp[0]).dir << "\n";
										ss << "mov A " << tmp << "\n";
										(yyval).tipo = ENTERO;
										(yyval).cod = ss.str();
									}else if((yyvsp[-2]).tipo == REAL && (yyvsp[0]).tipo == ENTERO){
										ss << (yyvsp[-2]).cod << (yyvsp[0]).cod;
										int tmpcnv = NuevoTemporal();
										ss << "mov " << (yyvsp[0]).dir << " A\n";
										ss << "itor\n";
										ss << "mov A" << tmpcnv << "\n";
										ss << "mov " << (yyvsp[-2]).dir << " A\n";
										ss << op << "r " << tmpcnv << "\n";
										ss << "mov A " << tmp << "\n";
										(yyval).tipo = REAL;
										(yyval).cod = ss.str();
									}else if((yyvsp[-2]).tipo == ENTERO && (yyvsp[0]).tipo == REAL){
										ss << (yyvsp[-2]).cod << (yyvsp[0]).cod;
										ss << "mov " << (yyvsp[-2]).dir << " A\n";
										ss << "itor\n";
										ss << op << "r " << (yyvsp[0]).dir << "\n";
										ss << "mov A" << tmp << "\n";
										(yyval).tipo = REAL;
										(yyval).cod = ss.str();
									}else{
										ss << (yyvsp[-2]).cod << (yyvsp[0]).cod;
										ss << "mov " << (yyvsp[-2]).dir << " A\n";
										ss << op << "r " << (yyvsp[0]).dir << "\n";
										ss << "mov A" << tmp << "\n";
										(yyval).tipo = REAL;
										(yyval).cod = ss.str();
									}
								}
#line 1887 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 491 "plp5.y" /* yacc.c:1661  */
    { (yyval).tipo = (yyvsp[0]).tipo; (yyval).cod = (yyvsp[0]).cod; (yyval).dir = (yyvsp[0]).dir; }
#line 1893 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 492 "plp5.y" /* yacc.c:1661  */
    { (yyval).tipo = (yyvsp[0]).tipo; (yyval).cod = (yyvsp[0]).cod; (yyval).dir = (yyvsp[0]).dir; }
#line 1899 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 495 "plp5.y" /* yacc.c:1661  */
    {
									if((yyvsp[-2]).tipo==LOGIC){
										msgError(ERR_EXIZQ_RE,(yyvsp[-1]).nlin,(yyvsp[-1]).ncol,(yyvsp[-1]).lexema.c_str());
									}
									if((yyvsp[0]).tipo==LOGIC){
										msgError(ERR_EXDER_RE,(yyvsp[-1]).nlin,(yyvsp[-1]).ncol,(yyvsp[-1]).lexema.c_str());
									}

									int temp = NuevoTemporal();
									string op = (yyvsp[-1]).lexema == "*" ? "mul" : "div";
									(yyval).dir = temp;
									stringstream ss; 
									if((yyvsp[-2]).tipo == ENTERO && (yyvsp[0]).tipo == ENTERO){
										ss << (yyvsp[-2]).cod;
										ss << (yyvsp[0]).cod;
										ss << "mov " << (yyvsp[-2]).dir << " A\n";
										ss << op << "i " << (yyvsp[0]).dir;
										ss << "\nmov A " << temp << "\n";
										(yyval).cod = ss.str();
										(yyval).tipo = ENTERO;
									}else if((yyvsp[-2]).tipo == REAL && (yyvsp[0]).tipo == ENTERO){
										int tmpcnv = NuevoTemporal();
										ss << (yyvsp[-2]).cod;
										ss << (yyvsp[0]).cod;
										ss << "mov " << (yyvsp[0]).dir << " A\n";
										ss << "itor\n";
										ss << "mov A " << tmpcnv;
										ss << "\nmov " << (yyvsp[-2]).dir << " A\n";
										ss << op << "r " << tmpcnv;
										ss << "\nmov A " << temp << "\n";
										(yyval).cod = ss.str();
										(yyval).tipo = REAL;
									}else if((yyvsp[-2]).tipo == ENTERO && (yyvsp[0]).tipo == REAL){
										ss << (yyvsp[-2]).cod;
										ss << (yyvsp[0]).cod;
										ss << "mov " << (yyvsp[-2]).dir << " A\n";
										ss << "itor\n";
										ss << op << "r " << (yyvsp[0]).dir;
										ss << "\nmov A " << temp << "\n";
										(yyval).cod = ss.str();                                    
										(yyval).tipo = REAL;
									}else{
										ss << (yyvsp[-2]).cod;
										ss << (yyvsp[0]).cod;
										ss << "mov " << (yyvsp[-2]).dir << " A\n";
										ss << op << "r " << (yyvsp[0]).dir;
										ss << "\nmov A " << temp << "\n";
										(yyval).cod = ss.str();                                    
										(yyval).tipo = REAL;
									}
								}
#line 1955 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 546 "plp5.y" /* yacc.c:1661  */
    { (yyval).tipo = (yyvsp[0]).tipo; (yyval).cod = (yyvsp[0]).cod; (yyval).dir = (yyvsp[0]).dir; }
#line 1961 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 549 "plp5.y" /* yacc.c:1661  */
    {	
						int tmp = NuevoTemporal();
						(yyval).dir = tmp;
						(yyval).tipo = (yyvsp[0]).tipo;
						stringstream ss;
						ss << (yyvsp[0]).cod;
						ss << "mov " << (yyvsp[0]).dir << " A\n";
						ss << "muli #" << tamT((yyvsp[0]).tipo) << "\n";
						ss << "addi #" << (yyvsp[0]).dir_base << "\n";
						ss << "mov @A " << tmp << "\n";;
						(yyval).cod = ss.str();
					}
#line 1978 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 561 "plp5.y" /* yacc.c:1661  */
    { 	
							(yyval).tipo = ENTERO;
							(yyval).trad = (yyvsp[0]).lexema;
							stringstream ss;
							int tmp = NuevoTemporal(); 
							ss << "mov #" << (yyvsp[0]).lexema <<" " << tmp << "\n";
							(yyval).cod = ss.str();
							(yyval).dir = tmp;
					  	}
#line 1992 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 570 "plp5.y" /* yacc.c:1661  */
    { 	
						(yyval).tipo = REAL;
						(yyval).trad = (yyvsp[0]).lexema;
						stringstream ss;
						int tmp = NuevoTemporal(); 
						ss << "mov $" << (yyvsp[0]).lexema << " " << tmp << "\n";
						(yyval).cod = ss.str();
						(yyval).dir = tmp;
					}
#line 2006 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 579 "plp5.y" /* yacc.c:1661  */
    {
									(yyval).tipo = (yyvsp[-1]).tipo;
									(yyval).cod = (yyvsp[-1]).cod;
									(yyval).dir = (yyvsp[-1]).dir;
								}
#line 2016 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 584 "plp5.y" /* yacc.c:1661  */
    {
								if((yyvsp[0]).tipo != LOGIC){
                                	msgError(ERR_EXP_LOG, (yyvsp[0]).nlin, (yyvsp[0]).ncol, (yyvsp[0]).lexema.c_str());
								}else{
									stringstream ss;
									int tmp = NuevoTemporal();

									ss << (yyvsp[0]).cod;
									ss << "mov " << (yyvsp[0]).dir << " A\n";
									ss << "noti\n";
									ss << "mov A " << tmp << "\n";

									(yyval).tipo = LOGIC;
									(yyval).dir = tmp;
									(yyval).cod = ss.str();
								}
							}
#line 2038 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 601 "plp5.y" /* yacc.c:1661  */
    {
							(yyval).tipo = LOGIC;
							stringstream ss;
							int tmp = NuevoTemporal();
							ss << "mov #1 " << tmp << "\n";
							(yyval).cod = ss.str();
							(yyval).dir = tmp;
						}
#line 2051 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 609 "plp5.y" /* yacc.c:1661  */
    {
						(yyval).tipo = LOGIC;
                        stringstream ss;
                        int tmp = NuevoTemporal();
                        ss << "mov #0 " << tmp << "\n";
                        (yyval).cod = ss.str();
                        (yyval).dir = tmp;
					}
#line 2064 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 619 "plp5.y" /* yacc.c:1661  */
    { 	
					Simbolo aux;
					if(buscarS(aux, (yyvsp[0]).lexema)){
						int tmp = NuevoTemporal();
						stringstream ss;
						ss << "mov #0 " << tmp << "\n";
						(yyval).cod = ss.str();
						(yyval).tipo = aux.tipo;
						(yyval).dir_base = aux.pos;
						(yyval).dir = tmp;
						(yyval).is_array = false;
					}else {
						msgError(ERRNODECL, (yyvsp[0]).nlin,(yyvsp[0]).ncol, (yyvsp[0]).lexema.c_str());
					}

	 			}
#line 2085 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 635 "plp5.y" /* yacc.c:1661  */
    {
						if(!esArray((yyvsp[-1]).tipo)){
							msgError(ERRSOBRAN, (yyvsp[0]).nlin, (yyvsp[0]).ncol, (yyvsp[0]).lexema.c_str());
						}

					}
#line 2096 "plp5.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 640 "plp5.y" /* yacc.c:1661  */
    {
										if((yyvsp[-1]).tipo != ENTERO){
											msgError(ERR_EXP_ENT, (yyvsp[-4]).nlin, (yyvsp[-4]).ncol, (yyvsp[-4]).lexema.c_str());
										}

                                        stringstream ss;
                                        int tmp = NuevoTemporal();
                                        int Seof = tamT((yyvsp[-4]).tipo);

                                        ss << (yyvsp[-4]).cod;
                                        ss << (yyvsp[-1]).cod;
                                        ss << "mov " << (yyvsp[-4]).dir << " A\n";
                                        ss << "muli #" << Seof;
                                        ss << "\naddi " << (yyvsp[-1]).dir;
                                        ss << "\nmov A " << tmp << "\n";

										(yyval).is_array = true;
                                        (yyval).dir = tmp;
                                        (yyval).tipo = buscarT((yyvsp[-4]).tipo);
                                        (yyval).dir_base = (yyvsp[-4]).dir_base;
                                        (yyval).cod = ss.str();
									}
#line 2123 "plp5.tab.c" /* yacc.c:1661  */
    break;


#line 2127 "plp5.tab.c" /* yacc.c:1661  */
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
#line 665 "plp5.y" /* yacc.c:1906  */


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

bool anyadirS(string nombre, int tipo, int tam){

	vector<Simbolo> ss = ts.simbolos;
	for(int i=0;i<ss.size();i++){
		if(ss[i].nombre == nombre){
			return false;
		}
	}

	if(memoryData+tam >= MAXMEMORY){
		msgError(ERR_NOCABE, nlin, ncol, nombre.c_str());
	}

	Simbolo s;
	s.nombre = nombre;
	s.tipo = tipo;
	s.pos = memoryData;
	memoryData += tam;

	ts.simbolos.push_back(s);
	return true;
}

bool buscarS(Simbolo& simbolo, string nombre) {

	vector<Simbolo> ss = ts.simbolos;
	for(int i=0;i<ss.size();i++){
		if (ss[i].nombre == nombre){
			simbolo = ss[i];
			return true;
		}
	}
	 
	return false;	
}

int NuevoTemporal(){
	if(posActual+1 > MAXMEMORY){
		char* e = 0;
		msgError(ERR_MAXTMP, 0, 0, e);
	}
	return posActual++;
}

void borrarTemp(){
	posActual = MAXMEMORYDATA;
}

int tamT(int tipo){
	if(tipo > LOGIC){
		for(int i=0;i<tt.tipos.size();i++){
			if(tt.tipos[i].tipo == tipo){
				return tt.tipos[i].tam;
			}
		}
	}
	
	return 1;
}

int anyadirT(int tam, int t_base){

	Tipo t;
	t.tipo = tt.tipos.size()+1;
	t.tam = tam;
	t.t_base = t_base;

	tt.tipos.push_back(t);
	return tt.tipos.size();
}

void printTablaTipos(){

	cout << "\tTipo\t\tTamaño\t\tTipo Base" << endl;
	cout << "\t----------------------------------------------------" << endl;

	for(int i=0;i<tt.tipos.size();i++){
		cout << "\t" << tt.tipos[i].tipo << "\t\t" << tt.tipos[i].tam << "\t\t" << tt.tipos[i].t_base << endl;
	}

	cout << endl;
}

int buscarT(int tipo){

	if(tipo > LOGIC){
		for(int i=0;i<tt.tipos.size();i++){
			if(tt.tipos[i].tipo == tipo){
				return tt.tipos[i].t_base;
			}
		}
	}

	return tipo;
}

bool esArray(int tipo){
	return tipo > LOGIC;
}

int getEtiqueta(){
	return etiquetas++;
}

void init(){
	Tipo t;
	t.tam = 0;
	t.t_base = 0;
	t.tipo = 1;
	tt.tipos.push_back(t);
	t.tipo = 2;
	tt.tipos.push_back(t);
	t.tipo = 3;
	tt.tipos.push_back(t);
	etiquetas = 0;
}

void printMemoryInfo(){
    vector<Simbolo> auxV = ts.simbolos;
    for(unsigned i=0;i<auxV.size();++i){
        cout << "\nNombre: " << auxV[i].nombre << endl;
        cout << "--------------" << endl;
        
        stack<int> s;
            
        int _tipo = auxV[i].tipo;
        while(_tipo>LOGIC){            
            Tipo t;
            buscarT(_tipo);    
            _tipo = t.t_base;
            s.push(t.tam);
        }   
        int sum = 1;
        if(s.size()>0){
            string tipoS = _tipo == ENTERO ? "enteros" : _tipo == REAL ? "reales" : _tipo == LOGIC ? "booleanos" : "ARRAY";
            cout << "Array de " << tipoS << " de " << s.size() << " dimensiones:";
            while(!s.empty()){
                cout << " [" << s.top() << "]";
                sum *= s.top();
             s.pop();
            }
            cout << endl;
        }
        string tipo = auxV[i].tipo == ENTERO ? "Entero" : auxV[i].tipo == REAL ? "Real" : auxV[i].tipo == LOGIC ? "Booleano" : "Array";
        cout << "Tipo:\t\t" << tipo  << endl;
        if(sum == 1){
            cout << "Posicion:\t[" << auxV[i].pos << "]" << endl;
        }else{
            cout << "Posicion:\t[" << auxV[i].pos << "-" << sum+auxV[i].pos-1 << "]" << endl;
        }
    }
    cout << "\nMemoria usada hasta ahora: " << memoryData << endl;

}

void msgError(int nerror,int nlin,int ncol,const char *s){

	if (nerror != ERREOF){
		fprintf(stderr,"Error %d (%d:%d) ",nerror,nlin,ncol);

		switch (nerror) {
			case ERRLEXICO: fprintf(stderr,"caracter '%s' incorrecto\n",s);
            	break;
			case ERRSINT: fprintf(stderr,"en '%s'\n",s);
				break;
			case ERRYADECL: fprintf(stderr,"variable '%s' ya declarada\n",s);
				break;
			case ERRNODECL: fprintf(stderr,"variable '%s' no declarada\n",s);
				break;
			case ERRDIM: fprintf(stderr,"la dimension debe ser mayor que cero\n");
				break;
			case ERRFALTAN: fprintf(stderr,"faltan indices\n");
				break;
			case ERRSOBRAN: fprintf(stderr,"sobran indices\n");
				break;
			case ERR_EXP_ENT: fprintf(stderr,"la expresion entre corchetes debe ser de tipo entero\n");
				break;
			case ERR_EXP_LOG: fprintf(stderr,"la expresion debe ser de tipo logico\n");
				break;
			case ERR_EXDER_LOG: fprintf(stderr,"la expresion a la derecha de '%s' debe ser de tipo logico\n",s);
				break;
			case ERR_EXDER_ENT: fprintf(stderr,"la expresion a la derecha de '%s' debe ser de tipo entero\n",s);
				break;
			case ERR_EXDER_RE:fprintf(stderr,"la expresion a la derecha de '%s' debe ser de tipo real o entero\n",s);
				break;        
			case ERR_EXIZQ_LOG:fprintf(stderr,"la expresion a la izquierda de '%s' debe ser de tipo logico\n",s); //PROBAR TAD
				break;       
			case ERR_EXIZQ_RE:fprintf(stderr,"la expresion a la izquierda de '%s' debe ser de tipo real o entero\n",s);
				break;       
			case ERR_NOCABE:fprintf(stderr,"la variable '%s' ya no cabe en memoria\n",s);
				break;
			case ERR_MAXVAR:fprintf(stderr,"en la variable '%s', hay demasiadas variables declaradas\n",s);
				break;
			case ERR_MAXTIPOS:fprintf(stderr,"hay demasiados tipos definidos\n");
				break;
			case ERR_MAXTMP:fprintf(stderr,"no hay espacio para variables temporales\n");
				break;
		}
	}else{
		fprintf(stderr,"Error al final del fichero\n");
	}
	
	exit(1);
}

int yyerror(char *s){
    extern int findefichero;   //  variable definida en plp5.l que indica si
                               // se ha acabado el fichero
    if (findefichero){
       msgError(ERREOF,-1,-1,"");
    }else{  
       msgError(ERRSINT,nlin,ncol-strlen(yytext),yytext);
    }
}

int main(int argc,char *argv[]){
    FILE *fent;

    if (argc==2){
        fent = fopen(argv[1],"rt");
        if (fent){
            yyin = fent;
            yyparse();
            fclose(fent);
        }
        else{
            fprintf(stderr,"No puedo abrir el fichero\n");
		}
    }
    else{
        fprintf(stderr,"Uso: ejemplo <nombre de fichero>\n");
	}
}

