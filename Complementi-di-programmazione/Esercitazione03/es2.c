// Ripetere il precedente esercizio usando un'unica chiamata della funzione malloc.
// Suggerimento: allocare la memoria per due interi adiacenti.
#include <stdio.h>
#include <stdlib.h>

int main() {
	int *p = (int *) malloc(sizeof(int)*2);

	do {
		printf("inserire numero intero positivo: ");
		scanf("%d", p);

		if (*p < 0) {
			printf("valore non valido\n");
		} else {
			*(p + 1) += *p;
		}
	} while (*p != 0);

	printf("\nsomma dei numeri inseriti: %d\n", *(p + 1));

	free(p);

	return 0;
}