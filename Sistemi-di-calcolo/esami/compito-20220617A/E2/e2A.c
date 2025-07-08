#include "e2A.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <wait.h>
#include <unistd.h>

int multicount(const char** s, char c, int n) {
    if (c == 0 || n == 0) return -1;

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            int count = 0;
            for (int j = 0; j < strlen(s[i]); j++)
                count += s[i][j] == c;
            exit(count);
        }
    }

    int max = 0, status;
    for (int i = 0; i < n; i++) {
        wait(&status);
        if (WIFEXITED(status)) {
            status = WEXITSTATUS(status);
            max = ( status > max ) ? status : max;
        }
    }
    return max;
}