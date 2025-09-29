#include "e2B.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int score = 0;
int trials = 0;

int areArraysIdentical(int arr1[], int size1, int arr2[], int size2) {
    if (size1 != size2) {
        return 0;
    }

    for (int i = 0; i < size1; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }

    return 1;
}

char* formatArrays(const int studentLens[], int studentLensSize, const int correctLens[], int correctLensSize) {
    int bufferSize = 100 + (studentLensSize + correctLensSize) * 12;
    char* result = malloc(bufferSize);
    if (result == NULL) {
        return NULL;
    }

    result[0] = '\0';

    strcat(result, "output: ");
    for (int i = 0; i < studentLensSize; i++) {
        char num[12];
        snprintf(num, sizeof(num), "%d ", studentLens[i]);
        strcat(result, num);
    }

    strcat(result, "atteso: ");
    for (int i = 0; i < correctLensSize; i++) {
        char num[12];
        snprintf(num, sizeof(num), "%d ", correctLens[i]);
        strcat(result, num);
    }

    return result;
}

static void test(const char* filename, int correctParNum, int* correctParLens) {
    trials++;

    int paragraphsNum = 0;
    int *paragraphsLens = NULL;

    frasePiuLungaPerParagrafo(filename, &paragraphsNum, &paragraphsLens);

    int ok = areArraysIdentical(paragraphsLens, paragraphsNum, correctParLens, correctParNum);
	//printf("Test %d: \"%d\" [atteso: \"%d\"] => %s\n", trials, maxFrasi, correctMaxNumeroFrasi, ok ? "OK" : "errore");
	printf("Test %d: %s\n", trials, ok ? "OK" : "errore");

    // char* s = formatArrays(paragraphsLens, paragraphsNum, correctParLens, correctParNum);
    // printf("%s\n", s);

    free(paragraphsLens);

    score += ok;
}

int main() {
    int solution1[] = { 117, 70 };
    test("lipsum1.txt", sizeof(solution1)/sizeof(int), solution1);
    
    int solution2[] = { 68, 79, 113, 115 };
    test("lipsum2.txt", sizeof(solution2)/sizeof(int), solution2);
    
    int solution3[] = { 68 };
    test("lipsum3.txt", sizeof(solution3)/sizeof(int), solution3);

    int solution4[] = { 70, 68, 68 };
    test("lipsum4.txt", sizeof(solution4)/sizeof(int), solution4);
    
    int solution5[] = { 71, 68, 65, 61, 67, 64 };
    test("lipsum5.txt", sizeof(solution5)/sizeof(int), solution5);
    
    int solution6[] = { 12 };
    test("lipsum6.txt", sizeof(solution6)/sizeof(int), solution6);

    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}
