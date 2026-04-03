#include <stdio.h>
#include "e1.h"

// la funzione sort_ins(v,n) ordina usando qsort un array v di 
// n interi

int main() {

    int i, v[] = { 20, 12, 3, 15, 17, 51, 43, 9 };
    
    for (i=0; i<8; ++i) printf("%d ", v[i]);
    printf("\n");

    sort_ints(v, 8);

    for (i=0; i<8; ++i) printf("%d ", v[i]);
    printf("\n");

    return 0;
}
