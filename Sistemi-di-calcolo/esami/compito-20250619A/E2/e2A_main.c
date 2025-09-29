#include "e2A.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int score = 0;
int trials = 0;

static void test(const char* filename, int correctMaxNumeroFrasi) {
    trials++;

    int ok = 0;
    int maxFrasi = 0;

    numeroFrasiMaxParagrafi(filename, &maxFrasi);
    // printf("File: %s, Max frasi: %d\n", filename, maxFrasi);

    ok = maxFrasi == correctMaxNumeroFrasi;
	printf("Test %d: \"%d\" [atteso: \"%d\"] => %s\n", trials, maxFrasi, correctMaxNumeroFrasi, ok ? "OK" : "errore");

    score += ok;
}

int main() {
    test("lipsum1.txt", 19);
    test("lipsum2.txt", 16);
    test("lipsum3.txt", 31);
    test("lipsum4.txt", 15);
    test("lipsum5.txt", 10);
    test("lipsum6.txt", 1);

    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}
