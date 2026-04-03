#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "auxiliary.h"

/**
 * Restituisce una coda vuota.
 * @returns una coda vuota
*/
Coda * codaVuota() {
	Coda *c = (Coda *)malloc(sizeof(Coda));
	*c = NULL;
	return c;
}

/**
 * Verifica se la coda e' vuota.
 * @param *c coda in input
 * @returns true se la coda e' vuota, false altrimenti
*/
bool estCodaVuota(Coda *c) {
	if (!c) {
		puts("errore: null input");
		exit(1);
	}
  return *c == NULL;
}

/**
 * Inserisce nella coda l'elemento e.
 * @param *c coda in input
 * @param e elemento da inserire
*/
void inCoda(Coda *c , T e) {
	if (!c) {
		puts("ERRORE: null input");
		exit(1);
	}
	if (*c == NULL) {
		*c = (TipoNodo *)malloc(sizeof(TipoNodo));
		(*c)->info = e;
		(*c)->next = NULL;
	} else {
		inCoda(&((*c)->next), e);
	}
}

/**
 * Estrae il primo elemento dalla coda.
 * @param *c coda in input
 * @returns il primo elemento della coda
*/
T outCoda(Coda *c) {
	if (!c) {
		puts("ERRORE: null input");
		exit(1);
	}
	if (*c == NULL ){
		puts("ERRORE: coda vuota");
		exit(1);
	}
	TipoNodo *primo = *c;
	T primo_valore = primo->info;
	*c = (*c)->next;
	free(primo);

	return primo_valore;
}

/**
 * Legge il primo elemento della coda, senza modificarla.
 * @param *c coda in input
 * @returns il primo elemento della coda
*/
T primoCoda(Coda* c) {
	if (!c) {
		puts("ERRORE: null input");
		exit(1);
	}
	if (*c == NULL ){
		puts("ERRORE: coda vuota");
		exit(1);
	}
  return (*c)->info;
}

/**
 * Crea una coda con elementi casuali in un range
 * @param len lunghezza della coda
 * @param lower limite inferiore per i valori
 * @param upper limite superiore per i valori
 * @returns una coda con elementi casuali
*/
Coda* initCoda(int len, int lower, int upper) {
    Coda *c = codaVuota();

    for (int i=0; i<len; i++) {
        T e = (rand() % (upper - lower + 1)) + lower; 
        inCoda(c, e);
    }

    return c;
}

/**
 * Stampa la coda.
 * @param *c coda da stampare
*/
void printCoda(Coda *c) {
	Coda *t = codaVuota();

    while (!estCodaVuota(c)) {
		T e = outCoda(c);
        printf("%d ", e);
		inCoda(t, e);
    }
    printf("\n");

	while (!estCodaVuota(t)) {
		inCoda(c, outCoda(t));
	}
}