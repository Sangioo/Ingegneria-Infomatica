// Scrivere la funzione
// char** split_string(const char* s, char sep);
// che, data in input una stringa s e un carattere sep, divida la stringa in sottostringhe usando sep come carattere di separazione e ritorni un array con le sottostringhe risultanti.
// Il carattere sep non deve comparire nelle sottostringhe in output.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split_string(const char* s, char sep) {
	int len = strlen(s);
	int dim = 1;
	for (int i=0; i<len; i++) {
		if (s[i] == sep) {
			dim++;
		}
	}

	char **output = (char **)malloc(sizeof(char*)*dim);
	int first = 0;
	int indice = 0;
	for (int i=0; i<len; i++) {
		if (s[i] == sep) {
			output[indice] = (char *)malloc(sizeof(char)*(i-first) + 1);

			for (int j=first; j<i; j++) {
				output[indice][j-first] = s[j];
			}
			output[indice][i-first] = '\0';
			indice++;
			first = i+1;
		} else if (i == len-1) {
			output[indice] = (char *)malloc(sizeof(char)*(i-first+1) + 1);

			for (int j=first; j<=i; j++) {
				output[indice][j-first] = s[j];
			}
			output[indice][i-first+1] = '\0';
		}
	}

	return output;
}

int main() {
	char *s = "abcd efgh ijkl mnop qrst uvwx";

	char **out = split_string(s, ' ');
	for (int i=0; i<6; i++) {
		for (int j=0; j<strlen(out[i]); j++) printf("%c", out[i][j]);
		printf("\n");
	}
}