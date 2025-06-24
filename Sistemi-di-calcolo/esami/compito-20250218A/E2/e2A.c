#include "e2A.h"
#include <stdio.h>
#include <stdlib.h>

char* load(const char* filename, unsigned* size) {
    // apro il file
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        perror("errore apertura file");
        exit(EXIT_FAILURE);
    }

    // posiziono l'indice alla fine
    *size = fseek(f, 0, SEEK_END);
    if (*size == -1) {
        perror("errore nel posizionamento alla fine");
        fclose(f);
        exit(EXIT_FAILURE);
    }
    
    // leggo l'offset
    *size = ftell(f);
    if (*size == -1) {
        perror("errore lettura offset");
        fclose(f);
        exit(EXIT_FAILURE);
    }

    // posiziono l'indice all'inizio
    int start = fseek(f, 0, SEEK_SET);
    if (start == -1) {
        perror("errore nel posizionamento all'inizio");
        fclose(f);
        exit(EXIT_FAILURE);
    }

    char* out = (char *) malloc(*size);
    int read = fread(out, 1, *size, f);
    if (read != *size) {
        perror("errore lettura file");
        fclose(f);
        exit(EXIT_FAILURE);
    }

    // chiudo il file
    int close = fclose(f);
    if (close) {
        perror("errore chiusura file");
        exit(EXIT_FAILURE);
    }

    return out;
}