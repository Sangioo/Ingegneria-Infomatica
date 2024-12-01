public class Rettangolo extends FiguraGeometrica {
    private final double base;
    private final double altezza;

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

    @Override
    public double area() {
        return base * altezza;
    }

    @Override
    public double perimetro() {
        return 2 * (base + altezza);
    }

    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        sb.append(getDescrizione()).append(" ");
        sb.append(Double.toString(base)).append(" ");
        sb.append(Double.toString(altezza));
        return sb.toString();
    }
}