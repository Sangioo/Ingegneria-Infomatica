package Esercizio4;

public class Classe {
    private Scuola scuola;
    private String nome;
    private Insegnante[] insegnanti;
    private int numAlunni;

    public Classe(Scuola scuola, String nome, Insegnante[] insegnanti, int numAlunni) {
        this.scuola = scuola;
        this.nome = nome;
        this.insegnanti = insegnanti.clone();
        this.numAlunni = numAlunni;
    }

    public Scuola getScuola() {
        return scuola;
    }

    public String getNome() {
        return nome;
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

    public void inserisciInsegnante(int pos, Insegnante i) {
        insegnanti[pos] = i;
    }

    public void stampaClasse() {
        System.out.println("Nome: " + nome);
        System.out.println("Scuola: " + scuola.getNome());
        System.out.println("NumAlunni: " + Integer.toString(numAlunni));
        System.out.print("Insegnanti: ");
        System.out.print(insegnanti[0].getNome() + " " + insegnanti[0].getCognome() + ", ");
        System.out.print(insegnanti[1].getNome() + " " + insegnanti[1].getCognome() + ", ");
        System.out.println(insegnanti[2].getNome() + " " + insegnanti[2].getCognome());
    }
}
