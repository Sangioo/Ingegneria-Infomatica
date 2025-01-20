package contoBancario;

public class Main {
	public static void main(String[] args) throws Exception {
		Banca firstBankOfJava = new Banca("OOPBank", "Indirizzo");
	      
	      ContoDebito d2 = new ContoDebito("D1002", 200);
	      d2.setNome("Paolo");
	      d2.setCognome("Liberatore");
	      
	      firstBankOfJava.aggiungiConto(d2);
	      
	      ContoCredito c1 = new ContoCredito("C1001", 400);
	      c1.setNome("Francesco");
	      c1.setCognome("Leotta");
	      
	    
	      firstBankOfJava.aggiungiConto(c1);
	      
	      ContoDebito d1 = new ContoDebito("D1001", 50);
	      d1.setNome("Massimo");
	      d1.setCognome("Mecella");
	      d1.riconosciInteresse(0.65);
	      
	      firstBankOfJava.aggiungiConto(d1);
	      
	      c1.setCommissione(10);
	      c1.prelievo(100);
	      c1.prelievo(200);
	      c1.deposito(30);
		  firstBankOfJava.riordina();
	      
	      System.out.println(firstBankOfJava);
	}
}
