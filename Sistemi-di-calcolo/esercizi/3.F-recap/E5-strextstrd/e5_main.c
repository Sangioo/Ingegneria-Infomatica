#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "e5.h"


int score, trials;

void test(const char *s, int stride,  const char *ok){
    trials++;

    char* res = strextstrd(s, stride);

    printf("Test %d: risultato=%s [corretto=%s]\n", trials, res, ok);

    score += strcmp(res,ok) == 0;
}

int main() {
    test("ciao", 1, "ciao");
    test("ciao", 2, "ca");
    test("Where Eagles Dare", 5, "W er");

    printf("Risultato: %d/%d\n", score, trials);
    return 0;
}


