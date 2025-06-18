#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "e1C.h"

unsigned int tests;

void hextodec_helper(unsigned char* start, int* out)
{
    char str[] = {*start, *(start + 1), 0};
    int val = strtol(str, NULL, 16);
    if (val > 128)
        val -= 256;
    *out = val;
}

int test(unsigned char* inp, int* expected, int expected_sum)
{
    tests += 1;
    int res;
    int size_out = (strlen(inp) / 2) * sizeof(int);
    int *out = malloc(size_out);

    res = hextodec_sum(inp, out);

    int outcome = 1 && expected_sum == res;

    for (int i = 0; i < size_out / sizeof(int); i++) {
        if (expected[i] != out[i]) {
            outcome = 0;
            break;
        }
    }


    printf("Risultato: %d ( ", res);
    for (int i = 0; i < size_out / sizeof(int); i++) {
        printf("%d ", out[i]);
    }
    printf(") [atteso: %d ( ", expected_sum);
    for (int i = 0; i < size_out / sizeof(int); i++) {
        printf("%d ", expected[i]);
    }
    printf("))] => %s\n", outcome ? "corretto!" : "non corretto!");

    free(out);
    return outcome;
}
int main()
{
    
    int score = 0;

    int exp_0[] = {10, 10};
    unsigned char inp_0[] = "0A0A";
    score += test(inp_0, exp_0, 20);

    int exp_1[] = {120, -20, 3};
    unsigned char inp_1[] = "78EC03";
    score += test(inp_1, exp_1, 123);

    int exp_2[] = {-1, -1, -1};
    unsigned char inp_2[] = "FFFFFF";
    score += test(inp_2, exp_2, 0);
    
    printf("Punteggio: %d/%d\n", score, tests);
    return score;
}