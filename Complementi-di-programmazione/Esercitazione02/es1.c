// Definire una variabile per ogni tipo primitivo (char, short, int, long, float, double) e stampare la dimensione in byte di ciascuna di esse.
#include <stdio.h>

int main() {
	char c;
	short s;
	int i;
	long l;
	float f;
	double d;

	printf("Dimensione in byte di c (char): %lu\n", sizeof(c));
	printf("Dimensione in byte di s (short): %lu\n", sizeof(s));
	printf("Dimensione in byte di i (int): %lu\n", sizeof(i));
	printf("Dimensione in byte di l (long): %lu\n", sizeof(l));
	printf("Dimensione in byte di f (float): %lu\n", sizeof(f));
	printf("Dimensione in byte di d (double): %lu\n", sizeof(d));

	return 0;
}