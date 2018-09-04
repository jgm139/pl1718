/*-------------------- plp5.l -------------------------------*/
id [a-zA-Z][a-zA-Z0-9]*
nentero [0-9]+
nreal [0-9]+\.[0-9]+

%{
	#include <iostream>
	#include "comun.h"
	#include "plp5.tab.h"

	using namespace std;

	int ncol = 1, nlin = 1, findefichero = 0;
	int ret(int token);
	void msgError(int nerror, int nlin, int ncol, const char *s);
%}

%x INIT

%%

" "				{ncol++;}
[\t]			{ncol++;}
[\n]			{nlin++;ncol=1;}
"//"(.)*		{;}

"algoritmo"		{return ret(algoritmo);}
"falgoritmo"	{return ret(falgoritmo);}
"var"			{return ret(var);}
"fvar"			{return ret(fvar);}
"entero"		{return ret(entero);}
"real"			{return ret(real);}
"logico"		{return ret(logico);}
"tabla"			{return ret(tabla);}
"de"			{return ret(de);}
"escribe"		{return ret(escribe);}
"lee"			{return ret(lee);}
"si"			{return ret(si);}
"entonces"		{return ret(entonces);}
"sino"			{return ret(sino);}
"mientras"		{return ret(mientras);}
"hacer"			{return ret(hacer);}
"blq"			{return ret(blq);}
"fblq"			{return ret(fblq);}
"cierto"		{return ret(cierto);}
"falso"			{return ret(falso);}

","				{return ret(coma);}
";"				{return ret(pyc);}
":"				{return ret(dospto);}
"("				{return ret(pari);}
")"				{return ret(pard);}
"="				{return ret(oprel);}
"<>"			{return ret(oprel);}
"<"				{return ret(oprel);}
"<="			{return ret(oprel);}
">"				{return ret(oprel);}
">="			{return ret(oprel);}
"+"				{return ret(opas);}
"-"				{return ret(opas);}
"*"				{return ret(opmd);}
"/"				{return ret(opmd);}
":="			{return ret(opasig);}
"["				{return ret(cori);}
"]"				{return ret(cord);}
"&&"			{return ret(ybool);}
"||"			{return ret(obool);}
"!"				{return ret(nobool);}

{id}			{return ret(id);}
{nentero}		{return ret(nentero);}
{nreal}			{return ret(nreal);}

.				{msgError(ERRLEXICO,nlin,ncol,yytext);}				

%%

int yywrap(void) {findefichero=1; return 1;}


int ret(int token){
	yylval.lexema=strdup(yytext);
	yylval.nlin=nlin;
	yylval.ncol=ncol;
	ncol+=(strlen(yytext));
	return(token);
}