#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("miofile.txt", O_RDONLY); //O_CREAT e O_TRUNC se dobbiamo leggere un file non hanno senso
    if (fd == -1) {
        perror("error in open");
        return EXIT_FAILURE;
    }
    char buf[512];
    ssize_t r = read(fd, buf, sizeof(buf));
    if (r == -1) {
        perror("error in read");
        return EXIT_FAILURE;
    }
    printf("Letti %ld bytes\n", r);
    if (r > 0) {
        //fwrite(buf, sizeof(char), r, stdout);
        write(1, buf, r);
        //buf[r]='\0'; 
        //printf("%s",buf);
    }
    int res = close(fd);
    if (res == -1) {
        perror("error in close");
        return EXIT_FAILURE;
    }
}