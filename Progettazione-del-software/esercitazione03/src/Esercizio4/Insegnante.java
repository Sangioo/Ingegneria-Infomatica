package Esercizio4;

public class Insegnante {
    private String nome;
    private String cognome;
    private int annoVincita;
    private Scuola scuola;

    public Insegnante(String nome, String cognome, int annoVincita,  Scuola scuola) {
        this.nome = nome;
        this.cognome = cognome;
        this.annoVincita = annoVincita;
        this.scuola = scuola;
    }

    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }

    public int getAnnoVincita() {
        return annoVincita;
    }

    public Scuola getScuola() {
        return scuola;
    }

    public void setScuola(Scuola nuova_scuola) {
        this.scuola = nuova_scuola;
    }

    public void stampaInsegnante() {
        System.out.println("Nome: " + nome);
        System.out.println("Cognome: " + cognome);
        System.out.println("AnnoVincita: " + Integer.toString(annoVincita));
        System.out.println("Scuola: " + scuola.getNome());
    }
}
