#include "e2A.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int loadStringsFromFile (const char * filename, char *** list) {
    // apro il file
    FILE* f = fopen(filename, "r");
    if (f == NULL) goto cleanup;

    // calcolo la dimensione del file
    int res = fseek(f, 0, SEEK_END);
    if (res < 0) goto cleanup;
    int size = ftell(f);
    if (size < 0) goto cleanup;
    res = fseek(f, 0, SEEK_SET);
    if (res < 0) goto cleanup;

    // scrivo il contenuto del file in un buffer
    char* buf = (char *) malloc((size + 1) * sizeof(char));
    if (buf == NULL) goto cleanup;
    buf[size] = '\0';
    res = fread(buf, sizeof(char), size, f);
    if (res < size) goto cleanup;

    // chiudo il file
    res = fclose(f);
    if (res < 0) goto cleanup;
    
    // alloco un array di stringhe temporaneo
    char** tmp = (char **) malloc(sizeof(char *) * 1024);
    if (tmp == NULL) goto cleanup;

    // popolo l'array temporaneo
    int i = 0;
    char* token = strtok(buf, "\n");
    while (token) {
        if (isalpha(*token)) {
            tmp[i] = (char *) malloc(sizeof(char) * (strlen(token) + 1));
            if (tmp[i] == NULL) goto cleanup;

            tmp[i][strlen(token)] = '\0';
            strcpy(tmp[i], token);
            i++;
        }
        token = strtok(NULL, "\n");
    }
    free(buf);

    // copio l'array temporaneo nell'array di output
    *list = (char **) malloc(sizeof(char *) * i);
    if (*list == NULL) goto cleanup;
    for (int j = 0; j < i; j++) {
        (*list)[j] = tmp[j];
    }
    free(tmp);
    return i;

cleanup:
    if (f != NULL) fclose(f);
    if (buf != NULL) free(buf);
    if (tmp != NULL) {
        for (int j = 0; j < i; j++) free(tmp[j]);
        free(tmp);
    }
    if (*list != NULL) {
        for (int j = 0; j < i; j++) free((*list)[j]);
        free(*list);
    }
    return -1;
}