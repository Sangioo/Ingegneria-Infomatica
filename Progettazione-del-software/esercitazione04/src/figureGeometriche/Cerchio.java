package figureGeometriche;

public class Cerchio extends Ellisse {
	public Cerchio(String descrizione, double raggio) {
		super(descrizione, raggio, raggio);
	}
	
	public Cerchio(double raggio) {
		super(raggio, raggio);
	}
	
	public double getRaggio() {
		return this.getSemiasseMaggiore();
	}
	
	@Override
	public String toString() {
		return "Cerchio " + this.getDescrizione()
				+ " raggio=" + this.getRaggio()
				+ " area=" + this.area()
				+ " perimetro=" + this.perimetro();
	}
	
	@Override
	public double perimetro() {
		return 2 * Math.PI * this.getRaggio();
	}
}
