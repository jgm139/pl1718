import java.util.ArrayList;
import java.util.Stack;

public class AnalizadorSintacticoSLR {

    private AnalizadorLexico al;
    private Token token;
    private int longRules [] = {0, 5, 1, 1, 3, 2, 1, 1, 4, 5, 3, 3, 1, 1, 1, 1};
    private int leftRules [] = {0, 0, 1, 1, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6};
    private int action[][] =
            /*pari,     pard,     llavei,     llaved,     asig,     pyc,     opas,     int,     float,     if,     id,     numentero,     numreal,     EOF*/
            {{0,        0,        0,          0,          0,        0,       0,        1002,    1003,      0,      0,      0,             0,           0},
            {0,         0,        0,          0,          0,        0,       0,        0,       0,         0,      0,      0,             0,           2000},
            {0,         0,        0,          0,          0,        0,       0,        0,       0,         0,      2002,   0,             0,           0},
            {0,         0,        0,          0,          0,        0,       0,        0,       0,         0,      2003,   0,             0,           0},
            {0,         0,        0,          0,          0,        0,       0,        0,       0,         0,      1005,   0,             0,           0},
            {1006,      0,        0,          0,          0,        0,       0,        0,       0,         0,      0,      0,             0,           0},
            {0,         1007,     0,          0,          0,        0,       0,        0,       0,         0,      0,      0,             0,           0},
            {0,         0,        1009,       0,          0,        0,       0,        0,       0,         0,      0,      0,             0,           0},
            {0,         0,        0,          0,          0,        0,       0,        0,       0,         0,      0,      0,             0,           2001},
            {0,         0,        1009,       0,          0,        0,       0,        1002,    1003,      1014,   1013,   0,             0,           0},
            {0,         0,        1009,       1023,       0,        0,       0,        1002,    1003,      1014,   1013,   0,             0,           0},
            {0,         0,        2006,       2006,       0,        0,       0,        2006,    2006,      2006,   2006,   0,             0,           0},
            {0,         0,        2007,       2007,       0,        0,       0,        2007,    2007,      2007,   2007,   0,             0,           0},
            {0,         0,        0,          0,          1029,     0,       0,        0,       0,         0,      0,      0,             0,           0},
            {1015,      0,        0,          0,          0,        0,       0,        0,       0,         0,      0,      0,             0,           0},
            {0,         0,        0,          0,          0,        0,       0,        0,       0,         0,      1018,   1016,          1017,        0},
            {0,         2013,     0,          0,          0,        2013,    2013,     0,       0,         0,      0,      0,             0,           0},
            {0,         2014,     0,          0,          0,        2014,    2014,     0,       0,         0,      0,      0,             0,           0},
            {0,         2015,     0,          0,          0,        2015,    2015,     0,       0,         0,      0,      0,             0,           0},
            {0,         1020,     0,          0,          0,        0,       1021,     0,       0,         0,      0,      0,             0,           0},
            {0,         0,        1009,       0,          0,        0,       0,        1002,    1003,      1014,   1013,   0,             0,           0},
            {0,         0,        0,          0,          0,        0,       0,        0,       0,         0,      1018,   1016,          1017,        0},
            {0,         2011,     0,          0,          0,        2011,    2011,     0,       0,         0,      0,      0,             0,           0},
            {0,         0,        2004,       2004,       0,        0,       0,        2004,    2004,      2004,   2004,   0,             0,           2004},
            {0,         0,        2005,       2005,       0,        0,       0,        2005,    2005,      2005,   2005,   0,             0,           0},
            {0,         0,        0,          0,          0,        0,       0,        0,       0,         0,      1026,   0,             0,           0},
            {0,         0,        0,          0,          0,        1027,    0,        0,       0,         0,      0,      0,             0,           0},
            {0,         0,        2010,       2010,       0,        0,       0,        2010,    2010,      2010,   2010,   0,             0,           0},
            {0,         0,        2009,       2009,       0,        0,       0,        2009,    2009,      2009,   2009,   0,             0,           0},
            {0,         0,        0,          0,          0,        0,       0,        0,       0,         0,      1018,   1016,          1017,        0},
            {0,         0,        0,          0,          0,        1031,    1021,     0,       0,         0,      0,      0,             0,           0},
            {0,         0,        2008,       2008,       0,        0,       0,        2008,    2008,      2008,   2008,   0,             0,           0},
            {0,         2012,     0,          0,          0,        2012,    2012,     0,       0,         0,      0,      0,             0,           0}};

    private int go_to[][] =
            /*Fun,      Tipo,     Bloque,     SInstr,     Instr,     E,      T*/
            {{1,        4,        -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,        8,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        25,       12,         10,         11,       -1,      -1},
            {-1,        25,       12,         -1,         24,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       19,      32},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        25,       12,         -1,         28,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      22},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       30,      32},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      -1},
            {-1,        -1,       -1,         -1,         -1,       -1,      22}};

    private Stack<Integer> stack = new Stack();
    private ArrayList<Integer> rules = new ArrayList();

    public AnalizadorSintacticoSLR(AnalizadorLexico al) {
        this.al = al;
    }

    public final void errorSintaxis(String tokEsperado){
        if(this.token.lexema.equals("fin de fichero")){
            System.err.println("Error sintactico: encontrado " + this.token.lexema + ", esperaba " + tokEsperado);
        }else{
            System.err.println("Error sintactico (" + this.token.fila + "," + this.token.columna + "): encontrado '" + this.token.lexema + "', esperaba " + tokEsperado);
        }
        System.exit(-1);
    }

    public void analizar() {
        this.stack.push(0);
        this.token = al.siguienteToken();
        int j;
        boolean end = false;

        while(!end){
            j=this.action[this.stack.lastElement()][this.token.tipo];
            //System.out.println(this.token.lexema);
            if(j>1000 && j<2000){
                //System.out.println("Desplazamiento " + j);
                this.stack.push(j-1000);
                this.token = al.siguienteToken();
                //System.out.println(this.token.lexema);
            }else if(j>2000){
                //System.out.println("Regla " + j);
                this.rules.add(j-2000);
                for(int i = 1;i<=this.longRules[j-2000];i++){
                    this.stack.pop();
                }
                this.stack.push(this.go_to[this.stack.lastElement()][this.leftRules[j-2000]]);
            }else if(j==2000){
                end = true;
            }else{
                int error;
                String tEsperado = "";
                for(int i=0;i<14;i++) {
                    error = this.action[this.stack.lastElement()][i];
                    //System.out.println(error);
                    if(error>0){
                        tEsperado += this.token.nombreToken.get(i);
                    }
                }
                errorSintaxis(tEsperado);
            }
        }
        for(int i=this.rules.size()-1;i>=0;i--) {
            System.out.print(this.rules.get(i) + " ");
        }
    }
}