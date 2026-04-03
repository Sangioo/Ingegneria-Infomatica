#include "e2A.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct destinazione * creaNodo(const char *dest, int costo) {
    struct destinazione *new_node = (struct destinazione *)malloc(sizeof(struct destinazione));
    if (new_node != NULL) {
        strncpy(new_node->destinazione, dest, sizeof(new_node->destinazione) - 1);
        new_node->destinazione[sizeof(new_node->destinazione) - 1] = '\0'; // Assicurarsi che sia null-terminated
        new_node->costo = costo;
        new_node->next = NULL;
    }
    return new_node;
}

void aggiungiNodo(struct destinazione **list, const char *dest, int costo) {
    struct destinazione * new_node = creaNodo(dest, costo);
    if (*list == NULL) {
        *list = new_node;
    } else {
        struct destinazione *current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void destinazioniDisponibili(const char * filename, const char * partenza, int budget, struct destinazione ** list){
    // Inizializza la lista come vuota
    *list = NULL;

    // Apri il file in modalità lettura
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        char part[4], dest[4];
        int costo;

        // Estrae il contenuto della linea letta dal file
        if (sscanf(line, "%3s-%3s-%d", part, dest, &costo) == 3) {
            // Controlla se la partenza corrisponde e il costo è entro il budget
            if (strcmp(part, partenza) == 0 && costo <= budget) {
                aggiungiNodo(list, dest, costo);
            }
        }
    }

    // Chiudi il file
    fclose(file);
}