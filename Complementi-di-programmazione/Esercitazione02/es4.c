// Scrivere un programma che calcoli il numero più grande possibile che una variabile di tipo int e una di tipo long possono immagazzinare.
// N.B: ricorda che il tipi long e int comprendono il segno.
// A) Risolvere l’esercizio usando la libreria <limits.h>
// B) Calcolare il risultato aritmeticamente, senza usare la libreria <limits.h>, usando la funzione sizeof
#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {
	int i;
	long l;

	printf("Versione A:\n");
	printf("Numero massimo int: %d\n", INT_MAX);
	printf("Numero massimo long: %ld\n\n", LONG_MAX);

	printf("Versione B:\n");
	i = (int)(pow(2, sizeof(i)*8 - 1) - 1);
	printf("Numero massimo int: %d\n", i);
	
	l = (long int)(pow(2, sizeof(l)*8 - 1) - 1);
	printf("NUmero massimo long: %ld\n", l);

	return 0;
}