%{
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

#define YYDEBUG 1

%}
%union{
	int number;	 /* integer value */
	char* ident; /* identifier */
	nodeType *nPtr;
};
%token <number> INTEGER
%token <ident> IDENTIFIER
%token VALUE
%token ASSIGN
%token ARRAY
%nonassoc EXIT
%nonassoc IFX
%token BEGINSYM REPEAT IF THEN READ WRITE UNTIL END WHILE DO
%nonassoc ELSE
%left OR
%left AND
%left '|'
%left '^'
%left '&'
%left EQ NE
%left GE LE '>' '<'
%nonassoc ODD
%left '+' '-' 
%left '*' '/' '%'
%right UMINUS '!' '~' PP MM FPP FMM BPP BMM
%left '[' ']'
%type <nPtr> statement expr stmt_seq
%start program
%%
program:
	function 												{;}
	;
function:
	function statement									
	{
		if(!bug)
		{
			ex($2);
			freeNode($2);
		}
		else
			printf("There are serveral errors in your programe,\nPlease check all errors!\n");
	}
	|/* NULL */
	|function error statement						{yyerror("Unexcepted Syntax Error");}
	;
statement:
	';'												{$$=opr(';',2,NULL,NULL);}
	|ARRAY IDENTIFIER'['INTEGER']'';'				{$$=opr(ARRAY,2,id($2),con($4));}
	|ARRAY IDENTIFIER error statement				{yyerror("Use \'[\'");bug=1;}
	|expr';'										{$$=$1;}
	|expr error statement							{yyerror("Missing \';\'");bug=1;}
	|REPEAT statement UNTIL expr';'					{$$=opr(REPEAT,2,$2,$4);}
	|REPEAT statement UNTIL expr error statement	{yyerror("Missing \';\'");bug=1;}
	|IDENTIFIER ASSIGN expr';'						{$$=opr(ASSIGN,2,id($1),$3);}
	|IDENTIFIER ASSIGN expr error statement			{yyerror("Missing \';\'");bug=1;}
	|IDENTIFIER'['expr']' ASSIGN expr';'			{$$=opr(ASSIGN,3,id($1),$3,$6);}
	|IDENTIFIER'['expr']' ASSIGN expr error statement {yyerror("Missing \';\'");bug=1;}
	|READ IDENTIFIER';'								{$$=opr(READ,1,id($2));}
	|READ IDENTIFIER error statement				{yyerror("Missing \';\'");bug=1;}
	|WRITE expr';'									{$$=opr(WRITE,1,$2);}
	|WRITE expr error statement						{yyerror("Missing \';\'");bug=1;}
	|IF expr THEN statement ELSE statement			{$$=opr(IF,3,$2,$4,$6);}
	|IF expr THEN statement %prec IFX				{$$=opr(IF,2,$2,$4);}
	|IF expr error statement						{yyerror("Excepting \"then\"");bug=1;}
	|BEGINSYM stmt_seq END							{$$=$2;}
	|BEGINSYM stmt_seq error statement				{yyerror("Missing \"end\"");bug=1;}
	|WHILE expr DO statement						{$$=opr(WHILE,2,$2,$4);}
	|WHILE expr error statement						{yyerror("Excepting \"do\"");}
	|EXIT';'										{$$=opr(EXIT,1,NULL);}
	|EXIT error statement							{yyerror("Missing \';\'");bug=1;}
	;
stmt_seq:
	statement											{$$=$1;}
	|stmt_seq statement									{$$=opr(';',2,$1,$2);}
	;
expr:
	INTEGER												{$$=con($1);}
	|IDENTIFIER											{$$=id($1);}
	|IDENTIFIER'['expr']'								{$$=opr(VALUE,2,id($1),$3);}
	|IDENTIFIER PP %prec BPP							{$$=opr(BPP,1,id($1));}
	|IDENTIFIER MM %prec BMM							{$$=opr(BMM,1,id($1));}
	|PP IDENTIFIER %prec FPP							{$$=opr(FPP,1,id($2));}
	|MM IDENTIFIER %prec FMM							{$$=opr(FMM,1,id($2));}
	|ODD expr											{$$=opr(ODD,1,$2);}
	|'-'expr %prec UMINUS								{$$=opr(UMINUS,1,$2);}
	|expr'+'expr										{$$=opr('+',2,$1,$3);}
	|expr'-'expr										{$$=opr('-',2,$1,$3);}
	|expr'*'expr										{$$=opr('*',2,$1,$3);}
	|expr'/'expr										{$$=opr('/',2,$1,$3);}
	|expr'>'expr										{$$=opr('>',2,$1,$3);}
	|expr'<'expr										{$$=opr('<',2,$1,$3);}
	|expr'%'expr										{$$=opr('%',2,$1,$3);}
	|expr GE expr										{$$=opr(GE,2,$1,$3);}
	|expr LE expr										{$$=opr(LE,2,$1,$3);}
	|expr NE expr										{$$=opr(NE,2,$1,$3);}
	|expr EQ expr										{$$=opr(EQ,2,$1,$3);}
	|'('expr')'											{$$=$2;}
	|expr AND expr										{$$=opr(AND,2,$1,$3);}
	|expr OR expr										{$$=opr(OR,2,$1,$3);}
	|'!'expr											{$$=opr('!',1,$2);}
	|expr'^'expr										{$$=opr('^',2,$1,$3);}
	|'~'expr											{$$=opr('~',1,$2);}
	|expr'&'expr										{$$=opr('&',2,$1,$3);}
	|expr'|'expr										{$$=opr('|',2,$1,$3);}
	;
%%
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
