#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "auxiliary.h"

/**
 * *ESERCIZIO 6:
 * Implementare la funzione che legge una sequenza di numeri inseriti da tastiera. 
 * Quando in input viene inserito un numero negativo, la sequenza termina, e la funzione deve stampare in output tutta la sequenza inserita fino a quel momento.
*/
void stampa_sequenza() {
    int in = 0;
    Coda *c = codaVuota();

    printf("inserire numero: ");
    scanf("%d", &in);
    while (in >= 0) {
        inCoda(c, in);
        printf("inserire numero: ");
        scanf("%d", &in);
    }

    printf("sequenza inserita: ");
    while (!estCodaVuota(c)) {
        printf("%d ", outCoda(c));
    }
    printf("\n");
}

/**
 * *ESERCIZIO 7:
 * Implementare la funzione che data una coda c in input, rimuova i primi pos elementi e restituisca il valore in posizione pos.
 * Se la posizione non è nella coda, si restituisca il valore -1.
 * @param *c coda in input
 * @param pos indice da estrarre
 * @returns l'elemento in i-esima posizione
*/
int elemento_iesimo(Coda *c, int pos) {
    int i = 0;
    while (!estCodaVuota(c)) {
        T e = outCoda(c);
        if (i == pos)
            return e;
        i++;
    }
    return -1;
}

/**
 * *ESERCIZIO 8:
 * Implementare la funzione che data una coda c in input, stampi tutti gli elementi della coda tranne quelli uguali ad elem.
 * Dopo l’esecuzione della funzione, la coda c deve ancora contenere gli elementi di partenza.
 * @param *c coda da stampare
 * @param elem elemento da evitare
*/
void avoid_stampa(Coda *c, int elem) {
    Coda *t = codaVuota();

    while (!estCodaVuota(c)) {
        T e = outCoda(c);
        if (e != elem) {
            printf("%d ", e);
        }
        inCoda(t, e);
    }
    printf("\n");

    while (!estCodaVuota(t)) {
        inCoda(c, outCoda(t));
    }
}

/**
 * *ESERCIZIO 9:
 * Implementare la funzione che data una coda c in input e un numero di elementi da stampare n, restituisce una nuova coda di n elementi, ottenuta dalla coda c nel seguente modo:
 * 1. Se n è minore o uguale al numero di elementi contenuti in c, la coda risultante conterrà i primi n elementi di c
 * 2. Se n è maggiore del numero di elementi in c, la coda conterrà gli elementi di c, in sequenza, ricominciando dal primo, ogni qualvolta la coda viene “esaurita”, finché non si arriva ad n.
 * @param *c coda in input
 * @param n numero di elementi da stampare
 * @returns una coda di n elementi
*/
Coda * coda_circolare(Coda *c, int n) {
    Coda *out = codaVuota();
    for (int i=0; i<n; i++) {
        T e = outCoda(c);
        inCoda(out, e);
        inCoda(c, e);
    }

    return out;
}

/**
 * *ESERCIZIO 10:
 * Implementare la funzione che data una coda c in input, restituisca una nuova coda con solo gli elementi di c in posizione pari.
 * @param *c coda in input
 * @returns una coda con solo gli elementi pari di c
*/
Coda * elementi_pari(Coda *c) {
    Coda *out = codaVuota();
    Coda *t = codaVuota();
    int i = 0;

    while (!estCodaVuota(c)) {
        T e = outCoda(c);
        if (i%2 == 0)
            inCoda(out, e);
        i++;
        inCoda(t, e);
    }

    while (!estCodaVuota(t)) {
        inCoda(c, outCoda(t));
    }

    return out;
}


void test6() {
    printf("\nTEST ESERCIZIO 6:\n");
    // stampa_sequenza();
}

void test7() {
	printf("\nTEST ESERCIZIO 7:\n");
    Coda *c = initCoda(10, 0, 20);
    int pos = 5;

    printf("coda: ");
    printCoda(c);
    
    printf("elemento in posizione %d: %d\n", pos, elemento_iesimo(c, pos));
}

void test8() {
	printf("\nTEST ESERCIZIO 8:\n");
    Coda *c = initCoda(10, 0, 20);
    int elem = 5;

    printf("coda: ");
    printCoda(c);

    printf("coda senza %d: ", elem);
    avoid_stampa(c, elem);

    printf("coda: ");
    printCoda(c);
}

void test9() {
	printf("\nTEST ESERCIZIO 9:\n");
    Coda *c = initCoda(10, 0, 20);
    int n = 15;

    printf("coda: ");
    printCoda(c);

    Coda *cc = coda_circolare(c, n);
    printf("coda circolare: ");
    printCoda(cc);
}

void test10() {
	printf("\nTEST ESERCIZIO 10:\n");
    Coda *c = initCoda(10, 0, 20);

    printf("coda: ");
    printCoda(c);

    Coda *p = elementi_pari(c);
    printf("coda con elementi in posizione pari: ");
    printCoda(p);
}