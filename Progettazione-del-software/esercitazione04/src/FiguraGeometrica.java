public class FiguraGeometrica {

    private String descrizione;

    public FiguraGeometrica(String descrizione) {
        this.descrizione = descrizione;
    }

    public String getDescrizione() {
        return descrizione;
    }

    public void setDescrizione(String descrizione) {
        this.descrizione = descrizione;
    }

    @Override
    public String toString() {
        return descrizione;
    }

    public double area() {
        return 0;
    }

    public double perimetro() {
        return 0;
    }

    public static double sommaAree(FiguraGeometrica[] f) {
        double somma = 0;
        for (FiguraGeometrica elem : f) {
            somma += elem.area();
        }

        return somma;
    }
}