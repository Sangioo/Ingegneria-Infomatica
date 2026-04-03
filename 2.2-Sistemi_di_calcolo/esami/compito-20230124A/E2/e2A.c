#include "e2A.h"
#include <stdio.h>
#include <stdlib.h>

void decodeTextFile(const char * encoded_file, const char * key, char **decoded_text) {
    FILE* fk = fopen(key, "r");
    if (fk == NULL) goto cleanup;
    
    char k[59];
    k[58] = '\0';

    int res = fread(k, 1, 58, fk);
    if (res < 58) goto cleanup;

    res = fclose(fk);
    if (res < 0) goto cleanup;
    
    FILE* f = fopen(encoded_file, "r");
    if (f == NULL) goto cleanup;

    res = fseek(f, 0, SEEK_END);
    if (res < 0) goto cleanup;
    int size = ftell(f);
    if (size < 0) goto cleanup;
    fseek(f, 0, SEEK_SET);
    if (res < 0) goto cleanup;

    char* buf = (char *) malloc(size + 1);
    if (buf == NULL) goto cleanup;
    buf[size] = '\0';

    *decoded_text = (char *) malloc(size + 1);
    if (*decoded_text == NULL) goto cleanup;
    (*decoded_text)[size] = '\0';

    res = fread(buf, 1, size, f);
    if (res < size) goto cleanup;
    
    for (int i = 0; i < size; i++) {
        if (65 <= buf[i] && buf[i] <= 122) {
            (*decoded_text)[i] = k[buf[i] - 65];
        } else {
            (*decoded_text)[i] = buf[i];
        }
    }

    free(buf);
    res = fclose(f);
    if (res < 0) goto cleanup;
    return;

cleanup:
    perror("[ERROR]");
    if (f != NULL) fclose(f);
    if (fk != NULL) fclose(fk);
    if (buf != NULL) free(buf);
    if (*decoded_text != NULL) free (*decoded_text);
    return;
}