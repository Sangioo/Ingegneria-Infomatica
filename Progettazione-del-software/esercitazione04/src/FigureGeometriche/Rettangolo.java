package FigureGeometriche;

public class Rettangolo extends FiguraGeometrica {
    private final double base;
    private final double altezza;

    public Rettangolo(double base, double altezza) {
        super();
        this.base = base;
        this.altezza = altezza;
    }

    public Rettangolo(String descrizione, double base, double altezza) {
        super(descrizione);
        this.base = base;
        this.altezza = altezza;
    }

    public double getBase() {
        return base;
    }

    public double getAltezza() {
        return altezza;
    }

    public double area() {
        return getBase() * getAltezza();
    }

    public double perimetro() {
        return 2 * (getBase() + getAltezza());
    }

    public String toString() {
        return "Rettangolo " + getDescrizione()
                + " base = " + getBase()
                + " altezza = " + getAltezza()
                + " perimetro = " + perimetro()
                + " area = " + area();
    }
}