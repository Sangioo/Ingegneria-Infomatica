#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "auxiliary.h"

/**
 * *ESERCIZIO 1:
 * Scrivere una funzione che, dati in ingresso un array vec e la sua lunghezza n, calcoli e restituisca il prodotto degli elementi di vec. (la ricorsione va eseguita sia su vec ed n).
 * @param vec[] array
 * @param n size
*/
float product(float vec[], int n) {
	if (n == 0) {
		return 1;
	} else {
		return vec[0] * product(vec+1, n-1);
	}
}

/**
 * *ESERCIZIO 2:
 * Scrivere una funzione che scrive in ogni elemento dell’array v[i] la somma di tutti gli elementi che lo precedono da 0 a i-1.
 * @param v[] array
 * @param n size
*/
void vec_integral(float* v, int n) {
	if (n == 1) {
		return;
	} else {
		v[1] += v[0];
		vec_integral(v+1, n-1);
	}
}

/**
 * *ESERCIZIO 3:
 * Scrivere una funzione che, data in ingresso una stringa, calcoli e restituisca la lunghezza della stringa.
 * @param s stringa
*/
int length(char * s) {
	if (s[0] == '\0') {
		return 0;
	} else {
		return 1 + length(s+1);
	}
}

/**
 * *ESERCIZIO 4:
 * Scrivere una funzione che, data in ingresso una stringa e un carattere, calcoli e restituisca la posizione del primo carattere ch nella stringa. Se il carattere non e' presente, la funzione deve restituire -1.
 * @param s stringa
 * @param ch carattere da cercare
*/
int char_position(char* s, char ch) {
	if (s[0] == '\0') {
		return -1;
	} else if (s[0] == ch) {
		return 0;
	} else {
		int c = char_position(s+1, ch);
		if (c >= 0) {
			return 1 + c;
		} else {
			return c;
		}
	}
}

/**
 * *ESERCIZIO 4b:
 * Scrivere una funzione che, data in ingresso una stringa e un carattere, calcoli e restituisca la posizione dell’ultimo carattere ch nella stringa. Se il carattere non e' presente, la funzione deve restituire -1.
 * @param s stringa
 * @param ch carattere da cercare
*/
int char_last_position(char* s, char ch) {
	if (s[0] == '\0') {
		return -1;
	} else {
		int i = char_last_position(s+1, ch);
		
		if (s[0] == ch && i == -1) {
			return 0;
		} else if (i != -1) {
			return 1 + i;
		} else {
			return i;
		}
	}
}

/**
 * *ESERCIZIO 5:
 * Scrivere una funzione che, data in ingresso una stringa, restituisca true se la stringa contiene solo lettere minuscole, false altrimenti.
 * @param s stringa
*/
bool is_lowercase(char *s) {
	if (s[0] == '\0') {
		return true;
	} else if ('a'<=s[0] && s[0]<='z') {
		return true && is_lowercase(s+1);
	} else {
		return false;
	}
}

/**
 * *ESERCIZIO 5b:
 * Scrivere una funzione che, data in ingresso una stringa, restituisca true se la stringa contiene almeno una lettera minuscola, false altrimenti.
 * @param s stringa
*/
bool is_any_lowercase(char *s) {
	if (s[0] == '\0') {
		return false;
	} else if ('a'<=s[0] && s[0]<='z') {
		return true || is_any_lowercase(s+1);
	} else {
		return false || is_any_lowercase(s+1);
	}
}

/**
 * *ESERCIZIO 6:
 * Scrivere la funzione che modifica la stringa in ingresso convertendo tutti i caratteri minuscoli in essa presenti nei corrispondenti caratteri maiuscoli.
 * @param s stringa
*/
void to_uppercase(char *s) {
	if (s[0] == '\0') {
		return;
	} else if ('a'<=s[0] && s[0]<='z') {
		s[0] -= 32;
		to_uppercase(s+1);
	} else {
		to_uppercase(s+1);
	}
}

/**
 * *ESERCIZIO 7:
 * Scrivere una funzione che, date in ingresso due stringhe, faccia la copia della stringa src dentro  dest. Assumere che la memoria di dest sia già stata allocata e lo spazio sia sufficiente a contenere il risultato.
 * @param dest stringa destinazione
 * @param src stringa sorgente
*/
void copy(char * dest, char * src) {
	if (src[0] == '\0') {
		return;
	} else {
		dest[0] = src[0];
		copy(dest+1, src+1);
	}
}

/**
 * *ESERCIZIO 8:
 * Scrivere una funzione che, date in ingresso due stringhe, concateni la stringa src a dest e la memorizzi in dest. Assumere che la memoria di dest sia già stata allocata e lo spazio sia sufficiente a contenere il risultato.
 * @param dest stringa destinazione
 * @param src stringa sorgente
*/
void concat(char * dest, char * src) {
	if (src[0] == '\0') {
		return;
	} else {
		dest[length(dest)] = src[0];
		concat(dest+1, src+1);
	}
}

/**
 * *ESERCIZIO 9:
 * Scrivere una funzione che dato in input una stringa con un messaggio e un puntatore a file già aperto in scrittura, scriva nel file tutti i caratteri nel messaggio compresi tra ‘a’ e ‘z’ (niente maiuscole, numeri o caratteri speciali).
 * @param message messaggio
 * @param file puntatore a file in scrittura
*/
void filter_write(char * message, FILE * file) {
	if (message[0] == '\0') {
		return;
	} else if ('a'<=message[0] && message[0]<='z') {
		fprintf(file, "%c", message[0]);
	}
	filter_write(message+1, file);
}

/**
 * *ESERCIZIO 10:
 * Scrivere una funzione che, ricevuti in input due puntatori a file già aperti in lettura, ritorni true se il contenuto dei due file è uguale.
 * @param f1 file 1
 * @param f2 file 2
*/
bool same_content(FILE *f1, FILE *f2) {
	char c1 = fgetc(f1);
	char c2 = fgetc(f2);
	printf("%c %c\n", c1, c2);
	if (c1 == EOF || c2 == EOF) {
		return true;
	} else if (c1 == c2) {
		return true && same_content(f1, f2);
	} else {
		return false;
	}
}


void test1() {
	const int n = 5;
	float v[n] = {1.0, 2.0, 3.0, 4.0, 5.0};
	float p = product(v, n);

	printf("\nTEST ESERCIZIO 1:\n");
	printf("prodotto: %f\n", p);
}

void test2() {
	const int n = 5;
	float v[n] = {1.0, 2.0, 3.0, 4.0, 5.0};
	vec_integral(v, n);

	printf("\nTEST ESERCIZIO 2:\n");
	for (int i=0; i<n; i++)
		printf("%f ", v[i]);
	printf("\n");
}

void test3() {
	char s[] = "Lorem ipsum dolor sit amet";
	int len = length(s);

	printf("\nTEST ESERCIZIO 3:\n");
	printf("stringa: '%s'\n", s);
	printf("lunghezza: %d\n", len);
}

void test4() {
	char s[] = "Lorem ipsum dolor sit amet", c = 'd';
	int index = char_position(s, c);

	printf("\nTEST ESERCIZIO 4:\n");
	printf("stringa: '%s'\n", s);
	printf("prima occorrenza di %c: %d\n", c, index);
}

void test4b() {
	char s[] = "Lorem ipsum dolor sit amet", c = 'o';
	int index = char_last_position(s, c);

	printf("\nTEST ESERCIZIO 4b:\n");
	printf("stringa: '%s'\n", s);
	printf("ultima occorrenza di %c: %d\n", c, index);
}

void test5() {
	char s[] = "loremipsumdolorsitamet";
	bool lower = is_lowercase(s);

	printf("\nTEST ESERCIZIO 5:\n");
	printf("stringa: '%s'\n", s);
	printf("lowercase: '%s'\n", (lower == 1)? "true" : "false");
}

void test5b() {
	char s[] = "Lorem ipsum dolor sit amet";
	bool lower = is_any_lowercase(s);

	printf("\nTEST ESERCIZIO 5b:\n");
	printf("stringa: '%s'\n", s);
	printf("any lowercase: %s\n", (lower == 1)? "true" : "false");
}

void test6() {
	char s[] = "Lorem ipsum dolor sit amet";

	printf("\nTEST ESERCIZIO 6:\n");
	printf("stringa: '%s'\n", s);
	to_uppercase(s);
	printf("stringa upper: '%s'\n", s);
}

void test7() {
	char s[] = "Lorem ipsum dolor sit amet";
	char *d = (char *) malloc(sizeof(char) * (length(s)+1));
	d[length(d)] = '\0';
	copy(d, s);

	printf("\nTEST ESERCIZIO 7:\n");
	printf("stringa: '%s'\n", s);
	printf("stringa copiata: '%s'\n", d);
}

void test8() {
	char d[] = "Lorem ipsum";
	char s[] = " dolor sit amet";
	char *dest = (char *) malloc(sizeof(char) * (length(s)+length(d)+1));
	for (int i=0; i<length(d); i++) {
		dest[i] = d[i];
	}
	dest[length(dest)] = '\0';

	printf("\nTEST ESERCIZIO 8:\n");
	printf("destinazione: '%s'\n", dest);
	printf("sorgente: '%s'\n", s);
	concat(dest, s);
	printf("stringa concatenata: '%s'\n", dest);
}

void test9() {
	FILE *f = fopen("output.txt", "w");
	char s[] = "Lorem ipsum dolor sit amet";

	if (f == NULL) {
		printf("ERRORE NELL'APERTURA DEL FILE\n");
		exit(1);
	}

	printf("\nTEST ESERCIZIO 9:\n");
	printf("stringa: '%s'\n", s);
	filter_write(s, f);

	int close = fclose(f);
	if (close == EOF) {
		printf("ERRORE NELLA CHIUSURA DEL FILE\n");
		exit(1);
	}
}

void test10() {
	FILE *f1 = fopen("file1.txt", "r");
	FILE *f2 = fopen("file2.txt", "r");

	if (f1 == NULL || f2 == NULL) {
		printf("ERRORE NELL'APERTURA DEI FILE\n");
		exit(1);
	}

	printf("\nTEST ESERCIZIO 9:\n");
	bool s = same_content(f1, f2);
	printf("stesso contenuto: %s\n", (s == 1)? "true" : "false");

	int close1 = fclose(f1);
	int close2 = fclose(f2);
	if (close1 == EOF || close2 == EOF) {
		printf("ERRORE NELLA CHIUSURA DEI FILE\n");
		exit(1);
	}
}