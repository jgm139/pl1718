public class TraductorDR {

    private AnalizadorLexico al;
    private StringBuilder traduction;
    private Token token;
    private TablaSimbolos ts;
    private String variables;
    private boolean flag;


    public TraductorDR(AnalizadorLexico al) {
        this.al = al;
        this.variables = "";
        this.traduction = new StringBuilder();
        this.ts = new TablaSimbolos(null);
        this.flag = true;
    }

    public void comprobarFinFichero() {
        if(this.token.tipo != Token.EOF){
            errorSintaxis("fin de fichero");
        }else{
            if(this.flag){
                //System.out.println(this.traduction.toString());
            }
        }
    }

    public final void pair(int tEsperado) {
        if (this.token.tipo == tEsperado){
            this.token = this.al.siguienteToken();
        }else{
            errorSintaxis(this.token.nombreToken.get(tEsperado));
        }
    }

    public final void errorSintaxis(String tokEsperado){
        if(this.token.lexema.equals("fin de fichero")){
            System.err.println("Error sintactico: encontrado " +this.token.lexema+ ", esperaba "+tokEsperado);
        }else{
            System.err.println("Error sintactico ("+this.token.fila+","+this.token.columna+"): encontrado '" +this.token.lexema+ "', esperaba "+tokEsperado);
        }
        System.exit(-1);
    }

    public final void errorAmbito(){
        System.err.println("Error semantico ("+this.token.fila+","+this.token.columna+"): '"+this.token.lexema+"' ya existe en este ambito");
        System.exit(-1);
    }

    public final void errorNoDeclarado(){
        System.err.println("Error semantico ("+this.token.fila+","+this.token.columna+"): '"+this.token.lexema+"' no ha sido declarado");
        System.exit(-1);
    }

    public final void errorIncompatible(){
        System.err.println("Error semantico ("+this.token.fila+","+this.token.columna+"): '"+this.token.lexema+"' tipos incompatibles entero/real");
        System.exit(-1);
    }

    public String Fun() {
        this.token = this.al.siguienteToken();

        if(this.token.tipo == Token.INT || this.token.tipo == Token.FLOAT){
            String id;
            Atributos args, tipo, bloque;

            tipo = Tipo();
            id = this.token.lexema;
            pair(12);//id
            args = Args();
            Atributos a = new Atributos();
            a.num_fun = id;
            a.prefix = id;
            bloque = Bloque(a);

            this.traduction.append("function "+id+args.trad+":"+tipo.trad+";\n"+
                    (this.variables == "" ? "" : "var\t"+this.variables.substring(0,this.variables.length()-1))+
                    '\n'+bloque.trad);
        }else{
            errorSintaxis("identificador 'int' 'float'");
        }

        return this.traduction.toString();
    }

    public Atributos Tipo() {
        Atributos tipoth = new Atributos();

        if(this.token.tipo == Token.INT){
            tipoth.trad = "integer";
            tipoth.type = Simbolo.ENTERO;
            pair(9);//int
        }else if(this.token.tipo == Token.FLOAT){
            tipoth.trad = "real";
            tipoth.type = Simbolo.REAL;
            pair(10);//float
        }else{
            errorSintaxis("identificador 'int' 'float'");
        }

        return tipoth;
    }

    public Atributos Args() {
        String largstrad;
        Atributos argsth = new Atributos();

        if(this.token.tipo == Token.PARI){
            pair(0);//(
            largstrad = LArgs().trad;
            pair(1);//)

            if(!largstrad.equals("")){
                argsth.trad = "("+largstrad+")";
            }
        }else{
            errorSintaxis("(");
        }

        return argsth;
    }

    public Atributos LArgs() {
        String atrad, masargstrad;
        Atributos largsth = new Atributos();

        if(this.token.tipo == Token.INT || this.token.tipo == Token.FLOAT){
            atrad = A().trad;
            masargstrad = MasArgs().trad;
            largsth.trad = atrad+masargstrad;
        }else if(this.token.tipo == Token.PARD){
        }else{
            errorSintaxis("'int' 'float'");
        }

        return largsth;
    }

    public Atributos MasArgs() {
        String atrad, masargstrad;
        Atributos masargsth = new Atributos();

        if(this.token.tipo == Token.COMA){
            pair(2);//,
            atrad = A().trad;
            masargstrad = MasArgs().trad;
            masargsth.trad = ";"+atrad+masargstrad;
        }else if(this.token.tipo == Token.PARD){
        }else{
            errorSintaxis(") ,");
        }

        return masargsth;
    }

    public Atributos A() {
        Atributos ath = new Atributos();

        if(this.token.tipo == Token.INT || this.token.tipo == Token.FLOAT){
            Atributos tipo = Tipo();
            Atributos var = Var();
            boolean ok = this.ts.anyadir(new Simbolo(var.trad, tipo.type, var.trad));
            if(!ok){
                errorAmbito();
            }
            ath.trad = var.th+var.trad+":"+tipo.trad;
        }else{
            errorSintaxis("'int' 'float'");
        }

        return ath;
    }

    public Atributos Var() {
        Atributos varth = new Atributos();

        if(this.token.tipo == Token.AMP){
            String id;
            pair(3);//&
            id = this.token.lexema;
            pair(12);//id
            varth.trad = id;
            varth.th = "var ";
        }else if(this.token.tipo == Token.ID){
            String id = this.token.lexema;
            pair(12);//id
            varth.trad = id;
        }else{
            errorSintaxis("identificador &");
        }

        return varth;
    }

    public Atributos Bloque(Atributos fun) {
        Atributos bloqueth = new Atributos();
        bloqueth.num_fun = fun.num_fun;

        if(this.token.tipo == Token.LLAVEI){
            pair(4);//{
            Atributos sinstrth = SInstr(fun);
            pair(5);//}

            if(sinstrth.trad.equals("")){
                bloqueth.trad = "begin\n"+"doNothing\n"+"end";
            }else{
                bloqueth.trad = "begin\n"+sinstrth.trad+"end";
            }

        }else{
            errorSintaxis("{");
        }

        return bloqueth;
    }

    public Atributos SInstr(Atributos fun) {
        Atributos sinstrth = new Atributos();
        sinstrth.num_fun = fun.num_fun;

        if(this.token.tipo == Token.INT || this.token.tipo == Token.FLOAT
                || this.token.tipo == Token.IF || this.token.tipo == Token.ID
                || this.token.tipo == Token.LLAVEI){
            Atributos instr = Instr(fun);
            Atributos sinstrp = SInstrp(fun);
            boolean isBlock = instr.block;

            if(sinstrp.trad == ""){
                if(isBlock) {
                    sinstrth.trad = (instr.trad.equals("") ? "" : instr.trad + "\n\n");
                }else{
                    sinstrth.trad = (instr.trad.equals("") ? "" : instr.trad + "\n");;
                }
            }else{
                if(isBlock){
                    sinstrth.trad = (instr.trad.equals("") ? "" : instr.trad+"\n;\n")+sinstrp.trad;
                }else{
                    sinstrth.trad = (instr.trad.equals("") ? "" : instr.trad+";\n")+sinstrp.trad;
                }
            }

        }else{
            errorSintaxis("identificador 'int' 'float' { 'if'");
        }
        return sinstrth;
    }

    public Atributos SInstrp(Atributos fun) {
        Atributos sinstrpth = new Atributos();
        sinstrpth.num_fun = fun.num_fun;

        if(this.token.tipo == Token.INT || this.token.tipo == Token.FLOAT
                || this.token.tipo == Token.IF || this.token.tipo == Token.ID
                || this.token.tipo == Token.LLAVEI){
            Atributos instr = Instr(fun);
            Atributos sinstrp = SInstrp(fun);
            boolean isBlock = instr.block;

            if(sinstrp.trad == ""){
                if(isBlock) {
                    sinstrpth.trad = (instr.trad.equals("") ? "" : instr.trad + "\n\n");
                }else{
                    sinstrpth.trad = (instr.trad.equals("") ? "" : instr.trad + "\n");;
                }
            }else{
                if(isBlock){
                    sinstrpth.trad = (instr.trad.equals("") ? "" : instr.trad+"\n;\n")+sinstrp.trad;
                }else{
                    sinstrpth.trad = (instr.trad.equals("") ? "" : instr.trad+";\n")+sinstrp.trad;
                }
            }

        }else if(this.token.tipo == Token.LLAVED){
        }else{
            errorSintaxis("identificador 'int' 'float' { } 'if'");
        }

        return  sinstrpth;
    }

    public Atributos Instr(Atributos fun) {
        Atributos instrth = new Atributos();
        instrth.num_fun = fun.num_fun;

        if(this.token.tipo == Token.LLAVEI){
            TablaSimbolos aux = new TablaSimbolos(this.ts);
            this.ts = aux;

            String ff = fun.prefix;
            fun.prefix+="_";
            Atributos bloque = Bloque(fun);
            fun.prefix = ff;
            instrth.block = true;
            this.ts = this.ts.padre;

            instrth.trad = bloque.trad;
        }else if(this.token.tipo == Token.ID){
            String id;
            Simbolo s;
            id = this.token.lexema;

            if((s=this.ts.buscar(id))==null){
                errorNoDeclarado();
            }

            pair(12);//id
            Token tokenAux = this.token;
            pair(6);//=
            Atributos e = E();

            if(s.tipo==Simbolo.ENTERO && e.type==Token.REAL){
                this.token = tokenAux;
                errorIncompatible();
            }
            pair(7);//;

            if(s.tipo == e.type){
                instrth.trad = s.trad+" := "+e.trad;
            }else if(s.tipo == Simbolo.ENTERO && e.type == Simbolo.REAL){
                this.token = tokenAux;
                errorIncompatible();
            }else if(s.tipo == Simbolo.REAL && e.type == Simbolo.ENTERO){
                instrth.trad = s.trad+" := itor("+e.trad+")";
            }

        }else if(this.token.tipo == Token.IF){
            String etrad;

            pair(11);//if
            pair(0);//(
            etrad = E().trad;
            pair(1);//)
            Atributos instr = Instr(fun);
            instrth.block = instr.block;

            if(instr.trad.equals("")){
                instrth.trad = "if "+etrad+" then\ndoNothing";
            }else{
                instrth.trad = "if "+etrad+" then\n"+instr.trad;
            }
        }else if(this.token.tipo == Token.INT || this.token.tipo == Token.FLOAT){
            String id;

            int tipotype = Tipo().type;
            id = this.token.lexema;

            String tradsymb;

            if(this.ts.padre!=null){
                tradsymb = fun.prefix+id;
            }else{
                tradsymb = id;
            }

            Simbolo s = new Simbolo(id, tipotype, tradsymb);

            if(!this.ts.anyadir(s)){
                errorAmbito();
            }

            pair(12);//id
            pair(7);//;

            if(tipotype==Simbolo.ENTERO){
                this.variables += '\t'+s.trad+":integer;\n";
            }else if(tipotype==Simbolo.REAL){
                this.variables += '\t'+s.trad+":real;\n";
            }
            instrth.prefix = fun.prefix;

        }else{
            errorSintaxis("identificador 'int' 'float' { 'if'");
        }

        return instrth;
    }

    public Atributos E() {
        Atributos eth = new Atributos();

        if(this.token.tipo == Token.ID || this.token.tipo == Token.REAL || this.token.tipo == Token.ENTERO){
            Atributos a = T();

            Atributos ep = Ep(a);
            eth.trad = ep.trad;
            eth.type = ep.type;

        }else{
            errorSintaxis("identificador numero entero numero real");
        }

        return eth;
    }

    public Atributos Ep(Atributos a) {
        Atributos epth;

        if(this.token.tipo == Token.OPAS){
            String opas = this.token.lexema;
            pair(8);//+-
            Atributos der = T();
            Atributos aux = new Atributos(a, opas, der);
            epth = Ep(aux);
        }else if(this.token.tipo == Token.PYC || this.token.tipo == Token.PARD){
            epth = a;
        }else{
            epth = a;
            errorSintaxis(") ; + -");
        }

        return epth;
    }

    public Atributos T() {
        Atributos tth = new Atributos();
        Simbolo s;

        if(this.token.tipo == Token.ENTERO){
            tth.trad = this.token.lexema;
            tth.type = Simbolo.ENTERO;
            pair(13);//entero
        }else if(this.token.tipo == Token.REAL){
            tth.trad = this.token.lexema;
            tth.type = Simbolo.REAL;
            pair(14);//real
        }else if(this.token.tipo == Token.ID) {
            if((s=this.ts.buscar(this.token.lexema))!=null){
                tth.trad = s.trad;
                tth.type = s.tipo;
            }else{
                errorNoDeclarado();
            }
            pair(12);//id
        }else{
            errorSintaxis("identificador numero entero numero real");
        }

        return tth;
    }

}