package figureGeometriche;

public class FiguraGeometrica {
	private String descrizione;
	
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

	@Override
	public String toString() {
		return "FiguraGeometrica " + this.getDescrizione();
	}
	
	public double area() {
		return 0;
	}
	
	public double perimetro() {
		return 0;
	}
}
