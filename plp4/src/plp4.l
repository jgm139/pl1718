/*------------------------------ plp4.l -------------------------------*/
ID [a-zA-Z][a-zA-Z0-9]*
NUMENTERO [0-9]+
NUMREAL [0-9]+\.[0-9]+


%{
  #include <string.h> 
  #include <string>
  #include <iostream>
  #include <cstring>

  using namespace std;

  #include "comun.h"
  #include "plp4.tab.h"

  int ncol = 1, nlin = 1, findefichero = 0;
  int ret(int token);
  void msgError(int nerror, int nlin, int ncol, const char *s);
%}

%x COMENTARIO

%%
%{
/* codigo local */
%}

" "                     {ncol++;}
[\t]                    {ncol++;}
[\n]                    {nlin++;ncol=1;}
"//"(.)*                {; /* comentarios de una linea, no hacer nada */}
"/*"                    {ncol += strlen(yytext);BEGIN(COMENTARIO);}
<COMENTARIO>[^/*\n]+    {ncol += strlen(yytext);}
<COMENTARIO>\n          {nlin++;ncol=1;}
<COMENTARIO><<EOF>>     {msgError(ERRLEXEOF,-1,-1,"");}
<COMENTARIO>"*/"        {ncol+=strlen(yytext); BEGIN(INITIAL);}
<COMENTARIO>[*/]        {ncol += strlen(yytext);}
"("                {return ret(pari);}
")"                {return ret(pard);}
","                {return ret(coma);}
"&"                {return ret(amp);}
"{"                {return ret(llavei);}
"}"                {return ret(llaved);}
"="                {return ret(asig);}
";"                {return ret(pyc);}
"+"                {return ret(opas);}
"-"                {return ret(opas);}
"int"              {return ret(INT);}
"float"            {return ret(FLOAT);}
"if"               {return ret(IF);}
{ID}               {return ret(ID);}
{NUMENTERO}        {return ret(NUMENTERO);}
{NUMREAL}          {return ret(NUMREAL);}
.                  {msgError(ERRLEXICO,nlin,ncol,yytext);}
%%

int yywrap(void) {findefichero=1; return 1;} /* para no tener que linkar con la libreria del lex */


int ret(int token){
  yylval.lexema=strdup(yytext);
  yylval.nlin=nlin;
  yylval.ncol=ncol;
  ncol+=(strlen(yytext));
  return(token);
}
