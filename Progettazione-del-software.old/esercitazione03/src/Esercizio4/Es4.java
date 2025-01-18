package Esercizio4;

public class Es4 {
    public static void esercizio4() {
        Scuola scuola = new Scuola("Federico Caffè", "Via Fonteiana 111", "Roma");
        Insegnante[] insegnanti = new Insegnante[3];
        insegnanti[0] = new Insegnante("Alfio", "Aricò", 2000, scuola);
        insegnanti[1] = new Insegnante("Giovanni", "Antonucci", 2000, scuola);
        insegnanti[2] = new Insegnante("Galeno", "Laura", 2000, scuola);

        Classe classe = new Classe(scuola, "5CI", insegnanti, 19);

        scuola.stampaScuola();
        System.out.println();
        classe.stampaClasse();
        System.out.println();
        insegnanti[0].stampaInsegnante();
        System.out.println();
        insegnanti[1].stampaInsegnante();
        System.out.println();
        insegnanti[2].stampaInsegnante();
        System.out.println();
    }
}
