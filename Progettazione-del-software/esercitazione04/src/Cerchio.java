public class Cerchio extends FiguraGeometrica {
    public final double raggio;

    public Cerchio(String descrizione, double raggio) {
        super(descrizione);
        this.raggio = raggio;
    }

    public double getRaggio() {
        return raggio;
    }

    @Override
    public double area() {
        return Math.pow(raggio, 2) * Math.PI;
    }

    @Override
    public double perimetro() {
        return 2 * raggio * Math.PI;
    }

    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        sb.append(getDescrizione() + " ");
        sb.append(Double.toString(raggio));
        return sb.toString();
    }
}
