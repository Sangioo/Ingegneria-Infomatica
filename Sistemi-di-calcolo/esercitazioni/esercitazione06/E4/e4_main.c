#include <stdlib.h>
#include <stdio.h>

#include "e4.h"

int score, trials;

void test(int x, int y, int ok) {
    trials++;
    int res = lcm(x, y);
    printf("Test %d: lcm(%d, %d) = %d ", trials, x, y, res);
    printf("[corretto: %d]\n", ok);
    score += res == ok;
}

int main() {

    test(4, 6, 12);
    test(3, 5, 15);
    test(6, 15, 30);
    test(54, 24, 216);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}