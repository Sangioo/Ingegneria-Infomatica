package esercizio4;

public class Classe {
	private final Scuola scuola;
	private final String nome;
	private Insegnante[] insegnanti = new Insegnante[3];
	private int numAlunni;
	
	public Classe(String nome, Scuola scuola, Insegnante ins0, Insegnante ins1, Insegnante ins2, int numAlunni) {
		this.scuola = scuola;
		this.nome = nome;
		this.insegnanti[0] = ins0;
		this.insegnanti[1] = ins1;
		this.insegnanti[2] = ins2;
		this.numAlunni = numAlunni;
	}

	public String getNome() {
		return nome;
	}

	public Scuola getScuola() {
		return scuola;
	}
	
	public int getNumAlunni() {
		return numAlunni;
	}

	public void setNumAlunni(int numAlunni) {
		this.numAlunni = numAlunni;
	}
	
	public Insegnante[] getInsegnanti() {
		return insegnanti;
	}

	public void setInsegnanti(Insegnante[] insegnanti) {
		this.insegnanti = insegnanti;
	}
	
	public void inserisciInsegnante(int posizione, Insegnante i) {
		if (posizione >= 0 && posizione < 3) {
			insegnanti[posizione] = i;
		}
	}

	@Override
	public String toString() {
		return "Classe " + nome + ", scuola: " + scuola.getNome() + ", numero alunni: " + numAlunni
				+ ", insegnante 0: " + insegnanti[0].getNome()
				+ ", insegnante 1: " + insegnanti[1].getNome()
				+ ", insegnante 2: " + insegnanti[2].getNome();
	}
	
}
