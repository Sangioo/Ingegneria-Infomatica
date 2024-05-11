// Definire due variabili intere a e b, calcolare la distanza  dist in memoria tra queste variabili (tramite differenza di puntatori)
// e assegnare il valore 13 ad  a utilizzando solo il puntatore a b e dist (ovvero senza usare né a né il puntatore ad a).
#include <stdio.h>

int main() {
	int a, b, dist;
	int *pa, *pb;

	pa = &a;
	pb = &b;
	dist = pa - pb;

	*(pb+dist) = 13;

	printf("%d\n", *pa);

	return 0;
}