#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>

int score, trials;

static void test(const char** s, int n, int correct) {
    trials++;
    int res = countMinWords(s, n);
    int ok = res == correct;
    printf("Test %d: %s\n", trials, ok ? "OK" : "errore");
    score += ok;
}

int main() {
    const char* s1[] = {};
    const char* s2[] = {"I'm tired of weakness"};
    const char* s3[] = {"I'm tired of weakness", "tired of my feet of clay"};
    const char* s4[] = {"I'm tired of weakness", "tired of my feet of clay", "tired of yesterday", "tired of days to come"};
    const char* s5[] = {"", ""};
    test(s1, 0, -1);
    test(s2, 1, 4);
    test(s3, 2, 4);
    test(s4, 4, 3);
    test(s5, 2, 0);

    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}
