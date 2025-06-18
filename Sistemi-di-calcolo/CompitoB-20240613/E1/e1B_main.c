#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "e1B.h"

static int tests = 0;

void deleetify_helper(unsigned char chr, unsigned char* out)
{
    if (chr == '0') *out = 'o';
    else if (chr == '1') *out = 'l';
    else if (chr == '3') *out = 'e';
    else if (chr == '4') *out = 'a';
    else if (chr == '5') *out = 's';
    else if (chr == '7') *out = 't';
    else if (chr == '9') *out = 'g';
    else *out = '*';
}

int test(unsigned char* inp, unsigned len, unsigned char* expected)
{
    tests += 1;
    unsigned char* res = malloc(len+1);
    res[len] = 0;
    deleetify(inp, len, res);
    int out = !strcmp(res, expected);
    printf("Risultato: \"%s\" [atteso: \"%s\"] => %s\n", 
        res, expected, out ? "corretto!" : "non corretto!");
    free(res);
    return out;
}

int main()
{
    
    int score = 0;

    // NOTE: funziona solo con stringhe senza simboli
    score += test("", 0, "");
    score += test("1337", strlen("1337"), "leet");
    score += test("i7w0rk5", strlen("i7w0rk5"), "itworks");
    
    printf("Punteggio: %d/%d\n", score, tests);
    return score;
}