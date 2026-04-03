#include <stdio.h>
#include "e2.h"

// la funzione sort_strings(v,n) ordina usando qsort un array v di 
// n stringhe

int main() {

    int i;
    char* v[] = { "Foxtrot", "Delta", "Hotel", "Charlie", "Bravo", "Golf", "Alfa", "Echo" };
    
    for (i=0; i<8; ++i) printf("%s ", v[i]);
    printf("\n");

    sort_strings(v, 8);

    for (i=0; i<8; ++i) printf("%s ", v[i]);
    printf("\n");

    return 0;
}
