package FigureGeometriche;

public class Triangolo extends FiguraGeometrica {
    private final double a, b, c;

    public Triangolo(double a, double b, double c) {
        super();
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public Triangolo(String descrizione, double a, double b, double c) {
        super(descrizione);
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public double getA() {
        return a;
    }

    public double getB() {
        return b;
    }

    public double getC() {
        return c;
    }

    public double area() {
        double sp = perimetro() / 2;
        return Math.sqrt(sp * (sp - this.getA()) * (sp - this.getB()) * (sp - this.getC()));
    }

    public double perimetro() {
        return getA() + getB() + getC();
    }

    public String toString() {
        return "Triangolo " + getDescrizione()
                + " lati = " + getA() + ", " + getB() + ", " + getC()
                + " perimetro = " + perimetro()
                + " area = " + area();
    }
}
