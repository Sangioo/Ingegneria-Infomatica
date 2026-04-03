#include <stdio.h>

#include "e5.h"

int score, trials;

void test(int i, int e) {
    trials++;
    int r = f(i, 5);
    printf("Test %d: %d [corretto: %d]\n", trials, r, e);
    score += r == e;
}

int main() {

    test(5, 20);
    test(10, 30);
    test(20, 50);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}