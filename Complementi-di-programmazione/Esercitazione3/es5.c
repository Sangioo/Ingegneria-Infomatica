// Scrivere un programma che prenda in input da tastiera un intero N, successivamente allochi dinamicamente
// in memoria lo spazio di N interi, e ne stampi indirizzo e contenuto non inizializzato di ognuno di essi.
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, *p;

	printf("inserire N: ");
	scanf("%d", &n);

	p = (int *) malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		printf("cella %d:\tindirizzo %x - valore %d\n", i, (p + i), *(p + i));
	}
	

	free(p);
}