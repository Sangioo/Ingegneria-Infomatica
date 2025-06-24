#include <stdio.h>
#include <string.h>

char *my_strcat(char *dest, const char *src);

int score, trials;

void test(char *x, const char *s, const char *c) {
    trials++;
    char* r = my_strcat(x, s);
    printf("Test %d: \"%s\" [corretto: \"%s\"] - return: %p [corretto: %p]\n", trials, x, c, r, x);
    score += strcmp(x,c) == 0 && r == x;
}

int main() {

    char s1[] = "hello\0----------------";
    char s2[] = "ham\0------------------";
    char s3[] = "\0---------------------";
    char s4[] = "computing \0-----------";

    test(s1, " world", "hello world");
    test(s2, "burger", "hamburger");
    test(s3, "", "");
    test(s4, "systems", "computing systems");

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
