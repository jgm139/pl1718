
public class Simbolo {

  public static final int ENTERO=1, REAL=2;

  public String nombre;
  public int tipo;          // ENTERO o REAL
  public String trad;


  public Simbolo(String nombre,int tipo,String trad) {
      this.nombre = nombre;
      this.tipo = tipo;
      this.trad = trad;
  }

}
