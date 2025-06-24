#include <stdio.h>
#include "e1.h"

int score, trials;

void test(int x, int y, int ok) {
    trials++;
    int res = max(x, y);
    printf("Test %d: max(%d,%d) = %d ", trials, x, y, res);
    printf("[corretto: %d]\n", ok);
    score += res == ok;
}

int main() {
    int x, y, q, r;

    test(4,2,4);
    test(23,3,23);
    test(3,8,8);
    test(-15,-10,-10);
    test(1,9,9);
    test(248, 332, 332);
    test(5, 5, 5);
    test(-25, 5, 5);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
