package esercizio4;

public class Insegnante {
	private final String nome;
	private final String cognome;
	private final String annoVincita;
	private Scuola scuola;
	
	public Insegnante(String nome, String cognome, String annoVincita, Scuola scuola) {
		this.nome = nome;
		this.cognome = cognome;
		this.annoVincita = annoVincita;
		this.scuola = scuola;
	}

	public Scuola getScuola() {
		return scuola;
	}

	public void setScuola(Scuola scuola) {
		this.scuola = scuola;
	}

	public String getNome() {
		return nome;
	}

	public String getCognome() {
		return cognome;
	}

	public String getAnnoVincita() {
		return annoVincita;
	}

	@Override
	public String toString() {
		return "Insegnante " + nome + " " + cognome + ", annoVincita: " + annoVincita + ", scuola: "
				+ scuola + ".";
	}
}
