#include <stdio.h>
#include <string.h>
#include "e1A.h"

char* b64_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static int tests = 0;

void print(unsigned char* data, int len) {
    int i;
    if (data == NULL) { printf("NULL"); return; }
    for(i = 0; i < len; i++) printf("%c", data[i]);
}

int test(unsigned char* input, int len, unsigned char* expected) {
    tests += 1;
    int out_len = (8 * len) / 6;
    unsigned char* res = base64lessless(input, out_len, b64_table);
    int correct = expected && res ? memcmp(res, expected, out_len) : expected == 0 && res == 0 ? 0 : 1;
    printf("Risultato: ");
    print(res, out_len);
    printf(" [atteso: ");
    print(expected, out_len); 
    printf("] => %s\n", correct == 0 ? "corretto!" : "non corretto!");
    if (res) free(res);
    return correct == 0;
}

int main() {
    
    int score = 0;
    score += test(NULL, 0, NULL);

    char s[] = "ABC";
    score += test(s, sizeof(s) - 1, "QUJD");

    char s2[] = "ABC";
    score += test(s2, sizeof(s2), "QUJDA");

    char s3[] = "AJEJE BRAZOV";
    score += test(s3, sizeof(s3), "QUpFSkUgQlJBWk9WA");
    
    printf("Punteggio: %d/%d\n", score, tests);
    return score;
}