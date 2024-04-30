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
	if (isemptySCL(scl)) {
		return 0;
	} else {
		return 1 + scl_len(restoSCL(scl));
	}
}

/**
 * *ESERCIZIO 2:
 * Implementare la funzione che calcola la somma degli elementi contenuti nella lista scl.
 * @param scl struttura collegata lineare input
*/
float scl_sum(TipoSCL scl) {
	if (isemptySCL(scl)) {
		return 0;
	} else {
		return primoSCL(scl) + scl_sum(restoSCL(scl));
	}
}


/**
 * *ESERCIZIO 3:
 * Implementare la funzione che restituisce il valore medio degli elementi della lista. L’esercizio deve essere svolto senza l’ausilio delle precedenti due funzioni.
 * @param scl struttura collegata lineare input
*/
float scl_avg(TipoSCL scl, int *n) {
    if (isemptySCL(scl)) {
        return 0;
    } else if (*n == 0) {
        *n += 1;
        float avg = primoSCL(scl) + scl_avg(restoSCL(scl), n);
        return avg / *n;
    } else {
        *n += 1;
        return primoSCL(scl) + scl_avg(restoSCL(scl), n);
    }
}

float scl_media(TipoSCL scl) {
	int n = 0;
	return scl_avg(scl, &n);
}

/**
 * *ESERCIZIO 4:
 * Implementare la funzione che ritorna il prodotto scalare, risultato della moltiplicazione degli elementi delle due liste.
 * @param scl1 struttura collegata lineare numero 1
 * @param scl1 struttura collegata lineare numero 2
*/
float scl_dot(TipoSCL scl1, TipoSCL scl2) {
	if (isemptySCL(scl1) || isemptySCL(scl2)) {
		return 1;
	} else {
		return primoSCL(scl1) * primoSCL(scl2) + scl_dot(restoSCL(scl1), restoSCL(scl2));
	}
}

/**
 * *ESERCIZIO 5:
 * Scrivere una funzione che modifichi la SCL in input duplicando l’elemento in posizione pos (si inserisca un nuovo nodo nella posizione successiva).
 * @param scl struttura collegata lineare input
 * @param pos posizione
*/
TipoSCL scl_duplicate_pos(TipoSCL scl, int pos) {
	if (pos == 0) {
		return addSCL(scl, primoSCL(scl));
	} else {
		return addSCL(scl_duplicate_pos(restoSCL(scl), pos-1), primoSCL(scl));
	}
}

/**
 * *ESERCIZIO 6:
 * Scrivere una funzione che modifichi la SCL ris contenente solo gli elementi con valori maggiori o uguali di zero di scl.
 * @param scl struttura collegata lineare input
*/
TipoSCL scl_positives(TipoSCL scl) {
	if (isemptySCL(scl)) {
		return NULL;
	} else if (primoSCL(scl) >= 0) {
		return addSCL(scl_positives(restoSCL(scl)), primoSCL(scl));
	} else {
		return scl_positives(restoSCL(scl));
	}
}

/**
 * *ESERCIZIO 7:
 * Scrivere la funzione che data in input la struttura s, ne stampi a schermo tutti i caratteri. Una SCL vuota corrisponderà alla stringa vuota "".
 * @param s struttura collegata lineare input
*/
void sclstring_print(TipoSCLC s) {
	if (isemptySCLC(s)) {
		printf("\n");
	} else {
		printf("%c", primoSCLC(s));
		sclstring_print(restoSCLC(s));
	}
}

/**
 * *ESERCIZIO 8:
 * Scrivere una funzione che data in input una stringa, generi una struttura SCL che la rappresenti.
 * @param s stringa input
*/
TipoSCLC sclstring_create(const char *s) {
	if (*s == '\0') {
		return NULL;
	} else {
		TipoInfoSCLC c = *s;
		return addSCLC(sclstring_create(s+1), c);
	}
}

/**
 * *ESERCIZIO 9:
 * Scrivere una funzione che restituisca true se e solo se la stringa rappresentata da scl è uguale a s.
 * @param scl struttura collegata lineare input
 * @param s stringa input
*/
bool sclstring_equals(TipoSCLC scl, const char *s) {
	if (*s == '\0' && isemptySCLC(scl)) {
		return true;
	} else if (*s == '\0' || isemptySCLC(scl)) {
		return false;
	} else if (*s == primoSCLC(scl)) {
		return true && sclstring_equals(restoSCLC(scl), s+1);
	} else {
		return false;
	}
}

/**
 * *ESERCIZIO 10:
 * Scrivere una funzione che modifichi la struttura puntata da scl, eliminando tutti gli elementi con valore uguale a val. Se val non è presente, non va fatta alcuna modifica.
 * @param scl struttura collegata lineare in input
 * @param val carattere da matchare
*/
TipoSCLC sclstring_remove(TipoSCLC scl, char val) {
	if (isemptySCLC(scl)) {
		return NULL;
	} else if (primoSCLC(scl) == val) {
		return sclstring_remove(restoSCLC(scl), val);
	} else {
		return addSCLC(sclstring_remove(restoSCLC(scl), val), primoSCLC(scl));
	}
}


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
	TipoSCL scl = initSCL_rand(10, 0, 10);

	printf("\nTEST ESERCIZIO 3:\n");
	writeSCL(scl);
	printf("media elementi: %f\n", scl_media(scl));
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
	TipoSCL ris = scl_duplicate_pos(scl, 5);
	writeSCL(ris);
}

void test6() {
	TipoSCL scl = initSCL_rand(10, -100, 100);
	TipoSCL ris = scl_positives(scl);

	printf("\nTEST ESERCIZIO 6:\n");
	writeSCL(scl);
	writeSCL(ris);
}

void test7() {
	char s[] = "Lorem ipsum dolor sit amet";
	TipoSCLC scl = sclstring_create(s);

	printf("\nTEST ESERCIZIO 7:\n");
	sclstring_print(scl);
}

void test8() {
	char s[] = "Lorem ipsum dolor sit amet";
	TipoSCLC scl = sclstring_create(s);

	printf("\nTEST ESERCIZIO 8:\n");
	sclstring_print(scl);
}

void test9() {
	char s[] = "Lorem ipsum dolor sit amet";
	char check[] = "Lorem ipsum dolor sit amet";
	TipoSCLC scl = sclstring_create(s);

	printf("\nTEST ESERCIZIO 9:\n");
	printf("SCL: ");
	sclstring_print(scl);
	printf("stringa: %s\n", check);
	printf("uguali: %s\n", (sclstring_equals(scl, check)) ? "true" : "false");
}

void test10() {
	char s[] = "oLorem ipsum dolor sit ameto";
	char c = 'o';
	TipoSCLC scl = sclstring_create(s);
	TipoSCLC ris = sclstring_remove(scl, c);

	printf("\nTEST ESERCIZIO 10:\n");
	printf("stringa: ");
	sclstring_print(scl);
	printf("carattere: %c\n", c);
	printf("risultato: ");
	sclstring_print(ris);
}
