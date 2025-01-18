package esercizio4;

public class Scuola {
	private final String nome;
	private final String indirizzo;
	private final String provveditorato;
	
	public Scuola(String nome, String indirizzo, String provveditorato) {
		this.nome = nome;
		this.indirizzo = indirizzo;
		this.provveditorato = provveditorato;
	}

	public String getNome() {
		return nome;
	}

	public String getIndirizzo() {
		return indirizzo;
	}

	public String getProvveditorato() {
		return provveditorato;
	}

	@Override
	public String toString() {
		return "Scuola " + nome + ", indirizzo: " + indirizzo + ", provveditorato: " + provveditorato + ".";
	}
	
}
