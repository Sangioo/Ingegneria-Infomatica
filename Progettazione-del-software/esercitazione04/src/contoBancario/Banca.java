package contoBancario;

public class Banca {
	private ContoCorrente[] conti = new ContoCorrente[10];
	private int index = 0;
	private String nome;
	private String indirizzo;
	
	public Banca(String nome, String indirizzo) {
		this.nome = nome;
		this.indirizzo = indirizzo;
	}
}
