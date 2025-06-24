#include "e2B.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funzione di confronto per qsort
int compare(const void *a, const void *b) {
    struct connessione *connA = (struct connessione *)a;
    struct connessione *connB = (struct connessione *)b;
    return (connA->costo - connB->costo);
}

void destinazioniAcquistabili(struct connessione *list, const char *partenza, int budget, const char *filename) {
    struct connessione *current = list;
    struct connessione *filteredList = NULL;
    int count = 0;

    // Conta le connessioni valide
    while (current != NULL) {
        if (strcmp(current->partenza, partenza) == 0 && current->costo <= budget) {
            count++;
        }
        current = current->next;
    }

    // Alloca un array per le connessioni valide
    filteredList = (struct connessione *)malloc(count * sizeof(struct connessione));
    if (filteredList == NULL) {
        perror("Errore nell'allocazione della memoria");
        return;
    }

    current = list;
    int index = 0;
    // Popola l'array con le connessioni valide
    while (current != NULL) {
        if (strcmp(current->partenza, partenza) == 0 && current->costo <= budget) {
            filteredList[index] = *current;
            index++;
        }
        current = current->next;
    }

    // Ordina l'array per costo crescente
    qsort(filteredList, count, sizeof(struct connessione), compare);

    // Scrive le connessioni ordinate nel file
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        free(filteredList);
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s-%s-%d\n", filteredList[i].partenza, filteredList[i].destinazione, filteredList[i].costo);
    }

    fclose(file);
    free(filteredList);
}