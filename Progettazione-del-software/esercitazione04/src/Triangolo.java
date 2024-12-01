public class Triangolo extends FiguraGeometrica {
    private final double[] lati;

    public Triangolo(String descrizione, double[] lati) {
        super(descrizione);
        this.lati = lati.clone();
    }

    public double[] getLati() {
        return lati.clone();
    }

    @Override
    public double area() {
        return lati[0] * lati[1] / 2;
    }

    @Override
    public double perimetro() {
        return lati[0] + lati[1] + lati[2];
    }

    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        sb.append(getDescrizione()).append(" ");
        sb.append(lati.toString());
        return sb.toString();
    }
}
