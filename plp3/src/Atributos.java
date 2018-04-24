public class Atributos {
    public String num_fun;
    public String th;
    public String trad;
    public String var;
    public int type;
    public String prefix;
    public boolean block;


    Atributos(Atributos left, String opas, Atributos right){
        if(left.type == 1 && right.type == 1){ //integer-integer
            this.type = 1;
            this.trad = left.trad + " " + opas + "i "+ right.trad;
        }else if(left.type == 1 && right.type == 2){ //integer-real
            this.type = 2;
            this.trad = "itor(" + left.trad + ") " + opas + "r "+ right.trad;
        }else if(left.type == 2 && right.type == 1){ //real-integer
            this.type = 2;
            this.trad = left.trad + " " + opas + "r "+ "itor(" + right.trad + ")";
        }else if(left.type == 2 && right.type == 2){ //real-real
            this.type = 2;
            this.trad = left.trad + " " + opas + "r "+ right.trad;
        }
    }

    Atributos(Token tk){
        this.type = tk.tipo;

        if(this.type == tk.ENTERO){
            this.trad = "integer";
        }else if(this.type == tk.REAL){
            this.trad = "real";
        }else{
            this.trad = tk.lexema;
        }
    }

    Atributos(){
        this.num_fun = "";
        this.th = "";
        this.trad = "";
        this.var = "";
        this.prefix = "";
        this.block = false;
    }

    public String getNum_fun(){ return this.num_fun; }
    public String getTh(){ return this.th; }
    public String getTrad(){ return this.trad; }
    public String getVar(){ return this.var; }
    public int getType(){ return this.type; }
    public String getPrefix(){ return this.prefix; }

    public void setNum_fun(String num_fun){
        this.num_fun = num_fun;
    }

    public void setTh(String th){
        this.th = th;
    }

    public void setTrad(String trad) {
        this.trad = trad;
    }

    public void setVar(String var) {
        this.var = var;
    }

    public void setType(int type) {
        this.type = type;
    }

    public void setPrefix(String prefix) {
        this.prefix = prefix;
    }

}
