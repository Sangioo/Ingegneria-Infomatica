// Scrivere la funzione 
// char* select_chars(const char s[], const int idxs[], int dim);
// simile alla funzione precedente, ma invece di stampare a schermo, essa restituisce una stringa composta dai caratteri corrispondenti agli indici.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* select_chars(const char s[], const int idxs[], int dim) {
	int len = strlen(s);
	int dimensione = 0;
	for (int i=0; i<dim; i++) {
		if (idxs[i] < len && idxs >= 0) {
			dimensione++;
		}
	}
	
	char *output = (char *) malloc(dimensione * sizeof(char) + 1);

	int j = 0;
	for (int i=0; i<dim; i++) {
		if (idxs[i] < len && idxs >= 0) {
			output[j] = s[idxs[i]];
			j++;
		}
	}
	output[dimensione] = '\0';
	return output;
}

int main() {
	int idxs[] = {1,8,3,5,0,21,888,44,2,7};
	char s[] = "HelloWorld!";

	char *out = select_chars(s, idxs, 10);
	int dim = strlen(out);
	for (int i=0; i<dim; i++) printf("%c ", out[i]);
	printf("\n");
}