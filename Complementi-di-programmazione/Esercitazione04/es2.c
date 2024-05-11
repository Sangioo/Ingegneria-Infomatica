// Scrivere la funzione 
// double* vec_clone(const double v[], int dim);
// che, dato in ingresso un vettore v di dimensioni dim allochi e restituisca una copia del vettore v.
#include <stdio.h>
#include <stdlib.h>

double* vec_clone(const double v[], int dim) {
	double *copia = (double *) malloc(sizeof(double) * dim);

	for (int i=0; i<dim; i++) {
		copia[i] = v[i];
	}

	return copia;
}

int main() {
	double v[10] = {0,1,2,3,4,5,6,7,8,9};
	int dim = 10;

	vec_clone(v, dim);
	for (int i=0; i<dim; i++) printf("%lf ", v[i]);
	printf("\n");

	return 0;
}