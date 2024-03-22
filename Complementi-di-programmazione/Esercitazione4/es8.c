// Scrivere una funzione 
// char * mocking_spongebob(const char s[], int step);
// che, data in input una stringa s, restituisce una nuova stringa in cui uno ogni step caratteri è maiuscolo.
// Nel conteggio degli step non bisogna contare gli spazi e, se il carattere è già maiuscolo, deve rimanere invariato.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * mocking_spongebob(const char s[], int step) {
	int dim = strlen(s);
	char *out = (char *)malloc(sizeof(char)*dim + 1);
	int counter = 0;
	for (int i=0; i<dim; i++) {
		if (s[i] != ' ') {
			counter++;
		}

		if ((counter - 1) % step == 0) {
			if (97 <= s[i] && s[i] <= 122) {
				out[i] = s[i] - 32;
			} else {
				out[i] = s[i];
			}
		} else {
			out[i] = s[i];
		}
	}
	out[dim] = '\0';
	return out;
}

int main() {
	char s[] = "Non puoi insegnare TDP con i meme";
	char *stringa = mocking_spongebob(s, 2);
	for (int i=0; i<strlen(stringa); i++) printf("%c", stringa[i]);
	printf("\n");
}