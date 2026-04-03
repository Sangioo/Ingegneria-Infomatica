#include <stdio.h>
#include "e2.h"

int score, trials;

void test(int x, int y, int ok) {
    trials++;
    int res = mcd(x, y);
    printf("Test %d: mcd(%d,%d) = %d ", trials, x, y, res);
    printf("[corretto: %d]\n", ok);
    score += res == ok;
}

int main() {
    int x, y, q, r;

    test(4,2,2);
    test(23,3,1);
    test(12,8,4);
    test(15,10,5);
    test(14,9,1);
    test(332,148,4);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
