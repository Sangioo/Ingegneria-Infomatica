package SistemaBancario;

import java.util.Arrays;

public class Banca {
    private final String nome;
    private final String indirizzo;
    private ContoCorrente[] conti;
    private int index;
    private static final int MAX = 10;

    public Banca(String nome, String indirizzo) {
        this.nome = nome;
        this.indirizzo = indirizzo;
        this.conti = new ContoCorrente[MAX];
        index = 0;
    }

    public String getNome() {
        return nome;
    }

    public String getIndirizzo() {
        return indirizzo;
    }

    public void aggiungiConto(ContoCorrente conto) {
        this.conti[index] = conto;
        index++;
        ordina();
    }

    private void ordina() {
        ContoCorrente[] tmp = Arrays.copyOf(conti, index);
        Arrays.sort(tmp);
        System.arraycopy(tmp, 0, conti, 0, conti.length);
    }

    public int getBilancio() {
        int bilancio = 0;
        for (ContoCorrente conto : conti) {
            bilancio += conto.getSaldo();
        }
        return bilancio;
    }

    @Override
    public String toString() {
        return "";
    }
}
