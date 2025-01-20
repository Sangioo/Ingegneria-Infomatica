package figureGeometriche;

public class Triangolo extends FiguraGeometrica {
	private final double a, b, c;
	
	public Triangolo(String descrizione, double lato1, double lato2, double lato3) {
		super(descrizione);
		this.a = lato1;
		this.b = lato2;
		this.c = lato3;
	}
	
	public Triangolo(double lato1, double lato2, double lato3) {
		super();
		this.a = lato1;
		this.b = lato2;
		this.c = lato3;
	}

	public double getA() {
		return a;
	}

	public double getB() {
		return b;
	}

	public double getC() {
		return c;
	}

	@Override
	public String toString() {
		return "Triangolo " + this.getDescrizione() + " lati: " + a + ", " + b + ", " + c
				+ " area=" + this.area()
				+ " perimetro=" + this.perimetro();
	}
	
	@Override
	public double area() {
		// formula di Erone
		double sp = perimetro() / 2;
		return Math.sqrt(sp * (sp - this.getA()) * (sp - this.getB()) * (sp - this.getC()));
	}
	
	@Override
	public double perimetro() {
		return a + b + c;
	}
}
