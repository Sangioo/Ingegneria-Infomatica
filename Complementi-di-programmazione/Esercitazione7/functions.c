#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "auxiliary.h"

/**
 * *ESERCIZIO 1:
 * Implementare la funzione che calcola la lunghezza struttura collegata scl.
 * @param scl struttura collegata lineare input
*/
int scl_len(TipoSCL scl) {
	if(scl == NULL) {
		return 0;
	} else {
		return 1 + scl_len(scl->next);
	}
}

/**
 * *ESERCIZIO 2:
 * Implementare la funzione che calcola la somma degli elementi contenuti nella lista scl.
 * @param scl struttura collegata lineare input
*/
float scl_sum(TipoSCL scl) {
	if (scl == NULL) {
		return 0;
	} else {
		return scl->info + scl_sum(scl->next);
	}
}

/**
 * *ESERCIZIO 3:
 * Implementare la funzione che restituisce il valore medio degli elementi della lista. L’esercizio deve essere svolto senza l’ausilio delle precedenti due funzioni.
 * @param scl struttura collegata lineare input
*/
// float scl_media(TipoSCL scl) {}

/**
 * *ESERCIZIO 4:
 * Implementare la funzione che ritorna il prodotto scalare, risultato della moltiplicazione degli elementi delle due liste.
 * @param scl1 struttura collegata lineare numero 1
 * @param scl1 struttura collegata lineare numero 2
*/
float scl_dot(TipoSCL scl1, TipoSCL scl2) {
	if (scl1 == NULL || scl2 == NULL) {
		return 1;
	} else {
		return scl1->info * scl2->info * scl_dot(scl1->next, scl2->next);
	}
}

/**
 * *ESERCIZIO 5:
 * Scrivere una funzione che modifichi la SCL in input duplicando l’elemento in posizione pos (si inserisca un nuovo nodo nella posizione successiva).
 * @param scl struttura collegata lineare input
 * @param pos posizione
*/
void scl_duplicate_pos(TipoSCL scl, int pos) {
	if (pos == 0) {
		addSCL(&scl->next, scl->info);
	} else {
		scl_duplicate_pos(scl->next, pos-1);
	}
}

/**
 * *ESERCIZIO 6:
 * Scrivere una funzione che modifichi la SCL ris contenente solo gli elementi con valori maggiori o uguali di zero di scl.
 * @param scl struttura collegata lineare input
 * @param ris struttura collegata lineare da modificare
*/
void scl_positives(TipoSCL scl, TipoSCL *ris) {
	if (scl == NULL) {
		return;
	}
}

/**
 * *ESERCIZIO 6b:
 * Scrivere una funzione che restituisca una nuova SCL contenente solo gli elementi con valori maggiori o uguali di zero di scl.
 * @param scl struttura collegata lineare input
*/
// TipoSCL scl_positives_(TipoSCL scl);

/**
 * *ESERCIZIO 7:
 * Scrivere la funzione che data in input la struttura s, ne stampi a schermo tutti i caratteri. Una SCL vuota corrisponderà alla stringa vuota "".
 * @param s struttura collegata lineare input
*/
// void sclstring_print(TipoSCL s);

/**
 * *ESERCIZIO 8:
 * Scrivere una funzione che data in input una stringa, generi una struttura SCL che la rappresenti.
 * @param s stringa input
 * @param ris struttura collegata lineare output
*/
// void sclstring_create(const char *s, TipoSCL *ris);

/**
 * *ESERCIZIO 8b:
 * Scrivere una funzione che data in input una stringa, ritorni una struttura SCL che la rappresenti.
 * @param s stringa input
*/
// TipoSCL sclstring_create_(const char *s);

/**
 * *ESERCIZIO 9:
 * Scrivere una funzione che restituisca true se e solo se la stringa rappresentata da scl è uguale a s.
 * @param scl struttura collegata lineare input
 * @param s stringa input
*/
// bool sclstring_equals(TipoSCL scl, const char *s);

/**
 * *ESERCIZIO 10:
 * Scrivere una funzione che modifichi la struttura puntata da scl_p, eliminando tutti gli elementi con valore uguale a val. Se val non è presente, non va fatta alcuna modifica.
 * @param scl_p puntatore a struttura collegata lineare input
 * @param val carattere da matchare
*/
// void sclstring_remove(TipoSCL *scl_p, char val);


void test1() {
	TipoSCL scl = initSCL(10, 10);

	printf("\nTEST ESERCIZIO 1:\n");
	writeSCL(scl);
	printf("lunghezza: %d\n", scl_len(scl));
}

void test2() {
	TipoSCL scl = initSCL(10, 10);

	printf("\nTEST ESERCIZIO 2:\n");
	writeSCL(scl);
	printf("somma elementi: %f\n", scl_sum(scl));
}

void test3() {
	
}

void test4() {
	TipoSCL scl1 = initSCL(2, 10);

	TipoSCL scl2 = initSCL(3, 10);

	printf("\nTEST ESERCIZIO 4:\n");
	writeSCL(scl1);
	writeSCL(scl2);
	printf("somma elementi: %f\n", scl_dot(scl1, scl2));
}

void test5() {
	TipoSCL scl = initSCL_rand(10, 0, 100);

	printf("\nTEST ESERCIZIO 5:\n");
	writeSCL(scl);
	scl_duplicate_pos(scl, 5);
	writeSCL(scl);
}

void test6() {
	
}

void test6b() {
	
}

void test7() {
	
}

void test8() {
	
}

void test8b() {

}

void test9() {
	
}

void test10() {
	
}