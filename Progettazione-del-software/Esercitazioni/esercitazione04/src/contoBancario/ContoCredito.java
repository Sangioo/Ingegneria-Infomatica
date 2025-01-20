package contoBancario;

public class ContoCredito extends ContoCorrente {
	private static final int SOGLIA = 100;
	private int counter, commissione;

	public ContoCredito(String codice, int saldo) {
		super(codice, saldo);
		this.counter = 0;
		this.commissione = 0;
	}

	public int getCounter() {
		return counter;
	}

	public void reset() {
		this.counter = 0;
	}

	public double getCommissione() {
		return commissione;
	}

	public void setCommissione(int commissione) {
		this.commissione = commissione;
	}

	public int getSoglia() {
		return SOGLIA;
	}
	
	private void applicaCommissione() {
		if (counter > ContoCredito.SOGLIA)
			super.prelievo(commissione);
	}

	@Override
	public void deposito(int cifra) {
		super.deposito(cifra);
		counter++;
		applicaCommissione();
	}

	@Override
	public void prelievo(int cifra) {
		super.prelievo(cifra);
		counter++;
		applicaCommissione();
	}
}
