#include <stdio.h>
#include <string.h>
#include <stdlib.h> // NOTE: aggiunto dopo l'esame per evitare warning nel checker
#include "e1A.h"

static unsigned tests = 0;

void slice_helper(char* str, int len, char* out)
{
    int i = 0;
    while (*str != '\0' && i <= len && len > 0) {
        if (i > len) {
            break;
        }
        out[i] = *str++;
        i++;
    }
    out[i] = '\0';
}

int test(char* inp, int start, int end, char* exp, int exp_ret)
{
    tests += 1;

    char* out = calloc(end - start + 1, sizeof(char));
    int ret = slice(inp, start, end, out);
    int outcome = strcmp(out, exp) == 0 && ret == exp_ret;

    printf("Risultato: \"%s\" (ret: %d) [atteso: \"%s\" (ret: %d))] => %s\n",
        out, ret, exp, exp_ret, outcome ? "corretto!" : "non corretto!");

    free(out);
    return outcome;
}

int main()
{
    int score = 0;

    char i0[] = "";
    char e0[] = "";
    score += test(i0, 1, 4, e0, 0);

    char i1[] = "ciao";
    char e1[] = "iao";
    score += test(i1, 1, 4, e1, 2);

    char i2[] = "troppo facile scrivere asm";
    char e2[] = "";
    score += test(i2, 0, 1, e2, 0);

    char i3[] = "troppo facile scrivere asm";
    char e3[] = "facile scrive";
    score += test(i3, 7, 20, e3, 12);

    printf("Punteggio: %d/%d\n", score, tests);
    return score;
}