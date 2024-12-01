package FigureGeometriche;

public class Quadrato extends Rettangolo {

    public Quadrato(double lato) {
        super(lato, lato);
    }

    public Quadrato(String descrizione, double lato) {
        super(descrizione, lato, lato);
    }

    public double getLato() {
        return super.getAltezza();
    }

    public String toString() {
        return "Quadrato " + getDescrizione()
                + " Lato = " + getLato()
                + " area = " + area()
                + " perimetro = " + perimetro();
    }
}
