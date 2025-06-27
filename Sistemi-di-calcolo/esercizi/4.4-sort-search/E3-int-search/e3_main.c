#include <stdio.h>
#include "e3.h"

// la funzione search_int(v,n,x) cerca x in un array
// v di n interi usando la funzione bsearch

int main() {

    int res, i, v[] = { 20, 12, 3, 15, 17, 51, 43, 9 };
    
    for (i=0; i<8; ++i) printf("%d ", v[i]);
    printf("\n");

    printf("Esito: %d [OK=1]\n", search_int(v, 8, 3));
    printf("Esito: %d [OK=0]\n", search_int(v, 8, 19));
    printf("Esito: %d [OK=1]\n", search_int(v, 8, 43));
    printf("Esito: %d [OK=1]\n", search_int(v, 8, 15));
    printf("Esito: %d [OK=0]\n", search_int(v, 8, 52));

    return 0;
}
