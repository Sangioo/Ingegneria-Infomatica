#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "e1.h"

int score, trials;

void test(const char* s1, const char* s2, int ok){
    trials++;
    int res = is_suffix(s1, s2);
    printf("Test %d: risultato=%d [corretto=%d]\n", trials, res, ok);
    score += res == ok;
}

int main() {
    
    test("ger", "hamburger", 1);
    test("ham", "ham", 1);
    test("hamburger", "ham", 0);
    test("", "ham", 1);
    test("ham", "hummingbird", 0);
    test("ham", "", 0);
    test("m", "ham", 1);

    printf("Risultato: %d/%d\n", score, trials);
    return EXIT_SUCCESS;
}