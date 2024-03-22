// Scrivere una funzione
// int * numeri_unici(const int array[], int dim, int *output_dim);
// che, dato un input un array di interi lungo dim, ritorni un nuovo array che non contiene ripetizioni (solo la prima occorrenza di ogni numero va mantenuta).
// La lunghezza dell’array ritornato deve essere salvata nell’intero puntato da output_dim.
#include <stdio.h>
#include <stdlib.h>

int* numeri_unici(const int array[], int dim, int *output_dim) {
	int counter;
	for (int i=0; i<dim; i++) {
		counter = 0;
		for (int j=0; j<i; j++) {
			if (array[j] == array[i]) {
				counter++;
			}
		}

		if (counter == 0) {
			*output_dim = *output_dim + 1;
		}
	}

	int *output_array = (int *) malloc(*output_dim * sizeof(int));

	int indice = 0;
	for (int i=0; i<dim; i++) {
		counter = 0;
		for (int j=0; j<i; j++) {
			if (array[j] == array[i]) {
				counter++;
			}
		}

		if (counter == 0) {
			output_array[indice] = array[i];
			indice++;
		}
	}

	return output_array;
}

int main() {
	int v[10] = {3,1,2,3,4,4,6,3,8,9};
	int dim = 10, output_dim = 0, *output;

	output = numeri_unici(v, dim, &output_dim);
	for (int i=0; i<output_dim; i++) printf("%d ", output[i]);
	printf("\n");

	return 0;
}