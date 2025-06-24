#include "e2A.h"
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int countWords(const char* s) {
    int n = 0;
    char* tmp = (char *) calloc(sizeof(char), strlen(s) + 1);
    strncpy(tmp, s, strlen(s));
    char* token = strtok(tmp, " ");
    while (token != NULL) {
        n++;
        token = strtok(NULL, " ");
    }
    free(tmp);
    return n;
}

int countMinWords(const char** s, int n) {
    if (n == 0) return -1;

    int min = INT_MAX;

    for (int i = 0; i < n; i++) {
        int pid = fork();
        if (pid < 0) goto cleanup;

        if (pid == 0) {
            int nwords = countWords(s[i]);
            exit(nwords);
        } else {
            int res;
            int wait_res = wait(&res);
            
            if (WIFEXITED(res)) {
                if (WEXITSTATUS(res) < min) {
                    min = WEXITSTATUS(res);
                }
            }
        }
    }
    return min;

cleanup:
    return -1;
}