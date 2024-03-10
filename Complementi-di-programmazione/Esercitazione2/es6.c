// Completare il seguente programma in modo tale da assegnare alla variabile  j il valore della variabile i
// usando solo puntatori a char e senza usare l'istruzione di assegnamento tra interi (ad es., l'istruzione j = i; è proibita).
#include <stdio.h>

int main() {
    int i = 10;
    int j = -1;
    char *p, *q;
    // Inserire codice qui (senza j = ...)
	p = (char *)&i;
	q = (char *)&j;

	for (int i=0; i<sizeof(i); i++) {
		printf("%d %d\n", *(q+i), *(p+i));
		*(q+i) = *(p+i);
	}
   
	printf("%d == %d\n", i, j);
}