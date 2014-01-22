typedef union{
	int number;	 /* integer value */
	char* ident; /* identifier */
	nodeType *nPtr;
} YYSTYPE;
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


extern YYSTYPE yylval;
