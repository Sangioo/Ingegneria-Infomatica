#include "e2C.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONNESSIONI 1000

// Definizione della struttura connessione
struct connessione {
    char partenza[4];       // Partenza del collegamento
    char destinazione[4];   // Destinazione del collegamento
    int costo;              // Costo del collegamento
    struct connessione *next; // Puntatore a un altro elemento della stessa struttura
};

// Funzione di confronto per qsort
int compare(const void *a, const void *b) {
    struct connessione *connA = (struct connessione *)a;
    struct connessione *connB = (struct connessione *)b;
    return (connA->costo - connB->costo);
}

void destinazioniSottoBudget(const char * filesorgente, const char * partenza, int budget, const char * filedestinazione){
	// Apertura del file sorgente in modalità lettura
    FILE *inputFile = fopen(filesorgente, "r");
    if (inputFile == NULL) {
        perror("Errore nell'apertura del file sorgente");
        return;
    }

    // Creazione dell'array di connessioni
    struct connessione connessioni[MAX_CONNESSIONI];
    int numConnessioni = 0;

    // Lettura delle connessioni dal file sorgente
    char buffer[50];
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL && numConnessioni < MAX_CONNESSIONI) {
        sscanf(buffer, "%3s-%3s-%d", connessioni[numConnessioni].partenza, connessioni[numConnessioni].destinazione, &connessioni[numConnessioni].costo);
        numConnessioni++;
    }

    fclose(inputFile);

    // Filtraggio delle connessioni sotto il budget
    struct connessione connessioniFiltrate[MAX_CONNESSIONI];
    int numConnessioniFiltrate = 0;

    for (int i = 0; i < numConnessioni; i++) {
        if (strcmp(connessioni[i].partenza, partenza) == 0 && connessioni[i].costo <= budget) {
            connessioniFiltrate[numConnessioniFiltrate] = connessioni[i];
            numConnessioniFiltrate++;
        }
    }

    // Ordinamento delle connessioni filtrate per costo crescente
    qsort(connessioniFiltrate, numConnessioniFiltrate, sizeof(struct connessione), compare);

    // Apertura del file destinazione in modalità scrittura
    FILE *outputFile = fopen(filedestinazione, "w");
    if (outputFile == NULL) {
        perror("Errore nell'apertura del file destinazione");
        return;
    }

    // Scrittura delle connessioni nel file destinazione
    for (int i = 0; i < numConnessioniFiltrate; i++) {
        fprintf(outputFile, "%s-%s-%d\n", connessioniFiltrate[i].partenza, connessioniFiltrate[i].destinazione, connessioniFiltrate[i].costo);
    }

    fclose(outputFile);
}