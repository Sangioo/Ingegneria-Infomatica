#include "e2A.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void numeroFrasiMaxParagrafi(const char* filename, int* maxNumeroFrasi) {
    FILE* f = fopen(filename, "r");
    if (f == NULL) goto cleanup;
    
    *maxNumeroFrasi = 0;
    char row[MAX_LINE_LEN], paragraph[MAX_PARAGRAFO_LEN];
    paragraph[0] = '\0';
    int n = 0, ultimaRiga = 0;
    char *check = fgets(row, sizeof(row), f);
    while (check || ultimaRiga) {
        if (row[0] == '\n') {
            paragraph[strlen(paragraph) - 1] = '\0';
            n++;
            int pid = fork();
            if (pid < 0) goto cleanup;

            if (pid == 0) {
                int count = 0;
                char *token = strtok(paragraph, ".");
                while (token != NULL) {
                    count++;
                    token = strtok(NULL, ".");
                }
                _exit(count);
            }
            paragraph[0] = '\0';
            if (ultimaRiga) break;
        } else {
            strcat(paragraph, row);
        }

        check = fgets(row, sizeof(row), f);
        if (!check) {
            ultimaRiga = 1;
            row[0] = '\n';
        }
    }

    int status, res;
    for (int i = 0; i < n; i++) {
        res = wait(&status);
        if (res < 0) goto cleanup;
        
        if (WIFEXITED(status) && WEXITSTATUS(status) > *maxNumeroFrasi) {
            *maxNumeroFrasi = WEXITSTATUS(status);
        }
    }

    res = fclose(f);
    if (res < 0) goto cleanup;
    return;

cleanup:
    if (f != NULL) fclose(f);
    *maxNumeroFrasi = -1;
    return;
}