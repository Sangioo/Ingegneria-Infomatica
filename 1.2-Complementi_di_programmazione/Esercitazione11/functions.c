#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "auxiliary.h"

/**
 * *ESERCIZIO 0:
 * Implementare il tipo astratto albero binario utilizzando la rappresentazione indicizzata generale (vedi sezione 12.4 della dispensa).
 * Suggerimento: memorizzare anche l’indice dell’array associato ad ogni nodo.
*/


/**
 * *ESERCIZIO 1:
 * Implementare la funzione che, dato un albero binario, restituisca il valore massimo contenuto nei nodi dell'albero. Se l’albero è vuoto, si ritorni -1.
*/
TipoInfoAlbero trova_massimo_aux(TipoAlbero a) {
    if (estVuoto(a))
        return 0;
    
    int max_sx = trova_massimo_aux(sinistro(a));
    int max_dx = trova_massimo_aux(destro(a));

    if (radice(a) > max_dx) {
        if (radice(a) > max_sx)
            return radice(a);
        else
            return max_sx;
    } else {
        if (max_dx > max_sx)
            return max_dx;
        else
            return max_sx;
    }
}
/**
 * *ESERCIZIO 1:
 * Implementare la funzione che, dato un albero binario, restituisca il valore massimo contenuto nei nodi dell'albero. Se l’albero è vuoto, si ritorni -1.
*/
TipoInfoAlbero trova_massimo(TipoAlbero a) {
    if (estVuoto(a)) return -1;

    return trova_massimo_aux(a);
}


/**
 * *ESERCIZIO 2:
 * Implementare la funzione che, dato un albero binario, restituisca la somma di tutti i valori contenuti nei nodi foglia.
*/
TipoInfoAlbero somma_foglie(TipoAlbero a) {
    if (estVuoto(sinistro(a)) && estVuoto(destro(a))) {
        return radice(a);
    }
    int fsum_sx = somma_foglie(sinistro(a));
    int fsum_dx = somma_foglie(destro(a));
    return fsum_dx + fsum_sx;
}


/**
 * *ESERCIZIO 3:
 * Implementare la funzione che, dati un albero binario a e un valore v, restituisca il livello dell’albero dove si trova v.
 * Se v non e’ presente all’interno dell’albero ritornare -1. Se sono presenti più nodi con lo stesso valore, si restituisca il livello del nodo più a sinistra.
*/
int cerca_livello(TipoAlbero a, TipoInfoAlbero v) {
    if (estVuoto(a)) {
        return -1;
    }
    if (radice(a) == v) {
        return 0;
    }

    int sx = cerca_livello(sinistro(a), v);
    if (sx != -1) {
        return 1 + sx;
    }

    int dx = cerca_livello(destro(a), v);
    if (dx != -1) {
        return 1 + dx;
    }

    return -1;
}


/**
 * *ESERCIZIO 4:
 * Implementare la funzione che, dato un albero binario, restituisca il numero di nodi che soddisfano la seguente condizione: la somma tra il valore del nodo e i suoi figli è dispari.
*/
int conta_dispari(TipoAlbero a) {
    if (isFoglia(a)) {
        return 0;
    }
    int x = radice(a) + radice(sinistro(a)) + radice(destro(a));
    if (x%2 == 1) {
        return 1 + conta_dispari(sinistro(a)) + conta_dispari(destro(a));
    } else {
        return conta_dispari(sinistro(a)) + conta_dispari(destro(a));
    }
}


/**
 * *ESERCIZIO 5:
 * Implementare la seguente funzione che, dato in input un albero binario, restituisca la somma dei valori dei nodi che hanno un solo successore.
*/
int somma_singoli(TipoAlbero a) {
    if (estVuoto(a)) {
        return 0;
    }
    if (!estVuoto(sinistro(a)) && estVuoto(destro(a))) {
        return radice(a) + somma_singoli(sinistro(a));
    }
    if (estVuoto(sinistro(a)) && !estVuoto(destro(a))) {
        return radice(a) + somma_singoli(destro(a));
    }
    return somma_singoli(sinistro(a)) + somma_singoli(destro(a));
}


/**
 * *ESERCIZIO 6:
 * Implementare la seguente funzione che, dato un albero binario di ricerca, restituisca la lista dei valori ordinati, in modo decrescente.
*/
TipoLista albero_lista(TipoAlbero a) {
    if (estVuoto(a)) {
        return NULL;
    }
    TipoLista scl_sx = albero_lista(sinistro(a));
    TipoLista scl_dx = albero_lista(destro(a));
    addSCL(&scl_sx, radice(a));
    fondi(scl_dx, &scl_sx);
    return scl_sx;
}


/**
 * *ESERCIZIO 7:
 * Implementare la seguente funzione che, dato un albero binario, restituisca la lista dei nodi contenuti nel percorso più lungo dalla radice a una delle foglie.
 * Se esistono diversi percorsi di dimensione massima, si restituisca quello più a sinistra.
*/
TipoLista percorso_lungo(TipoAlbero a) {
    if (estVuoto(a)) {
        return NULL;
    }
    TipoLista sx = percorso_lungo(sinistro(a));
    TipoLista dx = percorso_lungo(destro(a));

    if (length(sx) >= length(dx)) {
        addSCL(&sx, radice(a));
        return sx;
    } else {
        addSCL(&dx, radice(a));
        return dx;
    }
}


/**
 * *ESERCIZIO 8:
 * Implementare la funzione che modifica il valore di ogni nodo dell’albero a, scrivendo come valore la somma dei valori dei sottoalberi di quel nodo.
*/
void somma_sottoalbero(TipoAlbero a) {
    if (estVuoto(a) || isFoglia(a)) {
        return;
    }
    somma_sottoalbero(sinistro(a));
    somma_sottoalbero(destro(a));
    int sx = (estVuoto(sinistro(a))) ? 0 : radice(sinistro(a));
    int dx = (estVuoto(destro(a))) ? 0 : radice(destro(a));
    assegnaRadice(a, sx+dx);
}


/**
 * *ESERCIZIO 9:
 * Implementare la funzione che scambia il contenuto di tutte le coppie di foglie che hanno lo stesso padre.
*/
void scambia_foglie(TipoAlbero a) {
    if (estVuoto(a) || isFoglia(a)) {
        return;
    }
    if (!estVuoto(sinistro(a)) && !estVuoto(destro(a)) && isFoglia(sinistro(a)) && isFoglia(destro(a))) {
        int temp = radice(sinistro(a));
        assegnaRadice(sinistro(a), radice(destro(a)));
        assegnaRadice(destro(a), temp);
    }
    scambia_foglie(sinistro(a));
    scambia_foglie(destro(a));
}


/**
 * *ESERCIZIO 10:
 * Implementare la funzione che modifica il valore di ogni nodo dell’albero a al livello livello, scrivendo come valore il massimo tra i valori dei figli di quel nodo.
*/
void max_figli_livello(TipoAlbero a, int livello) {
    if (estVuoto(a)) {
        return;
    }
    if (livello == 0) {
        if (isFoglia(a)) return;

        int sx = (estVuoto(sinistro(a))) ? 0 : radice(sinistro(a));
        int dx = (estVuoto(destro(a))) ? 0 : radice(destro(a));
        assegnaRadice(a, (sx > dx) ? sx : dx);
    }
    max_figli_livello(sinistro(a), livello-1);
    max_figli_livello(destro(a), livello-1);
}


/**
 * *ESERCIZIO 11:
 * Implementare la funzione che scambia il contenuto di tutte le coppie di foglie che hanno lo stesso padre e si trovano al livello livello.
*/
void scambia_foglie_livello(TipoAlbero a, int livello) {
    if (estVuoto(a)) {
        return;
    }
    if (livello == 0) {
        if (!isFoglia(sinistro(a)) || !isFoglia(destro(a))) return;

        int temp = radice(sinistro(a));
        assegnaRadice(sinistro(a), radice(destro(a)));
        assegnaRadice(destro(a), temp);
    }
    scambia_foglie_livello(sinistro(a), livello-1);
    scambia_foglie_livello(destro(a), livello-1);
}


/**
 * *ESERCIZIO 12:
 * Implementare la seguente funzione che dato un albero a e una lista l di dimensioni pari al numero di nodi dell’albero contenente valori ordinati,
 * modifichi il contenuto dell’albero a in modo che esso diventi un albero binario di ricerca con i valori contenuti in l.
*/
TipoAlbero set_albero(TipoLista l, int start, int end) {
    if (start < end) {
        int med = (start + end) / 2;

        TipoAlbero sx = set_albero(l, med+1, end);
        TipoAlbero dx = set_albero(l, start, med-1);
        return creaAlbBin(index(l, med), sx, dx);
    }
    return creaAlbBin(index(l, start), NULL, NULL);
}
/**
 * *ESERCIZIO 12:
 * Implementare la seguente funzione che dato un albero a e una lista l di dimensioni pari al numero di nodi dell’albero contenente valori ordinati,
 * modifichi il contenuto dell’albero a in modo che esso diventi un albero binario di ricerca con i valori contenuti in l.
*/
void set_albbinric(TipoAlbero *a, TipoLista l) {
    int len = length(l);
    *a = set_albero(l, 0, len-1);
}

void test0() {
    printf("\nTEST ESERCIZIO 0:\n");
    
}

void test1() {
    printf("\nTEST ESERCIZIO 1:\n");
    char *s = "albero.txt";
    TipoAlbero a = initAlbero(s);

    printf("albero: ");
    stampaParentetica(a);

    printf("\nmassimo: %d\n", trova_massimo(a));
}

void test2() {
    printf("\nTEST ESERCIZIO 2:\n");
    char *s = "albero.txt";
    TipoAlbero a = initAlbero(s);

    printf("albero: ");
    stampaParentetica(a);

    printf("\nsomma delle foglie: %d\n", somma_foglie(a));
}

void test3() {
    printf("\nTEST ESERCIZIO 3:\n");
    char *s = "albero.txt";
    int v = 3;
    TipoAlbero a = initAlbero(s);

    printf("albero: ");
    stampaParentetica(a);

    printf("\nlivello di %d: %d\n", v, cerca_livello(a, v));
}

void test4() {
    printf("\nTEST ESERCIZIO 4:\n");
    char *s = "albero.txt";
    TipoAlbero a = initAlbero(s);

    printf("albero: ");
    stampaParentetica(a);

    printf("\ncalcolo: %d\n", conta_dispari(a));
}

void test5() {
    printf("\nTEST ESERCIZIO 5:\n");
    char *s = "albero.txt";
    TipoAlbero a = initAlbero(s);

    printf("albero: ");
    stampaParentetica(a);

    printf("\nsomma nodi con un solo successore: %d\n", somma_singoli(a));
}

void test6() {
    printf("\nTEST ESERCIZIO 6:\n");
    char *s = "albero.txt";
    TipoAlbero a = initAlbero(s);

    printf("albero: ");
    stampaParentetica(a);

    TipoLista scl = albero_lista(a);
    printf("\nlista: ");
    writeSCL(scl);
}

void test7() {
	printf("\nTEST ESERCIZIO 7:\n");
    char *s = "albero.txt";
    TipoAlbero a = initAlbero(s);

    printf("albero: ");
    stampaParentetica(a);

    TipoLista scl = percorso_lungo(a);
    printf("\nlista piu' lunga: ");
    writeSCL(scl);
}

void test8() {
	printf("\nTEST ESERCIZIO 8:\n");
    char *s = "albero.txt";
    TipoAlbero a = initAlbero(s);

    printf("albero: ");
    stampaParentetica(a);

    somma_sottoalbero(a);
    printf("\nalbero modificato: ");
    stampaParentetica(a);
    printf("\n");
}

void test9() {
	printf("\nTEST ESERCIZIO 9:\n");
    char *s = "albero.txt";
    TipoAlbero a = initAlbero(s);

    printf("albero: ");
    stampaParentetica(a);

    scambia_foglie(a);
    printf("\nalbero modificato: ");
    stampaParentetica(a);
    printf("\n");
}

void test10() {
	printf("\nTEST ESERCIZIO 10:\n");
    char *s = "albero.txt";
    TipoAlbero a = initAlbero(s);
    int level = 1;

    printf("albero: ");
    stampaParentetica(a);

    max_figli_livello(a, level);
    printf("\nalbero modificato al livello %d: ", level);
    stampaParentetica(a);
    printf("\n");
}

void test11() {
	printf("\nTEST ESERCIZIO 11:\n");
    char *s = "albero.txt";
    TipoAlbero a = initAlbero(s);
    int level = 1;

    printf("albero: ");
    stampaParentetica(a);

    scambia_foglie_livello(a, level);
    printf("\nalbero modificato al livello %d: ", level);
    stampaParentetica(a);
    printf("\n");
}

void test12() {
	printf("\nTEST ESERCIZIO 12:\n");
    const int n = 7;
    int arr[n] = {1,3,4,5,6,8,9};
    TipoLista scl = NULL;
    TipoAlbero a = albBinVuoto();

    for (int i=0; i<n; i++) {
        addSCL(&scl, arr[i]);
    }

    printf("lista: ");
    writeSCL(scl);

    printf("albero: ");
    set_albbinric(&a, scl);
    stampaParentetica(a);
    printf("\n");
}