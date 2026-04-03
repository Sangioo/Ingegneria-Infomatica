#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "auxiliary.h"

void rimuovi_minimo_aux(TipoAlbero *a, int min) {
    if (*a == NULL) {
        return;
    }
    if ((*a)->info == min) {
        delAlbero(a);
        *a = NULL;
        return;
    }
    rimuovi_minimo_aux(&((*a)->sinistro), min);
    rimuovi_minimo_aux(&((*a)->destro), min);
}
void rimuovi_minimo(TipoAlbero *a) {
    int min = minimo(*a);
    rimuovi_minimo_aux(a, min);
}

void test1() {
    printf("\nTEST ESERCIZIO 1:\n");
    char *s = "albero.txt";
    TipoAlbero a = initAlbero(s);

    printf("albero: ");
    stampaParentetica(a);
    printf("\n");
    
    rimuovi_minimo(&a);
    printf("albero modificato: ");
    stampaParentetica(a);
    printf("\n");
}

void test2() {
    printf("\nTEST ESERCIZIO 2:\n");
    
}

void test3() {
    printf("\nTEST ESERCIZIO 3:\n");
    
}

void test4() {
    printf("\nTEST ESERCIZIO 4:\n");
    
}

void test5() {
    printf("\nTEST ESERCIZIO 5:\n");
    
}

void test6() {
    printf("\nTEST ESERCIZIO 6:\n");
    
}

void test7() {
	printf("\nTEST ESERCIZIO 7:\n");
    
}

void test8() {
	printf("\nTEST ESERCIZIO 8:\n");

}

void test9() {
	printf("\nTEST ESERCIZIO 9:\n");
    
}

void test10() {
	printf("\nTEST ESERCIZIO 10:\n");
    
}

void test11() {
	printf("\nTEST ESERCIZIO 11:\n");
    
}

void test12() {
	printf("\nTEST ESERCIZIO 12:\n");
    
}