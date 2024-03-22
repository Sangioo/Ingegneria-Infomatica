// Scrivere la funzione
// char** split_string(const char* s, char sep);
// che, data in input una stringa s e un carattere sep, divida la stringa in sottostringhe usando sep come carattere di separazione e ritorni un array con le sottostringhe risultanti.
// Il carattere sep non deve comparire nelle sottostringhe in output.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split_string(const char* s, char sep) {
	int len = strlen(s);
	int dim = len;
	for (int i=0; i<len; i++) {
		if (s[i] == sep) {
			dim--;
		}
	}

	char *output = (char *)malloc(sizeof(char)*dim + 1);

	for (int i=0; i<len; i++) {
		
	}
}

int main() {
	
}