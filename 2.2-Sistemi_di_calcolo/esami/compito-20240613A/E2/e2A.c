#include "e2A.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void destinazioniDisponibili(const char * filename, const char *partenza, int budget, struct destinazione ** list) {
    // apro il file in lettura
    FILE* f = fopen(filename, "r");
    if (f == NULL) goto cleanup;

    // definisco le variabili necessarie
    char riga[13], start[4], end[4], cost[4];
    int costo, res;
    struct destinazione *head = NULL, *tail = NULL;
    riga[12] = '\0';
    start[3] = '\0';
    end[3] = '\0';
    cost[3] = '\0';

    // ciclo sulle righe del file
    while(fgets(riga, 13, f) != NULL) {
        // carico le informazioni nelle stringhe e converto il costo in intero
        res = sscanf(riga, "%03c-%03c-%03c", start, end, cost);
        if (res != 3) goto cleanup;
        
        costo = atoi(cost);

        // se la partenza non e' quella desiderata vado avanti
        if (strncmp(start, partenza, strlen(start)) != 0) continue;

        // se il costo e' minore o uguale al budget aggiungo un nodo alla lista
        if (costo <= budget) {
            struct destinazione *dest = (struct destinazione *) malloc(sizeof(struct destinazione));
            if (dest == NULL) goto cleanup;

            dest->costo = costo;
            strncpy(dest->destinazione, end, strlen(end)+1);
            dest->next = NULL;

            if (head == NULL) {
                head = dest;
                tail = dest;
            } else {
                tail->next = dest;
                tail = dest;
            }
        }
    }

    // posiziono *list alla testa della lista
    *list = head;

    // chiudo il file
    res = fclose(f);
    if (res < 0) goto cleanup;

    return;

cleanup:
    int curr_errno = errno;
    perror("[ERROR]");
    if (f != NULL) fclose(f);
    errno = curr_errno;
}