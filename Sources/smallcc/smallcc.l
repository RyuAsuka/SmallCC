%{
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "smallh.h"
#include "y.tab.h"

int line = 0;
void yyerror(char*);
int yywrap(void);
%}
%%

"/*"([^\*]|(\*)*[^\*/])*(\*)*"*/" 	{;}
"//".*\n							{;}
[\n] 								{line++;}
[-\(\)<>\+\*/;%\[\]!\^&\|~]			{return *yytext;}
"&&"								{return AND;}
"||"								{return OR;}
":="								{return ASSIGN;}
"<="								{return LE;}
">="								{return GE;}
"=="								{return	EQ;}
"!="								{return NE;}
"++"								{return PP;}
"--"								{return MM;}
"array" 							{return ARRAY;}
"begin" 							{return BEGINSYM;}
"exit"  							{return EXIT;}
"end"								{return END;}
"if"								{return IF;}
"else"  							{return ELSE;}
"read"								{return READ;}
"then"								{return THEN;}
"repeat" 							{return REPEAT;}
"until" 							{return UNTIL;}
"write"								{return WRITE;}
"odd"   							{return ODD;}
"while" 							{return WHILE;}
"do"    							{return DO;}
[A-Za-z]([A-Za-z0-9])* {	
	yylval.ident=(char *)malloc(strlen(yytext)+1);
	strcpy(yylval.ident,yytext);
	return IDENTIFIER;
}
[0-9]+ {
	yylval.number=atoi(yytext);
	return INTEGER;
}
[ \t]+ 			{;}
.				{yyerror("Unknown charactor");}
%%

void redirectInput(FILE* f)
{
	yyin = f;
}

void redirectOutput(FILE* f)
{
	yyout = f;
}

void yyerror(char* s)
{
	printf("%s at line %d\n",s,line);
}

int yywrap(void)
{
	return 1;
}