#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd = open("miofile.txt", O_CREAT | O_WRONLY | O_TRUNC, 0654);
    if (fd == -1) {
        perror("error in open");
        return EXIT_FAILURE;
    }
    char* str = "Hello World\n";
    ssize_t w = write(fd, str, strlen(str));
    if (w == -1) {
        perror("error in write");
        return EXIT_FAILURE;
    }
    printf("Scritti %ld bytes\n", w);
    int r = close(fd);
    if (r == -1) {
        perror("error in close");
        return EXIT_FAILURE;
    }
}