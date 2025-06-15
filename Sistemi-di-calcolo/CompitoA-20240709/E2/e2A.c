#include "e2A.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int cerca(const char * filename, const char * prefix, struct contatto ** arrayMatches) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) goto cleanup;

    struct contatto* arr_tmp = (struct contatto *) malloc(sizeof(struct contatto) * 32);
    if (arr_tmp == NULL) goto cleanup;

    char riga[48];
    int res, i = 0;
    while (fgets(riga, 48, f) != NULL) {
        if (strncmp(riga, prefix, strlen(prefix)) == 0) {
            int len = 0;
            char* r = riga;
            while(*r != '\0' && *r != '_' && len < 31) {
                r++;
                len++;
            }
            strncpy(arr_tmp[i].nomecompleto, riga, len);
            arr_tmp[i].nomecompleto[len] = '\0';
            
            len = 0;
            r = riga + 31;
            while(*r != '\0' && *r != '_' && len < 15) {
                r++;
                len++;
            }
            strncpy(arr_tmp[i].numero, riga + 31, len);
            arr_tmp[i].numero[len] = '\0';
            i++;
        }
    }

    *arrayMatches = (struct contatto *) malloc(sizeof(struct contatto) * i);
    if (*arrayMatches == NULL) goto cleanup;
    
    for (int j = 0; j < i; j++) {
        strncpy((*arrayMatches)[j].nomecompleto, arr_tmp[j].nomecompleto, strlen(arr_tmp[j].nomecompleto));
        strncpy((*arrayMatches)[j].numero, arr_tmp[j].numero, strlen(arr_tmp[j].numero));
    }

    free(arr_tmp);

    res = fclose(f);
    if (res < 0) goto cleanup;
    
    return i;

cleanup:
    int curr_errno = errno;
    perror("[ERROR]");

    if (f != NULL) fclose(f);
    if (arr_tmp != NULL) free(arr_tmp);
    if (*arrayMatches != NULL) free(*arrayMatches);

    errno = curr_errno;
    return -1;
}