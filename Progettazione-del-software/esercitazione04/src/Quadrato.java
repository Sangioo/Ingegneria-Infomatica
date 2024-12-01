public class Quadrato extends FiguraGeometrica {
    private final double lato;

    public Quadrato(String descrizione, double lato) {
        super(descrizione);
        this.lato = lato;
    }

    public double getLato() {
        return lato;
    }

    @Override
    public double area() {
        return lato * lato;
    }

    @Override
    public double perimetro() {
        return lato * 2;
    }

    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        sb.append(getDescrizione()).append(" ");
        sb.append(lato);
        return sb.toString();
    }
}
