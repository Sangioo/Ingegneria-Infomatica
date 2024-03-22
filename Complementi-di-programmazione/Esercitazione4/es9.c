// Scrivere la funzione 
// char* capitalizer(const char s[]);
// che, dati in input una stringa s , costruisca e restituisca in output una nuova stringa in cui il primo carattere
// di ciascuna parola nella stringa di partenza è stato reso maiuscolo.
// Tutti gli altri caratteri devono essere resi minuscoli.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* capitalizer(const char s[]) {
	int dim = strlen(s);
	char *stringa = (char *)malloc(sizeof(char)*dim + 1);

	for (int i=0; i<dim; i++) {
		if (i == 0 || (s[i-1] == ' ' && 97 <= s[i] && s[i] <= 122)) {
			stringa[i] = s[i] - 32;
		} else {
			stringa[i] = s[i];
		}
	}
	stringa[dim] = '\0';
	return stringa;
}

int main() {
	char s[] = "non puoi insegnare TDP con i meme";
	char *stringa = capitalizer(s);
	for (int i=0; i<strlen(stringa); i++) printf("%c", stringa[i]);
	printf("\n");
}