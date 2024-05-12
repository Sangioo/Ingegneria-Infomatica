#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "auxiliary.h"

/**
 * Crea una pila vuota.
 * @returns una pila vuota
*/
Pila* pilaVuota() {
	Pila *p = (Pila *)malloc(sizeof(Pila));
	*p = NULL;
	return p;
}

/**
 * Verifica se la pila e' vuota.
 * @param *p la pila da controllare
 * @returns true se la pila e' vuota false altrimenti
*/
bool estPilaVuota(Pila *p) {
	if (!p) {
		puts("errore: null input");
		exit(1);
	}
  return *p == NULL;
}

/**
 * Inserisce un elemento nella pila.
 * @param *p pila a cui aggiungere l'elemento
 * @param e elemento da aggiungere
*/
void inPila(Pila *p , T e) {
	if (!p) {
		puts("ERRORE: null input");
		exit(1);
	}
	TipoNodo *nuovo = (TipoNodo *)malloc(sizeof(TipoNodo));
	nuovo->info = e;
	nuovo->next = *p;
	*p = nuovo;
}

/**
 * Estrae il primo elemento dalla pila.
 * @param *p pila da cui estrarre
 * @returns l'elemento estratto
*/
T outPila(Pila *p) {
	if (!p) {
		puts("ERRORE: null input");
		exit(1);
	}
	if (*p == NULL ){
		puts("ERRORE: pila vuota");
		exit(1);
	}
	TipoNodo *primo = *p;
	T primo_valore = primo->info;
	*p = (*p)->next;
	free(primo);

	return primo_valore;
}

/**
 * Restituisce il primo elemento della pila senza modificare la pila stessa.
 * @param *p la pila di cui controllare il primo elemento
 * @returns il primo elemento della pila
*/
T primoPila(Pila* p) {
	if (!p) {
		puts("ERRORE: null input");
		exit(1);
	}
	if (*p == NULL ){
		puts("ERRORE: pila vuota");
		exit(1);
	}
  return (*p)->info;
}

/**
 * Verifica se un elemento e' presente nell'array.
 * @param e elemento da cercare
 * @param arr[] array in input
 * @param n lunghezza di arr[]
 * @returns true se l'elemento e' presente, false altrimenti
*/
bool membro(int e, const int *arr, int n) {
    for (int i=0; i<n; i++) {
        if (e == arr[i])
            return true;
    }
    return false;
}

/**
 * Crea una pila con elementi casuali in un range
 * @param len lunghezza della pila
 * @param lower limite inferiore per i valori
 * @param upper limite superiore per i valori
 * @returns una pila con elementi casuali
*/
Pila* pilaInit(int len, int lower, int upper) {
    Pila *p = pilaVuota();

    for (int i=0; i<len; i++) {
        T e = (rand() % (upper - lower + 1)) + lower; 
        inPila(p, e);
    }

    return p;
}

void printPila(Pila *p) {
	Pila *t = pilaVuota();

    while (!estPilaVuota(p)) {
		T e = outPila(p);
        printf("%d ", e);
		inPila(t, e);
    }
    printf("\n");

	while (!estPilaVuota(t)) {
		inPila(p, outPila(t));
	}
}