#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "auxiliary.h"

/**
 * *ESERCIZIO 1:
 * Implementare la funzione che, dato un array in ingresso di lunghezza len, restituisca una nuova Lista corrispondente alla sequenza contenuta nell’array.
 * @param *vec array in input
 * @param len dimensione dell'array
 * @returns lista corrispondente all'array fornito
*/
TipoLista init(T *vec, int len) {
    TipoLista list = listaVuota();

    for (int i=len-1; i>=0; i--) {
        list = cons(vec[i], list);
    }

    return list;
}

/**
 * *ESERCIZIO 2:
 * Implementare la funzione che data una lista di input, restituisca una nuova lista che contiene, per ogni elemento della lista di input, due ripetizioni contigue dello stesso.
 * Se la lista in input è vuota, si restituisca la lista vuota.
 * @param list lista in input
 * @returns una lista con due istanze contigue di ogni elemento
*/
TipoLista doubledCopy(TipoLista list) {
    TipoLista l = listaVuota();

    while (!estVuota(list)) {
        T e = car(list);
        l = cons(e, l);
        l = cons(e, l);
        list = cdr(list);
    }

    return l;
}

/**
 * *ESERCIZIO 3:
 * Implementare la funzione che data in input una lista list, restituisca una nuova lista che contiene i soli elementi di list i cui valori sono multipli di m.
 * Se la lista in input è vuota, si restituisca la lista vuota.
 * @param list insieme da copiare
 * @param m numero in input
 * @returns una lista contenente solo gli elementi multipli di m
*/
TipoLista multipleSublist(TipoLista list, unsigned int m) {
    TipoLista l = listaVuota();

    while (!estVuota(list)) {
        T e = car(list);
        if (e%m == 0)
            l = cons(e, l);
        list = cdr(list);
    }

    return l;
}

/**
 * *ESERCIZIO 4:
 * Implementare la funzione che data in input una lista e due posizioni start e end, restituisca una nuova Lista che contiene i valori dell’input da start a end.
 * Il valore in posizione start deve essere incluso nell’output mentre quello in posizione end no.
 * @param list lista in input
 * @param start indice di inizio
 * @param end indice di fine
 * @returns una sottolista dall'indice start (incluso) all'indice end (escluso)
*/
TipoLista subList(TipoLista list, int start, int end) {
    TipoLista l = listaVuota();
    int i = 0;
    while (!estVuota(list)) {
        T e = car(list);
        if (start <= i && i < end)
            l = cons(e, l);
        
        list = cdr(list);
        i++;
    }

    return l;
}

/**
 * *ESERCIZIO 5:
 * Scrivere una funzione che, date due liste in input, ritorni una nuova lista contenente tutti gli elementi di l1 nelle posizioni pari, e tutti quelli di l2 nelle posizioni dispari.
 * Si assuma che l1 e l2 abbiano la stessa lunghezza.
 * @param l1 lista 1
 * @param l2 lista 2
 * @returns una lista con gli elementi di l1 in posizioni pari e quelli di l2 in posizioni dispari
*/
TipoLista interleave(TipoLista l1, TipoLista l2) {
    TipoLista l = listaVuota();
    int i = 0;
    while (!estVuota(l1) || !estVuota(l2)) {
        T e;
        if (i%2 == 0) {
            e = car(l1);
            l1 = cdr(l1);
        } else {
            e = car(l2);
            l2 = cdr(l2);
        }
        l = cons(e, l);
        i++;
    }
    return l;
}


void test1() {
    printf("\nTEST ESERCIZIO 1:\n");
    const int n = 5;
    int a[n] = {1, 2, 3, 4, 5};

    TipoLista list = init(a, n);
    printf("lista: ");
    printlist(list);
}

void test2() {
	printf("\nTEST ESERCIZIO 2:\n");
    const int n = 5;
    int a[n] = {1, 2, 3, 4, 5};

    TipoLista list = init(a, n);
    printf("lista: ");
    printlist(list);

    TipoLista l = doubledCopy(list);
    printf("lista doppia: ");
    printlist(l);
}

void test3() {
	printf("\nTEST ESERCIZIO 3:\n");
    const int n = 6;
    int m = 2;
    int a[n] = {0, 1, 2, 3, 4, 5};

    TipoLista list = init(a, n);
    printf("lista: ");
    printlist(list);

    TipoLista l = multipleSublist(list, m);
    printf("lista con multipli di %d: ", m);
    printlist(l);
}

void test4() {
	printf("\nTEST ESERCIZIO 4:\n");
    const int n = 6;
    int start = 2, end = 5;
    int a[n] = {0, 1, 2, 3, 4, 5};

    TipoLista list = init(a, n);
    printf("lista: ");
    printlist(list);

    TipoLista l = subList(list, start, end);
    printf("sottolista: ");
    printlist(l);
}

void test5() {
	printf("\nTEST ESERCIZIO 5:\n");
    const int n = 5;
    int a[n] = {1, 2, 3, 4, 5};
    int b[n] = {10, 9, 8, 7, 6};

    TipoLista l1 = init(a, n);
    printf("lista 1: ");
    printlist(l1);

    TipoLista l2 = init(b, n);
    printf("lista 1: ");
    printlist(l2);

    TipoLista l = interleave(l1, l2);
    printf("interleave: ");
    printlist(l);
}