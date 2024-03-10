// Scrivere un programma che verifichi le modalità di rappresentazione binaria dei valori interi.
// Ad esempio dato il valore intero 0x11223344 (espresso in notazione esadecimale) verificare e stampare
// (in notazione esadecimale) byte per byte il contenuto della memoria associata a tale valore.
#include <stdio.h>

int main() {
	int a = 0x11223344;
	char *pa = (char *)&a;

	for (int i=0; i<sizeof(a); i++) {
		printf("byte numero %d: %x\n", i+1, *(pa+i));
	}

	return 0;
}