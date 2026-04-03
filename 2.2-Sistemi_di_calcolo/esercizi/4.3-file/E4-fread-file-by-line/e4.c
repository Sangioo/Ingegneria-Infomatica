#include "e4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int read_file_by_line(const char *filename, char ***lines, int *num_lines) {
    // apro il file
    FILE* f = fopen(filename, "r");
    if (f == NULL) goto cleanup;

    // determino la grandezza del file
    int size;
    int res = fseek(f, 0, SEEK_END);
    if (res < 0) goto cleanup;

    size = ftell(f);
    if (res < 0) goto cleanup;

    res = fseek(f, 0, SEEK_SET);
    if (res < 0) goto cleanup;

    // alloco un buffer temporaneo per contenere il file
    char *buf = (char *) malloc(size + 1);
    if (buf == NULL) goto cleanup;
    buf[size] = '\0';

    res = fread(buf, 1, size, f);
    if (res < size) goto cleanup;

    // determino il numero di righe nel file
    *num_lines = 1;
    for (int i = 0; i < size; i++) {
        if (buf[i] == '\n') {
            (*num_lines)++;
        }
    }

    // alloco l'array di stringhe
    *lines = (char **) malloc(*num_lines * sizeof(char *));
    if (*lines == NULL) goto cleanup;
    
    // popolo l'array di stringhe
    char* token = strtok(buf, "\n");
    int j = 0;
    while (token) {
        (*lines)[j] = malloc(strlen(token) + 1);
        if ((*lines)[j] == NULL) goto cleanup;

        (*lines)[j][strlen(token)] = '\0';
        strncpy((*lines)[j], token, strlen(token));

        j++;
        token = strtok(NULL, "\n");
    }

    // dealloco il buffer e chiudo il file
    free(buf);
    res = fclose(f);
    if (res < 0) goto cleanup;

    return EXIT_SUCCESS;

cleanup:
    int curr_errno = errno;

    if (f != NULL) fclose(f);
    if (buf != NULL) free(buf);
    if (*lines != NULL) deallocate_lines(*lines, *num_lines);

    errno = curr_errno;
    return EXIT_FAILURE;
}

void deallocate_lines(char **lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);
}