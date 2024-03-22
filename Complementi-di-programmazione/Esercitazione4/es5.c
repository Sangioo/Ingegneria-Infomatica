// Scrivere la funzione
// void print_chars(const char s[], const int idxs[], int dim);
// che, data in input la stringa s e un array di indici idxs con la sua dimensione dim , stampi a schermo i caratteri nella stringa corrispondenti agli indici.
// (Nota: se un valore di idxs non è nel range corretto, esso va ignorato).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_chars(const char s[], const int idxs[], int dim) {
	int len = strlen(s);
	for (int i=0; i<dim; i++) {
		if (idxs[i] < len && idxs >= 0) {
			printf("%c", s[idxs[i]]);
		}
	}
	printf("\n");
	return;
}

int main() {
	int idxs[] = {1,8,3,5,0,21,888,44,2,7};
	char s[] = "HelloWorld!";

	print_chars(s, idxs, 10);
}