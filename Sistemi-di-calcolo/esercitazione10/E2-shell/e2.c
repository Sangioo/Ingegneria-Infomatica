#include "e2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_TOKENS 64

void get_cmd_line(char *argv[]) {
    char buff[MAX_LINE];

    char *s = fgets(buff, MAX_LINE, stdin);
    if (s == NULL)
        goto cleanup;

    size_t len = strlen(buff);
    if (buff[len - 1] == '\n')
    {
        buff[len - 1] = '\0';
    }

    char *a = strtok(buff, " ");

    int i = 0;
    while (a != NULL && i < 64)
    {
        argv[i] = (char *)malloc(strlen(a) + 1);
        if (argv[i] == NULL)
        {
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

int do_shell(const char *prompt) {
    while (1) {
        int p_err = printf("%s", prompt);
        if (p_err < 0) goto cleanup;

        char *argv[64];
        get_cmd_line(argv);

        // skip empty command
        if (argv[0] == NULL) continue;

        // quit command
        if (strcmp(argv[0], "quit") == 0) break;

        // execute command in another process
        unsigned int pid = fork();
        if (pid == 0) {
            int err = execvp(argv[0], argv);
            if (err != 0) {
                printf("unknown command %s\n", argv[0]);
                exit(EXIT_FAILURE);
            }
            exit(EXIT_SUCCESS);
        }
        pid_t p = wait(NULL);
        if (p != 0) goto cleanup;
    }
cleanup:
    perror("ERRORE!!!!!!\n");
    exit(EXIT_FAILURE);
}