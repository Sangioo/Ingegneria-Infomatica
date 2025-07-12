#include "e2A.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int contains(char* s, char c, int n) {
    int len = strlen(s);
    int m = len / n, contains = 0, i;

    if (n * m < len) {
        for (i = n * m; i < len; i++)
            if (s[i] == c) contains = 1;
    }

    for (i = 0; i < n * m; i += m) {
        int pid = fork();
        if (pid == 0) {
            for (int j = i; j < i + m; j++) {
                if (s[j] == c) exit(1);
            }
            exit(0);
        }
    }

    int status;
    for (i = 0; i < n; i++) {
        wait(&status);
        if (WIFEXITED(status))
            contains |= WEXITSTATUS(status);
    }
    
    return contains;
}