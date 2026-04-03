#include "e2A.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void run(int* v, int n, int (*f)(int i)) {
    for (int i = 0; i < n; i++) {
        int pid = fork();
        if (pid < 0) {
            exit(EXIT_FAILURE);
        }
        if (pid == 0) {
            exit(f(i));
        }
    }

    int status;
    for (int j = 0; j < n; j++) {
        wait(&status);
        if (WIFEXITED(status)) {
            v[j] = WEXITSTATUS(status);
        }
    }
}