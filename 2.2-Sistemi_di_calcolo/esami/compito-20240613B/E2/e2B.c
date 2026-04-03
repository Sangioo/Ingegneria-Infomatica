#include "e2B.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *p1, const void *p2) {
    return strncmp((char *)p1 + 8, (char *)p2 + 8, 3);
}

void destinazioniAcquistabili(struct connessione * list, const char * partenza, int budget, const char * filename) {
    // apro il file
    FILE* f = fopen(filename, "w");
    if (f == NULL) goto cleanup;

    // inizializzo le variabili
    int res, count = 0;
    char tmp[10][12];

    // scorro il file per selezionare le connessioni che rispettano le condizioni
    while (list != NULL) {
        if (strncmp(list->partenza, partenza, strlen(partenza)) == 0 && list->costo <= budget) {
            res = sprintf(tmp[count], "%s-%s-%d\0", list->partenza, list->destinazione, list->costo);
            if (res != 11) goto cleanup;
            count++;
        }
        list = list->next;
    }

    // ordino le connessioni trovate
    qsort(tmp, count, 12, compare);

    // scrivo le connessioni nel file
    for (int i = 0; i < count; i++) {
        res = fprintf(f, "%s\n", tmp[i]);
        if (res != 12) goto cleanup;
    }

    // chiudo il file
    res = fclose(f);
    if (res < 0) goto cleanup;

    return;
cleanup:
    perror("[ERROR]");
    if (f != NULL) fclose(f);
    return;
}