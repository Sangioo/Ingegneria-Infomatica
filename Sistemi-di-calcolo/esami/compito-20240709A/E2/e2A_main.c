#include "e2A.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*** NON MODIFICARE PER NESSUNO MOTIVO IL CODICE CHE SEGUE ***/


int score, trials;

static void test(const char* filename, const char* prefix, const struct contatto *arrayCorrect, const int numCorrect) {
    trials++;
    struct contatto *result;
    int numResult = cerca(filename, prefix, &result);
    int ok = 1;
    if (numCorrect == numResult) {
        for (int i = 0; i < numResult; i++) {
            if (strcmp(arrayCorrect[i].nomecompleto, result[i].nomecompleto) != 0 || strcmp(arrayCorrect[i].numero, result[i].numero) != 0) {
                ok = 0; 
                break;
            }
        }
    }
    else {
        ok = 0;
    }
    free(result);
    printf("Test %d: %s\n", trials, ok ? "OK" : "errore");
    score += ok;
}

int main() {
    struct contatto ris1[1] = {{"Mario Rossi", "+393297854258"}};
    struct contatto ris2[2] = {{"Mario Rossi", "+393297854258"}, {"Martina Bianchini", "+398452158"}};
    struct contatto ris4[6] = {{"Mario Rossi", "+393297854258"}, {"Elisa Verdi", "+398569574"}, {"Massimo Cielesti", "0015065284785"}, {"Martina Bianchini", "+398452158"}, {"Giovanni Bizantini", "3859647851"}, {"Francesco Massimo Ernesti Piodu", "00390872897551"}};
    struct contatto ris5[1] = {{"Francesco Massimo Ernesti Piodu", "00390872897551"}};

    test("contatti1.txt","Mario", ris1, 1);
    test("contatti1.txt","Mar", ris2, 2);
    test("contatti1.txt","Leo", NULL, 0);
    test("contatti1.txt","", ris4, 6);
    test("contatti1.txt","Francesco", ris5, 1);

    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;    
}
