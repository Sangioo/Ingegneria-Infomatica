#include <stdio.h>
#include <string.h>

int count_substrings(const char* s, const char* sub);

int score, trials;

void test(char *s, const char *sub, int c) {
    trials++;
    int r = count_substrings(s, sub);
    printf("Test %d: count \"%s\" in \"%s\" - %d [corretto: %d]\n", trials, sub, s, r, c);
    score += r == c;
}

int main() {

    test("aaaaaaaaaa", "a", 10);
    test("aaaaaaaaaa", "aa", 9);
    test("oneoneoneone",  "neon", 3);
    test("", "up", 0);
    test("", "",1);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
