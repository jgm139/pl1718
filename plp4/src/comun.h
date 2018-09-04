//***-------------------- en comun.h -------------------------------

struct ph{
    string idfun;
    string prefix;
};

struct MITIPO{
    string lexema;
    int nlin,ncol;
    int tipo;
    string trad;
    string decl;
    bool block = false;
    struct ph ph;
};

#define YYSTYPE MITIPO

#define ERRLEXICO    1
#define ERRSINT      2
#define ERREOF       3
#define ERRLEXEOF    4
#define ERRORAMBITO  5
#define ERRORDECL    6
#define ERRORINCOM   7

void msgError(int nerror,int nlin,int ncol,const char *s);
