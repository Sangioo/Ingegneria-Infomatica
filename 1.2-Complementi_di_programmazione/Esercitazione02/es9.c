// Scopri il destino legato al tuo nome secondo la numerologia.
// I numeri del destino sono quelli compresi fra 1 e 9 più 11 e 22 (maggiori informazioni qui).
// Il numero del destino si ottiene sommando i codici ASCII delle lettere del nome
// e poi sommando le cifre di tale somma finché non viene un numero del destino.
// Scrivere un programma che legge uno alla volta i caratteri del nome e calcola il corrispondente numero del destino.
// Calcola il tuo numero.
#include <stdio.h>

int main() {
	char c = '*';
	int somma = 0, num = 0, cifra;
	
	printf("inserire carattere ('.' per terminare): ");
	scanf(" %c", &c);

	while(c != '.') {
		somma += c;
		printf("inserire carattere ('.' per terminare): ");
		scanf(" %c", &c);
	}

	printf("somma caratteri ASCII: %d\n", somma);

	while((num < 1 || num > 9) && num != 11 && num != 12) {
		num = 0;
		while (somma != 0) {
			cifra = somma % 10;
			somma -= cifra;
			somma /= 10;

			num += cifra;
		}
		somma = num;
	}
	printf("numero del destino: %d\n", num);

	return 0;
}