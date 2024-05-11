#include <stdio.h>
#include <stdlib.h>
#include "auxiliary.h"

/**
 * Crea una lista vuota.
 * @returns una lista vuota
*/
TipoLista listaVuota() {
    return NULL;
}

/**
 * Verifica se una lista e' vuota.
 * @param l lista in input
 * @returns true se la lista e' vuota, false altrimenti
*/
int estVuota(TipoLista l) {
    return l == NULL;
}

/**
 * Aggiunge un elemento in testa alla lista.
 * @param e elemnento da aggiungere
 * @param l lista a cui aggiungere l'elemento
 * @returns una lista composta dalla lista in input con in testa l'elemento
*/
TipoLista cons(T e, TipoLista l) {
    TipoLista nuovo = (TipoLista)malloc(sizeof(TipoNodo));
    nuovo->info = e;
    nuovo->next = l;
    return nuovo;
}

/**
 * Legge il valore del primo elemento della lista
 * @param l lista da cui leggere
 * @returns il primo elemento della lista
*/
T car(TipoLista l) {
    if (l == NULL) {
        printf("ERRORE: lista vuota \n ");
        exit(1);
    }
    return l->info;
}

/**
 * Restituisce la lista data in input meno il primo elemento
 * @param l lista in input
 * @returns la lista in input meno il primo elemento
*/
TipoLista cdr(TipoLista l) {
    if (l == NULL) {
        printf("ERRORE: lista vuota \n ");
        exit(1);
    }
    return l->next;
}

/**
 * Helper per la funzione printlist()
 * @param l lista da stampare
*/
void printlist_aux(TipoLista l) {
	if (estVuota(l))
        return;
	printf("%d ", car(l));
	printlist_aux(cdr(l));
}

/**
 * Stampa in output la lista
 * @param l lista da stampare
*/
void printlist(TipoLista l) {
	printlist_aux(l);
	printf("\n");
}
