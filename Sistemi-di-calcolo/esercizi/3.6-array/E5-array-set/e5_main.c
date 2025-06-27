#include <stdio.h>
#include <stdlib.h>

void array_set(short* v, int n, short c);

int main() {

    short a[] = { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(a) / sizeof(short);

    short c = 0xCAFE;
    array_set(a, n, 0xCAFE);

    int i, error = 0;
    for (i = 0; i < n; i++) {
        if (a[i] != c) {
            printf("ERRORE: cella %d non settata correttamente (%d vs %d)\n", i, a[i], c);
            error = 1;
        }
    }
    if (!error)
        printf("Corretto!\n");

    return 0;
}
