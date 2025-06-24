#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* clone(const void* src, int n);

int score, trials;

void test(char* src, int len) {
    trials++;
    char* res = (char*)clone(src, len);
    if (len > 0) {
        printf("Test %d: \"%s\" [corretto: \"%s\"]\n\n", trials, res, src);
        score += strcmp(res, src)==0;
        free(res);
    } else {
        printf("Test %d: gestione errore malloc %s\n\n", trials, res == 0 ? "corretta" : "errata");
        score += res == 0;
    }
}

int main() {

    char* s1 = "Fuit igitur causa capiendi novi consili...";
    char* s2 = "All those moments will be lost in time, like tears in rain.";
    char* s3 = "Anything in life that’s any fun is either immoral, illegal or fattening.";

    test(s1, strlen(s1)+1);
    test(s2, strlen(s2)+1);
    test(s3, strlen(s3)+1);
    test("", -1);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
