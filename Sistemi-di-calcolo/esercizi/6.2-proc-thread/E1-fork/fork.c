#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 10;
    pid_t pid = fork();

    // qui sono in esecuzione due processi: il genitore e il figlio
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // sono nel processo figlio
        // sleep(1);
        printf("Sono nel processo figlio: pid=%d ppid=%d\n", getpid(), getppid());
        i = 20;
    } else {
        printf("Sono nel processo genitore: pid=%d ppid=%d child_pid=%d\n", getpid(), getppid(), pid);
    }

    printf("i=%d\n", i);

    return EXIT_SUCCESS;
}
