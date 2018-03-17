import java.util.ArrayList;

public class Token {

	public int fila;
	public int columna;

	public String lexema;
	public static final ArrayList<String> nombreToken = new ArrayList<String>();

	static{
		nombreToken.add("(");
		nombreToken.add(")");
		nombreToken.add("{");
		nombreToken.add("}");
		nombreToken.add("=");
		nombreToken.add(";");
		nombreToken.add("+ -");
		nombreToken.add("'int'");
		nombreToken.add("'float'");
		nombreToken.add("'if'");
		nombreToken.add("identificador");
		nombreToken.add("numero entero");
		nombreToken.add("numero real");
		nombreToken.add("fin de fichero");
	}

	public int tipo;		// tipo es: ID, ENTERO, REAL ...

	public static final int
		PARI 		= 0,
		PARD		= 1,
		LLAVEI          = 2,
		LLAVED          = 3,
		ASIG		= 4,
		PYC		= 5,
		OPAS		= 6,
		INT		= 7,
		FLOAT		= 8,
		IF		= 9,
		ID		= 10,
		ENTERO		= 11,
		REAL		= 12,
		EOF		= 13;

	public String toString(){
	        return nombreToken.get(tipo);
	}
}

