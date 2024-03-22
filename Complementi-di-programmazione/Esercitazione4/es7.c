// Scrivere la funzione 
// char* invert_string(const char s[]);
// che, data in input una stringa s restituisca in output la stringa s con i caratteri invertiti (scambiando il primo carattere con l’ultimo e così via).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* invert_string(const char s[]) {
	int dim = strlen(s);
	char *stringa = (char *) malloc(sizeof(char) * dim);
	for (int i=0; i<dim; i++) {
		stringa[i] = s[dim-i-1];
	}
	return stringa;
}

int main() {
	char s[] = "abcdefghijklmnopqrstuvwxyz";
	char *stringa = invert_string(s);
	for (int i=0; i<strlen(stringa); i++) printf("%c ", stringa[i]);
	printf("\n");
}