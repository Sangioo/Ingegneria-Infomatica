// Completare il seguente programma in modo tale da assegnare alla variabile  c il valore dell'espressione a + b utilizzando i puntatori pa, pb e pc.
// Non e' consentito usare ne' assegnazioni dirette alla variabile c né operazioni aritmetiche dirette sulle variabili a e b.
#include <stdio.h>

int main() {
    int a = 10;
    int b = -1;
    int c;
    int *pa, *pb, *pc;
    // Assegnare i puntatori (da completare)
    pa = &a;
    pb = &b;
    pc = &c;
    // Inserire codice qui (che contenga solo pa, pb, pc)
	*pc = *pa + *pb;
	printf("%d == a + b\n", c);
}