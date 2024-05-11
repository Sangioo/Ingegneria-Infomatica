// Scrivere un programma che inserita una sequenza di interi positivi in input ne restituisca il minimo usando solamente
// variabili di tipo puntatore ad int, anziché variabili di tipo int. La sequenza di input termina quando viene inserito il numero 0 (escluso).
// Tutta la memoria utilizzata deve essere allocata dinamicamente (malloc), e quando non più utilizzata deve essere rilasciata.
// Nota bene: il programma deve controllare che la sequenza inserita sia costituita da numeri
// interi positivi.
#include <stdio.h>
#include <stdlib.h>

int main() {
	int *p = (int *) malloc(sizeof(int));
	int *somma = (int *) malloc(sizeof(int));

	do {
		printf("inserire numero intero positivo: ");
		scanf("%d", p);

		if (*p < 0) {
			printf("valore non valido\n");
		} else {
			*somma += *p;
		}
	} while (*p != 0);

	printf("\nsomma dei numeri inseriti: %d\n", *somma);

	free(p);
	free(somma);

	return 0;
}