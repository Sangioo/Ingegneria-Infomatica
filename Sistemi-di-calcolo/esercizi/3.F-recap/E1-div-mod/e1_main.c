#include <stdio.h>
#include "e1.h"

int score, trials;

void test(int x, int y, int q, int r) {
    trials++;
    int qr, rr;
    div_mod(x, y, &qr, &rr);
    printf("Test %d: %d/%d = %d, %d%%%d = %d ",trials, x, y, qr, x, y, rr);
    printf("[corretto: %d/%d = %d, %d%%%d = %d]\n", x, y, r,  x, y, r);
    score += q == qr && r == rr;
}

int main() {
    int x, y, q, r;

    test(3,2,1,1);
    test(23,3,7,2);
    test(0,1,0,0);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
