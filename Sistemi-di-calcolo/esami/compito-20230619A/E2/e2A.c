#include "e2A.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void getData(char* riga, char* cognome, char* nome, char* voto) {
    char* tmp = riga;
    int len = 0;
    while (*tmp != '\0' && *tmp != '-') {
        tmp++;
        len++;
    }
    strncpy(cognome, riga, len);
    cognome[len] = '\0';

    char* tmp2 = ++tmp;
    len = 0;
    while (*tmp2 != '\0' && *tmp2 != '-') {
        tmp2++;
        len++;
    }
    strncpy(nome, tmp, len);
    nome[len] = '\0';

    char* tmp3 = ++tmp2;
    len = 0;
    while (*tmp3 != '\0' && *tmp3 != '\n') {
        tmp3++;
        len++;
    }
    strncpy(voto, tmp2, len);
    voto[len] = '\0';
}

int examStats(const char* fname, int * min, int * max, float * avg) {
    FILE* f = fopen(fname, "r");
    if (f == NULL) goto cleanup;

    char riga[258], cognome[256], nome[256], voto[256];
    riga[257] = '\0';
    int somma = 0, count = 0;

    while (fgets(riga, sizeof(riga), f) != NULL) {
        getData(riga, cognome, nome, voto);
        int v = atoi(voto);
        if (v >= 18) {
            if (count == 0) {
                *min = v;
                *max = v;
            }
            if (v > *max) *max = v;
            if (v < *min) *min = v;
            somma += v;
            count++;
        }
    }

    if (count != 0) {
        *avg = (float) somma / (float) count;
    } else {
        *avg = 0.0;
    }

    fclose(f);
    return count;
cleanup:
    if (f != NULL) fclose(f);
    return -1;
}