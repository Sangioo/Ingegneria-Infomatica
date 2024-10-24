package Esercizio4;

public class Scuola {
    private String nome;
    private String indirizzo;
    private String provveditorato;

    public Scuola(String nome, String indirizzo, String provveditorato) {
        this.nome = nome;
        this.indirizzo = indirizzo;
        this.provveditorato = provveditorato;
    }

    public String getNome() {
        return nome;
    }

    public String getIndirizzo() {
        return indirizzo;
    }

    public String getProvveditorato() {
        return provveditorato;
    }

    public void stampaScuola() {
        System.out.println("Nome: " + nome);
        System.out.println("Indirizzo: " + indirizzo);
        System.out.println("Provveditorato: " + provveditorato);
    }
}
