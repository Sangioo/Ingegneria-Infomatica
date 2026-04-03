#include <stdio.h>
#include <stdlib.h>
#include "e1A.h"

static unsigned tests = 0;

char compute(char x, char* out) {
    *out = -x;
}

int test(char* inp_1, unsigned* inp_2, int len, char* exp)
{
    tests += 1;
    char *out = malloc(len * sizeof(char));
    cond_compute(inp_1, inp_2, len, out);

    int outcome = 1;

    for (int i = 0; i < len; i++) {
        if (exp[i] != out[i]) {
            outcome = 0;
            break;
        }
    }

    printf("Risultato: ( ");
    for (int i = 0; i < len; i++) {
        printf("%d ", out[i]);
    }
    printf(") [atteso: ( ");
    for (int i = 0; i < len; i++) {
        printf("%d ", exp[i]);
    }
    printf("))] => %s\n", outcome ? "corretto!" : "non corretto!");

    free(out);
    return outcome;
}

int main()
{
    int score = 0;

    char inp_01[] = {10, 5};
    unsigned inp_02[] = {0, 0};
    char exp_0[] = {10, 5};
    score += test(inp_01, inp_02, 2, exp_0);

    char inp_11[] = {5, 10};
    unsigned inp_12[] = {1, 1};
    char exp_1[] = {-5, -10};
    score += test(inp_11, inp_12, 2, exp_1);
    
    char inp_21[] = {10, -20, 5};
    unsigned inp_22[] = {0, 1, 0};
    char exp_2[] = {10, 20, 5};
    score += test(inp_21, inp_22, 3, exp_2);

    char inp_31[] = {42, 13, 27, 98, 5};
    unsigned inp_32[] = {0, 1, 0, 1, 0};
    char exp_3[] = {42, -13, 27, -98, 5};
    score += test(inp_31, inp_32, 5, exp_3);

    printf("Punteggio: %d/%d\n", score, tests);
    return score;
}