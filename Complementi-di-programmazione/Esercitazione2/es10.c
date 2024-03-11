// Dati due interi i, j il cui valore letto da tastiera, si calcoli il risultato della divisione k = i/j di tipo double. 
// In seguito, si iteri sui primi decimali di k (massimo 10), ciascuno a distanza p rispetto alla virgola (la prima
// cifra decimale starà a distanza 0 dalla virgola), e si stampi il carattere alfanumerico associato in ASCII dopo aver
// aggiunto il corrispondente valore p. 

// Esempio:
// Dati i seguenti valori di i,j,k:

// int i=2
// int j=3;
// double k=i/j;  // = 0.6666666

// Il risultato sara’:
// ‘6’
// ‘7’
// ‘8’
// ‘9’
// ‘:’
// ‘;’
// ‘<’
// ‘=’
// ‘>’
// ‘?’
#include <stdio.h>

int main() {
	int i, j, intero, cifra;
	double k;
	char c;

	printf("inserire i: ");
	scanf("%d", &i);

	printf("inserire j: ");
	scanf("%d", &j);

	k = (double)i / (double)j;

	intero = k;
	k = k - (double)intero;

	for (i = 0; i < 10; i++) {
		k = k * 10;
		cifra = (int)k % 10;
		k = k - cifra;

		c = cifra + i + 48;
		printf("posizione %d - cifra: %d - carattere: %c\n", i, cifra, c);
	}

	return 0;
}