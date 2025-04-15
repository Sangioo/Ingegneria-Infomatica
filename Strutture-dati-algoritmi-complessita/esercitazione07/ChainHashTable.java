import java.util.LinkedList;
import java.util.ArrayList;

public class ChainHashTable extends AbstractHashTable {
    // Un array di LinkedList per le liste di trabocco
    private LinkedList<Entry>[] table;

    /* Costruttori */
    public ChainHashTable(int cap, int p, double lambda) {
        super(cap, p, lambda);
    }

    public ChainHashTable(int cap, int p) {
        super(cap, p); // massimo fattore di carico predefinito
    }

    public ChainHashTable(int cap) {
        super(cap); // primo predefinito
    }

    public ChainHashTable() {
        super(); // capacità predefinita
    }

    /* Metodi non implementati in AbstractHashTable */

    // Inizializza una tabella hash vuota secondo i parametri passati al costruttore
    protected void createTable() {
        table = new LinkedList[this.getCapacity()];
        for (int i = 0; i < this.getCapacity(); i++) {
            table[i] = new LinkedList<Entry>();
        }
    }

    // Restituisce il valore (intero) associato alla chiave k
    // Restituisce -1 se la chiave è assente
    public int get(String k) {
        int key = this.hashFunction(k);
        int index = -1;

        for (int i = 0; i < table[key].size(); i++) {
            if (table[key].get(i).getKey().equals(k))
                index = i;
        }

        if (index == -1) {
            return -1;
        } else {
            return table[key].get(index).getValue();
        }
    }

    // Aggiorna il valore associato alla chiave k (o inserisce una nuova coppia se
    // la chiave non è presente)
    // Restituisce il vecchio valore o -1 se la chiave non è presente
    public int put(String k, int value) {
        int key = this.hashFunction(k);
        Entry e = new Entry(k, value);
        int index = -1;

        for (int i = 0; i < table[key].size(); i++) {
            if (table[key].get(i).getKey().equals(k))
                index = i;
        }

        if (index == -1) {
            table[key].add(e);
            return -1;
        } else {
            return table[key].set(index, e).getValue();
        }
    }

    // Rimuove la coppia con chiave k
    // Restituisce il vecchio valore o -1 se la chiave non è presente
    public int remove(String k) {
        int key = this.hashFunction(k);
        int index = -1;

        for (int i = 0; i < table[key].size(); i++) {
            if (table[key].get(i).getKey().equals(k))
                index = i;
        }

        if (index == -1) {
            return -1;
        } else {
            return table[key].remove(index).getValue();
        }
    }

    // Restituisce un oggetto Iterable contenente tutte le coppie presenti nella
    // tabella hash
    public Iterable<Entry> entrySet() {
        LinkedList<Entry> ret = new LinkedList<Entry>();
        for (LinkedList<Entry> l : table) {
            ret.addAll(l);
        }
        return ret;
    }

    // stampa una rappresentazione delle coppie presenti secondo
    // il formato [(k1, v1), (k2,v2), ..., (kn, vn)]
    @Override
    public void print() {
        System.out.print("[");
        for (LinkedList<Entry> l : table) {
            for (Entry e : l) {
                System.out.print(e.toString());
                System.out.print(",");
            }
        }
        System.out.println("]");
    }

    // metodo che aggiorna la dimensione della tabella hash
    @Override
    protected void resize(int newCap) {
        LinkedList<Entry> l = (LinkedList<Entry>) this.entrySet();
        super.resize(newCap);
        this.createTable();
        for (Entry e : l) {
            this.put(e.getKey(), e.getValue());
        }
    }
}
