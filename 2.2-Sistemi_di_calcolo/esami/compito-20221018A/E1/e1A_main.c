#include <stdio.h>
#include "e1A.h"

int test(const char* a, const char* expected) {
    char* res = str_to_upper(a);
    printf("s=%s", a ? a : "NULL");
    printf(" risultato=%s (atteso: %s)", res ? res : "NULL", expected ? expected : "NULL");
    int r;
    if (expected == NULL && res == NULL)
        r = 0;
    else if (expected == NULL || res == NULL)
        r = 1;
    else
        r = strcmp(res, expected);
    printf(" => %s\n", r == 0 ? "corretto!" : "non corretto!");
    if (res) free(res);
    return r == 0;
}

int main() {
    int score = 0;
    score += test(NULL, NULL);
    score += test("ABC", "ABC");
    score += test("abc", "ABC");
    printf("Punteggio: %d/%d\n", score, 3);
    return 0;
}