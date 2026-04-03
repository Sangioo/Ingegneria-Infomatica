package figureGeometriche;

public class Rettangolo extends FiguraGeometrica {
	private final double base, altezza;

	public Rettangolo(String descrizione, double base, double altezza) {
		super(descrizione);
		this.base = base;
		this.altezza = altezza;
	}

	public Rettangolo(double base, double altezza) {
		super();
		this.base = base;
		this.altezza = altezza;
	}

	public double getBase() {
		return base;
	}

	public double getAltezza() {
		return altezza;
	}

	@Override
	public String toString() {
		return "Rettangolo " + this.getDescrizione() + " base=" + base + " altezza=" + altezza
				+ " area=" + this.area()
				+ " perimetro=" + this.perimetro();
	}
	
	@Override
	public double area() {
		return base * altezza;
	}
	
	@Override
	public double perimetro() {
		return (base + altezza)*2;
	}
}
