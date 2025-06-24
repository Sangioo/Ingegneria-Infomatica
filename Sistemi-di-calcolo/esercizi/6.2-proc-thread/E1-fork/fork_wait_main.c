#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("[figlio] termina con codice 25 PID=%d PPID=%d\n", getpid(), getppid());
        _exit(25);
    }

    int status;
    pid = wait(&status); // sincronizzazione tra processi

    if (WIFEXITED(status)) {
        int codice = WEXITSTATUS(status);
        printf("[genitore] codice figlio %d PID=%d, CHILD_PID=%d\n", codice, pid, getpid());
    }
    return EXIT_SUCCESS; // oppure return 0;
}
