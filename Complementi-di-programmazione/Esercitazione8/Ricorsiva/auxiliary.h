#ifndef INCSCL_H
#define INCSCL_H


// Insieme: implementazione funzionale con memoria condivisa

// Rappresentazione con SCL
typedef int T;

// Valore errore di tipo T (per iteratore)
#define TERRORVALUE -999999

struct NodoSCL {
    T info;
    struct NodoSCL* next;
};

typedef struct NodoSCL TipoNodo;
typedef TipoNodo* Insieme;

typedef Insieme* IteratoreInsieme;

// Funzioni primitive del tipo:
Insieme insiemeVuoto();
bool estVuoto(Insieme ins);
Insieme inserisci(Insieme ins, T e);
Insieme elimina(Insieme ins, T e);
bool membro(Insieme ins, T e);

// Iteratore:
IteratoreInsieme creaIteratoreInsieme(Insieme ins);
bool hasNext(IteratoreInsieme it);
T next(IteratoreInsieme it);

#endif


/**
 * *ESERCIZIO 1:
 * Implementare la funzione che inizializza una struttura insieme contenente gli elementi dell’array arr di dimensione n.
 * @param *arr array in input
 * @param n dimensione dell'array
*/
Insieme init(int *arr, int n);

/**
 * *ESERCIZIO 2:
 * Implementare la funzione che stampi a schermo il contenuto dell’insieme.
 * @param s insieme da stampare
*/
void print(Insieme s);

/**
 * *ESERCIZIO 3:
 * Implementare la funzione che restituisce una copia dell’insieme s.
 * @param s insieme da copiare
*/
Insieme copy(Insieme s);

/**
 * *ESERCIZIO 4:
 * Implementare la funzione che restituisce la dimensione dell’insieme.
 * @param s insieme in input
*/
int size(Insieme s);

/**
 * *ESERCIZIO 5:
 * Implementare la funzione che, dati in ingresso due insiemi a e b, restituisce true se l'insieme a è completamente contenuto dentro l'insieme b.
 * @param a insieme a
 * @param b insieme b
*/
bool subset(Insieme a, Insieme b);

/**
 * *ESERCIZIO 6:
 * Implementare la funzione che, dati in ingresso due insiemi a e b, restituisce true se e solo se gli insiemi a e b sono uguali.
 * @param a insieme a
 * @param b insieme b
*/
bool equal(Insieme a, Insieme b);

/**
 * *ESERCIZIO 7:
 * Implementare la funzione che, dati in ingresso due insiemi a e b, restituisce l’insieme corrispondente all’intersezione tra i due.
 * @param a insieme a
 * @param b insieme b
*/
Insieme intersection(Insieme a, Insieme b);

/**
 * *ESERCIZIO 8:
 * Implementare la funzione che, dati in ingresso due insiemi a e b, restituisce l’insieme corrispondente all’unione dei due.
 * @param a insieme a
 * @param b insieme b
*/
Insieme union_(Insieme a, Insieme b);