package FigureGeometriche;

public class Cerchio extends Ellisse {
    public Cerchio(double raggio) {
        super(raggio, raggio);
    }

    public Cerchio(String descrizione, double raggio) {
        super(descrizione, raggio, raggio);
    }

    public double getRaggio() {
        return super.getSemiasseMaggiore();
    }

    public double area() {
        return Math.pow(super.getSemiasseMaggiore(), 2) * Math.PI;
    }

    public double perimetro() {
        return 2 * super.getSemiasseMaggiore() * Math.PI;
    }

    public String toString() {
        return "Cerchio " + getDescrizione()
                + " raggio = " + getRaggio()
                + " perimetro = " + perimetro()
                + " area = " + area();
    }
}
