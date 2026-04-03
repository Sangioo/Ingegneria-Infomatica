#include <stdio.h>

int count(const char *s1);

int score, trials;

void test(char* s, int c) {
    trials++;
    int r = count(s);
    printf("Test %d: %d [corretto: %d]\n", trials, r, c);
    score += r == c;
}

int main() {

    test("", 0);
    test("one", 3);
    test("bazinga bazinga bazinga!", 24);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}