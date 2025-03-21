#include <stdio.h>

char my_strcmp(const char* s1, const char* s2);

int score, trials;

void test(const char* s1, const char* s2, int c) {
    trials++;
    char r = my_strcmp(s1, s2);
    printf("Test %d: %d [corretto: %d]\n", trials, r, c);
    score += r == c;
}

int main() {

    test("one", "three", -5);
    test("1", "0", 1);
    test("ham", "hamburger", -98);
    test("hel", "hal", 4);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
