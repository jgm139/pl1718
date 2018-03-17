public class AnalizadorSintacticoDR {

    private AnalizadorLexico al;
    private StringBuilder rules;
    private Token token;
    private boolean flag;

    public AnalizadorSintacticoDR(AnalizadorLexico al) {
        this.al = al;
        this.rules = new StringBuilder();
        this.flag = true;
    }

    public void comprobarFinFichero() {
        if(this.token.tipo != Token.EOF){
            System.exit(-1);
        }else{
            if(this.flag){
                System.out.println(this.rules.toString());
            }
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

    public final void pair(int tEsperado) {
        if (this.token.tipo == tEsperado){
            this.token = this.al.siguienteToken();
        }else{
            errorSintaxis(this.token.nombreToken.get(tEsperado));
        }
    }

    public void Fun() {
        this.token = this.al.siguienteToken();

        if(this.token.tipo == Token.INT || this.token.tipo == Token.FLOAT){
            this.rules.append(" 1");
            Tipo();
            pair(12);//id
            Args();
            Bloque();
        }else{
            errorSintaxis("identificador 'int' 'float'");
        }
    }

    public void Tipo() {

        if(this.token.tipo == Token.INT){
            this.rules.append(" 2");
            pair(9);//int
        }else if(this.token.tipo == Token.FLOAT){
            this.rules.append(" 3");
            pair(10);//float
        }else{
            errorSintaxis("identificador 'int' 'float'");
        }
    }

    public void Args() {

        if(this.token.tipo == Token.PARI){
            this.rules.append(" 4");
            pair(0);//(
            LArgs();
            pair(1);//)
        }else{
            errorSintaxis("(");
        }
    }

    public void LArgs() {

        if(this.token.tipo == Token.INT || this.token.tipo == Token.FLOAT){
            this.rules.append(" 5");
            A();
            MasArgs();
        }else if(this.token.tipo == Token.PARD){
            this.rules.append(" 6");
        }else{
            errorSintaxis("'int' 'float'");
        }
    }

    public void MasArgs() {

        if(this.token.tipo == Token.COMA){
            this.rules.append(" 7");
            pair(2);//,
            A();
            MasArgs();
        }else if(this.token.tipo == Token.PARD){
            this.rules.append(" 8");
        }else{
            errorSintaxis(") ,");
        }
    }

    public void A() {

        if(this.token.tipo == Token.INT || this.token.tipo == Token.FLOAT){
            this.rules.append(" 9");
            Tipo();
            Var();
        }else{
            errorSintaxis("'int' 'float'");
        }
    }

    public void Var() {

        if(this.token.tipo == Token.AMP){
            this.rules.append(" 10");
            pair(3);//&
            pair(12);//id
        }else if(this.token.tipo == Token.ID){
            this.rules.append(" 11");
            pair(12);//id
        }else{
            errorSintaxis("identificador &");
        }
    }

    public void Bloque() {

        if(this.token.tipo == Token.LLAVEI){
            this.rules.append(" 12");
            pair(4);//{
            SInstr();
            pair(5);//}
        }else{
            errorSintaxis("{");
        }
    }

    public void SInstr() {

        if(this.token.tipo == Token.INT || this.token.tipo == Token.FLOAT
                || this.token.tipo == Token.IF || this.token.tipo == Token.ID
                || this.token.tipo == Token.LLAVEI){
            this.rules.append(" 13");
            Instr();
            SInstrp();
        }else{
            errorSintaxis("identificador 'int' 'float' { 'if'");
        }
    }

    public void SInstrp() {
        if(this.token.tipo == Token.INT || this.token.tipo == Token.FLOAT
                || this.token.tipo == Token.IF || this.token.tipo == Token.ID
                || this.token.tipo == Token.LLAVEI){
            this.rules.append(" 14");
            Instr();
            SInstrp();
        }else if(this.token.tipo == Token.LLAVED){
            this.rules.append(" 15");
        }else{
            errorSintaxis("identificador 'int' 'float' { } 'if'");
        }
    }

    public void Instr() {

        if(this.token.tipo == Token.LLAVEI){
            this.rules.append(" 16");
            Bloque();
        }else if(this.token.tipo == Token.ID){
            this.rules.append(" 17");
            pair(12);//id
            pair(6);//=
            E();
            pair(7);//;
        }else if(this.token.tipo == Token.IF){
            this.rules.append(" 18");
            pair(11);//if
            pair(0);//(
            E();
            pair(1);//)
            Instr();
        }else if(this.token.tipo == Token.INT || this.token.tipo == Token.FLOAT){
            this.rules.append(" 19");
            Tipo();
            pair(12);//id
            pair(7);//;
        }else{
            errorSintaxis("identificador 'int' 'float' { 'if'");
        }
    }

    public void E() {

        if(this.token.tipo == Token.ID || this.token.tipo == Token.REAL || this.token.tipo == Token.ENTERO){
            this.rules.append(" 20");
            T();
            Ep();
        }else{
            errorSintaxis("identificador numero entero numero real");
        }

    }

    public void Ep() {

        if(this.token.tipo == Token.OPAS){
            this.rules.append(" 21");
            pair(8);//+-
            T();
            Ep();
        }else if(this.token.tipo == Token.PYC || this.token.tipo == Token.PARD){
            this.rules.append(" 22");
        }else{
            errorSintaxis(") ; + -");
        }

    }

    public void T() {

        if(this.token.tipo == Token.ENTERO){
            this.rules.append(" 23");
            pair(13);//entero
        }else if(this.token.tipo == Token.REAL){
            this.rules.append(" 24");
            pair(14);//real
        }else if(this.token.tipo == Token.ID) {
            this.rules.append(" 25");
            pair(12);//id
        }else{
            errorSintaxis("identificador numero entero numero real");
        }
    }

}
