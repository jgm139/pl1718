/*------------------------------ plp4.y -------------------------------*/
/*-----------------------------------
|      Declaraciones de Bison        |
------------------------------------*/
%token algoritmo falgoritmo
%token var fvar
%token entero real
%token logico tabla de escribe lee
%token si entonces sino mientras hacer
%token blq fblq
%token cierto falso
%token id nentero nreal
%token coma pyc dospto
%token pari pard
%token oprel opas opmd opasig
%token cori cord
%token ybool obool nobool

%{
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

%}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

%%

	S : algoritmo dospto id { init(); } SDec SInstr falgoritmo	{	
																	int tk = yylex();
																	if(tk!=0){ 
																		yyerror("");
																	} 
																	//printTablaTipos();
																	cout << "\n" << $6.cod << "halt\n";
																	//printMemoryInfo();
																}

	SDec    : Dec
			| { $$.cod = ""; }
			;

	Dec     : var DVar MDVar fvar
			;

	DVar    : Tipo dospto id	{ 	
									if(anyadirS($3.lexema,$1.tipo, $1.tam)){
										$$.tipo = $1.tipo;
										$$.tam = $1.tam;
									}else{
										msgError(ERRYADECL, $3.nlin, $3.ncol, $3.lexema.c_str());
									}
								} LId pyc
			; 

	MDVar   : DVar MDVar
			| { $$.cod = ""; }
			;

	LId     : coma id	{	
							if(anyadirS($2.lexema,$0.tipo, $0.tam)){
								$$.tipo = $0.tipo;
								$$.tam = $0.tam;
							}else{
								msgError(ERRYADECL, $2.nlin, $2.ncol, $2.lexema.c_str());
							}
							
					  	} LId
			| { $$.cod = ""; }
			;

	Tipo    : entero { $$.tipo = ENTERO; $$.tam = 1; }
			| real	{ $$.tipo = REAL; $$.tam = 1; }
			| logico { $$.tipo = LOGIC; $$.tam = 1; }
			| tabla nentero { 	if( atoi($2.lexema.c_str()) < 1){
									msgError(ERRDIM, $2.nlin, $2.ncol, $2.lexema.c_str());
								} 
							} de Tipo	{	
											$$.tipo = anyadirT(atoi($2.lexema.c_str()), $5.tipo);
											$$.tam = atoi($2.lexema.c_str())*$5.tam;
										}
			;

	SInstr  : SInstr pyc Instr { $$.cod = $1.cod+"\n"+$3.cod; }
			| Instr { $$.cod = $1.cod; }
			;

	Instr   : escribe Expr {	
								stringstream ss;
								if($2.tipo == ENTERO){
									ss << $2.cod << "wri " << $2.dir << "\nwrl\n";
									$$.cod = ss.str();
								}else if($2.tipo == REAL){
									ss << $2.cod << "wrr " << $2.dir << "\nwrl\n";
									$$.cod = ss.str();
								}else{
									int tmp = NuevoTemporal();
									int e1, e2;
									e1 = getEtiqueta();
									e2 = getEtiqueta();
									ss << $2.cod;
									ss << "mov " << $2.dir << " A\n";
									ss << "jz L" << e1 << "\n";
									ss << "mov #99 " << $2.dir << "\n";
									ss << "jmp L" << e2 << "\n";
									ss << "L" << e1 << "\n";
									ss << "mov #102 " << $2.dir << "\n";
									ss << "L" << e2 << "\n";
									ss << "wrc " << $2.dir << "\nwrl\n";
									$$.cod = ss.str();
								}
								borrarTemp();
							}
			| lee Ref 	{	
							stringstream ss;

							if($2.tipo == ENTERO){
								int tmp = NuevoTemporal();

								if($2.is_array){
									ss << $2.cod;
								}else{
									ss << "mov #" << $2.dir_base << " " << $2.dir << "\n";
								}

								ss << "rdi " << tmp << "\n";
								ss << "mov " << $2.dir << " A\n";
								ss << "mov " << tmp << " @A\n";
								ss << "wrl\n";
								$$.cod = ss.str();
							}else if($2.tipo == REAL){
								int tmp = NuevoTemporal();

								if($2.is_array){
									ss << $2.cod;
								}else{
									ss << "mov #" << $2.dir_base << " " << $2.dir << "\n";
								}

								ss << "rdr " << tmp << "\n";
								ss << "mov " << $2.dir << " A\n";
								ss << "mov " << tmp << " @A\n";
								ss << "wrl\n";
								$$.cod = ss.str();
							}else{
								int tmp = NuevoTemporal();
								int e1, e2;
								e1 = getEtiqueta();
								e2 = getEtiqueta();

								if($2.is_array){
									ss << $2.cod;
								}else{
									ss << "mov #" << $2.dir_base << " " << $2.dir << "\n";
								}

								ss << "rdc " << tmp << "\n";
								ss << "mov " << tmp << "A\n";
								ss << "subi #99\n";
								ss << "jz L" << e1 << "\n";
								ss << "mov " << $2.dir << " A\n";
								ss << "mov #0 @A\n";
								ss << "jmp L" << e2 << "\n";
								ss <<  "L" << e1 << "\n";
								ss << "mov " << $2.dir << " A\n";
								ss << "mov #1 @A\n";
								ss << "L" << e2 << "\n";
								ss << "wrl\n";
								$$.cod = ss.str();
							}
							borrarTemp();
						}
			| si Expr entonces Instr	{
											if($2.tipo!=LOGIC){
												msgError(ERR_EXP_LOG, $1.nlin, $1.ncol, $1.lexema.c_str());
											}else{
												stringstream ss;
												int e1 = getEtiqueta();
												ss << $2.cod << "mov " << $2.dir << " A\n";
												ss << "jz L" << e1 << "\n";
												ss << $4.cod;
												ss << "L" << e1 << "\n";
												$$.cod = ss.str();
												borrarTemp();
											}
										}
			| si Expr entonces Instr sino Instr	{
													if($2.tipo!=LOGIC){
														msgError(ERR_EXP_LOG, $2.nlin, $2.ncol, $2.lexema.c_str());
													}else{
														stringstream ss;
														int e1, e2;
														e1 = getEtiqueta();
														e2 = getEtiqueta();
														ss << $2.cod << "mov " << $2.dir << " A\n";
														ss << "jz L" << e1 << "\n";
														ss << $4.cod;
														ss << "jmp L" << e2 << "\n";
														ss << "L" << e1 << "\n";
														ss << $6.cod;
														ss << "\nL" << e2 << "\n";
														$$.cod = ss.str();
														borrarTemp();
													}
												}
			| mientras Expr hacer Instr {
											if($2.tipo!=LOGIC){
												msgError(ERR_EXP_LOG, $2.nlin, $2.ncol, $2.lexema.c_str());
											}else{
												stringstream ss;
												int e1, e2;
												e1 = getEtiqueta();
												e2 = getEtiqueta();
												ss << "L" << e1 << "\n";
												ss << $2.cod;
												ss << "mov " << $2.dir << " A\n";
												ss << "jz L" << e2 << "\n";
												ss << $4.cod;
												ss << "jmp L" << e1 << "\n";
												ss << "L" << e2 << "\n";
												$$.cod = ss.str();
												borrarTemp();
											}
										}
			| Ref opasig Expr { 
								if(esArray($1.tipo)){
									msgError(ERRFALTAN, $2.nlin, ($2.ncol-$1.lexema.size()-1), $1.lexema.c_str());
								}
                                if($1.tipo == LOGIC && $3.tipo != LOGIC){
									msgError(ERR_EXDER_LOG, $2.nlin, $2.ncol, $2.lexema.c_str());
								}
                                if($1.tipo != LOGIC && $3.tipo == LOGIC){
									msgError(ERR_EXDER_RE, $2.nlin, $2.ncol, $2.lexema.c_str());
								}
								
								stringstream ss;
								int Seof = tamT($1.tipo);
								if($1.tipo == ENTERO && $3.tipo == ENTERO){
                                    ss << $1.cod << $3.cod;
                                    ss << "mov " << $1.dir << " A\n";
                                    ss << "muli #" << Seof;
                                    ss << "\naddi #" << $1.dir_base;
                                    ss << "\nmov " << $3.dir << " @A\n";
                                    $$.cod = ss.str();
                                }else if($1.tipo == REAL && $3.tipo == ENTERO){
                                    int tmp = NuevoTemporal();
                                    ss << $1.cod << $3.cod;
                                    ss << "mov " << $3.dir << " A\n";
                                    ss << "itor\n";
                                    ss << "mov A " << tmp << "\n";
                                    ss << "mov " << $1.dir << " A\n";
                                    ss << "muli #" << Seof;
                                    ss << "\naddi #" << $1.dir_base;
                                    ss << "\nmov " << tmp << " @A\n";
                                    $$.cod = ss.str();
                                }else if($1.tipo == ENTERO && $3.tipo == REAL){
                                    msgError(ERR_EXDER_ENT, $2.nlin, $2.ncol, $2.lexema.c_str());
                                }else { 
                                    ss << $1.cod << $3.cod;
                                    ss << "mov " << $1.dir << " A\n";
                                    ss << "muli #" << Seof;
                                    ss << "\naddi #" << $1.dir_base;
                                    ss << "\nmov " << $3.dir << " @A\n";
                                    $$.cod = ss.str();
                                }
								
								borrarTemp();
							  }
			| blq SInstr fblq { $$.cod = $2.cod; borrarTemp(); }
			;

	Expr    : Expr obool {	if($1.tipo!=LOGIC){
								msgError(ERR_EXIZQ_LOG, $2.nlin, $2.ncol, $2.lexema.c_str());
							}
						} Econj 	{ 
										if($4.tipo!=LOGIC){
											msgError(ERR_EXDER_LOG  , $2.nlin, $2.ncol, $2.lexema.c_str());
										}
										stringstream ss;
										int tmp = NuevoTemporal();
										ss << $1.cod << $4.cod;
										ss << "mov " << $1.dir << " A\n";
										ss << "ori " << $4.dir;
										ss << "\nmov A " << tmp << "\n";
										$$.cod = ss.str();
										$$.dir = tmp;
										$$.tipo = LOGIC;
									}
			| Econj { $$.tipo = $1.tipo; $$.cod = $1.cod; $$.dir = $1.dir; }
			;

	Econj   : Econj ybool	{	if($1.tipo!=LOGIC){
									msgError(ERR_EXIZQ_LOG, $2.nlin, $2.ncol, $2.lexema.c_str());
								}
							} Ecomp	{
										if($4.tipo!=LOGIC){
											msgError(ERR_EXDER_LOG, $2.nlin, $2.ncol, $2.lexema.c_str());
										}
										stringstream ss;
										int tmp = NuevoTemporal();
										ss << $1.cod << $4.cod;
										ss << "mov " << $1.dir << " A\n";
										ss << "andi " << $4.dir;
										ss << "\nmov A " << tmp << "\n";
										$$.cod = ss.str();
										$$.dir = tmp;
										$$.tipo = LOGIC;
									}	
			| Ecomp { $$.tipo = $1.tipo; $$.cod = $1.cod; $$.dir = $1.dir; }
			;

	Ecomp   : Esimple oprel Esimple	{
										if($1.tipo!=ENTERO && $1.tipo!=REAL){
											msgError(ERR_EXIZQ_RE, $2.nlin, $2.ncol, $2.lexema.c_str());
										}
										if($3.tipo!=ENTERO && $3.tipo!=REAL){
											msgError(ERR_EXDER_RE, $2.nlin, $2.ncol, $2.lexema.c_str());
										}
										
										stringstream ss;
										string op;

										if($2.lexema == "="){
											op = "eql";
										}else if($2.lexema == "<>"){
											op = "neq";
										}else if($2.lexema == "<"){
											op = "lss";
										}else if($2.lexema == "<="){
											op = "leq";
										}else if($2.lexema == ">"){
											op = "gtr";
										}else {
											op = "geq";
										}

										int tmp = NuevoTemporal();
										$$.dir = tmp;
										$$.tipo = LOGIC;

										if($1.tipo == ENTERO && $3.tipo == ENTERO){
											ss << $1.cod << $3.cod;
											ss << "mov " << $1.dir << " A\n";
											ss << op << "i " << $3.dir;
											ss << "\nmov A " << tmp << "\n";
											$$.cod = ss.str();
										}else if($1.tipo == REAL && $3.tipo == ENTERO){
											ss << $1.cod << $3.cod;
											ss << "mov " << $3.dir << " A\n";
											ss << "itor\n";
											ss << "mov A " << $3.dir << "\n"; 
											ss << "mov " << $1.dir << " A\n"; 
											ss << op << "r " << $3.dir;
											ss << "\nmov A " << tmp << "\n";
											$$.cod = ss.str();
										}else if($1.tipo == ENTERO && $3.tipo == REAL){
											ss << $1.cod << $3.cod;
											ss << "mov " << $1.dir << " A\n";
											ss << "itor\n";
											ss << op << "r " << $3.dir;
											ss << "\nmov A " << tmp << "\n";
											$$.cod = ss.str();
										}else{
											ss << $1.cod << $3.cod;
											ss << "mov " << $1.dir << " A\n";
											ss << op << "r " << $3.dir;
											ss << "\nmov A " << tmp << "\n";
											$$.cod = ss.str();
										}
									}
			| Esimple { $$.tipo = $1.tipo; $$.cod = $1.cod; $$.dir = $1.dir; }
			;

	Esimple : Esimple opas Term {	
									if($1.tipo==LOGIC){
										msgError(ERR_EXIZQ_RE,$2.nlin,$2.ncol,$2.lexema.c_str());
									}
                                	if($3.tipo==LOGIC){
										msgError(ERR_EXDER_RE,$2.nlin,$2.ncol,$2.lexema.c_str());
									}

									int tmp = NuevoTemporal();
									string op = $2.lexema == "+" ? "add" : "sub";
									$$.dir = tmp;
									stringstream ss;
									
									if($1.tipo == ENTERO && $3.tipo == ENTERO){
										ss << $1.cod << $3.cod;
										ss << "mov " << $1.dir << " A\n";
										ss << op << "i " << $3.dir << "\n";
										ss << "mov A " << tmp << "\n";
										$$.tipo = ENTERO;
										$$.cod = ss.str();
									}else if($1.tipo == REAL && $3.tipo == ENTERO){
										ss << $1.cod << $3.cod;
										int tmpcnv = NuevoTemporal();
										ss << "mov " << $3.dir << " A\n";
										ss << "itor\n";
										ss << "mov A" << tmpcnv << "\n";
										ss << "mov " << $1.dir << " A\n";
										ss << op << "r " << tmpcnv << "\n";
										ss << "mov A " << tmp << "\n";
										$$.tipo = REAL;
										$$.cod = ss.str();
									}else if($1.tipo == ENTERO && $3.tipo == REAL){
										ss << $1.cod << $3.cod;
										ss << "mov " << $1.dir << " A\n";
										ss << "itor\n";
										ss << op << "r " << $3.dir << "\n";
										ss << "mov A" << tmp << "\n";
										$$.tipo = REAL;
										$$.cod = ss.str();
									}else{
										ss << $1.cod << $3.cod;
										ss << "mov " << $1.dir << " A\n";
										ss << op << "r " << $3.dir << "\n";
										ss << "mov A" << tmp << "\n";
										$$.tipo = REAL;
										$$.cod = ss.str();
									}
								}
			| Term { $$.tipo = $1.tipo; $$.cod = $1.cod; $$.dir = $1.dir; }
			| opas Term { $$.tipo = $2.tipo; $$.cod = $2.cod; $$.dir = $2.dir; }
			;

	Term    : Term opmd Factor	{
									if($1.tipo==LOGIC){
										msgError(ERR_EXIZQ_RE,$2.nlin,$2.ncol,$2.lexema.c_str());
									}
									if($3.tipo==LOGIC){
										msgError(ERR_EXDER_RE,$2.nlin,$2.ncol,$2.lexema.c_str());
									}

									int temp = NuevoTemporal();
									string op = $2.lexema == "*" ? "mul" : "div";
									$$.dir = temp;
									stringstream ss; 
									if($1.tipo == ENTERO && $3.tipo == ENTERO){
										ss << $1.cod;
										ss << $3.cod;
										ss << "mov " << $1.dir << " A\n";
										ss << op << "i " << $3.dir;
										ss << "\nmov A " << temp << "\n";
										$$.cod = ss.str();
										$$.tipo = ENTERO;
									}else if($1.tipo == REAL && $3.tipo == ENTERO){
										int tmpcnv = NuevoTemporal();
										ss << $1.cod;
										ss << $3.cod;
										ss << "mov " << $3.dir << " A\n";
										ss << "itor\n";
										ss << "mov A " << tmpcnv;
										ss << "\nmov " << $1.dir << " A\n";
										ss << op << "r " << tmpcnv;
										ss << "\nmov A " << temp << "\n";
										$$.cod = ss.str();
										$$.tipo = REAL;
									}else if($1.tipo == ENTERO && $3.tipo == REAL){
										ss << $1.cod;
										ss << $3.cod;
										ss << "mov " << $1.dir << " A\n";
										ss << "itor\n";
										ss << op << "r " << $3.dir;
										ss << "\nmov A " << temp << "\n";
										$$.cod = ss.str();                                    
										$$.tipo = REAL;
									}else{
										ss << $1.cod;
										ss << $3.cod;
										ss << "mov " << $1.dir << " A\n";
										ss << op << "r " << $3.dir;
										ss << "\nmov A " << temp << "\n";
										$$.cod = ss.str();                                    
										$$.tipo = REAL;
									}
								}
			| Factor { $$.tipo = $1.tipo; $$.cod = $1.cod; $$.dir = $1.dir; }
			;

	Factor  : Ref 	{	
						if(esArray($1.tipo)){
							msgError(ERRFALTAN,$1.nlin,$1.ncol,$1.lexema.c_str());
                    	}else{
							int tmp = NuevoTemporal();
							$$.dir = tmp;
							$$.tipo = $1.tipo;
							stringstream ss;
							ss << $1.cod;
							ss << "mov " << $1.dir << " A\n";
							ss << "muli #" << tamT($1.tipo) << "\n";
							ss << "addi #" << $1.dir_base << "\n";
							ss << "mov @A " << tmp << "\n";;
							$$.cod = ss.str();
						}
					}
			| nentero	{ 	
							$$.tipo = ENTERO;
							$$.trad = $1.lexema;
							stringstream ss;
							int tmp = NuevoTemporal(); 
							ss << "mov #" << $1.lexema <<" " << tmp << "\n";
							$$.cod = ss.str();
							$$.dir = tmp;
					  	}
			| nreal	{ 	
						$$.tipo = REAL;
						$$.trad = $1.lexema;
						stringstream ss;
						int tmp = NuevoTemporal(); 
						ss << "mov $" << $1.lexema << " " << tmp << "\n";
						$$.cod = ss.str();
						$$.dir = tmp;
					}
			| pari Expr pard	{
									$$.tipo = $2.tipo;
									$$.cod = $2.cod;
									$$.dir = $2.dir;
								}
			| nobool Factor	{
								if($2.tipo != LOGIC){
                                	msgError(ERR_EXP_LOG, $2.nlin, $2.ncol, $2.lexema.c_str());
								}else{
									stringstream ss;
									int tmp = NuevoTemporal();

									ss << $2.cod;
									ss << "mov " << $2.dir << " A\n";
									ss << "noti\n";
									ss << "mov A " << tmp << "\n";

									$$.tipo = LOGIC;
									$$.dir = tmp;
									$$.cod = ss.str();
								}
							}
			| cierto	{
							$$.tipo = LOGIC;
							stringstream ss;
							int tmp = NuevoTemporal();
							ss << "mov #1 " << tmp << "\n";
							$$.cod = ss.str();
							$$.dir = tmp;
						}
			| falso	{
						$$.tipo = LOGIC;
                        stringstream ss;
                        int tmp = NuevoTemporal();
                        ss << "mov #0 " << tmp << "\n";
                        $$.cod = ss.str();
                        $$.dir = tmp;
					}
			;

	Ref : id	{ 	
					Simbolo aux;
					if(buscarS(aux, $1.lexema)){
						int tmp = NuevoTemporal();
						stringstream ss;
						ss << "mov #0 " << tmp << "\n";
						$$.cod = ss.str();
						$$.tipo = aux.tipo;
						$$.dir_base = aux.pos;
						$$.dir = tmp;
						$$.is_array = false;
					}else {
						msgError(ERRNODECL, $1.nlin,$1.ncol, $1.lexema.c_str());
					}

	 			}
		| Ref cori	{
						if(!esArray($1.tipo)){
							msgError(ERRSOBRAN, $2.nlin, $2.ncol, $2.lexema.c_str());
						}

					} Esimple cord	{
										if($4.tipo != ENTERO){
											msgError(ERR_EXP_ENT, $1.nlin, $1.ncol, $1.lexema.c_str());
										}

                                        stringstream ss;
                                        int tmp = NuevoTemporal();
                                        int Seof = tamT($1.tipo);

                                        ss << $1.cod;
                                        ss << $4.cod;
                                        ss << "mov " << $1.dir << " A\n";
                                        ss << "muli #" << Seof;
                                        ss << "\naddi " << $4.dir;
                                        ss << "\nmov A " << tmp << "\n";

										$$.is_array = true;
                                        $$.dir = tmp;
                                        $$.tipo = buscarT($1.tipo);
                                        $$.dir_base = $1.dir_base;
                                        $$.cod = ss.str();
									}
		;
                

%%

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

