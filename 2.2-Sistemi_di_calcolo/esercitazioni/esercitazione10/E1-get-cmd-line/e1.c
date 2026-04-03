//SCRIVERE LA SOLUZIONE QUI...

#include "e1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_cmd_line(char* argv[]) {
    char buff[MAX_LINE];

    char *s = fgets(buff, MAX_LINE, stdin);
    if (s == NULL) goto cleanup;

    size_t len = strlen(buff);
    if (buff[len-1] == '\n') {
        buff[len-1] = '\0';
    }

    char *a = strtok(buff, " ");
    
    int i = 0;
    while (a != NULL && i < 64) {
        argv[i] = (char *) malloc(strlen(a) + 1);
        if (argv[i] == NULL) {
            break;
        }
        strcpy(argv[i], a);
        i++;
        a = strtok(NULL, " ");
    }
    argv[i] = NULL;
    return;

cleanup:
    return;
}