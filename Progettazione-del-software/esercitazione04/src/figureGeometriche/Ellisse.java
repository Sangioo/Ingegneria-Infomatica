package figureGeometriche;

public class Ellisse extends FiguraGeometrica {
	private final double semiasseMax, semiasseMin;

	public Ellisse(double semiasseMax, double semiasseMin) {
		super();
		this.semiasseMax = semiasseMax;
		this.semiasseMin = semiasseMin;
	}
	
	public Ellisse(String descrizione, double semiasseMax, double semiasseMin) {
		super(descrizione);
		this.semiasseMax = semiasseMax;
		this.semiasseMin = semiasseMin;
	}

	public double getSemiasseMaggiore() {
		return semiasseMax;
	}

	public double getSemiasseMinore() {
		return semiasseMin;
	}

	@Override
	public String toString() {
		return "Ellisse " + this.getDescrizione()
				+ "semiasseMaggiore=" + this.getSemiasseMaggiore()
				+ " semiasseMinore=" + this.getSemiasseMinore()
				+ " area=" + this.area()
				+ " perimetro=" + this.perimetro();
	}
	
	@Override
	public double area() {
		return Math.PI * this.getSemiasseMaggiore() * this.getSemiasseMinore();
	}
	
	@Override
	public double perimetro() {
		return 2 * Math.PI * Math.sqrt((this.getSemiasseMaggiore() * this.getSemiasseMaggiore() + this.getSemiasseMinore() * this.getSemiasseMinore())/2);
	}
}
