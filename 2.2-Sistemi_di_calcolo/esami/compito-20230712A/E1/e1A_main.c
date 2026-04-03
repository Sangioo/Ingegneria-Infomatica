#include <stdio.h>
#include "e1A.h"

static int tests = 0;

int test(unsigned char* data, int n, int expected) {
    tests += 1;
    int res = adler32(data, n);
    printf("Risultato: %x [atteso: %x] => %s\n", res, expected, res == expected ? "corretto!" : "non corretto!");
    return res == expected;
}

int main() {
    
    int score = 0;

    score += test(NULL, 0, 0);

    unsigned char d1[] = { 1 };
    unsigned l1 = sizeof(d1);
    score += test(d1, l1, 0x20002);

    unsigned char d2[] = { 1, 2, 3, 4 };
    unsigned l2 = sizeof(d2);
    score += test(d2, l2, 0x18000b);
    
    printf("Punteggio: %d/%d\n", score, tests);
    return score;
}