package contoBancario;

public class ContoDebito extends ContoCorrente {

	public ContoDebito(String codice, int saldo) {
		super(codice, saldo);
	}

	public void riconosciInteresse(double interesse) {
		int ammontare = (int) Math.round(this.getSaldo()*interesse);
		this.deposito(ammontare);
	}
}
