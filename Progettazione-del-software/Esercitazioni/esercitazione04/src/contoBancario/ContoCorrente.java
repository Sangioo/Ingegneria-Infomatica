package contoBancario;

public class ContoCorrente implements Comparable {
	private final String codice;
	protected int saldo;
	private String nome, cognome;

	public ContoCorrente(String codice, int saldo) {
		this.codice = codice;
		this.saldo = saldo;
	}

	@Override
	public int compareTo(Object o) {
		ContoCorrente c = (ContoCorrente) o;
		
		if (this.getSaldo() < c.getSaldo()) {
			return -1;
		} else if (this.getSaldo() > c.getSaldo()) {
			return 1;
		} else {
			return 0;
		}
	}

	public int getSaldo() {
		return saldo;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getCognome() {
		return cognome;
	}

	public void setCognome(String cognome) {
		this.cognome = cognome;
	}

	public String getCodice() {
		return codice;
	}

	public void deposito(int cifra) {
		this.saldo += cifra;
	}
	
	public void prelievo(int cifra) {
		this.saldo -= cifra;
	}
	
	@Override
	public String toString() {
		return "Conto di " + this.getNome() + " " + this.getCognome()
				+ ", saldo=" + this.getSaldo();
	}
}
