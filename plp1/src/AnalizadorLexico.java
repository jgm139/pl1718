import java.io.IOException;
import java.io.RandomAccessFile;

public class AnalizadorLexico {

    private RandomAccessFile toProcess;
    private int row;
    private int column;
    private int toToken;

    public AnalizadorLexico(RandomAccessFile entrada) {
        this.row = 1;
        this.column = 1;
        this.toProcess = entrada;
    }

    private void rubbish() throws IOException {
        while(this.toToken == 32 || this.toToken == '\t' || this.toToken == '\n'){
            if(this.toToken == 32 || this.toToken == '\t'){
                this.toToken = this.toProcess.read();
                this.column++;
            }else if(this.toToken == '\n'){
                this.toToken = this.toProcess.read();
                this.row++;
                this.column = 1;
            }
        }
    }

    public Token siguienteToken() {

        Token tk = new Token();
        String token = new String();
        boolean next = false;
        boolean nReal = false;
        boolean ok = false;
        boolean comment = false;

        try {
            this.toToken = this.toProcess.read();

            rubbish();

            if(this.toToken == '/'){
                comment = true;
                this.toToken = this.toProcess.read();
                this.column++;
                if(this.toToken == '*'){
                    while(comment){
                        this.toToken = this.toProcess.read();
                        if(this.toToken == '\n') {
                            this.row++;
                            this.column = 1;
                        }else{
                            this.column++;
                        }
                        if(this.toToken == '*'){
                            this.toToken = this.toProcess.read();
                            this.column++;
                            if(this.toToken == '/'){
                                comment = false;
                                this.toToken = this.toProcess.read();
                                this.column++;
                                rubbish();
                            }
                        }else if(this.toToken == -1){
                            System.err.println("Error lexico: fin de fichero inesperado");
                            System.exit(-1);
                        }
                    }
                }
            }

            tk.columna = this.column;
            tk.fila = this.row;

            switch (this.toToken){
                case -1:
                    tk.tipo = 15;
                    token = "fin de fichero";
                    ok = true;
                    break;
                case '(':
                    tk.tipo = 0;
                    token += (char) this.toToken;
                    ok = true;
                    this.column++;
                    break;
                case ')':
                    tk.tipo = 1;
                    token += (char) this.toToken;
                    ok = true;
                    this.column++;
                    break;
                case ',':
                    tk.tipo = 2;
                    token += (char) this.toToken;
                    ok = true;
                    this.column++;
                    break;
                case '&':
                    tk.tipo = 3;
                    token += (char) this.toToken;
                    ok = true;
                    this.column++;
                    break;
                case '{':
                    tk.tipo = 4;
                    token += (char) this.toToken;
                    ok = true;
                    this.column++;
                    break;
                case '}':
                    tk.tipo = 5;
                    token += (char) this.toToken;
                    ok = true;
                    this.column++;
                    break;
                case '=':
                    tk.tipo = 6;
                    token += (char) this.toToken;
                    ok = true;
                    this.column++;
                    break;
                case ';':
                    tk.tipo = 7;
                    token += (char) this.toToken;
                    ok = true;
                    this.column++;
                    break;
                case '+': case '-':
                    tk.tipo = 8;
                    token += (char) this.toToken;
                    ok = true;
                    this.column++;
                    break;
                case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':

                    while (!next){
                        if(this.toToken >= '0' && this.toToken <= '9'){
                            token += (char) this.toToken;
                            this.toToken = this.toProcess.read();
                            this.column++;
                            ok = true;
                        }else if(this.toToken == '.' && !nReal){
                            this.toToken = this.toProcess.read();

                            if((this.toToken >= 'A' && this.toToken <= 'Z') || (this.toToken >= 'a' && this.toToken < 'z')) {
                                this.toProcess.seek(this.toProcess.getFilePointer() - 2);
                                next = true;
                            }else{
                                token += '.';
                                this.column++;
                                nReal = true;
                            }
                        }else{
                            if(this.toToken != '\n' || this.toToken != 32 || this.toToken != '\t' || this.toToken != -1) {
                                this.toProcess.seek(this.toProcess.getFilePointer() - 1);
                            }
                            else{
                                this.column++;
                            }
                            next = true;
                        }
                    }

                    if(nReal){
                        tk.tipo = 14;
                    }else{
                        tk.tipo = 13;
                    }

                    break;

                default:

                    while(!next) {
                        if((this.toToken >= 'A' && this.toToken <= 'Z') || (this.toToken >= 'a' && this.toToken < 'z') || (this.toToken >= '0' && this.toToken <= '9')){
                            token += (char) this.toToken;
                            this.toToken = this.toProcess.read();
                            this.column++;
                            ok = true;
                        }else{
                            if(this.toToken != '\n' || this.toToken != 32 || this.toToken != '\t' || this.toToken != -1) {
                                this.toProcess.seek(this.toProcess.getFilePointer() - 1);
                            }
                            else{
                                this.column++;
                            }

                            next = true;
                        }
                    }

                    if(token.equals("int")){
                        tk.tipo = 9;
                    }else if(token.equals("float")){
                        tk.tipo = 10;
                    }else if(token.equals("if")){
                        tk.tipo = 11;
                    }else{
                        tk.tipo = 12;
                    }

                    break;
            }

            tk.lexema = token;

            if(!ok){
                if(this.toToken == -1){
                    System.err.println("Error lexico: fin de fichero inesperado");
                }
                else{
                    System.err.println("Error lexico (" + this.row + "," + this.column + "): caracter " + '\'' + (char) this.toToken + '\'' + " incorrecto");
                }

                System.exit(-1);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        return tk;
    }
}
