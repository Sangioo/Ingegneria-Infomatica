#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int score, trials;

static void test(int num, const char * filename) {
    trials++;
    char ** list;
    int ret = loadStringsFromFile(filename, &list);
    int ok = (ret == num);
    printf("Test %d: %s\n", trials, ok ? "OK" : "errore");
    score += ok;
}

int main() {
    test(9, "input1.txt");
    test(2, "input2.txt");
    test(16, "input3.txt");
    test(0, "input4.txt");
    test(0, "input5.txt");

    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}

