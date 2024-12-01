public class Ellisse extends FiguraGeometrica {
    private final double max_semiasse;
    private final double min_semiasse;

    public Ellisse(String descrizione, double max_semiasse, double min_semiasse) {
        super(descrizione);
        this.max_semiasse = max_semiasse;
        this.min_semiasse = min_semiasse;
    }

    public double getMax_semiasse() {
        return max_semiasse;
    }

    public double getMin_semiasse() {
        return min_semiasse;
    }

    @Override
    public double area() {
        return max_semiasse * min_semiasse * Math.PI;
    }

    @Override
    public double perimetro() {
        double radice = Math.sqrt((Math.pow(max_semiasse, 2) + Math.pow(min_semiasse, 2)) / 2);
        return 2 * Math.PI * radice;
    }

    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        sb.append(getDescrizione()).append(" ");
        sb.append(Double.toString(max_semiasse)).append(" ");
        sb.append(Double.toString(min_semiasse));
        return sb.toString();
    }
}
