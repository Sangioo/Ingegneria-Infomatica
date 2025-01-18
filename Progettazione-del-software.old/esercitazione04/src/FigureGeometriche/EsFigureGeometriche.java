package FigureGeometriche;

public class EsFigureGeometriche {
    public static double sommaAree(FiguraGeometrica[] f) {
        double somma = 0;
        for (FiguraGeometrica elem : f) {
            somma += elem.area();
        }
        return somma;
    }

    public static void esercizio() {
        FiguraGeometrica[] f = new FiguraGeometrica[5];
        f[0] = new Triangolo(3,3,3);
        f[1] = new Rettangolo(4,2);
        f[2] = new Quadrato(2);
        f[3] = new Ellisse(7,5);
        f[4] = new Cerchio(5);

        for (FiguraGeometrica elem : f) {
            System.out.println(elem.toString());
        }
        System.out.println("Somma delle aree: " + sommaAree(f));
    }
}
