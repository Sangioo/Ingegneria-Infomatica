// Scrivere la funzione 
// void vec_scale(double v[], int dim, double scale)
// che dato in ingresso un vettore v di dimensione dim , modifichi v scalando le sue componenti di un fattore scale.
// Per “scalare” si intende moltiplicare tutte le sue componenti del valore scale.
#include <stdio.h>
#include <stdlib.h>

void vec_scale(double v[], int dim, double scale) {
	for (int i=0; i<dim; i++) {
		v[i] *= scale;
	}
	return;
}

int main() {
	double v[10] = {0,1,2,3,4,5,6,7,8,9};
	int dim = 10;
	double scale = 5.0;

	vec_scale(v, dim, scale);
	for (int i=0; i<dim; i++) printf("%lf ", v[i]);
	printf("\n");

	return 0;
}