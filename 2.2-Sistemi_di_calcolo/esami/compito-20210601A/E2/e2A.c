#include "e2A.h"
#include <stdio.h>
#include <stdlib.h>

char* load(const char* filename, unsigned* size) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) goto cleanup;

    int res = fseek(f, 0, SEEK_END);
    if (res < 0) goto cleanup;
    *size = ftell(f);
    if (*size < 0) goto cleanup;
    res = fseek(f, 0, SEEK_SET);
    if (res < 0) goto cleanup;

    char* out = (char *) malloc(sizeof(char) * (*size));
    if (out == NULL) goto cleanup;
    res = fread(out, sizeof(char), *size, f);
    if (res < *size) goto cleanup;
    
    res = fclose(f);
    if (res < 0) goto cleanup;
    return out;

cleanup:
    if (f) fclose(f);
    if (out) free(out);
    return NULL;
}