#include "e2A.h"
#include <string.h>
#include <stdlib.h>

int countChar(char * word, char c) {
    int count = 0;
    while (*word) { count += *word++ == c; }
    return count;
}

int wordWithMaxCount(const char* text, const char c, char ** word) {
    int len = strlen(text);
    char* tmp = (char *) malloc(sizeof(char) * (len + 1));
    if (tmp == NULL) goto cleanup;
    tmp = memcpy(tmp, text, sizeof(char) * (len + 1));

    int max = 0, curr;
    char* maxw = NULL, *token = strtok(tmp, " ");
    while (token) {
        curr = countChar(token, c);
        if (curr > max) {
            max = curr;
            maxw = token;
        }
        token = strtok(NULL, " ");
    }

    if (maxw) {
        len = strlen(maxw);
        *word = (char *) malloc(sizeof(char) * (len + 1));
        if (*word == NULL) goto cleanup;
        *word = memcpy(*word, maxw, sizeof(char) * (len + 1));
    }

    free(tmp);
    return max;

cleanup:
    if (tmp) free(tmp);
    if (*word) free(*word);
    return -1;
}