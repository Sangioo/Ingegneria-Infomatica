#pragma once

typedef int T;
struct NodoSCL
{
    T info;
    struct NodoSCL *next;
};
typedef struct NodoSCL TipoNodo;
typedef TipoNodo *TipoLista;


// Operazioni

TipoLista listaVuota();             // crea lista vuota
int estVuota(TipoLista l);          // controllo se vuota
TipoLista cons(T e, TipoLista l);   // creo lista aggiungendo per primo
T car(TipoLista l);                 // leggo valore del primo
TipoLista cdr(TipoLista l);         // ritorno coda della lista

void printlist(TipoLista l);

/**
 * *ESERCIZIO 1:
 * Implementare la funzione che, dato un array in ingresso di lunghezza len, restituisca una nuova Lista corrispondente alla sequenza contenuta nell’array.
 * @param *vec array in input
 * @param len dimensione dell'array
 * @returns lista corrispondente all'array fornito
*/
TipoLista init(T *vec, int len);

/**
 * *ESERCIZIO 2:
 * Implementare la funzione che data una lista di input, restituisca una nuova lista che contiene, per ogni elemento della lista di input, due ripetizioni contigue dello stesso.
 * Se la lista in input è vuota, si restituisca la lista vuota.
 * @param list lista in input
 * @returns una lista con due istanze contigue di ogni elemento
*/
TipoLista doubledCopy(TipoLista list);

/**
 * *ESERCIZIO 3:
 * Implementare la funzione che data in input una lista list, restituisca una nuova lista che contiene i soli elementi di list i cui valori sono multipli di m.
 * Se la lista in input è vuota, si restituisca la lista vuota.
 * @param list insieme da copiare
 * @param m numero in input
 * @returns una lista contenente solo gli elementi multipli di m
*/
TipoLista multipleSublist(TipoLista list, unsigned int m);

/**
 * *ESERCIZIO 4:
 * Implementare la funzione che data in input una lista e due posizioni start e end, restituisca una nuova Lista che contiene i valori dell’input da start a end.
 * Il valore in posizione start deve essere incluso nell’output mentre quello in posizione end no.
 * @param list lista in input
 * @param start indice di inizio
 * @param end indice di fine
 * @returns una sottolista dall'indice start (incluso) all'indice end (escluso)
*/
TipoLista subList(TipoLista list, int start, int end);

/**
 * *ESERCIZIO 5:
 * Scrivere una funzione che, date due liste in input, ritorni una nuova lista contenente tutti gli elementi di l1 nelle posizioni pari, e tutti quelli di l2 nelle posizioni dispari.
 * Si assuma che l1 e l2 abbiano la stessa lunghezza.
 * @param l1 lista 1
 * @param l2 lista 2
 * @returns una lista con gli elementi di l1 in posizioni pari e quelli di l2 in posizioni dispari
*/
TipoLista interleave(TipoLista l1, TipoLista l2);