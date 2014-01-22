
/*  A Bison parser, made from smallcc.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	INTEGER	257
#define	IDENTIFIER	258
#define	VALUE	259
#define	ASSIGN	260
#define	ARRAY	261
#define	EXIT	262
#define	IFX	263
#define	BEGINSYM	264
#define	REPEAT	265
#define	IF	266
#define	THEN	267
#define	READ	268
#define	WRITE	269
#define	UNTIL	270
#define	END	271
#define	WHILE	272
#define	DO	273
#define	ELSE	274
#define	OR	275
#define	AND	276
#define	EQ	277
#define	NE	278
#define	GE	279
#define	LE	280
#define	ODD	281
#define	UMINUS	282
#define	PP	283
#define	MM	284
#define	FPP	285
#define	FMM	286
#define	BPP	287
#define	BMM	288

#line 1 "smallcc.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <malloc.h>
#include "smallh.h"
#include "common.h"

nodeType *opr(int oper,int nops,...);
nodeType *id(char *name);
nodeType *con(int value);
void freeNode(nodeType* p);

int ex(nodeType*p);
void listcode(void);

int yylex(void);
void yyerror(char*);

void redirectInput(FILE *f);
void redirectOutput(FILE *f);

int bug = 0;

#define YYDEBUG 0


#line 28 "smallcc.y"
typedef union{
	int number;	 /* integer value */
	char* ident; /* identifier */
	nodeType *nPtr;
} YYSTYPE;
#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		130
#define	YYFLAG		-32768
#define	YYNTBASE	52

#define YYTRANSLATE(x) ((unsigned)(x) <= 288 ? yytranslate[x] : 57)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    39,     2,     2,     2,    37,    25,     2,    50,
    51,    35,    33,     2,    34,     2,    36,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,    49,    31,
     2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    47,     2,    48,    24,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,    23,     2,    40,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    26,    27,    28,    29,
    32,    38,    41,    42,    43,    44,    45,    46
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,     6,    10,    12,    19,    24,    27,    31,
    37,    44,    49,    55,    63,    72,    76,    81,    85,    90,
    97,   102,   107,   111,   116,   121,   126,   129,   133,   135,
   138,   140,   142,   147,   150,   153,   156,   159,   162,   165,
   169,   173,   177,   181,   185,   189,   193,   197,   201,   205,
   209,   213,   217,   221,   224,   228,   231,   235
};

static const short yyrhs[] = {    53,
     0,    53,    54,     0,     0,    53,     1,    54,     0,    49,
     0,     7,     4,    47,     3,    48,    49,     0,     7,     4,
     1,    54,     0,    56,    49,     0,    56,     1,    54,     0,
    11,    54,    16,    56,    49,     0,    11,    54,    16,    56,
     1,    54,     0,     4,     6,    56,    49,     0,     4,     6,
    56,     1,    54,     0,     4,    47,    56,    48,     6,    56,
    49,     0,     4,    47,    56,    48,     6,    56,     1,    54,
     0,    14,     4,    49,     0,    14,     4,     1,    54,     0,
    15,    56,    49,     0,    15,    56,     1,    54,     0,    12,
    56,    13,    54,    20,    54,     0,    12,    56,    13,    54,
     0,    12,    56,     1,    54,     0,    10,    55,    17,     0,
    10,    55,     1,    54,     0,    18,    56,    19,    54,     0,
    18,    56,     1,    54,     0,     8,    49,     0,     8,     1,
    54,     0,    54,     0,    55,    54,     0,     3,     0,     4,
     0,     4,    47,    56,    48,     0,     4,    41,     0,     4,
    42,     0,    41,     4,     0,    42,     4,     0,    32,    56,
     0,    34,    56,     0,    56,    33,    56,     0,    56,    34,
    56,     0,    56,    35,    56,     0,    56,    36,    56,     0,
    56,    30,    56,     0,    56,    31,    56,     0,    56,    37,
    56,     0,    56,    28,    56,     0,    56,    29,    56,     0,
    56,    27,    56,     0,    56,    26,    56,     0,    50,    56,
    51,     0,    56,    22,    56,     0,    56,    21,    56,     0,
    39,    56,     0,    56,    24,    56,     0,    40,    56,     0,
    56,    25,    56,     0,    56,    23,    56,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    57,    60,    71,    72,    74,    76,    77,    78,    79,    80,
    81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
    91,    92,    93,    94,    95,    96,    97,    98,   100,   102,
   104,   106,   107,   108,   109,   110,   111,   112,   113,   114,
   115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
   125,   126,   127,   128,   129,   130,   131,   132
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","INTEGER",
"IDENTIFIER","VALUE","ASSIGN","ARRAY","EXIT","IFX","BEGINSYM","REPEAT","IF",
"THEN","READ","WRITE","UNTIL","END","WHILE","DO","ELSE","OR","AND","'|'","'^'",
"'&'","EQ","NE","GE","LE","'>'","'<'","ODD","'+'","'-'","'*'","'/'","'%'","UMINUS",
"'!'","'~'","PP","MM","FPP","FMM","BPP","BMM","'['","']'","';'","'('","')'",
"program","function","statement","stmt_seq","expr", NULL
};
#endif

static const short yyr1[] = {     0,
    52,    53,    53,    53,    54,    54,    54,    54,    54,    54,
    54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
    54,    54,    54,    54,    54,    54,    54,    54,    55,    55,
    56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
    56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
    56,    56,    56,    56,    56,    56,    56,    56
};

static const short yyr2[] = {     0,
     1,     2,     0,     3,     1,     6,     4,     2,     3,     5,
     6,     4,     5,     7,     8,     3,     4,     3,     4,     6,
     4,     4,     3,     4,     4,     4,     2,     3,     1,     2,
     1,     1,     4,     2,     2,     2,     2,     2,     2,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     2,     3,     2,     3,     3
};

static const short yydefact[] = {     3,
     0,     0,    31,    32,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     5,     0,
     2,     0,     4,     0,    34,    35,     0,     0,     0,    27,
    29,     0,     0,    32,     0,     0,     0,     0,    38,    39,
    54,    56,    36,    37,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     8,     0,     0,     0,     0,    28,     0,    23,
    30,     0,     0,     0,     0,     0,    16,     0,    18,     0,
     0,    51,     9,    53,    52,    58,    55,    57,    50,    49,
    47,    48,    44,    45,    40,    41,    42,    43,    46,     0,
    12,    33,     7,     0,    24,     0,     0,    22,    21,    17,
    19,    26,    25,    13,     0,     0,     0,    10,    33,     0,
     0,     6,    11,    20,     0,    14,    15,     0,     0,     0
};

static const short yydefgoto[] = {   128,
     1,    21,    32,    22
};

static const short yypact[] = {-32768,
   121,   339,-32768,    -5,    15,     2,   339,   339,   106,    24,
   106,   106,   106,   106,   106,   106,    25,    31,-32768,   106,
-32768,   195,-32768,   106,-32768,-32768,   106,     6,   339,-32768,
-32768,   165,   -14,   -16,   369,     3,   212,   400,    66,-32768,
-32768,-32768,-32768,-32768,   -13,   339,   106,   106,   106,   106,
   106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
   106,   106,-32768,   249,   417,   339,    36,-32768,   339,-32768,
-32768,   106,   106,   339,   339,   339,-32768,   339,-32768,   339,
   339,-32768,-32768,   229,   283,   461,   474,   158,   330,   330,
    66,    66,    66,    66,    -3,    -3,-32768,-32768,-32768,   339,
-32768,    35,-32768,    -8,-32768,   266,   445,-32768,    37,-32768,
-32768,-32768,-32768,-32768,   106,     7,   339,-32768,-32768,   339,
   303,-32768,-32768,-32768,   339,-32768,-32768,    55,    59,-32768
};

static const short yypgoto[] = {-32768,
-32768,    -2,-32768,    34
};


#define	YYLAST		511


static const short yytable[] = {    23,
    24,    72,    29,    76,    31,    33,    66,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    28,    58,
    59,    60,    61,    62,    25,    26,    68,    36,    43,    71,
    73,    60,    61,    62,    44,    25,    26,    82,   104,   116,
   115,    27,    35,    83,    37,    38,    39,    40,    41,    42,
    30,    77,    67,    45,   129,   122,   120,    64,   130,     0,
    65,     0,     0,   103,     0,     0,   105,     0,     0,     0,
     0,   108,   109,   110,     0,   111,     0,   112,   113,     0,
    84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
    94,    95,    96,    97,    98,    99,     0,   114,    58,    59,
    60,    61,    62,     0,     0,   106,   107,     0,     3,    34,
     0,     0,     0,     0,   123,     0,     0,   124,     0,     0,
    -1,     2,   127,     3,     4,     0,     0,     5,     6,     0,
     7,     8,     9,     0,    10,    11,     0,    13,    12,    14,
     0,     0,     0,     0,    15,    16,    17,    18,   121,     0,
     0,     0,    13,     0,    14,    20,     0,     0,     0,    15,
    16,    17,    18,     0,     0,    69,     0,     3,     4,    19,
    20,     5,     6,     0,     7,     8,     9,     0,    10,    11,
     0,    70,    12,    52,    53,    54,    55,    56,    57,     0,
    58,    59,    60,    61,    62,    46,    13,     0,    14,     0,
     0,     0,     0,    15,    16,    17,    18,     0,     0,     0,
     0,     0,    78,    19,    20,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,     0,    58,    59,    60,
    61,    62,    47,    48,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    63,    58,    59,    60,    61,    62,   100,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
    79,    58,    59,    60,    61,    62,   117,     0,     0,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
     0,    58,    59,    60,    61,    62,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,   101,    58,    59,
    60,    61,    62,   125,     0,    49,    50,    51,    52,    53,
    54,    55,    56,    57,   118,    58,    59,    60,    61,    62,
     0,     0,     0,    47,    48,    49,    50,    51,    52,    53,
    54,    55,    56,    57,     0,    58,    59,    60,    61,    62,
     0,     3,     4,     0,     0,     5,     6,     0,     7,     8,
     9,   126,    10,    11,     0,     0,    12,    54,    55,    56,
    57,     0,    58,    59,    60,    61,    62,     0,     0,    74,
    13,     0,    14,     0,     0,     0,     0,    15,    16,    17,
    18,    75,     0,     0,     0,     0,     0,    19,    20,    47,
    48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
    80,    58,    59,    60,    61,    62,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    81,     0,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,     0,    58,    59,    60,    61,    62,    47,    48,    49,
    50,    51,    52,    53,    54,    55,    56,    57,     0,    58,
    59,    60,    61,    62,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,   102,    47,    48,    49,    50,    51,
    52,    53,    54,    55,    56,    57,     0,    58,    59,    60,
    61,    62,     0,     0,    50,    51,    52,    53,    54,    55,
    56,    57,   119,    58,    59,    60,    61,    62,    51,    52,
    53,    54,    55,    56,    57,     0,    58,    59,    60,    61,
    62
};

static const short yycheck[] = {     2,
     6,    16,     1,     1,     7,     8,     1,    21,    22,    23,
    24,    25,    26,    27,    28,    29,    30,    31,     4,    33,
    34,    35,    36,    37,    41,    42,    29,     4,     4,    32,
    47,    35,    36,    37,     4,    41,    42,    51,     3,    48,
     6,    47,     9,    46,    11,    12,    13,    14,    15,    16,
    49,    49,    47,    20,     0,    49,    20,    24,     0,    -1,
    27,    -1,    -1,    66,    -1,    -1,    69,    -1,    -1,    -1,
    -1,    74,    75,    76,    -1,    78,    -1,    80,    81,    -1,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,    60,    61,    62,    -1,   100,    33,    34,
    35,    36,    37,    -1,    -1,    72,    73,    -1,     3,     4,
    -1,    -1,    -1,    -1,   117,    -1,    -1,   120,    -1,    -1,
     0,     1,   125,     3,     4,    -1,    -1,     7,     8,    -1,
    10,    11,    12,    -1,    14,    15,    -1,    32,    18,    34,
    -1,    -1,    -1,    -1,    39,    40,    41,    42,   115,    -1,
    -1,    -1,    32,    -1,    34,    50,    -1,    -1,    -1,    39,
    40,    41,    42,    -1,    -1,     1,    -1,     3,     4,    49,
    50,     7,     8,    -1,    10,    11,    12,    -1,    14,    15,
    -1,    17,    18,    26,    27,    28,    29,    30,    31,    -1,
    33,    34,    35,    36,    37,     1,    32,    -1,    34,    -1,
    -1,    -1,    -1,    39,    40,    41,    42,    -1,    -1,    -1,
    -1,    -1,     1,    49,    50,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
    36,    37,    21,    22,    23,    24,    25,    26,    27,    28,
    29,    30,    31,    49,    33,    34,    35,    36,    37,     1,
    22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
    49,    33,    34,    35,    36,    37,     1,    -1,    -1,    21,
    22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
    -1,    33,    34,    35,    36,    37,    21,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    49,    33,    34,
    35,    36,    37,     1,    -1,    23,    24,    25,    26,    27,
    28,    29,    30,    31,    49,    33,    34,    35,    36,    37,
    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
    28,    29,    30,    31,    -1,    33,    34,    35,    36,    37,
    -1,     3,     4,    -1,    -1,     7,     8,    -1,    10,    11,
    12,    49,    14,    15,    -1,    -1,    18,    28,    29,    30,
    31,    -1,    33,    34,    35,    36,    37,    -1,    -1,     1,
    32,    -1,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
    42,    13,    -1,    -1,    -1,    -1,    -1,    49,    50,    21,
    22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
     1,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,
    21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
    31,    -1,    33,    34,    35,    36,    37,    21,    22,    23,
    24,    25,    26,    27,    28,    29,    30,    31,    -1,    33,
    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    48,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    -1,    33,    34,    35,
    36,    37,    -1,    -1,    24,    25,    26,    27,    28,    29,
    30,    31,    48,    33,    34,    35,    36,    37,    25,    26,
    27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
    37
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 58 "smallcc.y"
{;;
    break;}
case 2:
#line 62 "smallcc.y"
{
		if(!bug)
		{
			ex(yyvsp[0].nPtr);
			freeNode(yyvsp[0].nPtr);
		}
		else
			printf("There are serveral errors in your programe,\nPlease check all errors!\n");
	;
    break;}
case 4:
#line 72 "smallcc.y"
{yyerror("Unexcepted Syntax Error");;
    break;}
case 5:
#line 75 "smallcc.y"
{yyval.nPtr=opr(';',2,NULL,NULL);;
    break;}
case 6:
#line 76 "smallcc.y"
{yyval.nPtr=opr(ARRAY,2,id(yyvsp[-4].ident),con(yyvsp[-2].number));;
    break;}
case 7:
#line 77 "smallcc.y"
{yyerror("Use \'[\'");bug=1;;
    break;}
case 8:
#line 78 "smallcc.y"
{yyval.nPtr=yyvsp[-1].nPtr;;
    break;}
case 9:
#line 79 "smallcc.y"
{yyerror("Missing \';\'");bug=1;;
    break;}
case 10:
#line 80 "smallcc.y"
{yyval.nPtr=opr(REPEAT,2,yyvsp[-3].nPtr,yyvsp[-1].nPtr);;
    break;}
case 11:
#line 81 "smallcc.y"
{yyerror("Missing \';\'");bug=1;;
    break;}
case 12:
#line 82 "smallcc.y"
{yyval.nPtr=opr(ASSIGN,2,id(yyvsp[-3].ident),yyvsp[-1].nPtr);;
    break;}
case 13:
#line 83 "smallcc.y"
{yyerror("Missing \';\'");bug=1;;
    break;}
case 14:
#line 84 "smallcc.y"
{yyval.nPtr=opr(ASSIGN,3,id(yyvsp[-6].ident),yyvsp[-4].nPtr,yyvsp[-1].nPtr);;
    break;}
case 15:
#line 85 "smallcc.y"
{yyerror("Missing \';\'");bug=1;;
    break;}
case 16:
#line 86 "smallcc.y"
{yyval.nPtr=opr(READ,1,id(yyvsp[-1].ident));;
    break;}
case 17:
#line 87 "smallcc.y"
{yyerror("Missing \';\'");bug=1;;
    break;}
case 18:
#line 88 "smallcc.y"
{yyval.nPtr=opr(WRITE,1,yyvsp[-1].nPtr);;
    break;}
case 19:
#line 89 "smallcc.y"
{yyerror("Missing \';\'");bug=1;;
    break;}
case 20:
#line 90 "smallcc.y"
{yyval.nPtr=opr(IF,3,yyvsp[-4].nPtr,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 21:
#line 91 "smallcc.y"
{yyval.nPtr=opr(IF,2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 22:
#line 92 "smallcc.y"
{yyerror("Excepting \"then\"");bug=1;;
    break;}
case 23:
#line 93 "smallcc.y"
{yyval.nPtr=yyvsp[-1].nPtr;;
    break;}
case 24:
#line 94 "smallcc.y"
{yyerror("Missing \"end\"");bug=1;;
    break;}
case 25:
#line 95 "smallcc.y"
{yyval.nPtr=opr(WHILE,2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 26:
#line 96 "smallcc.y"
{yyerror("Excepting \"do\"");;
    break;}
case 27:
#line 97 "smallcc.y"
{yyval.nPtr=opr(EXIT,1,NULL);;
    break;}
case 28:
#line 98 "smallcc.y"
{yyerror("Missing \';\'");bug=1;;
    break;}
case 29:
#line 101 "smallcc.y"
{yyval.nPtr=yyvsp[0].nPtr;;
    break;}
case 30:
#line 102 "smallcc.y"
{yyval.nPtr=opr(';',2,yyvsp[-1].nPtr,yyvsp[0].nPtr);;
    break;}
case 31:
#line 105 "smallcc.y"
{yyval.nPtr=con(yyvsp[0].number);;
    break;}
case 32:
#line 106 "smallcc.y"
{yyval.nPtr=id(yyvsp[0].ident);;
    break;}
case 33:
#line 107 "smallcc.y"
{yyval.nPtr=opr(VALUE,2,id(yyvsp[-3].ident),yyvsp[-1].nPtr);;
    break;}
case 34:
#line 108 "smallcc.y"
{yyval.nPtr=opr(BPP,1,id(yyvsp[-1].ident));;
    break;}
case 35:
#line 109 "smallcc.y"
{yyval.nPtr=opr(BMM,1,id(yyvsp[-1].ident));;
    break;}
case 36:
#line 110 "smallcc.y"
{yyval.nPtr=opr(FPP,1,id(yyvsp[0].ident));;
    break;}
case 37:
#line 111 "smallcc.y"
{yyval.nPtr=opr(FMM,1,id(yyvsp[0].ident));;
    break;}
case 38:
#line 112 "smallcc.y"
{yyval.nPtr=opr(ODD,1,yyvsp[0].nPtr);;
    break;}
case 39:
#line 113 "smallcc.y"
{yyval.nPtr=opr(UMINUS,1,yyvsp[0].nPtr);;
    break;}
case 40:
#line 114 "smallcc.y"
{yyval.nPtr=opr('+',2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 41:
#line 115 "smallcc.y"
{yyval.nPtr=opr('-',2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 42:
#line 116 "smallcc.y"
{yyval.nPtr=opr('*',2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 43:
#line 117 "smallcc.y"
{yyval.nPtr=opr('/',2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 44:
#line 118 "smallcc.y"
{yyval.nPtr=opr('>',2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 45:
#line 119 "smallcc.y"
{yyval.nPtr=opr('<',2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 46:
#line 120 "smallcc.y"
{yyval.nPtr=opr('%',2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 47:
#line 121 "smallcc.y"
{yyval.nPtr=opr(GE,2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 48:
#line 122 "smallcc.y"
{yyval.nPtr=opr(LE,2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 49:
#line 123 "smallcc.y"
{yyval.nPtr=opr(NE,2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 50:
#line 124 "smallcc.y"
{yyval.nPtr=opr(EQ,2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 51:
#line 125 "smallcc.y"
{yyval.nPtr=yyvsp[-1].nPtr;;
    break;}
case 52:
#line 126 "smallcc.y"
{yyval.nPtr=opr(AND,2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 53:
#line 127 "smallcc.y"
{yyval.nPtr=opr(OR,2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 54:
#line 128 "smallcc.y"
{yyval.nPtr=opr('!',1,yyvsp[0].nPtr);;
    break;}
case 55:
#line 129 "smallcc.y"
{yyval.nPtr=opr('^',2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 56:
#line 130 "smallcc.y"
{yyval.nPtr=opr('~',1,yyvsp[0].nPtr);;
    break;}
case 57:
#line 131 "smallcc.y"
{yyval.nPtr=opr('&',2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
case 58:
#line 132 "smallcc.y"
{yyval.nPtr=opr('|',2,yyvsp[-2].nPtr,yyvsp[0].nPtr);;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 134 "smallcc.y"

#define SIZEOF_NODETYPE ((char*)&p->con-(char*)p)
nodeType *con(int value)
{
    nodeType *p;
    size_t nodeSize;
    nodeSize = SIZEOF_NODETYPE + sizeof(conNodeType);
    if((p=malloc(nodeSize))==NULL)
    {
        yyerror("out of memory\n");
    }
    p->type = typeCon;
    p->con.value = value;
    return p;
}

nodeType* id(char* name)
{
    nodeType *p;
    size_t nodeSize;
	nodeSize = SIZEOF_NODETYPE + sizeof(idNodeType);
    if((p=malloc(nodeSize))==NULL)
    {
        yyerror("out of memory\n");
    }
    p->type = typeId;
	p->id.name = name;
    return p;
}

nodeType* opr(int oper, int nops, ...)
{
    va_list ap;
    nodeType *p;
    size_t nodeSize;
    int i;
    nodeSize = SIZEOF_NODETYPE + sizeof(oprNodeType)+ (nops - 1)*sizeof(nodeType*);
    if((p=malloc(nodeSize))==NULL)
    {
        yyerror("out of memory\n");
    }
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap,nops);
    for(i=0;i<nops;i++)
    {
        p->opr.op[i] = va_arg(ap,nodeType*);
    }
    va_end(ap);
    return p;
}

void freeNode(nodeType* p)
{
    int i;
    if(!p)return;
    if(p->type == typeOpr)
    {
        for(i=0;i<p->opr.nops;i++)
            freeNode(p->opr.op[i]);
    }
	if(p->type==typeId)
		free(p->id.name);
    free(p);
}

extern int yy_flex_debug;

int main(int argc, char* argv[])
{
#if YYDEBUG
yydebug = 1;
#endif
	yy_flex_debug = 0;
	if((fInput = fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot open source code!\n");
		exit(1);
	}
	if((fOutput = fopen(argv[2],"w"))==NULL)
	{
		printf("Cannot open source code!\n");
		exit(1);
	}
	redirectInput(fInput);
	yyparse();

	listcode();

	fclose(fInput);
	fclose(fOutput);
	getchar();
	return 0;
}
