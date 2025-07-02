#include "e2.h"
#include <stdio.h>
#include <errno.h>

int read_file(char *filename, void **buffer, size_t *size) {
    *size = 0;
    *buffer = NULL;
    FILE* f = fopen(filename, "r");
    if (f == NULL) goto cleanup;

    int res = fseek(f, 0, SEEK_END);
    if (res < 0) goto cleanup;

    *size = ftell(f);
    if (*size < 0) goto cleanup;

    res = fseek(f, 0, SEEK_SET);
    if (res < 0) goto cleanup;

    *buffer = malloc(*size);
    if (*buffer == NULL) goto cleanup;

    res = fread(*buffer, 1, *size, f);
    if (res < *size) goto cleanup;

    res = fclose(f);
    if (res < 0) goto cleanup;

    return EXIT_SUCCESS;

cleanup:
    if (f != NULL) fclose(f);
    if (*buffer != NULL) free(*buffer);
    return EXIT_FAILURE;
}

