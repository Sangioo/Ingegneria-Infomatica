package FigureGeometriche;

public abstract class FiguraGeometrica {
    private String descrizione = "";

    public FiguraGeometrica() {}

    public FiguraGeometrica(String descrizione) {
        this.descrizione = descrizione;
    }

    public String getDescrizione() {
        return descrizione;
    }

    public void setDescrizione(String descrizione) {
        this.descrizione = descrizione;
    }

    public abstract String toString();

    public abstract double area();

    public abstract double perimetro();

    public static double sommaAree(FiguraGeometrica[] f) {
        double somma = 0;
        for (FiguraGeometrica elem : f) {
            somma += elem.area();
        }

        return somma;
    }
}