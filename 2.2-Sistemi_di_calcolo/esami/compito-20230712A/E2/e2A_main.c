#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>

int score, trials;

static void test(const char** s, int n, int correct) {
    trials++;
    int res = vowelcount(s, n);
    int ok = res == correct;
    printf("Test %d: %d (risultato) vs %d (atteso) => %s\n", trials, res, correct, ok ? "OK" : "errore");
    score += ok;
}

int main() {
    const char* s1[] = {"I'm tired of weakness"};
    const char* s2[] = {"I'm tired of weakness", "tired of my feet of clay", "tired of days to come", "tired of yesterday"};
    const char* s3[] = {"'m trd f wknss"};
    
    test(s1, 0, -1);
    test(s2, 1, 7);
    test(s2, 4, 27);
    test(s3, 1, 0);

    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}
