package contoBancario;

import java.util.Arrays;

public class Banca {
	private ContoCorrente[] conti;
	private int index = 0;
	private String nome;
	private String indirizzo;
	private final int MAX = 10;

	public Banca(String nome, String indirizzo) {
		this.nome = nome;
		this.indirizzo = indirizzo;
		this.conti = new ContoCorrente[MAX];
	}

	public ContoCorrente[] getConti() {
		return conti;
	}

	public int getNumConti() {
		return index;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getIndirizzo() {
		return indirizzo;
	}

	public void setIndirizzo(String indirizzo) {
		this.indirizzo = indirizzo;
	}

	public void aggiungiConto(ContoCorrente c) throws Exception {
		if (index == MAX)
			throw new Exception("raggiunto numero max di conti");
		conti[index] = c;
		index++;
		riordina();
	}

	public void riordina() {
		ContoCorrente[] buffer = Arrays.copyOf(conti, index);
		Arrays.sort(buffer);
		for (int i = 0; i < index; i++) {
			conti[i] = buffer[i];
		}
	}

	public int getBilancioTotale() {
		int totale = 0;
		for (int i = 0; i < index; i++)
			totale = totale + conti[i].getSaldo();
		return totale;
	}
	
	@Override
	public String toString() {
		StringBuilder stringa = new StringBuilder("Banca " + this.getNome()
				+ " indirizzo: " + this.getIndirizzo()
				+ "\nconti:\n");
		for (int i=0; i<index; i++) {
			stringa.append('\t' + conti[i].toString() + '\n');
		}
		return stringa.toString();
	}
}
