package FigureGeometriche;

public class Ellisse extends FiguraGeometrica {
    private final double semiasseMaggiore;
    private final double semiasseMinore;

    public Ellisse(double a, double b) {
        super();
        if (a > b) {
            this.semiasseMaggiore = a;
            this.semiasseMinore = b;
        } else {
            this.semiasseMaggiore = b;
            this.semiasseMinore = a;
        }
    }

    public Ellisse(String descrizione, double a, double b) {
        super(descrizione);
        if (a > b) {
            this.semiasseMaggiore = a;
            this.semiasseMinore = b;
        } else {
            this.semiasseMaggiore = b;
            this.semiasseMinore = a;
        }
    }

    public double getSemiasseMaggiore() {
        return semiasseMaggiore;
    }

    public double getSemiasseMinore() {
        return semiasseMinore;
    }

    public double area() {
        return semiasseMaggiore * semiasseMinore * Math.PI;
    }

    public double perimetro() {
        double radice = Math.sqrt((Math.pow(semiasseMaggiore, 2) + Math.pow(semiasseMinore, 2)) / 2);
        return 2 * Math.PI * radice;
    }

    public String toString() {
        return "Ellisse " + getDescrizione()
                + " semiasseMaggiore = " + getSemiasseMaggiore()
                + " semiasseMinore = " + getSemiasseMinore()
                + " area = " + area()
                + " perimetro = " + perimetro();
    }
}
