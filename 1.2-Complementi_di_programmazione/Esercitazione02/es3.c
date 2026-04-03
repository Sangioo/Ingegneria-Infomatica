// Scrivere un programma che stampi il set dei caratteri ASCII da 32 a 127, con la struttura: "carattere" ; "codice carattere"
// N.b. : alcuni caratteri speciali potrebbero non venire stampati.
#include <stdio.h>

int main() {
	unsigned char c;

	for (c = 32; c < 128; c++) {
		printf("%c ; %d\n", c, c);
	}

	return 0;
}