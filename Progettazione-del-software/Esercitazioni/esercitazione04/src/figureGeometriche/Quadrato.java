package figureGeometriche;

public class Quadrato extends Rettangolo {

	public Quadrato(String descrizione, double lato) {
		super(descrizione, lato, lato);
	}
	
	public Quadrato(double lato) {
		super(lato, lato);
	}
	
	public double getLato() {
		return this.getAltezza();
	}
	
	@Override
	public String toString() {
		return "Quadrato " + this.getDescrizione() + " lato=" + this.getLato()
		+ " area=" + this.area()
		+ " perimetro=" + this.perimetro();
	}
}
