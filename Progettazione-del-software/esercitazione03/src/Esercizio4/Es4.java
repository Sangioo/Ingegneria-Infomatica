package esercizio4;

public class Es4 {
	public static void esercizio4() {
		Scuola s1 = new Scuola("Scuola elementare Giuseppe Tomassetti", "Provveditorato 1", "Via Ariosto 25");

		Insegnante i1 = new Insegnante("Walter", "White", "1989", s1);
		Insegnante i2 = new Insegnante("Elliot", "Alderson", "2015", s1);
		Insegnante i3 = new Insegnante("Mary", "Poppins", "2001", s1);
		
		Classe c1 = new Classe("I A", s1, i1, i2, i3, 20);
		Classe c2 = new Classe("IV A", s1, i2, i3, i1, 22);
		Classe c3 = new Classe("III A", s1, i3, i1, i2, 21);

		System.out.println(s1);
		System.out.println(i1);
		System.out.println(i2);

		System.out.println();
		System.out.println(c1);
		System.out.println(c2);
		System.out.println(c3);

		c2.setNumAlunni(24);
		c2.inserisciInsegnante(1,i2);
		c2.inserisciInsegnante(2,i1);

		System.out.println();
		System.out.println(c2);
	}
}
