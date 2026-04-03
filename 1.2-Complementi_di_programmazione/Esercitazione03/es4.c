// Ripetere il precedente esercizio usando un'unica chiamata della funzione malloc.
#include <stdio.h>
#include <stdlib.h>

int main() {
	double *p = (double *) malloc(sizeof(double) + sizeof(char));
	char *c = (char *)(p + 1);

	printf("inserire un valore di temperatura: ");
	scanf(" %lf", p);

	printf("inserire una unita' di misura: ");
	scanf(" %c", c);

	if (*c == 'C') {
		printf("temperatura in Celsius: %lf\n", *p);
		printf("temperatura in Kelvin: %lf\n", *p + 273.15);
		printf("temperatura in Fahrenheit: %lf\n", (*p * 1.8) + 32);
	} else if (*c == 'K') {
		printf("temperatura in Celsius: %lf\n", *p - 273.15);
		printf("temperatura in Kelvin: %lf\n", *p);
		printf("temperatura in Fahrenheit: %lf\n", ((*p - 273.15) * 1.8) + 32);
	} else if (*c == 'F') {
		printf("temperatura in Celsius: %lf\n", (*p - 32) * 5/9);
		printf("temperatura in Kelvin: %lf\n", (*p - 32) * 5/9 + 273.15);
		printf("temperatura in Fahrenheit: %lf\n", *p);
	}

	free(p);
}