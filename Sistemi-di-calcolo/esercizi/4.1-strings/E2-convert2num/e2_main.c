#include <stdio.h>
#include <stdlib.h>
#include "e2.h"

// la funzione f deve convertire tutti i numeri in formato stringa
// nei corrispondenti numeri in complemento a due

int main() {
    int i;
    char *in[] = { "10ciao", "15uno22", "-17", "ciao", "  11" };
    int out[5];
    f(in, out, 5);
    for (i=0; i<5; i++)
        printf("%d -> orig: \"%s\" | conv: %d\n", i, in[i], out[i]);
    return 0;
}
