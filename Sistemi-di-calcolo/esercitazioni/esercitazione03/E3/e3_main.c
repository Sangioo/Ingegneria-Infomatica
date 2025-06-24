#include <stdio.h>
#include <stdlib.h>

int comp(const void*, const void*);

int main() {

    int i, sorted = 1;
    int v[] = { 21,7,23,17,17,61,9,12,6,34,25 };
    int n = sizeof(v)/sizeof(int);
    qsort(v, n, sizeof(int), comp);
    for (i=0; i<n; ++i) {
        printf("%d ", v[i]);
        if (i>0 && v[i-1]>v[i]) sorted = 0;
    }

    printf("\nRisultato: %d/1\n", sorted);

    return 0;
}

