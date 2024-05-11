// Scrivere la funzione
// char** capitalizer_strings(const char* s[], int len);
// che, dati in input un array di stringhe s e il suo numero di elementi len,
// restituisca un nuovo array di stringhe dove tutte le stringhe di  s sono state trasformate secondo la funzione  capitalizer descritta nell’esercizio 4.9.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** capitalizer_strings(const char* s[], int len) {
	if (len == 0) return NULL;
	
	char** output = (char **)malloc(sizeof(char*)*len);

	for (int i=0; i<len; i++) {
		int dim = strlen(s[i]);
		output[i] = (char *)malloc(sizeof(char)*dim + 1);

		for (int j=0; j<dim; j++) {
			if (j == 0 || (s[i][j-1] == ' ' && 97 <= s[i][j] && s[i][j] <= 122)) {
				output[i][j] = s[i][j] - 32;
			} else {
				output[i][j] = s[i][j];
			}
		}
		output[i][dim] = '\0';
	}
	return output;
}

int main() {
	const char **s;
	s[0] = "abcd efgh";
	s[1] = "ijkl mnop";
	s[2] = "qrst uvwx";

	char **out = capitalizer_strings(s, 3);
	for (int i=0; i<3; i++) {
		for (int j=0; j<strlen(out[i]); j++) printf("%c", out[i][j]);
		printf("\n");
	}
}