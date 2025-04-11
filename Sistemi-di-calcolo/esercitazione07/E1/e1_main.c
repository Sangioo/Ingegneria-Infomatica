#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "e1.h"


int score, trials;

void test(int *v, int n, int x, int ok){
    trials++;

    int res = binsearch(v, n, x);

    printf("Test %d: risultato=%d [corretto=%d]\n", trials, res, ok);

    score += res == ok;
}

int main() {

    int v0[] = {};
    int v1[] = {2};
    int v2[] = {2, 4, 4, 6, 8, 9, 12, 14, 17, 21};

    test(v0, sizeof(v0)/sizeof(int), 3, 0);
    test(v1, sizeof(v1)/sizeof(int), 3, 0);
    test(v1, sizeof(v1)/sizeof(int), 2, 1);
    test(v2, sizeof(v2)/sizeof(int), 1, 0);
    test(v2, sizeof(v2)/sizeof(int), 17, 1);
    test(v2, sizeof(v2)/sizeof(int), 22, 0);

    printf("Risultato: %d/%d\n", score, trials);
    return 0;
}
