#include <stdio.h>
#include <string.h>

char *my_strcpy(char *dest, const char *src);

int score, trials;

void test(char *x, const char *c) {
    trials++;
    char* r = my_strcpy(x, c);
    printf("Test %d: \"%s\" [corretto: \"%s\"] - return: %p [corretto: %p]\n", trials, x, c, r, x);
    score += strcmp(x,c) == 0 && r == x;
}

int main() {

    char s1[] = "----------------------";
    char s2[] = "----------------------";
    char s3[] = "----------------------";
    char s4[] = "----------------------";
    s1[5] = s2[3] = s3[2] = s4[0] = 0;

    test(s1, "hello world");
    test(s2, "hamburger");
    test(s3, "");
    test(s4, "computing systems");

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
