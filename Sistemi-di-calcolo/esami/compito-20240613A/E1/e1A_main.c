#include <stdio.h>
#include <string.h>
#include "e1A.h"

static int tests = 0;

unsigned char deleetify_helper(unsigned char chr)
{
    if (chr == '0') return 'o';
    if (chr == '1') return 'l';
    if (chr == '3') return 'e';
    if (chr == '4') return 'a';
    if (chr == '5') return 's';
    if (chr == '7') return 't';
    if (chr == '9') return 'g';
    return '*';
}

int test(unsigned char* inp, unsigned len, unsigned char* expected)
{
    tests += 1;
    unsigned char* res;
    res = deleetify(inp, len);
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