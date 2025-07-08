#include "e2B.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <string.h>

int wordcount(const char** s, int n) {
    if (n == 0) return -1;

    int max = 0, status;
    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("[ERROR]");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
            if (strlen(s[i]) == 0) exit(0);

            int count = 1;
            for (int j = 0; j < strlen(s[i]); j++)
                count += s[i][j] == ' ';
            
            exit(count);
        } else {
            wait(&status);
            if (WIFEXITED(status)) {
                status = WEXITSTATUS(status);
                max = ( status > max ) ? status : max;
            }
        }
    }
    return max;
}