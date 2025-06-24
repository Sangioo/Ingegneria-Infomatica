#include <stdio.h>
#include <string.h>
#include "e3.h"

int score, trials;

void test(char* s1, char* s2) {
    trials++;
    printf("Test %d: res=%s [corretto=%s]\n", trials, my_strpbrk(s1, s2), strpbrk(s1, s2));
    score += my_strpbrk(s1, s2)==strpbrk(s1, s2);
}

int main() {

    test("Once again, this is a test" , "ftir");
    test("Once again, this is a test" , ":#F");

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
