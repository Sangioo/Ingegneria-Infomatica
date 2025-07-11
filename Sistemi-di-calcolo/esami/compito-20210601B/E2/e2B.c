#include "e2B.h"
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

off_t searchfile(char* filename, char c) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) {
        perror("[ERROR]");
        exit(EXIT_FAILURE);
    }

    char cc;
    off_t out = -1;
    while ((cc = fgetc(f)) != EOF) {
        if (cc == c) {
            out = ftell(f) - 1;
        }
    }

    int res = fclose(f);
    if (res < 0) {
        perror("[ERROR]");
        exit(EXIT_FAILURE);
    }

    return out;
}