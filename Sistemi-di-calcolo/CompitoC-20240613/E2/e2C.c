#include "e2C.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *p1, const void *p2) {
    return strncmp((char *)p1 + 8, (char *)p2 + 8, 12);
}

void destinazioniSottoBudget(const char * filesorgente, const char * partenza, int budget, const char * filedestinazione) {
    FILE* fin = fopen(filesorgente, "r");
    if (fin == NULL) goto cleanup;

    FILE* fout = fopen(filedestinazione, "w");
    if (fout == NULL) goto cleanup;

    int res, count = 0;
    char riga[13], part[4], dest[4], cost[4], tmp[10][12];
    riga[12] = '\0';
    part[3] = '\0';
    dest[3] = '\0';
    cost[3] = '\0';

    while (fgets(riga, 13, fin) != NULL) {
        res = sscanf(riga, "%03c-%03c-%03c\n", part, dest, cost);
        if (res != 3) goto cleanup;

        if (strncmp(part, partenza, strlen(partenza)) == 0 && atoi(cost) <= budget) {
            res = sprintf(tmp[count], "%s-%s-%s\0", part, dest, cost);
            if (res != 11) goto cleanup;
            count++;
        }
    }

    qsort(tmp, count, 12, compare);

    for (int i = 0; i < count; i++) {
        res = fprintf(fout, "%s\n", tmp[i]);
        if (res != 12) goto cleanup;
    }

    res = fclose(fin);
    if (res < 0) goto cleanup;
    
    res = fclose(fout);
    if (res < 0) goto cleanup;

    return;
cleanup:
    perror("[ERROR]");
    if (fin != NULL) fclose(fin);
    if (fout != NULL) fclose(fout);
    return;
}