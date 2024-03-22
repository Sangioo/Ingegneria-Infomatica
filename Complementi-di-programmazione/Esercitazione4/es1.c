// Scrivere una funzione
// void random_array(int v[], int dim, int max_value)
// che dato in input un array v di dimensione dim, e un valore intero massimo max_value, popoli l’array con valori casuali compresi tra zero e max_value (escluso).
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_array(int v[], int dim, int max_value) {
	srand(time(NULL));

	for (int i=0; i<dim; i++) {
		v[i] = rand() % (max_value + 1);
	}

	return;
}

int main() {
	int v[10] = {0,1,2,3,4,5,6,7,8,9};
	int dim = 10, max_value = 9;

	random_array(v, dim, max_value);
	for (int i=0; i<dim; i++) printf("%d ", v[i]);
	printf("\n");
	
	return 0;
}