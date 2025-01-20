package figureGeometriche;

public class App {
	public static double sommaAree(FiguraGeometrica[] f) {
		int somma = 0;
		
		for (FiguraGeometrica figura : f) {
			somma += figura.area();
		}
		return somma;
	}
	
	public static void main(String[] args) {
		FiguraGeometrica[] af = new FiguraGeometrica[10];
		for (int i = 0; i < af.length; i++) {
			if (Math.random() < 1.0 / 5.0){
				double l = Math.random()*10;
				af[i] = new Triangolo(l, 5*l/6, 2*l/3);
			}
			else if (Math.random() < 2.0 / 5.0)
				af[i] = new Cerchio(Math.random() * 10);
			else if (Math.random() < 3.0 / 5.0)
				af[i] = new Ellisse(Math.random() * 10, Math.random() * 10);
			else if (Math.random() < 4.0 / 5.0)
				af[i] = new Quadrato(Math.random() * 10);
			else
				af[i] = new Rettangolo(Math.random() * 10, Math.random() * 10);
			
			System.out.println(af[i]);
		}
		
		double s = sommaAree(af);
		System.out.println("Area totale = " + s);
	}
}
