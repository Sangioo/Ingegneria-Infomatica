#include "e2B.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getData(char *riga, int* giorno, char* segno, int* valore) {
    char* tmp = strtok(riga, "|");
    *giorno = atoi(tmp);

    tmp = strtok(NULL, "|");
    *segno = *tmp;

    tmp = strtok(NULL, "|");
    *valore = atoi(tmp);
}

int getBalanceMovements(const char* fname, int min, int max, int *bal) {
    FILE* f = fopen(fname, "r");
    if (f == NULL) goto cleanup;

    int count = 0, giorno, valore;
    char riga[256], segno;
    riga[255] = '\0';

    while (fgets(riga, sizeof(riga), f) != NULL) {
        getData(riga, &giorno, &segno, &valore);

        if (min <= giorno && giorno <= max) {
            if (segno == '+') *bal += valore;
            if (segno == '-') *bal -= valore;
            count++;
        }
    }

    int res = fclose(f);
    if (res < 0) goto cleanup;
    return count;

cleanup:
    if (f != NULL) fclose(f);
    return -1;
}