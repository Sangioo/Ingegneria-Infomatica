#include "e2B.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void make_files(int n, void (*f)(int i, char name[64], char buf[256])) {
    for (int i = 0; i < n; i++) {
        int pid = fork();
        if (pid == 0) {
            char name[64], buf[256];
            f(i, name, buf);
            int fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0664);
            write(fd, buf, sizeof(buf));
            close(fd);
            exit(0);
        }
    }

    for (int i = 0; i < n; i++) {
        wait(NULL);
    }
}