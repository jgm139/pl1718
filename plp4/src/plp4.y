/*------------------------------ plp4.y -------------------------------*/
/*-----------------------------------
|      Declaraciones de Bison        |
------------------------------------*/
%token pari pard
%token coma amp
%token llavei llaved
%token asig pyc
%token opas INT FLOAT IF
%token ID NUMENTERO NUMREAL

%{
	/*-----------------------------------
	|        Declaraciones en C          |
	------------------------------------*/
	#include <stdio.h>
	#include <stdlib.h>
	#include <string>
	#include <iostream>
	#include <vector>
    #include <cstring>

	using namespace std;

	#include "comun.h"

	// variables y funciones del A. Léxico
	extern int ncol,nlin,findefichero;

	extern int yylex();
	extern char *yytext;
	extern FILE *yyin;

	int yyerror(char *s);
	void msgError(int nerror,int nlin,int ncol,const char *s);
	void msgErrorSEM(int nerror, int nlin,int ncol,string s);

	const int ENTERO=1;
	const int REAL=2;

	typedef struct{
		string nombre;
		int tipo;
		string trad;
	}Simbolo;

	struct TablaSimbolos{
		struct TablaSimbolos *padre;
		vector<Simbolo> simbolos;
	};

	TablaSimbolos* ts;
	string auxprefix;

	TablaSimbolos* newTS(TablaSimbolos* padre);
	bool anyadir(string nombre, int tipo, string trad);
	bool buscar(Simbolo& simbolo, string nombre);

%}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
%%
	S 	: 	Fun	{	int tk = yylex(); if(tk!=0){ yyerror(""); } }
		;

	Fun : 	{ ts = new TablaSimbolos(); }	Tipo 	ID 	Args 	{ $$.ph.idfun = $3.lexema; }	Bloque 	{ 	cout << "function " << $3.lexema;
																											cout << $4.trad << $2.trad;
																											cout << ";\nvar\t" << $6.decl << $6.trad << "\n";
																											delete ts;
																										}
		;

	Tipo	:	INT	{	$$.trad = ":integer";
						$$.tipo = ENTERO;
					}
			| 	FLOAT	{	$$.trad = ":real";
							$$.tipo = REAL;
						}
			;

	Args 	: 	pari 	LArgs 	pard	{	if($2.trad.empty()){
												$$.trad = "";
											}else{
												$$.trad = "("+$2.trad+")";
											}
										}
			;

	LArgs 	: 	MasArgs 	{ $$.trad = $1.trad; }
			| 	/*epsilon*/ { $$.trad = ""; }
			;

	MasArgs : 	MasArgs	coma	A	{ $$.trad = $1.trad+";"+$3.trad; }
			| 	A	{ $$.trad = $1.trad; }
			;

	A 	:	Tipo	{ $$.tipo = $1.tipo; }	Var	{ $$.trad = $3.trad+$1.trad; }
		;

	Var : 	amp	ID	{	if(!anyadir($2.lexema,$0.tipo,$2.lexema)){
							msgErrorSEM(ERRORDECL,$2.nlin,$2.ncol,$2.lexema);	
						};
						$$.trad = "var "+$2.lexema;
					}
		| 	ID	{	if(!anyadir($1.lexema,$0.tipo,$1.lexema)){
						msgErrorSEM(ERRORDECL,$1.nlin,$1.ncol,$1.lexema);
					}; 
					$$.trad = $1.lexema;
				}
		;

	Bloque 	: 	llavei 	{ $$.ph = $0.ph; }	SInstr	llaved	{	if($3.trad.empty()){
																	if($3.decl.empty()){
																		$$.decl = "";
																	}else{
																		$$.decl = $3.decl;
																	}
																	$$.trad = "begin\ndoNothing\nend";
																}else{
																	$$.trad = "begin\n"+$3.trad+"\nend";
																	$$.decl = $3.decl;
																}
															}
			;

	SInstr 	: 	SInstr 	{ $$.ph = $0.ph; }	Instr 	{	if(!$1.trad.empty() && $3.trad.empty()){
															$$.trad = $1.trad;
															
															if($3.decl.empty()){
																$$.decl = $1.decl;
															}else{
																$$.decl = $1.decl+$3.decl;
															}
														}else if($1.trad.empty() && !$3.trad.empty()){
															$$.trad = $3.trad;
															
															if($1.decl.empty()){
																$$.decl = $3.decl;
															}else{
																$$.decl = $1.decl+$3.decl;
															}
														}else if($1.trad.empty() && $3.trad.empty()){
															$$.trad = "";
															
															if($1.decl.empty() && $3.decl.empty()){
																$$.decl = "";
															}else if($1.decl.empty()){
																$$.decl = $3.decl;
															}else if($3.decl.empty()){
																$$.decl = $1.decl;
															}else{
																$$.decl = $1.decl+$3.decl;
															}
														}else{
															$$.trad = $1.trad+";\n"+$3.trad;
															$$.decl = $1.decl+$3.decl;
														}
													}
			| 	{ $$.ph = $0.ph; }	Instr 	{	
												$$.trad = $2.trad;
												$$.decl = $2.decl;
											}
			;

	Instr 	: 	{ ts = newTS(ts); $$.ph = $0.ph; $$.ph.prefix += "_"; }	Bloque	{	
																					$$.trad = $2.trad;
																					$$.decl = $2.decl;
																					TablaSimbolos* aux = ts;
																					ts = ts->padre;
																					delete aux;
																				}
			|  	ID	{ Simbolo ss;
						if(!buscar(ss, $1.lexema)){
							msgErrorSEM(ERRORDECL, $1.nlin, $1.ncol, $1.lexema);
						}
					}
					asig 	E 	pyc 	{	Simbolo aux;
											if(buscar(aux,$1.lexema)){
												if(aux.tipo == REAL && $4.tipo == ENTERO){
													$$.trad = aux.trad+" := itor("+$4.trad+") ";
													$$.decl = "";
												}else if(aux.tipo == ENTERO && $4.tipo == REAL){
													msgErrorSEM(ERRORINCOM,$3.nlin,$3.ncol,$3.lexema);
												}
												else{
													$$.trad = aux.trad+" := "+$4.trad;
													$$.decl = "";
												}
											}else{
												msgErrorSEM(ERRORDECL,$1.nlin,$1.ncol,$1.lexema);
											}
										}
			| 	IF 	pari 	E 	pard 	{ $$.ph = $0.ph; }	Instr 	{	if($6.trad.empty()){
																			$$.trad = "if "+$3.trad+" then\ndoNothing";
																		}else{
																			$$.trad = "if "+$3.trad+" then\n"+$6.trad;
																		}

																		if($6.decl.empty()){
																			$$.decl = "";
																		}else{
																			$$.decl = $6.decl;
																		}
																	}
			| 	Tipo 	ID 	{ 	if(ts->padre!=NULL){
				 					auxprefix = $0.ph.idfun+$0.ph.prefix;
								}else{
									auxprefix = "";
								}
								if(!anyadir($2.lexema,$1.tipo,auxprefix+$2.lexema)){  msgErrorSEM(ERRORAMBITO,$2.nlin,$2.ncol,$2.lexema);  }; 
							}
						pyc	{ 	$$.trad = "";
								$$.decl = auxprefix+$2.lexema+$1.trad+";\n";
							}
			;

	E 	: 	E 	opas 	T 	{ 	if($1.tipo == ENTERO && $3.tipo == ENTERO){
									$$.trad = $1.trad+" "+$2.lexema+"i "+$3.trad;
									$$.tipo = ENTERO;
								}else if($1.tipo == ENTERO && $3.tipo == REAL){
									$$.trad = "itor("+$1.trad+") "+$2.lexema+"r "+$3.trad;
									$$.tipo = REAL;
								}else if($1.tipo == REAL && $3.tipo == ENTERO){
									$$.trad = $1.trad+" "+$2.lexema+"r itor("+$3.trad+") ";
									$$.tipo = REAL;
								}else if($1.tipo == REAL && $3.tipo == REAL){
									$$.trad = $1.trad+" "+$2.lexema+"r "+$3.trad;
									$$.tipo = REAL;
								}
							}
		| 	T 	{ 	$$.trad = $1.trad;
					$$.tipo = $1.tipo;
				}
		;

	T 	: 	ID 	{	Simbolo s;
					if(buscar(s,$1.lexema)){
						$$.tipo = s.tipo;
						$$.trad = s.trad;
					}else{
						msgErrorSEM(ERRORDECL,$1.nlin,$1.ncol,$1.lexema);
                	}
				}
		|	NUMREAL	{	$$.trad = $1.lexema;
						$$.tipo = REAL;
					}
		| 	NUMENTERO 	{	$$.trad = $1.lexema;
							$$.tipo = ENTERO;
						}
		;
%%
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

TablaSimbolos* newTS(TablaSimbolos* padre){
	TablaSimbolos* nueva = new TablaSimbolos();
	nueva->padre = padre;

	return nueva;
}

bool anyadir(string nombre, int tipo, string trad){

	for(Simbolo ss:ts->simbolos){
		if(ss.nombre == nombre){
			return false;
		}
	}

	Simbolo s;
	s.nombre = nombre;
	s.tipo = tipo;
	s.trad = trad;

	ts->simbolos.push_back(s);
	return true;
}

bool buscar(Simbolo& simbolo, string nombre) {
	TablaSimbolos* aux = ts;
	
 	while(aux != NULL){
 		vector<Simbolo> auxV = aux->simbolos; 
 		for (Simbolo s : auxV) {
  			if (s.nombre == nombre){
	   			simbolo = s;
	   			return true;
  			}
 		}
 		aux = aux->padre;
 	}
	 
	return false;	
}

void msgError(int nerror,int nlin,int ncol,const char *s){
	switch (nerror) {
		case ERRLEXICO: fprintf(stderr,"Error lexico (%d,%d): caracter '%s' incorrecto\n",nlin,ncol,s);
		break;
		case ERRSINT: fprintf(stderr,"Error sintactico (%d,%d): en '%s'\n",nlin,ncol,s);
		break;
		case ERREOF: fprintf(stderr,"Error sintactico: fin de fichero inesperado\n");
		break;
		case ERRLEXEOF: fprintf(stderr,"Error lexico: fin de fichero inesperado\n");
		break;
	}

	exit(1);
}

void msgErrorSEM(int nerror, int nlin,int ncol,string s){
	switch (nerror) {
		case ERRORAMBITO: fprintf(stderr,"Error semantico (%d,%d): '%s' ya existe en este ambito\n",nlin,ncol,s.c_str());
		break;
		case ERRORDECL: fprintf(stderr,"Error semantico (%d,%d): '%s' no ha sido declarado\n",nlin,ncol,s.c_str());
		break;
		case ERRORINCOM: fprintf(stderr,"Error semantico (%d,%d): '%s' tipos incompatibles entero/real\n",nlin,ncol,s.c_str());
	}

	exit(1);
}

int yyerror(char *s){
    if (findefichero){
       msgError(ERREOF,-1,-1,"");
    }
    else{
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
