#include "e1A.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static unsigned tests = 0;

unsigned average(unsigned sum, int n)
{
    return sum / n;
}

int test(unsigned* array, unsigned len, unsigned* exp, unsigned exp_sum)
{
    tests += 1;

    unsigned* out = calloc(len, sizeof(unsigned));
    unsigned sum = transform(array, len, out);
    
    int outcome = 1;

    printf("Test %d: [ ", tests - 1);

    for (int i = 0; i < len; i++) {
        printf("%d ", out[i]);
        if (out[i] != exp[i]) {
            outcome = 0;
        }
    }

    printf("] (expected: [ ");
    for (int i = 0; i < len; i++) {
        printf("%d ", exp[i]);
    }
    printf("]); ret = %d (expected = %d)\n", sum, exp_sum);
    
    outcome &= sum == exp_sum;

    free(out);
    return outcome;
}

int main()
{
    int score = 0;

    unsigned i0[] = {0, 1, 1, 3, 4};
    unsigned e0[] = {0, 1, 1, 3, 1};
    score += test(i0, 5, e0, 9);

    unsigned i1[] = {0, 0, 0, 0, 0};
    unsigned e1[] = {0, 0, 0, 0, 0};
    score += test(i1, 5, e1, 0);

    unsigned i2[] = {10, 1, 2, 6, 12, 15, 9};
    unsigned e2[] = {10, 5, 3, 3, 3, 5, 6};
    score += test(i2, 7, e2, 55);

    unsigned i3[] = {1};
    unsigned e3[] = {1};
    score += test(i3, 1, e3, 1);

    printf("Punteggio: %d/%d\n", score, tests);
    return score;
}