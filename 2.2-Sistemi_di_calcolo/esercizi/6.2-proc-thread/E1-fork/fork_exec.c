#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid == 0) {
        char* argv[] = { "ls" , "-l", NULL };
        execvp("ls", argv);
        perror("execvp");
        _exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}

