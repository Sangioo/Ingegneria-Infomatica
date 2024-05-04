#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "auxiliary.h"

/**
 * *ESERCIZIO 1:
 * Implementare la funzione che inizializza una struttura insieme contenente gli elementi dell’array arr di dimensione n.
 * @param *arr array in input
 * @param n dimensione dell'array
*/
Insieme init(int *arr, int n) {
	Insieme ins = insiemeVuoto();

    for (int i=n-1; i>=0; i--) {
        ins = inserisci(ins, arr[i]);
    }

    return ins;
}

/**
 * *ESERCIZIO 2:
 * Implementare la funzione che stampi a schermo il contenuto dell’insieme.
 * @param s insieme da stampare
*/
void print(Insieme s) {
    IteratoreInsieme iter = creaIteratoreInsieme(s);
    while (hasNext(iter)) {
        printf("%d ", next(iter));
    }
    printf("\n");
}

/**
 * *ESERCIZIO 3:
 * Implementare la funzione che restituisce una copia dell’insieme s.
 * @param s insieme da copiare
*/
Insieme copy(Insieme s) {
    Insieme ins = insiemeVuoto();
    IteratoreInsieme iter = creaIteratoreInsieme(s);

    while (hasNext(iter)) {
        ins = inserisci(ins, next(iter));
    }

    return ins;
}

/**
 * *ESERCIZIO 4:
 * Implementare la funzione che restituisce la dimensione dell’insieme.
 * @param s insieme in input
*/
int size(Insieme s) {
    IteratoreInsieme iter = creaIteratoreInsieme(s);
    int count = 0;

    while (hasNext(iter)) {
        count++;
        next(iter);
    }

    return count;
}

/**
 * *ESERCIZIO 5:
 * Implementare la funzione che, dati in ingresso due insiemi a e b, restituisce true se l'insieme a è completamente contenuto dentro l'insieme b.
 * @param a insieme a
 * @param b insieme b
*/
bool subset(Insieme a, Insieme b) {
    IteratoreInsieme iter = creaIteratoreInsieme(a);
    bool incluso = true;

    while (hasNext(iter)) {
        T e = next(iter);
        incluso = incluso && membro(b, e);
    }
    
    return incluso;
}

/**
 * *ESERCIZIO 6:
 * Implementare la funzione che, dati in ingresso due insiemi a e b, restituisce true se e solo se gli insiemi a e b sono uguali.
 * @param a insieme a
 * @param b insieme b
*/
bool equal(Insieme a, Insieme b) {
    IteratoreInsieme iter_a = creaIteratoreInsieme(a);
    IteratoreInsieme iter_b = creaIteratoreInsieme(b);
    bool uguali = true;

    if (size(a) != size(b)) {
        return false;
    } else {
        while (hasNext(iter_a) && hasNext(iter_b)) {
            T elem_a = next(iter_a);
            T elem_b = next(iter_b);
            uguali = uguali && membro(a, elem_b) && membro(b, elem_a);
        }
    }

    return uguali;
}

/**
 * *ESERCIZIO 7:
 * Implementare la funzione che, dati in ingresso due insiemi a e b, restituisce l’insieme corrispondente all’intersezione tra i due.
 * @param a insieme a
 * @param b insieme b
*/
Insieme intersection(Insieme a, Insieme b) {
    Insieme res = insiemeVuoto();
    IteratoreInsieme iter = creaIteratoreInsieme(a);

    while (hasNext(iter)) {
        T e = next(iter);
        if (membro(b, e)) {
            res = inserisci(res, e);
        }
    }

    return res;
}

/**
 * *ESERCIZIO 8:
 * Implementare la funzione che, dati in ingresso due insiemi a e b, restituisce l’insieme corrispondente all’unione dei due.
 * @param a insieme a
 * @param b insieme b
*/
Insieme union_(Insieme a, Insieme b) {
    Insieme res = insiemeVuoto();
    IteratoreInsieme iter = creaIteratoreInsieme(b);
    res = copy(a);

    while (hasNext(iter)) {
        T e = next(iter);
        res = inserisci(res, e);
    }

    return res;
}


void test1() {
    printf("\nTEST ESERCIZIO 1:\n");
    const int n = 5;
	int a[n] = {1, 2, 3, 4, 5};

    Insieme ins = init(a, n);
    printf("insieme: ");
    print(ins);
}

void test2() {
	printf("\nTEST ESERCIZIO 2:\n");
    const int n = 5;
	int a[n] = {1, 2, 3, 4, 5};
    Insieme ins = init(a, n);
    
    printf("insieme: ");
    print(ins);
}

void test3() {
	printf("\nTEST ESERCIZIO 3:\n");
    const int n = 5;
	int a[n] = {1, 2, 3, 4, 5};
    Insieme ins1 = init(a, n);

    printf("insieme 1: ");
    print(ins1);

    Insieme ins2 = copy(ins1);
    printf("insieme 2: ");
    print(ins2);
}

void test4() {
	printf("\nTEST ESERCIZIO 4:\n");
    const int n = 5;
	int a[n] = {1, 2, 3, 4, 5};
    Insieme ins = init(a, n);

    printf("insieme: ");
    print(ins);
    printf("dimensione insieme: %d\n", size(ins));
}

void test5() {
	printf("\nTEST ESERCIZIO 5:\n");
    const int n = 5, m = 10;
	int a[n] = {1, 2, 3, 4, 5};
    int b[m] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Insieme ins1 = init(a, n);
    Insieme ins2 = init(b, m);

    printf("insieme a: ");
    print(ins1);
    printf("insieme b: ");
    print(ins2);

    const char *s = (subset(ins1, ins2)) ? "true" : "false";

    printf("insieme a incluso in insieme b: %s\n", s);
}

void test6() {
	printf("\nTEST ESERCIZIO 6:\n");
    const int n = 5, m = 5;
	int a[n] = {1, 2, 3, 4, 5};
    int b[m] = {1, 2, 3, 4, 5};
    Insieme ins1 = init(a, n);
    Insieme ins2 = init(b, m);

    printf("insieme a: ");
    print(ins1);
    printf("insieme b: ");
    print(ins2);

    const char *s = (equal(ins1, ins2)) ? "true" : "false";

    printf("insieme a uguale a insieme b: %s\n", s);
}

void test7() {
	printf("\nTEST ESERCIZIO 7:\n");
    const int n = 6, m = 7;
	int a[n] = {1, 2, 3, 4, 5, 6};
    int b[m] = {1, 2, 3, 7, 5, 9, 10};
    Insieme ins1 = init(a, n);
    Insieme ins2 = init(b, m);

    printf("insieme a: ");
    print(ins1);
    printf("insieme b: ");
    print(ins2);

    Insieme res = intersection(ins1, ins2);
    printf("intersezione: ");
    print(res);
}

void test8() {
	printf("\nTEST ESERCIZIO 8:\n");
    const int n = 6, m = 7;
	int a[n] = {1, 2, 3, 4, 5, 6};
    int b[m] = {1, 2, 3, 7, 5, 9, 10};
    Insieme ins1 = init(a, n);
    Insieme ins2 = init(b, m);

    printf("insieme a: ");
    print(ins1);
    printf("insieme b: ");
    print(ins2);

    Insieme res = union_(ins1, ins2);
    printf("unione: ");
    print(res);
}